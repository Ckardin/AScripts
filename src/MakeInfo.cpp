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
    std::string text   = "";

    if(argc != 3)
    {
        std::cout << "You must specify exactly 2 parameters." <<std::endl;
        return -1;
    }

    if(!Fenyx::VerifTermExist())
    {
        std::cout << "You don't have terminal." <<std::endl;
        return -2;
    }


    if(argv[1] == "making")
    {
        color = "red";
        text  = "Making " + argv[2];
    }
    else if(argv[1] == "clean")
    {
        color = "red";
        text  = "Cleaning " + argv[2];
    }
    else if(argv[1] == "install")
    {
        color = "red";
        text  = "Installing " + argv[2];
    }
    else if(argv[1] == "module")
    {
        color = "green";
        text  = "... Compile Module           " + argv[2];
    }
    else if(argv[1] == "static")
    {
        color = "blue";
        text  = "==> Creating static lib      " + argv[2];
    }
    else if(argv[1] == "dynamic")
    {
        color = "cyan";
        text  = "==> Creating dynamic lib     " + argv[2];
    }
    else if(argv[1] == "program_s")
    {
        color = "magenta";
        text  = "==> Linking static           " + argv[2];
    }
    else if(argv[1] == "program_d")
    {
        color = "magenta";
        text  = "==> Linking dynamic          " + argv[2];
    }
    else if(argv[1] == "doc")
    {
        color = "yellow";
        text  = "... Compiling doc: " + argv[2];
    }
    else
    {
        color = "red";
        text  = "MakeInfo(-3): Invalid [type] parameter.";
    }


    if(!Fenyx::SetTermFColor(color))
    {
        std::cout << "Error in call() to tput." <<std::endl;
        return -4;
    }

    std::cout << text <<std::endl;
    Fenyx::SetTermDColor();

    return 0;
}