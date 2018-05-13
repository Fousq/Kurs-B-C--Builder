//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
//Bound MainForm to DataModule1
#include "DataModule.h"
//Bound ReportForm to MainForm
#include "ReportUnit.h"
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

void __fastcall TMainForm::FormShow(TObject *Sender)
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
        DBText8->Top = 132;
        Label13->Show();
        DBText8->Show();
}
//---------------------------------------------------------------------------
/*                              Buttons                                    */
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddButtonClick(TObject *Sender)
{
        //if button "Add" was clicked
        DBComboBox1->Items->Add("��������");
        DBComboBox1->Items->Add("�������");
        GroupBox->Caption = "�������� ������";
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
                DBComboBox1->DataSource = DataModule1->NewbornsDS;
                DBComboBox1->DataField = "Sex";
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
                DBComboBox1->DataSource = DataModule1->DeadsDS;
                DBComboBox1->DataField = "Sex";
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
                        ErrorMessage += " �������, ���, ��������";
                }

                if (DBComboBox1->Text == "")
                {
                        Empty = true;
                        DBComboBox1->Color = clRed;
                        ErrorMessage += " ���";
                }

                if (DBEdit3->Text == "")
                {
                        Empty = true;
                        DBEdit3->Color = clRed;
                        ErrorMessage += " ���� ��������";
                }

                if (DBEdit4->Text == "")
                {
                        Empty = true;
                        DBEdit4->Color = clRed;
                        ErrorMessage += " ����� ��������";
                }

                if (DBMemo1->Text == "")
                {
                        Empty = true;
                        DBMemo1->Color = clRed;
                        ErrorMessage += " �������� � ���������";
                }

                if (Empty)
                {
                        //if one of the fildes is empty, the message will be shown up
                        Application->MessageBoxA(("��������� ��������� ����: " + ErrorMessage).c_str(), "������ ����", MB_ICONERROR);
                        return;
                }
                else
                {
                        //get the confirmation
                        if (Application->MessageBoxA("��������� �� �� ����� ��� ������?", "�������������", MB_YESNO | MB_ICONQUESTION) == IDYES)
                        {
                                //if "Yes" was clicked
                                //add  or change record
                                DataModule1->NewbornsTable->Post();
                                //go back to beginner view
                                GroupBox->Hide();
                                InformationPanel->Show();
                        }
                }
        }

        if (PageControl1->ActivePage == DeadsSheet)
        {
                if (DBEdit1->Text == "")
                {
                        Empty = true;
                        //change color of field to highlight empty field
                        DBEdit1->Color = clRed;
                        ErrorMessage += " �������, ���, ��������";
                }

                if (DBComboBox1->Text == "")
                {
                        Empty = true;
                        DBComboBox1->Color = clRed;
                        ErrorMessage += " ���";
                }

                if (DBEdit3->Text == "")
                {
                        Empty = true;
                        DBEdit3->Color = clRed;
                        ErrorMessage += " ���� ��������";
                }

                if (DBEdit4->Text == "")
                {
                        Empty = true;
                        DBEdit4->Color = clRed;
                        ErrorMessage += " ����� ��������";
                }

                if (DBEdit5->Text == "")
                {
                        Empty = true;
                        DBEdit5->Color = clRed;
                        ErrorMessage += " ���� ������";
                }

                if (DBEdit6->Text == "")
                {
                        Empty = true;
                        DBEdit6->Color = clRed;
                        ErrorMessage += " ����� ������";
                }

                if (DBEdit7->Text == "")
                {
                        Empty = true;
                        DBEdit7->Color = clRed;
                        ErrorMessage += " ������� ������";
                }

                 if (Empty)
                {
                        //if one of the fildes is empty, the message will be shown up
                        Application->MessageBoxA(("��������� ��������� ����: " + ErrorMessage).c_str(), "������ ����", MB_ICONERROR);
                        return;
                }
                else
                {
                        //get the confirmation
                        if (Application->MessageBoxA("��������� �� �� ����� ��� ������?", "�������������", MB_YESNO | MB_ICONQUESTION) == IDYES)
                        {
                                //if "Yes" was clicked
                                //add  or change record
                                DataModule1->DeadsTable->Post();
                                //go back to beginner view
                                GroupBox->Hide();
                                InformationPanel->Show();
                        }
                }
        }
        //for refrashing
        DBComboBox1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EditButtonClick(TObject *Sender)
{
        //Edit was clicked
        DBComboBox1->Items->Add("��������");
        DBComboBox1->Items->Add("�������");
        GroupBox->Caption = "������������� ������";
        InformationPanel->Hide();
        GroupBox->Show();
        GroupBox->Top = 24;
        GroupBox->Left = 520;

        if (PageControl1->ActivePage == NewbornsSheet)
        {
                //if page is "Newborns"
                DBEdit1->DataSource = DataModule1->NewbornsDS;
                DBEdit1->DataField = "FIO";
                DBComboBox1->DataSource = DataModule1->NewbornsDS;
                DBComboBox1->DataField = "Sex";
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
                //turn our data base to edit mode
                DataModule1->NewbornsTable->Edit();
        }

        if (PageControl1->ActivePage == DeadsSheet)
        {
                //if page is "Deads"
                DBEdit1->DataSource = DataModule1->DeadsDS;
                DBEdit1->DataField = "FIO";
                DBComboBox1->DataSource = DataModule1->DeadsDS;
                DBComboBox1->DataField = "Sex";
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
                //turn our data base to edit mode
                DataModule1->DeadsTable->Edit();
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DeleteButtonClick(TObject *Sender)
{
        //if Delete button was clicked
        //ask if you are sure about deleting the record
        if (Application->MessageBoxA("������ �� �� ������� ��� ������?", "�������������", MB_ICONQUESTION | MB_YESNO) == IDYES)
        {
                if (PageControl1->ActivePage == NewbornsSheet)
                {
                        //delete record in data base "Newborns"
                        DataModule1->NewbornsTable->Delete();
                }

                if (PageControl1->ActivePage == DeadsSheet)
                {
                        //delete record in data base "Deads"
                        DataModule1->DeadsTable->Delete();
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CancelButtonClick(TObject *Sender)
{
        //if cancel button was clicked
        if (PageControl1->ActivePage == NewbornsSheet)
        {
                //cancel the operation
                DataModule1->NewbornsTable->Cancel();
                //back to beginner view
                GroupBox->Hide();
                InformationPanel->Show();
        }

        if (PageControl1->ActivePage == DeadsSheet)
        {
                //the same
                DataModule1->DeadsTable->Cancel();
                GroupBox->Hide();
                InformationPanel->Show();
        }
        //for refrashing
        DBComboBox1->Clear();
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
                //if page was chenged while being in some data base operation
                //cancel this operation
                DataModule1->DeadsTable->Cancel();
                GroupBox->Hide();
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
                DBText8->Top = 132;
                Label13->Show();
                DBText8->Show();
                //change some fields and then show them
                InformationPanel->Show();
        }

        if (PageControl1->ActivePage == DeadsSheet)
        {
                //the same
                DataModule1->NewbornsTable->Cancel();
                GroupBox->Hide();
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
                InformationPanel->Show();
        }
}
//---------------------------------------------------------------------------
/*                         ActionList                                      */
//---------------------------------------------------------------------------
void __fastcall TMainForm::AopenExecute(TObject *Sender)
{
        //if open field was clicked
        //active data bases
        DataModule1->NewbornsTable->Active = true;
        DataModule1->DeadsTable->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AexitExecute(TObject *Sender)
{
        //if exit field was clicked
        //deactivate data bases
        DataModule1->NewbornsTable->Active = false;
        DataModule1->DeadsTable->Active = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AopenRepExecute(TObject *Sender)
{
        //if open report was clicked
        //go to report form
        ReportForm->Show();
        MainForm->Hide();
}
//---------------------------------------------------------------------------
/*                         DBEdit                                          */
//---------------------------------------------------------------------------
//Change color of elements back to normal
void __fastcall TMainForm::DBEdit1Click(TObject *Sender)
{
        DBEdit1->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DBEdit3Click(TObject *Sender)
{
        DBEdit3->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DBEdit4Click(TObject *Sender)
{
        DBEdit4->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DBEdit5Click(TObject *Sender)
{
        DBEdit5->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DBEdit6Click(TObject *Sender)
{
        DBEdit6->Color = clWindow;        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DBEdit7Click(TObject *Sender)
{
        DBEdit7->Color = clWindow;
}
//---------------------------------------------------------------------------
/*                         DBComboBox                                      */
//---------------------------------------------------------------------------
void __fastcall TMainForm::DBComboBox1Click(TObject *Sender)
{
        DBComboBox1->Color = clWindow;
}
//---------------------------------------------------------------------------
/*                          DBMemo                                         */
//---------------------------------------------------------------------------
void __fastcall TMainForm::DBMemo1Click(TObject *Sender)
{
        DBMemo1->Color = clWindow;
}
//---------------------------------------------------------------------------

