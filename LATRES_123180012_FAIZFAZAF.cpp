#include <iostream>
#include <string.h>
#include <malloc.h>
#define True 1
#define False 0
using namespace std;


typedef struct typequeue *typeptr;
struct typeinfo{
	int umur;
    string nama;
    string keluhan;
    int antrian;
};
struct typequeue{
    typeinfo pasien;
    typeptr next;
};
typeptr qdepan, qbelakang,bantu;
void buatqueue();
int queuekosong();
void enqueue(typeinfo IB);
void dequeue();
void cetakqueue();
int no = 1;
int total = 0;
int pilih;
char tambah, balik;

int main()
{
	typeptr data;
	buatqueue();
	cout<<"MENU"<<endl;
	cout<<"1. Input Data Pasien"<<endl;
	cout<<"2. panggil pasien "<<endl;
	cout<<"Masukan Pilihan = ";cin>>pilih;
	switch (pilih){
	 case 1:
			system("CLS");
			do{
			system("CLS");\
	        cout << "*** PENDAFTARAN ***\n\n";
            cout << "Nomor Antrian   : " << no << endl;
            //data->pasien.antrian = no;
            cin.ignore();
            cout << "Nama\t : ";
            cout<< "Umur Pasien \t : ";
            cin>>data->pasien.umur;
            getline(cin,data->pasien.nama);
            cout << "Keluhan\t : ";
            getline(cin,data->pasien.keluhan);
            enqueue(data->pasien);
            no++;
            total++;
            cout<<"tambah data ";cin>>tambah;
		}while (tambah=='y'||tambah=='Y');
            cout << "Kembali ke menu(y/n) ? ";
            cin >> balik;
            if (balik=='y'||balik=='Y')
                main();
            else
                exit(0);
        break;
	case 2:
            system("CLS");
            
            dequeue();
            cout << "Kembali ke menu(y/n) ? ";
            cin >> balik;
            if (balik=='y'||balik=='Y')
                main();
            else
                exit(0);
		break;
}
}

void buatqueue(){
    qdepan=(typequeue *) malloc(sizeof(typequeue));
    qdepan=NULL;
    qbelakang=qdepan;
}
int queuekosong(){
    if(qdepan==NULL)
        return(True);
    else
        return(False);
}
void enqueue(typeinfo IB){
    typeptr NB;
    NB=(typequeue *) malloc(sizeof(typequeue));
    NB->pasien=IB;
    if (qdepan==NULL){
        qdepan=NB;
        qbelakang=NB;
    }
    else{
        qbelakang->next=NB;
        qbelakang=NB;
        qbelakang->next=NULL;
  }
}
void dequeue(){
    typeptr hapus;
    if (queuekosong()){
        cout << "Queue masih kosong !";
    }
    else{
		cout << "Nomor Antrian "<<hapus->pasien.antrian;
		cout << "Nama "<<hapus->pasien.nama;
        hapus=qdepan;
        qdepan=hapus->next; 
        free(hapus); }
}
void cetakqueue(){
    typeptr bantu;
    bantu=qdepan;
    if (queuekosong()){
        cout << "Tidak Ada Antrian!";
    }
    else{
        cout << bantu->pasien.antrian << " "<< bantu->pasien.nama << " "<<bantu->pasien.keluhan<<endl;
    }
}
