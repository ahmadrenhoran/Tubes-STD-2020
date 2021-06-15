#ifndef T_H_INCLUDED
#define T_H_INCLUDED

#include <iostream>
#include <string>

#define info(P) P->info
#define next(P) P->next
#define firstj(P) P.firstj
#define firstk(P) P.firstk
#define firstr(P) P->firstr

using namespace std;

typedef  string infokota;
struct infojalan{
    string namajalan;
    string tipe;
};
typedef struct kota *adrkota;
typedef struct jalan *adrjalan;
typedef struct relasi *adrrelasi;

struct kota {
    infokota info;
    adrkota next;
    adrrelasi firstr;
};

struct relasi{
    adrrelasi next;
    adrjalan info;
};

struct jalan{
    infojalan info;
    adrjalan next;
};

struct listkota{
    adrkota firstk;
};

struct listjalan{
    adrjalan firstj;
};

void createlistkota(listkota &k);
void createlistjalan(listjalan &j);
adrkota createkota(infokota newinfo);
adrjalan createjalan(string nama, string tipe);
adrrelasi createrelasi(adrjalan p);
adrkota carikota(infokota infocari, listkota k);
void insertkota(infokota n, listkota &k);
void deletefirstkota(listkota &k, adrkota &p);
void deleteafterkota(listkota &k, adrkota prec, adrkota &p);
void deletekota(infokota namakota, listkota &k);
adrjalan carijalan(string nama, listjalan j);
void insertjalan(string nama,string tipe, listjalan &j);
void deletefirstjalan(listjalan &j, adrjalan &p);
void deleteafterjalan(listjalan &j, adrjalan prec, adrjalan &p);
void deletejalan(string namajalan, listjalan &j);
void insertlastrelasi(adrrelasi p, adrkota k);
void relasikotajalan(listkota t, listjalan ti,infokota kota, string namajalan);
void showall(listkota k);
void kotashowjalan(listkota k,listjalan j, string nama);
void jalanshowkota(listkota k,listjalan j, infokota kota);
void tipeshowjalankota(listkota k, listjalan j, string tipe);
void showjalan(listjalan j);
void showkota(listkota k);

#endif // T_H_INCLUDED
