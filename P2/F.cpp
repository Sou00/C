//Igor Lonak


#include <iostream>

using namespace std;

class SQUAD_CLASS;

class BERSERKER_CLASS;

class BEAST_CLASS;

class HUMAN_CLASS;

class ARENA_CLASS;

class CAESAR_CLASS;

class PLAYER_CLASS;

int ATTACKS = 0;



class PLAYER_CLASS {
public:

    unsigned int maxHP;
    unsigned int currentHP;
    unsigned int dmg;
    unsigned int agility;
    friend class CAESAR_CLASS;
    friend class ARENA_CLASS;


public:


    PLAYER_CLASS(unsigned int max = 1, unsigned int dmg = 0, unsigned int agility = 0){
        this->maxHP = max;
        this->currentHP = max;
        this->dmg = dmg;
        this->agility = agility;
    };


    virtual unsigned int getRemainingHealth() {

        return (currentHP * 100 / maxHP);
    }

    virtual unsigned int getDamage() = 0;

    virtual unsigned int getAgility() = 0;

    virtual void takeDamage(unsigned int dmg) = 0;

    virtual void applyWinnerReward() = 0;

    virtual void cure() = 0;

    virtual void printParams() = 0;

protected:

    void die() {
        currentHP = 0;
    }
};


class CAESAR_CLASS {

private:
    int counter = 0;

public:

    void judgeDeathOfLife(PLAYER_CLASS *player) {
        counter++;
        if (counter % 3 == 0 && ATTACKS % 2 == 0) {
            player->die();
        }
    }

};



class ARENA_CLASS {
private:

    CAESAR_CLASS *Caesar;

public:

    ARENA_CLASS(CAESAR_CLASS *caesar) {
        Caesar = caesar;
    }


    void fight(PLAYER_CLASS *player1, PLAYER_CLASS *player2) {

        if (player1->getRemainingHealth() != 0 && player2->getRemainingHealth() != 0)
        {
            PLAYER_CLASS *faster;
            PLAYER_CLASS *slower;
            if (player1->getAgility() < player2->getAgility()) {
                faster = player2;
                slower = player1;
            } else {
                faster = player1;
                slower = player2;
            }

            faster->printParams();
            slower->printParams();
            ATTACKS = 0;
            while (ATTACKS <= 40) {
                if (faster->getRemainingHealth() < 10 || slower->getRemainingHealth() < 10) {
                    break;
                }

                slower->takeDamage(faster->getDamage());
                slower->printParams();
                ATTACKS++;

                if (slower->getRemainingHealth() < 10) {
                    break;
                }

                faster->takeDamage(slower->getDamage());
                faster->printParams();
                ATTACKS++;

            }

            if (faster->getRemainingHealth() > 0) {
                Caesar->judgeDeathOfLife(faster);
                faster->printParams();
            }
            if (slower->getRemainingHealth() > 0) {
                Caesar->judgeDeathOfLife(slower);
                slower->printParams();
            }
            if (faster->getRemainingHealth() > 0) {
                faster->applyWinnerReward();
                faster->cure();
            }
            if (slower->getRemainingHealth() > 0) {
                slower->applyWinnerReward();
                slower->cure();
            }
            faster->printParams();
            slower->printParams();

        }
    }
};

class HUMAN_CLASS : public virtual PLAYER_CLASS {

protected:

    std::string idH;
    unsigned int defense;

public:

    HUMAN_CLASS(std::string name = "") {
        idH = name;
        maxHP = 200;
        currentHP = 200;
        dmg = 30;
        agility = 10;
        defense = 10;
    }

    void applyWinnerReward() {
        dmg += 2;
        agility += 2;
    }

    void cure() {
        currentHP = maxHP;
    }

    unsigned int getDamage() {
        return this->dmg;
    }

    unsigned int getAgility() {
        return this->agility;
    }

    void takeDamage(unsigned int DMG) {
        if (defense + agility < DMG)
        {
            if ((DMG - (defense + agility)) >= currentHP)
            {
                die();
                return;
            }
            currentHP -= (DMG - (defense + agility));
        }
    }

    void printParams() {
        if (getRemainingHealth() > 0)
        {
            cout << idH << ":" << maxHP << ":" << currentHP << ":" << getRemainingHealth()
            << "%:" << getDamage() << ":" << getAgility() << ":" << defense << endl;
        } else
            {
            cout << idH << ":R.I.P." << endl;
        }
    }

};


