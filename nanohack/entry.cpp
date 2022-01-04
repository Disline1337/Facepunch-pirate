#define NOMINMAX
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define THEM

#include <Windows.h>
#include <stdint.h>
#include <Windows.h>
#include <psapi.h>
#include <d3d11.h>
#include <string>
#include <codecvt>
#include <locale>
#include <cstdint>
#include <algorithm>
#include <random>
#include <iostream>
#include <iomanip>
#include <emmintrin.h>
#include <comdef.h>
#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <signal.h>
#include <sstream>
#include <stdio.h>
#include <lmcons.h>
#include <thread>
#include <map>
#include <shlobj.h>
#pragma comment(lib, "Shell32.lib")
#pragma comment(lib, "Winmm.lib")
#include "ThemidaSDK/ThemidaSDK.h"
#define VM_TIGER_WHITE_START
#define VM_TIGER_WHITE_END

#define VM_TIGER_RED_START
#define VM_TIGER_RED_END

#define VM_TIGER_BLACK_START
#define VM_TIGER_BLACK_END

#define VM_FISH_WHITE_START
#define VM_FISH_WHITE_END

#define VM_FISH_RED_START
#define VM_FISH_RED_END

#define VM_FISH_BLACK_START
#define VM_FISH_BLACK_END

#define VM_PUMA_WHITE_START
#define VM_PUMA_WHITE_END

#define VM_PUMA_RED_START
#define VM_PUMA_RED_END

#define VM_PUMA_BLACK_START
#define VM_PUMA_BLACK_END

#define VM_SHARK_WHITE_START
#define VM_SHARK_WHITE_END

#define VM_SHARK_RED_START
#define VM_SHARK_RED_END 

#define VM_SHARK_BLACK_START
#define VM_SHARK_BLACK_END

#define VM_DOLPHIN_WHITE_START
#define VM_DOLPHIN_WHITE_END

#define VM_DOLPHIN_RED_START
#define VM_DOLPHIN_RED_END

#define VM_DOLPHIN_BLACK_START
#define VM_DOLPHIN_BLACK_END

#define VM_EAGLE_WHITE_START
#define VM_EAGLE_WHITE_END

#define VM_EAGLE_RED_START
#define VM_EAGLE_RED_END

#define VM_EAGLE_BLACK_START
#define VM_EAGLE_BLACK_END

#define VM_MUTATE_ONLY_START
#define VM_MUTATE_ONLY_END
#pragma warning ( disable : 4172 )

#include "core/sdk/utils/string.hpp"
#include "core/sdk/utils/xorstr.hpp"
#include "core/sdk/utils/xorf.hpp"
#include "utils/WinReg.hpp"
#include "utils/Fingerprint.hpp"
#include "utils/Cryptography.hpp"

#include "settings.hpp"
#include "core/sdk/vector.hpp"
#include "core/stdafx.hpp"
#include "core/drawing/renderer.hpp"

#define FGUI_IMPLEMENTATION
#define FGUI_USE_D2D
#include "FGUI/FGUI.hpp"
#include "core/drawing/fgui/FInput.hpp"
#include "core/drawing/fgui/FRenderer.hpp"
#include "core/drawing/ui.hpp"

#include "core/sdk/utils/hookengine.hpp"
#include "core/sdk/mem.hpp"
#include "core/sdk/utils/crc32.hpp"
#include "core/sdk/il2cpp/wrapper.hpp"
#include "core/sdk/il2cpp/dissector.hpp"
#include "core/sdk/structs.hpp"
#include "core/sdk/game.hpp"
#include "core/main/cache.hpp"
#include "core/main/other.hpp"
#include "core/sdk/utils/math.hpp"
#include "core/main/entities.hpp"
#include "core/drawing/d3d.hpp"
#include "core/main/aimutils.hpp"
#include "core/main/hooks.hpp"
#include <Guard.h>




void entry_thread() {
	VM_DOLPHIN_BLACK_START
	PWSTR szPath = NULL;
	if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &szPath)))
	{
		std::filesystem::create_directories(StringConverter::ToASCII(std::wstring(szPath) + wxorstr_(L"\\vos.club")));

		settings::data_dir = StringConverter::ToASCII(std::wstring(szPath) + wxorstr_(L"\\vos.club"));
	}
	d3d::init( );

	/*
	AllocConsole( );
	SetConsoleTitleA(xorstr_("dbg"));
	freopen_s(reinterpret_cast<FILE**>(stdin), xorstr_("CONIN$"), xorstr_("r"), stdin);
	freopen_s(reinterpret_cast<FILE**>(stdout), xorstr_("CONOUT$"), xorstr_("w"), stdout);
	*/
	
	CheckLicense();
	init();
	do_hooks();

	VM_DOLPHIN_BLACK_END
}

//extern "C" __declspec(dllexport) int Gamer()
//{
//	MessageBoxA(0, "Success", "gamer", 0);
//	return 1337;
//}

bool DllMain(HMODULE hMod, uint32_t call_reason, LPVOID reserved) {
	if (call_reason == DLL_PROCESS_ATTACH)
	{
		const auto handle = CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(entry_thread), 0, 0, nullptr);
		if (handle != NULL)
			CloseHandle(handle);
	}
	return true;
}