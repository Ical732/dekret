#include "scenario.hpp"

static Skenario skenarioList[60] = 
{
    {
        "Perusahaan swasta meminta izin untuk membuka lahan sawit di hutan lindung.",
        {"Izinkan", +10, -5, 0, 5},
        {"Tolak", -10, 0, 0, +5}
    },
};

Skenario* daftarSkenario() {
    return skenarioList;
}

int jumlahSkenario() {
    return 60;
}