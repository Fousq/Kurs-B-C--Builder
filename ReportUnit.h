//---------------------------------------------------------------------------

#ifndef ReportUnitH
#define ReportUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
#include <Chart.hpp>
#include <DbChart.hpp>
#include <QRTEE.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TReportForm : public TForm
{
__published:	// IDE-managed Components
        TQuickRep *QuickRep1;
        TQRBand *QRBand1;
        TQRLabel *QRLabel1;
        TQRLabel *QRLabel3;
        TQRMemo *QRMemo3;
        TQRLabel *QRLabel4;
        TQRMemo *QRMemo6;
        TQRLabel *QRLabel2;
        TQRMemo *QRMemo1;
        TQRGroup *QRGroup1;
        TQRGroup *QRGroup2;
        TQRGroup *QRGroup3;
        TQRGroup *QRGroup4;
        TQRLabel *QRLabel5;
        TQRLabel *QRLabel6;
        TQRDBChart *QRDBChart1;
        TQRChart *QRChart1;
        TQRLabel *QRLabel7;
        TLineSeries *Series1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TReportForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TReportForm *ReportForm;
//---------------------------------------------------------------------------
#endif
