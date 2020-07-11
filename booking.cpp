#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 10 //maksimum data queue

using namespace std;

struct Pesanan
{
    string nama;
    char paket;
    int tgl_pesan[3];
    int tgl_booking[3];
} msg;

struct Queue
{
    int data[MAX];
    int awal;
    int akhir;
} antre;
// struct Queue antre;

vector<int> que;
vector<Pesanan> list;
vector<Pesanan> psn;
vector<Pesanan> antrian;
// struct Pesanan msg;

int getOption()
{
    int input;
    system("cls");
    cout << "\nSistem booking studio foto Kelompok 7" << endl;
    cout << "=============================" << endl;
    cout << "Data Pesanan" << endl;
    cout << "=========================================================================================\n";
    cout << "|  No.  |             Nama              |    Paket    |    Tgl_pesan   |   Tgl_potret   |\n";
    cout << "=========================================================================================\n";

    for (int b = 0; b < psn.size(); b++)
    {
        cout << "|" << setw(4) << b + 1 << setw(4) << "|" << setw(16) << psn[b].nama << setw(16) << "|" << setw(7) << psn[b].paket << setw(7) << "|" << setw(5) << psn[b].tgl_pesan[2] << "/" << psn[b].tgl_pesan[1] << "/" << psn[b].tgl_pesan[0] << setw(5) << "|" << setw(5) << psn[b].tgl_booking[2] << "/" << psn[b].tgl_booking[1] << "/" << psn[b].tgl_booking[0] << setw(6) << "|\n";
    }

    cout << "=========================================================================================\n\n";
    cout << "1. Memproses antrean" << endl;
    cout << "2. Tambah data pesanan" << endl;
    cout << "3. Ubah data pesanan" << endl;
    cout << "4. Batalkan pesanan" << endl;
    cout << "5. Cari pesanan" << endl;
    cout << "6. Selesai" << endl;
    cout << "=============================" << endl;
    cout << "pilih [1-5]? : ";
    cin >> input;
    return input;
}
int digit(int nimbir)
{
    return int(log10(nimbir) + 1);
}
int condate(int a, int b, int c)
{
    // Convert both the integers to string
    string s1 = to_string(a);
    string s2;
    if (digit(b) == 1)
    {
        s2 = "0" + to_string(b);
    }
    else
    {
        s2 = to_string(b);
    }
    string s3;
    if (digit(c) == 1)
    {
        s3 = "0" + to_string(c);
    }
    else
    {
        s3 = to_string(c);
    }

    // Concatenate both strings
    string s = s1 + s2 + s3;

    // Convert the concatenated string
    // to integer
    int d = stoi(s);

    // return the formed integer
    return d;
}
void insertion_sort()
{
    //deklarasi variabel
    int i, j, k, m, z;
    antrian.clear();
    for (z = 0; z < psn.size(); z++)
    {
        antrian.push_back(psn[z]);
    } //import vector

    for (i = 1; i < antrian.size(); i++)
    { //Pengecekan mulai dari data ke-1 sampai  data ke-n
        j = i;
        while (j > 0 && condate(antrian[j - 1].tgl_booking[0], antrian[j - 1].tgl_booking[1], antrian[j - 1].tgl_booking[2]) > condate(antrian[j].tgl_booking[0], antrian[j].tgl_booking[1], antrian[j].tgl_booking[2]))
        {                                     //Bandingkan data
            swap(antrian[j - 1], antrian[j]); //tukar data
            j--;
        }
    }
}

