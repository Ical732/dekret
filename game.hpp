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

struct Efek
{
    string nama;

    int ekonomi;
    int masyarakat;
    int militer;
    int lingkungan;

    int sisaTurn;
};

struct Keputusan {
    string teks;

    int pengaruhi_ekonomi;
    int pengaruhi_masyarakat;
    int pengaruhi_militer;
    int pengaruhi_lingkungan;

    Efek* efekTambahan = nullptr;
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

struct DecisionHistoryStack {
    string history[512];
    int top;
};

struct Peristiwa
{
    string teks;

    Keputusan keputusan_1;
    Keputusan keputusan_2;

    Peristiwa* pilihan_1;
    Peristiwa* pilihan_2;
};

struct EventKhusus {
    int bulanMuncul;
    Peristiwa* (*buatTree)();
};

struct EfekNode
{
    Efek data;
    EfekNode* next;
};

struct QueueEfek
{
    EfekNode* front;
    EfekNode* rear;
};

void clearScreen();
void delay(int ms);
void tampilkanStatistik(const Statistik &pemain);
void tampilkanSkenario(const Skenario &skenario);
void tampilkanEfek(const Statistik &pemain, const Keputusan &keputusan);
void batasiStat(int &nilai);
void terapkanKeputusan(
    Statistik &pemain,
    const Keputusan &keputusan,
    QueueEfek &efekAktif
);
bool periksaKalah(const Statistik &pemain);

void initQueue(QueueEfek &q);
bool isQueueEmpty(QueueEfek &q);
void enqueueEfek(QueueEfek &q, Efek efek);
void dequeueEfek(QueueEfek &q);
Efek* peekEfek(QueueEfek &q);
void prosesEfekAktif(QueueEfek &q, Statistik &pemain);

void initializeDecisionHistory(DecisionHistoryStack &decisionHistory);
void pushDecisionHistory(DecisionHistoryStack &decisionHistory, int month, string scenarioText, string decisionText);
bool popDecisionHistory(DecisionHistoryStack &decisionHistory);
void showDecisionHistory(const DecisionHistoryStack &decisionHistory);

SaveNode* buatSaveList();
void tampilkanSlot(SaveNode* head);
void simpanKeSlot(SaveNode* head, int slot, Statistik pemain, int bulan, const DecisionHistoryStack &history);
bool muatDariSlot(int slot, Statistik &pemain, int &bulan, DecisionHistoryStack &history);

void menuUtama();
void jalankanGame(Statistik &pemain, int bulanAwal, SaveNode* saveList, DecisionHistoryStack &decisionHistory);

Peristiwa* buatTreeMiliter();
void jalankanTree(
    Peristiwa* root,
    Statistik &pemain,
    SaveNode* saveList,
    DecisionHistoryStack &decisionHistory,
    int bulan,
    int tahun,
    int bulan_dalam_tahun,
    QueueEfek &efekAktif
);
void hapusTree(Peristiwa* root);

#endif
