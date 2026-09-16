# 🚀 2D Space Shooter — OpenGL Computer Graphics Mini Project

A simple **2D Space Shooter game developed using C++ and OpenGL** as a Computer Graphics mini project.

The project demonstrates fundamental computer graphics concepts such as **2D transformations, animation, keyboard interaction, object rendering, collision detection, and double buffering** through an interactive arcade-style game.

## 🎯 Objectives

- To understand the fundamentals of graphics programming using OpenGL.
- To implement 2D objects and transformations.
- To create real-time animation using OpenGL.
- To implement keyboard-based interaction.
- To implement basic collision detection between game objects.
- To develop an interactive game environment using fundamental Computer Graphics concepts.

## 🎮 Game Features

- Player-controlled spaceship
- Left and right movement
- Enemy spaceship generation and movement
- Bullet shooting
- Bullet–enemy collision detection
- Score system
- Lives/health system
- Increasing difficulty through levels
- Game-over and restart functionality
- Animated space background
- Basic explosion effects

## 🛠️ Technologies Used

- **Language:** C++
- **Graphics Library:** OpenGL
- **Window/Input Library:** FreeGLUT
- **Development Environment:** Visual Studio / VS Code
- **Optional Asset Creation:** Blender

## 🧩 Computer Graphics Concepts

The project demonstrates:

- 2D Translation
- Rotation
- Scaling
- Object Transformation
- Animation
- Keyboard Interaction
- Collision Detection
- Double Buffering
- Coordinate Systems
- Basic Shape Rendering

## 🕹️ Controls

| Key | Action |
|---|---|
| `←` / `A` | Move spaceship left |
| `→` / `D` | Move spaceship right |
| `SPACE` | Fire bullet |
| `P` | Pause / Resume |
| `R` | Restart game |
| `ESC` | Exit |

## 📂 Project Structure

```text
2D-Space-Shooter/
│
├── src/
│   ├── main.cpp
│   ├── player.cpp
│   ├── enemy.cpp
│   ├── bullet.cpp
│   ├── collision.cpp
│   └── game.cpp
│
├── include/
│   ├── player.h
│   ├── enemy.h
│   ├── bullet.h
│   ├── collision.h
│   └── game.h
│
├── assets/
│   ├── textures/
│   └── sounds/
│
├── screenshots/
│
│
├── Documentation/
│
├── README.md
└── .gitignore

```

> The exact structure may be modified during implementation depending on the final project architecture.

## ⚙️ System Requirements

### Hardware

- Computer/Laptop
- Minimum 4 GB RAM
- Basic graphics support
- Keyboard

### Software

- Windows / Linux
- C++ compiler
- OpenGL
- FreeGLUT
- Visual Studio or VS Code

## 🔄 Game Logic

The game continuously performs the following operations:

```text
Initialize Game
      ↓
Render Player & Enemies
      ↓
Read Keyboard Input
      ↓
Update Player Position
      ↓
Update Bullets
      ↓
Update Enemies
      ↓
Check Collisions
      ↓
Update Score & Lives
      ↓
Check Game State
      ↓
Render Updated Frame
      ↓
Repeat
```

## 💥 Collision Detection

Collision detection is used to determine interactions between:

- Player and enemies
- Bullets and enemies
- Enemies and game boundaries

When a bullet collides with an enemy:

```text
Bullet + Enemy
      ↓
Collision Detected
      ↓
Enemy Destroyed
      ↓
Score Increased
      ↓
Bullet Removed
```

## 🎨 Rendering

The game environment is constructed using OpenGL primitives and transformations.

Major objects include:

- Spaceship
- Enemy spaceships
- Bullets
- Stars
- Explosions
- Game interface elements

## 📈 Future Enhancements

Possible future improvements include:

- Additional enemy types
- Boss battles
- Power-ups
- Different weapons
- Sound effects and background music
- More complex enemy movement patterns
- High-score persistence
- Improved textures and visual effects

## 👥 Team

**Computer Graphics Mini Project**

Team Members:

- Member 1 : Kartik Ambhore

## 📚 References

- OpenGL documentation
- FreeGLUT documentation
- Computer Graphics course material
- Relevant tutorials and references used during implementation

---

### ⭐ Project Status

**Currently under development.**

The project will be implemented incrementally, starting with basic OpenGL rendering and progressing toward a complete interactive 2D space shooter.
