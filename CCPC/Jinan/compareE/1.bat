:loop
	data.exe >1.in
	std.exe <1.in >std.out
	my.exe <1.in >my.out
	fc std.out my.out
	if not errorlevel 1 goto loop
else
pause
goto loop