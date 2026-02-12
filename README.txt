Project Name: Matrix and Vector Computational Library
Instructor: Dr. Tabatabaei
Student Name: Mahak Tolouei
Student ID: 1404010121033

---------------------------------------------------------
1. PROJECT DESCRIPTION
---------------------------------------------------------
This project is a C++ application designed to perform mathematical operations on Matrices and Vectors. 
Originally based on the course requirements, I have implemented a fully interactive Console Application. 
The program takes input directly from the user (dimensions and values) and displays the results of 14 different mathematical operations in the terminal.

---------------------------------------------------------
2. FILE STRUCTURE
---------------------------------------------------------
The project consists of three main files:

a) matrix_library.h
   - Contains the definitions of 'Matris' and 'Vector' structures (structs).
   - Contains the declarations (prototypes) of all mathematical functions.

b) matrix_library.cpp
   - Contains the actual code and logic for all 14 operations (Implementation).
   - Includes logic for Determinant (Recursive), Inverse (Adjoint method), Cross Product, etc.

c) demonstration.cpp
   - The main entry point of the program.
   - Handles user input (getting matrix/vector sizes and data).
   - Calls the library functions and prints the results to the console.

---------------------------------------------------------
3. HOW TO COMPILE AND RUN
---------------------------------------------------------
You can compile and run this project using the GCC compiler (g++) in a terminal or Linux environment.

Step 1: Open your terminal in the project folder.

Step 2: Compile the code using the following command:
   g++ demonstration.cpp matrix_library.cpp -o run

Step 3: Run the executable:
   ./run

(If you are using Windows CMD, the output file will be run.exe, and you can run it by typing 'run').

---------------------------------------------------------
4. FEATURES AND OPERATIONS
---------------------------------------------------------
The program supports the following operations:

Matrix Operations:
1. Addition (A + B)
2. Subtraction (A - B)
3. Multiplication (A * B)
4. Scalar Multiplication (k * A)
5. Transpose (A^T)
6. Determinant (Recursive method for n*n matrices)
7. Inverse (A^-1)

Vector Operations:
1. Addition
2. Subtraction
3. Dot Product (Inner Product)
4. Cross Product (Only for 3D vectors)
5. Scalar Multiplication
6. Magnitude (Length)
7. Normalization (Unit Vector)

---------------------------------------------------------
5. ERROR HANDLING
---------------------------------------------------------
The program includes basic error checking to prevent crashes:
- Checks if matrix dimensions match for Addition/Subtraction.
- Checks if Columns of A == Rows of B for Matrix Multiplication.
- Checks if the matrix is Square for Determinant and Inverse.
- Checks if Determinant is zero before calculating Inverse (to avoid division by zero).
- Checks if vectors are 3-Dimensional for Cross Product.

If an error occurs, the program prints an error message (e.g., "Error: Dimensions do not match") and continues.