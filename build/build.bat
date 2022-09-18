@echo off
SET cur=%CD%
cd ..
SET folder=%CD%
IF EXIST "%folder%\flux.exe" DEL /F "%folder%\flux.exe"
g++ %folder%\flux.cpp -o %folder%\flux.exe -Wno-multichar -Wno-overflow
flux.exe program.flux
cd %cur%