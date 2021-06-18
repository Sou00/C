//Igor Łonak

#include <iostream>
#include <string>

using namespace std;

class CAESAR_CLASS;

class PLAYER_CLASS{
public:
    unsigned int maxhp;
    unsigned int hp;
    unsigned int ad;
    unsigned int agi;
    PLAYER_CLASS* next;
    friend class CAESAR_CLASS;
    friend class SQUAD_CLASS;
public:
    virtual unsigned int getRemainingHealth()=0;
    virtual unsigned int getDamage()=0;
    virtual unsigned int getAgility()=0;
    virtual string getId()=0;
    virtual unsigned int getDef(){return 0;};
    virtual void takeDamage(unsigned int dmg)=0;
    virtual void applyWinnerReward()=0;
    virtual void cure()=0;
    virtual void printParams()=0;
protected:
    virtual void die()=0;

};

class CAESAR_CLASS{
public:
    unsigned int countjudge;
public:
    void judgeDeathOfLife(PLAYER_CLASS *player){
        countjudge++;
        if(countjudge%3==0)
            player->die();

    }
};

class ARENA_CLASS{
private:
    CAESAR_CLASS caesar;
public:
    ARENA_CLASS(CAESAR_CLASS* c){
        caesar=*c;
        caesar.countjudge=0;
    }
    void fight(PLAYER_CLASS* p1, PLAYER_CLASS* p2){
        if(p1->getRemainingHealth()>0 && p2->getRemainingHealth()>0){
            if(p1->getAgility() < p2->getAgility()){
                PLAYER_CLASS* temp;
                temp=p1;
                p1=p2;
                p2=temp;
            }
            p1->printParams();
            p2->printParams();
            unsigned int i=40;
            while(i>=0 && p2->getRemainingHealth()>=10 && p1->getRemainingHealth()>=10){
                if(p1->getRemainingHealth()>=10 && p2->getRemainingHealth()>=10){
                    p2->takeDamage(p1->getDamage());
                    i--;
                    p2->printParams();
                }

                if(p2->getRemainingHealth()>=10 && p1->getRemainingHealth()>=10){
                    p1->takeDamage(p2->getDamage());
                    i--;
                    p1->printParams();
                }
            }
            if(p1->getRemainingHealth()>0){
                if(i%2!=0)
                    caesar.countjudge++;
                else
                    caesar.judgeDeathOfLife(p1);
                p1->printParams();
            }
            if(p2->getRemainingHealth()>0){
                if(i%2!=0)
                    caesar.countjudge++;
                else
                    caesar.judgeDeathOfLife(p2);
                p2->printParams();
            }
            if(p1->getRemainingHealth()>0){
                p1->applyWinnerReward();
                p1->cure();
            }
            if(p2->getRemainingHealth()>0){
                p2->applyWinnerReward();
                p2->cure();
            }
            p1->printParams();
            p2->printParams();

        }
    }
};

class HUMAN_CLASS : public virtual PLAYER_CLASS{
public:
    string id;
    unsigned int def;
public:
    HUMAN_CLASS(string name=""){
        id=name;
        maxhp=200;
        hp=200;
        ad=30;
        agi=10;
        def=10;
        next=NULL;
    }

    unsigned int getAgility(){
        return agi;
    }
    unsigned int getDamage(){
        return ad;
    }
    string getId(){
        return id;
    }
    unsigned int getDef(){
        return def;
    }
    unsigned int getRemainingHealth(){
        return hp*100/maxhp;
    }
    void takeDamage(unsigned int dmg){
        if(hp>dmg-(agi+def))
            hp-=dmg-(agi+def);
        else if (agi+def>dmg){}
        else die();
    }

    void applyWinnerReward(){
        ad+=2;
        agi+=2;
    }
    void cure(){
        hp=maxhp;
    }
    void die(){
        hp=0;
    }
    void printParams(){
        if(getRemainingHealth()>0)
            cout<<id<<":"<<maxhp<<":"<<hp<<":"<<getRemainingHealth()<<"%"
                <<":"<<ad<<":"<<agi<<":"<<def<<endl;
        else
            cout<<id<<":"<<"R.I.P."<<endl;
    }
};

