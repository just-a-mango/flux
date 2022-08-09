@echo off
set /p msg=Commit message:
git add .
git commit -am "%msg%"
git push -f origin main
