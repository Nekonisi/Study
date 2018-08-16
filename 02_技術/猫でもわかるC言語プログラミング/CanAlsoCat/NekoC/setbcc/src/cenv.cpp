//---------------------------------------------------------------------------
/*

   ���ϐ��𑀍삷��N���X CEnv


   2000/11/06
   Autoexec.bat��EOF���������Ƃ��ɑΉ�
   
   2000/08/12
   �Ȃ�₩���ŕ���^^;
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
//�e�L�X�g�̒u��
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

//���蕶����̍폜
void __fastcall CEnv::SubstringErase(AnsiString &destStr, AnsiString serchStr)
{
    AnsiString srcStr;

    srcStr = destStr;
    destStr = SubstringReplace(srcStr, serchStr, "");
}


//---------------------------------------------------------------------------
//OS�̔��f(Windows NT/2000��Windows 95/98��)
bool __fastcall CEnv::isWindowsNTfamily(void)
{
    OSVERSIONINFO osvi;

    osvi.dwOSVersionInfoSize = sizeof(osvi);
    GetVersionEx(&osvi);
    return (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT);
}

//OS�̎w��(Windows NT/2000��Windows 95/98��)
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

//���ϐ��̎擾
void __fastcall CEnv::GetEnv(const AnsiString KeyName, AnsiString &ValName)
{
    char envNameBuf[1024*16];

    GetEnvironmentVariable(KeyName.c_str(), envNameBuf, (1024*16)-1);
    ValName = envNameBuf;
}


//---------------------------------------------------------------------------
#define _EOF  0x1a

//EOF����菜��
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

//EOF���������悤�Ȃ�t��������
void __fastcall CEnv::CheckAutoexecEOF(TStringList *DestList)
{
    char strEOF[] = {_EOF, 0};

    if (!FFlagEOF)
        return;
    DestList->Add(strEOF);
    FFlagEOF = False;
}

//Autoexe.bat�̖��O
void __fastcall CEnv::SetAutoexecFilename(AnsiString FileName)
{
    FAutoexecFilename = FileName;
}

//���ϐ��̕ۑ�(Autoexec.bat)
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

//���ϐ��̓ǂݍ���(Autoexec.bat)
void __fastcall CEnv::ReadToAutoexec(const AnsiString KeyName, AnsiString &ValName)
{
    GetEnv(KeyName, ValName);
}

//���ϐ��̍폜(Autoexec.bat)
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
//���W�X�g���L�[�̖��O��ݒ�
void __fastcall CEnv::SetRegKeyname(AnsiString Name)
{
    FRegkeyname = Name;
}

//���W�X�g���̃��[�g�L�[�̖��O��ݒ�
void __fastcall CEnv::SetRootKey(HKEY Key)
{
    Reg->RootKey = Key;
}

//���W�X�g���̃��[�g�L�[�̖��O���擾
HKEY __fastcall CEnv::GetRootKey(void)
{
    return Reg->RootKey;
}

//���W�X�g���̊��ϐ��̂����CExpandString�����s��
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

//���ϐ��̕ۑ�(���W�X�g��)
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

//���ϐ��̓ǂݍ���(���W�X�g���C�W�J�Ȃ�)
void __fastcall CEnv::ReadToReg(const AnsiString KeyName, AnsiString &ValName)
{
    Reg->OpenKey(FRegkeyname, false);
    ValName = Reg->ReadString(KeyName);
    Reg->CloseKey();
}

//���ϐ��̍폜(���W�X�g��)
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
