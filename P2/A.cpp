//Igor Lonak
#include <iostream>

using namespace std;

int sznurki = -1;

struct Wiazanie{
	Wiazanie *next;
	Wiazanie *prev;
    int Id1;
    char pierwsza;
    char druga;
    char trzecia;
    Wiazanie(char A1, char B1, char C1, int id1);

};

struct BazaWiazan{
Wiazanie* head;
Wiazanie* tail;

void DeleteWiazanie (char A2, char B2, char C2, int id2);
void AddWiazanie (char A2,char B2,char C2,int id2);

 BazaWiazan(){
head=0;
tail=0;}

void sortuj(Wiazanie* &l)

{

   Wiazanie* posortowana = 0;

   while(l != 0)

   {

      Wiazanie *max = l,

             *przed_max = 0;


      for(Wiazanie *p = l, *i = l->next;

         i != 0;
         p = i, i = i->next)

      {

         if(i->pierwsza > max->pierwsza)
         {

            max = i;
            przed_max = p;

         }
         else if (i->pierwsza==max->pierwsza)
         {
             if(i->druga>max->druga)
             {
                 max = i;
                 przed_max = p;
             }
             else if(i->druga==max->druga)
             {
                 if(i->trzecia>max->trzecia)
                 {
                     max = i;
                        przed_max = p;
                 }
                 else if(i->trzecia==max->trzecia)
                 {
                     if(i->Id1>max->Id1)
                     {
                         max = i;
                         przed_max = p;
                     }
                 }
             }
         }

      }



      if(przed_max != 0)

         przed_max->next = max->next;
      else

         l = max->next;

      max->next = posortowana;

      posortowana = max;

   }

   l = posortowana;

}};

struct Koralik {
    Koralik *next;
    Koralik *former;
    int Id;
    BazaWiazan* baza;
    Koralik();
    void DisplayWiazania();

};

void Koralik::DisplayWiazania()
{
    if(baza)
    {
        Wiazanie* temp= baza->head;


        baza->sortuj(temp);

            while(temp)
            {
                cout<<temp->pierwsza<<temp->druga<<temp->trzecia<<" "<<temp->Id1<<" ";
                temp=temp->next;
            }
    }

}

Koralik::Koralik() {
    next = 0;
    former = 0;
    baza=0;
}


struct Sznurek {
    Sznurek *nastepny;
    Sznurek *poprzedni;
    Koralik *pierwszy;
    Koralik *ostatni;
    char a;
    char b;
    char c;

    void AddKoralik(Sznurek *tmp, int id);

    void DisplayKoralik();

    Sznurek();
};



Wiazanie::Wiazanie(char A1, char B1, char C1, int id1) {

    pierwsza=A1;
    druga=B1;
    trzecia=C1;
    Id1=id1;

}

Sznurek::Sznurek() {
    nastepny = 0;
    poprzedni = 0;
    pierwszy = 0;
}


struct Lista{

    Sznurek *pierwsza;
    Sznurek *ostatnia;

    void AddSznurek(char A, char B, char C);

    void AddBead(char A, char B, char C, int id);

    bool CzyKoraliki(char A1, char B1, char C1, int id1, char A2, char B2, char C2, int id2);

    void DeleteWiazanie(char A1, char B1, char C1, int id1, char A2, char B2, char C2, int id2);

	void DeleteKoralAndLinks(char a, char b, char c, int koral);

    void RemoveSznurek();

    void DisplaySznurki();

    void Display();

    void DodajWiazanie(char A1, char B1, char C1, int id1, char A2, char B2, char C2, int id2);

    void UsunWiazanie(char A1, char B1, char C1, int id1, char A2, char B2, char C2, int id2);

    void SwitchKoralik(char A1, char B1, char C1, int id1, char A2, char B2, char C2);

    void UsunSznur(char A1,char B1,char C1);

    void UsunNiepotrzebne(char A1, char B1, char C1, int id1,char A2,char B2,char C2);
    Lista();
};

