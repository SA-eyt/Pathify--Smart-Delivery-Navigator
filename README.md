# Pathify-Smart Delivery Navigator

## Description
The **Smart Delivery Navigator** is a GUI-based application developed using **RAD Studio** and written in **C++**. This project demonstrates the efficient use of graphs and algorithms, such as **Dijkstra's Algorithm**, to solve real-world routing problems. It calculates the shortest delivery route in a city while providing detailed information on distance, travel time, and fuel consumption. By integrating a user-friendly GUI, the application ensures an interactive and seamless user experience.

### Data Structures
- **Graph Implementation:** Utilizes both adjacency matrix and adjacency list.
- **Custom Node Struct:** Represents linked list elements.
- **Fixed-size Arrays:** Stores location names and distances.

## Features
- **Fuel Consumption Calculation:** Based on distance and fuel rate.
- **Travel Time Estimation:** Uses user-provided speed input.
- **Warning System:** Alerts for insufficient fuel.
- **Case-insensitive Matching:** Matches locations without regard to case.
- **Input Sanitization:** Ensures reliability and consistency.

## Technologies Used
- **Programming Language:** C++
- **Framework:** FMX (FireMonkey) in RAD Studio

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

---
This project highlights the practical application of data structures and algorithms in developing smart navigation systems, demonstrating a blend of technical efficiency and user-centric design.


