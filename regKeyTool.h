#ifndef __REG_KEY_WARPER_H__
#define __REG_KEY_WARPER_H__

#include <windows.h>
#include <atlstr.h>


LONG GetRegKeyStringValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, CString& valueData);
LONG GetRegKeyQWORDValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, ULONGLONG& valueData);
LONG GetRegKeyDWORDValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, DWORD& valueData);
LONG GetRegKeyBinaryValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, void* valueData, ULONG& valueDataLen);

LONG SetRegKeyStringValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, CString valueData);
LONG SetRegKeyQWORDValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, ULONGLONG valueData);
LONG SetRegKeyDWORDValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, DWORD valueData);
LONG SetRegKeyBinaryValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, const void* valueData, ULONG valueDataLen);


#endif