Lista::Lista() {
    pierwsza = 0;
}

void Sznurek::AddKoralik(Sznurek *tmp, int id) {

	Koralik *nowy = new Koralik;
    nowy->Id = id;
    nowy->baza= new BazaWiazan();
    if (pierwszy == 0) {
        pierwszy = nowy;
        ostatni = nowy;
    } else {
        bool test = true;
        Koralik *temp = pierwszy;
        while (temp->next) {
            if (id < temp->Id) {
                test = false;
                if (temp->former == 0) {
                    pierwszy = nowy;
                    nowy->former = 0;
                    nowy->next = temp;
                    temp->former = nowy;
                } else {
                    nowy->former = temp->former;
                    temp->former->next = nowy;
                    temp->former = nowy;
                    nowy->next = temp;
                }
                break;
            }
            temp = temp->next;
        }
        if (temp->next == 0) {
            if (id < temp->Id && test) {
                test = false;
                if (temp->former == 0) {
                    pierwszy = nowy;
                    nowy->former = 0;
                    nowy->next = temp;
                    temp->former = nowy;
                } else {
                    nowy->next = temp;
                    nowy->former = temp->former;
                    temp->former->next = nowy;
                    temp->former = nowy;
                }
            }
        }
        temp=NULL;
        delete temp;
        if (test) {
            nowy->former = ostatni;
            ostatni = nowy;
            if (nowy->former) {
                nowy->former->next = nowy;
            }
        }
    }
    nowy=NULL;
    delete nowy;
}

void Sznurek::DisplayKoralik() {

	Koralik *tmp = pierwszy;

	while(tmp){

        cout << tmp->Id<<" " ;
        tmp->DisplayWiazania();
        cout<<endl;
        tmp = tmp->next;
    }
    delete tmp;
}

void Lista::AddBead(char A, char B, char C, int id) {
    Sznurek *temp = pierwsza;
    while (temp) {
        if (A == temp->a && B == temp->b && C == temp->c) {
            temp->AddKoralik(temp, id);
        }
        temp = temp->nastepny;
    }
    delete temp;
}

void Lista::AddSznurek(char A, char B, char C) {

	Sznurek *nowy = new Sznurek;
    sznurki++;
    nowy->a = A;
    nowy->b = B;
    nowy->c = C;
    if (pierwsza == 0) {
        pierwsza = nowy;
        ostatnia = nowy;
    } else {
        bool test = true;
        Sznurek *temp = pierwsza;
        if (A < temp->a || (A == temp->a && B < temp->b) || (A == temp->a && B == temp->b && C < temp->c)) {
            if (sznurki <= 1) {
                test = false;
                nowy->nastepny = temp;
                pierwsza = nowy;
                nowy->poprzedni = 0;
                temp->nastepny = 0;
                nowy->nastepny->poprzedni = nowy;
            }
        }
        while (temp->nastepny) {
            if (A < temp->a || (A == temp->a && B < temp->b) || (A == temp->a && B == temp->b && C < temp->c)) {
                test = false;
                if (temp->poprzedni == 0) {
                    nowy->nastepny = temp;
                    nowy->poprzedni = 0;
                    pierwsza = nowy;
                    temp->poprzedni = nowy;
                } else {
                    nowy->nastepny = temp;
                    nowy->poprzedni = temp->poprzedni;
                    temp->poprzedni->nastepny = nowy;
                    temp->poprzedni = nowy;
                }
                break;
            }
            temp = temp->nastepny;
        }
        if (temp->nastepny == 0) {
            if ((A < temp->a || (A == temp->a && B < temp->b) || (A == temp->a && B == temp->b && C < temp->c)) &&
                test) {
                test = false;
                nowy->nastepny = temp;
                nowy->poprzedni = temp->poprzedni;
                temp->poprzedni->nastepny = nowy;
                temp->poprzedni = nowy;
            }
        }
        if (test) { // nie znaleziono mniejszeego
            nowy->poprzedni = ostatnia;
            ostatnia = nowy;
            if (nowy->poprzedni) {
                nowy->poprzedni->nastepny = nowy;
            }
        }
    }
    nowy=NULL;
    delete nowy;
}

