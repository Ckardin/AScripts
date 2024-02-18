s_func = require("s_func")

if #arg < 1 or #arg >= 2 then
    print("You must specify exactly 1 parameter.")
elseif string.match(arg[1], "^%d+$") == nil then
    print("Invalid parameter.")
else
    s_func.SysOsExec("tput cuf " .. arg[1])
end
