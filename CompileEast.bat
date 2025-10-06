@echo off
title Запустить East.cpp
color 0A
chcp 65001 > nul

REM ★★★ Исправление: устранение проблемы с невозможностью gcc распознавать китайские иероглифы в имени пользователя при создании временных файлов. ★★★
set TEMP=%CD%\temp
set TMP=%CD%\temp
if not exist "%TEMP%" mkdir "%TEMP%"

echo ===============================
echo	East.cpp Компилятор
echo ===============================
echo.

REM 其余代码保持不变...
if not exist "East.cpp" (
	echo Ошибка: исходный файл East.cpp не найден
	echo.
	echo Текущий список файлов в каталоге:
	dir *.cpp
	echo.
	pause
	exit /b 1
)

echo файл East.cpp найден
echo.

REM Проверка компилятора
g++ --version >nul 2>&1
if %errorlevel% neq 0 (
	echo ошибка: компилятор g++ не найден
	echo установите MinGW или настройте переменные окружения
	pause
	exit /b 1
)

echo Начать компиляцию
echo --------------------------------------------------
g++ -Wall -std=c++11 -O2 -fexec-charset=UTF-8 East.cpp -o East_program.exe

REM Проверка результатов компиляции
if %errorlevel% equ 0 (
	echo Компиляция успешна!
	echo.
	echo Программа запущена...
	echo ===============================
	East_program.exe
	echo ===============================
	echo Программа выполнена.
) else (
	echo Компиляция не удалась! Код ошибки: %errorlevel%
)

echo.
pause