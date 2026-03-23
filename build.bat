@echo off
g++ main.cpp src\algorithms\*.cpp src\algorithms\*.h src\core\*.cpp src\core\*.h src\engine\*.cpp src\engine\*.h -o focusforge.exe
echo Build complete!
pause