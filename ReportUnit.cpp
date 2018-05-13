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
        MainForm->Show();
        ReportForm->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TReportForm::FormShow(TObject *Sender)
{
        DataModule1->DeadsTable->Active = true;
        DataModule1->DeadsTable->Filtered = true;
        DataModule1->DeadsTable->Filter = "Sex='Муржской'";
        DataModule1->DeadsTable->First();
        for (int i = 1; i <= DataModule1->DeadsTable->RecordCount; i++)
        {
                QRMemo1->Lines->Add(DataModule1->DeadsTable->FieldByName("FIO")->AsString);
                DataModule1->DeadsTable->Next();
        }
        DataModule1->DeadsTable->Filtered = false;
        DataModule1->DeadsTable->Filtered = true;

        DataModule1->DeadsTable->Filter = "Sex='Женский'";
        for (int i = 1; i <= DataModule1->DeadsTable->RecordCount; i++)
        {
                QRMemo2->Lines->Add(DataModule1->DeadsTable->FieldByName("FIO")->AsString);
                DataModule1->DeadsTable->Next();
        }
        if (QRMemo1->Height > QRMemo2->Height)
        {
                QRStringsBand1->Height += QRMemo1->Height;
        }
        else if (QRMemo1->Height < QRMemo2->Height)
        {
                QRStringsBand1->Height += QRMemo2->Height;
        }
        DataModule1->DeadsTable->Filtered = false;
        Word year,month,day;
        Word Year,Month,Day;
        DataModule1->DeadsTable->First();
        QuickRep1->Preview();

        for (int i = 1; i <= DataModule1->DeadsTable->RecordCount; i++)
        {
                DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfBirth")->Value,Year,Month,Day);
                DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfDeath")->Value,year,month,day);
                if ((year - Year) <= 25)
                {
                        QRMemo3->Lines->Add(DataModule1->DeadsTable->FieldByName("FIO")->AsString);
                }
                else if ((year - Year) <= 60)
                {
                        QRMemo4->Lines->Add(DataModule1->DeadsTable->FieldByName("FIO")->AsString);
                }
                else
                {
                        QRMemo5->Lines->Add(DataModule1->DeadsTable->FieldByName("FIO")->AsString);
                }
                DataModule1->DeadsTable->Next();
        }
        int *height = new int[3];
        height[0] = QRMemo3->Height;
        height[1] = QRMemo4->Height;
        height[2] = QRMemo5->Height;
        int max = height[0];
        for (int i = 0; i < 3; i++)
        {
                if (height[i] > max)
                {
                        max = height[i];
                }
        }
        delete height;
        QRStringsBand2->Height += max;
        DataModule1->ReasonTable->Active = true;
        DataModule1->DeadsTable->Filtered = true;
        int size = DataModule1->ReasonTable->RecordCount;
        int *reasons = new int[size];
        DataModule1->ReasonTable->First();
        for (int i = 1; i <= size; i++)
        {
                if (DataModule1->ReasonTable->FieldByName("ReasonOfDeath")->AsString == "Другое")
                {
                        DataModule1->DeadsTable->Filtered = false;
                        reasons[i-1] = DataModule1->DeadsTable->RecordCount;
                        max = i-1;
                        DataModule1->DeadsTable->Filtered = true;
                }
                else
                {
                        DataModule1->DeadsTable->Filter = "ReasonOfDeath='" + DataModule1->ReasonTable->FieldByName("ReasonOfDeath")->AsString + "'";
                        reasons[i-1] = DataModule1->DeadsTable->RecordCount;
                        DataModule1->DeadsTable->Filtered = false;
                        DataModule1->DeadsTable->Filtered = true;
                }
                DataModule1->ReasonTable->Next();
        }
        DataModule1->DeadsTable->Filtered = false;
        for (int i = 0; i < size; i++)
        {
                if (max != i)
                {
                        reasons[max] -= reasons[i];
                }
        }

        DataModule1->ReasonTable->First();
        for (int i = 1; i <= size; i++)
        {
                QRMemo6->Lines->Add(DataModule1->ReasonTable->FieldByName("ReasonOfDeath")->AsString + ": " + IntToStr(reasons[i-1]));
                DataModule1->ReasonTable->Next();
        }
        QRStringsBand3->Height += QRMemo6->Height;
        QuickRep1->Preview();
}
//---------------------------------------------------------------------------

