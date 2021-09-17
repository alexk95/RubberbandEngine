@ECHO OFF
REM This script requires the following environment variables to be set:
REM 1. RUBBERBAND_ENGINE_ROOT
REM 2. DEVENV_ROOT

REM Ensure that the setup will only be performed once
if "%RUBBERBAND_ENGINE_ENV_DEFINED%"=="1" (
	goto END
)

SET RUBBERBAND_ENGINE_ENV_DEFINED=1

ECHO Setup Rubberband Engine environment

IF "%RUBBERBAND_ENGINE_ROOT%" == "" (
	ECHO Please specify the following environment variables: RUBBERBAND_ENGINE_ROOT
	goto END
)

IF "%DEVENV_ROOT%" == "" (
	ECHO Please specify the following environment variables: DEVENV_ROOT
	goto END
)

IF "%R_JSON_ROOT%" == "" (
	ECHO Setup R_JSON_ROOT
	SET R_JSON_ROOT=%RUBBERBAND_ENGINE_ROOT%\Third_Party_Libraries\rapidjson
)

SET RUBBERBAND_ENGINE_CORE=%RUBBERBAND_ENGINE_ROOT%\Core

SET RUBBERBAND_ENGINE_OSG=%RUBBERBAND_ENGINE_ROOT%\osgWrapper

SET RJSON_INCLUDE="%R_JSON_ROOT%\include"

REM ##########################################################################################################

ECHO Environment was set up successfully.

:END
