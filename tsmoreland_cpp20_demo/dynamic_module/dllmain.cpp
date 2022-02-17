// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>

// ReSharper disable once CppInconsistentNaming
int __stdcall DllMain(HMODULE, DWORD ul_reason_for_call,
                      LPVOID reserved) {
  switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
    default:
      break;
  }
  return TRUE;
}
