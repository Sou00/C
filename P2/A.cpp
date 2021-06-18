//Igor Lonak
#include <iostream>

using namespace std;

int sznurki = -1;

bool PorownajWiazanie(int Id1,char a1,char b1, char c1, int Id2,char a2, char b2, char c2){
    if(a1 < a2)return true;
    else if(a1 == a2 && b1 < b2)return true;
    else if(a1 == a2 && b1 == b2 && c1 < c2)return true;
    else if(a1 == a2 && b1 == b2 && c1 == c2 && Id1< Id2)return true;
    else return false;

}

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
        tail=0;
    }
};

struct Koralik {
    Koralik *next;
    Koralik *prev;
    int Id;
    BazaWiazan* baza;
    Koralik();
    void DisplayWiazania();
    void UsunWiazania();
};

void Koralik::DisplayWiazania()
{
    if(baza)
    {
        Wiazanie *temp= baza->head;

        while(temp)
        {
            cout<<temp->pierwsza<<temp->druga<<temp->trzecia<<" "<<temp->Id1<<" ";
            temp=temp->next;
        }

    }

}

void Koralik::UsunWiazania() {
    Wiazanie *temp=baza->head;
    while(temp){
        if(temp->next){
            temp=temp->next;
            delete temp->prev;
            temp->prev=0;
        }
        else{
            delete temp;
            temp=0;
            baza->head=0;
        }
    }
}

Koralik::Koralik() {
    next = 0;
    prev = 0;
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

    void AddKoralik(int id);

    void DisplayKoralik();

    void UsunKoraliki();

    Sznurek();
};

void Sznurek::UsunKoraliki() {
    Koralik *temp=pierwszy;
    while(temp)
    {
        if(temp->next){
            temp=temp->next;
            temp->prev->UsunWiazania();
            delete temp->prev->baza;
            delete temp->prev;
            temp->prev=0;
        }
        else{
            temp->UsunWiazania();
            delete temp->baza;
            delete temp;
            temp=0;
            pierwszy=0;
            ostatni=0;
        }
    }
}

Wiazanie::Wiazanie(char A1, char B1, char C1, int id1) {

    pierwsza=A1;
    druga=B1;
    trzecia=C1;
    Id1=id1;
    next=0;
    prev=0;

}

Sznurek::Sznurek() {
    nastepny = 0;
    poprzedni = 0;
    pierwszy = 0;
}


struct Lista{

    Sznurek *pierwszy;
    Sznurek *ostatni;

    void AddSznurek(char A, char B, char C);

    void AddBead(char A, char B, char C, int id);

    void DeleteKoral(char a, char b, char c, int koral);

    void Display();

    void DodajWiazanie(char A1, char B1, char C1, int id1, char A2, char B2, char C2, int id2);

    void UsunWiazanie(char A1, char B1, char C1, int id1, char A2, char B2, char C2, int id2);

    void SwitchKoralik(char A1, char B1, char C1, int id1, char A2, char B2, char C2);

    void UsunSznur(char A1,char B1,char C1);

    bool CzySznurek(char A, char B, char C){
        Sznurek *temp= pierwszy;
        while(temp)
        {
            if(temp->a==A && temp->b==B && temp->c==C)return true;
            temp=temp->nastepny;
        }
        return false;
    }
    bool CzyKoralik(int Id1, char A, char B, char C){
        Sznurek *sznurektemp= pierwszy;
        while(sznurektemp ){
            if(sznurektemp->a==A && sznurektemp->b==B && sznurektemp->c==C){
                Koralik *koraliktemp= sznurektemp->pierwszy;
                while(koraliktemp){
                    if(koraliktemp->Id==Id1)return true;
                    koraliktemp=koraliktemp->next;
                }
            }
            sznurektemp=sznurektemp->nastepny;
        }
        return false;
    }
    Lista();
};

Lista::Lista() {
    pierwszy = 0;
}

