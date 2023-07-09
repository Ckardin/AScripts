

if($($env:ASHES_DIR | grep -c .) -ceq 0)
{
    setx /M ASHES_DIR C:\Ashes
    setx ASHES_DIR C:\Ashes

    if(Test-Path -Path "C:\Ashes\bin")
    {
        Copy-Item -Path .\Windows\*.ps1 -Destination C:\Ashes\bin -Force
    }
    else {
        if(Test-Path -Path "C:\Ashes")
        {
            mkdir C:\Ashes\bin
        }
        else
        {
            mkdir C:\Ashes
            mkdir C:\Ashes\bin
        }

        Copy-Item -Path .\Windows\*.ps1 -Destination C:\Ashes\bin -Force
    }

    mkdir C:\Ashes
    mkdir C:\Ashes\bin
}
else
{
    $INSTALL_DIR = $($env:ASHES_DIR) + "\bin"

    if(Test-Path -Path $INSTALL_DIR)
    {
        Copy-Item -Path .\Windows\*.ps1 -Destination $INSTALL_DIR -Force
    }
    else {
        mkdir $INSTALL_DIR
        Copy-Item -Path .\Windows\*.ps1 -Destination $INSTALL_DIR -Force
    } 
}
