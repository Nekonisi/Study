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
    //���낢�돉����
    oldBtnName = ButtonNext->Caption;
    baseDirName = "c:\\Borland\\Bcc55";
    includepathName = baseDirName + AnsiString("\\include");
    libpathName = baseDirName + AnsiString("\\lib");

    //���N���X������
    EnvData = new CEnv();

    EnvData->AutoexecFilename = "c:\\autoexec.bat";
    bcc32cfg = new TStringList();
    ilink32cfg = new TStringList();

    //autoexecbatFileName�̕\��
    ViewAutexecbatFilenameEdit();

    //Windows�̎�ނ𔻒f
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
//�{�[�����h��Web�T�C�g������
void __fastcall TForm1::WebW1Click(TObject *Sender)
{
    ShellExecute(Form1->Handle,"open","http://www.borland.co.jp/",NULL,NULL,SW_SHOW);
}
//---------------------------------------------------------------------------
//�{�[�����h��Borland C++Compiler��Web�T�C�g������
void __fastcall TForm1::BorlandCWebI1Click(TObject *Sender)
{
    ShellExecute(Form1->Handle,"open","http://www.borland.co.jp/cppbuilder/freecompiler/",NULL,NULL,SW_SHOW);
}
//---------------------------------------------------------------------------
//C MAGAZINE��Web�T�C�g������
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
//�t�@�C���㏑���̊m�F
bool __fastcall TForm1::CheckFileName(AnsiString Filename)
{
    if (FileExists(Filename)) {
        AnsiString Msg = Filename + AnsiString("�͑��݂��܂��B\n�{�v���O�����Őݒ肵�����e�ɏ㏑�����܂����H");

        if (Application->MessageBox(
            Msg.c_str(),
            "�t�@�C���㏑���̊m�F", MB_OKCANCEL) == IDCANCEL) {
            return false;
        } else {
            DeleteFile(Filename);
        }
    }
    return true;
}

