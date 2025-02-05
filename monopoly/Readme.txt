Project Title
Monopoly Board Simulation Using Circular Linked List

Overview
This project implements a simplified version of a Monopoly board using a circular linked list in C++. The core operations performed include:

Insertion: Add properties at different positions (head, tail, or specific index).
Deletion: Remove properties from different positions.
Search: Find specific properties in the list.
Sort: Sort the list based on property names.
Other Operations: Reverse the list, access the head and tail nodes, check if the list is empty, and count the number of nodes.
The program is written in C++ and can be executed using CLion IDE or any other C++ IDE supporting C++20 standard.

How to Run the Code
Prerequisites
C++ Compiler: Ensure you have a compiler that supports C++20.
IDE: This project was tested on CLion, but any IDE with support for CMake can be used.
CMake: Required for compiling the project if you're using an IDE like CLion.
Instructions
Clone or download the project into your desired folder.
Open the project in CLion or your preferred IDE.
Ensure your CMake configuration is set up correctly.
Build the project.
Run the project using the IDE's run feature.
Operations
Insertion

Description: Adds a new property to the list. Properties can be inserted at the beginning, the end, or at a specific position in the list.
Time Complexity:
Best case: O(1) (for insertion at the head or tail).
Worst case: O(n) (for insertion at a specific position).
Deletion

Description: Removes a property from the list. Properties can be removed from the head, tail, or a specific position.
Time Complexity:
Best case: O(1) (for deletion at the head or tail).
Worst case: O(n) (for deletion at a specific position).
Search

Description: Searches the list for a property by name. Returns the details of the matching property.
Time Complexity:
Best case: O(1) (if the property is at the head).
Worst case: O(n) (if the property is near the end).
Sort

Description: Sorts the list based on property names in lexicographical order.
Time Complexity:
Best case: O(n) (if the list is already sorted).
Worst case: O(n^2) (if the list is unsorted).
Reverse

Description: Reverses the order of properties in the circular linked list.
Time Complexity:
Best case: O(n).
Worst case: O(n).
Access Head Node

Description: Retrieves the details of the property at the head of the list.
Time Complexity:
Best case: O(1).
Worst case: O(1).
Access Last Node

Description: Retrieves the details of the property at the last node of the list.
Time Complexity:
Best case: O(n).
Worst case: O(n).
Check if List is Empty

Description: Checks if the list contains any nodes.
Time Complexity:
Best case: O(1).
Worst case: O(1).
Count Nodes

Description: Counts the total number of nodes in the circular linked list.
Time Complexity:
Best case: O(n).
Worst case: O(n