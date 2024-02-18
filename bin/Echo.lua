ascript = require("ascript")

if #arg < 3 or #arg >= 4 then
    print("You must specify exactly 3 parameters.")
elseif ascript.IsValidColor(arg[2]) ~= true then
    print("Foreground color is invalid.")
elseif ascript.IsValidColor(arg[3]) ~= true then
    print("Background color is invalid.")
else
    ascript.SetTermFColor(arg[2])
    ascript.SetTermBColor(arg[3])

    print(arg[1])
    ascript.SetTermDColor()
end
