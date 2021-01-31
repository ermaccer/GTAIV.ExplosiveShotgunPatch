// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "MemoryMgr.h"
#include "pattern/Hooking.Patterns.h"

using namespace Memory::VP;

void Init()
{
	
	// Explosive Shotgun
	// 0xB5D466
	auto exp_shotgun_pat = hook::pattern("83 3D ? ? ? ? 02 0F 8C DA 00 00 00");
	if (!exp_shotgun_pat.count_hint(1).empty())
	{
		auto ptr = exp_shotgun_pat.get(0).get<int>(0);
		Nop((int)ptr, 13);

	}


	// APC Patches
	// 
	// process control, shooting
	auto apc_pat = hook::pattern("83 3D ? ? ? ? 02 0F 8C CA 04 00 00");
	if (!apc_pat.count_hint(1).empty())
	{
		auto ptr = apc_pat.get(0).get<int>(0);
		Nop((int)ptr, 13);
	}


	// 0xA12F61
	// lock drive by
	apc_pat = hook::pattern("83 3D ? ? ? ? 02 75 35 0F BF 46 2E 3B 05");
	if (!apc_pat.count_hint(1).empty())
	{
		auto ptr = apc_pat.get(0).get<int>(0);
		Nop((int)ptr, 9);
	}


	// 0x5C8C16
	// task stuff?
	apc_pat = hook::pattern("83 3D ? ? ? ? 02 A0 91 D1");
	if (!apc_pat.count_hint(1).empty())
	{
		auto ptr = apc_pat.get(0).get<int>(0);
		Nop((int)ptr, 7);
	}


	// 0x4E4B8C
	// apc model compare
	apc_pat = hook::pattern("83 3D ? ? ? ? 02 75 08 3B 05");
	if (!apc_pat.count_hint(1).empty())
	{
		auto ptr = apc_pat.get(0).get<int>(0);
		Nop((int)ptr, 9);
	}


	// 0xA12F61
	apc_pat = hook::pattern("83 3D ? ? ? ? 02 7C 27 8B 85 30 0B 00 00");
	if (!apc_pat.count_hint(1).empty())
	{
		auto ptr = apc_pat.get(0).get<int>(0);
		Nop((int)ptr, 9);
	}


	// 0xA443FB
	apc_pat = hook::pattern("83 3D ? ? ? ? 02 7C 37 0F BF 46 2E");
	if (!apc_pat.count_hint(1).empty())
	{
		auto ptr = apc_pat.get(0).get<int>(0);
		Nop((int)ptr, 9);
	}

	// 0x993AD5
	apc_pat = hook::pattern("83 3D ? ? ? ? 02 75 21 8B 87 20 08 00 00 0F");
	if (!apc_pat.count_hint(1).empty())
	{
		auto ptr = apc_pat.get(0).get<int>(0);
		Nop((int)ptr, 9);
	}

	// 0x4E4B8C
	apc_pat = hook::pattern("83 3D ? ? ? ? 02 7C 52 0F BF 46 2E");
	if (!apc_pat.count_hint(1).empty())
	{
		auto ptr = apc_pat.get(0).get<int>(0);
		Nop((int)ptr, 9);
	}


	// 0xB2C290
	apc_pat = hook::pattern("83 3D ? ? ? ? 02 75 1F 8B 44 24 04 85");
	if (!apc_pat.count_hint(1).empty())
	{
		auto ptr = apc_pat.get(0).get<int>(0);
		Nop((int)ptr, 9);
	}

}

extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		Init();
	}
}