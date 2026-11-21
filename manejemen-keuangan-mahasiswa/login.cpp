
#include "login.h"
#include "data.h"

#include <iostream>
#include <fstream>

using namespace std;

// ================================================================
//  FUNGSI REGISTRASI
// ================================================================

bool registrasiAkun() {

    Login akunBaru;

    string usernameLama;
    string passwordLama;

    // Memeriksa apakah akun sudah terdaftar
    ifstream cekFile("akun_login.txt");

    if (cekFile >> usernameLama >> passwordLama) {
        cout << "\nAkun sudah terdaftar!" << endl;
        cout << "Silakan langsung melakukan login." << endl;
        cekFile.close();
        return false;
    }

    cekFile.close();

    cout << "\n===== REGISTRASI MONETIX =====" << endl;

    cout << "Masukkan Username : ";
    cin >> akunBaru.username;

    cout << "Masukkan Password : ";
    cin >> akunBaru.password;

    // Menyimpan akun ke file
    ofstream file("akun_login.txt");

    if (!file.is_open()) {
        cout << "Gagal menyimpan akun!" << endl;
        return false;
    }

    file << akunBaru.username << endl;
    file << akunBaru.password << endl;

    file.close();

    cout << "\nRegistrasi berhasil!" << endl;

    return true;
}


// ================================================================
//  FUNGSI LOGIN
// ================================================================

bool loginAkun() {

    Login akunTerdaftar;
    Login akunInput;

    // Membuka data akun yang tersimpan
    ifstream file("akun_login.txt");

    if (!file.is_open()) {
        cout << "\nBelum ada akun!" << endl;
        cout << "Silakan registrasi terlebih dahulu." << endl;
        return false;
    }

    file >> akunTerdaftar.username;
    file >> akunTerdaftar.password;

    file.close();

    cout << "\n===== LOGIN MONETIX =====" << endl;

    cout << "Masukkan Username : ";
    cin >> akunInput.username;

    cout << "Masukkan Password : ";
    cin >> akunInput.password;

    // Memeriksa username dan password
    if (akunInput.username == akunTerdaftar.username &&
        akunInput.password == akunTerdaftar.password) {

        cout << "\nLogin berhasil!" << endl;
        cout << "Selamat datang di MONETIX." << endl;

        return true;

    } else {

        cout << "\nUsername atau password salah!" << endl;

        return false;
    }
}
