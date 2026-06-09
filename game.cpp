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

void hapusTree(Peristiwa* root)
{
    if (root == nullptr)
        return;

    hapusTree(root->pilihan_1);
    hapusTree(root->pilihan_2);

    delete root;
}

void initializeDecisionHistory(DecisionHistoryStack &decisionHistory)
{
    decisionHistory.top = -1;
}

void pushDecisionHistory(DecisionHistoryStack &decisionHistory, int month, string scenarioText, string decisionText)
{
    string historyText =
    "Bulan " + to_string(month + 1) +
    " | Skenario: " + scenarioText +
    " | Keputusan: " + decisionText;

    if (decisionHistory.top < 511) {
        decisionHistory.top++;
        decisionHistory.history[decisionHistory.top] = historyText;
    } else {
        for (int index = 1; index <= 511; index++) {
            decisionHistory.history[index - 1] = decisionHistory.history[index];
        }

        decisionHistory.history[511] = historyText;
    }
}

void showDecisionHistory(const DecisionHistoryStack &decisionHistory)
{
    cout << "===============================\n";
    cout << "        Riwayat Keputusan      \n";
    cout << "===============================\n\n";

    if (decisionHistory.top == -1) {
        cout << "Belum ada riwayat keputusan.\n";
    } else {
        for (int index = 0; index <= decisionHistory.top; index++) {
            cout << decisionHistory.history[index] << endl;
        }
    }

    cout << "\n===============================\n";
}

void pauseAfterDecision(const DecisionHistoryStack &decisionHistory)
{
    string historyInput;

    cin.ignore();

    while (true) {
        cout << "Input 'r' untuk memeriksa riwayat keputusan\n";
        cout << "Tekan 'enter' untuk lanjut...";
        getline(cin, historyInput);

        if (historyInput == "r" || historyInput == "R") {
            clearScreen();
            showDecisionHistory(decisionHistory);
            cout << "Tekan 'enter' untuk kembali...";
            getline(cin, historyInput);
            clearScreen();
        } else if (historyInput == "") {
            break;
        } else {
            cout << "\nInput tidak valid!\n\n";
        }
    }
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

void simpanKeSlot(SaveNode* head, int pilihanSlot, Statistik pemain, int bulan, const DecisionHistoryStack &history) {
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
            file << history.top + 1 << endl;
            for (int i = 0; i <= history.top; i++)
            {
                file << history.history[i] << endl;
            }

            file.close();

            cout << "Game disimpan di slot " << pilihanSlot << "!\n\n";
            return;
        }
        current = current->next;
    }
}