class BEAST_CLASS : public virtual PLAYER_CLASS{
public:
    string id;
public:
    BEAST_CLASS(string name=""){
        id=name;
        maxhp=150;
        hp=150;
        ad=40;
        agi=20;
        next=NULL;
    }
    unsigned int getAgility(){
        return agi;
    }
    unsigned int getDamage(){
        if(getRemainingHealth()>=25)
            return ad;
        else return ad*2;
    }
    string getId(){
        return id;
    }
    unsigned int getDef(){
        return 0;
    }
    unsigned int getRemainingHealth(){
        return hp*100/maxhp;
    }
    void takeDamage(unsigned int dmg){
        if(hp>dmg-(agi/2))
            hp-=dmg-(agi/2);
        else if (agi/2>dmg){}
        else die();
    }
    void applyWinnerReward(){
        ad+=2;
        agi+=2;
    }
    void cure(){
        hp=maxhp;
    }
    void die(){
        hp=0;
    }
    void printParams(){
        if(getRemainingHealth()>0)
            cout<<id<<":"<<maxhp<<":"<<hp<<":"<<getRemainingHealth()<<"%"
                <<":"<<getDamage()<<":"<<agi<<endl;
        else
            cout<<id<<":"<<"R.I.P."<<endl;
    }
};

class BERSERKER_CLASS :public   HUMAN_CLASS, public  BEAST_CLASS{
public:
    BERSERKER_CLASS(string human="", string beast=""): HUMAN_CLASS(human),BEAST_CLASS(beast){
        maxhp=200;
        hp=200;
        ad=35;
        agi=5;
        def=15;
        next=NULL;
    }
    unsigned int getDamage(){
        if(getRemainingHealth()>=25 || getRemainingHealth()==0)
            return HUMAN_CLASS::getDamage();
        else
            return BEAST_CLASS::getDamage();
    }
    unsigned int getAgility(){
        if(getRemainingHealth()>=25 || getRemainingHealth()==0)
            return HUMAN_CLASS::getAgility();
        else
            return BEAST_CLASS::getAgility();
    }
    unsigned int getRemainingHealth(){
        return hp*100/maxhp;
    }
    string getId(){
        if(getRemainingHealth()>=25 || getRemainingHealth()==0)
            return HUMAN_CLASS::getId();
        else
            return BEAST_CLASS::getId();
    }
    unsigned int getDef(){
        if(getRemainingHealth()>=25 || getRemainingHealth()==0)
            return HUMAN_CLASS::getDef();
        else
            return BEAST_CLASS::getDef();
    }
    void takeDamage(unsigned int dmg){
        if(getRemainingHealth()>=25 || getRemainingHealth()==0)
            HUMAN_CLASS::takeDamage(dmg);
        else
            BEAST_CLASS::takeDamage(dmg);
    }
    void printParams(){
        if(getRemainingHealth()>=25 || getRemainingHealth()==0)
            HUMAN_CLASS::printParams();
        else
            BEAST_CLASS::printParams();
    }
    void applyWinnerReward(){
        ad+=2;
        agi+=2;
    }
    void cure(){
        hp=maxhp;
    }
    void die(){
        hp=0;
    }
};

class SQUAD_CLASS : public  PLAYER_CLASS{
public:
    string id;
    unsigned int members;
    PLAYER_CLASS* first;
public:
    SQUAD_CLASS(string squad="") {
        id=squad;
        first=NULL;
        members=0;
        agi=0;
        ad=0;
        maxhp=1;
        hp=0;
    }

    void addPlayer(PLAYER_CLASS* player){
        PLAYER_CLASS* temp=first;
        if(player->getRemainingHealth()>0) {
            if (temp) {
                while (temp->next && temp != player) {
                    temp = temp->next;
                }
                if (temp != player) {
                    temp->next = player;
                    player->next=NULL;
                    members++;
                }
            } else {
                first = player;
                player->next=NULL;
                members++;
            }
        }
    }

    unsigned int getAgility(){
        PLAYER_CLASS* temp =first;
        agi=-1;
        while(temp){
            if(agi>temp->agi)
                agi=temp->agi;
            temp=temp->next;
        }
        return agi;
    }
    string getId(){
        return id;
    }
    unsigned int getDef(){
        return 0;
    }
    unsigned int getDamage(){
        PLAYER_CLASS* temp =first;
        ad=0;
        while(temp){
            ad+=temp->getDamage();
            temp=temp->next;
        }
        return ad;
    }

    unsigned int getRemainingHealth(){
        PLAYER_CLASS* temp=first;
        hp=0;
        while(temp){
            if(temp->getRemainingHealth() > hp*100/maxhp){
                hp=temp->hp;
                maxhp=temp->maxhp;
            }
            temp=temp->next;
        }
        return hp*100/maxhp;
    }

