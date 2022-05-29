@echo off
g++ -std=c++11 -o tmp.exe %1.cpp
echo running...
tmp.exe
