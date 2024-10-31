#include <iostream>   // Library untuk input-output
#include <cmath>      // Library untuk fungsi matematika

const double PI = 3.1416;   // Konstanta PI

// Fungsi untuk menghitung jarak antara dua titik
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Fungsi untuk menghitung jari-jari lingkaran
double radius(double x1, double y1, double x2, double y2) {
    return distance(x1, y1, x2, y2);
}

// Fungsi untuk menghitung keliling lingkaran
double circumference(double r) {
    return 2 * PI * r;
}

// Fungsi untuk menghitung luas lingkaran
double area(double r) {
    return PI * pow(r, 2);
}

int main() {
    double x1, y1, x2, y2;
    std::cout << "Masukkan koordinat pusat lingkaran (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Masukkan koordinat titik pada lingkaran (x2 y2): ";
    std::cin >> x2 >> y2;

    double r = radius(x1, y1, x2, y2);  // Menghitung jari-jari
    double d = 2 * r;                   // Menghitung diameter
    double c = circumference(r);        // Menghitung keliling
    double a = area(r);                 // Menghitung luas

    std::cout << "Jari-jari lingkaran: " << r << std::endl;
    std::cout << "Diameter lingkaran: " << d << std::endl;
    std::cout << "Keliling lingkaran: " << c << std::endl;
    std::cout << "Luas lingkaran: " << a << std::endl;

    return 0;
}