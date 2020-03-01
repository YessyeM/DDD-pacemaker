#define ALL_SENSE    1
#define V_SENSE      2
#define V_REF        3
#define A_REF        4
#define V_PULSE      5
#define A_PULSE      6

state = ALL_STATE;
set_Atimeout();
set_Vtimeout();
ehile(1) {
	switch (state) {
	case: ALL_SENSE
	{
		if (Atimeout) {
			set AP();
			set APtimer();
			state = A_PULSE;
			break;
}
		if (Vtimeout) {
			set VP();
			set VPtimer();
			state = V_PULSE;
			break;
		}
		if (AS) {
			set AReftimeout();
			set AVtimeout();
			set A_timeout();
			state = A_REF;
			break;
		}
		if (VS) {
			set VReftimeout();
			set_Atimeout();
			set_Vtimeout();
			state = V_REF;
			break;
		}
		if (AVtimeout) {
			set VP();
			set VPtimer();
			state = V_PULSE;
			break;
		}
		end if
	}
	case: V_REF
		{
			if (VReftimeout & AReftimeout) {
				state = ALL_STATE;
				break;
}
		end if
		}
	case: A_REF
		{
			if (AReftimeout) {
				state = V_SENSE;
				break;
}
		}
	case: V_PULSE
		{
			if (VPtimeout) {
				set VReftimeout();
				set_Atimeout();
				set_Vtimeout();
				state = V_REF;
				break;
}
		end if
		}
	case: A_PULSE
		{
			if (APtimeout) {
				set AReftimeout();
				set AVtimeout();
				state = A_REF;
}
		end if
		}
	}
}
