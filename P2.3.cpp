#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>


double x = 0.0;
double y = 0.0;

void lokasi() {
    std::cout << "Lokasi drone: (" << std::fixed << std::setprecision(2) << x << ", " << y << ")" << std::endl;
}

void gerak_2(double v, double t, double theta) {
    double delta_x = v * t * cos(theta * M_PI / 180.0);
    double delta_y = v * t * sin(theta * M_PI / 180.0);

   
    x += delta_x;
    y += delta_y;

    std::cout << "Koordinat drone sekarang: (" << std::fixed << std::setprecision(2) << x << ", " << y << ")" << std::endl;
}


void parseInput(std::string input) {
    double v, t, theta;
    char dummy;
    std::stringstream ss(input);
    ss >> dummy >> v >> dummy >> t >> dummy >> theta >> dummy;
    gerak_2(v, t, theta);
}

int main() {
    char lanjut;

    do {
        std::string input;

        
        std::cout << "Gerak Drone : ";
        std::getline(std::cin, input);

        
        parseInput(input);

        
        std::cout << "Apakah Anda ingin mengubah gerak drone lagi? (y/n): ";
        std::cin >> lanjut;
        std::cin.ignore(); // Membersihkan newline karakter dari buffer
    } while (lanjut == 'y' || lanjut == 'Y');

    return 0;
}
