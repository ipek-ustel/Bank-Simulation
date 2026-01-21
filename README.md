# Bank-Simulation

This project is a high-fidelity Discrete Event Simulation (DES) that models the daily operations of a banking system, developed for the CENG 213 Data Structures course at METU.

## Core Features

**Event-Driven Logic:** Models system state changes at specific points in time, such as customer arrivals and service completions.

**Load Balancing:** Implements a Multiple Queue structure where arriving customers automatically join the shortest available line to optimize flow.

**Priority-Based Service:** Utilizes a Sorted Doubly Linked List to ensure customers are served based on their priority levels.

**Entities:** Simulates interactions between Customers, Security Officers, and Bankers, each with unique IDs and processing times.

## Technical Implementation

Instead of using standard libraries (STL), I implemented all underlying data structures from scratch to master Manual Memory Management and Template Programming:

  **Singly Linked List (SLL):** Used as the base for standard FIFO queues.

  **Sorted Doubly Linked List (SDLL):** Developed with dummy head and tail nodes to manage priority-ordered events and services efficiently.

  **Deep Copy Semantics:** All structures implement custom copy constructors and assignment operators to ensure memory safety.

  **Exception Handling:** Custom exception classes for robust error management (e.g., EmptyCollectionException, IndexOutOfRangeException).

## Complexity Analysis

**Insertion/Removal:** Optimized for $O(n)$ in sorted structures.

**Memory Efficiency:** Achieved $O(1)$ space complexity for pointer-based operations during list traversal and reversal.
