#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

#include <vector>
#include <iostream>

using namespace std;

// ساختار ماتریس
struct Matris {
    vector<vector<double>> dadeh;
    int satr;
    int soton;
};

// ساختار بردار
struct Vector {
    vector<double> anaser;
    int size;
};

// --- توابع کمکی ورودی/خروجی  ---
Matris begir_matris_az_karbar(string name);
Vector begir_vector_az_karbar(string name);
void chap_matris(Matris m, string title);
void chap_vector(Vector v, string title);
void chap_adad(double d, string title);

// --- عملیات ماتریسی ---
Matris jam_matris(Matris a, Matris b);
Matris tafrigh_matris(Matris a, Matris b);
Matris zarb_skalar_matris(Matris a, double k);
Matris zarb_matris(Matris a, Matris b);
Matris transpose_matris(Matris a);
double determinant_matris(Matris a);
Matris makoos_matris(Matris a);

// --- عملیات برداری ---
Vector jam_vector(Vector v1, Vector v2);
Vector tafrigh_vector(Vector v1, Vector v2);
Vector zarb_skalar_vector(Vector v, double k);
double zarb_dakheli(Vector v1, Vector v2);
Vector zarb_khareji(Vector v1, Vector v2);
double andaze_vector(Vector v);
Vector normalize_vector(Vector v);

#endif