@echo off

mkdir ..\build
pushd ..\build
cl -Zi /w /EHsc /MTd ..\code\gl_invade.cpp ..\code\ShaderLoader.cpp ..\code\glad.c ..\code\stb_image.cpp ..\code\invade.cpp ..\code\Enemy.cpp /link  /LIBPATH:..\lib OpenGL32.lib glfw3.lib user32.lib gdi32.lib Shell32.lib Winmm.lib
popd