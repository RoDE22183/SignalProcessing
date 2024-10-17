@echo off
setlocal enabledelayedexpansion

:: Function to run the program with given inputs
:run_test
echo.
echo Test Case: %~1
echo %~2 | waveform_generator-exe.exe
echo Exit Code: !errorlevel!
echo ----------------------------------------
exit /b

:: Compile the program (adjust this line according to your compilation needs)
g++ -std=c++17 main.cpp waveform.cpp squarewave.cpp sinwave.cpp dsp.cpp -o waveform_generator.exe

:: Test 1: Valid input for sine wave
call :run_test "Valid sine wave" "sine 440 1 0 2 44100 n"

:: Test 2: Valid input for square wave
call :run_test "Valid square wave" "square 220 0.5 1.57 1 22050 n"

:: Test 3: Invalid waveform type
call :run_test "Invalid waveform type" "sine 440 1 0 2 44100 n"

:: Test 4: Invalid frequency (negative)
call :run_test "Invalid frequency" "sine -440 1 0 2 44100 n"

:: Test 5: Invalid amplitude (non-numeric)
call :run_test "Invalid amplitude" "sine 440 abc 0 2 44100 n"

:: Test 6: Invalid phase (non-numeric)
call :run_test "Invalid phase" "sine 440 1 xyz 2 44100 n"

:: Test 7: Invalid duration (zero)
call :run_test "Invalid duration" "sine 440 1 0 0 44100 n"

:: Test 8: Invalid sample rate (negative)
call :run_test "Invalid sample rate" "sine 440 1 0 2 -44100 n"

:: Test 9: Valid input with DSP application
call :run_test "Valid input with DSP" "sine 440 1 0 2 44100 y 2 0.1 5 n"

:: Test 10: Invalid scale factor for DSP
call :run_test "Invalid scale factor for DSP" "sine 440 1 0 2 44100 y abc 0.1 5 n"

:: Test 11: Invalid noise magnitude for DSP (negative)
call :run_test "Invalid noise magnitude for DSP" "sine 440 1 0 2 44100 y 2 -0.1 5 n"

:: Test 12: Invalid filter window size for DSP (zero)
call :run_test "Invalid filter window size for DSP" "sine 440 1 0 2 44100 y 2 0.1 0 n"

:: Test 13: Valid input with waveform overlay
call :run_test "Valid input with waveform overlay" "sine 440 1 0 2 44100 y 2 0.1 5 y square"

:: Test 14: Invalid second waveform type for overlay
call :run_test "Invalid second waveform type for overlay" "sine 440 1 0 2 44100 y 2 0.1 5 y sawtooth"

echo All tests completed.
pause