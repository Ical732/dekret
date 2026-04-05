#include <iostream>
#include <fstream>
#include <cstdio>

#include "game.hpp"
#include "scenario.hpp"

using namespace std;

void saveGame(const Statistik &pemain, int bulan) {
    ofstream file("save.txt");

    file << pemain.ekonomi << endl;
    file << pemain.masyarakat << endl;
    file << pemain.militer << endl;
    file << pemain.lingkungan << endl;
    file << bulan << endl;

    file.close();
    cout << "Game ter-save!\n";
}

bool muatSave(Statistik &pemain, int &bulan) {
    ifstream file("save.txt");

    if (!file) {
        cout << "File save kosong.\n";
        return false;
    }

    file >> pemain.ekonomi;
    file >> pemain.masyarakat;
    file >> pemain.militer;
    file >> pemain.lingkungan;
    file >> bulan;

    file.close();
    cout << "Save dimuat!\n";
    return true;
}

void hapusSave() {
    if (remove("save.txt") == 0) {
        cout << "Save dihapus.\n";
    } else {
        cout << "File save kosong.\n";
    }
}

void menuUtama() {
    Statistik pemain = {50, 50, 50, 50};
    int bulan = 0;

    int pilihan;

    while (true) {
        cout << "------------------------\n";
        cout << "1. Game Baru\n";
        cout << "2. Lanjutkan\n";
        cout << "3. Keluar\n";
        cout << "------------------------\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Memulai game baru akan menghapus save sebelumnya. Lanjutkan? (Y/T)";
            hapusSave();
            jalankanGame(pemain, 0);
        }
        else if (pilihan == 2) {
            if (muatSave(pemain, bulan)) {
                jalankanGame(pemain, bulan);
            }
        }
        else {
            cout << "Keluar...\n";
            break;
        }

        cout << endl;
    }
}

void tampilkanStatistik(const Statistik &pemain) 
{
    cout << "------------------------" << endl;
    cout << "Ekonomi    : " << pemain.ekonomi << endl;
    cout << "Masyarakat : " << pemain.masyarakat << endl;
    cout << "Militer    : " << pemain.militer << endl;
    cout << "Lingkungan : " << pemain.lingkungan << endl;
    cout << "------------------------" << endl;
}

void tampilkanSkenario(const Skenario &skenario) 
{
    cout << skenario.teks << endl;
    cout << "1. " << skenario.keputusan_1.teks << endl;
    cout << "2. " << skenario.keputusan_2.teks << endl;
}

void terapkanKeputusan(Statistik &pemain, const Keputusan &keputusan) 
{
    pemain.ekonomi += keputusan.pengaruhi_ekonomi;
    pemain.masyarakat += keputusan.pengaruhi_masyarakat;
    pemain.militer += keputusan.pengaruhi_militer;
    pemain.lingkungan += keputusan.pengaruhi_lingkungan;
}

bool periksaKalah(const Statistik &pemain) 
{
    
    if (pemain.ekonomi <= 0) {
        cout << "\nEkonomi negeri Anda runtuh...\n";
        return true;
    }
    else if (pemain.masyarakat <= 0) {
        cout << "\nRakyat menggulingkan Anda...\n";
        return true;
    }
    else if (pemain.militer <= 0) {
        cout << "\nNegeri seberang menjajah negara ini...\n";
        return true;
    }
    else if (pemain.lingkungan <= 0) {
        cout << "\nLingkungan di negeri ini telah rusak...\n";
        return true;
    }
    else if (pemain.ekonomi >= 100) {
        cout << "\nPerusahaan menguasai negara Anda...\n";
        return true;
    }
    else if (pemain.masyarakat >= 100) {
        cout << "\nRakyat mencintai Anda, tetapi Anda dibunuh oleh pihak tidak dikenal...\n";
        return true;
    }
    else if (pemain.militer >= 100) {
        cout << "\nMiliter mengudeta Anda...\n";
        return true;
    }
    else if (pemain.lingkungan >= 100) {
        cout << "\nRakyat mencintai Anda, tetapi Anda dibunuh oleh pihak tidak dikenal...\n";
        return true;
    }

    return false;
}

void jalankanGame(Statistik &pemain, int bulan_awal) {
    Skenario* skenario = daftarSkenario();
    int totalSkenario = jumlahSkenario();

    for (int bulan = bulan_awal; bulan < totalSkenario; bulan++) {
        int tahun = bulan / 12;
        int bulan_dalam_tahun = bulan % 12 + 1;

        cout << "Masa Jabatan: " << tahun << " Tahun, " << bulan_dalam_tahun << " Bulan\n";

        tampilkanStatistik(pemain);
        cout << endl;

        Skenario sekarang = skenario[bulan];
        tampilkanSkenario(sekarang);

        cout << endl;

        cout << "Pilih keputusan (1-2) atau (s) untuk save." << endl;

        char pilihan;

        while (true) {
            cout << "Input: ";
            cin >> pilihan;

            if (pilihan == '1') {
                terapkanKeputusan(pemain, sekarang.keputusan_1);
                break;
            } 
            else if (pilihan == '2') {
                terapkanKeputusan(pemain, sekarang.keputusan_2);
                break;
            }
            else if (pilihan == 's' || pilihan == 'S') {
                cout << "Simpan game? (Y/T): ";
                char save;
                cin >> save;

                if (save == 'y' || save == 'Y') {
                    saveGame(pemain, bulan);
                }
            }
            else {
                cout << "Pilihan tidak valid!\n";
            }
        }

        if (periksaKalah(pemain)) {
            break;
        }

        cout << endl;
    }

    cout << "\nGame Over.\n";
}