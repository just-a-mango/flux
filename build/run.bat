@echo off
SET cur=%CD%
cd ..
flux.exe program.flux
cd %cur%
