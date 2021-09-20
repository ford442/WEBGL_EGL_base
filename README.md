mkdir build

cd build

emcmake cmake ..

emmake make

<br>

(Must have CMake 3.20)

<br>

Imperatively modify the env.bat of ./project/ to adapt to your new paths.
Also, I am using VSCODE and the .vscode contains paths to modify:
- c_cpp_properties.json
- tasks.json

I am currently compiling this project with Mingw64 from MSYS2.
PLEASE NOTE, according to emscripten refers to itself as a purely 32-bit platform.
https://emscripten.org/docs/compiling/Building-Projects.html

Compatibility issues can arise when compiling in the 64 bit architecture.
So I recommend switching to MingW, although the project has been abandoned or switching to another compiler.
The MINGW and MINGW64 compilers are functional for this project.

///////
 
Compile the project!

- ./cmake_generate.bat
- ./cmake_build.bat

For bin deployment I use: python -m http.server
which is the newer command from SimpleHTTPServer.
