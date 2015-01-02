// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DigitsPanel.pas' rev: 5.00

#ifndef DigitsPanelHPP
#define DigitsPanelHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ExtCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Digitspanel
{
//-- type declarations -------------------------------------------------------
typedef Shortint TDigitsLength;

class DELPHICLASS TDigitsPanel;
class PASCALIMPLEMENTATION TDigitsPanel : public Controls::TGraphicControl 
{
	typedef Controls::TGraphicControl inherited;
	
private:
	Graphics::TBitmap* FDigits;
	Word FDigitWidth;
	Word FDigitHeight;
	Controls::TBevelCut FBevelOuter;
	Controls::TBevelCut FBevelInner;
	Byte FBevelWidth;
	Graphics::TColor FColor;
	TDigitsLength FLength;
	Byte FMargin;
	int FValue;
	
protected:
	void __fastcall SetDigits(Graphics::TBitmap* Value);
	void __fastcall SetBevelOuter(Controls::TBevelCut Value);
	void __fastcall SetBevelInner(Controls::TBevelCut Value);
	void __fastcall SetBevelWidth(Byte Value);
	HIDESBASE void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetLength(TDigitsLength Value);
	void __fastcall SetMargin(Byte Value);
	void __fastcall SetValue(int Value);
	void __fastcall DigitsChanged(System::TObject* Sender);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TDigitsPanel(Classes::TComponent* AOwner);
	__fastcall virtual ~TDigitsPanel(void);
	
__published:
	__property Graphics::TBitmap* Digits = {read=FDigits, write=SetDigits};
	__property Controls::TBevelCut BevelOuter = {read=FBevelOuter, write=SetBevelOuter, default=2};
	__property Controls::TBevelCut BevelInner = {read=FBevelInner, write=SetBevelInner, default=1};
	__property Byte BevelWidth = {read=FBevelWidth, write=SetBevelWidth, default=2};
	__property Graphics::TColor Color = {read=FColor, write=SetColor, default=0};
	__property TDigitsLength Length = {read=FLength, write=SetLength, default=4};
	__property Byte Margin = {read=FMargin, write=SetMargin, default=2};
	__property int Value = {read=FValue, write=SetValue, default=0};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);

}	/* namespace Digitspanel */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Digitspanel;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DigitsPanel
