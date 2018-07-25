#include "suspend.h"
#include <iostream>

typedef LONG(NTAPI *NtSuspendProcess)(IN HANDLE ProcessHandle);

bool suspend_process(DWORD processId)
{
	HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);

	NtSuspendProcess pfnNtSuspendProcess = (NtSuspendProcess)GetProcAddress(
		GetModuleHandleA("ntdll"), "NtSuspendProcess");

	LONG res = pfnNtSuspendProcess(processHandle);
	CloseHandle(processHandle);
	if (res == S_OK) {
		return true;
	}
	return false;
}

typedef LONG(NTAPI *NtResumeProcess)(IN HANDLE ProcessHandle);

bool resume_process(DWORD processId)
{
	HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);

	NtResumeProcess pfnNtResumeProcess = (NtResumeProcess)GetProcAddress(
		GetModuleHandleA("ntdll"), "NtResumeProcess");

	LONG res = pfnNtResumeProcess(processHandle);
	CloseHandle(processHandle);
	if (res == S_OK) {
		return true;
	}
	return false;
}
