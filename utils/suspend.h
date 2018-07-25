#pragma once
#include <Windows.h>

bool suspend_process(DWORD processId);

bool resume_process(DWORD processId);
