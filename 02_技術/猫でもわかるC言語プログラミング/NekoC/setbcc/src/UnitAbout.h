//----------------------------------------------------------------------------
#ifndef UnitAboutH
#define UnitAboutH
//----------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Windows.hpp>
#include <Messages.hpp>
#include <Classes.hpp>
#include <Graphics.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//----------------------------------------------------------------------------
class TFormAbout : public TForm
{
__published:
	TButton *Button1;
    TPanel *Panel1;
    TRichEdit *RichEdit1;
    TRichEdit *RichEdit2;
private:
public:
	virtual __fastcall TFormAbout(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern TFormAbout *FormAbout;
//----------------------------------------------------------------------------
#endif
 