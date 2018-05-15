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
        Word year,month,day;
        Word Year,Month,Day;
        QRGroup1->Height = 80;
        QRGroup2->Height = 80;
        QRGroup3->Height = 80;
        QRMemo1->Height = 24;
        QRMemo3->Height = 24;
        QRMemo6->Height = 24;
        DataModule1->DeadsTable->Active = true;
        DataModule1->DeadsTable->Filtered = true;
        DataModule1->DeadsTable->Filter = "Sex='��������'";
        DataModule1->DeadsTable->First();
        QRMemo1->Lines->Add("�������:");
        if (DataModule1->DeadsTable->RecordCount == 0)
        {
                QRMemo1->Lines->Add("���� �������");
                QRMemo1->Height += 24;
        }
        else
        {
                int menLife = 0;
                for (int i = 1; i <= DataModule1->DeadsTable->RecordCount; i++)
                {
                        DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfBirth")->Value,Year,Month,Day);
                        DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfDeath")->Value,year,month,day);
                        QRMemo1->Lines->Add(DataModule1->DeadsTable->FieldByName("FIO")->AsString);
                        menLife += (year - Year);
                        DataModule1->DeadsTable->Next();
                        QRMemo1->Height += 30;
                }
                menLife /= DataModule1->DeadsTable->RecordCount;
                QRLabel5->Caption = "������� ����������������� ����� � ������: " + IntToStr(menLife);
        }
        DataModule1->DeadsTable->Filtered = false;
        DataModule1->DeadsTable->Filtered = true;

        DataModule1->DeadsTable->Filter = "Sex='�������'";
        QRMemo1->Lines->Add("�������: ");
        if (DataModule1->DeadsTable->RecordCount == 0)
        {
                QRMemo1->Lines->Add("���� �������");
                QRMemo1->Height += 24;
        }
        else
        {
                int womenLife = 0;
                for (int i = 1; i <= DataModule1->DeadsTable->RecordCount; i++)
                {
                        DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfBirth")->Value,Year,Month,Day);
                        DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfDeath")->Value,year,month,day);
                        QRMemo1->Lines->Add(DataModule1->DeadsTable->FieldByName("FIO")->AsString);
                        DataModule1->DeadsTable->Next();
                        womenLife += (year - Year);
                        QRMemo1->Height += 30;
                }
                womenLife /= DataModule1->DeadsTable->RecordCount;
                QRLabel6->Caption = "������� ����������������� ����� � ������: " + IntToStr(womenLife);
        }
        QRGroup1->Height += QRMemo1->Height;
        DataModule1->DeadsTable->Filtered = false;
        DataModule1->DeadsTable->First();

        QRMemo3->Lines->Add("�� 25:");
        for (int i = 1; i <= DataModule1->DeadsTable->RecordCount; i++)
        {
                DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfBirth")->Value,Year,Month,Day);
                DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfDeath")->Value,year,month,day);
                if ((year - Year) <= 25)
                {
                        QRMemo3->Lines->Add(DataModule1->DeadsTable->FieldByName("FIO")->AsString);
                        QRMemo3->Height += 30;
                }
                DataModule1->DeadsTable->Next();
        }
        QRMemo3->Lines->Add("60:");
        DataModule1->DeadsTable->First();
        for (int i = 1; i <= DataModule1->DeadsTable->RecordCount; i++)
        {
                DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfBirth")->Value,Year,Month,Day);
                DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfDeath")->Value,year,month,day);
                if ((year - Year) <= 60 && (year - Year) > 25)
                {
                        QRMemo3->Lines->Add(DataModule1->DeadsTable->FieldByName("FIO")->AsString);
                        QRMemo3->Height += 30;
                }
                DataModule1->DeadsTable->Next();
        }
        DataModule1->DeadsTable->First();
        QRMemo3->Lines->Add("������ 60:");
        for (int i = 1; i <= DataModule1->DeadsTable->RecordCount; i++)
        {
                DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfBirth")->Value,Year,Month,Day);
                DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfDeath")->Value,year,month,day);
                if ((year - Year) > 60)
                {
                        QRMemo3->Lines->Add(DataModule1->DeadsTable->FieldByName("FIO")->AsString);
                        QRMemo3->Height += 30;
                }
                DataModule1->DeadsTable->Next();
        }
        int max;
        QRGroup2->Height += QRMemo3->Height;
        DataModule1->ReasonTable->Active = true;
        DataModule1->DeadsTable->Filtered = true;
        int size = DataModule1->ReasonTable->RecordCount;
        int *reasons = new int[size];
        DataModule1->ReasonTable->First();
        for (int i = 1; i <= size; i++)
        {
                if (DataModule1->ReasonTable->FieldByName("ReasonOfDeath")->AsString == "������")
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
                QRMemo6->Height += 24;
                DataModule1->ReasonTable->Next();
        }
        QRGroup3->Height += QRMemo6->Height;

        DataModule1->DeadsTable->First();
        max = 0;
        for (int i = 1; i <= DataModule1->DeadsTable->RecordCount; i++)
        {
                DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfBirth")->Value,Year,Month,Day);
                DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfDeath")->Value,year,month,day);
                if (max < (year - Year))
                {
                        max = (year - Year);
                }
                DataModule1->DeadsTable->Next();
        }

        DataModule1->DeadsTable->First();
        int count = 0;
        int i = 1;

        while (i <= max)
        {
                DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfBirth")->Value,Year,Month,Day);
                DecodeDate(DataModule1->DeadsTable->FieldByName("DateOfDeath")->Value,year,month,day);
                if ( i == (year - Year))
                {
                        count++;
                        if (DataModule1->DeadsTable->Eof)
                        {
                                count--;
                                QRChart1->Chart->Series[0]->AddXY(i, count);
                                i++;

                        }
                        DataModule1->DeadsTable->Next();
                }
                else
                {
                        QRChart1->Chart->Series[0]->AddXY(i, count);
                        count = 0;
                        i++;
                }
        }
        QuickRep1->Preview();
}
//---------------------------------------------------------------------------

