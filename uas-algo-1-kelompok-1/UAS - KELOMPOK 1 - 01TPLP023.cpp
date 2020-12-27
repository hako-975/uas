#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>

using namespace std;

void tampil(string mata_kuliah, 
			int sks, 
			string nim, 
			string nama_mhs, 
			float jumlah_kehadiran, 
			float nilai_tugas, 
			float nilai_uts, 
			float nilai_uas, 
			float nilai_angka, 
			char grade);

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void cetak(int a, int b, char *teks)
{
	gotoxy(a, b);
	cout<<teks;
}

main()
{
	// mendeklarasi variabel
	string nim;
	string nama_mhs;
	string mata_kuliah;
	int sks;
	float jumlah_kehadiran;
	float nilai_tugas;
	float nilai_uts;
	float nilai_uas;
	
	float nilai_angka;
	char grade;
	
	do
	{	
		// input nim
		gotoxy(2,1);
		cout<<"Masukkan NIM : ";
		cin>>nim;
		
		// meng-ignore karakter agar dapat menginput getline pd baris berikutnya
		cin.ignore(256, '\n');
		
		// jika nim bernilai negatif, keluar aplikasi
		if(nim < "0")
		{
			return 0;
		}
		
		// input nama_mhs
		gotoxy(2,2);
		cout << "Masukkan Nama Mahasiswa : ";
		getline(cin, nama_mhs);
		
		// input mata_kuliah
		gotoxy(2,3);
		cout << "Masukkan Mata Kuliah : ";
		getline(cin, mata_kuliah);
	
		// input sks
		gotoxy(2,4);
		cout<<"Masukkan SKS : ";
		cin>>sks;
	
		// input jumlah_kehadiran
		gotoxy(2,5);
		cout<<"Masukkan Jumlah Kehadiran : ";
		cin>>jumlah_kehadiran;
	
		// input nilai_tugas
		gotoxy(2,6);
		cout<<"Masukkan Nilai Tugas : ";
		cin>>nilai_tugas;
	
		// input nilai_uts
		gotoxy(2,7);
		cout<<"Masukkan Nilai UTS : ";
		cin>>nilai_uts;
	
		// input nilai_uas
		gotoxy(2,8);
		cout<<"Masukkan Nilai UAS : ";
		cin>>nilai_uas;
		
		if(jumlah_kehadiran && nilai_tugas && nilai_uts && nilai_uas > 0)
		{
			/* 
			untuk yg jml hadir, 
			jadi jika jml hadir kurang dari empat, maka nilainya otomatis berkurang
			contoh: 2 - 4 = -2 * 10 = -20 * 10% = -2
			nilai akan ditambahkan -2			    
			*/
			nilai_angka = (((jumlah_kehadiran - 4) * 10) * 0.1) + 
						  (nilai_tugas * 0.2) + 
						  (nilai_uts * 0.3) + 
						  (nilai_uas * 0.4);
						  
			if(nilai_angka > 80)
			{
				grade = 'A';
			}
			else if(nilai_angka >= 70 && nilai_angka < 80)
			{
				grade = 'B';
			}
			else if(nilai_angka >= 60 && nilai_angka < 70)
			{
				grade = 'C';
			}
			else if(nilai_angka >= 50 && nilai_angka < 60)
			{
				grade = 'D';
			}
			else if(nilai_angka < 50)
			{
				grade = 'E';
			}
		}
		else 
		{
			grade = 'D';
		}		
		tampil(mata_kuliah, 
			sks, 
			nim, 
			nama_mhs, 
			jumlah_kehadiran, 
			nilai_tugas, 
			nilai_uts, 
			nilai_uas, 
			nilai_angka, 
			grade);	
		
		cout<<endl;
		system("pause");
		system("cls");
	} 
	// jika nim diatas angka 0, maka lakukan perulangan
	while(nim > "0");
	
	return 0;
}

void tampil(string mata_kuliah, 
			int sks, 
			string nim, 
			string nama_mhs, 
			float jumlah_kehadiran, 
			float nilai_tugas, 
			float nilai_uts, 
			float nilai_uas, 
			float nilai_angka, 
			char grade)
{
	cetak(4,11,"NAMA MATA KULIAH : ");
	cout<<mata_kuliah;
	cetak(4,12,"SKS");
	cetak(20,12, " : ");
	cout<<sks;
	cetak(4,13,"===============================================================================================");
	cetak(4,14,"|");
	cetak(10,14,"NIM");
	cetak(19,14,"|");
	cetak(27,14,"N A M A");
	cetak(44,14,"|");
	cetak(46,14,"JML HADIR");
	cetak(56,14,"|");
	cetak(58,14,"TUGAS");
	cetak(64,14,"|");
	cetak(66,14,"UTS");
	cetak(70,14,"|");
	cetak(72,14,"UAS");
	cetak(76,14,"|");
	cetak(78,14,"NILAI ANGKA");
	cetak(90,14,"|");
	cetak(92,14,"GRADE");
	cetak(98,14,"|");
	cetak(4,15,"===============================================================================================");
	cout<<endl;
	cetak(4,16,"|");
	cetak(6,16,""); cout<<nim;
	
	cetak(19,16,"|");
	cetak(21,16,""); cout<<nama_mhs;
	
	cetak(44,16,"|");
	cetak(46,16,""); cout<<jumlah_kehadiran;
	
	cetak(56,16,"|");
	cetak(58,16,""); cout<<nilai_tugas;
	
	cetak(64,16,"|");
	cetak(66,16,""); cout<<nilai_uts;
	
	cetak(70,16,"|");
	cetak(72,16,""); cout<<nilai_uas;
	
	cetak(76,16,"|");
	cetak(78,16,""); cout<<nilai_angka;
	
	cetak(90,16,"|");
	cetak(92,16,""); cout<<grade;
	
	cetak(98,16,"|");
	cetak(4,17,"===============================================================================================");
	cout<<endl;
}


