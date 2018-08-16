//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <windowsx.h>
#include <Registry.hpp>
#include <FileCtrl.hpp>
#include <Shellapi.hpp>
#include <shlobj.h>

#include "Unit1.h"
#include "UnitAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    //いろいろ初期化
    oldBtnName = ButtonNext->Caption;
    baseDirName = "c:\\Borland\\Bcc55";
    includepathName = baseDirName + AnsiString("\\include");
    libpathName = baseDirName + AnsiString("\\lib");

    //環境クラス初期化
    EnvData = new CEnv();

    EnvData->AutoexecFilename = "c:\\autoexec.bat";
    bcc32cfg = new TStringList();
    ilink32cfg = new TStringList();

    //autoexecbatFileNameの表示
    ViewAutexecbatFilenameEdit();

    //Windowsの種類を判断
    RadioGroup_OSSelect->ItemIndex = (EnvData->FlagWinNT) ? 1 : 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
    delete bcc32cfg;
    delete ilink32cfg;
    delete EnvData;
}
//---------------------------------------------------------------------------
//About
void __fastcall TForm1::A1Click(TObject *Sender)
{
    FormAbout->ShowModal();
}
//---------------------------------------------------------------------------
//readme
void __fastcall TForm1::readmeR1Click(TObject *Sender)
{
    AnsiString readmeFilename;

    readmeFilename = ExtractFilePath(Application->ExeName) + AnsiString("readme.txt");
    ShellExecute(Form1->Handle,"open",readmeFilename.c_str(),NULL,NULL,SW_SHOW);
}
//---------------------------------------------------------------------------
//ボーランドのWebサイトを見る
void __fastcall TForm1::WebW1Click(TObject *Sender)
{
    ShellExecute(Form1->Handle,"open","http://www.borland.co.jp/",NULL,NULL,SW_SHOW);
}
//---------------------------------------------------------------------------
//ボーランドのBorland C++CompilerのWebサイトを見る
void __fastcall TForm1::BorlandCWebI1Click(TObject *Sender)
{
    ShellExecute(Form1->Handle,"open","http://www.borland.co.jp/cppbuilder/freecompiler/",NULL,NULL,SW_SHOW);
}
//---------------------------------------------------------------------------
//C MAGAZINEのWebサイトを見る
void __fastcall TForm1::CMAGAZINEWebC1Click(TObject *Sender)
{
    ShellExecute(Form1->Handle,"open","http://www.cmagazine.jp/",NULL,NULL,SW_SHOW);
}
//---------------------------------------------------------------------------
//Exit
void __fastcall TForm1::Exit1Click(TObject *Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------
//ファイル上書きの確認
bool __fastcall TForm1::CheckFileName(AnsiString Filename)
{
    if (FileExists(Filename)) {
        AnsiString Msg = Filename + AnsiString("は存在します。\n本プログラムで設定した内容に上書きしますか？");

        if (Application->MessageBox(
            Msg.c_str(),
            "ファイル上書きの確認", MB_OKCANCEL) == IDCANCEL) {
            return false;
        } else {
            DeleteFile(Filename);
        }
    }
    return true;
}

//進む/戻るボタン
void __fastcall TForm1::ButtonNextClick(TObject *Sender)
{
    AnsiString bcc32cfgFilename = envpathName + AnsiString("\\bcc32.cfg");
    AnsiString ilink32cfgFilename = envpathName + AnsiString("\\ilink32.cfg");

    //最後のページだったら値を書き込み
    if (PageControl1->ActivePage->PageIndex == PageControl1->PageCount-1) {

        //正しいディレクトリかチェック
        if (!FileExists(envpathName + AnsiString("\\bcc32.exe"))) {
            Application->MessageBox("このフォルダにはbcc32.exeが見当たりません。\n"
                                    "もう一度「インストール先」の指定をやり直してください。\n"
                                    "またBorland C++Compiler 5.5.1本体をインストールしていない方は，\n"
                                    "先にインストールを行ってから本プログラムを実行してください。", "確認", IDOK);
        } else {
            //正しければ書き込み
            if (CheckFileName(bcc32cfgFilename))
                bcc32cfg->SaveToFile(bcc32cfgFilename);
            if (CheckFileName(ilink32cfgFilename))
                ilink32cfg->SaveToFile(ilink32cfgFilename);
            EnvSave("PATH", envpathName);
            EnvSave("INCLUDE", includepathName);
            EnvRegSetExpandString();

            Application->MessageBox("Borland C++ Compilerに必要な各種設定を行いました。\n\n"
                                    "フロッピーディスクまたはCDが挿入されている場合は，\n"
                                    "それを取り外して，コンピュータを再起動してください。\n"
                                    "設定は再起動後に有効になります。", "確認", MB_OK);

            Close();
            return;
        }

    }
    PageControl1->SelectNextPage(true);
}

void __fastcall TForm1::ButtonUndoClick(TObject *Sender)
{
    PageControl1->SelectNextPage(false);
}
//---------------------------------------------------------------------------
#define PAGESTART   1
#define PAGEEND     2
#define PAGEOTHER   3

//ボタンの遷移
void __fastcall TForm1::BtnReg(int id)
{
    switch(id) {
      case PAGESTART:
        //最初のページだったら戻るボタンをグレー化
        ButtonUndo->Enabled = false;
        ButtonNext->Caption = oldBtnName;
        break;
      case PAGEEND:
        //最後のページだったらボタン名を変える
        ButtonNext->Caption = "設定";
        ButtonUndo->Enabled = true;
        break;
      case PAGEOTHER:
        ButtonNext->Caption = oldBtnName;
        ButtonUndo->Enabled = true;
        break;
    }
}


//---------------------------------------------------------------------------
const AnsiString RegEnvSystemKey = "\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment";
const AnsiString RegEnvUserKey = "Environment";

//環境変数を設定
void __fastcall TForm1::EnvSave(AnsiString EnvName, AnsiString EnvValName)
{
    AnsiString AddNameTail,AddNameHead, AddName, s;

    if (EnvData->FlagWinNT) {
        AddNameTail = AnsiString(";") + EnvValName;
        AddNameHead = EnvValName + AnsiString(";");
        EnvData->RegRootKey = HKEY_LOCAL_MACHINE;
        EnvData->RegKeyname = RegEnvSystemKey;
        EnvData->Erase(EnvName, AddNameTail);
        EnvData->Erase(EnvName, AddNameHead);
        EnvData->RegRootKey = HKEY_CURRENT_USER;
        EnvData->RegKeyname = RegEnvUserKey;
        EnvData->Erase(EnvName, AddNameTail);
        EnvData->Erase(EnvName, AddNameHead);

        switch (RadioGroup_PathPriority->ItemIndex) {
          case 0:
          case 1:
            EnvData->RegRootKey = HKEY_CURRENT_USER;
            EnvData->RegKeyname = RegEnvUserKey;
            EnvData->Read(EnvName, s);
            break;
          case 2:
            return;
          case 3:
          case 4:
            EnvData->RegRootKey = HKEY_LOCAL_MACHINE;
            EnvData->RegKeyname = RegEnvSystemKey;
            EnvData->Read(EnvName, s);
            break;
        }
        switch (RadioGroup_PathPriority->ItemIndex) {
          case 0:
          case 3:
            AddName = AddNameHead + s;
            break;
          case 1:
          case 4:
            AddName = s + AddNameTail;
            break;
        }
        if (s == "") {
            AddName = AddNameHead;
        }
        EnvData->Write(EnvName, AddName);
    } else {
        AddNameTail = AnsiString("%") + EnvName + AnsiString("%;") + EnvValName;
        AddNameHead = EnvValName + AnsiString(";%") + EnvName + AnsiString("%");
        EnvData->Erase(EnvName, AddNameTail);
        EnvData->Erase(EnvName, AddNameHead);

        //"%PATH%;……"という形式も探す
        AddNameTail = AnsiString("\"") + AddNameTail + AnsiString("\"");
        AddNameHead = AnsiString("\"") + AddNameHead + AnsiString("\"");
        EnvData->Erase(EnvName, AddNameTail);
        EnvData->Erase(EnvName, AddNameHead);
        if (RadioGroup_PathPriority->ItemIndex == 1) {
            EnvData->Write(EnvName, AddNameTail);
        } else if (RadioGroup_PathPriority->ItemIndex == 0) {
            EnvData->Write(EnvName, AddNameHead);
        }
    }
}

//Windows NT/2000で環境変数PATHを強制的に展開文字列にする
void __fastcall TForm1::EnvRegSetExpandString(void)
{
    if (EnvData->FlagWinNT) {
        EnvData->RegRootKey = HKEY_LOCAL_MACHINE;
        EnvData->RegKeyname = RegEnvSystemKey;
        EnvData->RegSetExpandString("PATH");
        EnvData->RegRootKey = HKEY_CURRENT_USER;
        EnvData->RegKeyname = RegEnvUserKey;
        EnvData->RegSetExpandString("PATH");
    }
}

//autoexec.batの遷移
void __fastcall TForm1::ViewAutexecbatFilenameEdit(void)
{
    //autoexecbatFileNameの表示
    Edit_AutoexecbatFilename->Text = EnvData->AutoexecFilename;

    //autoexec.batの名前を入力できるようにするかどうか
    Edit_AutoexecbatFilename->Enabled = (RadioGroup_OSSelect->ItemIndex == 0) ? True : False;
    Label_AutoexecbatFilename->Enabled = Edit_AutoexecbatFilename->Enabled;
    ButtonRefFileOpen->Enabled = Edit_AutoexecbatFilename->Enabled;
}
//---------------------------------------------------------------------------
//テキストの置換
AnsiString __fastcall TForm1::TextReplace(AnsiString SrcText,
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
        SrcText.Insert(AnsiString::StringOfChar(' ', ReplText.Length()), hitIndex);
    }
    return DestText;
}

