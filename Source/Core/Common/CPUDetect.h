// Copyright 2013 Dolphin Emulator Project
// Licensed under GPLv2
// Refer to the license.txt file included.


// Detect the cpu, so we'll know which optimizations to use
#pragma once

#include <string>

enum CPUVendor
{
	VENDOR_INTEL = 0,
	VENDOR_AMD = 1,
	VENDOR_ARM = 2,
	VENDOR_OTHER = 3,
};

struct CPUInfo
{
	CPUVendor vendor;

	char cpu_string[0x21];
	char brand_string[0x41];
	bool OS64bit;
	bool CPU64bit;
	bool Mode64bit;

	bool HTT;
	int num_cores;
	int logical_cpu_count;

	bool bSSE;
	bool bSSE2;
	bool bSSE3;
	bool bSSSE3;
	bool bPOPCNT;
	bool bSSE4_1;
	bool bSSE4_2;
	bool bLZCNT;
	bool bSSE4A;
	bool bAVX;
	bool bFMA;
	bool bAES;
	// FXSAVE/FXRSTOR
	bool bFXSR;
	// This flag indicates that the hardware supports some mode
	// in which denormal inputs _and_ outputs are automatically set to (signed) zero.
	// TODO: ARM
	bool bFlushToZero;
	bool bLAHFSAHF64;
	bool bLongMode;

	// ARM specific CPUInfo
	bool bSwp;
	bool bHalf;
	bool bThumb;
	bool bFastMult;
	bool bVFP;
	bool bEDSP;
	bool bThumbEE;
	bool bNEON;
	bool bVFPv3;
	bool bTLS;
	bool bVFPv4;
	bool bIDIVa;
	bool bIDIVt;
	bool bArmV7;  // enable MOVT, MOVW etc

	// ARMv8 specific
	bool bFP;
	bool bASIMD;

	// Call Detect()
	explicit CPUInfo();

	// Turn the cpu info into a string we can show
	std::string Summarize();
	bool IsUnsafe();

private:
	// Detects the various cpu features
	void Detect();
};

extern CPUInfo cpu_info;
