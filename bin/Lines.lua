if #arg < 1 or #arg >= 2 then
    print("You must specify exactly 1 parameter.")
elseif string.match(arg[1], "^%d+$") == nil then
    print("Invalid parameter.")
else
    for i = 1, tonumber(arg[1]) do
        print("")
    end
end