//設定データの作成
void __fastcall TForm1::MakeSettingData(void)
{
    AnsiString includeDir, libDir, oldbaseDirName;

    oldbaseDirName = baseDirName;
    baseDirName = Edit_InstallFolder->Text;
    if (!baseDirName.IsPathDelimiter(baseDirName.Length())) {
        baseDirName = baseDirName + AnsiString("\\");
    }

    //baseDirNameが変わったら
    if (baseDirName != oldbaseDirName) {

        //Path設定用の文字列
        envpathName = baseDirName + AnsiString("bin");

        //インクルードファイルのディレクトリ名
        includepathName = baseDirName + AnsiString("include");

        //インクルードファイルのディレクトリ名
        libpathName = baseDirName + AnsiString("lib;") + baseDirName + AnsiString("lib\\PSDK");

        //cfgファイルの内容作成
        includeDir = AnsiString("-I\"") + includepathName + AnsiString("\"");
        libDir = AnsiString("-L\"") + libpathName + AnsiString("\"");

        //それぞれのファイル用リストに格納
        if (bcc32cfg->Count == 0) {
            bcc32cfg->Add(includeDir);
            bcc32cfg->Add(libDir);
        } else {
            bcc32cfg->Text = TextReplace(bcc32cfg->Text, oldbaseDirName, baseDirName);
        }
        if (ilink32cfg->Count == 0) {
            ilink32cfg->Add(libDir);
        } else {
            ilink32cfg->Text = TextReplace(ilink32cfg->Text, oldbaseDirName, baseDirName);
        }
        RichEdit_bcc32cfg->Lines->Assign(bcc32cfg);
        RichEdit_ilink32cfg->Lines->Assign(ilink32cfg);
    }

    //autoexec.bat名に変更があれば，それを反映する
    if (EnvData->AutoexecFilename != Edit_AutoexecbatFilename->Text)
        EnvData->AutoexecFilename = Edit_AutoexecbatFilename->Text;

    //ユーザが設定ファイルを編集したかどうか
    if (RichEdit_bcc32cfg->Modified)
        bcc32cfg->Assign(RichEdit_bcc32cfg->Lines);
    if (RichEdit_ilink32cfg->Modified)
        ilink32cfg->Assign(RichEdit_ilink32cfg->Lines);
    if (EnvData->FlagWinNT != (RadioGroup_OSSelect->ItemIndex == 0) ? False : True)
        EnvData->FlagWinNT = (RadioGroup_OSSelect->ItemIndex == 0) ? False : True;
}