void Lista::Display(){

    Sznurek *temp = pierwsza;

    while (temp){

        cout << temp->a << temp->b << temp->c << endl;
        temp->DisplayKoralik();
        temp = temp->nastepny;
    }
    delete temp;

}

bool Lista::CzyKoraliki(char A1, char B1, char C1, int id1, char A2, char B2, char C2, int id2) {

	Sznurek *temp = pierwsza;
	Koralik *koral = new Koralik;

    bool koralik1 = false, koralik2 = false;

    while (temp){

        if (A1 == temp->a && B1 == temp->b && C1 == temp->c) {

        	koral = temp->pierwszy;

            while(koral) {

				if(koral->Id == id1) koralik1 = true;

                koral = koral->next;
            }
        }

		if (temp->a == A2 && temp->b == B2 && temp->c == C2) {

            koral = temp->pierwszy;

			while(koral) {

				if(koral->Id == id2) koralik2 = true;

                koral = koral->next;
            }
        }

        temp = temp->nastepny;
    }
    delete koral;
    if(koralik1==true&&koralik2==true)return true;
    return false;


}

void BazaWiazan::DeleteWiazanie( char A2, char B2, char C2, int id2) {


            Wiazanie *temp2 ;
            temp2= head;
            while(temp2){
                    if(temp2->Id1==id2&&temp2->pierwsza==A2&&temp2->druga==B2&&temp2->trzecia==C2)
                    {
                        if(temp2==head||temp2==tail)
                        {if(temp2==head)
                        {
                            if(head==tail)
                            {
                                head=0;
                                tail=0;
                            }
                            else{head=head->next;
                            if(head)head->prev=0;}
                        }
                        if(temp2==tail)
                        {
                            if(head==tail)
                            {
                                head=0;
                                tail=0;
                            }
                            else{
                                    tail=tail->prev;
                            if(tail)tail->next=0;
                            }
                        }
                        }
                       // else{
                        //temp2->prev->next=temp2->next;
                        //temp2->next->prev=temp2->prev;}

                    }
                temp2 = temp2->next;
            }

}

void BazaWiazan::AddWiazanie(char A2, char B2, char C2, int id2){

Wiazanie* nowe =new Wiazanie(A2,B2,C2,id2);
if(tail){
tail->next=nowe;
nowe->prev=tail;
tail=nowe;
nowe->next=NULL;
}
else {head=nowe;
tail=nowe;
nowe->next=NULL;}
nowe=NULL;
delete nowe;

}

void Lista::DodajWiazanie(char A1,char B1,char C1,int id1,char A2, char B2, char C2, int id2)
{
    Sznurek* temp=pierwsza;
    Koralik * koral;
    while(temp)
    {
        if (A1 == temp->a && B1 == temp->b && C1 == temp->c) {

        	koral = temp->pierwszy;

            while(koral) {

				if(koral->Id == id1) {
                        koral->baza->AddWiazanie(A2,B2,C2,id2);
                }
                koral = koral->next;
            }

    }
    temp=temp->nastepny;
    }
    koral=NULL;
    delete koral;
    delete temp;
}

void Lista::UsunWiazanie(char A1,char B1,char C1,int id1,char A2, char B2, char C2, int id2)
{
    Sznurek* temp=pierwsza;
    Koralik * koral;
    while(temp)
    {
        if (A1 == temp->a && B1 == temp->b && C1 == temp->c) {

        	koral = temp->pierwszy;

            while(koral) {

				if(koral->Id == id1) koral->baza->DeleteWiazanie(A2,B2,C2,id2);

                koral = koral->next;
            }
    }
    temp=temp->nastepny;
    }

}

