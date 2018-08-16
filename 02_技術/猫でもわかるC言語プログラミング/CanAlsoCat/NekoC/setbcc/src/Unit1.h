//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include "cenv.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
    TPageControl *PageControl1;
    TTabSheet *TabSheet1;
    TTabSheet *TabSheet2;
    TTabSheet *TabSheet3;
    TMainMenu *MainMenu1;
    TMenuItem *F1;
    TMenuItem *Exit1;
    TMenuItem *Help1;
    TMenuItem *A1;
    TTabSheet *TabSheet4;
    TTabSheet *TabSheet5;
    TOpenDialog *OpenDialog1;
    TMenuItem *readmeR1;
    TMenuItem *N1;
    TMenuItem *WebW1;
    TTabSheet *TabSheet6;
    TMenuItem *CMAGAZINEWebC1;
    TMenuItem *BorlandCWebI1;
    TMenuItem *N2;
    TPanel *Panel1;
    TButton *ButtonUndo;
    TButton *ButtonNext;
    TLabel *Label1;
    TLabel *Label2;
    TRichEdit *RichEdit_TopMsg;
    TBevel *Bevel1;
    TEdit *Edit_InstallFolder;
    TLabel *Label3;
    TButton *ButtonRefForder;
    TEdit *Edit_AutoexecbatFilename;
    TLabel *Label_AutoexecbatFilename;
    TButton *ButtonRefFileOpen;
    TRadioGroup *RadioGroup_OSSelect;
    TRadioGroup *RadioGroup_PathPriority;
    TLabel *Label8;
    TRichEdit *RichEdit_path;
    TLabel *Label4;
    TRichEdit *RichEdit_bcc32cfg;
    TLabel *Label6;
    TLabel *Label5;
    TLabel *Label7;
    TLabel *Label9;
    TRichEdit *RichEdit_ilink32cfg;
    TLabel *Label12;
    TRichEdit *RichEdit_AnkerView;
    TLabel *Label11;
    TRichEdit *RichEdit_Msg;
    TPanel *Panel2;
    TPanel *Panel3;
    TPanel *Panel21;
    TMenuItem *N3;
    TMenuItem *WinNT2000N1;
    TButton *ButtonDefBack;
    void __fastcall A1Click(TObject *Sender);
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall ButtonNextClick(TObject *Sender);
    void __fastcall ButtonUndoClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall TabSheet1Show(TObject *Sender);
    void __fastcall TabSheet2Show(TObject *Sender);
    void __fastcall TabSheet3Show(TObject *Sender);
    void __fastcall TabSheet4Show(TObject *Sender);
    void __fastcall TabSheet5Show(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall readmeR1Click(TObject *Sender);
    void __fastcall WebW1Click(TObject *Sender);
    void __fastcall TabSheet6Show(TObject *Sender);
    void __fastcall CMAGAZINEWebC1Click(TObject *Sender);
    void __fastcall BorlandCWebI1Click(TObject *Sender);
    void __fastcall ButtonRefForderClick(TObject *Sender);
    void __fastcall ButtonRefFileOpenClick(TObject *Sender);
    void __fastcall RadioGroup_OSSelectClick(TObject *Sender);
    void __fastcall WinNT2000N1Click(TObject *Sender);
    void __fastcall ButtonDefBackClick(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// ユーザー宣言
    AnsiString oldBtnName;          //ボタン名の保存
    AnsiString baseDirName;         //ベースとなるディレクトリ名
    AnsiString envpathName;         //パスとして設定するディレクトリ名
    AnsiString includepathName;     //インクルードファイルがあるディレクトリ名
    AnsiString libpathName;         //ライブラリファイルがあるディレクトリ名
    CEnv *EnvData;
    TStringList *bcc32cfg;
    TStringList *ilink32cfg;
    AnsiString __fastcall TForm1::TextReplace(AnsiString SrcText,
      AnsiString SerchText, AnsiString ReplText);
    void __fastcall BtnReg(int id);
    void __fastcall MakeSettingData(void);
    void __fastcall ViewAutexecbatFilenameEdit(void);
    bool __fastcall CheckFileName(AnsiString Filename);
    void __fastcall ViewMsg(int no);
    void __fastcall EnvSave(AnsiString EnvName, AnsiString EnvValName);
    void __fastcall EnvRegSetExpandString(void);
    void __fastcall ViewPath(AnsiString envPathName);
public:		// ユーザー宣言
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 