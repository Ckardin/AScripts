s_Func = dofile("func.lua")

if #arg < 2 then
    print("You must specify number of spaces to print.")
elseif #arg > 2 then
    print("You must specify exactly 1 parameter.")
else
    if type(arg[1]) != 'number' then
        print("Invalid parameter.")
    else
        local nspace = arg[1] .. ""
        s_Func.SysOsExec("tput cuf" .. nspace)
    end
end
