function SysOsExec(Command)
    local cmd = Command..' 2> ./SysOsExecute.log'
    local ret = os.execute(cmd)

    local file = assert(io.open("./SysOsExecute.log", "r"))
    local stdout = file:read("*all")
    assert(file:close())

    os.execute("rm ./SysOsExecute.log")

    return (ret == 0 or ret == true), stdout
end

return { SysOsExec = SysOsExec }
