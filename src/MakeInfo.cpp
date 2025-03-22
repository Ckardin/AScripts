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

/// @file MakeInfo.cpp
/// @brief Source de AScripts/MakeInfo
/// @author F&nµx
/// @version 1.0
/// @date 10/03/2024

#include "AScripts.h"

int main(int argc, char *argv[])
{
    std::string color = "default";
    std::string text  = "";
    bool tmpv = false;

    if (argc != 4)
    {
        std::cout << "You must specify exactly 3 parameters." <<std::endl;
        return -1;
    }

    if (!Fenyx::VerifTermExist())
    {
        std::cout << "You don't have terminal." <<std::endl;
        return -2;
    }

    Fenyx::SetTermDColor();


    std::string argv1 = argv[1];
    std::string argv2 = argv[2];
    std::string argv3 = argv[3];

    if (argv2 == "making") {
        color = "red";
        text  = (argv1 == "fr") ? "Construction " : "Making ";
    } else if (argv2 == "clean") {
        color = "red";
        text  = (argv1 == "fr") ? "Nettoyage " : "Cleaning ";
    } else if (argv2 == "install") {
        color = "red";
        text  = (argv1 == "fr") ? "Installation " : "Installing ";
    } else if (argv2 == "module") {
        color = "green";
        text  = (argv1 == "fr") ? "... Compilation du module              " : "... Compile Module           ";
    } else if (argv2 == "static") {
        color = "blue";
        text  = (argv1 == "fr") ? "==> Assemblage de la lib statique      " : "==> Creating static lib      ";
    } else if (argv2 == "dynamic") {
        color = "cyan";
        text  = (argv1 == "fr") ? "==> Assemblage de la lib dynamique     " : "==> Creating dynamic lib     ";
    } else if (argv2 == "program_s") {
        color = "magenta";
        text  = (argv1 == "fr") ? "Edition des liens statiques pour       " : "==> Linking static           ";
    } else if (argv2 == "program_d") {
        color = "magenta";
        text  = (argv1 == "fr") ? "Edition des liens dynamiques pour      " : "==> Linking dynamic          ";
    } else if (argv2 == "doc") {
        color = "yellow";
        text  = (argv1 == "fr") ? "... Compilation de la doc " : "... Compiling doc: ";
    } else {
        color = "red";
        text  = "MakeInfo(-3): Invalid [type] parameter.";
        tmpv = true;
    }

    if (!tmpv) text += argv3;

    if (!Fenyx::SetTermFColor(color))
    {
        std::cout << "Error in call() to tput." <<std::endl;
        return -4;
    }

    std::cout << text <<std::endl;
    Fenyx::SetTermDColor();

    return 0;
}