bool muatDariSlot(int slot, Statistik &pemain, int &bulan, DecisionHistoryStack &history) {
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
         initializeDecisionHistory(history);

        int jumlahHistory;
        file >> jumlahHistory;

        file.ignore();
        for (int i = 0; i < jumlahHistory; i++)
        {
            getline(file, history.history[i]);
        }

        history.top = jumlahHistory - 1;

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

void initQueue(QueueEfek &q)
{
    q.front = nullptr;
    q.rear = nullptr;
}

bool isQueueEmpty(QueueEfek &q)
{
    return q.front == nullptr;
}

void enqueueEfek(QueueEfek &q, Efek efek)
{
    EfekNode* baru = new EfekNode;

    baru->data = efek;
    baru->next = nullptr;

    if (isQueueEmpty(q))
    {
        q.front = baru;
        q.rear = baru;
    }
    else
    {
        q.rear->next = baru;
        q.rear = baru;
    }
}

void dequeueEfek(QueueEfek &q)
{
    if (isQueueEmpty(q))
    {
        return;
    }

    EfekNode* hapus = q.front;

    q.front = q.front->next;

    delete hapus;

    if (q.front == nullptr)
    {
        q.rear = nullptr;
    }
}

Efek* peekEfek(QueueEfek &q)
{
    if (isQueueEmpty(q))
    {
        return nullptr;
    }

    return &q.front->data;
}

void prosesEfekAktif(QueueEfek &q, Statistik &pemain)
{
    if (isQueueEmpty(q))
    {
        return;
    }

    Efek* efek = peekEfek(q);

    pemain.ekonomi += efek->ekonomi;
    pemain.masyarakat += efek->masyarakat;
    pemain.militer += efek->militer;
    pemain.lingkungan += efek->lingkungan;

    batasiStat(pemain.ekonomi);
    batasiStat(pemain.masyarakat);
    batasiStat(pemain.militer);
    batasiStat(pemain.lingkungan);

    cout << "\n=== EFEK AKTIF ===\n";
    cout << efek->nama << endl;

    if (efek->ekonomi != 0)
    {
        cout << "Ekonomi ";
        if (efek->ekonomi > 0)
            cout << "+" << efek->ekonomi;
        else
            cout << efek->ekonomi;
        cout << endl;
    }

    if (efek->masyarakat != 0)
    {
        cout << "Masyarakat ";
        if (efek->masyarakat > 0)
            cout << "+" << efek->masyarakat;
        else
            cout << efek->masyarakat;
        cout << endl;
    }

    if (efek->militer != 0)
    {
        cout << "Militer ";
        if (efek->militer > 0)
            cout << "+" << efek->militer;
        else
            cout << efek->militer;
        cout << endl;
    }

    if (efek->lingkungan != 0)
    {
        cout << "Lingkungan ";
        if (efek->lingkungan > 0)
            cout << "+" << efek->lingkungan;
        else
            cout << efek->lingkungan;
        cout << endl;
    }

    efek->sisaTurn--;

    cout << "Sisa Turn : " << efek->sisaTurn << endl;

    if (efek->sisaTurn <= 0)
    {
        cout << "Efek \"" << efek->nama
             << "\" telah berakhir.\n";

        dequeueEfek(q);
    }
    cout << endl;
}

void menuUtama() {
    SaveNode* saveList = buatSaveList();
    DecisionHistoryStack decisionHistory;

    initializeDecisionHistory(decisionHistory);
    loadSaveList(saveList);
    Statistik pemain = {50, 
        50, 50, 50};
    int bulan = 0;

    string pilihan, konfirmasi, slot;

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
            initializeDecisionHistory(decisionHistory);

            while (true) {
                clearScreen();

                cout << "Memulai game baru...\n";
                delay(1000);

                clearScreen();
                Statistik pemainBaru = {50, 50, 50, 50};
                jalankanGame(pemainBaru, 0, saveList, decisionHistory);
                break;
            }
        }
        else if (pilihan == "2") {
            clearScreen();
            cout << "Memuat save...\n";
            delay(800);

            loadSaveList(saveList);

            clearScreen();
            tampilkanSlot(saveList);

            while (true)
            {
                cout << "Pilih slot (1-5) atau (q) untuk keluar: ";
                cin >> slot;

                if (slot.length() == 1 && slot[0] >= '1' && slot[0] <= '5')
                {
                    int slotAngka = slot[0] - '0';

                    cout << "Memuat game...\n";
                    delay(800);

                    if (muatDariSlot(slotAngka, pemain, bulan, decisionHistory)) {
                        clearScreen();
                        jalankanGame(pemain, bulan, saveList, decisionHistory);
                    } else {
                        cout << "Slot kosong!\n";
                        delay(800);
                    }
                    break;
                }
                else if (slot == "q" || slot == "Q")
                {
                    clearScreen();
                    break;
                }
                else
                {
                    cout << "Input tidak valid!\n";
                    pauseScreen();
                    clearScreen();
                }
            }
        }
        else if (pilihan == "3") {
            clearScreen();
            cout << "Memuat save...\n";
            delay(1000);
            clearScreen();

            tampilkanSlot(saveList);
            while (true)
            {
                cout << "Pilih slot (1-5) atau (c) untuk batal: ";
                cin >> slot;

                if (slot.length() == 1 && slot[0] >= '1' && slot[0] <= '5')
                {
                    int slotAngka = slot[0] - '0';

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
                else if (slot == "c" || slot == "C")
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

void jalankanTree(
    Peristiwa* root,
    Statistik &pemain,
    SaveNode* saveList,
    DecisionHistoryStack &decisionHistory,
    int bulan,
    int tahun,
    int bulan_dalam_tahun,
    QueueEfek &efekAktif
)
{
    Peristiwa* current = root;

    string konfirmasi;
    string slot;

    tampilkanStatistik(pemain);

    prosesEfekAktif(efekAktif, pemain);

    while (current != nullptr)
    {
        cout << endl;
        cout << current->teks << endl;

        if (current->pilihan_1 == nullptr &&
            current->pilihan_2 == nullptr)
        {
            cout << "\nTekan enter untuk lanjut...";
            cin.ignore();
            cin.get();
            break;
        }

        cout << "\n1. " << current->keputusan_1.teks << endl;
        cout << "2. " << current->keputusan_2.teks << endl;
        cout << endl;
        cout << "Pilih keputusan (1-2) atau (s) untuk save dan (q) untuk kembali.\n\n";
        cout << "Input 'r' untuk memeriksa riwayat keputusan.\n\n";

        string pilih;
        cout << "\nInput: ";
        cin >> pilih;

        cout << endl;

        if (pilih == "1")
        {
            terapkanKeputusan(
                pemain,
                current->keputusan_1,
                efekAktif
            );

            tampilkanEfek(
                pemain,
                current->keputusan_1
            );

            current = current->pilihan_1;
        }
        else if (pilih == "2")
        {
            terapkanKeputusan(
                pemain,
                current->keputusan_2,
                efekAktif
            );

            tampilkanEfek(
                pemain,
                current->keputusan_2
            );

            current = current->pilihan_2;
        }
        else if (pilih == "q" || pilih == "Q")
        {
            cout << "Kembali ke menu utama...\n";
            delay(800);
            return;
        }
        else if (pilih == "s" || pilih == "S")
        {
            while (true)
            {
                cout << "Simpan game? (y/t): ";
                cin >> konfirmasi;
                cout << endl;

                if (konfirmasi == "y" || konfirmasi == "Y")
                {
                    loadSaveList(saveList);
                    tampilkanSlot(saveList);

                    while (true)
                    {
                        cout << "Pilih slot (1-5) atau batal (c): ";
                        cin >> slot;
                        cout << endl;

                        if (slot.length() == 1 &&
                            slot[0] >= '1' &&
                            slot[0] <= '5')
                        {
                            int slotAngka = slot[0] - '0';

                            simpanKeSlot(
                                saveList,
                                slotAngka,
                                pemain,
                                bulan,
                                decisionHistory
                            );

                            delay(800);
                            break;
                        }
                        else if (slot == "c" || slot == "C")
                        {
                            cout << "Batal menyimpan.\n\n";
                            break;
                        }
                        else
                        {
                            cout << "Input tidak valid!\n\n";
                        }
                    }

                    break;
                }
                else if (konfirmasi == "t" || konfirmasi == "T")
                {
                    break;
                }
                else
                {
                    cout << "Pilihan tidak valid.\n";
                }
            }
            pauseScreen();
        }
        else if (pilih == "r" || pilih == "R")
        {
            clearScreen();
            showDecisionHistory(decisionHistory);
            pauseScreen();
            clearScreen();

            cout << "----------------------------------\n";
            cout << "Masa Jabatan: "
                 << tahun
                 << " Tahun, "
                 << bulan_dalam_tahun
                 << " Bulan\n";

            tampilkanStatistik(pemain);
        }
        else
        {
            cout << "Pilihan tidak valid!\n";
            delay(800);
        }
        
    }
}

void terapkanKeputusan(
    Statistik &pemain,
    const Keputusan &keputusan,
    QueueEfek &efekAktif
)
{
    pemain.ekonomi += keputusan.pengaruhi_ekonomi;
    pemain.masyarakat += keputusan.pengaruhi_masyarakat;
    pemain.militer += keputusan.pengaruhi_militer;
    pemain.lingkungan += keputusan.pengaruhi_lingkungan;

    batasiStat(pemain.ekonomi);
    batasiStat(pemain.masyarakat);
    batasiStat(pemain.militer);
    batasiStat(pemain.lingkungan);

    if (keputusan.efekTambahan != nullptr)
    {
        enqueueEfek(
            efekAktif,
            *keputusan.efekTambahan
        );
    }
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

void jalankanGame(Statistik &pemain, int bulan_awal, SaveNode* saveList, DecisionHistoryStack &decisionHistory) {
    Skenario* skenario = daftarSkenario();
    int totalSkenario = jumlahSkenario();
    bool kalah = false;

    EventKhusus* eventList = ambilEventKhusus();
    int totalEvent = jumlahEventKhusus();
    
    QueueEfek efekAktif;
    initQueue(efekAktif);

    // Efek demo =
    // {
    //     "Demonstrasi Besar",

    //     0,
    //     -5,
    //     0,
    //     0,

    //     3
    // };

    // enqueueEfek(efekAktif, demo);


    for (int bulan = bulan_awal; bulan < totalSkenario; bulan++)
    {
    clearScreen();

    int tahun = bulan / 12;
    int bulan_dalam_tahun = bulan % 12 + 1;

    cout << "----------------------------------\n";
    cout << "Masa Jabatan: " << tahun << " Tahun, " << bulan_dalam_tahun << " Bulan\n";

    bool eventDitemukan = false;

    for (int i = 0; i < totalEvent; i++)
    {
        if (eventList[i].bulanMuncul == bulan + 1)
        {
            Peristiwa* eventTree = eventList[i].buatTree();

            jalankanTree(
                eventTree,
                pemain,
                saveList,
                decisionHistory,
                bulan,
                tahun,
                bulan_dalam_tahun,
                efekAktif
            );

            hapusTree(eventTree);

            if (periksaKalah(pemain))
            {
                kalah = true;
                break;
            }

            eventDitemukan = true;
            break;
        }
    }

    if (kalah)
    {
        break;
    }

    if (eventDitemukan)
    {
        continue;
    }
    else
    {
        tampilkanStatistik(pemain);
        prosesEfekAktif(efekAktif, pemain);

        Skenario sekarang = skenario[bulan];
        tampilkanSkenario(sekarang);
        cout << endl;

        cout << "Pilih keputusan (1-2) atau (s) untuk save dan (q) untuk kembali.\n\n";
        cout << "Input 'r' untuk memeriksa riwayat keputusan.\n\n";

        string pilihan, konfirmasi, slot;

        while (true) {
            cout << "Input: ";
            cin >> pilihan;
            cout << endl;

            if (pilihan == "1") {
                terapkanKeputusan(pemain, sekarang.keputusan_1, efekAktif);
                pushDecisionHistory(decisionHistory, bulan, sekarang.teks, sekarang.keputusan_1.teks);
                tampilkanEfek(pemain, sekarang.keputusan_1);
                cout << endl;
                pauseScreen();
                break;
            } 
            else if (pilihan == "2") {
                terapkanKeputusan(pemain, sekarang.keputusan_2);
                pushDecisionHistory(decisionHistory, bulan, sekarang.teks, sekarang.keputusan_2.teks);
                tampilkanEfek(pemain, sekarang.keputusan_2);
                cout << endl;
                pauseScreen();
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

                        loadSaveList(saveList);
                        tampilkanSlot(saveList);

                        while (true)
                        {
                            cout << "Pilih slot (1-5) atau batal (c): ";
                            cin >> slot;
                            cout << endl;

                            if (slot.length() == 1 && slot[0] >= '1' && slot[0] <= '5')
                            {
                                int slotAngka = slot[0] - '0';
                                simpanKeSlot(saveList, slotAngka, pemain, bulan, decisionHistory);
                                delay(800);
                                break;
                            }
                            else if (slot == "c" || slot == "C")
                            {
                                cout << "Batal menyimpan.\n\n";
                                break;
                            }
                            else
                            {
                                cout << "Input tidak valid!\n\n";
                            }
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
            else if (pilihan == "r" || pilihan == "R") {
                clearScreen();
                showDecisionHistory(decisionHistory);
                pauseScreen();
                clearScreen();

                cout << "----------------------------------\n";
                cout << "Masa Jabatan: " << tahun << " Tahun, " << bulan_dalam_tahun << " Bulan\n";

                tampilkanStatistik(pemain);
                cout << endl;

                tampilkanSkenario(sekarang);
                cout << endl;

                cout << "Pilih keputusan (1-2) atau (s) untuk save dan (q) untuk kembali.\n\n";
                cout << "Input 'r' untuk memeriksa riwayat keputusan.\n\n";
            }
            else {
                cout << "Pilihan tidak valid!\n";
            }
        }

        }
        
        if (periksaKalah(pemain)) {
            kalah = true;
            break;
        }
    }

    clearScreen();

    if (kalah == true)
    {
        delay(3000);
        cout << "\nGame Berakhir.\n";
    }
    else
    {
        cout << "Selamat! Anda berhasil menyelesaikan masa jabatan 5 tahun!\n";
    }

    delay(2000);
}
