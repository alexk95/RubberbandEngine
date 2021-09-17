@ECHO OFF
REM This script requires the following environment variables to be set:
REM 1. RUBBERBAND_ENGINE_ROOT
REM 2. DEVENV_ROOT
REM 3. QTDIR_ROOT
REM 3. OSG_ROOT
REM 3. R_JSON_ROOT

REM Ensure that the setup will only be performed once
if "%RUBBERBAND_ENGINE_OSG_ENV_DEFINED%"=="1" (
	goto END
)

SET RUBBERBAND_ENGINE_OSG_ENV_DEFINED=1

ECHO Setup Rubberband Engine OSG Wrapper environment

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

IF "%OSG_ROOT%" == "" (
	ECHO Please specify the following environment variables: OSG_ROOT
	goto END
)

IF "%R_JSON_ROOT%" == "" (
	ECHO Please specify the following environment variables: R_JSON_ROOT
	goto END
)

REM ##########################################################################################################

SET QTDIR=%QTDIR_ROOT%
SET QDIR=%QTDIR%

REM ##########################################################################################################

ECHO OSG Wrapper Environment was set up successfully.

:END
