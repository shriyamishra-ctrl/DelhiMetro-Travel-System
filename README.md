# Delhi Metro Navigation App

Overview

The Delhi Metro Navigation App is a command-line application that allows users to navigate the Delhi Metro system. It enables users to find the shortest path between two metro stations, calculate the fare based on the distance traveled, and display the total travel time. The application also features a welcome page that is written to and read from a text file, enhancing the user experience.

Features

- Station Management: Add new stations and metro lines to create a dynamic map of the metro system.
- Pathfinding: Utilizes Dijkstra's algorithm to find the shortest path between two stations.
- Fare Calculation: Calculates fare based on distance traveled, with discounts available on Mondays.
- Travel Time Calculation: Displays the total travel time based on the selected path.
- Station Search: Search for stations by name or select them by number.
- File I/O: Write a welcome page to a file and read it back for display.
- User  Interaction: Provides a user-friendly interface for selecting stations and displaying results.

Algorithms Used

- Dijkstra's Algorithm: Employed to find the shortest path between two stations in the metro system.
- Fare Calculation Logic: Calculates fare based on distance traveled with specific fare brackets and discounts.

Data Structures Used

- `unordered_map`: Stores metro stations and their neighbors (connections) efficiently.
- `vector`: Used to store lists of stations, paths, and search matches.
- `priority_queue`: Utilized in Dijkstra's algorithm to efficiently retrieve the nearest unvisited station.
- `string`: Used for station names and user input.
- `pair`: Returns multiple values (fare and distance) from functions.

Usage

1. Adding Stations and Lines: The application initializes with a predefined set of metro stations and lines. Users can extend this by adding more stations and connections.
2. Finding Paths: Users can search for stations by name or select them by number. After selecting the start and end stations, the application calculates the shortest path and displays it.
3. Calculating Fare and Travel Time: After determining the path, the application calculates the fare based on the distance and displays the total travel time.
4. File Operations: The welcome page is written to a file and displayed to the user, providing a visually appealing introduction.

Screenshots
![image](https://github.com/user-attachments/assets/95810484-3c38-4294-9f57-5bd31d6a055c)