    void takeDamage(unsigned int dmg){
        PLAYER_CLASS* temp=first;
        unsigned int deadcount=0;
        if(temp) {
            temp->takeDamage(dmg/members);
            if(temp->getRemainingHealth()>0) {
                while (temp->next) {
                    temp->next->takeDamage(dmg / members);
                    if (temp->next->getRemainingHealth() == 0) {
                        temp->next = temp->next->next;
                        deadcount++;
                    } else temp = temp->next;
                }
                members-=deadcount;
            }
            else {
                first = first->next;
                deadcount++;
                while (temp->next) {
                    temp->next->takeDamage(dmg/members);
                    if (temp->next->getRemainingHealth() == 0) {
                        temp->next=temp->next->next;
                        deadcount++;
                    }
                    else temp = temp->next;
                }
                members-=deadcount;

                temp=first;
                bool found=0;
                while(temp && found==0){
                    if(temp->getRemainingHealth()>0){
                        first=temp;
                        found=1;
                    }
                    temp=temp->next;
                }
                if(!found)
                    first=NULL;
            }
        }
    }

    void die(){
        PLAYER_CLASS* temp=first;
        while(temp){
            temp->die();
            temp=temp->next;
        }
        first=NULL;
        members=0;
        hp=0;
    }

    void applyWinnerReward(){
        PLAYER_CLASS* temp=first;
        while(temp){
            temp->applyWinnerReward();
            agi+=2;
            ad+=2;
            temp=temp->next;
        }
    }

    void cure(){
        PLAYER_CLASS* temp=first;
        while(temp){
            temp->cure();
            temp=temp->next;
        }
    }

    PLAYER_CLASS* Sort(PLAYER_CLASS* head) {
        if (!head){
            return head;
        }

        PLAYER_CLASS* new_head = head;
        head = head->next;
        new_head->next = NULL;

        while (head){
            PLAYER_CLASS* insert_pre = NULL;
            PLAYER_CLASS* insert_pos = new_head;
            while (insert_pos){
                if (insert_pos->getId() > head->getId()){
                    break;
                }
                else if (insert_pos->getId() == head->getId()){
                    if(insert_pos->maxhp>head->maxhp){
                        break;
                    }
                    else if(insert_pos->maxhp == head->maxhp){
                        if(insert_pos->hp>head->hp){
                            break;
                        }
                        else if(insert_pos->hp == head->hp){
                            if(insert_pos->getRemainingHealth()>head->getRemainingHealth()){
                                break;
                            }
                            else if(insert_pos->getRemainingHealth()==head->getRemainingHealth()){
                                if(insert_pos->getDamage() > head->getDamage()){
                                    break;
                                }
                                else if(insert_pos->getDamage() == head->getDamage()){
                                    if(insert_pos->getAgility()>head->getAgility()){
                                        break;
                                    }
                                    else if(insert_pos->getAgility() == head->getAgility()){
                                        if(insert_pos->getDef()>head->getDef()){
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                insert_pre = insert_pos;
                insert_pos = insert_pos->next;
            }

            if (insert_pre){
                insert_pre->next = head;
                head = head->next;
                insert_pre->next->next = insert_pos;
            }
            else{
                new_head = head;
                head = head->next;
                new_head->next = insert_pos;
            }
        }
        return new_head;
    }

    void printParams(){
        if(members && first!=NULL) {

            PLAYER_CLASS* temp=first;

            cout << id << ":" << members << ":" << getRemainingHealth()
                 << "%:" << getDamage() << ":" << getAgility() << endl;

            first= Sort(first);
            temp=first;
            while(temp){
                temp->printParams();
                temp=temp->next;
            }
        }
        else cout<<id<<":"<<"nemo"<<endl;
    }
};

int main(){

    CAESAR_CLASS caesar;
    ARENA_CLASS arena(&caesar);

    HUMAN_CLASS human1("human1");
    BEAST_CLASS beast1("beast1");
    BERSERKER_CLASS berserker1("berserker-human1", "berserker-beast1");

    HUMAN_CLASS dead("dead-human");
    dead.takeDamage(500);

    SQUAD_CLASS squad("squad");
    squad.addPlayer(&human1);
    squad.addPlayer(&beast1);
    squad.addPlayer(&berserker1);
    squad.addPlayer(&dead);
    squad.addPlayer(&human1);
    squad.addPlayer(&beast1);
    squad.addPlayer(&berserker1);

    HUMAN_CLASS human2("human");
    BEAST_CLASS human3("human");
    HUMAN_CLASS human4("human");
    BERSERKER_CLASS human5("human", "human");

    SQUAD_CLASS humansquad("humansquad");
    humansquad.addPlayer(&human2);
    humansquad.addPlayer(&human3);
    humansquad.addPlayer(&human4);
    humansquad.addPlayer(&human5);

    humansquad.takeDamage(680);

    arena.fight(&humansquad, &squad);


    return 0;

}
