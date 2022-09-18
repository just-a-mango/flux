@echo off
IF EXIST "flux.exe" DEL /F "flux.exe"
g++ flux.cpp -o flux.exe -Ofast -Wall -Wextra -pedantic -flto -fno-signed-zeros -fno-trapping-math -frename-registers -funroll-loops
flux.exe program.flux