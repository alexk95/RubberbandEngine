@ECHO OFF
REM This script requires the following environment variables to be set:
REM 1. RUBBERBAND_ENGINE_ROOT
REM 2. DEVENV_ROOT
REM 3. QTDIR_ROOT

IF "%RUBBERBAND_ENGINE_ROOT%" == "" (
	ECHO Please specify the following environment variables: RUBBERBAND_ENGINE_ROOT
	goto END
)

IF "%DEVENV_ROOT%" == "" (
	ECHO Please specify the following environment variables: DEVENV_ROOT
	goto END
)

IF "%QTDIR_ROOT%" == "" (
	ECHO Please specify the following environment variables: QTDIR_ROOT
	goto END
)

CALL "%RUBBERBAND_ENGINE_ROOT%\setupEnvironment.bat"

CALL "%RUBBERBAND_ENGINE_CORE%\rebuild.bat" BOTH BUILD

:END