# 🚀 2D Projectile Motion Simulator

## 📌 About the Project
The **2D Projectile Motion Simulator** is a Computer Graphics mini project developed using **C++ and OpenGL (GLUT/FreeGLUT)**.

This project visually demonstrates the motion of a projectile launched at a particular angle and initial velocity. It displays the parabolic trajectory and calculates important parameters such as maximum height, time of flight, and horizontal range.

The simulation allows users to change the launch angle and speed using keyboard controls and observe the projectile's motion in real time.

## 🎯 Objectives
- To understand the concept of projectile motion.
- To visualize the parabolic trajectory using computer graphics.
- To calculate maximum height, time of flight, and horizontal range.
- To implement 2D animation using OpenGL.
- To understand keyboard interaction and graphical transformations.

## ✨ Features
- 2D projectile motion simulation.
- Real-time projectile animation.
- Adjustable launch angle and initial velocity.
- Parabolic trajectory visualization.
- Display of maximum height.
- Calculation of time of flight.
- Calculation of horizontal range.
- Visualization of velocity components and direction of motion.

## 🛠️ Technologies Used
- **Programming Language:** C++
- **Graphics Library:** OpenGL
- **Windowing Library:** GLUT / FreeGLUT
- **IDE:** CodeBlocks
- **Operating System:** Windows

## 📐 Mathematical Formulas

The simulator uses the following projectile motion equations:

**1. Horizontal Velocity**

Vx = V₀ × cos(θ)

**2. Vertical Velocity**

Vy = V₀ × sin(θ)

**3. Maximum Height**

H = V₀² × sin²(θ) / 2g

**4. Time of Flight**

T = 2 × V₀ × sin(θ) / g

**5. Horizontal Range**

R = V₀² × sin(2θ) / g

Where:
- V₀ = Initial velocity
- θ = Launch angle
- g = Acceleration due to gravity (9.81 m/s²)

## 🎮 Controls

| Key | Function |
|---|---|
| SPACE | Launch the projectile |
| UP Arrow | Increase launch angle |
| DOWN Arrow | Decrease launch angle |
| RIGHT Arrow | Increase initial speed |
| LEFT Arrow | Decrease initial speed |
| ESC | Exit the simulation |

## 💻 Software Requirements
- CodeBlocks IDE
- C++ Compiler (MinGW)
- OpenGL
- GLUT / FreeGLUT
- Windows Operating System

## ⚙️ How to Run the Project

1. Install CodeBlocks with the MinGW compiler.
2. Install and configure the FreeGLUT library.
3. Create a new C++ project in CodeBlocks.
4. Copy the project source code into `main.cpp`.
5. Configure the linker settings with the following libraries:

   - freeglut
   - opengl32
   - glu32

6. Make sure `freeglut.dll` is available in the executable's directory or system path.
7. Build and run the project.

## 📊 Project Output

The simulator displays:
- Launch platform and projectile.
- Launch angle and velocity.
- Parabolic trajectory.
- Maximum height.
- Time of flight.
- Horizontal range.
- Current velocity and direction of motion.

## 👨‍💻 Team Members

- Kartik Ambhore (10)
- Aditya Lichade (11)
- Soham More (14)
- Shreyas Agre (23)

## 👩‍🏫 Project Guide

**Dr. Madhavi Nimkar**

## 📚 References
- OpenGL Documentation – https://www.opengl.org/
- FreeGLUT Documentation – https://freeglut.sourceforge.net/
- C++ Reference – https://en.cppreference.com/
- Computer Graphics with OpenGL – D. Hearn and M. P. Baker
- Fundamentals of Physics – Halliday, Resnick and Walker

---

**Project:** Computer Graphics Mini Project  
**Title:** 2D Projectile Motion Simulator

