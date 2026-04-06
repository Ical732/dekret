#include "scenario.hpp"

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

Skenario* daftarSkenario() {
    return skenarioList;
}

int jumlahSkenario() {
    return 48;
}