void Sznurek::AddKoralik( int id) {

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
                if (temp->prev == 0) {
                    pierwszy = nowy;
                    nowy->prev = 0;
                    nowy->next = temp;
                    temp->prev = nowy;
                } else {
                    nowy->prev = temp->prev;
                    temp->prev->next = nowy;
                    temp->prev = nowy;
                    nowy->next = temp;
                }
                break;
            }
            temp = temp->next;
        }
        if (temp->next == 0) {
            if (id < temp->Id && test) {
                test = false;
                if (temp->prev == 0) {
                    pierwszy = nowy;
                    nowy->prev = 0;
                    nowy->next = temp;
                    temp->prev = nowy;
                } else {
                    nowy->next = temp;
                    nowy->prev = temp->prev;
                    temp->prev->next = nowy;
                    temp->prev = nowy;
                }
            }
        }

        if (test) {
            nowy->prev = ostatni;
            ostatni = nowy;
            if (nowy->prev) {
                nowy->prev->next = nowy;
            }
        }
    }

}

void Sznurek::DisplayKoralik() {

    Koralik *tmp = pierwszy;

    while(tmp){

        cout << tmp->Id<<" " ;
        tmp->DisplayWiazania();
        cout<<endl;
        tmp = tmp->next;
    }
}

void Lista::AddBead(char A, char B, char C, int id) {
    Sznurek *temp = pierwszy;
    while (temp) {
        if (A == temp->a && B == temp->b && C == temp->c) {
            temp->AddKoralik(id);
        }
        temp = temp->nastepny;
    }
}

