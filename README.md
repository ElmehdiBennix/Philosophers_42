# Dining Philosophers Problem Implementation

## Overview

This project implements the classic Dining Philosophers problem, a fundamental computer science problem that illustrates synchronization issues and techniques for resolving them in concurrent programming. The implementation includes both a threads-based solution using mutexes (mandatory part) and a processes-based solution using semaphores (bonus part).

### Problem Statement

- N philosophers sit at a round table with N forks
- Each philosopher needs two forks to eat spaghetti
- Philosophers alternate between three states: eating, thinking, or sleeping
- When a philosopher finishes eating, they put down both forks and begin sleeping
- After sleeping, they start thinking
- The simulation continues until either:
  - A philosopher dies of starvation
  - All philosophers have eaten a specified number of times

### Key Constraints

- Time to die: Maximum time a philosopher can go without starting a meal
- Time to eat: Duration required for eating (requires two forks)
- Time to sleep: Duration of sleeping state
- Optional: Number of times each philosopher must eat

## Requirements

- C compiler (gcc/clang)
- POSIX threads library
- POSIX semaphores (bonus part)
- make

## Usage

- Clone repo :

```bash
git clone https://github.com/ElmehdiBennix/Philosophers_42.git
cd Philosophers_42
```

### Compilation

- Mandatory part :

```bash
cd philo
make
```

- Bonus part :

```bash
cd philo_bonus
make
```

### Running the Program

```bash
# Format
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

# Example
./philo 5 800 200 200 5
```

### Parameters

1. number_of_philosophers: Number of philosophers and forks
2. time_to_die: Time (ms) a philosopher can survive without eating
3. time_to_eat: Time (ms) required to eat
4. time_to_sleep: Time (ms) spent sleeping
5. [Optional] number_of_times_each_philosopher_must_eat

## Technical Concepts

### Threads vs Processes

#### Threads (Mandatory Part)

- Lightweight units of execution within a process
- Share the same memory space
- Faster context switching
- Communicate through shared memory
- Synchronized using mutexes

#### Processes (Bonus Part)

- Independent execution units with separate memory spaces
- Heavier weight than threads
- Communicate through inter-process communication (IPC)
- Synchronized using semaphores

### Synchronization Tools

#### Mutexes

- Used in the mandatory part
- Binary semaphore for mutual exclusion
- Protects shared resources (forks)
- Owner concept: only the thread that locked can unlock
- Key functions:
  - pthread_mutex_init()
  - pthread_mutex_lock()
  - pthread_mutex_unlock()
  - pthread_mutex_destroy()

#### Semaphores

- Used in the bonus part
- Counter for resource management
- Can have multiple values
- No owner concept
- Key functions:
  - sem_open()
  - sem_wait()
  - sem_post()
  - sem_close()
  - sem_unlink()

## Implementation Details

### Mandatory Part (Threads)

- Each philosopher is a thread
- One mutex per fork
- Additional mutex for printing status
- Deadlock prevention through:
  - Resource hierarchy (fork numbering)
  - Timeout mechanism

### Bonus Part (Processes)

- Each philosopher is a process
- Central semaphore for forks
- Shared memory for state management
- Process synchronization through semaphores

## Common Challenges and Solutions

### 1. Race Conditions

- Protected by mutexes in mandatory part
- Semaphores handle synchronization in bonus part
- Careful management of shared resources

### 2. Deadlock Prevention

- Implemented through resource hierarchy
- Philosophers pick up forks in numerical order
- Timeout mechanism prevents indefinite waiting

### 3. Performance Considerations

- Minimal mutex locking duration
- Efficient state checking
- Balanced timing parameters

### 4. Death Detection

- Separate monitoring thread/process
- Accurate timestamp management
- Quick death notification (under 10ms)

## Debugging Tips

1. Use thread/process IDs in logs
2. Monitor resource allocation
3. Check for proper cleanup
4. Verify timing accuracy
5. Test edge cases:
   - Single philosopher
   - Even vs odd number of philosophers
   - Various timing combinations

## Error Handling

The implementation includes robust error handling for:

- Memory allocation failures
- Thread/process creation errors
- Mutex/semaphore initialization failures
- Invalid input parameters
