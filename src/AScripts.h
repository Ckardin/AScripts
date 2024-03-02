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

#include <string>
#include <iostream>
#include <array>
#include <cstdlib>

namespace Fenyx
{

const std::array<std::string, 9> tput_c {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white", "default"};

bool VerifTerminalExist();
bool IsValidColor(std::string color);
bool SetTermFColor(std::string color);
bool SetTermBColor(std::string color);
void SetTermDColor();

}

#endif // ASCRIPTS_H
