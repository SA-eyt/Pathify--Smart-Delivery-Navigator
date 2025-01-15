//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *curren;
	TEdit *box;
	TLabel *destinatio;
	TEdit *boxx;
	TButton *Button1;
	TLabel *fue;
	TEdit *boxxx;
	TLabel *spee;
	TEdit *boxxxx;
	TLabel *pathify;
	TLabel *slogen;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *f;
	TLabel *t;
	TLabel *d;
	TLabel *p;
	TLabel *Label4;
	TLabel *Label7;
	TButton *Button2;
	TScrollBar *ScrollBar1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
