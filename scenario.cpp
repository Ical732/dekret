#include "scenario.hpp"
#include "game.hpp"

static Skenario skenarioList[48] = 
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
    },

    {
        "Harga listrik naik akibat krisis energi.",
        {"Naikkan tarif listrik", +10, -10, 0, -5},
        {"Subsidi listrik", -10, +5, 0, 0}
    },

    {
        "Protes buruh menuntut kenaikan upah minimum.",
        {"Naikkan UMR", -5, +10, 0, 0},
        {"Tolak tuntutan", +5, -10, 0, 0}
    },

    {
        "Kasus pelanggaran HAM masa lalu kembali mencuat.",
        {"Buka investigasi", -5, +10, -5, 0},
        {"Tutup isu", +5, -10, 0, 0}
    },

    {
        "Krisis air bersih melanda beberapa daerah.",
        {"Bangun infrastruktur air", -10, +5, 0, +10},
        {"Distribusi darurat", -5, +5, 0, 0}
    },

    {
        "Industri lokal kalah saing dengan produk impor.",
        {"Batasi impor", -5, +5, 0, 0},
        {"Biarkan pasar bebas", +5, -5, 0, 0}
    },

    {
        "Kasus pandemi baru mulai menyebar.",
        {"Lockdown wilayah", -10, +5, 0, +5},
        {"Biarkan aktivitas normal", +5, -10, 0, -5}
    },

    {
        "Tekanan internasional untuk mengurangi emisi karbon.",
        {"Kurangi emisi drastis", -5, +5, 0, +10},
        {"Abaikan tekanan", +5, -5, 0, -10}
    },

    {
        "Krisis perumahan di kota besar.",
        {"Bangun rumah subsidi", -10, +10, 0, 0},
        {"Serahkan ke swasta", +5, -5, 0, 0}
    },

    {
        "Demonstrasi anti pemerintah semakin besar.",
        {"Dialog dengan massa", -5, +10, 0, 0},
        {"Tindak tegas", 0, -10, +10, 0}
    },

    {
        "Harga emas melonjak, investor panik.",
        {"Stabilkan pasar", -5, +5, 0, 0},
        {"Biarkan mekanisme pasar", +5, -5, 0, 0}
    },

    {
        "Kasus mafia tanah merugikan masyarakat.",
        {"Berantas mafia", -5, +10, -5, 0},
        {"Diamkan demi stabilitas", +5, -10, 0, 0}
    },

    {
        "Teknologi AI mulai menggantikan banyak pekerjaan.",
        {"Regulasi AI", -5, +10, 0, 0},
        {"Dukung inovasi penuh", +5, -5, 0, 0}
    },

    {
        "Krisis transportasi umum di kota besar.",
        {"Bangun transportasi massal", -10, +10, 0, +5},
        {"Biarkan swasta berkembang", +5, -5, 0, 0}
    },

    {
        "Kasus kekerasan meningkat di masyarakat.",
        {"Perketat hukum", -5, 0, +10, 0},
        {"Program edukasi sosial", -5, +10, 0, 0}
    },

    {
        "Ketergantungan impor pangan meningkat.",
        {"Perkuat pertanian lokal", -5, +5, 0, +5},
        {"Impor besar-besaran", +10, 0, 0, -5}
    },

    {
        "Skandal pajak besar melibatkan perusahaan besar.",
        {"Tindak tegas perusahaan", -5, +10, -5, 0},
        {"Lindungi investor", +10, -10, 0, 0}
    },

    {
        "Penebangan liar meningkat di hutan.",
        {"Tindak tegas pelaku", -5, +5, 0, +10},
        {"Biarkan demi ekonomi", +10, 0, 0, -10}
    },

    {
        "Krisis pendidikan akibat kekurangan guru.",
        {"Rekrut guru besar-besaran", -10, +10, 0, 0},
        {"Gunakan sistem online", -5, +5, 0, 0}
    },

    {
        "Nilai mata uang melemah drastis.",
        {"Intervensi pasar", -5, +5, 0, 0},
        {"Biarkan pasar menyesuaikan", +5, -5, 0, 0}
    },

    {
        "Gerakan separatis muncul di daerah tertentu.",
        {"Pendekatan militer", -5, -5, +10, 0},
        {"Dialog damai", 0, +10, -5, 0}
    },

    {
        "Harga bahan bakar naik drastis akibat krisis global.",
        {"Naikkan subsidi", -10, +10, 0, -5},
        {"Biarkan harga pasar", +10, -10, 0, +5}
    },

    {
        "Kelompok masyarakat menuntut reformasi pendidikan nasional.",
        {"Setujui reformasi", -5, +15, 0, +5},
        {"Tolak perubahan", +5, -10, 0, 0}
    },

    {
        "Negara tetangga meningkatkan aktivitas militer di perbatasan.",
        {"Perkuat militer", -10, -5, +15, 0},
        {"Diplomasi damai", +5, +5, -5, 0}
    },

    {
        "Terjadi kebakaran hutan besar di beberapa wilayah.",
        {"Kirim bantuan besar", -10, +5, 0, +15},
        {"Biarkan daerah tangani sendiri", +5, -5, 0, -15}
    },
    {
        "Investor asing ingin membangun pabrik besar di Indonesia.",
        {"Terima investasi", +15, +5, 0, -10},
        {"Tolak demi lingkungan", -10, 0, 0, +15}
    },
    {
        "Terjadi demonstrasi besar menuntut transparansi pemerintah.",
        {"Buka transparansi", -5, +15, 0, 0},
        {"Batasi informasi", +5, -15, +5, 0}
    },
    {
        "Program wajib militer diusulkan untuk meningkatkan pertahanan.",
        {"Terapkan wajib militer", -5, -5, +15, 0},
        {"Tolak usulan", +5, +5, -10, 0}
    },
    {
        "Teknologi energi terbarukan mulai berkembang pesat.",
        {"Investasi besar", -10, +5, 0, +15},
        {"Tetap gunakan energi lama", +10, 0, 0, -10}
    }
};

