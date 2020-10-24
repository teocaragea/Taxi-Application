#include <iostream>
#include <string.h>
using namespace std;

class Student
{
private:
    const int ID_Matricol;
    int varsta;
    char* nume;
    int nrNote;
    int* note;
public:
    static int anCurent;
    static void mesaj()
    {
        cout<<"bine ati venit\n";
    }
    Student():ID_Matricol(000)
    {
        this->varsta=0;
        this->nume=new char[strlen("Anonim")+1];
        strcpy(this->nume,"Anonim");


    }
    Student(int id,int varsta, char* nume, int nrNote,int* note):ID_Matricol(id)
    {
        this->varsta=varsta;

        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);

        this->nrNote=nrNote;

        this->note=new int[nrNote];

        for(int i=0; i<nrNote; i++)
            this->note[i]=note[i];



    }

    void afisare()
    {
        cout<<"Student "<<this->nume<<" are urmatoarele note: ";
        for(int i=0; i<this->nrNote; i++)
            cout<<this->note[i]<<" ";
    }
    char* getNume()
    {

        return this->nume;
    }
    int* getNote()
    {
        return this->note;
    }
    void setVarsta(int varsta)
    {
        this->varsta=varsta;
    }
    int getvarsta()
    {
        return this->varsta;
    }
    void setnume(char* nume)
    {
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(this->nume)+1];
        strcpy(this->nume,nume);
    }

    ~Student()
    {
        if(this->note!=NULL)
            delete[] this->note;
        if(this->nume!=NULL)
            delete[] this->nume;





    }
};

int Student::anCurent=2;


int main()
{
    Student::mesaj();

    Student s;
    char nume[]= {"POO"};
    int note[]= {5,9,5,5};
    Student s2(101,3,nume,4,note);
    int* marks=s2.getNote();
    cout<<*(marks+1);


    return 0;
}
