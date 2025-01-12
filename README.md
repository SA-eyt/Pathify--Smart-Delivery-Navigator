# Pathify-Smart Delivery Navigator

## Overview
The code implements a navigation system using C++ with the FMX framework, primarily focused on pathfinding between different locations using Dijkstra's algorithm.

## Key Components

### Data Structures
- **Graph Implementation:** Utilizes both adjacency matrix and adjacency list.
- **Custom Node Struct:** Represents linked list elements.
- **Fixed-size Arrays:** Stores location names and distances.

### Core Functionality

#### Path Finding
- Implements **Dijkstra's Algorithm** for shortest path calculation.
- Supports **weighted, undirected edges**.
- Includes calculations for:
  - Distance
  - Fuel consumption
  - Travel time

#### GUI Integration
- Input validation for source and destination.
- Real-time feedback through labels and messages.
- Clear functionality for resetting inputs.

### Notable Features
- **Fuel Consumption Calculation:** Based on distance and fuel rate.
- **Travel Time Estimation:** Uses user-provided speed input.
- **Warning System:** Alerts for insufficient fuel.
- **Case-insensitive Matching:** Matches locations without regard to case.
- **Input Sanitization:** Ensures reliability and consistency.

## Technical Specifications
- **Language:** C++ with FMX framework.
- **Graph Size:** Fixed at 8 nodes.
- **Pre-defined Locations:** 8 destinations.
- **Edge Properties:** Bidirectional with weights.

## Limitations
- Fixed graph size of 8 nodes.
- Hard-coded location names.
- Static edge connections.
- No dynamic memory management for locations.

## Safety Features
- Input validation for all fields.
- Warning system for fuel requirements.
- Error messages for invalid locations.
- Input sanitization for consistency.

## Performance Considerations
- **Time Complexity:** O(V^2) for Dijkstra's implementation.
- **Space Complexity:** O(V^2) for adjacency matrix storage.

# DSA Project: Pathify-Smart Delivery Navigator

## Description
The **Smart Delivery Navigator** is a GUI-based application developed using **RAD Studio** and written in **C++**. It is designed to calculate the shortest delivery route in a city. The project demonstrates the use of **graphs** and other data structures to solve real-world routing problems efficiently.

## Features
- Calculate the shortest delivery path using **Dijkstra’s Algorithm**.
- Display detailed information, including distance, estimated time, and fuel requirements.
- Interactive input system for managing delivery locations.
- Efficiently handles multiple delivery points with optimized algorithms.

## Technologies Used
- **Programming Language:** C++
- **Data Structures:** Graphs, Arrays, and Linked Lists
- **Platform:** GUI-based application developed using **RAD Studio**.

## How to Run

1. Clone the repository to your local machine:

    ```sh
    git clone https://github.com/your-username/DSA-Project-Smart-Delivery-Navigator.git
    ```

2. Navigate to the project directory:

    ```sh
    cd DSA-Project-Smart-Delivery-Navigator
    ```

3. Open the project in **RAD Studio**.

4. Build and run the application within the IDE.

5. Follow the on-screen instructions to interact with the navigator.