//�i��/�߂�{�^��
void __fastcall TForm1::ButtonNextClick(TObject *Sender)
{
    AnsiString bcc32cfgFilename = envpathName + AnsiString("\\bcc32.cfg");
    AnsiString ilink32cfgFilename = envpathName + AnsiString("\\ilink32.cfg");

    //�Ō�̃y�[�W��������l����������
    if (PageControl1->ActivePage->PageIndex == PageControl1->PageCount-1) {

        //�������f�B���N�g�����`�F�b�N
        if (!FileExists(envpathName + AnsiString("\\bcc32.exe"))) {
            Application->MessageBox("���̃t�H���_�ɂ�bcc32.exe����������܂���B\n"
                                    "������x�u�C���X�g�[����v�̎w�����蒼���Ă��������B\n"
                                    "�܂�Borland C++Compiler 5.5.1�{�̂��C���X�g�[�����Ă��Ȃ����́C\n"
                                    "��ɃC���X�g�[�����s���Ă���{�v���O���������s���Ă��������B", "�m�F", IDOK);
        } else {
            //��������Ώ�������
            if (CheckFileName(bcc32cfgFilename))
                bcc32cfg->SaveToFile(bcc32cfgFilename);
            if (CheckFileName(ilink32cfgFilename))
                ilink32cfg->SaveToFile(ilink32cfgFilename);
            EnvSave("PATH", envpathName);
            EnvSave("INCLUDE", includepathName);
            EnvRegSetExpandString();

            Application->MessageBox("Borland C++ Compiler�ɕK�v�Ȋe��ݒ���s���܂����B\n\n"
                                    "�t���b�s�[�f�B�X�N�܂���CD���}������Ă���ꍇ�́C\n"
                                    "��������O���āC�R���s���[�^���ċN�����Ă��������B\n"
                                    "�ݒ�͍ċN����ɗL���ɂȂ�܂��B", "�m�F", MB_OK);

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

//�{�^���̑J��
void __fastcall TForm1::BtnReg(int id)
{
    switch(id) {
      case PAGESTART:
        //�ŏ��̃y�[�W��������߂�{�^�����O���[��
        ButtonUndo->Enabled = false;
        ButtonNext->Caption = oldBtnName;
        break;
      case PAGEEND:
        //�Ō�̃y�[�W��������{�^������ς���
        ButtonNext->Caption = "�ݒ�";
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

//���ϐ���ݒ�
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

        //"%PATH%;�c�c"�Ƃ����`�����T��
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

//Windows NT/2000�Ŋ��ϐ�PATH�������I�ɓW�J������ɂ���
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

//autoexec.bat�̑J��
void __fastcall TForm1::ViewAutexecbatFilenameEdit(void)
{
    //autoexecbatFileName�̕\��
    Edit_AutoexecbatFilename->Text = EnvData->AutoexecFilename;

    //autoexec.bat�̖��O����͂ł���悤�ɂ��邩�ǂ���
    Edit_AutoexecbatFilename->Enabled = (RadioGroup_OSSelect->ItemIndex == 0) ? True : False;
    Label_AutoexecbatFilename->Enabled = Edit_AutoexecbatFilename->Enabled;
    ButtonRefFileOpen->Enabled = Edit_AutoexecbatFilename->Enabled;
}
//---------------------------------------------------------------------------
//�e�L�X�g�̒u��
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

//�ݒ�f�[�^�̍쐬
void __fastcall TForm1::MakeSettingData(void)
{
    AnsiString includeDir, libDir, oldbaseDirName;

    oldbaseDirName = baseDirName;
    baseDirName = Edit_InstallFolder->Text;
    if (!baseDirName.IsPathDelimiter(baseDirName.Length())) {
        baseDirName = baseDirName + AnsiString("\\");
    }

    //baseDirName���ς������
    if (baseDirName != oldbaseDirName) {

        //Path�ݒ�p�̕�����
        envpathName = baseDirName + AnsiString("bin");

        //�C���N���[�h�t�@�C���̃f�B���N�g����
        includepathName = baseDirName + AnsiString("include");

        //�C���N���[�h�t�@�C���̃f�B���N�g����
        libpathName = baseDirName + AnsiString("lib;") + baseDirName + AnsiString("lib\\PSDK");

        //cfg�t�@�C���̓��e�쐬
        includeDir = AnsiString("-I\"") + includepathName + AnsiString("\"");
        libDir = AnsiString("-L\"") + libpathName + AnsiString("\"");

        //���ꂼ��̃t�@�C���p���X�g�Ɋi�[
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

    //autoexec.bat���ɕύX������΁C����𔽉f����
    if (EnvData->AutoexecFilename != Edit_AutoexecbatFilename->Text)
        EnvData->AutoexecFilename = Edit_AutoexecbatFilename->Text;

    //���[�U���ݒ�t�@�C����ҏW�������ǂ���
    if (RichEdit_bcc32cfg->Modified)
        bcc32cfg->Assign(RichEdit_bcc32cfg->Lines);
    if (RichEdit_ilink32cfg->Modified)
        ilink32cfg->Assign(RichEdit_ilink32cfg->Lines);
    if (EnvData->FlagWinNT != (RadioGroup_OSSelect->ItemIndex == 0) ? False : True)
        EnvData->FlagWinNT = (RadioGroup_OSSelect->ItemIndex == 0) ? False : True;
}

//---------------------------------------------------------------------------
static char *MsgTbl[] = {
    "Borland C++ Compiler 5.5.1�̃p�b�P�[�W���C���X�g�[������"
      "�t�H���_(�f�B���N�g����)����͂��Ă��������B�f�t�H���g�̂܂�"
      "�C���X�g�[�������Ƃ��́C",
    " ",
    "�@�@�@�@c:\\Borland\\Bcc55\\",
    " ",
    "�ɂȂ��Ă��܂��B�킩��Ȃ��ꍇ��[�Q��]�{�^���������āC�t�H"
      "���_�����m�F���Ă��������B",
    NULL,
    "�p�X�Ɗ��ϐ��̐ݒ���I�����܂��B"
      "����ɂ��CDOS�v�����v�g����ǂ̃t�H���_(�f�B���N�g��)����ł�"
      "�R���p�C�����\�ɂȂ�܂��B�Ȃ��C����͐ݒ肵���}�V���̍ċN����ɗL���ɂȂ�܂��B",
    " ",
    "Windows Me/98/95�Ȃǂ����g���̕��́Cautoexec.bat�ɓo�^���܂��B"
      "Windows XP/2000/NT�Ȃǂ����g���̕��́C���W�X�g���ɓo�^���܂��B"
      "OS�̌��o���Ԉ���Ă���悤�������琳����OS��I�����Ă��������B",
    NULL,
    "�p�X�̗D��x��I�����܂��B�ʏ�̓f�t�H���g�́u��Ɂv�ł��܂��܂���B",
    " ",
    "�{�[�����h��Borland C++Builder�����łɂ��g���̕��ŁC"
    "Borland C++ Compiler��D�悳���ē��삳�������Ƃ���"
    "�u�擪�Ɂv��I��ł��������B"
    "���݂̐ݒ�Ɠ����p�X/���ϐ�INCLUDE���폜�������Ƃ��́u�����̃p�X���폜����v��I��ł��������B",
    NULL,
    "�w�b�_�t�@�C��(*.h/*.hpp)���u����Ă���t�H���_(�f�B���N�g��)���̎w���"
      "���C�u�����t�@�C��(*.lib/*.obj)���u����Ă���t�H���_(�f�B���N�g��)���̎w����s���܂��B",
    " ",
    "�t�H���_(�f�B���N�g��)����ǉ�����Ƃ��́u;�v������ŁC�\����ʏ�ɒǉ����Ă��������B",
    " ",
    "�R�}���h���C���I�v�V�����ŏ펞�g�����̂�����΁C�����ɉ����Ă��������B"
      "�Ȃ��t�@�C���͍Ō�̍H���ŏ������܂�܂��B",
    NULL,
    "�����N���郉�C�u�����t�@�C��(*.lib/*.obj)���u����Ă���t�H���_(�f�B���N�g��)���̎w����s���܂��B",
    " ",
    "�t�H���_(�f�B���N�g��)����ǉ�����Ƃ��́u;�v������ŁC�\����ʏ�ɒǉ����Ă��������B",
    " ",
    "�Ȃ��t�@�C���͍Ō�̍H���ŏ������܂�܂��B",
    NULL,
    "�\������Ă���ݒ�ł悯���[�ݒ�]�{�^���������Ă��������B�ݒ����������Ńv���O�����͏I�����܂��B"
    "�ݒ肪�Ԉ���Ă���ꍇ��[�߂�]�{�^���������Ă�蒼���Ă��������B",
    " ",
    "�܂��C�ݒ肹���Ƀv���O�������I��������ɂ́C���j���[��[�ݒ�𔽉f�������ɏI��(X)]��I��ł��������B",
    " ",
    "�ݒ肳�ꂽ���e�̓R���s���[�^���ċN���������ƂɗL���ɂȂ�܂��B�K���R���s���[�^�����Z�b�g���Ă��������B",
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

//PATH�̕\��
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
    //autoexecbatFileName�̕\��
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
            RadioGroup_PathPriority->Items->Add("�O�Ɂi�V�X�e���֐ݒ�j");
            RadioGroup_PathPriority->Items->Add("��Ɂi�V�X�e���֐ݒ�j");
        }
        //PATH�̕\��
        RichEdit_path->Clear();
        RichEdit_path->Lines->Add("[�V�X�e��]");
        EnvData->RegRootKey = HKEY_LOCAL_MACHINE;
        EnvData->RegKeyname = RegEnvSystemKey;
        EnvData->Read("PATH", envPathName);
        ViewPath(envPathName);
        RichEdit_path->Lines->Add("");
        RichEdit_path->Lines->Add("[���[�U�[]");
        EnvData->RegRootKey = HKEY_CURRENT_USER;
        EnvData->RegKeyname = RegEnvUserKey;
        EnvData->Read("PATH", envPathName);
        ViewPath(envPathName);
    } else {
        //���ϐ��̎擾
        EnvData->GetEnv("PATH", envPathName);

        //PATH�̕\��
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

    s = "[�p�X�̐ݒ�]";
    switch (RadioGroup_PathPriority->ItemIndex) {
      case 0:
        s += "�@[�O��]";
        break;
      case 1:
        s += "�@[���]";
        break;
      case 2:
        s += "�@[���̃p�X���폜]";
        break;
      case 3:
        s += "�@[�O�Ɂi�V�X�e���j]";
        break;
      case 4:
        s += "�@[��Ɂi�V�X�e���j]";
        break;
    }
    RichEdit_AnkerView->Lines->Add(s);
    RichEdit_AnkerView->Lines->Add(envpathName);
    RichEdit_AnkerView->Lines->Add("");
    RichEdit_AnkerView->Lines->Add("[���ϐ�INCLUDE�̐ݒ�]");
    RichEdit_AnkerView->Lines->Add(includepathName);
    RichEdit_AnkerView->Lines->Add("");
    RichEdit_AnkerView->Lines->Add("[bcc32.cfg�̓��e]");
    RichEdit_AnkerView->Lines->AddStrings(bcc32cfg);
    RichEdit_AnkerView->Lines->Add("");
    RichEdit_AnkerView->Lines->Add("[ilink32.cfg�̓��e]");
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
    BrowsingInfo.lpszTitle      = "�t�H���_��I�����Ă�������";
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
        Application->MessageBox("�p�X���W�J�ł���悤�ɏC�����܂����B", "�m�F", MB_OK);
    } else {
        Application->MessageBox("Windows XP/NT/2000�ȊO�ł͗��p����K�v�͂���܂���B", "�m�F", MB_OK);
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


