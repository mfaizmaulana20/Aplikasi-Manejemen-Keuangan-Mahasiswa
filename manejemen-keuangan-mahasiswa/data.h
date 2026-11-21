
#ifndef DATA_H
#define DATA_H

#include <string>

// ================================================================
//  Data.h - SATU-SATUNYA TEMPAT DEFINISI SEMUA STRUCT MONETIX
//  Proyek : Aplikasi Manajemen Keuangan Mahasiswa
//
//  ATURAN:
//  1. Semua struct didefinisikan di file ini.
//  2. Tidak menggunakan "using namespace std".
//  3. File .h dan .cpp setiap modul menggunakan struct dari data.h.
//  4. Struktur data disesuaikan dengan kebutuhan aplikasi MONETIX.
// ================================================================


// ================================================================
//  JENIS DATA
// ================================================================

// Jenis transaksi keuangan
enum class JenisTransaksi {
    PEMASUKAN,
    PENGELUARAN
};

// Jenis utang dan piutang
enum class JenisUtangPiutang {
    UTANG,
    PIUTANG
};

// Jenis aksi untuk Stack (Undo)
enum class JenisAksi {
    TAMBAH,
    EDIT,
    HAPUS
};


// ================================================================
//  DATA LOGIN
//  File : login.h, login.cpp
//  Fungsi : Menyimpan username dan password pengguna.
// ================================================================

struct Login {
    std::string username;
    std::string password;
};


// ================================================================
//  DATA PROFIL DAN AKUN MAHASISWA
//  File : akun.h, akun.cpp
// ================================================================

// Data profil mahasiswa
struct ProfilMahasiswa {
    std::string nama;
    std::string nim;
    std::string programStudi;
};

// Data akun keuangan
struct Akun {
    int id;
    std::string namaAkun;
    long long saldo;
};


// ================================================================
//  DATA TRANSAKSI KEUANGAN
//  File : transaksi.h, transaksi.cpp
// ================================================================

struct Transaksi {
    int id;
    int idAkun;
    std::string tanggal;
    long long nominal;
    std::string keterangan;
    JenisTransaksi jenis;
};


// ================================================================
//  LINKED LIST
//  File : transaksi.h, transaksi.cpp
//  Fungsi : Menyimpan catatan transaksi keuangan.
// ================================================================

struct NodeTransaksi {
    Transaksi data;
    NodeTransaksi* next;
};


// ================================================================
//  MULTI LINKED LIST
//  File : multilist.h, multilist.cpp
//  Fungsi : Menghubungkan akun dengan transaksi yang dimiliki.
// ================================================================

// Parent: Akun
// Child : Daftar transaksi

struct NodeAkun {
    Akun data;
    NodeAkun* nextAkun;
    NodeTransaksi* firstTransaksi;
};

struct MultiLinkedList {
    NodeAkun* firstAkun;
    int jumlahAkun;
};


// ================================================================
//  BINARY SEARCH TREE
//  File : bst.h, bst.cpp
//  Fungsi : Mengelola dan mencari akun berdasarkan ID.
// ================================================================

struct NodeBST {
    int id;
    NodeAkun* ptrAkun;
    NodeBST* left;
    NodeBST* right;
};


// ================================================================
//  STACK
//  File : stack.h, stack.cpp
//  Fungsi : Mengelola aksi menggunakan prinsip LIFO.
//  Rencana tambahan : Fitur Undo perubahan transaksi.
// ================================================================

struct Aksi {
    JenisAksi jenis;
    Transaksi sebelum;
    Transaksi sesudah;
};

struct NodeStack {
    Aksi data;
    NodeStack* next;
};

struct Stack {
    NodeStack* top;
    int jumlah;
};


// ================================================================
//  DATA FITUR TAMBAHAN MONETIX
// ================================================================

// Alokasi pembagian uang saku
struct AlokasiUangSaku {
    std::string kategori;
    double persentase;
    long long nominalAlokasi;
    long long nominalTerpakai;
};

// Biaya akademik
struct BiayaAkademik {
    int id;
    std::string namaBiaya;
    std::string tanggal;
    long long nominal;
    bool sudahDibayar;
};

// Kalkulator patungan
struct Patungan {
    int id;
    std::string namaKegiatan;
    long long totalBiaya;
    int jumlahOrang;
    long long biayaPerOrang;
};

// Jadwal kewajiban pembayaran
struct JadwalPembayaran {
    int id;
    std::string keterangan;
    std::string tanggalJatuhTempo;
    long long nominal;
    bool sudahDibayar;
};

// Target dana darurat
struct TargetDanaDarurat {
    long long targetNominal;
    long long danaTerkumpul;
};

// Catatan utang dan piutang
struct UtangPiutang {
    int id;
    std::string namaPihak;
    JenisUtangPiutang jenis;
    long long nominal;
    std::string tanggal;
    bool sudahLunas;
};

// Penghasilan tambahan
struct PenghasilanTambahan {
    int id;
    std::string sumberPenghasilan;
    std::string tanggal;
    long long nominal;
    std::string keterangan;
};


// ================================================================
//  QUEUE
//  File : queue.h, queue.cpp
//  Fungsi : Mengelola data menggunakan prinsip FIFO.
//  Rencana penggunaan : Antrean pengingat pembayaran.
// ================================================================

struct NodeQueue {
    JadwalPembayaran data;
    NodeQueue* next;
};

struct Queue {
    NodeQueue* front;
    NodeQueue* rear;
    int jumlah;
};

#endif