Peristiwa* buatTreeMiliter()
{
    Peristiwa* root = new Peristiwa{
        "Para jenderal mengeluhkan anggaran militer.",

        {"Tambah anggaran", -10, 0, +10, 0},
        {"Tolak permintaan", +5, -5, -10, 0},

        nullptr,
        nullptr
    };

    Peristiwa* dana = new Peristiwa{
        "Anda memberi tambahan dana militer.",

        {"Dukung penuh", 0, +5, +10, 0},
        {"Awasi penggunaan dana", -10, -5, -5, 0},

        nullptr,
        nullptr
    };

    Peristiwa* tolak = new Peristiwa{
        "Anda menolak permintaan mereka.",

        {"Lakukan reformasi", 0, +5, 0, 0},
        {"Abaikan keluhan", 0, -10, -20, 0},

        nullptr,
        nullptr
    };

    Peristiwa* loyal = new Peristiwa{
        "Militer menjadi lebih loyal.",

        {"Lanjut", 0, 0, 0, 0},
        {"Lanjut", 0, 0, 0, 0},

        nullptr,
        nullptr
    };

    Peristiwa* korupsi = new Peristiwa{
        "Sebagian dana disalahgunakan.",

        {"Lanjut", 0, 0, 0, 0},
        {"Lanjut", 0, 0, 0, 0},

        nullptr,
        nullptr
    };

    Peristiwa* reformasi = new Peristiwa{
        "Militer menerima keputusan Anda.",

        {"Lanjut", 0, 0, 0, 0},
        {"Lanjut", 0, 0, 0, 0},

        nullptr,
        nullptr
    };

    Peristiwa* kudeta = new Peristiwa{
        "Sebagian petinggi mulai merencanakan kudeta.",

        {"Lanjut", 0, 0, 0, 0},
        {"Lanjut", 0, 0, 0, 0},

        nullptr,
        nullptr
    };

    root->pilihan_1 = dana;
    root->pilihan_2 = tolak;

    dana->pilihan_1 = loyal;
    dana->pilihan_2 = korupsi;

    tolak->pilihan_1 = reformasi;
    tolak->pilihan_2 = kudeta;

    return root;
}

Peristiwa* buatTreeMasyarakat()
{
    Peristiwa* root = new Peristiwa{
        "Gelombang demonstrasi menuntut reformasi sosial terjadi di berbagai kota.",

        {"Dengarkan tuntutan", -5, +10, 0, 0},
        {"Kerahkan aparat", 0, -10, +10, 0},

        nullptr,
        nullptr
    };

    Peristiwa* dialog = new Peristiwa{
        "Perwakilan demonstran bersedia berdialog.",

        {"Bentuk tim reformasi", -10, +10, 0, 0},
        {"Janji tanpa tindakan", 0, -5, 0, 0},

        nullptr,
        nullptr
    };

    Peristiwa* represi = new Peristiwa{
        "Aparat berhasil membubarkan demonstrasi.",

        {"Perketat pengawasan", 0, -10, +5, 0},
        {"Longgarkan setelah situasi tenang", 0, +5, -5, 0},

        nullptr,
        nullptr
    };

    Peristiwa* sukses = new Peristiwa{
        "Kepercayaan publik meningkat.",
        {"Lanjut",0,0,0,0},
        {"Lanjut",0,0,0,0},
        nullptr,nullptr
    };

    Peristiwa* kecewa = new Peristiwa{
        "Masyarakat mulai kecewa pada pemerintah.",
        {"Lanjut",0,0,0,0},
        {"Lanjut",0,0,0,0},
        nullptr,nullptr
    };

    Peristiwa* takut = new Peristiwa{
        "Situasi terkendali, tetapi rakyat hidup dalam ketakutan.",
        {"Lanjut",0,0,0,0},
        {"Lanjut",0,0,0,0},
        nullptr,nullptr
    };

    Peristiwa* damai = new Peristiwa{
        "Ketegangan sosial mulai mereda.",
        {"Lanjut",0,0,0,0},
        {"Lanjut",0,0,0,0},
        nullptr,nullptr
    };

    root->pilihan_1 = dialog;
    root->pilihan_2 = represi;

    dialog->pilihan_1 = sukses;
    dialog->pilihan_2 = kecewa;

    represi->pilihan_1 = takut;
    represi->pilihan_2 = damai;

    return root;
}

