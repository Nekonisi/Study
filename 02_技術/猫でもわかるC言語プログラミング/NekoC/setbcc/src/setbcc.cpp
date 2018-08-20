//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("setbcc.res");
USEFORM("Unit1.cpp", Form1);
USEFORM("UnitAbout.cpp", FormAbout);
USEUNIT("cenv.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "BCC5.5環境ファイル/パス設定プログラム";
         Application->CreateForm(__classid(TForm1), &Form1);
         Application->CreateForm(__classid(TFormAbout), &FormAbout);
         Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
