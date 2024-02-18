s_Func = dofile("func.lua")

if #arg < 1 then
    print("You must specify number of spaces to print.")
elseif #arg >= 2 then
    print("You must specify exactly 1 parameter.")
else
    s_Func.SysOsExec("tput cuf " .. arg[1])
end
