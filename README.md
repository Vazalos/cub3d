*This project has been created as part of the 42 curriculum by david-fe and gumendes.*

## Description

**cub3d** is a 3D graphical project inspired by the classic FPS game Wolfenstein 3D. This project is an introduction to raycasting techniques, a fundamental concept in computer graphics that creates a pseudo-3D perspective in a 2D map.

The goal of cub3d is to create a dynamic view inside a maze, which players can navigate through using keyboard and mouse controls, experiencing real-time rendering of textured walls, floor, and ceiling.

## Instructions

### Prerequisites
- Make
- GCC or Clang compiler
- MiniLibX library (included in make)

### Compilation

To compile the project run:

'make': for base project
'make bonus' :for mouse controls and minimap
'make O_FLAG=3', with or without 'bonus', for a more fluid experience

This will generate the `cub3d` executable.

### Execution

Run the program with a valid `.cub` map file, for example:

./cub3d maps/map.cub 

### Map Configuration

Map files (`.cub`) must include:
- **Textures**: Paths to north, south, east, and west wall textures (NO, SO, EA, WE)
- **Colors**: RGB values for floor (F) and ceiling (C)
- **Map layout**: A grid using characters:
  - `1` for walls
  - `0` for empty space
  - `N`, `S`, `E`, or `W` for player starting position and orientation

### Controls

- **W/A/S/D** or **Arrow Keys**: Move forward, left, backward, right
- **Left/Right Arrow Keys**: Rotate camera
- **ESC**: Exit the program
- **Mouse Move Left/Right**: Rotate camera (bonus only)
- **P**: debug prints
- **N**: hide cursor (useful in bonus)
- **M**: hide minimap (bonus only)


## Resources

### References

- **[Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html)**: Comprehensive guide to raycasting fundamentals and implementation

### AI Usage

AI tools were used to assist with the following aspects of this project:

- **Rotation formulas**: For view and minimap cursor rotations calculations
- **README creation**: Created a base structure for the README.md