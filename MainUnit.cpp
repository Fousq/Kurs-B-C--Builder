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
        GroupBox->Hide();
        //Active data bases
        DataModule1->NewbornsTable->Active = true;
        DataModule1->NewbornsTable->Open();
        DataModule1->DeadsTable->Active = true;
        DataModule1->DeadsTable->Open();
        //Focused on first page
        PageControl1->ActivePage = NewbornsSheet;

        //Set default vision of information panel
        DBText1->DataSource = DataModule1->NewbornsDS;
        DBText1->DataField = "FIO";
        DBText2->DataSource = DataModule1->NewbornsDS;
        DBText2->DataField = "Sex";
        DBText3->DataSource = DataModule1->NewbornsDS;
        DBText3->DataField = "DateOfBirth";
        DBText4->DataSource = DataModule1->NewbornsDS;
        DBText4->DataField = "PlaceOfBirth";
        Label10->Hide();
        DBText5->Hide();
        Label11->Hide();
        DBText6->Hide();
        Label12->Hide();
        DBText7->Hide();
        Label13->Top = 112;
        DBText8->Top = 128;
        Label13->Show();
        DBText8->Show();
}
//---------------------------------------------------------------------------
/*                              Buttons                                    */
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddButtonClick(TObject *Sender)
{
        //if button "Add" was clicked
        GroupBox->Caption = "Добавить запись";
        InformationPanel->Hide();
        GroupBox->Show();
        GroupBox->Top = 24;
        GroupBox->Left = 520;
        //determine which page is now
        if (PageControl1->ActivePage == NewbornsSheet)
        {
                //if page is "Newborns"
                DBEdit1->DataSource = DataModule1->NewbornsDS;
                DBEdit1->DataField = "FIO";
                DBEdit2->DataSource = DataModule1->NewbornsDS;
                DBEdit2->DataField = "Sex";
                DBEdit3->DataSource = DataModule1->NewbornsDS;
                DBEdit3->DataField = "DateOfBirth";
                DBEdit4->DataSource = DataModule1->NewbornsDS;
                DBEdit4->DataField = "PlaceOfBirth";
                Label14->Hide();
                DBEdit5->Hide();
                Label15->Hide();
                DBEdit6->Hide();
                Label16->Hide();
                DBEdit7->Hide();
                Label5->Top = 152;
                DBMemo1->Top = 164;
                Label5->Show();
                DBMemo1->Show();
                //Prepare data base to add new record
                DataModule1->NewbornsTable->Append();
        }

        if (PageControl1->ActivePage == DeadsSheet)
        {
                //if page is "Deads"
                DBEdit1->DataSource = DataModule1->DeadsDS;
                DBEdit1->DataField = "FIO";
                DBEdit2->DataSource = DataModule1->DeadsDS;
                DBEdit2->DataField = "Sex";
                DBEdit3->DataSource = DataModule1->DeadsDS;
                DBEdit3->DataField = "DateOfBirth";
                DBEdit4->DataSource = DataModule1->DeadsDS;
                DBEdit4->DataField = "PlaceOfBirth";
                Label5->Hide();
                DBMemo1->Hide();
                Label14->Show();
                DBEdit5->Show();
                Label15->Show();
                DBEdit6->Show();
                Label16->Show();
                DBEdit7->Show();
                //Prepare data base to add new record
                DataModule1->DeadsTable->Append();
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ConfirmButtonClick(TObject *Sender)
{
        //After fill all fields
        //Check if fields are empty or not
        //if one of the fields is empty, Empty will be equal true
        bool Empty = false;
        //save name of empty fields
        AnsiString ErrorMessage = "";
        if (PageControl1->ActivePage == NewbornsSheet)
        {
                if (DBEdit1->Text == "")
                {
                        Empty = true;
                        //change color of field to highlight empty field
                        DBEdit1->Color = clRed;
                        ErrorMessage += "";
                }

                if (DBEdit2->Text == "")
                {
                        Empty = true;
                        DBEdit2->Color = clRed;
                        ErrorMessage += "";
                }

                if (DBEdit3->Text == "")
                {
                        Empty = true;
                        DBEdit3->Color = clRed;
                        ErrorMessage += "";
                }

                if (DBEdit4->Text == "")
                {
                        Empty = true;
                        DBEdit4->Color = clRed;
                        ErrorMessage += "";
                }

                if (DBMemo1->Text == "")
                {
                        Empty = true;
                        DBMemo1->Color = clRed;
                        ErrorMessage += "";
                }

                if (Empty)
                {
                        //if one of the fildes is empty, the message will be shown up
                        Application->MessageBoxA("", "", MB_ICONERROR);
                        return;
                }
                else
                {
                        //get the confirmation
                        if (Application->MessageBoxA("", "", MB_YESNO | MB_ICONQUESTION) == IDYES)
                        {
                                //if "Yes" was clicked
                                //add record
                                DataModule1->NewbornsTable->Post();
                                //go back to beginner view
                                GroupBox->Hide();
                                InformationPanel->Show();
                        }
                }
        }
}
//---------------------------------------------------------------------------
/*                         PageControl's Events                            */
//---------------------------------------------------------------------------
void __fastcall TMainForm::PageControl1Change(TObject *Sender)
{
        //when pages were chenged
        //determine which page
        if (PageControl1->ActivePage == NewbornsSheet)
        {
                DBText1->DataSource = DataModule1->NewbornsDS;
                DBText1->DataField = "FIO";
                DBText2->DataSource = DataModule1->NewbornsDS;
                DBText2->DataField = "Sex";
                DBText3->DataSource = DataModule1->NewbornsDS;
                DBText3->DataField = "DateOfBirth";
                DBText4->DataSource = DataModule1->NewbornsDS;
                DBText4->DataField = "PlaceOfBirth";
                Label10->Hide();
                DBText5->Hide();
                Label11->Hide();
                DBText6->Hide();
                Label12->Hide();
                DBText7->Hide();
                Label13->Top = 112;
                DBText8->Top = 128;
                Label13->Show();
                DBText8->Show();
        }

        if (PageControl1->ActivePage == DeadsSheet)
        {
                DBText1->DataSource = DataModule1->DeadsDS;
                DBText1->DataField = "FIO";
                DBText2->DataSource = DataModule1->DeadsDS;
                DBText2->DataField = "Sex";
                DBText3->DataSource = DataModule1->DeadsDS;
                DBText3->DataField = "DateOfBirth";
                DBText4->DataSource = DataModule1->DeadsDS;
                DBText4->DataField = "PlaceOfBirth";
                Label10->Show();
                DBText5->Show();
                Label11->Show();
                DBText6->Show();
                Label12->Show();
                DBText7->Show();
                Label13->Hide();
                DBText8->Hide();
        }
}
//---------------------------------------------------------------------------
