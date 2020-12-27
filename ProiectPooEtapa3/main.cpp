#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <graphics.h>
#include <time.h>
#include <map>
#include <list>
#include <string>
#include <iterator>
#include <set>
#include <windows.h>
#define MAX_THREADS 2
using namespace std;


class User
{
    int varsta;
    bool voucher;
    char gen;
    char* nume;
    char prenume[100];
    float inaltime;
    int* cnp;
    double kilograme;
    const long codPostal;
    static bool acordPrelucrareDate;
public:
    User():codPostal(0)
    {
        this->varsta=0;
        this->voucher=FALSE;
        this->gen='n';
        this->nume=NULL;
        this->inaltime=0;
        this->cnp=NULL;
        this->kilograme=0;
        this->acordPrelucrareDate=TRUE;

    }
    bool operator==(const User& user)
    {
        if(this->varsta!=user.varsta)
            return false;
        if(this->voucher!=user.voucher)
            return false;
        if(this->gen!=user.gen)
            return false;
        if(this->inaltime!=user.inaltime)
            return false;
        if(this->kilograme!=user.kilograme)
            return false;
        if(this->codPostal!=user.codPostal)
            return false;
        if(strcmp(this->nume,user.nume)!=0)
            return false;
        if(strcmp(this->prenume,user.prenume)!=0)
            return false;
        for(int i=0; i<=12; i++)
            if(this->cnp[i]!=user.cnp[i])
                return false;
        return true;
    }
    User(int varsta,bool voucher,char gen,const char* nume,char prenume[100],float inaltime,int *cnp,double kilograme,long codPostal,bool acordPrelucrareDate):codPostal(codPostal)
    {
        this->nume=new char[strlen(nume)+1];
        this->varsta=varsta;
        this->voucher=voucher;
        this->gen=gen;
        strcpy(this->nume,nume);
        strcpy(this->prenume,prenume);
        this->cnp=new int[13];
        this->inaltime=inaltime;
        for(int i=0; i<=12; i++)
        {
            this->cnp[i]=cnp[i];
        }
        this->kilograme=kilograme;
        this->acordPrelucrareDate=acordPrelucrareDate;

    }
    User(const User& user):codPostal(user.codPostal)
    {
        cnp=new int[13];
        nume=new char[strlen(user.nume)+1];
        this->varsta=user.varsta;
        this->voucher=user.voucher;
        this->gen=user.gen;
        strcpy(this->nume,user.nume);
        strcpy(this->prenume,user.prenume);
        this->inaltime=user.inaltime;
        for(int i=0; i<=12; i++)
        {
            this->cnp[i]=user.cnp[i];
        }
        this->kilograme=user.kilograme;
        this->acordPrelucrareDate=user.acordPrelucrareDate;

    }
    User& operator=(const User& user)
    {
        if(this!=&user)
        {
            this->varsta=user.varsta;
            this->voucher=user.voucher;
            this->gen=user.gen;
            if(this->nume!=NULL)
                delete[] this->nume;
            if(this->cnp!=NULL)
                delete[] this->cnp;
            this->cnp=new int[13];
            this->nume=new char[strlen(user.nume)+1];

            strcpy(this->nume,user.nume);
            strcpy(this->prenume,user.prenume);
            this->inaltime=user.inaltime;
            for(int i=0; i<=12; i++)
            {
                this->cnp[i]=user.cnp[i];
            }
            this->kilograme=user.kilograme;
            this->acordPrelucrareDate=user.acordPrelucrareDate;
        }
        return *this;
    }
    void setVarsta(int varsta)
    {
        this->varsta=varsta;
    }
    int getVarsta()
    {
        return this->varsta;
    }
    void setVoucher(bool voucher)
    {
        this->voucher=voucher;
    }
    bool getVoucher()
    {
        return this->voucher;
    }
    void setGen(char gen)
    {
        this->gen=gen;
    }
    char getGen()
    {
        return this->gen;
    }
    void setNume(char *nume)
    {
        if(this->nume!=NULL)
            delete[] this->nume;

        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
    }
    char* getNume()
    {
        return this->nume;
    }
    void setPrenume(char prenume[100])
    {
        strcpy(this->prenume,prenume);
    }
    char* getPrenume()
    {
        return this->prenume;
    }
    void setInaltime(float inaltime)
    {
        this->inaltime=inaltime;
    }
    float getInaltime()
    {
        return this->inaltime;
    }
    void setCnp(int *cnp)
    {
        if(this->cnp!=NULL)
            delete[] this->cnp;

        this->cnp=new int[13];
        for(int i=0; i<=12; i++)
            this->cnp[i]=cnp[i];
    }
    int* getCnp()
    {
        return this->cnp;
    }
    void setKilograme(double kilograme)
    {
        this->kilograme=kilograme;
    }
    double getKilograme()
    {
        return this->kilograme;
    }
    long getCodPostal()
    {
        return this->codPostal;
    }
    bool getAcordPrelucrareDate()
    {
        return this->acordPrelucrareDate;
    }

    friend ostream& operator<<(ostream& os, User& user);
    friend istream& operator>>(istream& is, User& user);
    friend ofstream& operator<<(ofstream& os, User& user);
    friend ifstream& operator>>(ifstream& is, User& user);
    bool verificare();
    ~User()
    {
        if(this->nume!=NULL)
            delete[] this->nume;
        if(this->cnp!=NULL)
            delete[] this->cnp;
    }



};
bool User::verificare()
{
    if(this->gen=='m' && (this->cnp[0]!=1 && this->cnp[0]!=5))
    {
        return FALSE;
        cout<<"aici";
    }
    if(this->gen=='f' && (this->cnp[0]!=2 && this->cnp[0]!=6))
        return FALSE;
    int x=2000+(10*this->cnp[1]+this->cnp[2]);
    if(this->cnp[0]==5 || this->cnp[1]==6)
        if(abs(2020-x-this->varsta)>1)
            return FALSE;
    x=1900+(10*this->cnp[1]+this->cnp[2]);
    if(this->cnp[0]==1 ||this->cnp[1]==2)
    {
        if(abs(2020-x-this->varsta)>1)
            return FALSE;
    }
    return TRUE;

}

