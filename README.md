# 🧮 Matrix & Vector C++ Library

![Language](https://img.shields.io/badge/language-C%2B%2B-00599C?style=flat-square&logo=c%2B%2B)
![Standard](https://img.shields.io/badge/std-C%2B%2B11-blue?style=flat-square)
![Project Type](https://img.shields.io/badge/Type-University%20Project-orange?style=flat-square)

A comprehensive C++ library for performing linear algebra operations. This project was developed as a university term project to demonstrate the implementation of complex mathematical algorithms (such as recursive determinants and matrix inversion) using standard C++ without external libraries.

## 📂 Repository Structure
```text
📦 Matrix-Vector-Project
 ┣ 📜 matrix_library.h      # Header file (Structs & Prototypes)
 ┣ 📜 matrix_library.cpp    # Core logic implementation
 ┣ 📜 demonstration.cpp     # Console UI for testing & demo
 ┗ 📜 README.md             # Documentation

## ✨ Features

### 1️⃣ Matrix Operations (`Matris`)
| Operation | Description | Algorithm / Note |
| :--- | :--- | :--- |
| Addition / Subtraction | $A \pm B$ | Element-wise operation |
| Multiplication | $A \times B$ | Standard row-by-column multiplication |
| Scalar Product | $k \cdot A$ | Multiplies every element by $k$ |
| Transpose | $A^T$ | Swaps rows and columns |
| Determinant | $\det(A)$ | Recursive Laplace Expansion method |
| Inverse | $A^{-1}$ | Adjoint Matrix method: $A^{-1} = \frac{1}{|A|} \text{adj}(A)$ |

### 2️⃣ Vector Operations (`Vector`)
| Operation | Description | Note |
| :--- | :--- | :--- |
| Dot Product | $\vec{u} \cdot \vec{v}$ | Inner product (scalar result) |
| Cross Product | $\vec{u} \times \vec{v}$ | Strictly for 3D vectors |
| Magnitude | $\|\vec{v}\|$ | Euclidean length calculation |
| Normalization | $\hat{v}$ | Unit vector calculation |

## 🧠 Mathematical Implementation

### Recursive Determinant
The determinant function uses recursion to break down an $n \times n$ matrix into minors. It calculates the determinant using the first row expansion:

$$ \det(A) = \sum_{j=1}^{n} (-1)^{1+j} a_{1j} M_{1j} $$

### Matrix Inversion
The inverse is calculated without Gaussian elimination. Instead, it computes the Cofactor Matrix, transposes it to get the Adjoint Matrix, and divides by the determinant.

## 🚀 How to Compile and Run

You can compile this project using any standard C++ compiler (like `g++`).

1. Compile:
bash
g++ demonstration.cpp matrix_library.cpp -o matrix_app

2. Run:
*   Windows:

```bash
    matrix_app.exe
Linux / macOS:
    ./matrix_app

Name: mahak tolouei
University: University of Guilan
Department: Computer Science


Created as a final term project for “Computer Basics and Programming”.
