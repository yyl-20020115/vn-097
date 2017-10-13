//////////////////////////////////////////////////////////////////////////
// Family Basic Keyboard                                                //
//////////////////////////////////////////////////////////////////////////
void	EXPAD_Keyboard::Reset()
{
	bGraph = FALSE;
	bOut = FALSE;
	ScanNo = 0;
}

BYTE	EXPAD_Keyboard::Read4016()
{
BYTE	data = 0;

	return	data;
}

BYTE	EXPAD_Keyboard::Read4017()
{
	BYTE	data = 0;
	BOOL	setzero = FALSE;
	std::vector<BYTE> hits;
	if (DirectInput.HasTypedKeys()) {
		setzero = DirectInput.LoadTypedKeys();
	}
	if( ScanNo ) {
		data = 0x1E;
	}

	if (DirectInput.m_Sw[DIK_NEXT])
	{
		bGraph = TRUE;
	}
	if (DirectInput.m_Sw[DIK_PRIOR])
	{
		bGraph = FALSE;
	}
	switch( ScanNo ) {
		case	1:
			if( bOut ) {
				if (DirectInput.m_Sw[DIK_F8])
				{
					data &= ~0x02;
					hits.push_back(DIK_F8);
				}
				if (DirectInput.m_Sw[DIK_RETURN])
				{
					data &= ~0x04;
					hits.push_back(DIK_RETURN);
				}
				if (DirectInput.m_Sw[DIK_LBRACKET])
				{
					data &= ~0x08;
					hits.push_back(DIK_LBRACKET);
				}
				if (DirectInput.m_Sw[DIK_RBRACKET]) 
				{
					data &= ~0x10;
					hits.push_back(DIK_RBRACKET);
				}
			} else {
				if (DirectInput.m_Sw[DIK_F12])
				{
					data &= ~0x02;
					hits.push_back(DIK_F12);
				}
				if (DirectInput.m_Sw[DIK_RSHIFT])
				{
					data &= ~0x04;
					hits.push_back(DIK_RSHIFT);
				}
				if (DirectInput.m_Sw[DIK_BACKSLASH]
					|| DirectInput.m_Sw[DIK_YEN])
				{
					data &= ~0x08;
					hits.push_back(DIK_BACKSLASH);
				}
				if (DirectInput.m_Sw[DIK_END])
				{
					data &= ~0x10;
					hits.push_back(DIK_END);
				}
			}
			break;
		case	2:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_F7       ] )
				{
					data &= ~0x02;
					hits.push_back(DIK_F7);
				}
				if( DirectInput.m_Sw[DIK_AT       ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_AT);
				}
				if( DirectInput.m_Sw[DIK_COLON    ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_COLON);
				}
				if( DirectInput.m_Sw[DIK_SEMICOLON] )
				{
					data &= ~0x100;
					hits.push_back(DIK_SEMICOLON);
				}
			} else {
				if( DirectInput.m_Sw[DIK_UNDERLINE ] )
				{
					data &= ~0x02;
					hits.push_back(DIK_UNDERLINE);
				}
				if( DirectInput.m_Sw[DIK_SLASH     ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_SLASH);
				}
				if( DirectInput.m_Sw[DIK_MINUS     ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_MINUS);
				}
				if( DirectInput.m_Sw[DIK_CIRCUMFLEX] )
				{
					data &= ~0x10;
					hits.push_back(DIK_CIRCUMFLEX);
				}
			}
			break;
		case	3:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_F6] )
				{
					data &= ~0x02;
					hits.push_back(DIK_F6);
				}
				if( DirectInput.m_Sw[DIK_O ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_O);
				}
				if( DirectInput.m_Sw[DIK_L ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_L);
				}
				if( DirectInput.m_Sw[DIK_K ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_K);
				}
			} else {
				if( DirectInput.m_Sw[DIK_PERIOD] )
				{
					data &= ~0x02;
					hits.push_back(DIK_PERIOD);
				}
				if( DirectInput.m_Sw[DIK_COMMA ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_COMMA);
				}
				if( DirectInput.m_Sw[DIK_P     ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_P);
				}
				if( DirectInput.m_Sw[DIK_0     ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_0);
				}
			}
			break;
		case	4:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_F5] )
				{
					data &= ~0x02;
					hits.push_back(DIK_F5);
				}
				if( DirectInput.m_Sw[DIK_I ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_I);
				}
				if( DirectInput.m_Sw[DIK_U ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_U);
				}
				if( DirectInput.m_Sw[DIK_J ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_J);
				}
			} else {
				if( DirectInput.m_Sw[DIK_M] )
				{
					data &= ~0x02;
					hits.push_back(DIK_M);
				}
				if( DirectInput.m_Sw[DIK_N] )
				{
					data &= ~0x04;
					hits.push_back(DIK_N);
				}
				if( DirectInput.m_Sw[DIK_9] )
				{
					data &= ~0x08;
					hits.push_back(DIK_9);
				}
				if( DirectInput.m_Sw[DIK_8] )
				{
					data &= ~0x10;
					hits.push_back(DIK_8);
				}
			}
			break;
		case	5:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_F4] )
				{
					data &= ~0x02;
					hits.push_back(DIK_F4);
				}
				if( DirectInput.m_Sw[DIK_Y ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_Y);
				}
				if( DirectInput.m_Sw[DIK_G ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_G);
				}
				if( DirectInput.m_Sw[DIK_H ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_H);
				}
			} else {
				if( DirectInput.m_Sw[DIK_B] )
				{
					data &= ~0x02;
					hits.push_back(DIK_B);
				}
				if( DirectInput.m_Sw[DIK_V] )
				{
					data &= ~0x04;
					hits.push_back(DIK_V);
				}
				if( DirectInput.m_Sw[DIK_7] )
				{
					data &= ~0x08;
					hits.push_back(DIK_7);
				}
				if( DirectInput.m_Sw[DIK_6] )
				{
					data &= ~0x10;
					hits.push_back(DIK_6);
				}
			}
			break;
		case	6:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_F3] )
				{
					data &= ~0x02;
					hits.push_back(DIK_F3);
				}
				if( DirectInput.m_Sw[DIK_T ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_T);
				}
				if( DirectInput.m_Sw[DIK_R ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_R);
				}
				if( DirectInput.m_Sw[DIK_D ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_D);
				}
			} else {
				if( DirectInput.m_Sw[DIK_F] )
				{
					data &= ~0x02;
					hits.push_back(DIK_F);
				}
				if( DirectInput.m_Sw[DIK_C] )
				{
					data &= ~0x04;
					hits.push_back(DIK_C);
				}
				if( DirectInput.m_Sw[DIK_5] )
				{
					data &= ~0x08;
					hits.push_back(DIK_5);
				}
				if( DirectInput.m_Sw[DIK_4] )
				{
					data &= ~0x10;
					hits.push_back(DIK_4);
				}
			}
			break;
		case	7:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_F2] )
				{
					data &= ~0x02;
					hits.push_back(DIK_F2);
				}
				if( DirectInput.m_Sw[DIK_W ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_W);
				}
				if( DirectInput.m_Sw[DIK_S ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_S);
				}
				if( DirectInput.m_Sw[DIK_A ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_A);
				}
			} else {
				if( DirectInput.m_Sw[DIK_X] )
				{
					data &= ~0x02;
					hits.push_back(DIK_X);
				}
				if( DirectInput.m_Sw[DIK_Z] )
				{
					data &= ~0x04;
					hits.push_back(DIK_Z);
				}
				if( DirectInput.m_Sw[DIK_E] )
				{
					data &= ~0x08;
					hits.push_back(DIK_E);
				}
				if( DirectInput.m_Sw[DIK_3] )
				{
					data &= ~0x10;
					hits.push_back(DIK_3);
				}
			}
			break;
		case	8:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_F1      ] )
				{
					data &= ~0x02;
					hits.push_back(DIK_F1);
				}
				if( DirectInput.m_Sw[DIK_ESCAPE  ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_ESCAPE);
				}
				if( DirectInput.m_Sw[DIK_Q       ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_Q);
				}
				if( DirectInput.m_Sw[DIK_LCONTROL]
				 || DirectInput.m_Sw[DIK_RCONTROL] )
				{
					data &= ~0x10;
					hits.push_back(DIK_LCONTROL);
				}
			} else {
				if( DirectInput.m_Sw[DIK_LSHIFT] )
				{
					data &= ~0x02;
					hits.push_back(DIK_LSHIFT);
				}
				if( bGraph                       )
				{
					data &= ~0x04;
					hits.push_back(DIK_NEXT);
				}
				if( DirectInput.m_Sw[DIK_1     ] )
				{
					data &= ~0x08;
					hits.push_back(DIK_1);
				}
				if( DirectInput.m_Sw[DIK_2     ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_2);
				}
			}
			break;
		case	9:
			if( bOut ) {
				if( DirectInput.m_Sw[DIK_HOME ] )
				{
					data &= ~0x02;
					hits.push_back(DIK_HOME);
				}
				if( DirectInput.m_Sw[DIK_UP   ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_UP);
				}
				if( DirectInput.m_Sw[DIK_RIGHT] )
				{
					data &= ~0x08;
					hits.push_back(DIK_RIGHT);
				}
				if( DirectInput.m_Sw[DIK_LEFT ] )
				{
					data &= ~0x10;
					hits.push_back(DIK_LEFT);
				}
			} else {
				if( DirectInput.m_Sw[DIK_DOWN  ] )
				{
					data &= ~0x02;
					hits.push_back(DIK_DOWN);
				}
				if( DirectInput.m_Sw[DIK_SPACE ] )
				{
					data &= ~0x04;
					hits.push_back(DIK_SPACE);
				}
				if( DirectInput.m_Sw[DIK_DELETE] )
				{
					data &= ~0x08;
					hits.push_back(DIK_DELETE);
				}
				if( DirectInput.m_Sw[DIK_INSERT] )
				{
					data &= ~0x10;
					hits.push_back(DIK_INSERT);
				}
			}
			break;
		case	10:
			break;
	}

	if (hits.size()>0
		|| (hits.size() == 0 && setzero))
	{
		DirectInput.ConfirmTypedKeys();
	}

	return	data & 0x1E;
}

void	EXPAD_Keyboard::Write4016( BYTE data )
{
	if( data == 0x05 ) {
		bOut = FALSE;
		ScanNo = 0;
	} else if( data == 0x04 ) {
//		if( ++ScanNo > 9 )
		if( ++ScanNo > 10 )
			ScanNo = 0;
		bOut = !bOut;
	} else if( data == 0x06 ) {
		bOut = !bOut;
	} else {
		ScanNo = 0;
	}
}
