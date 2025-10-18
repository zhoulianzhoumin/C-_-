@echo off
color 0A
chcp 65001 > nul

set EXE=merge_sort.exe
set CHARSET="-finput-charset=utf-8 -fexec-charset=utf-8"
if exist %EXE% del %EXE%

g++ io.cpp MergeSort.cpp orig_1d_arr.cpp -o %EXE%

%EXE%

pause