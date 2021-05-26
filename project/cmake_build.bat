
echo Recuperation de l'environnement ..
call env.bat 

cd /D %BUILD_DIR%
echo Regeneration du projet ..
cmake^
  -G "MinGW Makefiles"^
  -DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN_FILE%^
  -B %BUILD_DIR%^
  -S %CMAKE_FILE_DIR%^
  > /dev/null

echo Build..
cmake --build . -j 8
if !ERRORLEVEL! GEQ 1 goto rate
cmake --install .
if !ERRORLEVEL! GEQ 1 goto rate

cd %~dp0
EXIT /B 0

:rate
cd %~dp0
EXIT /B 1