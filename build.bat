@echo off
IF EXIST flux.exe DEL /F flux.exe
IF "%1" == "-production" (
    g++ flux.cpp -o flux.exe -Ofast -Wall -Wextra -Wno-multichar -Wno-overflow flux.o
)
IF "%1" == "" (
   g++ flux.cpp -o flux.exe -Wno-multichar -Wno-overflow
)
flux.exe program.flux