@echo off
::以管理员运行
::%1 mshta vbscript:CreateObject("Shell.Application").ShellExecute("cmd.exe","/c %~s0 ::","","runas",1)(window.close)&&exit
::设置要永久加入到path环境变量中的路径
::要以管理员权限运行
set MY_PATH=E:\lou\software\Git\cmd\;E:\lou\software\Git\;E:\lou\software\TDM-GCC10.3.0\bin\;
 
set PATH=%MY_PATH%%PATH%;
reg add "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v "Path" /t REG_EXPAND_SZ /d "%PATH%" /f
pause