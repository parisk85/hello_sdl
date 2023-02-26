### Local Setup
- Download Min-GW setup https://sourceforge.net/projects/mingw/files/latest/download
- Install Min-GW
- Open Min-GW installation manager and mark mingw32-gcc-g++ for installation
- Apply for the package to install
- Add Min-GW to path environmental variable
- Download and unzip SDL2 zip with -VC suffix

### To compile my main.cpp
> g++ main.cpp -o main

### To compile with SDL2
> g++ -IC:\SDL2\SDL2-2.26.3\include main.cpp -o main -L"C:\SDL2\SDL2-2.26.3\lib\x86" -lSDL2 -mconsole

### To compile in different input and output dirs
> g++ -IC:\SDL2\SDL2-2.26.3\include -Isrc src\game.cpp -o build\game -L"C:\SDL2\SDL2-2.26.3\lib\x86" -lSDL2 -mconsole
