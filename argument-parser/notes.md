# Quick notes

The commands below are what I used to compile using msvc compiler

```bat
cl /I include /Fobuild\objects\ /c /EHsc src\ArgParser.cpp
cl /I include /Fobuild\objects\ /c /EHsc src\main.cpp
cl /EHsc build\objects\*.obj /link /out:build\apps\ArgParser.exe
```
