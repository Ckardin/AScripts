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
/// @brief Source de AScripts
/// @author F&nµx
/// @version 1.0
/// @date 02/03/2024

#include "AScripts.h"

namespace Fenyx
{

bool VerifTermExist()
{
    if(system(nullptr) == 0) return false;
    else                     return true;
}

bool IsValidColor(std::string color)
{
    for (auto it = tput_c.begin(); it != tput_c.end(); ++it)
    {
        if(*it == color) return true;
    }

    return false;
}

std::string GetIdxColor(std::string color)
{
    if(!IsValidColor(color)) return "9";

    uint8_t idx = 0;

    for (auto it = tput_c.begin(); it != tput_c.end(); ++it)
    {
        if(*it == color) break;
    }

    std::stringstream sstr;
    sstr << idx;

    return sstr.str();
}

bool SetTermFColor(std::string color, bool vterm)
{
    if(!vterm)
    {
        if(!VerifTermExist()) return false;
    }

    std::string c_idx = GetIdxColor(color), setc_cmd = "";

    if(c_idx == "9") return false;

    if(color != "default")
    {
        setc_cmd = "tput setaf " + c_idx;
        if(system(setc_cmd.c_str()) != 0) return false;
    }

    return true;
}

bool SetTermBColor(std::string color, bool vterm)
{
    if(!vterm)
    {
        if(!VerifTermExist()) return false;
    }

    std::string c_idx = GetIdxColor(color), setc_cmd = "";

    if(c_idx == "9") return false;

    if(color != "default")
    {
        setc_cmd = "tput setab " + c_idx;
        if(system(setc_cmd.c_str()) != 0) return false;
    }

    return true;
}

void SetTermDColor(bool vterm)
{
    if(!vterm)
    {
        if(!VerifTermExist()) return;
    }

    system("tput sgr0");
}

}

