### Local Setup
- Download Min-GW setup https://sourceforge.net/projects/mingw/files/latest/download
- Install Min-GW
- Open Min-GW installation manager and mark mingw32-gcc-g++ for installation
- Apply for the package to install
- Add Min-GW to path environmental variable
- Download and unzip SDL2 zip with -VC suffix

### To use with Makefile
- Add make and sys base from Min-GW installation
- use mingw23-make command to run

### To compile my main.cpp
> g++ main.cpp -o main

### To compile with SDL2
> g++ -IC:\SDL2\SDL2-2.26.3\include main.cpp -o main -L"C:\SDL2\SDL2-2.26.3\lib\x86" -lSDL2 -mconsole

### To compile in different input and output dirs
> g++ -std=c++11 -Isrc/ -Iinclude/ -Ilib/SDL2/include/ src/*.cpp -Llib/SDL2/ -Wl,-rpath,./lib/SDL2/ -lSDL2 -o bin/game
