@echo off
setlocal enabledelayedexpansion

echo ===================================================
echo   Building Unity WebGL for Next.js Website
echo ===================================================

set UNITY_PATH=D:\unity\6000.6.0f1\Editor\Unity.exe
if not exist "%UNITY_PATH%" (
    echo [ERROR] Unity Editor not found at %UNITY_PATH%.
    echo Please set UNITY_PATH to your installed Unity.exe.
    exit /b 1
)

set CURR_DIR=%~dp0
if "%CURR_DIR:~-1%"=="\" set CURR_DIR=%CURR_DIR:~0,-1%

set PROJECT_PATH=%CURR_DIR%
set OUTPUT_PATH=%CURR_DIR%\..\nextjs-app\public\unity-build
set LOG_PATH=%CURR_DIR%\unity_webgl_build.log

echo Project Path: %PROJECT_PATH%
echo Target Output: %OUTPUT_PATH%
echo Log File:     %LOG_PATH%
echo.
echo Launching Unity in batchmode... (This may take several minutes on first run)

"%UNITY_PATH%" -batchmode -quit -projectPath "%PROJECT_PATH%" -executeMethod UnityNextViewer.Editor.WebGLBuilder.BuildWebGL -logFile "%LOG_PATH%"

if %ERRORLEVEL% equ 0 (
    echo.
    echo ===================================================
    echo   [SUCCESS] Unity WebGL build completed!
    echo   Build files generated in nextjs-app\public\unity-build
    echo ===================================================
) else (
    echo.
    echo ===================================================
    echo   [ERROR] Unity build failed with code %ERRORLEVEL%.
    echo   Check log file for details: %LOG_PATH%
    echo ===================================================
)

exit /b %ERRORLEVEL%
