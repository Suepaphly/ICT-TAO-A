//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DigitsPanel"
#pragma resource "*.dfm"
TForm1 *Form1;
HANDLE hCom1;
COMMTIMEOUTS toCom1;
DWORD dwAct;
RS232 *ReadThread;
#include "rs232.h"
Rs232 rs232;
int fg_wait_escrow,receive_money,Accept_ON,STACK_MONEY_COUNT;
char  InIdiling=1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  AnsiString COMM,BAUD;
  TStrings *list=new TStringList;
  char *Com,*baud;

  list->LoadFromFile("comm.ini");
  COMM=list->Strings[1].Delete(1,5).c_str();
  Com=COMM.c_str();
  BAUD=list->Strings[2].Delete(1,5).c_str();
  baud=BAUD.c_str();
  STACK_MONEY_COUNT=0;

  list->LoadFromFile("BILLVALUE.TXT");
  for( int i=0; i<list->Count; i++ )
  {
      switch (i)
      {
        case  0:
            CheckBox1->Caption=list->Strings[i];
        break;
        case  1:
            CheckBox2->Caption=list->Strings[i];
        break;
        case  2:
            CheckBox3->Caption=list->Strings[i];
        break;
        case  3:
            CheckBox4->Caption=list->Strings[i];
        break;
        case  4:
            CheckBox5->Caption=list->Strings[i];
        break;
        case  5:
            CheckBox6->Caption=list->Strings[i];
        break;
      }
  }

  delete list;

  if(rs232.SetComPort(hCom1,toCom1,Com,baud))
  {
    Form1->StatusBar1->Panels->Items[1]->Text=Com;
    ReadThread=new RS232(false);
  }
  else
  {
    ShowMessage("The COM open error !");
    exit(0);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  rs232.Exit(hCom1);
  exit(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn6Click(TObject *Sender)
{
  if(fg_wait_escrow==1)
  {
    fg_wait_escrow=0;
    Accept_ON=0;
    rs232.TransferComm(hCom1,0x02);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn7Click(TObject *Sender)
{
  if(fg_wait_escrow==1)
  {
    fg_wait_escrow=0;
    rs232.TransferComm(hCom1,0x0F);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn8Click(TObject *Sender)
{
  Edit1->Text=0;
  Edit2->Text=0;
  Edit3->Text=0;
  STACK_MONEY_COUNT=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
   if( InIdiling==1 )
   {
     rs232.TransferComm(hCom1,0x0C);
   }    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup2Click(TObject *Sender)
{
  if(Form1->RadioGroup2->ItemIndex==0)
  {rs232.TransferComm(hCom1,62);}
  else
  {rs232.TransferComm(hCom1,94);}
}
//---------------------------------------------------------------------------