void Lista::AddSznurek(char A, char B, char C) {

    Sznurek *nowy = new Sznurek;
    sznurki++;
    nowy->a = A;
    nowy->b = B;
    nowy->c = C;
    if (pierwszy == 0) {
        pierwszy = nowy;
        ostatni = nowy;
    } else {
        bool test = true;
        Sznurek *temp = pierwszy;
        if (A < temp->a || (A == temp->a && B < temp->b) || (A == temp->a && B == temp->b && C < temp->c)) {
            if (sznurki <= 1) {
                test = false;
                nowy->nastepny = temp;
                pierwszy = nowy;
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
                    pierwszy = nowy;
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
            nowy->poprzedni = ostatni;
            ostatni = nowy;
            if (nowy->poprzedni) {
                nowy->poprzedni->nastepny = nowy;
            }
        }
    }
}

void Lista::Display(){

    Sznurek *temp = pierwszy;

    while (temp){
        cout << temp->a << temp->b << temp->c << endl;
        temp->DisplayKoralik();
        temp = temp->nastepny;
    }
}

void BazaWiazan::DeleteWiazanie( char A2, char B2, char C2, int id2) {

    Wiazanie *temp2 ;
    temp2= head;
    while(temp2){
        if(temp2->Id1==id2&&temp2->pierwsza==A2&&temp2->druga==B2&&temp2->trzecia==C2){
            if(temp2==head||temp2==tail){
                if(temp2==head)
                {
                    if(head==tail)
                    {
                        delete head;
                        head=0;
                        tail=0;
                        temp2=0;
                    }
                    else{
                        temp2=temp2->next;
                        if(temp2){
                            delete temp2->prev;
                            temp2->prev=0;
                            head=temp2;
                        }
                    }
                }
                else if(temp2==tail)
                {
                    if(head==tail)
                    {
                        delete head;
                        head=0;
                        tail=0;
                        temp2=0;
                    }
                    else{
                        temp2=temp2->prev;
                        if(temp2){
                            delete temp2->next;
                            temp2->next=0;
                            tail=temp2;
                        }
                    }
                }
            }
            else{
                temp2->prev->next=temp2->next;
                temp2->next->prev=temp2->prev;
                delete temp2;
                temp2=0;
            }

        }
        else temp2 = temp2->next;
    }

}

void BazaWiazan::AddWiazanie(char A2, char B2, char C2, int id2){

    Wiazanie* nowe =new Wiazanie(A2,B2,C2,id2);
    Wiazanie* temp = head;
    if(!temp){
        head=nowe;
        tail=nowe;
    }
    else{
        while(temp && !PorownajWiazanie(id2, A2, B2, C2,temp->Id1,temp->pierwsza,temp->druga,temp->trzecia))
        {
            temp=temp->next;
        }
        if(!temp)
        {
            nowe->prev=tail;
            tail->next=nowe;
            tail=nowe;
        }
        else if(temp!=head){
            nowe->prev=temp->prev;
            nowe->next=temp;
            temp->prev->next=nowe;
            temp->prev=nowe;
        }
        else{
            nowe->next=temp;
            temp->prev=nowe;
            head=nowe;
        }

    }
}

void Lista::DodajWiazanie(char A1,char B1,char C1,int id1,char A2, char B2, char C2, int id2)
{
    Sznurek* temp=pierwszy;
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
}

void Lista::UsunWiazanie(char A1,char B1,char C1,int id1,char A2, char B2, char C2, int id2)
{
    Sznurek* temp=pierwszy;
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

void Lista::DeleteKoral(char s1, char s2, char s3, int id1){

    Sznurek* temp=pierwszy;
    Koralik* temp1;
    while(temp){
        temp1=temp->pierwszy;
        if(temp->a==s1&&temp->b==s2&&temp->c==s3) {
            while (temp1) {
                if (temp1->Id == id1) {
                    if (temp1 == temp->pierwszy || temp1 == temp->ostatni) {
                        if (temp1 == temp->pierwszy) {
                            if (temp1->next) {
                                temp1 = temp1->next;
                                temp1->prev->UsunWiazania();
                                delete temp1->prev->baza;
                                delete temp1->prev;
                                temp1->prev = 0;
                                temp->pierwszy=temp1;
                            }
                            else {
                                temp1->UsunWiazania();
                                delete temp1->baza;
                                delete temp1;
                                temp1=0;
                                temp->pierwszy=0;
                            }
                        }
                        else if (temp1 == temp->ostatni) {
                            if (temp1->prev) {
                                temp1 = temp1->prev;
                                temp1->next->UsunWiazania();
                                delete temp1->next->baza;
                                delete temp1->next;
                                temp1->next = 0;
                                temp->ostatni=temp1;
                            }
                            else {
                                temp1->UsunWiazania();
                                delete temp1->baza;
                                delete temp1;
                                temp1=0;
                            }
                        }
                    }
                    else {
                        temp1->prev->next = temp1->next;
                        temp1->next->prev = temp1->prev;
                        temp1->UsunWiazania();
                        delete temp1->baza;
                        delete temp1;
                        temp1=0;
                    }
                }
                else temp1 = temp1->next;
            }
        }
        temp=temp->nastepny;
    }
}

void Lista::SwitchKoralik(char A1, char B1, char C1, int id1, char A2, char B2, char C2)
{
    Sznurek* temp=pierwszy;
    Koralik* temp1;
    Koralik* temp2;

    while(temp)
    {
        temp1=temp->pierwszy;
        if(temp->a==A1&&temp->b==B1&&temp->c==C1)
        {
            while(temp1 && temp1->Id!=id1){
                temp1=temp1->next;
            }
            if(temp1){
                temp2=temp1;
                if(temp1==temp->pierwszy){
                    if(temp1==temp->ostatni){
                        temp->pierwszy=0;
                        temp->ostatni=0;
                    }
                    else{
                        temp->pierwszy=temp->pierwszy->next;
                        temp->pierwszy->prev=0;
                    }
                }
                else if(temp1==temp->ostatni){
                    temp->ostatni=temp->ostatni->prev;
                    temp->ostatni->next=0;
                }
                else{
                    temp1->prev->next=temp1->next;
                    temp1->next->prev=temp1->prev;
                }
            }
        }
        temp=temp->nastepny;

    }
    temp2->next=0;
    temp2->prev=0;


    temp=pierwszy;
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
                temp2->prev=0;

            }
            else {
                while(temp1 && temp1->Id<temp2->Id )
                {
                    temp1=temp1->next;
                }

                if(temp1)
                {
                    if(temp1==temp->pierwszy&&temp1->next==0)
                    {
                        temp2->next=temp1;
                        temp1->prev=temp2;
                        temp->pierwszy=temp2;
                        temp->ostatni->prev=temp2;
                    }
                    else{
                        if(temp1==temp->pierwszy)
                        {

                            temp2->next=temp1;
                            temp1->prev=temp2;
                            temp->pierwszy=temp2;

                        }
                        else{
                            temp2->next=temp1;
                            temp1->prev->next=temp2;
                            temp2->prev=temp1->prev;
                            temp1->prev=temp2;
                        }
                    }
                }
                else
                {
                    temp->ostatni->next=temp2;
                    temp2->prev=temp->ostatni;
                    temp->ostatni=temp2;
                }
            }
        }
        temp=temp->nastepny;
    }


}

