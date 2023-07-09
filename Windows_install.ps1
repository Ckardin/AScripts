

if($($env:ASHES_DIR | grep -c .) -ceq 0)
{
    setx /M ASHES_DIR C:\Ashes
    setx ASHES_DIR C:\Ashes
    mkdir C:\Ashes
    mkdir C:\Ashes\bin
    Copy-Item -Path .\Windows\*.ps1 -Destination C:\Ashes\bin -Force
}
else
{
    mkdir $($env:ASHES_DIR)/bin
    Copy-Item -Path .\Windows\*.ps1 -Destination $($env:ASHES_DIR) -Force
}
