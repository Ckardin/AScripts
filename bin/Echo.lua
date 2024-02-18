s_func = dofile("s_func")

local colors = { ["black"]   = "0",
                 ["red"]     = "1",
                 ["green"]   = "2",
                 ["yellow"]  = "3",
                 ["blue"]    = "4",
                 ["magenta"] = "5",
                 ["cyan"]    = "6",
                 ["white"]   = "7",
                 ["default"] = "8" }

if #arg < 3 or #arg >= 4 then
    print("You must specify exactly 3 parameters.")
elseif s_func.ExistInTab(colors, arg[2]) ~= true then
    print("Foreground color is invalid.")
elseif s_func.ExistInTab(colors, arg[3]) ~= true then
    print("Background color is invalid.")
else
    if arg[2] ~= "default" then
        s_func.SysOsExec("tput setaf " .. colors[arg[2]])
    end

    if arg[3] ~= "default" then
        s_func.SysOsExec("tput setab " .. colors[arg[3]])
    end

    print(arg[1])
    s_func.SysOsExec("tput sgr0")
end