void Lista::UsunSznur(char A1, char B1, char C1)
{
    Sznurek* temp=pierwszy;

    while(temp){
        if(temp->a==A1&&temp->b==B1&&temp->c==C1){
            if(temp==pierwszy||temp==ostatni){
                if(temp==pierwszy){
                    temp->UsunKoraliki();

                    if(temp->nastepny){
                        temp=temp->nastepny;
                        delete temp->poprzedni;
                        temp->poprzedni=0;
                        pierwszy=temp;
                    }
                    else{
                        delete temp;
                        temp=0;
                        pierwszy=0;
                        ostatni=0;
                    }
                }
                else if(temp==ostatni){
                    temp->UsunKoraliki();
                    if(temp->poprzedni){
                        temp=temp->poprzedni;
                        delete temp->nastepny;
                        temp->nastepny=0;
                        ostatni=temp;
                    }
                    else{
                        delete temp;
                        temp=0;
                        pierwszy=0;
                    }
                }
            }
            else{
                temp->nastepny->poprzedni=temp->poprzedni;
                temp->poprzedni->nastepny=temp->nastepny;
                temp->UsunKoraliki();
                delete temp;
                temp=0;
            }
        }
        else temp=temp->nastepny;
    }
}

int main(){

    Lista *baza = new Lista;

    char operacja;
    int koral, koralA;
    char a, b, c, A, B, C;
    do {
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
            if(koral>=100&&koral<=999){
                baza->DodajWiazanie(a,b,c,koral,A,B,C,koralA);
            }
        }
        else if (operacja == 'U') { // Usuniecie powiazania
            cin >> koral >> a >> b >> c >> koralA >> A >> B >> C;
            if(koral>=100&&koral<=999)
                if(baza->CzyKoralik(koral,a,b,c)){
                    baza->UsunWiazanie(a, b, c, koral, A, B, C, koralA);
                }
        }
        else if (operacja == 'D') { // Usuniecie koralika wraz z jego powiazaniami
            cin >> koral >> a >> b >> c;
            if(koral>=100&&koral<=999)
                if(baza->CzyKoralik(koral, a, b, c)){
                    baza->DeleteKoral(a, b, c, koral);
                }
        }
        else if (operacja == 'M') { // Przeniesienie koralika
            cin >> koral >> a >> b >> c >> A >> B >> C;
            if(koral>=100&&koral<=999)
                if (baza->CzySznurek(A,B,C) && baza->CzySznurek(a,b,c)&& baza->CzyKoralik(koral,a,b,c)){
                    baza->SwitchKoralik(a,b,c,koral,A,B,C);
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

    Sznurek *temp=baza->pierwszy;

    while(temp){
        temp->UsunKoraliki();
        if(temp->nastepny){
            temp=temp->nastepny;
            delete temp->poprzedni;
            temp->poprzedni=0;
        }
        else{
            delete temp;
            temp=0;
            baza->pierwszy=0;
        }
    }
    delete (baza);

    return 0;
}
