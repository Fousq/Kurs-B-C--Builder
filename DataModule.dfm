//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ReportUnit.h"
//bout ReportForm to MainForm
#include "MainUnit.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TReportForm *ReportForm;
//---------------------------------------------------------------------------
__fastcall TReportForm::TReportForm(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TReportForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        //when report form closed, then back to main form
        MainForm->Show