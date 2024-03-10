/*
---------------------------------------------
|    ____                                   |
|   /\  _`\                                 |
|   \ \ \L\_\ __    ___   __  __   __  _    |
|    \ \  _\/'__`\/' _ `\/\ \/\ \ /\ \/'\   |
|     \ \ \/\  __//\ \/\ \ \ \_\ \\/>  </   |
|      \ \_\ \____\ \_\ \_\/`____ \/\_/\_\  |
|       \/_/\/____/\/_/\/_/`/___/> \//\/_/  |
|                             /\___/        |
|                             \/__/         |
|                                           |
---------------------------------------------
*/

/// @file AScripts.h
/// @brief Header de AScripts
/// @author F&nµx
/// @version 1.0
/// @date 02/03/2024

#ifndef ASCRTPTS_H
#define ASCRIPTS_H

#include <map>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <cstdlib>

namespace Fenyx
{

const std::map<std::string, std::string> tput_c = {
    {"black",   "0"},
    {"red",     "1"},
    {"green",   "2"},
    {"yellow",  "3"},
    {"blue",    "4"},
    {"magenta", "5"},
    {"cyan",    "6"},
    {"white",   "7"},
    {"default", "8"}
};

bool IsNumStr(std::string str);
bool VerifTermExist();

bool IsValidColor(std::string color);

bool SetTermFColor(std::string color, bool vterm = true);
bool SetTermBColor(std::string color, bool vterm = true);
void SetTermDColor(bool vterm = true);

bool CompareDir(std::filesystem::path d1, std::filesystem::path d2);

}

#endif // ASCRIPTS_H
