//----------------------------------------------------------------------------
#ifndef CENVH
#define CENVH
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Registry.hpp>
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TEnvWriteEvent)
  (const AnsiString KeyName, const AnsiString ValName);
typedef void __fastcall (__closure *TEnvReadEvent)
  (const AnsiString KeyName, AnsiString &ValName);

class CEnv : public TObject
{
private:
    AnsiString FAutoexecFilename, FRegkeyname;
    bool FFlagWinNT, FFlagEOF;
    TRegistry *Reg;
    TEnvWriteEvent FWrite;
    TEnvReadEvent  FRead;
    TEnvWriteEvent FErase;
    void __fastcall SetAutoexecFilename(AnsiString Name);
    void __fastcall SetRegKeyname(AnsiString Name);
    AnsiString __fastcall GetRegKeyname(void);
    void __fastcall SetRootKey(HKEY Key);
    HKEY __fastcall GetRootKey(void);
    void __fastcall SubstringErase(AnsiString &destStr, AnsiString serchStr);
    AnsiString __fastcall SubstringReplace(AnsiString SrcText,
                                  AnsiString SerchText, AnsiString ReplText);
    void __fastcall SetWinNT(bool flag);

    void __fastcall WriteToAutoexec(const AnsiString KeyName, const AnsiString ValName);
    void __fastcall ReadToAutoexec(const AnsiString KeyName, AnsiString &ValName);
    void __fastcall EraseToAutoexec(const AnsiString KeyName, const AnsiString ValName);
    void __fastcall WriteToReg(const AnsiString KeyName, const AnsiString ValName);
    void __fastcall ReadToReg(const AnsiString KeyName, AnsiString &ValName);
    void __fastcall EraseToReg(const AnsiString KeyName, const AnsiString ValName);
    void __fastcall EraseAutoexecEOF(TStringList *DestList);
    void __fastcall CheckAutoexecEOF(TStringList *DestList);
public:
    __fastcall CEnv(void);
    __fastcall ~CEnv(void);
    __property AnsiString AutoexecFilename = {read=FAutoexecFilename, write=SetAutoexecFilename};
    __property AnsiString RegKeyname = {read=FRegkeyname, write=SetRegKeyname};
    __property HKEY RegRootKey = {read=GetRootKey, write=SetRootKey};
    __property bool FlagWinNT = {read=FFlagWinNT, write=SetWinNT};
    bool __fastcall isWindowsNTfamily(void);
    void __fastcall RegSetExpandString(const AnsiString KeyName);
    void __fastcall GetEnv(const AnsiString KeyName, AnsiString &ValName);
    void __fastcall Write(const AnsiString KeyName, const AnsiString ValName);
    void __fastcall Read(const AnsiString KeyName,  AnsiString &ValName);
    void __fastcall Erase(const AnsiString KeyName, const AnsiString ValName);
};
#endif
