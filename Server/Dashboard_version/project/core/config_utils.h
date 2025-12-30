#ifndef CONFIG_UTILS_H
#define CONFIG_UTILS_H

#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

bool GetPrivateProfileBoolean(string selection, string varname, string default_val, string filename);
float GetPrivateProfileFloat(string selection, string varname, string default_val, string filename);
string GetPrivateProfileLine(string selection, string varname, string default_val, string filename);
void WriteLog(const char *file_name, const char *text);

#endif
