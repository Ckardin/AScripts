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

/// @file Echo.cpp
/// @brief Source de AScripts/Echo
/// @author F&nµx
/// @version 1.0
/// @date 02/03/2024

#include "AScripts.h"

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        std::cout << "You must specifiy exactly 3 parameters." <<std::endl;
        return -1;
    }

    if(!Fenyx::VerifTermExist())
    {
        std::cout << "You don't have terminal." <<std::endl;
        return -2;
    }

    if(!Fenyx::IsValidColor(argv[2]))
    {
        std::cout << "Foreground color is invalid for tput." <<std::endl;
        return -3;
    }

    if(!Fenyx::IsValidColor(argv[3]))
    {
        std::cout << "Background color is invalid for tput." <<std::endl;
        return -4;
    }

    if(!Fenyx::SetTermFColor(argv[2]) || !Fenyx::SetTermBColor(argv[3]))
    {
        std::cout << "Error in call() to tput." <<std::endl;
        return -5;
    }

    std::cout << argv[1] <<std::endl;
    Fenyx::SetTermDColor();

    return 0;
}