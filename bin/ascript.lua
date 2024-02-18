local ascript = {}

local colors = { ["black"]   = "0",
                 ["red"]     = "1",
                 ["green"]   = "2",
                 ["yellow"]  = "3",
                 ["blue"]    = "4",
                 ["magenta"] = "5",
                 ["cyan"]    = "6",
                 ["white"]   = "7",
                 ["default"] = "8" }

function ascript.SysOsExec(Command, filec)
    if filec == true then
		    local cmd = Command..' 2> ./SysOsExecute.log'
    else
        local cmd = Command
    end

		local ret    = os.execute(cmd)
    local stdout = ""

    if filec == true then
		    local file = assert(io.open("./SysOsExecute.log", "r"))
		    local stdout = file:read("*all")
		    assert(file:close())

        os.execute("rm ./SysOsExecute.log")
    end

		return (ret == 0 or ret == true), stdout
end

function ascript.ExistInTab(tab, idx)
		for i, v in pairs(tab) do
				if(i == idx) then
						return true
				end
		end

		return false
end

function ascript.GetFilesInTab(path, tab)
		for tfile in fs.dir(path) do
		    if tfile ~= "." and tfile ~= ".." then
					local entirep = path .. "/" .. tfile
					if fs.isDir(entirep) then
						GetFilesInTab(entirep, tab)
					else
						tab[#tab+1] = entirep
					end
				end
		end
end

function ascript.IsValidColor(color)
    if ExistInTab(colors, color) then
        return true
    else
        return false
    end
end

function ascript.SetTermFColor(color)
    if color ~= "default" then
        SysOsExec("tput setaf " .. colors[color])
    end
end

function ascript.SetTermBColor(color)
    if color ~= "default" then
        SysOsExec("tput setab " .. colors[color])
    end
end

function ascript.SetTermDColor()
    SysOsExec("tput sgr0")
end

return ascript