int opsiAntre()
{
    int opsi;
    cout << "\n=============================" << endl;
    cout << "Lakukan Tindakan" << endl;
    cout << "1. Tambah Antrean" << endl;
    cout << "2. Lanjut Antrean" << endl;
    cout << "3. Kosongkan Antrean" << endl;
    cout << "4. Kembali ke Menu Utama" << endl;
    cout << "=============================" << endl;
    cout << "pilih [1-4]? : ";
    cin >> opsi;
    return opsi;
}
void init()
{
    antre.awal = -1;
    antre.akhir = -1;
}
bool full(void)
{
    if (antre.akhir == 10 - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool kosong(void)
{
    if (antre.akhir == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void checkAntre()
{
those:
    int elemen;
    cout << "\nTambah antrean dari nomor pada List Data :\n";
    cin >> elemen;
    if (elemen > list.size() | elemen == 0)
    {
        cout << "\nData yang dimasukkan tidak valid!\n";
        goto those;
    }
    else
    {
        antre.data[antre.akhir] = elemen - 1;
        antre.akhir++;
    }
}
void inQueue()
{
    if (!full())
    {
        checkAntre();
    }
    else
    {
        cout << "\nAntrean Penuh\n";
    }
}
void deQueue()
{
    int x;
    if (!kosong())
    {
        for (x = antre.awal; x < antre.akhir; x++)
        {
            antre.data[x] = antre.data[x + 1];
        }
        antre.akhir--;
    }
    else
    {
        cout << "\nAntrean Kosong\n";
    }
}
void clear()
{
    antre.awal = -1;
    antre.akhir = -1;
}
void tampilData()
{
here:
    system("cls");
    cout << "List Data " << list[0].tgl_booking[2] << "/" << list[0].tgl_booking[1] << "/" << list[0].tgl_booking[0] << endl;
    cout << setw(4) << "No." << setw(12) << "Nama" << setw(12) << "Paket" << setw(12) << "Tgl_Pesan" << setw(12) << endl;
    for (int g = 0; g < list.size(); g++)
    {
        cout << setw(2) << g + 1 << setw(12) << list[g].nama << setw(12) << list[g].paket << setw(8) << list[g].tgl_pesan[2] << "/" << list[g].tgl_pesan[1] << "/" << list[g].tgl_pesan[0] << setw(8) << endl;
    }

    if (kosong() == 0)
    {
        cout << "\nData Antrean\n";
        cout << setw(4) << "No." << setw(12) << "Nama" << setw(12) << "Paket" << setw(12) << "Tgl_Pesan" << setw(12) << endl;
        for (int q = antre.awal; q < antre.akhir; q++)
        {
            cout << setw(2) << q + 2 << setw(12) << list[antre.data[q]].nama << setw(12) << list[antre.data[q]].paket << setw(8) << list[antre.data[q]].tgl_pesan[2] << "/" << list[antre.data[q]].tgl_pesan[1] << "/" << list[antre.data[q]].tgl_pesan[0] << setw(8) << endl;
        }
    }
    else
    {
        cout << "Tidak ada antrean\n";
    }

    int pilih = opsiAntre();
    while (pilih != 4)
    {

        switch (pilih)
        {
        case 1:
            cout << "Tambah antrean" << endl;
            inQueue();
            goto here;

        case 2:
            cout << "Lanjut antrean" << endl;
            deQueue();
            goto here;

        case 3:
            cout << "Kosongkan antrean" << endl;
            clear();
            goto here;

        default:
            cout << "Pilihan tidak ditemukan" << endl;
            goto here;
        }
        cout << "Kembali ke Menu utama" << endl;
        break;
    }
}
void queue()
{
    int choose;
    cout << "\nPilih No. tanggal potret :" << endl;
    cin >> choose;
    list.clear();
    for (int n = 0; n < antrian.size(); n++)
    {
        if (condate(antrian[n].tgl_booking[0], antrian[n].tgl_booking[1], antrian[n].tgl_booking[2]) == que[choose - 1])
        {
            list.push_back(antrian[n]);
        }
    }

    tampilData();
}
void antri()
{
    system("cls");
    init();
    que.clear();
    int d = 1;
    insertion_sort();
    if (!antrian.empty())
    {
        cout << "Tanggal Potret :" << endl;
        cout << "1. " << antrian[0].tgl_booking[2] << "/" << antrian[0].tgl_booking[1] << "/" << antrian[0].tgl_booking[0] << endl;
        que.push_back(condate(antrian[0].tgl_booking[0], antrian[0].tgl_booking[1], antrian[0].tgl_booking[2]));
        for (int l = 1; l < antrian.size();)
        {
            if (condate(antrian[l].tgl_booking[0], antrian[l].tgl_booking[1], antrian[l].tgl_booking[2]) != condate(antrian[l - 1].tgl_booking[0], antrian[l - 1].tgl_booking[1], antrian[l - 1].tgl_booking[2]))
            {
                cout << d + 1 << ". " << antrian[l].tgl_booking[2] << "/" << antrian[l].tgl_booking[1] << "/" << antrian[l].tgl_booking[0] << endl;
                d = d + 1;
                que.push_back(condate(antrian[l].tgl_booking[0], antrian[l].tgl_booking[1], antrian[l].tgl_booking[2]));
            }
            l++;
        }
        queue();
    }
    else
    {
        return;
    }
}

void addData()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    cin.ignore();
    cout << "\nInput Nama : " << endl;
    getline(cin, msg.nama);
    cout << "Input Paket (tipe char) : " << endl;
    cin >> msg.paket;
    cout << "Input Tanggal Potret" << endl;
    cout << "Tanggal : ";
    cin >> msg.tgl_booking[2];
    cout << "Bulan : ";
    cin >> msg.tgl_booking[1];
    cout << "Tahun : ";
    cin >> msg.tgl_booking[0];
    msg.tgl_pesan[2] = tm.tm_mday;
    msg.tgl_pesan[1] = tm.tm_mon + 1;
    msg.tgl_pesan[0] = tm.tm_year + 1900;
    psn.push_back(msg);
}
void updateData()
{
    int no_data;
begin:
    cout << "\nEdit data pesanan no. : " << endl;
    cin >> no_data;
    if (!psn[no_data - 1].nama.empty())
    {
        cin.ignore();
        cout << "\nInput Nama : " << endl;
        getline(cin, psn[no_data - 1].nama);
        cout << "Input Paket (tipe char) : " << endl;
        cin >> psn[no_data - 1].paket;
        cout << "Input Tanggal Potret" << endl;
        cout << "Tanggal : ";
        cin >> psn[no_data - 1].tgl_booking[2];
        cout << "Bulan : ";
        cin >> psn[no_data - 1].tgl_booking[1];
        cout << "Tahun : ";
        cin >> psn[no_data - 1].tgl_booking[0];
    }
    else
    {
        cout << "data tidak ditemukan" << endl;
        goto begin;
    }
}
void delData()
{
    int no_data;
start:
    cout << "\nInput no. pesanan yang ingin dihapus : " << endl;
    cin >> no_data;
    if (!psn[no_data - 1].nama.empty())
    {
        psn.erase(psn.begin() + no_data);
    }
    else
    {
        cout << "data tidak ditemukan" << endl;
        goto start;
    }
}

int opsiSearch()
{
    int opt;
    cout << "\n=============================" << endl;
    cout << "Cari data berdasarkan" << endl;
    cout << "1. Nama" << endl;
    cout << "2. Paket" << endl;
    cout << "3. Tanggal Pesan" << endl;
    cout << "4. Tanggal Potret" << endl;
    cout << "5. Kembali ke Menu Utama" << endl;
    cout << "=============================" << endl;
    cout << "pilih [1-5]? : ";
    cin >> opt;
    return opt;
}
void searchName()
{
    string keyName;
    int number = 0;
    system("cls");
    cin.ignore();
    cout << "Input Nama yang dicari :" << endl;
    getline(cin, keyName);
    cout << "Data yang dicari" << endl;
    cout << "=========================================================================================\n";
    cout << "|  No.  |             Nama              |    Paket    |    Tgl_pesan   |   Tgl_potret   |\n";
    cout << "=========================================================================================\n";
    for (int u = 0; u < psn.size(); u++)
    {
        if (psn[u].nama == keyName)
        {
            cout << "|" << setw(4) << number + 1 << setw(4) << "|" << setw(16) << psn[u].nama << setw(16) << "|" << setw(7) << psn[u].paket << setw(7) << "|" << setw(5) << psn[u].tgl_pesan[2] << "/" << psn[u].tgl_pesan[1] << "/" << psn[u].tgl_pesan[0] << setw(5) << "|" << setw(5) << psn[u].tgl_booking[2] << "/" << psn[u].tgl_booking[1] << "/" << psn[u].tgl_booking[0] << setw(6) << "|\n";
            number++;
        }
    }
    cout << "=========================================================================================\n\n";
    if (number != 0)
    {
        cout << "Data ditemukan sebanyak " << number << " data." << endl;
    }
    else
    {
        cout << "Data tidak ditemukan" << endl;
    }
}
void searchPaket()
{
    char keyPaket;
    int numb = 0;
    system("cls");
    cin.ignore();
    cout << "Input Paket yang dicari :" << endl;
    cin >> keyPaket;
    cout << "Data yang dicari" << endl;
    cout << "=========================================================================================\n";
    cout << "|  No.  |             Nama              |    Paket    |    Tgl_pesan   |   Tgl_potret   |\n";
    cout << "=========================================================================================\n";
    for (int v = 0; v < psn.size(); v++)
    {
        if (psn[v].paket == keyPaket)
        {
            cout << "|" << setw(4) << numb + 1 << setw(4) << "|" << setw(16) << psn[v].nama << setw(16) << "|" << setw(7) << psn[v].paket << setw(7) << "|" << setw(5) << psn[v].tgl_pesan[2] << "/" << psn[v].tgl_pesan[1] << "/" << psn[v].tgl_pesan[0] << setw(5) << "|" << setw(5) << psn[v].tgl_booking[2] << "/" << psn[v].tgl_booking[1] << "/" << psn[v].tgl_booking[0] << setw(6) << "|\n";
            numb++;
        }
    }
    cout << "=========================================================================================\n\n";
    if (numb != 0)
    {
        cout << "Data ditemukan sebanyak " << numb << " data." << endl;
    }
    else
    {
        cout << "Data tidak ditemukan" << endl;
    }
}
void searchPesan()
{
    int keyPesanTanggal;
    int keyPesanBulan;
    int keyPesanTahun;
    int num = 0;
    system("cls");
    cin.ignore();
    cout << "Input Pencarian" << endl;
    cout << "Tanggal : ";
    cin >> keyPesanTanggal;
    cout << "Bulan : ";
    cin >> keyPesanBulan;
    cout << "Tahun : ";
    cin >> keyPesanTahun;
    cout << "Data yang dicari" << endl;
    cout << "=========================================================================================\n";
    cout << "|  No.  |             Nama              |    Paket    |    Tgl_pesan   |   Tgl_potret   |\n";
    cout << "=========================================================================================\n";
    for (int w = 0; w < psn.size(); w++)
    {
        if (condate(psn[w].tgl_pesan[0], psn[w].tgl_pesan[1], psn[w].tgl_pesan[2]) == condate(keyPesanTahun, keyPesanBulan, keyPesanTanggal))
        {
            cout << "|" << setw(4) << num + 1 << setw(4) << "|" << setw(16) << psn[w].nama << setw(16) << "|" << setw(7) << psn[w].paket << setw(7) << "|" << setw(5) << psn[w].tgl_pesan[2] << "/" << psn[w].tgl_pesan[1] << "/" << psn[w].tgl_pesan[0] << setw(5) << "|" << setw(5) << psn[w].tgl_booking[2] << "/" << psn[w].tgl_booking[1] << "/" << psn[w].tgl_booking[0] << setw(6) << "|\n";
            num++;
        }
    }
    cout << "=========================================================================================\n\n";
    if (num != 0)
    {
        cout << "Data ditemukan sebanyak " << num << " data." << endl;
    }
    else
    {
        cout << "Data tidak ditemukan" << endl;
    }
}
void searchBooking()
{
    int keyBookingTanggal;
    int keyBookingBulan;
    int keyBookingTahun;
    int nom = 0;
    system("cls");
    cin.ignore();
    cout << "Input Pencarian" << endl;
    cout << "Tanggal : ";
    cin >> keyBookingTanggal;
    cout << "Bulan : ";
    cin >> keyBookingBulan;
    cout << "Tahun : ";
    cin >> keyBookingTahun;
    cout << "Data yang dicari" << endl;
    cout << "=========================================================================================\n";
    cout << "|  No.  |             Nama              |    Paket    |    Tgl_pesan   |   Tgl_potret   |\n";
    cout << "=========================================================================================\n";
    for (int e = 0; e < psn.size(); e++)
    {
        if (condate(psn[e].tgl_booking[0], psn[e].tgl_booking[1], psn[e].tgl_booking[2]) == condate(keyBookingTahun, keyBookingBulan, keyBookingTanggal))
        {
            cout << "|" << setw(4) << nom + 1 << setw(4) << "|" << setw(16) << psn[e].nama << setw(16) << "|" << setw(7) << psn[e].paket << setw(7) << "|" << setw(5) << psn[e].tgl_pesan[2] << "/" << psn[e].tgl_pesan[1] << "/" << psn[e].tgl_pesan[0] << setw(5) << "|" << setw(5) << psn[e].tgl_booking[2] << "/" << psn[e].tgl_booking[1] << "/" << psn[e].tgl_booking[0] << setw(6) << "|\n";
            nom++;
        }
    }
    cout << "=========================================================================================\n\n";
    if (nom != 0)
    {
        cout << "Data ditemukan sebanyak " << nom << " data." << endl;
    }
    else
    {
        cout << "Data tidak ditemukan" << endl;
    }
}
void seqSearch()
{
    system("cls");
    char lanj;
    cout << "Pencarian data" << endl;
    int h = opsiSearch();
    while (h != 5)
    {
        switch (h)
        {
        case 1:
            cout << "*Berdasarkan nama" << endl;
            searchName();
            break;

        case 2:
            cout << "*Berdasarkan paket" << endl;
            searchPaket();
            break;
        case 3:
            cout << "*Berdasarkan tgl_pesan" << endl;
            searchPesan();
            break;
        case 4:
            cout << "*Berdasarkan tgl_potret" << endl;
            searchBooking();
            break;
        default:
            cout << "Pilihan tidak ditemukan" << endl;
            break;
        }
        cout << "\nKembali ke Menu Utama" << endl;
        break;
    }
}
int main()
{
    int pilihan = getOption();
    char lanjut;

    while (pilihan != 6)
    {

        switch (pilihan)
        {
        case 1:
            cout << "Memproses antrean" << endl;
            antri();
            break;

        case 2:
            cout << "Tambah data pesanan" << endl;
            addData();
            break;

        case 3:
            cout << "Ubah data pesanan" << endl;
            updateData();
            break;

        case 4:
            cout << "Batalkan pesanan" << endl;
            delData();
            break;
        case 5:
            seqSearch();
            break;
        default:
            cout << "Pilihan tidak ditemukan" << endl;
            break;
        }

    back:

        cout << "Lanjutkan?(y/n) : ";
        cin >> lanjut;
        if ((lanjut == 'y') | (lanjut == 'Y'))
        {
            pilihan = getOption();
        }
        else if ((lanjut == 'n') | (lanjut == 'N'))
        {
            break;
        }
        else
        {
            goto back;
        }
    }

    cout << "akhir dari program" << endl;
    return 0;
}
