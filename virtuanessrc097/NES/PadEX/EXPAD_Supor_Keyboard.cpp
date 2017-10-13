#include "EmuThread.h"

/////////////////////////////////////////////////////////////////////////
// Supor Keyboard                                                       //
//////////////////////////////////////////////////////////////////////////
void	EXPAD_Supor_Keyboard::Reset()
{
	bGraph = FALSE;
	bOut = FALSE;
	ScanNo = 0;

	DirectInput.SetCapsLock(TRUE);
}

BYTE	EXPAD_Supor_Keyboard::Read4016()
{
	BYTE	data = 0;

	return	data;
}

BYTE	EXPAD_Supor_Keyboard::Read4017()
{
	BYTE	data = 0xFF;
	BOOL	setzero = FALSE;
	std::vector<BYTE>	hits;
	if (DirectInput.HasTypedKeys()) {
		setzero = DirectInput.LoadTypedKeys();
	}
	switch( ScanNo ) {
		case	1:
			if( bOut ) {
				if (DirectInput.m_Sw[DIK_4])
				{
					data &= ~0x02;
					hits.push_back(DIK_4);
				}
				if( DirectInput.m_Sw[DIK_G       ] ) 
				{
					data &= ~0x04;
					hits.push_back(DIK_G);
				}
				if( DirectInput.m_Sw[DIK_F       ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_F);
				}
				if( DirectInput.m_Sw[DIK_C       ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_C);
				}
			} else {
				if( DirectInput.m_Sw[DIK_F2       ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_F2);
				}
				if( DirectInput.m_Sw[DIK_E        ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_E);
				}
				if( DirectInput.m_Sw[DIK_5        ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_5);
				}
				if( DirectInput.m_Sw[DIK_V        ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_V);
				}
			}
			break;
		case	2:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_2        ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_2);
				}
				if( DirectInput.m_Sw[DIK_D        ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_D);
				}
				if( DirectInput.m_Sw[DIK_S        ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_S);
				}
				if( DirectInput.m_Sw[DIK_END      ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_END);
				}
			} else {
				if( DirectInput.m_Sw[DIK_F1       ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_F1);
				}
				if( DirectInput.m_Sw[DIK_W         ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_W);
				}
				if( DirectInput.m_Sw[DIK_3         ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_3);
				}
				if( DirectInput.m_Sw[DIK_X         ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_X);
				}
			}
			break;
		case	3:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_INSERT    ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_INSERT);
				}
				if( DirectInput.m_Sw[DIK_BACK      ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_BACK);
				}
				if( DirectInput.m_Sw[DIK_NEXT      ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_NEXT);
				}
				if( DirectInput.m_Sw[DIK_RIGHT     ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_RIGHT);
				}
			} else {
				if( DirectInput.m_Sw[DIK_F8    ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_F8);
				}
				if( DirectInput.m_Sw[DIK_PRIOR ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_PRIOR);
				}
				if( DirectInput.m_Sw[DIK_DELETE] )
				{
					data &= ~0x08;
					hits.push_back(DIK_DELETE);
				}
				if( DirectInput.m_Sw[DIK_HOME  ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_HOME);
				}
			}
			break;
		case	4:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_9     ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_9);
				}
				if( DirectInput.m_Sw[DIK_I     ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_I);
				}
				if( DirectInput.m_Sw[DIK_L     ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_L);
				}
				if( DirectInput.m_Sw[DIK_COMMA ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_COMMA);
				}
			} else {
				if( DirectInput.m_Sw[DIK_F5     ] )
				{
					data &= ~0x02;
					hits.push_back(DIK_F5);
				}
				if( DirectInput.m_Sw[DIK_O      ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_O);
				}
				if( DirectInput.m_Sw[DIK_0      ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_0);
				}
				if( DirectInput.m_Sw[DIK_PERIOD ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_PERIOD);
				}
			}
			break;
		case	5:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_RBRACKET ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_RBRACKET);
				}
				if( DirectInput.m_Sw[DIK_RETURN   ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_RETURN);
				}
				if( DirectInput.m_Sw[DIK_UP       ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_UP);
				}
				if( DirectInput.m_Sw[DIK_LEFT     ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_LEFT);
				}
			} else {
				if( DirectInput.m_Sw[DIK_F7        ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_F7);
				}
				if( DirectInput.m_Sw[DIK_LBRACKET  ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_LBRACKET);
				}
				if( DirectInput.m_Sw[DIK_BACKSLASH ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_BACKSLASH);
				}
				if( DirectInput.m_Sw[DIK_DOWN      ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_DOWN);
				}
			}
			break;
		case	6:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_Q       ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_Q);
				}
				if( DirectInput.m_Sw[DIK_CAPITAL ] )
				{
					//Toggle caps lock
					DirectInput.SetCapsLock(!DirectInput.GetCapsLock());

					data &= ~0x04;
					hits.push_back(DIK_CAPITAL);
				}
				if( DirectInput.m_Sw[DIK_Z       ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_Z);
				}
				if( DirectInput.m_Sw[DIK_TAB     ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_TAB);
				}
			} else {
				if( DirectInput.m_Sw[DIK_ESCAPE   ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_ESCAPE);
				}
				if( DirectInput.m_Sw[DIK_A        ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_A);
				}
				if( DirectInput.m_Sw[DIK_1        ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_1);
				}
				if( DirectInput.m_Sw[DIK_LCONTROL ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_LCONTROL);
				}
			}
			break;
		case	7:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_7 ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_7);
				}
				if( DirectInput.m_Sw[DIK_Y ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_Y);
				}
				if( DirectInput.m_Sw[DIK_K ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_K);
				}
				if( DirectInput.m_Sw[DIK_M ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_M);
				}
			} else {
				if( DirectInput.m_Sw[DIK_F4 ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_F4);
				}
				if( DirectInput.m_Sw[DIK_U  ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_U);
				}
				if( DirectInput.m_Sw[DIK_8  ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_8);
				}
				if( DirectInput.m_Sw[DIK_J  ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_J);
				}
			}
			break;
		case	8:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_MINUS      ] )
				{
					data &= ~0x02;
					hits.push_back(DIK_MINUS);
				}
				if( DirectInput.m_Sw[DIK_SEMICOLON  ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_SEMICOLON);
				}
				if( DirectInput.m_Sw[DIK_APOSTROPHE ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_APOSTROPHE);
				}
				if( DirectInput.m_Sw[DIK_SLASH      ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_SLASH);
				}
			} else {
				if( DirectInput.m_Sw[DIK_F6     ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_F6);
				}
				if( DirectInput.m_Sw[DIK_P      ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_P);
				}
				if( DirectInput.m_Sw[DIK_EQUALS ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_EQUALS);
				}
				if( DirectInput.m_Sw[DIK_LSHIFT ] ||
					DirectInput.m_Sw[DIK_RSHIFT ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_RSHIFT);
				}
			}
			break;
		case	9:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_T     ] )
				{
					data &= ~0x02;
					hits.push_back(DIK_T);
				}
				if( DirectInput.m_Sw[DIK_H     ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_H);
				}
				if( DirectInput.m_Sw[DIK_N     ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_N);
				}
				if( DirectInput.m_Sw[DIK_SPACE ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_SPACE);
				}
			} else {
				if( DirectInput.m_Sw[DIK_F3 ] )
				{
					data &= ~0x02;
					hits.push_back(DIK_F3);
				}
				if( DirectInput.m_Sw[DIK_R  ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_R);
				}
				if( DirectInput.m_Sw[DIK_6  ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_6);
				}
				if( DirectInput.m_Sw[DIK_B  ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_B);
				}
			}
			break;
		case	10:
			if( bOut ) {
			} else {
				data &= ~0x02;
				//hits.push_back(0);
				//hits.push_back(0);
			}
			break;
		case	11:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_LMENU   ] )
				{
					data &= ~0x02;
					hits.push_back(DIK_LMENU);
				}
				if( DirectInput.m_Sw[DIK_NUMPAD4 ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_NUMPAD4);
				}
				if( DirectInput.m_Sw[DIK_NUMPAD7 ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_NUMPAD7);
				}
				if( DirectInput.m_Sw[DIK_F11     ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_F11);
				}
			} else {
				if( DirectInput.m_Sw[DIK_F12     ] )
				{
					data &= ~0x02;
					hits.push_back(DIK_F12);
				}
				if( DirectInput.m_Sw[DIK_NUMPAD1 ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_NUMPAD1);
				}
				if( DirectInput.m_Sw[DIK_NUMPAD2 ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_NUMPAD2);
				}
				if( DirectInput.m_Sw[DIK_NUMPAD8 ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_NUMPAD8);
				}
			}
			break;
		case	12:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_SUBTRACT ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_SUBTRACT);
				}
				if( DirectInput.m_Sw[DIK_ADD      ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_ADD);
				}
				if( DirectInput.m_Sw[DIK_MULTIPLY ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_MULTIPLY);
				}
				if( DirectInput.m_Sw[DIK_NUMPAD9  ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_NUMPAD9);
				}
			} else {
				if( DirectInput.m_Sw[DIK_F10     ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_F10);
				}
				if( DirectInput.m_Sw[DIK_NUMPAD5 ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_NUMPAD5);
				}
				if( DirectInput.m_Sw[DIK_DIVIDE  ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_DIVIDE);
				}
				if( DirectInput.m_Sw[DIK_NUMLOCK ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_NUMLOCK);
				}
			}
			break;
		case	13:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_GRAVE   ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_GRAVE);
				}
				if( DirectInput.m_Sw[DIK_NUMPAD6 ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_NUMPAD6);
				}
				if( DirectInput.m_Sw[DIK_PAUSE   ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_PAUSE);
					//simulate G-BASIC reset
					Emu.GetNES()->GotoGBasicReset();

				}
				if( DirectInput.m_Sw[DIK_SPACE ] ) 
				{
					data &= ~0x10;
					hits.push_back(DIK_SPACE);
				}
			} else {
				if( DirectInput.m_Sw[DIK_F9      ] ) 
				{
					data &= ~0x02;
					hits.push_back(DIK_F9);
				}
				if( DirectInput.m_Sw[DIK_NUMPAD3 ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_NUMPAD3);
				}
				if( DirectInput.m_Sw[DIK_DECIMAL ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_DECIMAL);
				}
				if( DirectInput.m_Sw[DIK_NUMPAD0 ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_NUMPAD0);
				}
			}
			break;
	}
	if (hits.size()>0 
		|| (hits.size() == 0 && setzero))
	{
		DirectInput.ConfirmTypedKeys();
	}
	return	data;
}

void	EXPAD_Supor_Keyboard::Write4016( BYTE data )
{
	if( data == 0x05 ) {
		bOut = FALSE;
		ScanNo = 0;
	} else if( data == 0x04 ) {
		if( ++ScanNo > 13 )
			ScanNo = 0;
		bOut = !bOut;
	} else if( data == 0x06 ) {
		bOut = !bOut;
	}
}