class BEAST_CLASS : public virtual PLAYER_CLASS {
protected:

    std::string idB;

public:


    BEAST_CLASS(std::string name="") {
        idB = name;
        maxHP = 150;
        currentHP = 150;
        dmg = 40;
        agility = 20;
    }

    void printParams() {
        if (getRemainingHealth() > 0) {
            cout << idB << ":" << maxHP << ":" << currentHP << ":" << getRemainingHealth()
            << "%:" << getDamage() << ":"<< getAgility() << endl;
        } else {
            cout << idB << ":R.I.P." << endl;
        }
    }

    void applyWinnerReward() {
        dmg += 2;
        agility += 2;
    }

    void cure() {
        currentHP = maxHP;
    }

    unsigned int getDamage() {
        if (this->getRemainingHealth() > 25)
            return this->dmg;
        else return this->dmg * 2;

    }

    unsigned int getAgility() {
        return this->agility;
    }

    void takeDamage(unsigned int dmg) {
        if (agility / 2 < dmg) {
            if ((dmg - (agility / 2)) >= currentHP) {
                die();
                return;
            }
            currentHP -= (dmg - (agility / 2));
        }
    }


};

class BERSERKER_CLASS : virtual public HUMAN_CLASS, virtual public BEAST_CLASS {

public:

    BERSERKER_CLASS(){};

    BERSERKER_CLASS(std::string human="", string beast="") : HUMAN_CLASS(human), BEAST_CLASS(beast) {
        idH = human;
        idB = beast;
        maxHP = 200;
        currentHP = 200;
        dmg = 35;
        agility = 5;
        defense = 15;
    }

    void applyWinnerReward() {
        dmg += 2;
        agility += 2;
    }

    void cure() {
        currentHP = maxHP;
    }

    void printParams() {
        if (getRemainingHealth() >= 25 || getRemainingHealth() == 0)
        {
            HUMAN_CLASS::printParams();
        } else
            {
            BEAST_CLASS::printParams();
        }
    }

    unsigned int getDamage() {
        if (getRemainingHealth() >= 25 || getRemainingHealth() == 0)
        {
            return HUMAN_CLASS::getDamage();
        } else
            {
            return BEAST_CLASS::getDamage();
        }
    }

    unsigned int getAgility() {
        if (getRemainingHealth() >= 25 || getRemainingHealth() == 0)
        {
            return HUMAN_CLASS::getAgility();
        } else
            {
            return BEAST_CLASS::getAgility();
        }
    }

    void takeDamage(unsigned int DMG) {

        if (getRemainingHealth() >= 25 || getRemainingHealth() == 0)
        {
            HUMAN_CLASS::takeDamage(DMG);
        } else
            {
            BEAST_CLASS::takeDamage(DMG);
        }
    }

};

struct Node {

    PLAYER_CLASS *member;
    Node *next;
    Node *prev;

    Node(Node *n, Node *p, PLAYER_CLASS *newmember) {
        next = n;
        prev = p;
        member = newmember;
    }

    ~Node() {
        member = NULL;
        next = NULL;
        prev = NULL;
    }

};


class SQUAD_CLASS : virtual public PLAYER_CLASS {
protected:
    Node *first;
    string idS;
    unsigned int members;

public:

    SQUAD_CLASS(){};

    SQUAD_CLASS(std::string name) {
        idS = name;
        first = NULL;
        members = 0;
        currentHP = 0;
        maxHP = 1;
    }

    void applyWinnerReward() {
        if (first != NULL) {
            if (first->next != NULL)
            {
                Node *temp = first;
                temp->member->applyWinnerReward();
                while (temp->next != NULL)
                {
                    temp = temp->next;
                    temp->member->applyWinnerReward();
                }
            } else
            {
                first->member->applyWinnerReward();
            }
        }
    }

    void cure() {
        currentHP = maxHP;
        if (first != NULL)
        {
            if (first->next != NULL)
            {
                Node *temp = first;
                temp->member->cure();
                while (temp->next != NULL)
                {
                    temp = temp->next;
                    temp->member->cure();
                }
            } else {
                first->member->cure();
            }
        }
    }

