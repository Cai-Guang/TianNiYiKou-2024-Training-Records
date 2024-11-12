:loop
 data.exe > data.in
 std.exe < data.in > std.out
 my.exe < data.in > my.out
fc std.out my.out
if not errorlevel 1 goto loop
pause
goto loop