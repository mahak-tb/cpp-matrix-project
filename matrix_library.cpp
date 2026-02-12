#include "matrix_library.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> // برای مرتب‌سازی خروجی

using namespace std;


Matris begir_matris_az_karbar(string name) {
    Matris m;
    cout << "\n--- Voroode Matris " << name << " ---\n";
    cout << "Tedad Satr: "; cin >> m.satr;
    cout << "Tedad Soton: "; cin >> m.soton;
    
    m.dadeh.resize(m.satr, vector<double>(m.soton));
    
    cout << "Maghadir ra vared konid:\n";
    for(int i=0; i<m.satr; i++) {
        for(int j=0; j<m.soton; j++) {
            cout << name << "[" << i << "][" << j << "]: ";
            cin >> m.dadeh[i][j];
        }
    }
    return m;
}

Vector begir_vector_az_karbar(string name) {
    Vector v;
    cout << "\n--- Voroode Vector " << name << " ---\n";
    cout << "Size Vector (masalan 3): "; cin >> v.size;
    
    v.anaser.resize(v.size);
    for(int i=0; i<v.size; i++) {
        cout << name << "[" << i << "]: ";
        cin >> v.anaser[i];
    }
    return v;
}

void chap_matris(Matris m, string title) {
    cout << "\nResult: " << title << " (" << m.satr << "x" << m.soton << "):\n";
    if (m.satr == 0) {
        cout << "Error / Empty Matrix\n";
        return;
    }
    for(int i=0; i<m.satr; i++) {
        for(int j=0; j<m.soton; j++) {
            cout << setw(10) << setprecision(4) << m.dadeh[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------------------------\n";
}

void chap_vector(Vector v, string title) {
    cout << "\nResult: " << title << " (Size: " << v.size << "):\n[ ";
    if (v.size == 0) {
        cout << "Error / Empty Vector ]\n";
        return;
    }
    for(int i=0; i<v.size; i++) {
        cout << v.anaser[i] << (i < v.size-1 ? ", " : "");
    }
    cout << " ]\n--------------------------------\n";
}

void chap_adad(double d, string title) {
    cout << "\nResult: " << title << ": " << d << "\n";
    cout << "--------------------------------\n";
}

// --- پیاده‌سازی عملیات ماتریسی ---

Matris jam_matris(Matris a, Matris b) {
    if (a.satr != b.satr || a.soton != b.soton) {
        cout << "Error: Abad barabar nistand baraye Jam!\n";
        return { {}, 0, 0 };
    }
    Matris result = a; 
    for(int i=0; i<a.satr; i++)
        for(int j=0; j<a.soton; j++)
            result.dadeh[i][j] += b.dadeh[i][j];
    return result;
}

Matris tafrigh_matris(Matris a, Matris b) {
    if (a.satr != b.satr || a.soton != b.soton) {
        cout << "Error: Abad barabar nistand baraye Tafrigh!\n";
        return { {}, 0, 0 };
    }
    Matris result = a;
    for(int i=0; i<a.satr; i++)
        for(int j=0; j<a.soton; j++)
            result.dadeh[i][j] -= b.dadeh[i][j];
    return result;
}

Matris zarb_skalar_matris(Matris a, double k) {
    Matris result = a;
    for(int i=0; i<a.satr; i++)
        for(int j=0; j<a.soton; j++)
            result.dadeh[i][j] *= k;
    return result;
}

Matris zarb_matris(Matris a, Matris b) {
    if (a.soton != b.satr) {
        cout << "Error: Soton A ba Satr B barabar nist!\n";
        return { {}, 0, 0 };
    }
    Matris result;
    result.satr = a.satr;
    result.soton = b.soton;
    result.dadeh.assign(result.satr, vector<double>(result.soton, 0.0));

    for(int i=0; i<a.satr; i++)
        for(int j=0; j<b.soton; j++)
            for(int k=0; k<a.soton; k++)
                result.dadeh[i][j] += a.dadeh[i][k] * b.dadeh[k][j];
    return result;
}

Matris transpose_matris(Matris a) {
    Matris result;
    result.satr = a.soton;
    result.soton = a.satr;
    result.dadeh.assign(result.satr, vector<double>(result.soton));
    
    for(int i=0; i<a.satr; i++)
        for(int j=0; j<a.soton; j++)
            result.dadeh[j][i] = a.dadeh[i][j];
    return result;
}

// تابع بازگشتی برای دترمینان
double determinant_matris(Matris a) {
    if (a.satr != a.soton) {
        cout << "Error: Matris morabaei nist!\n";
        return 0;
    }
    int n = a.satr;
    if (n == 1) return a.dadeh[0][0];
    if (n == 2) return (a.dadeh[0][0]*a.dadeh[1][1]) - (a.dadeh[0][1]*a.dadeh[1][0]);
    double det = 0;
    for (int x = 0; x < n; x++) {
        Matris sub;
        sub.satr = n - 1;
        sub.soton = n - 1;
        sub.dadeh.assign(n - 1, vector<double>(n - 1));
        
        for (int i = 1; i < n; i++) {
            int sub_j = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                sub.dadeh[i - 1][sub_j] = a.dadeh[i][j];
                sub_j++;
            }
        }
        det += (x % 2 == 0 ? 1 : -1) * a.dadeh[0][x] * determinant_matris(sub);
    }
    return det;
}

Matris makoos_matris(Matris a) {
    double det = determinant_matris(a);
    if (det == 0) {
        cout << "Error: Determinant 0 ast, makoos nadarad.\n";
        return { {}, 0, 0 };
    }
    
    int n = a.satr;
    Matris adj; // ماتریس الحاقی
    adj.satr = n;
    adj.soton = n;
    adj.dadeh.assign(n, vector<double>(n));

    if (n == 1) {
        adj.dadeh[0][0] = 1.0 / a.dadeh[0][0];
        return adj;
    }

    // ساخت ماتریس هم‌سازه (Cofactor)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Matris sub;
            sub.satr = n - 1;
            sub.soton = n - 1;
            sub.dadeh.assign(n - 1, vector<double>(n - 1));
            
            int sub_i = 0;
            for (int r = 0; r < n; r++) {
                if (r == i) continue;
                int sub_j = 0;
                for (int c = 0; c < n; c++) {
                    if (c == j) continue;
                    sub.dadeh[sub_i][sub_j] = a.dadeh[r][c];
                    sub_j++;
                }
                sub_i++;
            }
            double sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;
            adj.dadeh[j][i] = sign * determinant_matris(sub); // Transpose همزمان
        }
    }

    // تقسیم بر دترمینان
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            adj.dadeh[i][j] /= det;
            
    return adj;
}

