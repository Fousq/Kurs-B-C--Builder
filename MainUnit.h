//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TActionList *ActionList1;
        TAction *Aopen;
        TAction *Aexit;
        TAction *AopenRep;
        TAction *Aguide;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TPageControl *PageControl1;
        TTabSheet *NewbornsSheet;
        TTabSheet *DeadsSheet;
        TDBGrid *DBGrid1;
        TDBGrid *DBGrid2;
        TGroupBox *GroupBox;
        TButton *AddButton;
        TButton *EditButton;
        TButton *DeleteButton;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TPanel *InformationPanel;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TDBText *DBText1;
        TLabel *Label13;
        TDBText *DBText2;
        TDBText *DBText3;
        TDBText *DBText4;
        TDBText *DBText5;
        TDBText *DBText6;
        TDBText *DBText7;
        TDBText *DBText8;
        TDBEdit *DBEdit1;
        TDBEdit *DBEdit3;
        TDBEdit *DBEdit4;
        TLabel *Label14;
        TLabel *Label15;
        TDBEdit *DBEdit5;
        TDBEdit *DBEdit6;
        TDBMemo *DBMemo1;
        TDBEdit *DBEdit7;
        TLabel *Label16;
        TButton *CancelButton;
        TButton *ConfirmButton;
        TDBComboBox *DBComboBox1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall AddButtonClick(TObject *Sender);
        void __fastcall PageControl1Change(TObject *Sender);
        void __fastcall ConfirmButtonClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall EditButtonClick(TObject *Sender);
        void __fastcall DeleteButtonClick(TObject *Sender);
        void __fastcall CancelButtonClick(TObject *Sender);
        void __fastcall AopenExecute(TObject *Sender);
        void __fastcall AexitExecute(TObject *Sender);
        void __fastcall AopenRepExecute(TObject *Sender);
        void __fastcall DBEdit1Click(TObject *Sender);
        void __fastcall DBEdit3Click(TObject *Sender);
        void __fastcall DBEdit4Click(TObject *Sender);
        void __fastcall DBEdit5Click(TObject *Sender);
        void __fastcall DBEdit6Click(TObject *Sender);
        void __fastcall DBEdit7Click(TObject *Sender);
        void __fastcall DBComboBox1Click(TObject *Sender);
        void __fastcall DBMemo1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
