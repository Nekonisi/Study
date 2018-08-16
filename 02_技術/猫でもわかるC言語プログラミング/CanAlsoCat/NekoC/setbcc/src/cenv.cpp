//---------------------------------------------------------------------------
/*

   環境変数を操作するクラス CEnv


   2000/11/06
   Autoexec.batでEOFがあったときに対応
   
   2000/08/12
   なんやかんやで分離^^;
*/

#include "cenv.h"


//---------------------------------------------------------------------------
__fastcall CEnv::CEnv(void)
{
    Reg = new TRegistry;
    FlagWinNT = isWindowsNTfamily();
    FRegkeyname = "";
    FFlagEOF = false;
}

__fastcall CEnv::~CEnv(void)
{
    delete Reg;
}


//---------------------------------------------------------------------------
//テキストの置換
AnsiString __fastcall CEnv::SubstringReplace(AnsiString SrcText,
  AnsiString SerchText, AnsiString ReplText)
{
    int hitIndex;
    AnsiString DestText = SrcText;

    for (;;) {
        hitIndex = SrcText.AnsiPos(SerchText);
        if (hitIndex == 0)
            break;
        DestText.Delete(hitIndex, SerchText.Length());
        DestText.Insert(ReplText, hitIndex);

        SrcText.Delete(hitIndex, SerchText.Length());
        SrcText.Insert(AnsiString::StringOfChar(' ', ReplText.Length()),
          hitIndex);
    }
    return DestText;
}

//特定文字列の削除
void __fastcall CEnv::SubstringErase(AnsiString &destStr, AnsiString serchStr)
{
    AnsiString srcStr;

    srcStr = destStr;
    destStr = SubstringReplace(srcStr, serchStr, "");
}


//---------------------------------------------------------------------------
//OSの判断(Windows NT/2000かWindows 95/98か)
bool __fastcall CEnv::isWindowsNTfamily(void)
{
    OSVERSIONINFO osvi;

    osvi.dwOSVersionInfoSize = sizeof(osvi);
    GetVersionEx(&osvi);
    return (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT);
}

//OSの指定(Windows NT/2000かWindows 95/98か)
void __fastcall CEnv::SetWinNT(bool flag)
{
    FFlagWinNT = flag;
    if (FFlagWinNT) {
        FWrite = WriteToReg;
        FRead  = ReadToReg;
        FErase = EraseToReg;
    } else {
        FWrite = WriteToAutoexec;
        FRead  = ReadToAutoexec;
        FErase = EraseToAutoexec;
    }
}

//環境変数の取得
void __fastcall CEnv::GetEnv(const AnsiString KeyName, AnsiString &ValName)
{
    char envNameBuf[1024*16];

    GetEnvironmentVariable(KeyName.c_str(), envNameBuf, (1024*16)-1);
    ValName = envNameBuf;
}


//---------------------------------------------------------------------------
#define _EOF  0x1a

//EOFを取り除く
void __fastcall CEnv::EraseAutoexecEOF(TStringList *DestList)
{
    char strEOF[] = {_EOF, 0};
    AnsiString s;
    int pos;

    s = DestList->Strings[DestList->Count - 1];
    pos = s.Pos(strEOF);
    if (pos) {
        s.Delete(pos, 1);
        if (s == "") {
            DestList->Delete(DestList->Count - 1);
        } else {
            DestList->Strings[DestList->Count - 1] = s;
        }
        FFlagEOF = True;
    }
}

//EOFがあったようなら付け加える
void __fastcall CEnv::CheckAutoexecEOF(TStringList *DestList)
{
    char strEOF[] = {_EOF, 0};

    if (!FFlagEOF)
        return;
    DestList->Add(strEOF);
    FFlagEOF = False;
}

//Autoexe.batの名前
void __fastcall CEnv::SetAutoexecFilename(AnsiString FileName)
{
    FAutoexecFilename = FileName;
}

//環境変数の保存(Autoexec.bat)
void __fastcall CEnv::WriteToAutoexec(const AnsiString KeyName, const AnsiString ValName)
{
    TStringList *DestList = new TStringList();
    AnsiString SetName = AnsiString("SET ") + KeyName;

    EraseToAutoexec(KeyName, ValName);
    EraseToAutoexec(SetName, ValName);
    if (FileExists(FAutoexecFilename)) {
        DestList->LoadFromFile(FAutoexecFilename);
        EraseAutoexecEOF(DestList);
    }
    if (KeyName == AnsiString("PATH"))
        SetName = KeyName;
    DestList->Add(SetName + AnsiString("=") + ValName);
    
    CheckAutoexecEOF(DestList);
    DestList->SaveToFile(FAutoexecFilename);
    delete DestList;
}

