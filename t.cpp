#include "t.h"

void createlistkota(listkota &k)
{
    firstk(k) = NULL;
}

void createlistjalan(listjalan &j)
{
    firstj(j) = NULL;
}

adrkota createkota(infokota newinfo)
{
    adrkota p = new kota;
    info(p) = newinfo;
    firstr(p) =  NULL;
    next(p) = NULL;

    return p;
}

adrjalan createjalan(string nama, string tipe)
{
    adrjalan p = new jalan;
    info(p).namajalan = nama;
    info(p).tipe = tipe;
    next(p) = NULL;

    return p;
}

adrrelasi createrelasi(adrjalan p)
{
    adrrelasi r = new relasi;
    info(r) = p;
    next(r) = NULL;

    return r;
}

adrkota carikota(infokota infocari, listkota k)
{
    if(firstk(k) == NULL) {
        return NULL;
    } else {
        adrkota p = firstk(k);
        while(next(p) != NULL && info(p) != infocari) {
            p = next(p);
        }
        if (info(p) == infocari) {
            return p;
        } else {
            return NULL;
        }
    }

}
void insertkota(infokota n, listkota &k)
{
    adrkota p = createkota(n);
    if(firstk(k) == NULL) {
        firstk(k) = p;
    } else {
        adrkota q = firstk(k);
        while(next(q) != NULL) {
            q = next(q);
        }
        next(q) = p;
    }
}

void deletefirstkota(listkota &k, adrkota &p)
{
    if(firstk(k) == NULL) {
        cout<<"Data Kosong"<<endl;
    } else {
        p = firstk(k);
        firstr(p) = NULL;
        firstk(k) = next(p);
        next(p) = NULL;
    }
}

void deleteafterkota(listkota &k, adrkota prec, adrkota &p)
{
    p = next(prec);
    next(prec) = next(p);
    firstr(p) = NULL;
    next(p) = NULL;
}

void deletekota(infokota namakota, listkota &k)
{
    adrkota temp; adrkota prec;
    adrkota p = carikota(namakota,k);
    if(p == NULL) {
        cout<<"Kota Tidak ada"<<endl;
    } else {
        if(p == firstk(k)) {
            deletefirstkota(k,prec);
        } else {
            prec = firstk(k);
            while (next(prec) != p) {
                prec = next(prec);
            }
            deleteafterkota(k,prec,temp);
        }
    }
}

adrjalan carijalan(string nama, listjalan j)
{
    if(firstj(j) == NULL) {
        return NULL;
    } else {
        adrjalan p = firstj(j);
        while(next(p) != NULL && info(p).namajalan != nama) {
            p = next(p);
        }
        if (info(p).namajalan == nama) {
            return p;
        } else {
            return NULL;
        }
    }
}
void insertjalan(string nama,string tipe, listjalan &j)
{
    adrjalan p = createjalan(nama,tipe);
    if(firstj(j) == NULL) {
        firstj(j) = p;
    } else {
        next(p) = firstj(j);
        firstj(j) = p;
    }
}

void deletefirstjalan(listjalan &j, adrjalan &p)
{
     if(firstj(j) == NULL) {
        cout<<"Data Kosong"<<endl;
    } else {
        p = firstj(j);
        firstj(j) = next(p);
        next(p) = NULL;
    }
}

void deleteafterjalan(listjalan &j, adrjalan prec, adrjalan &p)
{
    p = next(prec);
    next(prec) = next(p);
    next(p) = NULL;
}

void deletejalan(string namajalan, listjalan &j)
{
    adrjalan temp; adrjalan prec;
    adrjalan p = carijalan(namajalan,j);
    if(p == NULL) {
        cout<<"Jalan Tidak ada"<<endl;
    } else {
        if(p == firstj(j)) {
            deletefirstjalan(j,prec);
        } else {
            prec = firstj(j);
            while (next(prec) != p) {
                prec = next(prec);
            }
            deleteafterjalan(j,prec,temp);
        }
    }
}

void insertlastrelasi(adrrelasi p, adrkota k)
{
    adrrelasi q;
    if(firstr(k) == NULL) {
        firstr(k) = p;
    } else {
        q = firstr(k);
        while(next(q) != NULL) {
            q = next(q);
        }
        next(q) = p;

    }
}

void relasikotajalan(listkota t, listjalan ti,infokota kota, string namajalan)
{
    adrkota p; adrjalan q;
    if(firstk(t) != NULL && firstj(ti) != NULL) {
        p = carikota(kota, t);
        q = carijalan(namajalan, ti);
        if(p != NULL && q != NULL) {
            adrrelasi r = createrelasi(q);
            insertlastrelasi(r, p);
        } else {
            cout<<"Kota atau Jalan tidak ada"<<endl;
        }
    } else {
        cout<<"Data Kosong"<<endl;
    }
}

void showall(listkota k)
{
    if(firstk(k) != NULL) {
        adrkota p = firstk(k);

        while(p != NULL) {
            cout<<"Kota "<<info(p)<<" Punya jalan :"<<endl;
            adrrelasi q = firstr(p);
            while(q != NULL) {
                cout<<info(info(q)).namajalan<<" Bertipe "<<info(info(q)).tipe<<endl;
                q = next(q);
            }
            cout<<endl;
            p = next(p);
        }
    } else {
        cout<<"Data Kosong"<<endl;
    }
}
void kotashowjalan(listkota k, listjalan j, string nama)
{

    adrkota p;
    adrrelasi u;
    if (firstk(k) != NULL) {
        p = firstk(k);

        while(p != NULL){
                u = firstr(p);
            while(u != NULL) {
                if(info(info(u)).namajalan == nama) {
                    cout<<"Kota "<<info(p)<<" Punya Jalan :" <<nama<<endl;
                }
                u = next(u);
            }
            p = next(p);
        }
    } else {
        cout<<"Jalan Tidak Ada"<<endl;
    }
    cout<<endl;
}

void jalanshowkota(listkota k,listjalan j, infokota kota)
{
    adrkota q = carikota(kota, k);
    if(q != NULL) {
        adrrelasi p = firstr(q);
        while(p != NULL) {
            cout<<"Kota "<<kota<<" Punya Jalan"<<endl;
            cout<<info(info(p)).namajalan<<endl;
            p = next(p);
        }
    } else {
        cout<<"Kota Tidak Ada"<<endl;
    }
    cout<<endl;
}

void tipeshowjalankota(listkota k, listjalan j, string tipe)
{
    if(firstk(k) != NULL) {
        adrkota p = firstk(k);
        while(p != NULL) {
            adrrelasi q = firstr(p);
            while(q != NULL) {
                if( info(info(q)).tipe == tipe){
                    cout<<"Kota "<<info(p)<<" Mempunyai Jalan "<<info(info(q)).namajalan<<" Bertipe "<<tipe<<endl;
                }
                q = next(q);
            }
            p = next(p);
        }
    } else {
        cout<<"Data Kosong"<<endl;
    }
    cout<<endl;
}

void showjalan(listjalan j)
{
    adrjalan p = firstj(j);
    while(p != NULL) {
        cout<<info(p).namajalan<<" Bertipe "<<info(p).tipe<<endl;
        p = next(p);
    }
}

void showkota(listkota k)
{
    adrkota p = firstk(k);
    while(p != NULL) {
        cout<<info(p)<<endl;
        p = next(p);
    }
}
