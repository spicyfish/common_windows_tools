CString GetSettings( HKEY__* MainKey, LPSTR SubKey, LPSTR Key, LPSTR Default) 
{ 
 HKEY hSubKey; 
 DWORD dwType; 
 DWORD dwSize; 
 LONG retval; 
 unsigned char strValue[512]; 
 strcpy( (char *)strValue, ""); 
 if ((retval=RegOpenKeyEx( MainKey, SubKey, NULL, KEY_READ,&hSubKey)) 
  == ERROR_SUCCESS) 
  { 
  unsigned char Buffer[512]; 
  dwSize = 512; 
  if ((retval=RegQueryValueEx(hSubKey, Key, NULL, &dwType, Buffer, 
      &dwSize)) == ERROR_SUCCESS) 
   { 
   strcpy( (char *)strValue, (const char *)Buffer); 
   } 
  else 
   { 
   strcpy( (char *)strValue, Default); 
   } 
  } 
 CString Ret; 
 Ret = strValue; 
 return Ret; 
 } 
void SaveSettings( HKEY__* MainKey, LPSTR SubKey, LPSTR Key, LPSTR strWert) 
{ 
 HKEY hSubKey; 
 LONG retval; 
 DWORD dwDispo; 
    if ((retval = RegCreateKeyEx( MainKey, 
          SubKey, 
          NULL, "", 
          REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, 
          &hSubKey, &dwDispo)) 
           == ERROR_SUCCESS) 
  { 
  retval = RegSetValueEx( hSubKey, Key, 0, REG_SZ, (const unsigned char 
*)strWert, strlen(strWert)+1); 
  if( retval != ERROR_SUCCESS ) 
   { 
   LPVOID lpMsgBuf; 
matMessage( 
    FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, 
    NULL, 
    GetLastError(), 
    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language 
    (LPTSTR) &lpMsgBuf, 
    0, 
    NULL 
   ); 
   // Display the string. 
   MessageBox( NULL, (LPTSTR)lpMsgBuf, "GetLastError", MB_OK|MB_ICONINFORMATION ); 
   // Free the buffer. 
   LocalFree( lpMsgBuf );   
   } 
  } 