// --- پیاده‌سازی عملیات برداری ---

Vector jam_vector(Vector v1, Vector v2) {
    if (v1.size != v2.size) { cout << "Error Size Vector!\n"; return { {}, 0 }; }
    Vector res = v1;
    for(int i=0; i<v1.size; i++) res.anaser[i] += v2.anaser[i];
    return res;
}

Vector tafrigh_vector(Vector v1, Vector v2) {
    if (v1.size != v2.size) { cout << "Error Size Vector!\n"; return { {}, 0 }; }
    Vector res = v1;
    for(int i=0; i<v1.size; i++) res.anaser[i] -= v2.anaser[i];
    return res;
}

Vector zarb_skalar_vector(Vector v, double k) {
    Vector res = v;
    for(int i=0; i<v.size; i++) res.anaser[i] *= k;
    return res;
}

double zarb_dakheli(Vector v1, Vector v2) {
    if (v1.size != v2.size) { cout << "Error Size Vector!\n"; return 0; }
    double sum = 0;
    for(int i=0; i<v1.size; i++) sum += v1.anaser[i] * v2.anaser[i];
    return sum;
}

Vector zarb_khareji(Vector v1, Vector v2) {
    if (v1.size != 3 || v2.size != 3) {
        cout << "Error: Zarb khareji faghat baraye vector 3D ast!\n";
        return { {}, 0 };
    }
    Vector res; res.size = 3; res.anaser.resize(3);
    res.anaser[0] = v1.anaser[1]*v2.anaser[2] - v1.anaser[2]*v2.anaser[1];
    res.anaser[1] = v1.anaser[2]*v2.anaser[0] - v1.anaser[0]*v2.anaser[2];
    res.anaser[2] = v1.anaser[0]*v2.anaser[1] - v1.anaser[1]*v2.anaser[0];
    return res;
}

double andaze_vector(Vector v) {
    double sum = 0;
    for(double val : v.anaser) sum += val * val;
    return sqrt(sum);
}

Vector normalize_vector(Vector v) {
    double len = andaze_vector(v);
    if (len == 0) return v;
    return zarb_skalar_vector(v, 1.0/len);
}