    void addPlayer(PLAYER_CLASS *newplayer) {

        if (newplayer->getRemainingHealth() != 0)
        {
            if (currentHP < newplayer->currentHP)
            {
                currentHP = newplayer->currentHP;
                maxHP = newplayer->maxHP;
            }

            if (first == NULL)
            {
                first = new Node(NULL, NULL, newplayer);
                members++;
            } else {
                Node *temp = first;
                if (newplayer != first->member)
                {
                    bool found=false;
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                        if (newplayer == temp->member) found=true;
                    }
                    if(found==false)
                    {
                        temp->next = new Node(NULL, temp, newplayer);
                        members++;
                    }
                }
            }
        }
    }

    void deletePlayer(PLAYER_CLASS *player) {
        if (first != NULL) {
            if (first->member == player && first->next == NULL) {
                delete first;
                members--;
                first = NULL;
            } else if (first->member == player) {
                Node *temp = first->next;
                temp->prev = NULL;
                delete first;
                first = temp;
                members--;
            } else {
                Node *temp = first;
                bool found=false;
                while (temp->next != NULL&&found==false)
                {
                    if (temp->member == player)
                    {
                        Node *next = temp->next;
                        Node *prev = temp->prev;
                        next->prev = prev;
                        prev->next = next;
                        delete temp;
                        members--;
                        found=true;
                    }
                    temp = temp->next;
                }
                if (temp->member == player && found == false)
                {
                    Node *prev = temp->prev;
                    prev->next = NULL;
                    delete temp;
                    members--;
                }
            }
        }
    }

    void printParams() {

        newHP();
        if (first == NULL || currentHP == 0)
        {
            cout << idS << ":nemo" << endl;
            if (first != NULL)
            {
                delete first;
                first = NULL;
            }

        } else {
            cout << idS << ":" << members << ":" << getRemainingHealth()
                 << "%:" << getDamage() << ":"<< getAgility() << endl;

            Node *temp = first;
            while (temp != NULL)
            {
                temp->member->printParams();
                temp = temp->next;
            }
        }
    }

    void newHP() {
        currentHP = 0;
        maxHP = 1;

        if (first == NULL)
        {
            currentHP = 0;
            maxHP = 1;
        } else if (first != NULL && first->next == NULL) {
            currentHP = first->member->currentHP;
            maxHP = first->member->maxHP;
        } else {
            Node *temp = first;
            if (temp->member->getRemainingHealth() > getRemainingHealth())
            {
                currentHP = temp->member->currentHP;
                maxHP = temp->member->maxHP;
            }
            while (temp->next != NULL)
            {
                temp = temp->next;
                if (temp->member->getRemainingHealth() > getRemainingHealth())
                {
                    currentHP = temp->member->currentHP;
                    maxHP = temp->member->maxHP;
                }
            }
            if (temp->member->getRemainingHealth() > getRemainingHealth())
            {
                currentHP = temp->member->currentHP;
                maxHP = temp->member->maxHP;
            }
        }
    }

    unsigned int getDamage() {
        unsigned int dmg = 0;
        if (first != NULL)
        {
            Node *temp = first;
            dmg += first->member->getDamage();
            while (temp->next != NULL)
            {
                temp = temp->next;
                dmg += temp->member->getDamage();
            }
        }
        return dmg;
    }

    unsigned int getAgility() {
        unsigned int agility=0;
        if (first != NULL) {
            Node *temp = first;
            agility = first->member->getAgility();
            while (temp->next != NULL) {
                temp = temp->next;
                if (agility > temp->member->getAgility())
                {
                    agility = temp->member->getAgility();
                }
            }
        }
        return agility;
    }

    void takeDamage(unsigned int DMG) {

        if (first != NULL)
        {
            if (first->next == NULL)
            {
                first->member->takeDamage(DMG);
                if (first->member->getRemainingHealth() == 0)
                {
                    die();
                    deletePlayer(first->member);
                }
            }
            else {
                Node *temp;
                bool removeFirst = false;

                first->member->takeDamage(DMG / members);
                if (first->member->getRemainingHealth() == 0)
                {
                    removeFirst = true;
                }

                for (temp = first->next; temp->next != NULL; temp = temp->next)
                {
                    temp->member->takeDamage(DMG / members);
                    if (temp->member->getRemainingHealth() == 0)
                    {
                        Node *tmp = temp;
                        temp = temp->prev;
                        deletePlayer(tmp->member);
                    }
                }

                temp->member->takeDamage(DMG / members);
                if (temp->member->getRemainingHealth() == 0)
                {
                    deletePlayer(temp->member);
                }

                if (removeFirst)
                {
                    deletePlayer(first->member);
                }
            }
        }
    }
};
