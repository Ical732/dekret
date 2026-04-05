#include <iostream>
#include <fstream>
#include <cstdio>
#include <windows.h>

#include "game.hpp"
#include "scenario.hpp"

using namespace std;

void clearScreen() {
    system("cls");
}

void delay(int ms) {
    Sleep(ms);
}

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
        cout << "File save tidak ditemukan.\n";
        return false;
    }

    if (!(file >> pemain.ekonomi
              >> pemain.masyarakat
              >> pemain.militer
              >> pemain.lingkungan
              >> bulan)) {
        cout << "Data save kosong atau rusak!\n";
        file.close();
        return false;
    }

    file.close();

    if (pemain.ekonomi < 0 || pemain.ekonomi > 100 ||
        pemain.masyarakat < 0 || pemain.masyarakat > 100 ||
        pemain.militer < 0 || pemain.militer > 100 ||
        pemain.lingkungan < 0 || pemain.lingkungan > 100) {
        
        cout << "Data save tidak valid!\n";
        return false;
    }

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

    string pilihan, konfirmasi;

    while (true) {
        clearScreen();

        cout << "============================\n";
        cout << "        D E K R E T\n";
        cout << "  Simulasi Kepemimpinan\n";
        cout << "     Indonesia 2039\n";
        cout << "============================\n\n";
        cout << "1. Game Baru\n";
        cout << "2. Lanjutkan\n";
        cout << "3. Keluar\n";
        cout << "------------------------\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == "1") {
            while (true) {
                cout << "Memulai game baru akan menghapus save sebelumnya. Lanjutkan? (y/t): ";
                cin >> konfirmasi;

                if (konfirmasi == "y" || konfirmasi == "Y") {
                    clearScreen();
                    cout << "Menghapus save...\n";
                    delay(800);

                    hapusSave();

                    cout << "Memulai game baru...\n";
                    delay(1000);

                    clearScreen();
                    jalankanGame(pemain, 0);
                    break;
                }
                else if (konfirmasi == "t" || konfirmasi == "T") {
                    clearScreen();
                    break;
                }
                else {
                    cout << "Pilihan tidak valid.\n";
                }
            }
        }
        else if (pilihan == "2") {
            clearScreen();
            cout << "Memuat save...\n";
            delay(1000);

            if (muatSave(pemain, bulan)) {
                cout << "Save berhasil dimuat!\n";
                delay(1000);

                clearScreen();
                jalankanGame(pemain, bulan);
            } 
            else {
                cout << "Tidak bisa melanjutkan game.\n";
                delay(1000);
            }
        }
        else if (pilihan == "3") {
            cout << "Keluar...\n";
            delay(800);
            break;
        }
        else {
            cout << "Pilihan tidak valid.\n";
            delay(800);
        }
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

void batasiStat(int &nilai) {
    if (nilai < 0) nilai = 0;
    if (nilai > 100) nilai = 100;
}

void terapkanKeputusan(Statistik &pemain, const Keputusan &keputusan) 
{
    pemain.ekonomi += keputusan.pengaruhi_ekonomi;
    pemain.masyarakat += keputusan.pengaruhi_masyarakat;
    pemain.militer += keputusan.pengaruhi_militer;
    pemain.lingkungan += keputusan.pengaruhi_lingkungan;

    batasiStat(pemain.ekonomi);
    batasiStat(pemain.masyarakat);
    batasiStat(pemain.militer);
    batasiStat(pemain.lingkungan);
}

bool periksaKalah(const Statistik &pemain) 
{
    
    if (pemain.ekonomi <= 0) {
        cout << "\nEkonomi negeri Anda runtuh...\n";
        delay(800);
        return true;
    }
    else if (pemain.masyarakat <= 0) {
        cout << "\nRakyat menggulingkan Anda...\n";
        delay(800);
        return true;
    }
    else if (pemain.militer <= 0) {
        cout << "\nNegeri seberang menjajah negara ini...\n";
        delay(800);
        return true;
    }
    else if (pemain.lingkungan <= 0) {
        cout << "\nLingkungan di negeri ini telah rusak...\n";
        delay(800);
        return true;
    }
    else if (pemain.ekonomi >= 100) {
        cout << "\nPerusahaan menguasai negara Anda...\n";
        delay(800);
        return true;
    }
    else if (pemain.masyarakat >= 100) {
        cout << "\nRakyat mencintai Anda, tetapi Anda dibunuh oleh pihak tidak dikenal...\n";
        delay(800);
        return true;
    }
    else if (pemain.militer >= 100) {
        cout << "\nMiliter mengudeta Anda...\n";
        delay(800);
        return true;
    }
    else if (pemain.lingkungan >= 100) {
        cout << "\nRakyat mencintai Anda, tetapi Anda dibunuh oleh pihak tidak dikenal...\n";
        delay(800);
        return true;
    }

    return false;
}

void jalankanGame(Statistik &pemain, int bulan_awal) {
    Skenario* skenario = daftarSkenario();
    int totalSkenario = jumlahSkenario();
    bool kalah = false;

    for (int bulan = bulan_awal; bulan < totalSkenario; bulan++) {
        int tahun = bulan / 12;
        int bulan_dalam_tahun = bulan % 12 + 1;

        cout << "------------------------\n";
        cout << "Masa Jabatan: " << tahun << " Tahun, " << bulan_dalam_tahun << " Bulan\n";

        tampilkanStatistik(pemain);
        cout << endl;

        Skenario sekarang = skenario[bulan];
        tampilkanSkenario(sekarang);
        cout << endl;

        cout << "Pilih keputusan (1-2) atau (s) untuk save dan (q) untuk kembali ke menu utama." << endl;

        string pilihan, konfirmasi;

        while (true) {
            cout << "Input: ";
            cin >> pilihan;

            if (pilihan == "1") {
                terapkanKeputusan(pemain, sekarang.keputusan_1);
                break;
            } 
            else if (pilihan == "2") {
                terapkanKeputusan(pemain, sekarang.keputusan_2);
                break;
            }
            else if (pilihan == "q" || pilihan == "Q") {
                cout << "Kembali ke menu utama...\n";
                delay(800);
                return;
            }
            else if (pilihan == "s" || pilihan == "S") {
                while (true) {
                    cout << "Simpan game? (y/t): ";
                    cin >> konfirmasi;

                    if (konfirmasi == "y" || konfirmasi == "Y") {
                        saveGame(pemain, bulan);
                        break;
                    }
                    else if (konfirmasi == "t" || konfirmasi == "T") {
                        break;
                    }
                    else {
                        cout << "Pilihan tidak valid.\n";
                    }
                }
            }
            else {
                cout << "Pilihan tidak valid!\n";
            }
        }

        if (periksaKalah(pemain)) {
            kalah = true;
            break;
        }

        cout << "Tekan enter untuk lanjut...";
        cin.ignore();
        cin.get();

        clearScreen();
    }

    if (!kalah) {
        cout << "\nSelamat! Anda berhasil menyelesaikan masa jabatan!\n";
        if (pemain.ekonomi > 70 && pemain.masyarakat > 70) {
            delay(5000);
            cout << "Rakyat makmur dan bahagia! Anda dikenang sebagai pemimpin hebat.\n";
        } 
        else if (pemain.militer > 80) {
            delay(5000);
            cout << "Negara kuat, tapi rakyat hidup dalam tekanan.\n";
        }
        else {
            delay(5000);
            cout << "Anda bertahan, tapi banyak masalah tersisa.\n";
        }
    }
    else {
        delay(3000);
        cout << "\nGame Over.\n";
    }
}