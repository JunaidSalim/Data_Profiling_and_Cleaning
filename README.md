# Student Data Profiling and Cleansing in C++

This project is a C++ implementation for processing and profiling student data from Lahore and Peshawar campuses. It handles data stored in text files, cleanses anomalies, and provides useful statistics like the number of students, courses, and invalid values.

This project was completed as our **Object-Oriented Programming (OOP)** course project.


## Project Overview

The project reads data from various text files related to students' details and course registrations for different batches. It performs data profiling, detects anomalies, and handles data cleansing tasks like normalizing names, checking date validity, and ensuring consistent gender representation.

## Features

- **Data Profiling**: 
  - Calculates the number of unique values, nulls, and invalid entries for each column.
  - Computes statistics such as total students, male vs female students, and total courses.
  - Checks the relationship between unique student IDs and total students.
  - Provides an average number of students per semester and per batch.
  
- **Data Cleansing**:
  - Standardizes names for students and fathers.
  - Extracts and standardizes city names from addresses.
  - Adds missing gender information based on name lookup.
  - Ensures date validation for DOB and registration dates.
  - Normalizes gender representation to 'M' and 'F'.

- **Anomalies Detection**:
  - Invalid marks (outside the range of 0 to 100).
  - Invalid dates (e.g., 31st Feb, DOB greater than registration date).
  - Missing degree information is addressed.

- **Output Files**:
  - After processing, the program generates two output files:
    - `Output_Student_Data.txt`: Contains the cleaned and processed student data.
    - `Output_Course_Data.txt`: Contains the cleaned and processed course data.

## Setup Instructions

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/JunaidSalim/Data_Profiling_and_Cleaning.git
   ```
   ```bash
   cd Data_Profiling_and_Cleaning
   ```

2. **Compile the Code**:
   Ensure you have a C++ compiler installed. You can use g++:
   ```bash
   g++ -o main main.cpp
   ```

3. **Run the Program**:
   The program reads data from text files stored in a `Data/` directory:
   ```bash
   ./main
   ```

## Data Files

The program uses text files containing student and course data for each batch. These files should be placed in a `Data/` folder, and the filenames follow the structure:
- `Lhr_Student_<year>.txt` for student records.
- `Lhr_Detail_<year>.txt` for course records.
- `Pesh_Student_<year>.txt` and `Pesh_Detail_<year>.txt` for Peshawar campus data.

## Example Output

The program provides detailed output regarding:
- Number of nulls, unique values, and invalid entries in both campuses.
- Ratio of male to female students.
- Total students taking more than 5 courses.
- Summary statistics per semester and batch.


## Contributors
- [Junaid Saleem](https://github.com/JunaidSalim)
- [Muhammad Taimoor](https://github.com/muhammadtaimoor9583)
- [Hamza Faraz](https://github.com/Hamzafaraz1821)