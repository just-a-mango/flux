@echo off
SET cur=%CD%
cd ..
SET folder=%CD%
IF EXIST "%folder%\flux.exe" DEL /F "%folder%\flux.exe"
IF "%1" == "-production" (
    g++ %folder%\flux.cpp -o %folder%\flux.exe -Ofast -Wall -Wextra -Wno-multichar -Wno-overflow %folder%\resources\flux.o
)
IF "%1" == "" (
   g++ %folder%\flux.cpp -o %folder%\flux.exe -Wno-multichar -Wno-overflow
)
echo %folder%
flux.exe program.flux
cd %cur%
