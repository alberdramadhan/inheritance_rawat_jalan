#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// kelas dasar: Pasien
class Pasien {
   protected:
    string nama;
    int umur;

   public:
	int nomorAntrian = 0;
    Pasien() {
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan umur: ";
        cin >> umur;
    }
    void display() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << endl;
    }
};

// kelas turunan: PasienBaru
class PasienBaru : public Pasien {
   private:
    string diagnosa;

   public:
    PasienBaru() : Pasien() {
        cout << "Masukkan diagnosa: ";
        cin >> diagnosa;
    }
    void display() {
        Pasien::display();
        cout << "Diagnosa: " << diagnosa << endl;
        cout << "Silakan ambil nomor antrian Anda: " << ++nomorAntrian << endl;
    }
};

// kelas turunan: PasienLama
class PasienLama : public Pasien {
   private:
    string nomorAnggota;

   public:
    PasienLama() : Pasien() {
        cout << "Masukkan nomor Anggota Pasien: ";
        cin >> nomorAnggota;
    }
    void display() {
        Pasien::display();
        cout << "Nomor Anggota: " << nomorAnggota << endl;
        cout << "Silakan ambil nomor antrian Anda: " << ++nomorAntrian << endl;
    }
};


int main() {
    bool pernahBerobat;
    cout << "=================PENDAFTARAN PASIEN=====================\n";
    cout << "*PERHATIKAN ATURAN ISI*\n";
    cout << " 1 = Sudah\n 0 = Belum\n";
    cout << "\n";
    cout << "Apakah pasien ini sudah pernah berobat sebelumnya? (1/0)";
    cin >> pernahBerobat;

    if (pernahBerobat) {
        PasienLama p;
        cout << "============\n";
        cout << "Pasien Lama: " << endl;
        cout << "============\n";
        p.display();
    } else {
        PasienBaru p;
        cout << "============\n";
        cout << "Pasien Baru" << endl;
        cout << "============\n";
        p.display();
    }
char input;
   cout <<"\n";
   cout << "Apakah pasien membutuhkan surat rujukan? (y/n): ";
   cin >> input;

   if(input == 'y' || input == 'Y') {
      cout << "Pembuatan surat rujukan sedang diproses" << endl;
      for (int i = 0; i < 10; i++) {
            cout << ".";
            this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        
        cout << endl << "Segera Proses obat Pasien." << endl;
   }
   else if(input == 'n' || input == 'N') {
      cout << "Pembuatan resep obat sedang diproses" << endl;
      for (int i = 0; i < 10; i++) {
            cout << ".";
            this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        
        cout << endl << "Proses Selesai." << endl;
   }
   else {
      cout << "Input tidak valid. Silakan coba lagi." << endl;
   }
   
char input1;
    cout << "\n";
    cout <<"Pasien Menggunakan BPJS/ASURANSI? (y/n): ";
    cin >> input1;
    
    if(input1 == 'y' || input1 == 'Y') {
      cout << "Pengedukasian Pasien" << endl;
      for (int i = 0; i < 10; i++) {
            cout << ".";
            this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        
        cout << endl << "Proses selesai." << endl;
   }
   else if(input1 == 'n' || input1 == 'N') {
      cout << "Pembayaran Rawat Jalan" << endl;
      for (int i = 0; i < 10; i++) {
            cout << ".";
            this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        
        cout << endl << "Proses Selesai." << endl;
   }
   else {
      cout << "Input tidak valid. Silakan coba lagi." << endl;
   }
   

    return 0;
}
