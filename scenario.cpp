#include "scenario.hpp"

static Skenario skenarioList[20] = 
{
    {
        "Perusahaan swasta meminta izin untuk membuka lahan sawit di hutan lindung.",
        {"Izinkan", +10, -5, 0, -5},
        {"Tolak", -10, 0, 0, +5}
    },
    {
        "Harga bahan bakar naik akibat krisis global.",
        {"Naikkan harga BBM", +10, -10, 0, +5},
        {"Tahan harga dengan subsidi", -10, +5, 0, -5}
    },

    {
        "Demo besar mahasiswa menuntut reformasi kebijakan.",
        {"Akomodasi tuntutan", -5, +10, 0, 0},
        {"Kerahkan aparat", 0, -10, +10, 0}
    },

    {
        "Investor asing ingin membangun pabrik besar di daerah.",
        {"Setujui investasi", +10, -5, 0, -5},
        {"Tolak demi lingkungan", -5, +5, 0, +10}
    },

    {
        "Kasus korupsi besar terungkap di pemerintahan.",
        {"Usut tuntas", -5, +10, -5, 0},
        {"Tutup kasus demi stabilitas", +5, -10, 0, 0}
    },

    {
        "Lonjakan pengangguran terjadi akibat otomatisasi industri.",
        {"Latih ulang tenaga kerja", -10, +10, 0, 0},
        {"Biarkan pasar menyesuaikan", +5, -10, 0, 0}
    },

    {
        "Kebakaran hutan besar terjadi di Kalimantan.",
        {"Tindak tegas perusahaan", -5, +5, 0, +10},
        {"Fokus pemulihan cepat ekonomi", +10, 0, 0, -10}
    },

    {
        "Viral kasus pencemaran sungai oleh limbah pabrik.",
        {"Tutup pabrik", -10, +10, 0, +10},
        {"Berikan sanksi ringan", +5, -5, 0, -5}
    },

    {
        "Tekanan publik untuk menaikkan gaji ASN.",
        {"Naikkan gaji", -10, +10, 0, 0},
        {"Tunda kenaikan", +5, -5, 0, 0}
    },

    {
        "Ancaman konflik di perbatasan meningkat.",
        {"Perkuat militer", -5, 0, +10, 0},
        {"Diplomasi damai", 0, +5, -5, 0}
    },

    {
        "Startup lokal meminta subsidi untuk berkembang.",
        {"Berikan subsidi", -5, +5, 0, 0},
        {"Biarkan kompetisi bebas", +5, -5, 0, 0}
    },

    {
        "Kasus kebocoran data besar terjadi di platform digital.",
        {"Perketat regulasi", -5, +10, 0, 0},
        {"Biarkan perusahaan tangani sendiri", +5, -5, 0, 0}
    },

    {
        "Viral influencer mempromosikan gaya hidup konsumtif.",
        {"Batasi iklan digital", -5, +5, 0, 0},
        {"Biarkan kebebasan pasar", +5, -5, 0, 0}
    },

    {
        "Harga pangan melonjak drastis di pasar.",
        {"Impor pangan", +5, +5, 0, -5},
        {"Perkuat produksi lokal", -5, +5, 0, +5}
    },

    {
        "Kasus kriminal meningkat di kota besar.",
        {"Perbanyak patroli", -5, 0, +10, 0},
        {"Program sosial masyarakat", -5, +10, -5, 0}
    },

    {
        "Proyek Ibu Kota Nusantara menuai pro dan kontra.",
        {"Lanjutkan proyek", +10, -5, 0, -5},
        {"Tunda proyek", -10, +5, 0, +5}
    },

    {
        "Tenaga kerja asing meningkat di sektor industri.",
        {"Batasi TKA", -5, +5, 0, 0},
        {"Izinkan untuk investasi", +5, -5, 0, 0}
    },

    {
        "Serangan siber ke sistem pemerintah meningkat.",
        {"Perkuat keamanan digital", -5, 0, +5, 0},
        {"Kerja sama dengan pihak luar negeri", +5, 0, 0, 0}
    },

    {
        "Konten hoaks menyebar luas di media sosial.",
        {"Perketat regulasi media", -5, +10, 0, 0},
        {"Edukasi masyarakat", 0, +5, 0, 0}
    },
    
    {
        "Kasus stunting masih tinggi di beberapa daerah.",
        {"Program bantuan gizi besar-besaran", -10, +10, 0, 0},
        {"Fokus edukasi jangka panjang", -5, +5, 0, 0}
    }
};

Skenario* daftarSkenario() {
    return skenarioList;
}

int jumlahSkenario() {
    return 20;
}