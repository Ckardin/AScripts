function SysOsExec(Command)
    local cmd = Command..' 2> ./SysOsExecute.log'
    local ret = os.execute(cmd)

    local file = assert(io.open("./SysOsExecute.log", "r"))
    local stdout = file:read("*all")
    assert(file:close())

    os.execute("rm ./SysOsExecute.log")

    return (ret == 0 or ret == true), stdout
end

function ExistInTab(tab, idx)
    for i, v in pairs(tab) do
        if(i == idx) then
            return true
        end
    end

    return false
end

return { SysOsExec = SysOsExec, ExistInTab = ExistInTab }
