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

void pauseScreen()
{
    cout << "Tekan 'enter' untuk lanjut...";
    cin.ignore();
    cin.get();
}

void delay(int ms) {
    Sleep(ms);
}

SaveNode* buatSaveList() {
    SaveNode* head = nullptr;
    SaveNode* tail = nullptr;

    for (int i = 1; i <= 5; i++) {
        SaveNode* node = new SaveNode;
        node->slot = i;
        node->terisi = false;
        node->bulan = 0;
        node->next = nullptr;

        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

void loadSaveList(SaveNode* head)
{
    SaveNode* current = head;

    while (current != nullptr) {
        string namaFile = "save_" + to_string(current->slot) + ".txt";
        ifstream file(namaFile);

        if (file) {
            current->terisi = true;

            Statistik temp;
            file >> temp.ekonomi
                 >> temp.masyarakat
                 >> temp.militer
                 >> temp.lingkungan
                 >> current->bulan;
        } else {
            current->terisi = false;
            current->bulan = 0;
        }

        file.close();
        current = current->next;
    }
}

void tampilkanSlot(SaveNode* head) {
    SaveNode* current = head;

    cout << "---------------------------\n";
    cout << "         Slot Save         \n";
    cout << "---------------------------\n";


    while (current != nullptr) {
        cout << current->slot << ". ";

        if (current->terisi) {
            cout << "Terisi (Bulan " << current->bulan << ")\n";
        } else {
            cout << "Kosong\n";
        }

        current = current->next;
    }

    cout << "---------------------------\n";
}

void simpanKeSlot(SaveNode* head, int pilihanSlot, Statistik pemain, int bulan) {
    SaveNode* current = head;

    while (current != nullptr) {
        if (current->slot == pilihanSlot) {
            current->pemain = pemain;
            current->bulan = bulan;
            current->terisi = true;

            string namaFile = "save_" + to_string(pilihanSlot) + ".txt";
            ofstream file(namaFile);

            file << pemain.ekonomi << endl;
            file << pemain.masyarakat << endl;
            file << pemain.militer << endl;
            file << pemain.lingkungan << endl;
            file << bulan << endl;

            file.close();

            cout << "Game disimpan di slot " << pilihanSlot << "!\n\n";
            return;
        }
        current = current->next;
    }
}

bool muatDariSlot(int slot, Statistik &pemain, int &bulan) {
    string namaFile = "save_" + to_string(slot) + ".txt";
    ifstream file(namaFile);

    if (!file) {
        cout << "Slot kosong.\n";
        return false;
    }

    file >> pemain.ekonomi
         >> pemain.masyarakat
         >> pemain.militer
         >> pemain.lingkungan
         >> bulan;

    file.close();
    return true;
}

void hapusSlot(SaveNode* head, int slot)
{
    SaveNode* current = head;

    while (current != nullptr) {
        if (current->slot == slot) {

            string namaFile = "save_" + to_string(slot) + ".txt";

            if (remove(namaFile.c_str()) == 0) {
                current->terisi = false;
                current->bulan = 0;

                cout << "Save di slot " << slot << " berhasil dihapus!\n";
            } else {
                cout << "Slot sudah kosong atau file tidak ditemukan.\n";
            }

            return;
        }
        current = current->next;
    }
}

void menuUtama() {
    SaveNode* saveList = buatSaveList();
    loadSaveList(saveList);
    Statistik pemain = {50, 
        50, 50, 50};
    int bulan = 0;

    string pilihan, konfirmasi;

    while (true) {
        clearScreen();

        cout << "============================\n";
        cout << "        D E K R E T\n";
        cout << "  Simulasi Kepemimpinan\n";
        cout << "     Indonesia 2039\n";
        cout << "============================\n";
        cout << "1. Game Baru\n";
        cout << "2. Muat Save\n";
        cout << "3. Hapus Save\n";
        cout << "4. Keluar\n";
        cout << "----------------------------\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == "1") {
            while (true) {
                clearScreen();

                cout << "Memulai game baru...\n";
                delay(1000);

                clearScreen();
                Statistik pemainBaru = {50, 50, 50, 50};
                jalankanGame(pemainBaru, 0, saveList);
                break;
            }
        }
        else if (pilihan == "2") {
            clearScreen();
            cout << "Memuat save...\n";
            delay(1000);
            clearScreen();

            tampilkanSlot(saveList);

            char slot;

            while (true)
            {
                cout << "Pilih slot (1-5) atau (q) untuk keluar: ";
                cin >> slot;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Input tidak valid!\n";
                    continue;
                }

                cin.ignore(1000, '\n');

                if (slot >= '1' && slot <= '5')
                {
                    int slotAngka = slot - '0';
                    if (muatDariSlot(slotAngka, pemain, bulan)) {
                        jalankanGame(pemain, bulan, saveList);
                    }
                    cout << "Memuat game...\n";
                    delay(800);
                    clearScreen();
                    break;
                }
                else if (slot == 'q' || slot == 'Q')
                {
                    clearScreen();
                    break;
                }
                else
                {
                    cout << "Input tidak valid!\n";
                }
                cout << endl;
            }
        }
        else if (pilihan == "3") {
            clearScreen();
            cout << "Memuat save...\n";
            delay(1000);
            clearScreen();

            tampilkanSlot(saveList);

            char slot;

            while (true)
            {
                cout << "Pilih slot (1-5) atau (c) untuk batal: ";
                cin >> slot;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Input tidak valid!\n";
                    continue;
                }

                cin.ignore(1000, '\n');

                if (slot >= '1' && slot <= '5')
                {
                    int slotAngka = slot - '0';

                    cout << "Yakin ingin menghapus? (y/n): ";
                    string konfirmasi;
                    cin >> konfirmasi;

                    if (konfirmasi == "y" || konfirmasi == "Y") {
                        hapusSlot(saveList, slotAngka);
                    } else {
                        cout << "Dibatalkan.\n";
                    }

                    break;
                }
                else if (slot == 'c' || slot == 'C')
                {
                    cout << "Batal.\n";
                    break;
                }
                else
                {
                    cout << "Input tidak valid!\n";
                }
            }

            pauseScreen();
        }
        else if (pilihan == "4") {
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
    cout << "----------------------------------" << endl;
    cout << "Ekonomi    : " << pemain.ekonomi << endl;
    cout << "Masyarakat : " << pemain.masyarakat << endl;
    cout << "Militer    : " << pemain.militer << endl;
    cout << "Lingkungan : " << pemain.lingkungan << endl;
    cout << "----------------------------------" << endl;
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

void tampilkanEfek(const Statistik &pemain, const Keputusan &keputusan)
{
    cout << "----------------------------------" << endl;

    cout << "Ekonomi    : " << pemain.ekonomi;
    if (keputusan.pengaruhi_ekonomi > 0)
        cout << " [+" << keputusan.pengaruhi_ekonomi << "]";
    else if (keputusan.pengaruhi_ekonomi < 0)
        cout << " [" << keputusan.pengaruhi_ekonomi << "]";
    cout << endl;

    cout << "Masyarakat : " << pemain.masyarakat;
    if (keputusan.pengaruhi_masyarakat > 0)
        cout << " [+" << keputusan.pengaruhi_masyarakat << "]";
    else if (keputusan.pengaruhi_masyarakat < 0)
        cout << " [" << keputusan.pengaruhi_masyarakat << "]";
    cout << endl;

    cout << "Militer    : " << pemain.militer;
    if (keputusan.pengaruhi_militer > 0)
        cout << " [+" << keputusan.pengaruhi_militer << "]";
    else if (keputusan.pengaruhi_militer < 0)
        cout << " [" << keputusan.pengaruhi_militer << "]";
    cout << endl;

    cout << "Lingkungan : " << pemain.lingkungan;
    if (keputusan.pengaruhi_lingkungan > 0)
        cout << " [+" << keputusan.pengaruhi_lingkungan << "]";
    else if (keputusan.pengaruhi_lingkungan < 0)
        cout << " [" << keputusan.pengaruhi_lingkungan << "]";
    cout << endl;

    cout << "----------------------------------" << endl;
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

void jalankanGame(Statistik &pemain, int bulan_awal, SaveNode* saveList) {
    Skenario* skenario = daftarSkenario();
    int totalSkenario = jumlahSkenario();
    bool kalah = false;

    for (int bulan = bulan_awal; bulan < totalSkenario; bulan++) {
        int tahun = bulan / 12;
        int bulan_dalam_tahun = bulan % 12 + 1;

        cout << "----------------------------------\n";
        cout << "Masa Jabatan: " << tahun << " Tahun, " << bulan_dalam_tahun << " Bulan\n";

        tampilkanStatistik(pemain);
        cout << endl;

        Skenario sekarang = skenario[bulan];
        tampilkanSkenario(sekarang);
        cout << endl;

        cout << "Pilih keputusan (1-2) atau (s) untuk save dan (q) untuk kembali ke menu utama." << endl;

        cout << endl;

        string pilihan, konfirmasi;

        while (true) {
            cout << "Input: ";
            cin >> pilihan;

            cout << endl;

            if (pilihan == "1") {
                terapkanKeputusan(pemain, sekarang.keputusan_1);
                tampilkanEfek(pemain, sekarang.keputusan_1);
                break;
            } 
            else if (pilihan == "2") {
                terapkanKeputusan(pemain, sekarang.keputusan_2);
                tampilkanEfek(pemain, sekarang.keputusan_1);
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

                    cout << endl;

                    if (konfirmasi == "y" || konfirmasi == "Y") {
                        tampilkanSlot(saveList);

                        char slot;

                        while (true)
                        {
                            cout << "Pilih slot (1-5) atau batal (c): ";
                            cin >> slot;

                            cout << endl;

                            if (cin.fail())
                            {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "Input tidak valid!\n\n";
                                continue;
                            }

                            cin.ignore(1000, '\n');

                            if (slot >= '1' && slot <= '5')
                            {
                                int slotAngka = slot - '0';
                                simpanKeSlot(saveList, slotAngka, pemain, bulan);
                                break;
                            }
                            else if (slot == 'c' || slot == 'C')
                            {
                                cout << "Batal menyimpan.\n\n";
                                break;
                            }
                            else
                            {
                                cout << "Input tidak valid!\n\n";
                                pauseScreen();
                            }

                            cout << endl;
                        }
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

        pauseScreen();

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
            cout << "Negara kuat, tetapi rakyat hidup dalam tekanan.\n";
        }
        else {
            delay(5000);
            cout << "Anda bertahan, tetapi banyak masalah tersisa.\n";
        }
    }
    else {
        delay(3000);
        cout << "\nGame Over.\n";
    }
}