void Lista::DeleteKoralAndLinks(char s1, char s2, char s3, int id1){

	Sznurek* temp=pierwsza;
	Koralik* temp1;
	while(temp)
    {
        temp1=temp->pierwszy;
        if(temp->a==s1&&temp->b==s2&&temp->c==s3)
        {
            while(temp1)
            {
                if(temp1->Id==id1)
                {
                    if(temp1==temp->pierwszy||temp1==temp->ostatni)
                    {
                        if(temp1==temp->pierwszy)
                        {
                            temp->pierwszy=temp->pierwszy->next;
                            if(temp->pierwszy)temp->pierwszy->former=0;
                        }
                        if(temp1==temp->ostatni)
                        {
                            temp->ostatni=temp->ostatni->former;
                            if(temp->ostatni)temp->ostatni->next=0;
                        }
                    }
                    else{temp1->former->next=temp1->next;
                    temp1->next->former=temp1->former;}


                }
                temp1=temp1->next;
            }
        }
        temp=temp->nastepny;
    }
    temp1=NULL;
    delete temp1;
    delete temp;

}

void Lista::SwitchKoralik(char A1, char B1, char C1, int id1, char A2, char B2, char C2)
{
    Sznurek* temp=pierwsza;
    Koralik* temp1;
    Koralik* temp2;

    while(temp)
    {
        temp1=temp->pierwszy;
        if(temp->a==A1&&temp->b==B1&&temp->c==C1)
        {
            while(temp1)
            {
                if(temp1->Id==id1)
                {
                    temp2=temp1;
                    if(temp2==temp->pierwszy||temp2==temp->ostatni)
                    {
                        if(temp2==temp->pierwszy)
                        {
                            temp->pierwszy=temp2->next;
                            if(temp->pierwszy)
                            {
                                temp->pierwszy->former=0;
                            }
                        }
                        if(temp2==temp->ostatni)
                        {
                            temp->ostatni=temp2->former;
                            if(temp->ostatni)
                            {
                                temp->ostatni->next=0;
                            }

                        }
                    }
                    else{
                            temp2->former->next=temp2->next;
                            temp2->next->former=temp2->former;
                        }
                }
                temp1=temp1->next;
            }
        }
        temp=temp->nastepny;

    }
temp2->next=0;
temp2->former=0;


    temp=pierwsza;
    while(temp)
    {
        if(temp->a==A2&&temp->b==B2&&temp->c==C2)
        {
         temp1=temp->pierwszy;
         if(!temp1)
         {
             temp->pierwszy=temp2;
             temp->ostatni=temp2;
             temp2->next=0;
             temp2->former=0;

         }
         else {while(temp1->Id<temp2->Id&&temp1->next!=0)
         {
             temp1=temp1->next;
         }

         if(temp->pierwszy==temp1||temp1->next==0)
         {
             if(temp1==temp->pierwszy&&temp1->next==0)
             {
                 temp2->next=temp1;
                 temp1->former=temp2;
                 temp->pierwszy=temp2;
                 temp->ostatni->former=temp2;
             }
            else{ if(temp1==temp->pierwszy)
             {

                 temp2->next=temp1;
                 temp1->former=temp2;
                 temp->pierwszy=temp2;


             }
              if(temp1->next==NULL)
             {
                 if(temp1->Id>temp2->Id)
                 {
                     temp2->former=temp1->former;
                     temp1->former->next=temp2;
                     temp1->former=temp2;
                     temp2->next=temp1;

                 }
                 else
                 {temp->ostatni->next=temp2;
                 temp2->former=temp->ostatni;
                 temp->ostatni=temp2;}
             }
            }
         }
         else
         {
             temp2->former=temp1->former;
             temp1->former->next=temp2;
             temp2->next=temp1;
             temp1->former=temp2;
         }
        }
        }
        temp=temp->nastepny;
    }


}

