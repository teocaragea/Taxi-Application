#include <iostream>
#include <list>
#include <iterator>
#include<cstring>
#include<exception>
#include<fstream>
using namespace std;



///Caragea Theodor grupa 212
///GNU GCC compiler
///Profesor Eduar Szmetanca



class Vaccin
{
    double pret;
    double temperatura;
    string substante;
    string producatori;
public:
    Vaccin()
    {
        this->pret=0;
        this->temperatura=0;
    }
    virtual void afisareSchemaVaccinare()=0;
    friend ostream& operator<<(ostream& out,const Vaccin& ob)
    {
        out<<ob.pret<<" "<<ob.temperatura<<" "<<ob.producatori<<" "<<ob.substante;
        return out;
    }
    friend istream& operator>>(istream& in,Vaccin& ob)
    {
        in>>ob.pret>>ob.temperatura>>ob.substante>>ob.producatori;
        return in;
    }
    double getPret()
    {
        return this->pret;
    }
    string getProducatori()
    {
        return this->producatori;
    }

    ~Vaccin()
    {

    }






};
class VaccinAntigripal:public Vaccin
{
    char* tulpina;
    bool respectaRecomandari;
public:
    VaccinAntigripal():Vaccin()
    {
        this->tulpina=new char[strlen("anonim")+1];
        strcpy(this->tulpina,"anonim");
        this->respectaRecomandari=false;
    }
    void afisareSchemaVaccinare()
    {
        cout<<"se administrează la adulți o doză de 0.5 ml, iar la copii și adolescenți o doză de 0.3 ml, repetându-se din 2 în 2 ani"<<endl;
    }
    friend ostream& operator<<(ostream& out,const VaccinAntigripal& ob)
    {
        out<<(Vaccin&)ob;
        out<<ob.tulpina<<ob.respectaRecomandari;
        out<<endl;
        return out;
    }
    friend istream& operator>>(istream& in,VaccinAntigripal& ob)
    {
        in>>(Vaccin&)ob;
        char s[100];
        in>>s;
        ob.tulpina=new char[strlen(s)+1];
        strcpy(ob.tulpina,s);
        in>>ob.respectaRecomandari;
        return in;
    }
    ~VaccinAntigripal()
    {
        if(this->tulpina!=NULL)
        {
            delete[] tulpina;
        }
    }




};
class VaccinAntihepatic:public Vaccin
{
    string tip;
    string mod;
public:
    void afisareSchemaVaccinare()
    {
        cout<<"la copii cu vârstă mai mică de 1 an se adminstrează 2 injectări la un interval de o lună, a treia injectare după 6 luni de la prima administrare, la adulți conform schemei de imunizare recomandată de medic cel Antihepatită C doar la recomandarea medicului"<<endl;
    }
    friend ostream& operator<<(ostream& out,const VaccinAntihepatic& ob)
    {
        out<<(Vaccin&)ob;
        out<<ob.tip<<" "<<ob.mod;
        out<<endl;
        return out;
    }
    friend istream& operator>>(istream& in,VaccinAntihepatic& ob)
    {
        in>>(Vaccin&)ob;
        in>>ob.tip>>ob.mod;
        return in;
    }
    VaccinAntihepatic():Vaccin()
    {
        this->tip="anonim";
        this->mod="anonim";
    }
    ~VaccinAntihepatic()
    {

    }



};

class VaccinAntiSarsCov2:public Vaccin
{
    string medicamenteContraindicate;
    double rata;
    string efecteAdverse;
public:
    VaccinAntiSarsCov2():Vaccin()
    {
        this->rata=0;
    }
    friend ostream& operator<<(ostream& out,const VaccinAntiSarsCov2& ob)
    {
        out<<(Vaccin&)ob;
        out<<ob.rata;
        out<<ob.medicamenteContraindicate;
        out<<ob.efecteAdverse;
        out<<endl;
        return out;
    }
    friend istream& operator>>(istream& in,VaccinAntiSarsCov2& ob)
    {
        in>>(Vaccin&)ob;
        in>>ob.rata>>ob.medicamenteContraindicate>>ob.efecteAdverse;
        return in;
    }

    void afisareSchemaVaccinare()
    {
        cout<<"se administrează persoanelor cu vârstă de peste 16 ani, 2 doze la o perioadă de 21 zile."<<endl;
    }

};

class Comanda
{
    static int id;
    string data;
    string nume;
    string vac;
    int cantitate;
public:
    Comanda()
    {
        this->id++;
        this->data="NULL";
    }
    Comanda(string data,string nume,string vac,int cantinate)
    {
        this->id++;
        this->data=data;
        this->nume=nume;
        this->cantitate=cantinate;
        this->vac=vac;
    }
    friend ostream& operator<<(ostream& out,const Comanda& ob)
    {
        out<<ob.id<<" "<<ob.data<<" "<<ob.nume<<" "<<ob.vac<<" "<<ob.cantitate<<endl;
        return out;
    }
   friend ofstream& operator<<(ofstream& out,Comanda& ob)
   {
       out<<ob.id<<" "<<ob.data<<" "<<ob.nume<<" "<<ob.vac<<" "<<ob.cantitate<<'\n';
       return out;
   }
   friend istream& operator>>(istream& is,Comanda& ob)
   {
       ob.id++;
       is>>ob.data>>ob.nume>>ob.vac>>ob.cantitate;
       return is;

   }


};

