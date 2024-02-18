local s_func = {}

function s_func.SysOsExec(Command)
    local cmd = Command..' 2> ./SysOsExecute.log'
    local ret = os.execute(cmd)

    local file = assert(io.open("./SysOsExecute.log", "r"))
    local stdout = file:read("*all")
    assert(file:close())

    os.execute("rm ./SysOsExecute.log")

    return (ret == 0 or ret == true), stdout
end

function s_func.ExistInTab(tab, idx)
    for i, v in pairs(tab) do
        if(i == idx) then
            return true
        end
    end

    return false
end

function s_func.GetFilesInTab(path, tab)
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

return s_func
