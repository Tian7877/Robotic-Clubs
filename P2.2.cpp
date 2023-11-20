#include <iostream>
#include <iomanip>
#include <sstream> 


double x = 0.0;
double y = 0.0;

void lokasi() {
    std::cout << "Lokasi drone: (" << std::fixed << std::setprecision(2) << x << ", " << y << ")" << std::endl;
}


void gerak(double delta_x, double delta_y) {
    x += delta_x;
    y += delta_y;
    std::cout << "Drone digerakkan. ";
    lokasi();
}


void bacaPerubahanKoordinat(std::string input, double& delta_x, double& delta_y) {
    char dummy;
    std::stringstream ss(input);
    ss >> dummy >> delta_x >> dummy >> delta_y >> dummy;
}

int main() {
    char lanjut;

    do {
        // Meminta input pergerakan dari pengguna dalam format "(x, y)"
        std::string inputKoordinat;
        std::cout << "Masukkan perubahan koordinat : ";
        std::cin >> inputKoordinat;

        double delta_x, delta_y;
        bacaPerubahanKoordinat(inputKoordinat, delta_x, delta_y);

        // Menggerakkan drone
        gerak(delta_x, delta_y);

        // Meminta pengguna apakah ingin melanjutkan
        std::cout << "Apakah Anda ingin melanjutkan? (y/n): ";
        std::cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');

    return 0;
}