ostream& operator<<(ostream& os, User& user)
{

    os<<user.nume<<'\n';
    os<<user.prenume<<'\n';
    os<<user.varsta<<'\n';
    os<<user.voucher<<'\n';
    os<<user.gen<<'\n';
    for(int i=0; i<=12; i++)
        os<<user.cnp[i];
    os<<'\n';
    os<<user.kilograme<<'\n';
    os<<user.inaltime<<'\n';
    //os<<user.acordPrelucrareDate<<'\n';

    return os;
}
ofstream& operator<<(ofstream& os, User& user)
{

    os<<user.nume<<'\n';
    os<<user.prenume<<'\n';
    os<<user.varsta<<'\n';
    os<<user.voucher<<'\n';
    os<<user.gen<<'\n';
    for(int i=0; i<=12; i++)
        os<<user.cnp[i]<<'\n';
    os<<user.kilograme<<'\n';
    os<<user.inaltime<<'\n';
    // os<<user.codPostal<<'\n';
    //os<<user.acordPrelucrareDate<<'\n';

    return os;
}


istream& operator>>(istream& is, User& user)
{
    if(user.nume!=NULL)
        delete[] user.nume;
    if(user.cnp!=NULL)
        delete[] user.cnp;
    user.cnp=new int[13];
    char s[100];
    is>>s;
    user.nume=new char[strlen(s)+1];
    strcpy(user.nume,s);
    is>>s;
    user.setPrenume(s);

    is>>user.varsta;
    bool b;
    is>>b;
    user.setVoucher(b);
    char c;
    is>>c;
    user.setGen(c);
    int v[13];
    for(int i=0; i<=12; i++)
        is>>v[i];
    user.setCnp(v);
    double d;
    is>>d;
    user.setKilograme(d);
    float f;
    is>>f;
    user.setInaltime(f);

    return is;
}
ifstream& operator>>(ifstream& is, User& user)
{
    if(user.nume!=NULL)
        delete[] user.nume;
    if(user.cnp!=NULL)
        delete[] user.cnp;
    user.cnp=new int[13];
    char s[100];
    is>>s;
    user.nume=new char[strlen(s)+1];
    strcpy(user.nume,s);
    is>>s;
    user.setPrenume(s);
    is>>user.varsta;
    bool b;
    is>>b;
    user.setVoucher(b);
    char c;
    is>>c;
    user.setGen(c);
    int v[13];
    for(int i=0; i<=12; i++)
        is>>v[i];
    user.setCnp(v);
    double d;
    is>>d;
    user.setKilograme(d);
    float f;
    is>>f;
    user.setInaltime(f);
    return is;
}
class Cont:public User
{
    string numeUtilizator;
    string parola;
public:
    Cont():User()
    {
        numeUtilizator="Anonim";
        parola="parola";
    }
    string getNumeUtl()
    {
        return numeUtilizator;
    }
    string getParola()
    {
        return parola;
    }
    void setNumeUtl(string nume)
    {
        this->numeUtilizator=nume;
    }
    void setParola(string parola)
    {
        this->parola=parola;
    }
    bool operator==(const Cont& cont)
    {
        User::operator=(cont);
        if(this->numeUtilizator!=cont.numeUtilizator)
            return false;
        if(this->parola!=cont.parola)
            return false;

        return true;
    }
    Cont(string numeUtilizator,string parola,int varsta,bool voucher,char gen,const char* nume,char prenume[100],float inaltime,int *cnp,double kilograme,long codPostal,bool acordPrelucrareDate):User(varsta,voucher,gen,nume,prenume,inaltime,cnp,kilograme,codPostal,acordPrelucrareDate)
    {
        this->numeUtilizator=numeUtilizator;
        this->parola=parola;
    }
    Cont& operator=(const Cont& cont)
    {
        if(this!=&cont)
        {
            User::operator=(cont);
            this->numeUtilizator=cont.numeUtilizator;
            this->parola=cont.parola;

        }
        return *this;
    }
    Cont(const Cont& cont):User(cont)
    {
        this->numeUtilizator=cont.numeUtilizator;
        this->parola=cont.parola;
    }
    friend ostream& operator<<(ostream& out, const Cont& cont)
    {
        out<<(User&)cont;
        out<<"Numele de utilizator este:"<<cont.numeUtilizator<<" si parola este "<<cont.parola;
        out<<'\n';
        return out;

    }
    friend ofstream& operator<<(ofstream& out, const Cont& cont)
    {
        out<<(User&)cont;
        out<<cont.numeUtilizator<<'\n';
        out<<cont.parola<<'\n';
        return out;

    }
    friend ifstream& operator>>(ifstream& in, Cont& cont)
    {
        in>>(User&)cont;
        in>>cont.numeUtilizator;
        in>>cont.parola;
        return in;
    }
    friend istream& operator>>(istream& in, Cont& cont)
    {
        in>>(User&)cont;
        in>>cont.numeUtilizator;
        in>>cont.parola;
        return in;
    }
    bool verificareCont()
    {
        if(parola.size()<8)
            return FALSE;
        int ok=0;
        for(int i=0; i<parola.size(); i++)
            if(parola[i]>='0' && parola[i]<='9')
                ok=1;
        if(ok==0)
            return FALSE;
        for(int i=0; i<parola.size(); i++)
            if(parola[i]>='A' && parola[i]<='Z')
                ok=1;
        if(ok==0)
            return FALSE;
        return ok;

    }

    ~Cont()
    {

    }

};
bool User::acordPrelucrareDate=TRUE;

