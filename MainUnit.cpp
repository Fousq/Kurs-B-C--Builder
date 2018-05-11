//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
//Bound MainForm to DataModule1
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*                           Form's Events                                 */
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
        //Deactivate all data bases
        DataModule1->NewbornsTable->Active = false;
        DataModule1->DeadsTable->Active = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
        //Hide all panels
        AddGB->Hide();
        DeleteGB->Hide();
        EditGB->Hide();
        //Active data bases
        DataModule1->NewbornsTable->Active = true;
        DataModule1->NewbornsTable->Open();
        DataModule1->DeadsTable->Active = true;
        DataModule1->DeadsTable->Open();
        //Focused on first page
        PageControl1->ActivePage = NewbornsSheet;
}
//---------------------------------------------------------------------------
/*                              Buttons                                    */
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddButtonClick(TObject *Sender)
{
        InformationPanel->Hide();
        AddGB->Show();
        AddGB->Top = 24;
        AddGB->Left = 520;
}
//---------------------------------------------------------------------------
