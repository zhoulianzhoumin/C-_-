@echo off
chcp 65001 > nul
echo ========================================
echo   旅游菜单系统 - 编译脚本
echo ========================================

echo 正在编译目标文件...

g++ -c -std=c++11 main.cpp -o main.o
if %errorlevel% neq 0 (
    echo 错误: main.cpp 编译失败
    pause
    exit /b 1
)

g++ -c -std=c++11 menu_manager.cpp -o menu_manager.o
if %errorlevel% neq 0 (
    echo 错误: menu_manager.cpp 编译失败
    pause
    exit /b 1
)

echo 正在链接可执行文件...
g++ main.o menu_manager.o -o tourist_system.exe
if %errorlevel% neq 0 (
    echo 错误: 链接失败
    pause
    exit /b 1
)

echo.
echo ========================================
echo   编译成功! 生成 tourist_system.exe
echo ========================================
echo.

echo 是否要运行程序？(Y/N)
set /p choice=
if /i "%choice%"=="Y" (
    echo 正在启动程序...
    echo.
    tourist_system.exe
)

pause