class Taxi
{
    char culoare;
    char* marca;
    double consum;///la suta de km
public:
    Taxi()
    {
        culoare='n';
        marca=NULL;
        consum=0;
    }
    Taxi(char culoare,char *marca,double consum)
    {
        this->culoare=culoare;
        this->marca=new char[strlen(marca)+1];
        strcpy(this->marca,marca);
        this->consum=consum;

    }
    Taxi(const Taxi& taxi)
    {

        this->culoare=taxi.culoare;
        marca=new char[strlen(taxi.marca)+1];
        strcpy(this->marca,taxi.marca);
        this->consum=taxi.consum;
    }
    Taxi& operator=(const Taxi& taxi)
    {
        if(this!=&taxi)
        {
            if(this->marca!=NULL)
                delete[] this->marca;
            this->culoare=taxi.culoare;
            marca=new char[strlen(taxi.marca)+1];
            strcpy(this->marca,taxi.marca);
            this->consum=taxi.consum;
        }
        return *this;
    }
    void setCuloare(char culoare)
    {
        this->culoare=culoare;
    }
    char getCuloare()
    {
        return this->culoare;
    }
    void setMarca(char *Marca)
    {
        if(this->marca!=NULL)
            delete[] this->marca;

        marca=new char[strlen(marca)+1];
        strcpy(this->marca,marca);

    }
    char* getMarca()
    {
        return this->marca;
    }
    void setConsum(double consum)
    {
        this->consum=consum;
    }
    double getConsum()
    {
        return this->consum;
    }

    Taxi operator+(const Taxi& taxi)
    {
        this->consum=this->consum+taxi.consum;
        return *this;
    }
    Taxi operator-(const Taxi& taxi)
    {
        this->consum=this->consum-taxi.consum;
        return *this;
    }
    Taxi& operator++()
    {
        this->consum+=1.0;
        return *this;
    }
    Taxi& operator--()
    {
        this->consum-=1.0;
        return *this;
    }
    bool operator>(const Taxi& taxi)
    {
        return (this->consum > taxi.consum);
    }
    bool operator==(const Taxi& taxi)
    {
        return (this->consum == taxi.consum);
    }
    bool operator<(const Taxi& taxi)
    {
        return (this->consum < taxi.consum);
    }
    operator double() const
    {
        return this->consum;
    }
    char operator[](int i)
    {
        return this->marca[i];
    }
    friend ostream& operator<<(ostream& os, Taxi& taxi);
    friend istream& operator>>(istream& is, Taxi& taxi);
    void parteneriatBenzinarie();


    ~Taxi()
    {
        if(this->marca!=NULL)
            delete[] this->marca;
    }



};

ostream& operator<<(ostream& os,Taxi& taxi)
{
    cout<<"Culoare:"<<taxi.culoare<<" Marca:"<<taxi.marca<<" Consum:"<<taxi.consum<<'\n';
    return os;
}
istream& operator>>(istream& is,Taxi& taxi)
{
    is>>taxi.culoare;
    char s[100];
    is>>s;
    taxi.marca=new char[strlen(s)+1];
    strcpy(taxi.marca,s);
    is>>taxi.consum;
    return is;
}

void Taxi::parteneriatBenzinarie()
{
    if(this->consum>=6.0)
        this->setConsum(this->getConsum()/2);
}
class LuxuryTaxi:public Taxi
{
    int gradConfort;
    bool plataCard;
    bool chooseYourMusic;
public:
    LuxuryTaxi():Taxi()
    {
        this->gradConfort=0;
        this->plataCard=FALSE;
        this->chooseYourMusic=FALSE;
    }
    bool getChooseYourMusic()
    {
        return this->chooseYourMusic;
    }
    LuxuryTaxi(int gradConfort,bool plataCard,bool chooseYourMusic,char culoare,char* marca,double consum):Taxi(culoare,marca,consum)
    {

        this->gradConfort=gradConfort;
        this->plataCard=plataCard;
        this->chooseYourMusic=chooseYourMusic;
    }
    LuxuryTaxi(const LuxuryTaxi& taxi):Taxi(taxi)
    {

        this->gradConfort=taxi.gradConfort;
        this->plataCard=taxi.plataCard;
        this->chooseYourMusic=taxi.chooseYourMusic;
    }
    LuxuryTaxi operator=(const LuxuryTaxi& taxi)
    {
        if(this!=&taxi)
        {
            Taxi::operator=(taxi);
            this->gradConfort=taxi.gradConfort;
            this->plataCard=taxi.plataCard;
            this->chooseYourMusic=taxi.chooseYourMusic;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os,LuxuryTaxi& taxi)
    {
        os<<(Taxi&)taxi;
        os<<"Grad de confort:"<<taxi.gradConfort<<" plata cu card:"<<taxi.plataCard<<" Alegi muzica:"<<taxi.chooseYourMusic<<endl;
        return os;
    }
    friend istream& operator>>(istream& in,LuxuryTaxi& taxi)
    {
        in>>(Taxi&)taxi;
        in>>taxi.gradConfort;
        in>>taxi.plataCard;
        in>>taxi.chooseYourMusic;
        return in;
    }
    bool YourMusic(int melodie,map<int,char*>Melodii)///map melodii
    {
        for(map<int,char*>::iterator it=Melodii.begin(); it!=Melodii.end(); ++it)
        {
            if(it->first==melodie)
                PlaySound(it->second, NULL, SND_FILENAME);
        }
        return FALSE;
    }

    ~LuxuryTaxi()
    {

    }
};


class Taximetrist
{
    int varsta;
    bool vbLbEngl;
    char gen;
    char* nume;
    char prenume[100];
    float coeficient;
    int* cnp;
    double vechime;
    const int id;
    static bool atestatProfesional;
    Taxi taxi;
public:
    Taximetrist():id(0)
    {
        this->nume=NULL;
        this->varsta=0;
        this->vbLbEngl=FALSE;
        this->gen='n';
        this->cnp=NULL;
    }
    Taximetrist(int varsta,bool vbLbEngl,char gen,char* nume,char prenume[100],float coeficient,int* cnp,double vechime,int id,bool atestatProfesional,Taxi taxi):id(id)
    {
        this->cnp=new int[13];
        this->nume=new char[strlen(nume)+1];
        this->varsta=varsta;
        this->vbLbEngl=vbLbEngl;
        this->gen=gen;
        strcpy(this->nume,nume);
        strcpy(this->prenume,prenume);
        this->coeficient=coeficient;
        for(int i=0; i<=12; i++)
            this->cnp[i]=cnp[i];
        this->vechime=vechime;
        this->atestatProfesional=atestatProfesional;
        this->taxi=taxi;
    }
    Taximetrist(const Taximetrist& taximetrist):id(taximetrist.id)
    {
        this->cnp=new int[13];
        this->nume=new char[strlen(taximetrist.nume)+1];
        this->varsta=taximetrist.varsta;
        this->vbLbEngl=taximetrist.vbLbEngl;
        this->gen=taximetrist.gen;
        strcpy(this->nume,taximetrist.nume);
        strcpy(this->prenume,taximetrist.prenume);
        this->coeficient=taximetrist.coeficient;
        for(int i=0; i<=12; i++)
            this->cnp[i]=taximetrist.cnp[i];
        this->vechime=taximetrist.vechime;
        this->atestatProfesional=taximetrist.atestatProfesional;
        this->taxi=taximetrist.taxi;
    }
    Taximetrist(int varsta,char* nume,Taxi taxi,int id):id(id)
    {
        this->nume=new char[strlen(nume)+1];
        this->varsta=varsta;
        strcpy(this->nume,nume);
        this->taxi=taxi;
        this->cnp=NULL;

    }