int Comanda::id=0;
class ListaComenzi
{
    list<Comanda>lista;
public:
    ListaComenzi operator+(Comanda com)
    {
        this->lista.push_back(com);
        return *this;
    }
    Comanda operator[]( int index)
    {
        int i=1;
        list<Comanda>::iterator it;
        for(it=lista.begin(); it!=lista.end(); ++it)
        {
            if(index==i)
                return *it;
            i++;
        }
    }
    void AfisareFisier()
    {

        ofstream f("Comenzi.txt");
        list<Comanda>::iterator it;
        try
        {

            for(it=lista.begin(); it!=lista.end(); ++it)
            {
                f<<*it;
            }

        }
        catch(exception& e)
        {
            cout<<e.what();
        }

    }
    void Afisare()
    {
         list<Comanda>::iterator it;
        try
        {

            for(it=lista.begin(); it!=lista.end(); ++it)
            {
                cout<<*it;
            }

        }
        catch(const bad_alloc& e)
        {
            cout<<e.what();
        }
    }




};

template <typename T>
T mySum(list<Vaccin*>lista)
{
    T x=0;
    list<Vaccin*>::iterator it;
    for(it=lista.begin(); it!=lista.end(); ++it)
    {
        x+=(*it)->getPret;
    }

}




int main()
{
    /* demo
    VaccinAntigripal a;
    VaccinAntihepatic b;
    VaccinAntiSarsCov2 c;
    cin>>a>>b>>c;
    cout<<a<<b<<c;
    Vaccin* list[3];
    list[0]=new VaccinAntigripal();
    list[1]=new VaccinAntihepatic ();
    list[2]=new VaccinAntiSarsCov2();
    for(int i=0; i<3; i++)
        list[i]-> afisareSchemaVaccinare();
        Comanda com1("20-12-2020", "SpitalX","AntiSarsCov2",20);
    ListaComenzi lista;
    lista=lista+com1;
    cout<<lista[0];
    */
ListaComenzi lista;
    int optiune=5;
 Vaccin* list[3];
 int i=0;
    while(optiune!=0)
    {
        cout<<"1. Adăugarea unui vaccin nou"<<endl;
        cout<<"2. Afișarea tuturor vaccinurilor pe care le deține "<<endl;
        cout<<"3. Numele producătorilor pentru toate vaccinurile "<<endl;
        cout<<"4. Adăugarea unei comenzi "<<endl;
        cout<<"5. Afișarea tuturor comenzilor "<<endl;
        cout<<"6. Valorea comenzilor dintr-o anumită zi "<<endl;
        cout<<"7. Afișarea schemei de vaccinare pentru un anumit tip de vaccin "<<endl;
        cout<<"8. Exportul comenzilor într-un fișier .txt "<<endl;
        cout<<"0 pt a iesi "<<endl;
        cin>>optiune;

        switch(optiune)
        {
        case 1:
        {
      cout<<"Ce vaccin? 1-Antigripal 2-Antihepatic 3-Sars"<<endl;
      int vac;
      cin>>vac;
      if(vac==1)
      {

          VaccinAntigripal a;
          cin>>a; list[i]=&a;
      }
      if(vac==2)
      {
          VaccinAntihepatic b;
          cin>>b;list[i]=&b;

      }
      if(vac==3)
      {
          VaccinAntiSarsCov2 c;
          cin>>c;list[i]=&c;
      }
        }
        break;
        case 2:
        {
      for(int j=1;j<=i;j++)
        cout<<*(list[i]);
        }
        break;
        case 3:
        {
 for(int j=1;j<=i;j++)
        cout<<list[i]->getProducatori();
        }
        break;
        case 4:
        {
        Comanda a;
        cin>>a;
        lista=lista+a;
        }
        break;
        case 5:
        {

    lista.Afisare();
        }
        break;
        case 6:
        {

        }
        break;
        case 7:
        {
       cout<<"Ce vaccin? 1-Antigripal 2-Antihepatic 3-Sars"<<endl;
       VaccinAntigripal a;
    VaccinAntihepatic b;
    VaccinAntiSarsCov2 c;int vac;
    cin>>vac;
    if(vac==1)
        a.afisareSchemaVaccinare();
    if(vac==2)
        b.afisareSchemaVaccinare();
    if(vac==3)
        c.afisareSchemaVaccinare();
        }
        break;
        case 8:
        {

  lista.AfisareFisier();

        }
        break;

        }

    }




    return 0;
}
