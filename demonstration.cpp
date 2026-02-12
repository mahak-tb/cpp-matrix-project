#include <iostream>
#include "matrix_library.h"

using namespace std;

int main() {
    cout << "========================================\n";
    cout << "   PROJECT PAYAN TERM - Console Mode    \n";
    cout << "========================================\n";

    
    // 1. عملیات ماتریسی
    
    cout << "\n>>> PART 1: MATRIX OPERATIONS <<<\n";
    
    // گرفتن ورودی‌ها
    Matris A = begir_matris_az_karbar("A");
    Matris B = begir_matris_az_karbar("B");

    cout << "\n========================================\n";
    cout << "   NATAYEJ AMALIAT MATRIS (RESULTS)     \n";
    cout << "========================================\n";


    chap_matris(jam_matris(A, B), "Jam (A + B)");
    chap_matris(tafrigh_matris(A, B), "Tafrigh (A - B)");
    chap_matris(zarb_matris(A, B), "Zarb (A * B)");
    
    // --- ضرب عدد در ماتریس ---
    double k;
    cout << "\n>>> Adad baraye zarb scalar vared konid (k): ";
    cin >> k;
    chap_matris(zarb_skalar_matris(A, k), "Zarb Scalar A (k * A)");
    chap_matris(zarb_skalar_matris(B, k), "Zarb Scalar B (k * B)");

    // --- ترانهاده  ---
    chap_matris(transpose_matris(A), "Transpose A");
    chap_matris(transpose_matris(B), "Transpose B");

    // --- دترمینان و معکوس برای A ---
    if (A.satr == A.soton) {
        chap_adad(determinant_matris(A), "Determinant A");
        chap_matris(makoos_matris(A), "Makoos (Inverse) A");
    } else {
        cout << "\nDeterminant/Inverse A: Error (A Morabaei nist)\n";
        cout << "--------------------------------\n";
    }

    // --- دترمینان و معکوس برای B  ---
    if (B.satr == B.soton) {
        chap_adad(determinant_matris(B), "Determinant B");
        chap_matris(makoos_matris(B), "Makoos (Inverse) B");
    } else {
        cout << "\nDeterminant/Inverse B: Error (B Morabaei nist)\n";
        cout << "--------------------------------\n";
    }

    
    // 2. عملیات برداری
    
    cout << "\n\n>>> PART 2: VECTOR OPERATIONS <<<\n";

    // گرفتن ورودی‌ها
    Vector V1 = begir_vector_az_karbar("V1");
    Vector V2 = begir_vector_az_karbar("V2");

    cout << "\n========================================\n";
    cout << "   NATAYEJ AMALIAT VECTOR (RESULTS)     \n";
    cout << "========================================\n";

    
    chap_vector(jam_vector(V1, V2), "Jam (V1 + V2)");
    chap_vector(tafrigh_vector(V1, V2), "Tafrigh (V1 - V2)");
    
    // --- ضرب عدد در بردار ---
    double kv;
    cout << "\n>>> Adad baraye zarb scalar Vector vared konid: ";
    cin >> kv;
    chap_vector(zarb_skalar_vector(V1, kv), "Zarb Scalar V1");
    chap_vector(zarb_skalar_vector(V2,kv),"zarb scalar V2");

    // --- ضرب داخلی و خارجی ---
    chap_adad(zarb_dakheli(V1, V2), "Zarb Dakheli (Dot Product)");

    if (V1.size == 3 && V2.size == 3) {
        chap_vector(zarb_khareji(V1, V2), "Zarb Khareji (Cross Product)");
    } else {
        cout << "\nZarb Khareji: Error (Faghat baraye vector haye 3D)\n";
        cout << "--------------------------------\n";
    }

    // --- اندازه و نرمال‌سازی ---
    chap_adad(andaze_vector(V1), "Andaze (Magnitude) V1");
    chap_vector(normalize_vector(V1), "Normalize V1");
    

    chap_adad(andaze_vector(V2), "Andaze (Magnitude) V2");
    chap_vector(normalize_vector(V2), "Normalize V2");

    cout << "\n========================================\n";
    cout << "   Payan Barname. Enter bezanid...      \n";
    cout << "========================================\n";
    
    cin.ignore(); 
    cin.get(); 

    return 0;
}