    void setVarsta(int varsta)
    {
        this->varsta=varsta;
    }
    int getVarsta()
    {
        return this->varsta;
    }
    void setVbLbEngl(bool vbLbEngl)
    {
        this->vbLbEngl=vbLbEngl;
    }
    bool getVbLbEngl()
    {
        return this->vbLbEngl;
    }
    void setGen(char gen)
    {
        this->gen=gen;
    }
    char getGen()
    {
        return this->gen;
    }
    void setNume(char *nume)
    {
        if(this->nume!=NULL)
            delete[] this->nume;

        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
    }
    char* getNume()
    {
        return this->nume;
    }
    void setPrenume(char prenume[100])
    {
        strcpy(this->prenume,prenume);
    }
    char* getPrenume()
    {
        return this->prenume;
    }
    void setCoeficient(float coef)
    {
        this->coeficient=coef;
    }
    float getCoeficient()
    {
        return this->coeficient;
    }
    void setCnp(int *cnp)
    {
        if(this->cnp!=NULL)
            delete[] this->cnp;
        this->cnp=new int[13];
        for(int i=0; i<11; i++)
            this->cnp[i]=cnp[i];
    }
    int* getCnp()
    {
        return this->cnp;
    }
    void setVechime(double vechime)
    {
        this->vechime=vechime;
    }
    double getVechime()
    {
        return this->vechime;
    }
    int getId()
    {
        return this->id;
    }
    bool getAtestatProfesional()
    {
        return this->atestatProfesional;
    }
    void setTaxi(Taxi taxi)
    {
        this->taxi=taxi;
    }
    Taxi getTaxi()
    {
        return this->taxi;
    }
    friend ostream& operator<<(ostream& os, Taximetrist& taxi);
    friend istream& operator>>(istream& is, Taximetrist& taxi);


    Taximetrist& operator=(const Taximetrist& taximetrist)
    {
        if(this!=&taximetrist)
        {
            if(this->nume!=NULL)
                delete[] this->nume;
            if(this->cnp!=NULL)
                delete[] this->cnp;
            this->cnp=new int[13];
            this->nume=new char[strlen(taximetrist.nume)+1];
            this->varsta=taximetrist.varsta;
            this->vbLbEngl=taximetrist.vbLbEngl;
            this->gen=taximetrist.gen;
            strcpy(this->nume,taximetrist.nume);
            strcpy(this->prenume,taximetrist.prenume);
            this->coeficient=taximetrist.coeficient;
            for(int i=0; i<=12; i++)
                this->cnp[i]=taximetrist.cnp[i];
            this->vechime=taximetrist.vechime;
            this->atestatProfesional=taximetrist.atestatProfesional;
            this->taxi=taximetrist.taxi;

        }
        return *this;
    }

    virtual double Salariu() {};

