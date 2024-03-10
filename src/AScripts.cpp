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
    using vsfp = std::vector<std::filesystem::path>;
    vsfp f_d1;
    vsfp f_d2;

    if(!std::filesystem::exists(d1)       || !std::filesystem::exists(d2))       return false;
    if(!std::filesystem::is_directory(d1) || !std::filesystem::is_directory(d2)) return false;

    for (const auto& e1 : std::filesystem::recursive_directory_iterator(d1))
    {
        f_d1.push_back(e1.path());
    }

    for (const auto& e2 : std::filesystem::recursive_directory_iterator(d2))
    {
        f_d2.push_back(e2.path());
    }

    if(f_d1.size() != f_d2.size()) return false;

    vsfp::iterator j = f_d2.begin();
    for(vsfp::iterator i = f_d1.begin(); i != f_d1.end(); ++i)
    {
        if(std::filesystem::is_regular_file(*i))
        {
            if(!std::filesystem::is_regular_file(*j))                            return false;
            if(std::filesystem::file_size(*i) != std::filesystem::file_size(*j)) return false;
        }

        if(std::filesystem::is_directory(*i))
        {
            if(!std::filesystem::is_directory(*j)) return false;
            if(!CompareDir(*i, *j))                return false;
        }

        ++j;
    }

    return true;
}

}

