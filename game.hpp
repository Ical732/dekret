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

void tampilkanStatistik(const Statistik &pemain);
void tampilkanSkenario(const Skenario &skenario);
void terapkanKeputusan(Statistik &pemain, const Keputusan &keputusan);
bool periksaKalah(const Statistik &pemain);

void saveGame(const Statistik &pemain, int bulan);
bool muatSave(Statistik &pemain, int &bulan);
void hapusSave();

void menuUtama();
void jalankanGame(Statistik &pemain, int bulanAwal);

#endif