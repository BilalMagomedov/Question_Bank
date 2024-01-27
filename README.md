## Question Bank Project

### Overview

This C++ program is designed to manage a question bank stored in a specific format in a text file. The program allows the user to shuffle the questions, options, or both, and provides an option to save the shuffled information to a new file.

### Input File Format

The input file should follow this format:

```
Q1: Each class you create becomes a new ________ that can be used to declare variables and create objects.
a.    package
b.    instance
c.    library
d.    type.
ANS: d.

Q2: You can declare new classes as needed; this is one reason Java is known as a(n) ________ language.
a.    portable
b.    incremental
c.    extensible
d.    virtual
ANS: c.

Q3: Which of the following statements is false?
a.    Each class declaration that begins with the access modifier private must be stored in a file that has the same name as the class and ends with the .java filename extension.
b.    Every class declaration contains keyword class followed immediately by the class's name.
c.    Class, method, and variable names are identifiers.
d.    An object has attributes that are implemented as instance variables and carried with it throughout its lifetime.
ANS: a.
```

### Shuffle Menu

1. **Shuffle Questions Only (1):**
   - Shuffles the order of the questions.

2. **Shuffle Options Only (2):**
   - Shuffles the options within each question.

3. **Shuffle Both (3):**
   - Shuffles both the order of the questions and options within each question.

4. **Do Not Shuffle (4):**
   - Displays the questions and options in their original order.

### Program Execution

1. The program reads the questions from the specified input file ("questions.txt").
2. The user is prompted to choose a shuffling option from the menu.
3. The program shuffles questions and/or options based on the user's choice.
4. Shuffled questions are displayed, and the user is asked if they want to save the shuffled information to a new file.
5. If the user chooses to save, the program creates a new file ("SavedQuestions.txt") and writes the shuffled information to it.

### How to Run

Compile and run the C++ program, and follow the on-screen instructions to choose shuffling options and save the shuffled questions if desired.

### Code Explanation

- The program uses structures to represent questions and various functions to handle shuffling, formatting, and file operations.
- The Windows API is used to set console text attributes for colorful output.

### Additional Notes

- Ensure that the input file ("questions.txt") is present in the same directory as the executable.
- The program provides visual cues with console colors for a better user experience.

### Author

Bilal Magomedov (200201107)

### Project Date

January 27, 2024
