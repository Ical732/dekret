#ifndef GAME_HPP
#define GAME_HPP

#include <string>

using namespace std;

struct Statistik
{
    int ekonomi;
    int masyarakat;
    int militer;
    int lingkungan;
};

struct Keputusan {
    string teks;

    int pengaruhi_ekonomi;
    int pengaruhi_masyarakat;
    int pengaruhi_militer;
    int pengaruhi_lingkungan;
}; 

struct Skenario {
    string teks;

    Keputusan keputusan_1;
    Keputusan keputusan_2;
};

struct SaveNode {
    int slot;
    bool terisi;
    Statistik pemain;
    int bulan;
    SaveNode* next;
};

void clearScreen();
void delay(int ms);
void tampilkanStatistik(const Statistik &pemain);
void tampilkanSkenario(const Skenario &skenario);
void batasiStat(int &nilai);
void terapkanKeputusan(Statistik &pemain, const Keputusan &keputusan);
bool periksaKalah(const Statistik &pemain);

SaveNode* buatSaveList();
void tampilkanSlot(SaveNode* head);
void simpanKeSlot(SaveNode* head, int slot, Statistik pemain, int bulan);
bool muatDariSlot(int slot, Statistik &pemain, int &bulan);

void menuUtama();
void jalankanGame(Statistik &pemain, int bulanAwal, SaveNode* saveList);

#endif