Peristiwa* buatTreeEkonomi()
{
    Peristiwa* root = new Peristiwa{
        "Perekonomian melambat dan investor mulai khawatir.",

        {"Berikan insentif bisnis", +10, -5, 0, -5},
        {"Fokus bantuan rakyat", -10, +10, 0, 0},

        nullptr,
        nullptr
    };

    Peristiwa* investor = new Peristiwa{
        "Investor merespons kebijakan Anda.",

        {"Potong pajak perusahaan", +10, -5, 0, -5},
        {"Batasi insentif", -5, +5, 0, 0},

        nullptr,
        nullptr
    };

    Peristiwa* bantuan = new Peristiwa{
        "Program bantuan sosial mulai berjalan.",

        {"Perluas program", -10, +10, 0, 0},
        {"Batasi anggaran", +5, -5, 0, 0},

        nullptr,
        nullptr
    };

    Peristiwa* boom = new Peristiwa{
        "Investasi meningkat pesat.",
        {"Lanjut",0,0,0,0},
        {"Lanjut",0,0,0,0},
        nullptr,nullptr
    };

    Peristiwa* stagnan = new Peristiwa{
        "Ekonomi tetap stagnan.",
        {"Lanjut",0,0,0,0},
        {"Lanjut",0,0,0,0},
        nullptr,nullptr
    };

    Peristiwa* populer = new Peristiwa{
        "Program sosial mendapat dukungan luas.",
        {"Lanjut",0,0,0,0},
        {"Lanjut",0,0,0,0},
        nullptr,nullptr
    };

    Peristiwa* defisit = new Peristiwa{
        "Defisit anggaran mulai membesar.",
        {"Lanjut",0,0,0,0},
        {"Lanjut",0,0,0,0},
        nullptr,nullptr
    };

    root->pilihan_1 = investor;
    root->pilihan_2 = bantuan;

    investor->pilihan_1 = boom;
    investor->pilihan_2 = stagnan;

    bantuan->pilihan_1 = populer;
    bantuan->pilihan_2 = defisit;

    return root;
}

Peristiwa* buatTreeLingkungan()
{
    Peristiwa* root = new Peristiwa{
        "Aktivis lingkungan menyoroti kerusakan hutan yang semakin parah.",

        {"Lindungi kawasan hutan", -5, +5, 0, +10},
        {"Prioritaskan ekonomi", +10, -5, 0, -10},

        nullptr,
        nullptr
    };

    Peristiwa* konservasi = new Peristiwa{
        "Program konservasi mulai berjalan.",

        {"Perluas kawasan lindung", -5, +5, 0, +10},
        {"Cari kompromi dengan industri", +5, 0, 0, +5},

        nullptr,
        nullptr
    };

    Peristiwa* eksploitasi = new Peristiwa{
        "Perusahaan meminta izin tambahan.",

        {"Setujui", +10, -5, 0, -10},
        {"Batasi ekspansi", -5, +5, 0, +5},

        nullptr,
        nullptr
    };

    Peristiwa* hijau = new Peristiwa{
        "Kondisi lingkungan membaik.",
        {"Lanjut",0,0,0,0},
        {"Lanjut",0,0,0,0},
        nullptr,nullptr
    };

    Peristiwa* seimbang = new Peristiwa{
        "Pertumbuhan dan konservasi relatif seimbang.",
        {"Lanjut",0,0,0,0},
        {"Lanjut",0,0,0,0},
        nullptr,nullptr
    };

    Peristiwa* rusak = new Peristiwa{
        "Kerusakan lingkungan meningkat drastis.",
        {"Lanjut",0,0,0,0},
        {"Lanjut",0,0,0,0},
        nullptr,nullptr
    };

    Peristiwa* terkendali = new Peristiwa{
        "Ekspansi industri berhasil dikendalikan.",
        {"Lanjut",0,0,0,0},
        {"Lanjut",0,0,0,0},
        nullptr,nullptr
    };

    root->pilihan_1 = konservasi;
    root->pilihan_2 = eksploitasi;

    konservasi->pilihan_1 = hijau;
    konservasi->pilihan_2 = seimbang;

    eksploitasi->pilihan_1 = rusak;
    eksploitasi->pilihan_2 = terkendali;

    return root;
}

static EventKhusus daftarEvent[] =
{
    {12, buatTreeMiliter},
    {24, buatTreeMasyarakat},
    {36, buatTreeEkonomi},
    {48, buatTreeLingkungan}
};

int jumlahEventKhusus()
{
    return sizeof(daftarEvent) / sizeof(daftarEvent[0]);
}

EventKhusus* ambilEventKhusus()
{
    return daftarEvent;
}

Skenario* daftarSkenario() {
    return skenarioList;
}

int jumlahSkenario() {
    return 48;
}