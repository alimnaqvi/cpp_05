# C++ Module 05: Repetition and Exceptions

[![C++ Programming](https://img.shields.io/badge/Language-C++-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Makefile](https://img.shields.io/badge/Build-Make-brightgreen.svg)](https://www.gnu.org/software/make/)

This project is part of the curriculum at 42 School and focuses on advanced C++ concepts, including exception handling, abstract classes, inheritance, and polymorphism. Through a series of exercises, we implement a hierarchy of forms that can be signed and executed by bureaucrats, with specific actions tied to each form.

## Core Concepts Covered

### Exception Handling
- Using `try`-`catch` blocks to handle runtime errors.
- Creating custom exception classes derived from `std::exception`.
- Throwing exceptions in constructors to abort object creation.

### Abstract Classes and Polymorphism
- Implementing abstract classes with pure virtual functions.
- Using inheritance to define specialized behaviors in derived classes.
- Understanding and applying the **Orthodox Canonical Form (OCF)** for proper resource management.

### File I/O and Randomization
- Writing ASCII art to files using `std::ofstream`.
- Generating random outcomes using the Mersenne Twister PRNG.

### DRY Principle and Code Reusability
- Designing reusable components for form creation and execution.
- Implementing factory methods to dynamically create forms.

## Learning Resources
- [**Chapter 27 - Exceptions LearnCpp.com**](https://www.learncpp.com/cpp-tutorial/the-need-for-exceptions/) (go through the whole chapter)
- [Introduction to random number generation](https://www.learncpp.com/cpp-tutorial/introduction-to-random-number-generation/)
- [Generating random numbers using Mersenne Twister](https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/)
- [Pure virtual functions, abstract base classes, and interface classes](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/)

## Exercises Overview

### Exercise 00: Bureaucrat Class
- **Task:** Implement a `Bureaucrat` class with a grade system (1 being the highest and 150 the lowest).
- **Implementation:**
  - Added exception classes for grade validation (`GradeTooHighException`, `GradeTooLowException`).
  - Implemented methods to increment and decrement grades, ensuring they remain within valid bounds.
  - Overloaded the insertion operator (`<<`) for easy printing of bureaucrat details.

### Exercise 01: Basic Form Class
- **Task:** Create a `Form` class that can be signed by bureaucrats.
- **Implementation:**
  - Added validation for form grades during construction.
  - Implemented a `beSigned()` method to change the form's signed status, ensuring the bureaucrat's grade is sufficient.
  - Introduced exception classes for invalid grades and already signed forms.

### Exercise 02: Specialized Forms
- **Task:** Extend the `Form` class into three specialized forms:
  - `ShrubberyCreationForm`: Creates ASCII art of trees in a file.
  - `RobotomyRequestForm`: Simulates a robotomy with a 50% success rate.
  - `PresidentialPardonForm`: Prints a pardon message to the console.
- **Implementation:**
  - Defined abstract base class `AForm` with pure virtual methods.
  - Implemented derived classes with specific behaviors tied to `execute()`.

### Exercise 03: Intern Class
- **Task:** Implement an `Intern` class that can create forms dynamically based on a string identifier.
- **Implementation:**
  - Used a factory method to map form names to their corresponding constructors.
  - Added exception handling for unknown form names.

## Project Structure

Each exercise builds upon the previous one, culminating in a complete system for bureaucratic form handling.

### Directory Structure
- `ex00/`: Bureaucrat class implementation.
- `ex01/`: Basic Form class with signing functionality.
- `ex02/`: Specialized forms with execution behaviors.
- `ex03/`: Intern class for dynamic form creation.

### Common Files
- `Makefile`: To compile the exercises.
- `main.cpp`: Test programs for each exercise.
- Header and implementation files for classes (`Bureaucrat`, `Form`, `AForm`, etc.).

## How to Compile and Run

Each exercise can be compiled and run independently using the provided `Makefile`.

1. Navigate to the specific exercise directory (e.g., `ex00`, `ex01`, etc.).
    ```bash
    cd exXX
    ```
2. Use `make` to compile the project.
    ```bash
    make
    ```
3. This will create an executable file named after the exercise (e.g., `ex00`, `ex01`).
4. Run the executable:
    ```bash
    ./exXX
    ```

### Other Make Commands
- `make clean`: Removes object files (`*.o`).
- `make fclean`: Removes object files and the executable.
- `make re`: Performs `fclean` followed by `make`.

**Example (Compiling and running Exercise 02):**
```bash
cd ex02
make
./ex02
```

## Conclusion

<p>
  This module reinforces key C++ concepts such as exception handling, abstract classes, and polymorphism. By implementing a system of forms and bureaucrats, we gain practical experience in designing reusable and extensible object-oriented code.
  <img src="https://page-views-counter-534232554413.europe-west1.run.app/view?src=github.com&src_uri=/alimnaqvi/cpp_05" style="display: none;" />
</p>
