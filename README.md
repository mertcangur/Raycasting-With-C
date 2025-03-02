# cub3d

cub3d is a project from Ecole 42 focused on graphics programming. This project aims to develop a raycasting engine similar to Wolfenstein 3D, helping students learn fundamental rendering techniques.

## Requirements

- **Operating System**: macOS or Linux
- **Compiler**: gcc or clang
- **Libraries**: minilibX (42's graphics library), math library (`-lm`)

## Installation

1. **Clone the repository:**  
   ```sh
   git clone https://github.com/username/cub3d.git
   cd cub3d
   ```

2. **Compile the project:**  
   ```sh
   make
   ```

3. **Run the program:**  
   ```sh
   ./cub3d map.cub
   ```

## Controls

- **WASD**: Move
- **Left / Right Arrow Keys**: Rotate view
- **ESC**: Exit

## Directory Structure

- `src/` - Main source files
- `includes/` - Header files
- `maps/` - Example maps
- `textures/` - Textures used in the game

## Map Format

Maps are stored in `.cub` files and follow this format:
```
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm
F 220,100,0
C 225,225,225

111111
100001
100001
111111
```

- **NO, SO, WE, EA**: Paths to texture files
- **F, C**: Floor (F) and ceiling (C) colors (RGB format)
- **Map**: 1 = Wall, 0 = Empty space

## Development

- `make clean`: Cleans compiled files
- `make fclean`: `make clean` + removes the executable
- `make re`: Recompiles the project

## License

This project was developed as part of Ecole 42's curriculum and is not released under any specific license.

