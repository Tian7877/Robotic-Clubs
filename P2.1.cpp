#include <iostream>

void fungsiSatu() {
    // Teorema Nilai Antara
    std::cout << "Misalkan f suatu fungsi kontinu di selang tertutup [a, b]. "
              << "Jika u menyatakan suatu bilangan di antara f(a) dan f(b), "
              << "maka terdapat suatu bilangan c, dengan a < c < b, sedemikian sehingga f(c) = u." << std::endl;
}

void fungsiDua() {
    // Teorema Pythagorass
    std::cout << "Pada suatu segitiga siku-siku, kuadrat dari sisi terpanjang yaitu sama dengan "
              << "hasil jumlah dari kuadrat sisi-sisi penyikunya." << std::endl;

    std::cout << "*\n"
              << "*   *\n"
              << "*     *\n"
              << "*       *\n"
              << "* * * * * *\n ";
}
void fungsTiga() { 
        std::cout << " "
              << "Teorema Nilai Rata-rata mengatakan bahwa jika grafik sebuah fungsi kontinu mempunyai garis singgung tak vertikal pada setiap titik antara A dan B,"
              << "maka terdapat paling sedikit satu titik C pada grafik antara A dan B sehingga garis singgung di titik C sejajar talibusur AB." << std::endl;
}

int main() {
    char pilihan;

    while (true) {
        std::cout << "\nPilih opsi:" << std::endl;
        std::cout << "1. Teorema Nilai antara" << std::endl;
        std::cout << "2. Teorema Pythagoras" << std::endl;
        std::cout << "3. Teorema Rata rata Turunan" << std::endl;

        std::cout << "Masukkan angka pilihan: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case '1':
                fungsiSatu();
                break;
            case '2':
                fungsiDua();
                break;
            case '3':
                fungsTiga();
                return 0;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi." << std::endl;
        }
    }

    return 0;
}