    ~Taximetrist()
    {
        if(this->nume!=NULL)
            delete[] this->nume;
        if(this->cnp!=NULL)
            delete[] this->cnp;
    }

};


bool Taximetrist::atestatProfesional;

ostream& operator<<(ostream& os, Taximetrist& taxi)
{
    os<<"Nume:"<<taxi.nume<<'\n';
    os<<"Prenume:"<<taxi.prenume<<'\n';
    os<<"Varsta:"<<taxi.varsta<<'\n';
    os<<"Vorbeste engleza?"<<taxi.vbLbEngl<<'\n';
    os<<"Genul:"<<taxi.gen<<'\n';
    os<<"Coeficient:"<<taxi.coeficient<<'\n';

    os<<"CNP:";
    for(int i=0; i<=12; i++)
        os<<taxi.cnp[i];
    os<<'\n';
    os<<"Vechime"<<taxi.vechime<<'\n';
    os<<"Id:"<<taxi.id<<'\n';
    os<<"Atestat Profesional:"<<taxi.atestatProfesional<<'\n';
    // os<<"Taxi:"<<taxi.taxi;

    return os;


}
istream& operator>>(istream& is, Taximetrist& taxi)
{
    char s[100];
    is>>s;
    taxi.nume=new char[strlen(s)+1];
    taxi.cnp=new int[13];
    taxi.setNume(s);
    is>>s;
    taxi.setPrenume(s);
    int x;
    is>>x;
    taxi.setVarsta(x);
    bool a;
    is>>a;
    taxi.setVbLbEngl(a);
    float z;
    is>>z;
    taxi.setCoeficient(z);
    double j;
    taxi.setVechime(j);
    char c;
    is>>c;
    taxi.setGen(c);
    is>>taxi;
    int* v;
    for(int i=0; i<=12; i++)
        cin>>v[i];
    taxi.setCnp(v);
    return is;

}
class EntryLevel:public Taximetrist
{
    const double bonus=0.5;
public:
    double Salariu()
    {
        return bonus*double(this->getCoeficient())*this->getVechime();
    }

};
class MidLevel:public Taximetrist
{
    const double bonus=1;
public:
    MidLevel(int varsta,bool vbLbEngl,char gen,char* nume,char prenume[100],float coeficient,int* cnp,double vechime,int id,bool atestatProfesional,Taxi taxi):Taximetrist(varsta,vbLbEngl,gen,nume,prenume,coeficient,cnp,vechime,id,atestatProfesional,taxi)
    {

    }
    double Salariu()
    {
        return bonus*double(this->getCoeficient())*this->getVechime();
    }

};
class AdvancedLevel:public Taximetrist
{
    const double bonus=1.2;
public:
    double Salariu()
    {
        return bonus*double(this->getCoeficient())*this->getVechime();
    }

};
class Pozitie
{
    int x;
    int y;
    int valoare;
public:
    Pozitie()
    {
        x=y=0;
    }
    Pozitie(int x,int y,int valoare)
    {
        this->x=x;
        this->y=y;
        this->valoare=valoare;
    }
    Pozitie(const Pozitie& pozitie)
    {
        this->x=pozitie.x;
        this->y=pozitie.y;
        this->valoare=pozitie.valoare;
    }
    Pozitie(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    void setX(int x)
    {
        this->x=x;
    }
    int getX()
    {
        return this->x;
    }
    void setY(int y)
    {
        this->y=y;
    }
    int getY()
    {
        return this->y;
    }
    int getValoare()
    {
        return this->valoare;
    }
    void setValoare(int valoare)
    {
        this->valoare=valoare;
    }
    Pozitie& operator=(const Pozitie& poz)
    {
        if(this!=&poz)
        {
            this->x=poz.x;
            this->y=poz.y;
            this->valoare=poz.valoare;

        }
        return *this;
    }
    Pozitie operator+(const Pozitie& poz)
    {
        this->valoare=this->valoare+poz.valoare;
        return *this;
    }
    Pozitie operator-(const Pozitie& poz)
    {
        this->valoare=this->valoare-poz.valoare;
        return *this;
    }
    Pozitie& operator++()
    {
        this->valoare+=1;
        return *this;
    }
    Pozitie& operator--()
    {
        this->valoare-=1;
        return *this;
    }
    bool operator>(const Pozitie& poz)
    {
        return (this->valoare > this->valoare);
    }
    bool operator<(const Pozitie& poz)
    {
        return (this->valoare < this->valoare);
    }
    bool operator==(const Pozitie& poz)
    {
        return (this->valoare==this->valoare);
    }
    operator int() const
    {
        return this->valoare;
    }
    int operator[](int i)
    {
        if(i==0)
            return this->x;
        if(i==1)
            return this->y;
        else
            return this->valoare;
    }


    friend ostream& operator<<(ostream& os, Pozitie& poz);
    friend istream& operator>>(istream& is, Pozitie& poz);
    bool verificarePozitie(int N,int M);


    ~Pozitie()
    {

    }

};
bool Pozitie::verificarePozitie(int N,int M)
{
    if(x<0 || y<0)
        return FALSE;
    if(x>N)
        return FALSE;
    if(y>M)
        return FALSE;
    return TRUE;

}
ostream& operator<<(ostream& os,  Pozitie& poz)
{
    os<<"Linia:"<<poz.x<<" Coloana:"<<poz.y<<" Are valoarea:"<<poz.valoare<<'\n';
    return os;
}
istream& operator>>(istream& is,Pozitie& poz)
{
    is>>poz.x;
    is>>poz.y;
    is>>poz.valoare;
    return is;
}


class Careu
{
    int n;
    int m;
    int A[101][101];//!!
    int matriceDeLucru[101][101];
    const int dj[4];
    const int di[4];

public:
    Careu():di({-1, 0, 1, 0}),dj({0, 1, 0,-1})
    {
        m=n=0;
    }
    Careu(int n,int m,long A[101][101]):di({-1, 0, 1, 0}),dj({0, 1, 0,-1})
    {
        this->n=n;
        this->m=m;
        for(int i = 1 ; i <= n ; i ++)
            for(int j = 1 ; j <= m ; j ++)
                this->A[i][j]=A[i][j];
    }
    Careu(int n,int m):di({-1, 0, 1, 0}),dj({0, 1, 0,-1})
    {
        this->n=n;
        this->m=m;
    }
    void setN(int n)
    {
        this->n=n;
    }
    int getN()const
    {
        return n;
    }
    void setM(int m)
    {
        this->m=m;
    }
    int getM()const
    {
        return m;
    }
    void setA(int i,int j,int val)
    {
        this->A[i][j]=val;
    }
    int getA(int i,int j)const
    {
        return this->A[i][j];
    }
    void setMatriceDeLucru(int i,int j,int val)
    {
        this->matriceDeLucru[i][j]=val;
    }
    int getMatriceDeLucru(int i,int j)const
    {
        return this->matriceDeLucru[i][j];
    }
    int getDi(int k)
    {
        return this->di[k];
    }
    int getDj(int k)
    {
        return this->dj[k];
    }

    virtual void InitMatriceDeLucru()=0;
    virtual void Lee(int istart,int jstart)=0;
    virtual int Traseu2(int istop,int jstop)=0;
    virtual void incarcaImagine(int i,int j,int val,int latura)=0;
    ~Careu()
    {

    }


};
long M[101][101];
class Start:public Careu
{
public:
    Start():Careu(0,0,M)
    {
    }
    Start(int n,int m,long  A[101][101]):Careu(n,m,A)
    {
    }
    Start(const Start& start):Careu(start)
    {
    }
    void incarcaImagine(int i,int j,int val,int latura)
    {
        int x, y;
        x=(j-1)*latura;
        y=(i-1)*latura;
        char nf[20];///val=1
        sprintf(nf,"%d",val);
        //itoa(val, nf,10);///nf="1"
        strcat(nf,".jpg");
        readimagefile(nf,x,y,x+latura, y+latura);
    }
    void Lee(int istart ,int jstart)
    {
        try
        {
            queue<pair<int,int> > Q;
            Q.push(make_pair(istart , jstart));
            setMatriceDeLucru(istart,jstart,1);
            while(! Q.empty())
            {
                int i = Q.front().first, j = Q.front().second;
                for(int k = 0 ; k < 4 ; k ++)
                {
                    int iv = i + getDi(k), jv = j + getDj(k);
                    if(iv >= 1 && iv <= getN() && jv >= 1 && jv <= getM() &&  getMatriceDeLucru(iv,jv)==0)
                    {
                        setMatriceDeLucru(iv,jv,getMatriceDeLucru(i,j)+1);
                        Q.push(make_pair(iv , jv));
                    }
                }
                Q.pop();
            }

        }
        catch(exception& e)
        {
            cout<<e.what()<<" ";
        }

    }
///https://www.pbinfo.ro/articole/18589/algoritmul-lui-lee




