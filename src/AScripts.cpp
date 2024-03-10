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

/// @file AScripts.cpp
/// @brief Source de AScripts
/// @author F&nµx
/// @version 1.0
/// @date 02/03/2024

#include "AScripts.h"

namespace Fenyx
{

bool IsNumStr(std::string str)
{
    auto it = std::find_if(str.begin(), str.end(), [](char c) {
        return !std::isdigit(c);
    });

    return (str.size() > 0) && (it == str.end());
}

bool VerifTermExist()
{
    if(system(nullptr) == 0) return false;
    else                     return true;
}

bool IsValidColor(std::string color)
{
    for (auto it = tput_c.begin(); it != tput_c.end(); ++it)
    {
        if(it->first == color) return true;
    }

    return false;
}

bool SetTermFColor(std::string color, bool vterm)
{
    std::string setc_cmd = "";

    if(!vterm)
    {
        if(!VerifTermExist()) return false;
    }

    if(!IsValidColor(color)) return false;

    if(color != "default")
    {
        setc_cmd = "tput setaf " + tput_c.find(color)->second;
        if(system(setc_cmd.c_str()) != 0) return false;
    }

    return true;
}

bool SetTermBColor(std::string color, bool vterm)
{
    std::string setc_cmd = "";

    if(!vterm)
    {
        if(!VerifTermExist()) return false;
    }

    if(!IsValidColor(color)) return false;

    if(color != "default")
    {
        setc_cmd = "tput setab " + tput_c.find(color)->second;
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


bool CompareDir(std::filesystem::path d1, std::filesystem::path d2)
{
    std::filesystem::path sp1, sp2;

    if(d1.filename() != d2.filename()) return false;

    if(!std::filesystem::exists(d1)       || !std::filesystem::exists(d2))       return false;
    if(!std::filesystem::is_directory(d1) || !std::filesystem::is_directory(d2)) return false;

    for (const auto& entry : fs::recursive_directory_iterator(d1))
    {
        sp1 = entry.path();
        sp2 = d2 / sp1.filename();

        if(!std::filesystem::exists(sp2)) return false;

        if(std::filesystem::is_regular_file(sp1))
        {
            if(!std::filesystem::is_regular_file(sp2))                             return false;
            if(std::filesystem::file_size(sp1) != std::filesystem::file_size(sp2)) return false;
        }

        if(std::filesystem::is_directory(sp1))
        {
            if(!std::filesystem::is_directory(sp2)) return false;
            if(!CompareDir(sp1, sp2))              return false;
        }
    }

    return true;
}

}

