
#include <iostream>
#include "login.h"

using namespace std;

// ================================================================
//  MENU UTAMA MONETIX
// ================================================================

void menuUtama() {

    int pilihan;

    do {

        cout << "\n===== MENU UTAMA MONETIX =====" << endl;
        cout << "1. Profil dan Data Keuangan Mahasiswa" << endl;
        cout << "2. Simulasi Pembagian Uang Saku" << endl;
        cout << "3. Manajemen Biaya Akademik" << endl;
        cout << "4. Kalkulator Patungan Teman" << endl;
        cout << "5. Jadwal Kewajiban Pembayaran" << endl;
        cout << "6. Target Dana Darurat" << endl;
        cout << "7. Catatan Utang Piutang" << endl;
        cout << "8. Manajemen Penghasilan Tambahan" << endl;
        cout << "9. Evaluasi Alokasi Uang Saku" << endl;
        cout << "10. Keluar" << endl;

        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 9) {
            cout << "\nFitur belum diimplementasikan." << endl;
        }
        else if (pilihan == 10) {
            cout << "\nTerima kasih telah menggunakan MONETIX!" << endl;
        }
        else {
            cout << "\nPilihan tidak tersedia!" << endl;
        }

    } while (pilihan != 10);
}


// ================================================================
//  PROGRAM UTAMA
// ================================================================

int main() {

    int pilihan;

    do {

        cout << "\n===== APLIKASI MONETIX =====" << endl;
        cout << "1. Registrasi" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;

        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                registrasiAkun();
                break;

            case 2:

                if (loginAkun()) {
                    menuUtama();
                    return 0;
                }

                break;

            case 3:
                cout << "\nProgram MONETIX ditutup." << endl;
                break;

            default:
                cout << "\nPilihan tidak tersedia!" << endl;
        }

    } while (pilihan != 3);

    return 0;
}