    int Traseu2(int istop, int jstop)
    {
        vector< pair <int,int> > V;
        int i = istop , j = jstop;
        V.push_back(make_pair(i , j));
        do
        {
            int p = -1;
            for(int k = 0 ; k < 4 && p == -1 ; k ++)
                if(getMatriceDeLucru(i,j)==getMatriceDeLucru(i+getDi(k),j+getDj(k))+1)
                    p = k;
            i = i + getDi(p) , j = j + getDj(p);
            V.push_back(make_pair(i , j));

        }
        while(getMatriceDeLucru(i,j) != 1);
        try
        {
            ///cout << V.size() << '\n';
            Pozitie *last=new Pozitie();
            Pozitie *now=new Pozitie();
            int aux=-1;
            for(vector<pair<int,int> >::reverse_iterator I = V.rbegin() ; I != V.rend() ; I ++)
            {
                now->setX(I->first);
                now->setY(I->second);
                last->setX((I-1)->first);
                last->setY((I-1)->second);
                this->incarcaImagine(now->getX(),now->getY(),20,70);
                if(aux!=-1)
                    this->incarcaImagine(last->getX(),last->getY(),aux,70);
                aux=getA(I->first,I->second);
                delay(300);
            }
            return V.size();
        }
        catch(const std::bad_alloc&)
        {
            cout<<"prea departe";
            return 0;
        }
    }
    void InitMatriceDeLucru()
    {
        for(int i=1; i<=getN(); i++)
            for(int j=1; j<=getM(); j++)
                if(getA(i,j)==15 || getA(i,j)==16 ||getA(i,j)==0)
                    setMatriceDeLucru(i,j,0);
                else
                    setMatriceDeLucru(i,j,-1);

    }
    friend ostream &operator<<(ostream &output,Start &Daf)
    {
        for(int i=1; i<=Daf.getN(); i++)
        {
            for(int j=1; j<=Daf.getM(); j++)
                output<<Daf.getMatriceDeLucru(i,j)<<" ";
            output<<endl;
        }
        return output;
    }
    friend istream &operator>>( istream  &input, Start &D )
    {
        int x,y;
        input>>x;
        D.setN(x);
        input>>y;
        D.setM(y);
        for(int i=1; i<=D.getN(); i++)
            for(int j=1; j<=D.getM(); j++)
            {
                input>>x;
                D.setA(i,j,x);
            }
        return input;
    }
    Start& operator=(const Start& start)
    {
        if(this!=&start)
        {
            this->setN(start.getN());
            this->setM(start.getM());
            for(int i=1; i<=start.getN(); i++)
                for(int j=1; j<=start.getM(); j++)
                    this->setA(i,j,start.getA(i,j));
            for(int i=1; i<=start.getN(); i++)
                for(int j=1; j<=start.getM(); j++)
                    this->setMatriceDeLucru(i,j,start.getMatriceDeLucru(i,j));


        }
        return *this;
    }
    ~Start()
    {

    }



};
class Mapa
{
public:
    virtual void incarcaImagine(int i,int j,int val)=0;
    virtual void genereazaFereastraGrafica()=0;
    virtual void genereazaMapa(Start A)=0;
    virtual Pozitie getMouseClick()=0;
};
class Fereastra: public Mapa
{
    int m;
    int n;
    int latura;
public:
    Fereastra()
    {
        m=n=latura=0;
    }
    Fereastra(int m,int n,int latura)
    {
        this->m=n;
        this->n=n;
        this->latura=latura;
    }
    Fereastra(int m,int n)
    {
        this->m=n;
        this->n=n;
        this->latura=100;

    }
    Fereastra(const Fereastra& fereastra)
    {
        this->m=fereastra.n;
        this->n=fereastra.n;
        this->latura=fereastra.latura;
    }

    void setN(int n)
    {
        this->n=n;
    }
    int getN()
    {
        return n;
    }
    void setM(int m)
    {
        this->m=m;
    }
    int getM()
    {
        return m;
    }
    void setLatura(int latura)
    {
        this->latura=latura;
    }
    int getLatura()
    {
        return this->latura;
    }

    void genereazaFereastraGrafica()
    {

        initwindow(n*latura,m*latura,"Bucuresti");

    }
    void incarcaImagine(int i,int j,int val)
    {
        int x, y;
        x=(j-1)*latura;
        y=(i-1)*latura;
        char nf[20];
        sprintf(nf,"%d",val);
        //itoa(val, nf,10);
        strcat(nf,".jpg");
        readimagefile(nf,x,y,x+latura, y+latura);
    }
    void genereazaMapa(Start A)
    {
        for(int i=1; i<=A.getN(); i++)
            for(int j=1; j<=A.getM(); j++)
            {
                this->incarcaImagine(i,j,A.getA(i,j));
                if(A.getA(i,j)!=15 && A.getA(i,j)!=16)
                    A.setA(i,j,A.getA(i,j)*10000);
            }

    }
    Pozitie getMouseClick()
    {
        int x,y,k=0;
        Pozitie pozitie;
        while(k!=1)
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x!=-1)
            {
                k++;
                pozitie.setX(int(y/70)+1);
                pozitie.setY(int(x/70)+1);
            }
        }

