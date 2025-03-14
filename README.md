# Maze Solver - C++ Solution Using DFS

## Overview

The **Maze Solver** is a C++ implementation of a Depth-First Search (DFS) algorithm that solves a maze represented as a 2D grid. The program finds a path from a designated start point to an endpoint while avoiding obstacles (walls). It demonstrates key concepts of graph traversal algorithms, object-oriented programming (OOP), and data structures in C++.

## Features

- **DFS Algorithm**: Implements a Depth-First Search approach to explore the maze.
- **Pathfinding**: Finds and prints a valid path from the start point to the destination, if one exists.
- **Graph Traversal**: Uses a stack-based approach for DFS traversal.
- **Object-Oriented Design**: The program is structured using OOP principles, encapsulating the maze-solving logic within a class.
- **User-Friendly Output**: Displays the solution path (if found) or an indication when no path exists.

## Project Structure

- `MazeSolver.cpp`: The C++ source file containing the implementation of the maze solver and the DFS algorithm.
- `README.md`: This file, containing detailed instructions and project information.

## Maze Representation

- **0**: Open path (can be traversed).
- **1**: Wall (cannot be traversed).
  
### Example Maze:
The maze is a fixed 5x5 grid:

