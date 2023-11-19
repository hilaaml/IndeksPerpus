#include <iostream>
#include <string>
using namespace std;

const int max_books = 100;
string username, password, judul[max_books], penulis[max_books];
int pilihan, stok[max_books], bookCount = 0, bookNumber, totalStock = 0;

int main() {
    cout << "Selamat Datang di Indeks Perpustakaan\nSilahkan Login\n\n";

login:
    cout << "Username : "; cin >> username;
    cout << "Password : "; cin >> password;

    if ((username == "kel7") && (password == "kel7")) {
        system("cls");
        cout << "Selamat Anda Berhasil Login di Indeks Perpustakaan \n\n";
    }
    else {
        system("cls");
        cout << "Username dan Password Salah, Silahkan Coba Kembali!\n\n";
        goto login;
    }

menu:
    cout << "Daftar Menu: " << endl;
    cout << "1. Input buku \t 4. Pengembalian" << endl;
    cout << "2. Daftar buku \t 5. Laporan" << endl;
    cout << "3. Peminjaman \t 7. Keluar" << endl;
    cout << "6. Pencarian Buku atau Penulis";
    cout << "\nPilih menu yang Anda inginkan: "; cin >> pilihan;
    system("cls");

    if (pilihan == 1) {
        cout << "Masukkan judul buku\t: "; cin >> judul[bookCount];
        cout << "Masukkan nama penulis\t: "; cin >> penulis[bookCount];
        cout << "Masukkan jumlah stok\t: "; cin >> stok[bookCount];

        bookCount++;

        cout << "Berhasil menambahkan buku \n\n";
        goto menu;
    }
    else if (pilihan == 2) {
        if (bookCount == 0) {
            cout << "Maaf, untuk saat ini belum ada buku yang tersedia\n\n";
        }
        else {
            cout << "Daftar buku yang tersedia:\n";
            cout << "No.\tJudul\tPenulis\tStok" << endl;
            for (int i = 0; i < bookCount; i++) {
                cout << i + 1 << ".\t" << judul[i] << "\t" << penulis[i] << "\t" << stok[i] << endl;
            }
        }
        cout << endl;
        goto menu;
    }
    else if (pilihan == 3) {
        cout << "Masukkan nomor buku yang ingin dipinjam: "; cin >> bookNumber;

        if (bookNumber < 1 || bookNumber > bookCount) {
            cout << "Nomor buku yang Anda masukkan salah. Silakan coba lagi.\n\n";
            goto menu;
        }
        if (stok[bookNumber - 1] == 0) {
            cout << "Maaf, stok buku tersebut saat ini kosong. Silakan coba lagi nanti.\n\n";
            goto menu;
        }

        stok[bookNumber - 1]--;
        cout << "Buku berhasil dipinjam. \nJumlah stok saat ini: " << stok[bookNumber - 1] << ".\n\n";

        goto menu;

    }
    else if (pilihan == 4) {
        cout << "Masukkan nomor buku yang ingin dikembalikan: "; cin >> bookNumber;

        if (bookNumber < 1 || bookNumber > bookCount) {
            cout << "Nomor buku yang Anda masukkan salah. Silakan coba lagi.\n\n";
            goto menu;
        }

        stok[bookNumber - 1]++;
        cout << "Buku berhasil dikembalikan. \nJumlah stok saat ini: " << stok[bookNumber - 1] << ".\n\n";

        goto menu;
    }
    else if (pilihan == 5) {
        for (int i = 0; i < bookCount; i++) {
            totalStock += stok[i];
        }
        cout << "Total stok saat ini: " << totalStock << ".\n\n";
        goto menu;
    }
    else if (pilihan == 6) {
        string searchQuery;
        cout << "Masukkan judul buku atau nama penulis: "; cin >> searchQuery;
        // Search by judul
        for (int i = 0; i < bookCount; i++) {
            if (searchQuery == judul[i] || searchQuery == penulis[i]) {
                cout << "No.\tJudul\tPenulis\tStok" << endl;
                cout << i + 1 << ".\t" << judul[i] << "\t" << penulis[i] << "\t" << stok[i] << "\n\n";
                goto menu;
            }
        }
    }
    else if (pilihan == 7) {
        cin.ignore();
        cout << "Terima kasih telah menggunakan Indeks Perpustakaan.\n\n";
    }
    else {
        cin.ignore();
        cout << "Menu yang Anda masukkan salah. Silakan coba lagi.\n\n";
        system("cls");
        goto menu;
    }
}