//---------------------------------------------------------------------------
static char *MsgTbl[] = {
    "Borland C++ Compiler 5.5.1のパッケージをインストールした"
      "フォルダ(ディレクトリ名)を入力してください。デフォルトのまま"
      "インストールしたときは，",
    " ",
    "　　　　c:\\Borland\\Bcc55\\",
    " ",
    "になっています。わからない場合は[参照]ボタンを押して，フォ"
      "ルダ名を確認してください。",
    NULL,
    "パスと環境変数の設定先を選択します。"
      "これにより，DOSプロンプトからどのフォルダ(ディレクトリ)からでも"
      "コンパイルが可能になります。なお，これは設定したマシンの再起動後に有効になります。",
    " ",
    "Windows Me/98/95などをお使いの方は，autoexec.batに登録します。"
      "Windows XP/2000/NTなどをお使いの方は，レジストリに登録します。"
      "OSの検出が間違っているようだったら正しいOSを選択してください。",
    NULL,
    "パスの優先度を選択します。通常はデフォルトの「後に」でかまいません。",
    " ",
    "ボーランドのBorland C++Builderをすでにお使いの方で，"
    "Borland C++ Compilerを優先させて動作させたいときは"
    "「先頭に」を選んでください。"
    "現在の設定と同じパス/環境変数INCLUDEを削除したいときは「同名のパスを削除する」を選んでください。",
    NULL,
    "ヘッダファイル(*.h/*.hpp)が置かれているフォルダ(ディレクトリ)名の指定と"
      "ライブラリファイル(*.lib/*.obj)が置かれているフォルダ(ディレクトリ)名の指定を行います。",
    " ",
    "フォルダ(ディレクトリ)名を追加するときは「;」を挟んで，表示画面上に追加してください。",
    " ",
    "コマンドラインオプションで常時使うものがあれば，ここに加えてください。"
      "なおファイルは最後の工程で書き込まれます。",
    NULL,
    "リンクするライブラリファイル(*.lib/*.obj)が置かれているフォルダ(ディレクトリ)名の指定を行います。",
    " ",
    "フォルダ(ディレクトリ)名を追加するときは「;」を挟んで，表示画面上に追加してください。",
    " ",
    "なおファイルは最後の工程で書き込まれます。",
    NULL,
    "表示されている設定でよければ[設定]ボタンを押してください。設定を書き込んでプログラムは終了します。"
    "設定が間違っている場合は[戻る]ボタンを押してやり直してください。",
    " ",
    "また，設定せずにプログラムを終了させるには，メニューの[設定を反映させずに終了(X)]を選んでください。",
    " ",
    "設定された内容はコンピュータを再起動したあとに有効になります。必ずコンピュータをリセットしてください。",
    NULL,
    NULL,
    NULL,
};

