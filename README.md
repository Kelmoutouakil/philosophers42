## Philosopher42
---
Philosopher42 is a classic concurrency problem inspired by the Dining Philosophers problem. 
The goal of this project is to simulate a system where multiple philosophers (threads) are eating and thinking, while ensuring that there are no deadlocks or race conditions.

This project is designed as part of the 42 School curriculum to help you learn about thread synchronization, mutexes, semaphores, and general concurrency concepts.
Optional Parameters:
Number of philosophers: Must be greater than 1.
Time parameters: Values are in milliseconds.
Optional maximum number of meals: If provided, each philosopher will eat this number of times before the simulation ends.
## Controls and Behavior:
---
Philosophers think, eat, and sleep, trying to avoid deadlock.
A philosopher needs two forks (mutexes) to eat, and these are shared between philosophers.
If a philosopher can't get both forks, they will stop and think until they can eat again.
---
## Features
---
Multi-threading: Simulates philosophers as threads, each interacting with shared resources (forks).
Mutexes: Prevents race conditions and ensures that forks are properly locked and released.
Semaphore Control: Ensures proper synchronization of philosophers' actions and handles timing constraints.
Deadlock Prevention: The algorithm ensures that deadlock doesn't occur, so all philosophers can eventually eat.
## Technologies
---
C: Core programming language.
Pthreads: Library for thread management.
Mutexes and Semaphores: For thread synchronization and resource management.
---
License
This project is licensed under the MIT License.

