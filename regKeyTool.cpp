#include "regKeyTool.h"

#define OPEN_REG_KEY(mainKey, subKey)               \
    CRegKey regKey;                                 \
    LONG retTmp = regKey.Open((mainKey), (subKey)); \
    if (ERROR_SUCCESS != retTmp) {                  \
        return retTmp;                              \
    }                                   

LONG GetRegKeyStringValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, CString& valueData)
{
    OPEN_REG_KEY(mainKey, subKey);

    ULONG dwSize = 512;
    TCHAR pszValue[521] = { 0 };
    LONG ret = regKey.QueryStringValue(valueName, pszValue, &dwSize);
    if (ERROR_SUCCESS == ret) {
        valueData = pszValue;
    }

    return ret;
}

LONG GetRegKeyQWORDValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, ULONGLONG& valueData)
{
    OPEN_REG_KEY(mainKey, subKey);

    return regKey.QueryQWORDValue(valueName, valueData);
}

LONG GetRegKeyDWORDValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, DWORD& valueData)
{
    OPEN_REG_KEY(mainKey, subKey);

    return regKey.QueryDWORDValue(valueName, valueData);
}

LONG GetRegKeyBinaryValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, void* valueData, ULONG& valueDataLen)
{
    OPEN_REG_KEY(mainKey, subKey);

    return regKey.QueryBinaryValue(valueName, valueData, &valueDataLen);
}

LONG SetRegKeyStringValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, CString valueData)
{
    OPEN_REG_KEY(mainKey, subKey);

    return regKey.SetStringValue(valueName, (LPCTSTR)valueData);
}

LONG SetRegKeyQWORDValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, ULONGLONG valueData)
{
    OPEN_REG_KEY(mainKey, subKey);

    return regKey.SetQWORDValue(valueName, valueData);
}

LONG SetRegKeyDWORDValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, DWORD valueData)
{
    OPEN_REG_KEY(mainKey, subKey);

    return regKey.SetDWORDValue(valueName, valueData);
}

LONG SetRegKeyBinaryValue(HKEY__* mainKey, LPCTSTR subKey, LPCTSTR valueName, const void* valueData, ULONG valueDataLen)
{
    OPEN_REG_KEY(mainKey, subKey);

    return regKey.SetBinaryValue(valueName, valueData, valueDataLen);
}
