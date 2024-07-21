# Save the King Game

## Project Description
This project is an enhanced implementation of the "Save the King" game, previously developed in Exercise 2. The main differences this time are the use of inheritance and polymorphism, as well as the SFML graphics library. The game is now designed with better object-oriented principles and includes additional features compared to the previous version.

## Features and Enhancements
- **Real-Time Game:** The game now operates in real-time, driven by a clock rather than turns.
- **Collision Detection:** Improved collision detection between characters and tiles, using overlapping rectangles.
- **Dwarves:** Added randomly wandering dwarf characters that block player movement.
- **Time Limit:** Some levels now have a time limit, which can be predefined or random.
- **Gifts:** New items in the game that affect gameplay, such as increasing/decreasing the time limit or removing all dwarves from the level.

## Game Mechanics
- **Real-Time Movement:** Characters move in real-time based on clock ticks rather than turns.
- **Collisions:** Defined by overlapping bounding rectangles of characters and tiles.
- **Gifts:** Types of gifts include time extensions, time reductions, and dwarf removal.
- **Levels:** At least three levels, with an easy way to add new levels without modifying the code.

## Menu and Display
- **Menu:** Basic menu for starting a new game, viewing help, or exiting.
- **Information Display:** Shows level number, elapsed time, and remaining time if there is a time limit.

## Movement and Controls
- **Movement:** Characters move in straight lines along the axes.
- **Controls:** Arrow keys for movement, using SFML events for key presses.

## Design and Implementation
- **Object-Oriented Design:** Proper use of inheritance and polymorphism.
- **Graphics:** Use of SFML for graphics, including transparent PNG images for characters.
- **Sound:** Added sound effects using SFML.


## Usage
- Use the arrow keys to move the characters.
- Collect gifts by walking over them.
- Avoid or navigate around dwarves.
- Complete the level within the time limit if applicable.

## Technologies Used
- **C++:** Core programming language.
- **SFML:** Graphics and sound library.
- **Object-Oriented Programming:** Inheritance, polymorphism.

## Contributors
- Lubaba Nairoukh
