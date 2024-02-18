s_func = require("s_func")

if #arg < 2 or #arg >= 3 then
    print("You must specify exactly 2 parameters.")
else
    local d1_files = {}
    local d2_files = {}
    local d_same   = true

    s_func.GetFilesInTab(arg[1], d1_files)
    s_func.GetFilesInTab(arg[2], d2_files)

    if #d1_files ~= #d2_files then
        d_same = false
    else
        for i, v in pairs(d1_files) do
            if d1_files[i] ~= d2_files[i] then
                d_same = false
                break
            end
        end
    end

    if d_same == false then
        print("Not same directory")
    else
        print("Same directory")
    end
end