void __fastcall TForm1::ViewMsg(int no)
{
    RichEdit_Msg->Clear();
    for (int i = 0, count = 0; !((MsgTbl[i] == NULL) && (MsgTbl[i+1] == NULL)); i++) {
        if (count == no) {
            RichEdit_Msg->Lines->Add(MsgTbl[i]);
        } else if (count > no) {
            break;
        }
        if (MsgTbl[i] == NULL)
            count++;
    }
}

//PATHの表示
void __fastcall TForm1::ViewPath(AnsiString envPathName)
{
    AnsiString s;
    int searchIndex, oldSearchIndex;

    oldSearchIndex = 1;
    for (;;) {
        searchIndex = envPathName.Pos(";");
        if (searchIndex == 0)
            break;
        s = envPathName.SubString(oldSearchIndex, searchIndex - oldSearchIndex);
        if (s.Length()) {
            s = s + AnsiString(";");
            RichEdit_path->Lines->Add(s);
        }
        envPathName[searchIndex] = ' ';
        oldSearchIndex = searchIndex + 1;
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::TabSheet1Show(TObject *Sender)
{
    Edit_InstallFolder->Text = baseDirName;
    Edit_InstallFolder->SetFocus();

    MakeSettingData();

    ViewMsg(0);
    BtnReg(PAGESTART);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TabSheet2Show(TObject *Sender)
{
    //autoexecbatFileNameの表示
    ViewAutexecbatFilenameEdit();

    MakeSettingData();

    ViewMsg(1);
    BtnReg(PAGEOTHER);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TabSheet3Show(TObject *Sender)
{
    AnsiString envPathName;

    MakeSettingData();

    if (EnvData->FlagWinNT) {
        if (RadioGroup_PathPriority->Items->Count <= 3) {
            RadioGroup_PathPriority->Items->Add("前に（システムへ設定）");
            RadioGroup_PathPriority->Items->Add("後に（システムへ設定）");
        }
        //PATHの表示
        RichEdit_path->Clear();
        RichEdit_path->Lines->Add("[システム]");
        EnvData->RegRootKey = HKEY_LOCAL_MACHINE;
        EnvData->RegKeyname = RegEnvSystemKey;
        EnvData->Read("PATH", envPathName);
        ViewPath(envPathName);
        RichEdit_path->Lines->Add("");
        RichEdit_path->Lines->Add("[ユーザー]");
        EnvData->RegRootKey = HKEY_CURRENT_USER;
        EnvData->RegKeyname = RegEnvUserKey;
        EnvData->Read("PATH", envPathName);
        ViewPath(envPathName);
    } else {
        //環境変数の取得
        EnvData->GetEnv("PATH", envPathName);

        //PATHの表示
        RichEdit_path->Clear();
        ViewPath(envPathName);
    }

    ViewMsg(2);
    BtnReg(PAGEOTHER);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TabSheet4Show(TObject *Sender)
{
    MakeSettingData();

    RichEdit_bcc32cfg->Lines->Assign(bcc32cfg);
    ViewMsg(3);
    BtnReg(PAGEOTHER);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TabSheet5Show(TObject *Sender)
{
    MakeSettingData();

    RichEdit_ilink32cfg->Lines->Assign(ilink32cfg);
    ViewMsg(4);
    BtnReg(PAGEOTHER);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TabSheet6Show(TObject *Sender)
{
    AnsiString s;

    MakeSettingData();
    RichEdit_AnkerView->Clear();

    s = "[パスの設定]";
    switch (RadioGroup_PathPriority->ItemIndex) {
      case 0:
        s += "　[前に]";
        break;
      case 1:
        s += "　[後に]";
        break;
      case 2:
        s += "　[このパスを削除]";
        break;
      case 3:
        s += "　[前に（システム）]";
        break;
      case 4:
        s += "　[後に（システム）]";
        break;
    }
    RichEdit_AnkerView->Lines->Add(s);
    RichEdit_AnkerView->Lines->Add(envpathName);
    RichEdit_AnkerView->Lines->Add("");
    RichEdit_AnkerView->Lines->Add("[環境変数INCLUDEの設定]");
    RichEdit_AnkerView->Lines->Add(includepathName);
    RichEdit_AnkerView->Lines->Add("");
    RichEdit_AnkerView->Lines->Add("[bcc32.cfgの内容]");
    RichEdit_AnkerView->Lines->AddStrings(bcc32cfg);
    RichEdit_AnkerView->Lines->Add("");
    RichEdit_AnkerView->Lines->Add("[ilink32.cfgの内容]");
    RichEdit_AnkerView->Lines->AddStrings(ilink32cfg);

    ViewMsg(5);
    BtnReg(PAGEEND);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioGroup_OSSelectClick(TObject *Sender)
{
    ViewAutexecbatFilenameEdit();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonRefForderClick(TObject *Sender)
{
    BROWSEINFO BrowsingInfo;
    char DirPath[MAX_PATH];
    char FolderName[MAX_PATH];
    LPITEMIDLIST ItemID;
    AnsiString s;

    memset(&BrowsingInfo, 0, sizeof(BROWSEINFO));
    memset(DirPath, 0, MAX_PATH);
    memset(FolderName, 0, MAX_PATH);
    BrowsingInfo.hwndOwner      = Handle;
    BrowsingInfo.pszDisplayName = FolderName;
    BrowsingInfo.lpszTitle      = "フォルダを選択してください";
    BrowsingInfo.ulFlags        = BIF_RETURNONLYFSDIRS | BIF_DONTGOBELOWDOMAIN;
    ItemID = SHBrowseForFolder(&BrowsingInfo);
    SHGetPathFromIDList(ItemID, DirPath );
    GlobalFreePtr(ItemID);

    if (strlen(DirPath)) {
        Edit_InstallFolder->Text = DirPath;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonRefFileOpenClick(TObject *Sender)
{
    OpenDialog1->FileName = Edit_AutoexecbatFilename->Text;
    OpenDialog1->InitialDir = ExtractFilePath(OpenDialog1->FileName);

    if (OpenDialog1->Execute()) {
        Edit_AutoexecbatFilename->Text = OpenDialog1->FileName;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::WinNT2000N1Click(TObject *Sender)
{
    if (EnvData->FlagWinNT) {
        EnvRegSetExpandString();
        Application->MessageBox("パスが展開できるように修整しました。", "確認", MB_OK);
    } else {
        Application->MessageBox("Windows XP/NT/2000以外では利用する必要はありません。", "確認", MB_OK);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonDefBackClick(TObject *Sender)
{
    Edit_InstallFolder->Text = baseDirName;
    Edit_InstallFolder->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_RETURN)
        ButtonNextClick(Sender);
}
//---------------------------------------------------------------------------