void Lista::UsunSznur(char A1, char B1, char C1)
{
    Sznurek* temp=pierwsza;
    Koralik* temp1;

    while(temp)
    {
        if(temp->a==A1&&temp->b==B1&&temp->c==C1)
        {
            temp1=temp->pierwszy;

            if(temp==pierwsza||temp==ostatnia)
            {
                if(temp==pierwsza)
                {
                    pierwsza=temp->nastepny;

                }
                if(temp==ostatnia)
                {
                    ostatnia=ostatnia->poprzedni;
                    if(ostatnia)ostatnia->nastepny=0;
                }
            }
            else{
                temp->nastepny->poprzedni=temp->poprzedni;
                temp->poprzedni->nastepny=temp->nastepny;
            }

        }
        temp=temp->nastepny;
    }
    delete temp;
    delete temp1;
}

void Lista::UsunNiepotrzebne(char A1, char B1, char C1, int id1,char A2,char B2,char C2)
{
    Sznurek* temp=pierwsza;
    Koralik* temp1;
    BazaWiazan* temp2;
    Wiazanie* temp3;
    while(temp)
    {
        temp1=temp->pierwszy;
        while(temp1)
        {
            temp2=temp1->baza;
            if(temp2)
            {
                temp3=temp2->head;
                while(temp3)
                {
                    if(temp3->pierwsza==A1&&temp3->druga==B1&&temp3->trzecia==C1&&temp3->Id1)
                    {
                        temp3->pierwsza=A2;
                        temp3->druga=B2;
                        temp3->trzecia=C2;
                    }
                    temp3=temp3->next;
                }
            }
            temp1=temp1->next;

        }
        temp=temp->nastepny;

    }

}

int main(){

    Lista *baza = new Lista;

    char operacja;
    int koral, koralA;
    char a, b, c, A, B, C;
    do {
        //cout << "Polecenie" << endl;
        cin >> operacja;

        if (operacja == 'S') { // Dodanie pustego Sznura
            cin >> a >> b >> c;
            baza->AddSznurek(a, b, c);
        }

		else if (operacja == 'B') { // Dodanie koralika do Sznura
            cin >> koral >> a >> b >> c;
            if(koral>=100&&koral<=999)
            baza->AddBead(a, b, c, koral);
        }

		else if (operacja == 'L') { // Dodanie wiazania
            cin >> koral >> a >> b >> c >> koralA >> A >> B >> C;
            if(koral>=100&&koral<=999)
            if(baza->CzyKoraliki(a, b, c, koral, A, B, C, koralA))
            {baza->DodajWiazanie(a,b,c,koral,A,B,C,koralA);}
        }

		else if (operacja == 'U') { // Usuniecie powiazania
            cin >> koral >> a >> b >> c >> koralA >> A >> B >> C;
            if(koral>=100&&koral<=999)
            if(baza->CzyKoraliki(a, b, c, koral, A, B, C, koralA)){}
			{
			    baza->UsunWiazanie(a, b, c, koral, A, B, C, koralA);

			}
        }

		else if (operacja == 'D') { // Usuniecie koralika wraz z jego powiazaniami
            cin >> koral >> a >> b >> c;
            if(koral>=100&&koral<=999)
            if(baza->CzyKoraliki(a, b, c, koral, a, b, c, koral))
			{
			    baza->DeleteKoralAndLinks(a, b, c, koral);

			}
        }

		else if (operacja == 'M') { // Przeniesienie koralika
            cin >> koral >> a >> b >> c >> A >> B >> C;
            if(koral>=100&&koral<=999)
            if(baza->CzyKoraliki(a, b, c, koral, a, b, c, koral))
           {
               baza->SwitchKoralik(a,b,c,koral,A,B,C);
               baza->UsunNiepotrzebne(a,b,c,koral,A,B,C);
            }

        }

		else if (operacja == 'R') { // Usuniecie Sznura
            cin >> a >> b >> c;
            baza->UsunSznur(a,b,c);
        }

		else if (operacja == 'P') { // wyswietl
            baza->Display();
        }

    } while (operacja != 'F'); // zakoncz

    delete (baza);

	return 0;
}




















