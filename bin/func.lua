function SysOsExec(Command)
    local cmd = Command..' > /tmp/SysOsExecute.log 2>&1'
    local ret = os.execute(cmd)

    local file = assert(io.open("/tmp/SysOsExecute.log", "r"))
    local stdout = file:read("*all")
    assert(file:close())

    return (ret == 0 or ret == true), stdout
end

return { SysOsExec = SysOsExec }
