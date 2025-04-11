:loop
    data.exe > data.txt
    M.exe < data.txt > M.out
    M1.exe < data.txt > M1.out
    fc M.out M1.out
    if not errorlevel 1 goto loop
pause