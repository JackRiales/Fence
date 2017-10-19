@ECHO off

set name=fence
set cart_conf=nrom_128_horz.cfg
set include=include
set meta=meta
set src=source
set cc_out=asm
set cc_flags=-Oi
set platform=nes
set ca_out=build
set ld_out=bin

set path=%path%;%cc65%\bin

set sources=%name% nesdev players
set asm=%cc_out%/neslib/crt0.s
set objects=%ca_out%/%name%.o %ca_out%/nesdev.o %ca_out%/players.o %ca_out%/neslib.o %ca_out%/nes.lib

REM compile to asm
ECHO Compiling to assembly ...
for %%a in (%sources%) do (
    cc65 %cc_flags% -I %include% -I %meta% -o %cc_out%/%%a.s %src%/%%a.c
)

REM compile to object binaries
ECHO Compiling to binary ...
ca65 -o %ca_out%/neslib.o %asm%
for %%a in (%sources%) do (
    ca65 -o %ca_out%/%%a.o %cc_out%/%%a.s
)

REM Link
ECHO Linking ...
ld65 -C %cart_conf% -o %ld_out%/%name%.nes %objects%
ECHO Done!

del %ca_out%\*.o