        return pozitie;

    }
    Fereastra& operator=(Fereastra& fereastra)
    {
        if(this!=&fereastra)
        {
            this->m=fereastra.m;
            this->n=fereastra.n;
            this->latura=fereastra.latura;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os, Fereastra& fereastra);
    friend istream& operator>>(istream& is, Fereastra& fereastra);


    ~Fereastra()
    {

    }

};
ostream& operator<<(ostream& os,Fereastra& fereastra)
{
    os<<"Fereastra are "<<fereastra.n<<" linii si "<<fereastra.m<<" coloane cu latura de "<<fereastra.latura<<endl;
    return os;
}
istream& operator>>(istream& is, Fereastra& fereastra)
{
    is>>fereastra.n;
    is>>fereastra.m;
    is>>fereastra.latura;
    return is;
}

class Singleton
{
    static Singleton *instance;
    LuxuryTaxi angajat;
    Singleton()
    {

    }
public:
    static Singleton *getInstance()
    {
        if (!instance)
            instance = new Singleton;
        return instance;
    }
    void setTaximetrist(LuxuryTaxi angajat)
    {
        this->angajat=angajat;
    }
    LuxuryTaxi getTaximetrist()
    {
        return this->angajat;
    }





};
Singleton *Singleton::instance = 0;


DWORD   dwThreadIdArray[2];
HANDLE  hThreadArray[2];

DWORD WINAPI Muzica( LPVOID lpParam )
{
    map<int,char*>Melodii;
    Melodii.insert(pair<int,char*>(1,"astro.wav"));
    Melodii.insert(pair<int,char*>(2,"dior.wav"));
    Melodii.insert(pair<int,char*>(3,"congratulations.wav"));
    Melodii.insert(pair<int,char*>(4,"nonstop.wav"));
    LuxuryTaxi* s=(LuxuryTaxi*)lpParam;
    int optiune;
    cout<<"1.Travis Scott-HOUSTONFORNICATION"<<endl;
    cout<<"2.Pop Smoke-Aim for the moon"<<endl;
    cout<<"3.Post Malone-Congratulations"<<endl;
    cout<<"4.Drake-Nonstop"<<endl;
    cin>>optiune;
    s->YourMusic(optiune,Melodii);



    return 0;
}

set<int, greater<int> > s1;

DWORD WINAPI Traseu( LPVOID lpParam )
{
    ifstream f("Bucuresti.in");
    Fereastra a(13,13,70);
    Start A;
    f>>A;
    Start B(A);
    Pozitie x,y;
    a.genereazaFereastraGrafica();
    a.genereazaMapa(A);
    x=a.getMouseClick();
    A.InitMatriceDeLucru();
    B.InitMatriceDeLucru();
    A.Lee(11,12);
    A.Traseu2(x[0],x[1]);
    y=a.getMouseClick();
    B.Lee(x[0],x[1]);
    int b=B.Traseu2(y[0],y[1]);
    cout<<"Va costa "<<b<<" lei"<<endl;
    s1.insert(b);
    f.close();
    return 0;
}

int v[2];
template<class T>T mySum(set<T,greater<T> > s1)
{
    T x=0;
    set<int, greater<int> >::iterator itr;
            for (itr = s1.begin(); itr != s1.end(); ++itr)
            {
                x+=*itr;
            }
    return x;

}

int main()
{


    int nrConturi;
    Cont curent;
    list<Cont> conturi;
    map<Pozitie,char*> locatii;
    ifstream in("baze.txt");
    in>>nrConturi;
    for(int i=1; i<=nrConturi; i++)
    {
        in>>curent;
        conturi.push_back(curent);
    }

    int optiune=5;
    while(optiune!=0)
    {
        int CNP[12]= {5,0,0,1,1,1,7,1,8,0,0,5};
        User user(15,TRUE,'m',"caragea","Theodor",1.88,CNP,88.0,800281,TRUE);

        cout<<"Bine ati venit la TaxiBlocks"<<endl;
        cout<<"1.Creaza cont"<<endl;
        cout<<"2.Logare"<<endl;
        cout<<"3.Editare profil"<<endl;
        cout<<"4.Voucher"<<endl;
        cout<<"5.Cursa noua"<<endl;
        cout<<"6.Istoric plati curse"<<endl;
        cout<<"Orice alta cifra pentru iesire...";

        cin>>optiune;
        switch(optiune)
        {
        case 1:
        {
            char nume[100],prenume[100];
            int varsta;
            char c;
            double h;
            int CNP[13];
            double g;
            long cod;
            bool acord;
            char cnp[13];
            string numeutl;
            string parola;
            cout<<"Nume:";
            cin>>nume;

            cout<<"Prenume:";
            cin>>prenume;
            cout<<"Varsta:";
            cin>>varsta;
            cout<<"Gen (m-masculin, f-feminin):";
            cin>>c;
            cout<<"Inaltime:";
            cin>>h;
            cout<<"CNP:";
            cin>>cnp;
            for(int i=0; i<=12; i++)CNP[i]=(int)(cnp[i])-48;
            cout<<"Greutate:";
            cin>>g;
            cout<<"Cod postal:";
            cin>>cod;
            cout<<"Nume utilizator:";
            cin>>numeutl;
            for(list<Cont>::iterator it=conturi.begin(); it!=conturi.end(); ++it)
            {
                if(numeutl==it->getNumeUtl())
                {
                    cout<<"Numele de utilizator este deja folosit...va rugam incercati iar";
                    delay(5000);
                    break;
                }
            }
            cout<<"Parola:";
            cin>>parola;

            try
            {
                cout<<"Acord prelucrare date (0 sau 1)";
                cin>>acord;
                throw acord;
            }
            catch(bool acord)
            {
                if(acord==0)
                    cout<<"Nu se poate crea contul...va rugam incercati iar";
                else
                {
                    Cont nou(numeutl,parola,varsta,FALSE,c,nume,prenume,h,CNP,g,cod,TRUE);

                    conturi.push_back(nou);
                    curent=nou;

                }
            }

            delay(4000);
        }
        break;
        case 2:
        {
            bool logare;
            string nume,parola;
            cout<<"Nume utilizator:";
            cin>>nume;
            cout<<"Parola:";
            cin>>parola;
            try
            {

                for(list<Cont>::iterator it=conturi.begin(); it!=conturi.end(); ++it)
                {
                    if(nume==it->getNumeUtl() && parola==it->getParola())
                    {
                        curent=*it;
                        cout<<"Logare cu succes!!";
                        logare=1;
                    }
                }
            }
            catch(exception& e)
            {
                cout<<"Eroare la baza de date..va rugam reveniti"<<endl;
            }
            if(logare==FALSE)
                cout<<"Nume de utilizator sau parola gresite...incercati iar";
            delay(5000);
        }
        break;
        case 3:
        {
            if(!curent.verificare())
            {
                cout<<"IMPORTANT!!Datele contului nu sunt corecte!!"<<endl;
            }
            if(!curent.verificareCont())
            {
                cout<<"IMPORTANT!!Parola este slaba..va rugam sa o schimbati.."<<endl;
            }

            cout<<curent<<endl;
            string decizie;
            cout<<"Doriti sa efectuati modificari?(da/nu):";
            cin>>decizie;
            if(decizie=="da")
            {

                char nume[100],prenume[100];
                int varsta;
                char c;
                double h;
                int CNP[13];
                double g;
                long cod;
                char s[13];
                string numeutl;
                string parola;
                try
                {
                    for(list<Cont>::iterator it=conturi.begin(); it!=conturi.end(); ++it)
                    {
                        if(curent.getNumeUtl()==it->getNumeUtl() && curent.getParola()==it->getParola())
                        {
                            cout<<"Nume:";
                            cin>>nume;
                            cout<<"Prenume:";
                            cin>>prenume;
                            cout<<"Varsta:";
                            cin>>varsta;
                            cout<<"Gen (m-masculin, f-feminin):";
                            cin>>c;
                            cout<<"Inaltime:";
                            cin>>h;
                            cout<<"CNP:";
                            try
                            {
                                cin>>s;
                            }
                            catch(bad_alloc& e)
                            {
                                cout<<"introdu un cnp de lungime valida!";
                            }
                            for(int i=0; i<=12; i++)CNP[i]=(int)s[i]-48;
                            cout<<"Greutate:";
                            cin>>g;
                            cout<<"Cod postal:";
                            cin>>cod;
                            cout<<"Nume utilizator:";
                            cin>>numeutl;
                            cout<<"Parola:";
                            cin>>parola;
                            it->setNume(nume);
                            it->setPrenume(prenume);
                            it->setVarsta(varsta);
                            it->setGen(c);
                            it->setCnp(CNP);
                            it->setKilograme(g);
                            it->setNumeUtl(numeutl);
                            it->setParola(parola);
                            curent=*it;
                        }
                    }
                }
                catch(exception& e)
                {
                    cout<<e.what();
                }
                cout<<"modificari salvate cu succes"<<endl;
            }
            delay(5000);
        }
        break;
        case 4:
            system("cls");
            if(curent.getVoucher()==FALSE)
            {
                cout<<"Bine ai venit "<<curent.getNume()<<" "<<curent.getPrenume()<<endl;
                cout<<"Introdu codul promotional:";
                char s[30];
                cin>>s;
                if(strcmp(s,"voucher")!=0)
                    cout<<"Voucher incorect...";
                else
                {
                    try
                    {
                        for(list<Cont>::iterator it=conturi.begin(); it!=conturi.end(); ++it)
                        {
                            if(curent.getNumeUtl()==it->getNumeUtl() && curent.getParola()==it->getParola())
                            {

                                cout<<"Voucher introdus cu succes!";
                                it->setVoucher(TRUE);
                                curent=*it;
                            }
                        }
                    }
                    catch(exception& e)
                    {
                        cout<<e.what();
                    }
                }
            }
            else
                cout<<"Voucher introdus cu succes!";
            delay(5000);
            break;
        case 5:
        {
            v[0] = (int) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
                                   sizeof(int));
            v[1] = (int) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
                                   sizeof(int));

            if(v[0] == NULL && v[1]==NULL)
            {
                ExitProcess(2);
            }
            LuxuryTaxi angajat(3,TRUE,TRUE,'r',"mercedes",7.2);
            Singleton *s = s->getInstance();
            s->setTaximetrist(angajat);
            int cnp[13]= {1,7,9,0,4,2,2,1,8,0,0,7,4};
            Taximetrist *taximetrist1;
            MidLevel taximetristAngajat(31,TRUE,'m',"Alexandru","Vlad",3.0,cnp,1,501,TRUE,angajat);
            taximetrist1=&taximetristAngajat;
            cout<<*taximetrist1;
            cout<<"Taxi marca:"<<s->getTaximetrist().getMarca()<<" culoare galbena Muzica:"<<s->getTaximetrist().getChooseYourMusic()<<endl;
            string decizie,muzica;
            cout<<"Acceptati cursa?(da/nu)";
            cin>>decizie;
            if(decizie=="da")
            {
                cout<<"Doriti muzica?(da/nu)";
                cin>>muzica;
                if(muzica=="da")
                {
                    try
                    {
                        hThreadArray[0]=CreateThread(NULL,0,Muzica,&angajat,0,&dwThreadIdArray[0]);
                    }
                    catch(exception &e)
                    {
                        cout<<e.what();
                    }
                }
                hThreadArray[1]=CreateThread(NULL,0,Traseu,NULL,0,&dwThreadIdArray[1]);
                if (hThreadArray[0] == NULL || hThreadArray[1]==NULL)
                {
                    throw("Eroare");
                    ExitProcess(3);
                }
                WaitForMultipleObjects(MAX_THREADS, hThreadArray, TRUE, INFINITE);
            }
            cout<<"Salariul e:"<<taximetrist1->Salariu()<<" lei pe cursa"<<endl;
            delay(5000);
            break;

        }
        case 6:
        {
            set<int, greater<int> >::iterator itr;
            for (itr = s1.begin(); itr != s1.end(); ++itr)
            {
                cout <<*itr<<" ";
            }
            cout << endl;
            cout<<"suma totala:"<<mySum<int>(s1);
            delay(5000);
            break;

        }
        default:
        {
            optiune=0;
            break;
        }
        }
        system("cls");
    }
    cout<<"Iesire din aplicatie cu succes!"<<endl;
    cout<<"Va mai asteptam...";

    ofstream g("baze.txt");
    g<<conturi.size()<<'\n';
    for(list<Cont>::iterator it=conturi.begin(); it!=conturi.end(); ++it)
        g<<*it;
    g.close();

    return 0;
}
