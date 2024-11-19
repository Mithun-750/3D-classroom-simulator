# 3D Classroom Simulator

The 3D Classroom Simulator is an interactive application designed to simulate a classroom environment using OpenGL. It features various classroom elements such as chairs, tables, cupboards, windows, and a fan, all rendered in 3D.

## Features

- **Interactive Camera**: Navigate through the classroom using keyboard and mouse controls for an immersive experience.
- **3D Models**: Includes detailed models of classroom furniture and appliances.
- **Realistic Lighting and Colors**: Enhanced visual appeal with realistic lighting and color schemes.

## Directory Structure

- **`classroom.cpp`**: The main entry point of the application, handling rendering and user interaction.
- **`src/`**: Contains header files for different classroom elements:
  - `chair.hpp`: Defines the chair model.
  - `table.hpp`: Defines the table model.
  - `cupboard.hpp`: Defines the cupboard model.
  - `window.hpp`: Defines the window model.
  - `fan.hpp`: Defines the fan model.

## Controls

- **Keyboard**:
  - `W`, `A`, `S`, `D`: Move the camera forward, left, backward, and right.
  - `Esc`: Exit the application.

- **Mouse**:
  - Move to change the camera angle.
  - Right-click to toggle specific interactions.

## Dependencies

- OpenGL
- GLUT
- FreeGLUT

## Building and Running

1. Ensure you have the necessary OpenGL and GLUT libraries installed.
2. Compile the project using a C++ compiler with OpenGL support.
3. Run the executable to start the simulator.
