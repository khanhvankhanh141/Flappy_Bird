# **FLAPPY BIRD**
## GAME PROJECT OF INT2215-2 created by ĐOÀN VIỆT KHÁNH

Using C/C++ and [SDL2](https://www.libsdl.org/), [SDL_ttf](https://www.libsdl.org/projects/SDL_ttf/), [SDL_image](https://www.libsdl.org/projects/SDL_image/) development libraries on [Code::Blocks](https://www.codeblocks.org/).

### Introduction
  * Flappy Bird is an arcade-style game in which the player controls the bird Faby, which moves persistently to the right. The player is tasked with navigating Faby through pairs of pipes that have equally sized gaps placed at random heights. Faby automatically descends and only ascends when the player touch the SpaceButton. Each successful pass through a pair of pipes awards the player one point.
  * My game is an evolution of Flappy Bird for desktop. It was code by C++ language active on Code::Blocks IDE for C++ with graphics made by development libraries `SDL2`, SDL_image, SDL_ttf.
### Screenshots
#### The Start Menu 

<img src="https://user-images.githubusercontent.com/72251681/116425366-70f57180-a86c-11eb-844d-9c7b5a7f0230.png" width="600">

#### GameOver Screen

<img src="https://user-images.githubusercontent.com/72251681/116425427-7ce13380-a86c-11eb-9fdb-b72c4d2d315b.png" width="600">

### Compiling
You need to setup SDL development libraries to play the game:
* Learn how to setup SDL2 for your computer on [Lazyfoo](https://lazyfoo.net/tutorials/SDL/index.php) at the Lesson 1.
* Put the `libgcc_s_seh-1.dll`, `libstdc++-6.dll`, `libwinpthread-1.dll` in [Core](https://github.com/khanhvankhanh141/Flappy_Bird/tree/main/Core) into the System32 if your computer contains the 32bit library <into the SysWow64 if contains the 64bit library >.
* Extract file [Setup](https://github.com/khanhvankhanh141/Flappy_Bird/blob/main/Setup.rar) to get the SDL2 library or another library to compile.
* After setup the libraries and put all file.dll into the Windows system dowload all file of project.
* After setup [Mingw64](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-win32/seh/x86_64-8.1.0-release-win32-seh-rt_v6-rev0.7z/download),[SDL2](https://www.libsdl.org/download-2.0.php),[SDL_Image](https://www.libsdl.org/projects/SDL_image/),[SDL_TTF](https://www.libsdl.org/projects/SDL_ttf/) you can use [Flappy-Bird.exe](https://github.com/khanhvankhanh141/Flappy_Bird/blob/main/bin/Debug/Flappy_Bird.exe) in [bin/Debug](https://github.com/khanhvankhanh141/Flappy_Bird/tree/main/bin/Debug) to play the game.
* Another way you can setup the compiler in `Code::Blocks` and run the source code.
### Play Guide
Press Space to jump.
### Contributing 
* This game made by 100% C++ language.
