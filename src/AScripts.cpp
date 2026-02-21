/// English version
/*
Copyright (C) 2025 BOUCARD NICOLLE Jody

This file is part of AScripts.

AScripts is a free library: you can redistribute it and/or modify it under the terms of the GNU General 
Public License as published by the Free Software Foundation, either version 3 of the License, or (at your 
option) any later version.

ASCripts is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
General Public License for more details.

You should have received a copy of the GNU General Public License along with AScripts. If not, see 
<https://www.gnu.org/licenses/>.
*/

/// Version française
/*
Copyright (C) 2025 BOUCARD NICOLLE Jody

Ce fichier fait partie de AScripts.

AScripts est une bibliothèque libre ; vous pouvez la redistribuer ou la modifier suivant les termes de la GNU General 
Public License telle que publiée par la Free Software Foundation, soit la version 3 de la licence soit (à votre 
gré) toute version ultérieure.

AScripts est distribuée dans l'espoir qu'elle sera utile, mais SANS AUCUNE GARANTIE; sans même la 
garantie tacite de QUALITÉ MARCHANDE ou d'ADÉQUATION À UN BUT PARTICULIER. Consultez la GNU 
General Public License pour plus de détails.

Vous devez avoir reçu une copie de la GNU General Public License en même temps que AScripts. Si ce n'est pas le cas, consultez 
<http://www.gnu.org/licenses>.
*/

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
/// @version 2.0
/// @date 21/02/2025

#include "AScripts.h"

namespace Fenyx
{

bool IsNumStr(const std::string &str)
{
    const auto it = std::find_if(str.begin(), str.end(), [](const char c) {
        return !std::isdigit(c);
    });

    return (!str.empty()) && (it == str.end());
}

bool VerifTermExist()
{
    if (system(nullptr) == 0) return false;
    return true;
}

bool IsValidColor(const std::string &color)
{
    for (const auto &[fst, snd] : tput_c) {
        if(fst == color) return true;
    }

    return false;
}

bool SetTermFColor(const std::string &color, const bool vterm)
{
    std::string setc_cmd = "";

    if (!vterm) {
        if(!VerifTermExist()) return false;
    }

    if (!IsValidColor(color)) return false;

    if (color != "default") {
        setc_cmd = "tput setaf " + tput_c.find(color)->second;
        if (system(setc_cmd.c_str()) != 0) return false;
    }

    return true;
}

bool SetTermBColor(const std::string &color, const bool vterm)
{
    std::string setc_cmd = "";

    if (!vterm) {
        if (!VerifTermExist()) return false;
    }

    if (!IsValidColor(color)) return false;

    if (color != "default") {
        setc_cmd = "tput setab " + tput_c.find(color)->second;
        if (system(setc_cmd.c_str()) != 0) return false;
    }

    return true;
}

void SetTermDColor(const bool vterm)
{
    if (!vterm) {
        if (!VerifTermExist()) return;
    }

    system("tput sgr0");
}


bool CompareDir(const std::filesystem::path& d1, const std::filesystem::path& d2)
{
    using vsfp = std::vector<std::filesystem::path>;
    vsfp f_d1;
    vsfp f_d2;

    if (!std::filesystem::exists(d1)       || !std::filesystem::exists(d2))       return false;
    if (!std::filesystem::is_directory(d1) || !std::filesystem::is_directory(d2)) return false;

    for (const auto& e1 : std::filesystem::recursive_directory_iterator(d1)) {
        f_d1.push_back(e1.path());
    }

    for (const auto& e2 : std::filesystem::recursive_directory_iterator(d2)) {
        f_d2.push_back(e2.path());
    }

    if(f_d1.size() != f_d2.size()) return false;

    auto j = f_d2.begin();
    for(auto &i : f_d1)
    {
        if (std::filesystem::is_regular_file(i)) {
            if (!std::filesystem::is_regular_file(*j))                           return false;
            if (std::filesystem::file_size(i) != std::filesystem::file_size(*j)) return false;
        }

        if(std::filesystem::is_directory(i)) {
            if (!std::filesystem::is_directory(*j)) return false;
            if (!CompareDir(i, *j))                 return false;
        }

        j += 1;
    }

    return true;
}

}