//環境変数の読み込み(Autoexec.bat)
void __fastcall CEnv::ReadToAutoexec(const AnsiString KeyName, AnsiString &ValName)
{
    GetEnv(KeyName, ValName);
}

//環境変数の削除(Autoexec.bat)
void __fastcall CEnv::EraseToAutoexec(const AnsiString KeyName, const AnsiString ValName)
{
    AnsiString s;

    if (!FileExists(FAutoexecFilename))
        return;

    TStringList *DestList = new TStringList();
    DestList->LoadFromFile(FAutoexecFilename);
    EraseAutoexecEOF(DestList);

    for (int i = 0; i < DestList->Count; i++) {
        s = DestList->Strings[i];
        if (!s.Pos(KeyName))
            continue;
        SubstringErase(s, ValName);
        s = SubstringReplace(s, ";;", ";");
        s = SubstringReplace(s, "=\"\"", "=");
        s = SubstringReplace(s, "=;", "=");
        if ((s.Pos("=") == s.Length()) || (s == KeyName)) {
            DestList->Delete(i);
            i--;
        } else {
            DestList->Strings[i] = s;
        }
    }

    CheckAutoexecEOF(DestList);
    DestList->SaveToFile(FAutoexecFilename);
    delete DestList;
}


//---------------------------------------------------------------------------
//レジストリキーの名前を設定
void __fastcall CEnv::SetRegKeyname(AnsiString Name)
{
    FRegkeyname = Name;
}

//レジストリのルートキーの名前を設定
void __fastcall CEnv::SetRootKey(HKEY Key)
{
    Reg->RootKey = Key;
}

//レジストリのルートキーの名前を取得
HKEY __fastcall CEnv::GetRootKey(void)
{
    return Reg->RootKey;
}

//レジストリの環境変数のうち，ExpandString化を行う
void __fastcall CEnv::RegSetExpandString(const AnsiString KeyName)
{
    AnsiString ValName;

    Reg->OpenKey(FRegkeyname, false);
    ValName = Reg->ReadString(KeyName);
    Reg->DeleteValue(KeyName);
    if (ValName != "")
        Reg->WriteExpandString(KeyName, ValName);
    Reg->CloseKey();
}

//環境変数の保存(レジストリ)
void __fastcall CEnv::WriteToReg(const AnsiString KeyName, const AnsiString ValName)
{
    TRegDataInfo RegDataInfo;

    Reg->OpenKey(FRegkeyname, true);
    Reg->GetDataInfo(KeyName, RegDataInfo);
    if ((RegDataInfo.RegData == rdExpandString) || (ValName.Pos("%"))) {
        Reg->WriteExpandString(KeyName, ValName);
    } else {
        Reg->WriteString(KeyName, ValName);
    }
    if (Reg->ReadString(KeyName) == "")
        Reg->DeleteValue(KeyName);
    Reg->CloseKey();
}

//環境変数の読み込み(レジストリ，展開なし)
void __fastcall CEnv::ReadToReg(const AnsiString KeyName, AnsiString &ValName)
{
    Reg->OpenKey(FRegkeyname, false);
    ValName = Reg->ReadString(KeyName);
    Reg->CloseKey();
}

//環境変数の削除(レジストリ)
void __fastcall CEnv::EraseToReg(const AnsiString KeyName, const AnsiString ValName)
{
    AnsiString s;

    Reg->OpenKey(FRegkeyname, false);
    s = Reg->ReadString(KeyName);
    SubstringErase(s, ValName);
    s = SubstringReplace(s, ";;", ";");
    Reg->CloseKey();
    WriteToReg(KeyName, s);
    Reg->OpenKey(FRegkeyname, false);
    s = Reg->ReadString(KeyName);
    if (s == "")
        Reg->DeleteValue(KeyName);
    Reg->CloseKey();
}


//---------------------------------------------------------------------------
void __fastcall CEnv::Write(const AnsiString KeyName, const AnsiString ValName)
{
    FWrite(KeyName, ValName);
}

void __fastcall CEnv::Read(const AnsiString KeyName,  AnsiString &ValName)
{
    FRead(KeyName, ValName);
}

void __fastcall CEnv::Erase(const AnsiString KeyName, const AnsiString ValName)
{
    FErase(KeyName, ValName);
}
