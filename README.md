# Galaga OpenGL

A 3D arcade game inspired by the classic **Galaga**, developed collaboratively in **C++** using **OpenGL** and **GLUT/FreeGLUT**.

The project explores real-time rendering, player input, enemy behaviour, shooting mechanics, collision handling and 3D model loading without relying on a commercial game engine.

## Authors

- José Manuel Pastor González
- Adrián Gómez-Lobo Núñez

## Technologies

- C++
- OpenGL
- GLUT / FreeGLUT
- GLEW
- MSVC / Visual Studio Build Tools

## Repository structure

- `src/` — C++ source code and headers
- `assets/models/` — 3D models used by the game
- `packages/` — OpenGL/GLUT dependencies used by the original project
- `Galaga-OpenGL.sln` / `.vcxproj` — MSBuild project files

## Build

Build the solution in `Release | x64`. The project automatically copies the required models into the executable output directory.
