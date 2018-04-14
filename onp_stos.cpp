#include <iostream>
using namespace std;
const int NIC=-2147483000;


struct Telement
{ int liczba;
  Telement *next;
};

Telement *stos;

void inicjuj() // na pocz¹tku na stosie nic nie ma
{
  stos=NULL;
}
bool pusty() // spr czy stos nie jest pusty
{
  return (stos==NULL);
 }
void wstaw(int i) // dodanie elementu na stos
{
 Telement *temp;
 temp=new Telement;
 temp->liczba=i;
 temp->next=stos;
 stos=temp;
}

int zdejmij()//pobiera wartosc, która jest aktualnie na wierzchu stosu
{ int pom;
    if (pusty())return NIC;
    else
    {pom= stos->liczba;
    stos=stos->next;
    return pom;}
}

int main()
{ char znak;
  int cyfra;
  string  wyrazenie;
  inicjuj();
  cout<<"Czy pusty: "<<pusty()<<endl;
  cin>>wyrazenie;
  for(int i=0;i<wyrazenie.size();i++)
      { znak=wyrazenie[i];
       if (znak=='+'){cyfra=zdejmij();wstaw(zdejmij()+cyfra);}else
       if (znak=='-'){cyfra=zdejmij();wstaw(zdejmij()-cyfra);}else
       if (znak=='*'){cyfra=zdejmij();wstaw(zdejmij()*cyfra);}else
       if (znak=='/'){cyfra=zdejmij();wstaw(zdejmij()/cyfra);}
       else {cyfra=znak-'0';wstaw(cyfra);}
       }
    cout<<zdejmij()<<endl;


}

