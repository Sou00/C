//Igor Lonak

#include <iostream>

class FRUIT_CLASS;

class BRANCH_CLASS;

class WOOD_CLASS;

class GARDEN_CLASS;

class FRUIT_CLASS {

private:
    unsigned int weigth = 0;
    unsigned int length = 0;
    BRANCH_CLASS *branch;
    FRUIT_CLASS *prev, *next;

public:

    FRUIT_CLASS() {
        this->weigth = 0;
        this->branch = NULL;
        this->prev = NULL;
        this->next = NULL;
        this->length = 0;

    }



    FRUIT_CLASS(BRANCH_CLASS *newBranch, FRUIT_CLASS *newPrev, FRUIT_CLASS *newNext, unsigned int newLength) {
        this->weigth = 0;
        this->branch = newBranch;
        this->prev = newPrev;
        this->next = newNext;
        this->length = newLength;
    }

    FRUIT_CLASS(const FRUIT_CLASS &oldFruit, BRANCH_CLASS *Branch = NULL) {
        branch = Branch;
        length = oldFruit.length;
        weigth = oldFruit.weigth;
        prev = NULL;
        next = NULL;
    }

    FRUIT_CLASS(const FRUIT_CLASS &newFruit, BRANCH_CLASS *newBranch, FRUIT_CLASS *newPrev,
                FRUIT_CLASS *newNext, unsigned int newLength) {
        this->weigth = newFruit.weigth;
        this->prev = newPrev;
        this->branch = newBranch;
        this->next = newNext;
        this->length = newLength;
    }


    ~FRUIT_CLASS() {
        this->weigth = 0;
        this->branch = NULL;
        this->prev = NULL;
        this->next = NULL;
    }



    void setNext(FRUIT_CLASS *newTail);

    void setBranch(BRANCH_CLASS *newBranch);

    void setPrev(FRUIT_CLASS *newHead);

    void pluckFruit();

    BRANCH_CLASS *getBranchPointer();

    FRUIT_CLASS *getNext();

    FRUIT_CLASS *getFirst();

    unsigned int getLength();

    unsigned int getWeight();

    void growthFruit();

    void fadeFruit();


};


class BRANCH_CLASS {

private:
    unsigned int length = 0;
    unsigned int height = 0;
    BRANCH_CLASS *prev, *next;
    FRUIT_CLASS *first;
    WOOD_CLASS *wood;
public:

    BRANCH_CLASS() {
        this->length = 0;
        this->first = NULL;
        this->wood = NULL;
        this->prev = NULL;
        this->next = NULL;
    }

    BRANCH_CLASS(WOOD_CLASS *newWood, BRANCH_CLASS *newPrev, BRANCH_CLASS *newNext, unsigned int newHeight) {
        this->length = 0;
        this->first = NULL;
        this->wood = newWood;
        this->prev = newPrev;
        this->next = newNext;
        this->height = newHeight;
    }

    BRANCH_CLASS(const BRANCH_CLASS &Branch, BRANCH_CLASS *newPrev, BRANCH_CLASS *newNext,
                 FRUIT_CLASS *firstFruit, unsigned int newHeight, WOOD_CLASS *newWood) {
        this->length = Branch.length;
        this->first = firstFruit;
        this->wood = newWood;
        this->prev = newPrev;
        this->next = newNext;
        this->height = newHeight;
    }

    ~BRANCH_CLASS() {
        if (first == NULL) return;
        FRUIT_CLASS *Temp1 = this->first;
        FRUIT_CLASS *Temp2;
        while (Temp1->getNext() != NULL) {
            Temp2 = Temp1;
            Temp1 = Temp1->getNext();
            delete Temp2;
        }
        delete Temp1;
    }

    BRANCH_CLASS(const BRANCH_CLASS &oldBranch, WOOD_CLASS *newWood = NULL, unsigned int newHeight = 0, BRANCH_CLASS *newPrev = NULL,
                 BRANCH_CLASS *newNext = NULL) {
        length = oldBranch.length;
        height = newHeight;
        wood = newWood;
        prev = newPrev;
        next = newNext;
        first = NULL;

        FRUIT_CLASS *Temp1 = oldBranch.first;
        while (Temp1 != NULL) {
            FRUIT_CLASS *newFruit = new FRUIT_CLASS(*Temp1, this);
            if (Temp1 == oldBranch.first) {
                first = newFruit;
                first->setNext(NULL);
            } else {
                FRUIT_CLASS *Temp2 = first;
                while (Temp2->getNext() != NULL) {
                    Temp2 = Temp2->getNext();
                }
                Temp2->setNext(newFruit);
                newFruit->setPrev(Temp2);
                newFruit->setNext(NULL);

            }
            Temp1 = Temp1->getNext();
        }
    }

    unsigned int getFruitsTotal();

    unsigned int getWeightsTotal();

    unsigned int getHeight();

    unsigned int getLength();

    void growthBranch();

    void fadeBranch();

    void harvestBranch(unsigned int i);

    void cutBranch(unsigned int i);

    FRUIT_CLASS *getFruitPointer(unsigned int i);

    WOOD_CLASS *getWoodPointer();

    void deleteLast();

    void setNext(BRANCH_CLASS *newTail);

    BRANCH_CLASS *getPrev();

    BRANCH_CLASS *getNext();

    void setPrev(BRANCH_CLASS *newNext);


};

class WOOD_CLASS {

private:
    unsigned int index = 0;
    unsigned int height = 0;
    BRANCH_CLASS *first;
    WOOD_CLASS *prev, *next;
    GARDEN_CLASS *garden;
    bool exists;
public:

    WOOD_CLASS() {

        this->height = 0;
        this->index = 0;
        this->first = NULL;
        this->garden = NULL;
        this->prev = NULL;
        this->next = NULL;
        this->exists = true;
    }


    WOOD_CLASS(GARDEN_CLASS *newGarden, WOOD_CLASS *newPrev, WOOD_CLASS *newNext, unsigned int newIndex) {
        this->height = 0;
        this->index = newIndex;
        this->first = NULL;
        this->garden = newGarden;
        this->prev = newPrev;
        this->next = newNext;
        this->exists = true;
    }

    WOOD_CLASS(const WOOD_CLASS &oldtree, GARDEN_CLASS *newGarden = NULL) {
        height = oldtree.height;
        prev = NULL;
        next = NULL;
        garden = newGarden;
        index = 0;
        first = NULL;
        exists = true;
        BRANCH_CLASS *Temp1 = oldtree.first;
        while (Temp1 != NULL) {
            BRANCH_CLASS *newBranch = new BRANCH_CLASS(*Temp1, this, Temp1->getHeight());
            if (Temp1 == oldtree.first) {
                first = newBranch;
            } else {
                BRANCH_CLASS *Temp2 = first;
                while (Temp2->getNext() != NULL) {
                    Temp2 = Temp2->getNext();
                }
                Temp2->setNext(newBranch);
                newBranch->setPrev(Temp2);
                newBranch->setNext(NULL);

            }
            Temp1 = Temp1->getNext();

        }
    }

    ~WOOD_CLASS() {
        if (first == NULL) return;
        BRANCH_CLASS *Temp1 = this->first;
        BRANCH_CLASS *Temp2;
        while (Temp1->getNext() != NULL) {
            Temp2 = Temp1;
            Temp1 = Temp1->getNext();
            delete Temp2;
        }
        delete Temp1;
    }

    unsigned int getBranchesTotal();

    unsigned int getFruitsTotal();

    unsigned int getWeightsTotal();

    unsigned int getNumber();

    unsigned int getHeight();

    void growthWood();

    void fadeWood();

    void harvestWood(unsigned int i);

    void cutWood(unsigned int i);

    void cloneBranch(BRANCH_CLASS *i);

    GARDEN_CLASS *getGardenPointer();

    BRANCH_CLASS *getBranchPointer(unsigned int i);

    void deleteLast();

    WOOD_CLASS *getPrev();

    WOOD_CLASS *getNext();

    void setNext(WOOD_CLASS *newNext);

    void setNumber(int num);


    BRANCH_CLASS *getFirst();


    bool existence();

    void setHight(unsigned int h);

    void setPrev(WOOD_CLASS *newPrev);
};



class GARDEN_CLASS {
private:
    WOOD_CLASS *first, *last;
    unsigned int free=0;


public:

    GARDEN_CLASS() {
        this->first = NULL;
        this->last=NULL;
    }

    ~GARDEN_CLASS() {
        if (first == NULL) return;
        WOOD_CLASS *firstTemp = this->first;
        WOOD_CLASS *secondTemp;
        while (firstTemp->getNext() != NULL) {
            secondTemp = firstTemp;
            firstTemp = firstTemp->getNext();
            delete secondTemp;
        }
        delete firstTemp;

    }


    WOOD_CLASS *getWoodPointer(unsigned int i);

    void cloneWood(unsigned int i);

    void harvestGarden(unsigned int i);

    void fadeGarden();

    void extractWood(unsigned int i);

    void plantWood();

    unsigned int getWeightsTotal();

    unsigned int getFruitsTotal();

    unsigned int getBranchesTotal();

    unsigned int getWoodsTotal();

    void growthGarden();

    WOOD_CLASS *getFirst();

    void setFirst(WOOD_CLASS *a);

    void display();
};


unsigned int FRUIT_CLASS::getLength() {
    return this->length;
}

unsigned int FRUIT_CLASS::getWeight() {
    return this->weigth;
}

void FRUIT_CLASS::growthFruit() {
    this->weigth++;
}

void FRUIT_CLASS::fadeFruit() {
    if (this->weigth > 0) {
        this->weigth--;
    }
}

void FRUIT_CLASS::pluckFruit() {
    this->weigth = 0;
}

BRANCH_CLASS *FRUIT_CLASS::getBranchPointer() {
    return this->branch;
}

FRUIT_CLASS *FRUIT_CLASS::getNext() {
    return this->next;
}

FRUIT_CLASS *FRUIT_CLASS::getFirst() {
    return this->prev;
}

void FRUIT_CLASS::setNext(FRUIT_CLASS *newTail) {
    this->next = newTail;
}

void FRUIT_CLASS::setBranch(BRANCH_CLASS *newBranch) {

    this->branch = newBranch;
}

void FRUIT_CLASS::setPrev(FRUIT_CLASS *newHead) {

    this->prev = newHead;
}


void BRANCH_CLASS::deleteLast() {
    if (this->first != NULL) {
        FRUIT_CLASS *Temp1 = this->first;
        if (Temp1->getNext() == NULL) {
            this->first = NULL;

        } else {
            while (Temp1->getNext() != NULL) {
                Temp1 = Temp1->getNext();
            }
            FRUIT_CLASS *prevTemp = Temp1->getFirst();
            delete Temp1;
            prevTemp->setNext(NULL);
        }
    }
}


unsigned int BRANCH_CLASS::getFruitsTotal() {
    unsigned int fruits = 0;
    if (first == NULL) {
        return 0;
    } else {

        fruits++;
        FRUIT_CLASS *Temp1 = this->first;
        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            fruits++;
        }
        return fruits;
    }
}

unsigned int BRANCH_CLASS::getWeightsTotal() {
    unsigned int weights = 0;
    if (first == NULL) {
        return 0;
    } else {
        FRUIT_CLASS *Temp1 = this->first;
        weights += Temp1->getWeight();
        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            weights += Temp1->getWeight();
        }
        return weights;
    }
}

unsigned int BRANCH_CLASS::getHeight() {
    return this->height;
}

unsigned int BRANCH_CLASS::getLength() {
    return this->length;

}

void BRANCH_CLASS::growthBranch() {
    this->length++;
    FRUIT_CLASS *Temp1 = this->first;


    if (Temp1 != NULL) {
        Temp1->growthFruit();

        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            Temp1->growthFruit();

        }
    }

    Temp1 = this->first;


    if (length == 2) {
        this->first = new FRUIT_CLASS(this, NULL, NULL, 2);
    } else if (length == 4) {
        this->first->setNext((new FRUIT_CLASS(this, this->first, NULL, 4)));
    } else if (length % 2 == 0 && length != 0) {
        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
        }
        Temp1->setNext((new FRUIT_CLASS(this, Temp1, NULL, length)));
    }
}

void BRANCH_CLASS::fadeBranch() {
    if (length > 0) {

        if (length % 2 == 0 && length > 0) {
            deleteLast();
        }
        this->length--;
        if (this->first != NULL) {
            FRUIT_CLASS *Temp1 = this->first;
            Temp1->fadeFruit();
            while (Temp1->getNext() != NULL) {
                Temp1 = Temp1->getNext();
                Temp1->fadeFruit();
            }
        }
    }
}

void BRANCH_CLASS::harvestBranch(unsigned int i) {

    if (this->first != NULL) {
        FRUIT_CLASS *Temp1 = this->first;
        if (Temp1->getWeight() >= i) {
            Temp1->pluckFruit();
        }
        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            if (Temp1->getWeight() >= i) {
                Temp1->pluckFruit();
            }
        }
    }
}

void BRANCH_CLASS::cutBranch(unsigned int i) {

    if (i > length) {
        return;
    }

    if (this->length % 2 != 0 && this->length != i) {
        this->length--;
    }

    if (this->length != i && this->length > 0) {

        while (this->length > i) {
            if (this->length % 2 == 0) {
                deleteLast();
            }
            this->length--;
        }
    }
}

FRUIT_CLASS *BRANCH_CLASS::getFruitPointer(unsigned int i) {
    if (i % 2 != 0 || i == 0) {
        return NULL;
    }
    if (i == 2) {
        return first;
    } else {
        unsigned int j = 2;
        FRUIT_CLASS *Temp1 = this->first;
        while (j != i) {
            if (j % 2 == 0) {
                Temp1 = Temp1->getNext();
            }
            j++;
        }
        return Temp1;
    }
}

WOOD_CLASS *BRANCH_CLASS::getWoodPointer() {
    return this->wood;

}

BRANCH_CLASS *BRANCH_CLASS::getNext() {
    return this->next;
}

BRANCH_CLASS *BRANCH_CLASS::getPrev() {
    return this->prev;
}

void BRANCH_CLASS::setNext(BRANCH_CLASS *newNext) {
    this->next = newNext;
}

void BRANCH_CLASS::setPrev(BRANCH_CLASS *newPrev) {
    this->prev = newPrev;
}


void WOOD_CLASS::deleteLast() {
    if (this->first != NULL) {
        BRANCH_CLASS *Temp1 = this->first;
        if (Temp1->getNext() == NULL) {
            this->first = NULL;

        } else {
            while (Temp1->getNext() != NULL) {
                Temp1 = Temp1->getNext();
            }
            BRANCH_CLASS *prevTemp = Temp1->getPrev();
            delete Temp1;
            prevTemp->setNext(NULL);
        }
    }
}

unsigned int WOOD_CLASS::getBranchesTotal() {
    unsigned int branches = 0;
    if (first == NULL) {
        return 0;
    } else {

        branches++;
        BRANCH_CLASS *Temp1 = this->first;
        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            branches++;
        }
        return branches;
    }

}

unsigned int WOOD_CLASS::getFruitsTotal() {
    unsigned int fruits = 0;
    if (first == NULL) {
        return 0;
    } else {

        fruits += first->getFruitsTotal();
        BRANCH_CLASS *Temp1 = this->first;
        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            fruits += Temp1->getFruitsTotal();
        }
        return fruits;
    }

}

unsigned int WOOD_CLASS::getWeightsTotal() {
    unsigned int weights = 0;
    if (first == NULL) {
        return 0;
    } else {

        weights += first->getWeightsTotal();
        BRANCH_CLASS *Temp1 = this->first;
        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            weights += Temp1->getWeightsTotal();
        }
        return weights;
    }
}

unsigned int WOOD_CLASS::getNumber() {

    return this->index;
}

void WOOD_CLASS::setNumber(int num) {
    this->index = num;
}


BRANCH_CLASS *WOOD_CLASS::getFirst() {
    return this->first;
}

unsigned int WOOD_CLASS::getHeight() {

    return this->height;

}

void WOOD_CLASS::growthWood() {
    this->height++;
    BRANCH_CLASS *Temp1 = this->first;

    if (Temp1 != NULL) {
        Temp1->growthBranch();

        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            Temp1->growthBranch();

        }
    }

    Temp1 = this->first;

    if (height == 3) {
        this->first = new BRANCH_CLASS(this, NULL, NULL, 3
        );
    } else if (height == 6) {
        this->first->setNext((new BRANCH_CLASS(this, this->first, NULL, 6)));
    } else if (height % 3 == 0 && height != 0) {
        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
        }
        Temp1->setNext((new BRANCH_CLASS(this, Temp1, NULL, height)));
    }
}

void WOOD_CLASS::fadeWood() {
    if (height > 0) {

        if (height % 3 == 0 && height > 0) {
            deleteLast();
        }
        this->height--;
        if (this->first != NULL) {
            BRANCH_CLASS *Temp1 = this->first;
            Temp1->fadeBranch();
            while (Temp1->getNext() != NULL) {
                Temp1 = Temp1->getNext();
                Temp1->fadeBranch();
            }
        }
    }
}

void WOOD_CLASS::harvestWood(unsigned int i) {

    if (this->first != NULL) {
        BRANCH_CLASS *Temp1 = this->first;
        Temp1->harvestBranch(i);
        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            Temp1->harvestBranch(i);
        }
    }
}

void WOOD_CLASS::cutWood(unsigned int i) {
    if (i > height) {
        return;
    }

    if (this->height % 3 == 1 && this->height != i) {
        this->height--;
    } else if (this->height % 3 == 2 && this->height != i) {
        this->height--;
    }

    if (this->height != i && this->height > 0) {

        while (this->height > i) {
            if (this->height % 3 == 0) {
                deleteLast();
            }
            this->height--;
        }
    }
}

void WOOD_CLASS::cloneBranch(BRANCH_CLASS *i) {

    if (this->first != NULL && i != NULL) {
        BRANCH_CLASS *Temp1 = this->first;
        BRANCH_CLASS *TempPrev = Temp1->getPrev();
        BRANCH_CLASS *TempNext = Temp1->getNext();
        while (Temp1->getLength() != 0 && Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            TempPrev = Temp1->getPrev();
            TempNext = Temp1->getNext();
        }
        if (Temp1->getLength() == 0) {

            FRUIT_CLASS *fruitTemp = i->getFruitPointer(2);
            if (fruitTemp != NULL) {
                FRUIT_CLASS *firstFruit = new FRUIT_CLASS(*fruitTemp, Temp1, NULL, NULL, fruitTemp->getLength());
                if (Temp1 != this->first) {

                    unsigned int heightTemp = Temp1->getHeight();
                    BRANCH_CLASS *TempPrev = Temp1->getPrev();
                    BRANCH_CLASS *TempNext = Temp1->getNext();
                    delete Temp1;
                    BRANCH_CLASS *newBranch = new BRANCH_CLASS(*i, TempPrev, TempNext, firstFruit, heightTemp, this);
                    TempPrev->setNext(newBranch);
                    firstFruit->setBranch(newBranch);
                    if (TempNext != NULL)
                        TempNext->setPrev(newBranch);
                } else {

                    BRANCH_CLASS *TempPrev = Temp1->getPrev();
                    BRANCH_CLASS *TempNext = Temp1->getNext();
                    delete Temp1;
                    BRANCH_CLASS *newBranch = new BRANCH_CLASS(*i, TempPrev, TempNext, firstFruit, 3, this);
                    firstFruit->setBranch(newBranch);
                    if (TempNext != NULL)
                        TempNext->setPrev(newBranch);
                }
                fruitTemp = fruitTemp->getNext();
                while (fruitTemp != NULL) {
                    FRUIT_CLASS *newFruit = new FRUIT_CLASS(*fruitTemp, Temp1, firstFruit, NULL, fruitTemp->getLength());
                    newFruit->setBranch(firstFruit->getBranchPointer());
                    firstFruit->setNext(newFruit);
                    fruitTemp = fruitTemp->getNext();
                    firstFruit = firstFruit->getNext();
                }
            } else {
                if (Temp1 != this->first) {
                    unsigned int heightTemp = Temp1->getHeight();
                    BRANCH_CLASS *TempPrev = Temp1->getPrev();
                    BRANCH_CLASS *TempNext = Temp1->getNext();
                    delete Temp1;
                    BRANCH_CLASS *newBranch = new BRANCH_CLASS(*i, TempPrev, TempNext, NULL, heightTemp, this);
                    TempPrev->setNext(newBranch);
                    if (TempNext != NULL)
                        TempNext->setPrev(newBranch);
                } else {
                    BRANCH_CLASS *TempPrev = Temp1->getPrev();
                    BRANCH_CLASS *TempNext = Temp1->getNext();
                    delete Temp1;
                    BRANCH_CLASS *newBranch = new BRANCH_CLASS(*i, TempPrev, TempNext, NULL, 3, this);
                    if (TempNext != NULL)
                        TempNext->setPrev(newBranch);
                }

            }
        }
    }

}


GARDEN_CLASS *WOOD_CLASS::getGardenPointer() {
    return this->garden;
}

BRANCH_CLASS *WOOD_CLASS::getBranchPointer(unsigned int i) {
    if (i % 3 != 0 || i == 0) {
        return NULL;
    }
    if (i == 3) {
        BRANCH_CLASS *Temp1 = getFirst();
        return Temp1;
    } else {
        unsigned int j = 3;
        BRANCH_CLASS *Temp1 = this->getFirst();
        if (Temp1 != NULL);
        while (j != i && Temp1 != NULL) {
            if (j % 3 == 0) {
                Temp1 = Temp1->getNext();
            }
            j++;
        }
        return Temp1;
    }
}

WOOD_CLASS *WOOD_CLASS::getNext() {
    return this->next;
}

WOOD_CLASS *WOOD_CLASS::getPrev() {
    return this->prev;
}

void WOOD_CLASS::setNext(WOOD_CLASS *newNext) {
    this->next = newNext;
}

bool WOOD_CLASS::existence() {
    return this->exists;
}


void WOOD_CLASS::setPrev(WOOD_CLASS *newPrev) {
    this->prev = newPrev;
}


WOOD_CLASS *GARDEN_CLASS::getFirst() {
    return first;
}

void GARDEN_CLASS::setFirst(WOOD_CLASS *newFirst) {
    first = newFirst;
}

unsigned int GARDEN_CLASS::getWoodsTotal() {

    unsigned int woods = 0;
    if (first == NULL) {
        return 0;
    } else {


        WOOD_CLASS *Temp1 = this->first;
        bool exist = Temp1->existence();
        if (exist)
            woods++;
        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            exist = Temp1->existence();
            if (exist)
                woods++;
        }
        return woods;
    }

}

unsigned int GARDEN_CLASS::getBranchesTotal() {

    unsigned int branches = 0;
    if (first == NULL) {
        return 0;
    } else {


        WOOD_CLASS *Temp1 = this->first;
        bool exist = Temp1->existence();
        if (exist)
            branches += this->first->getBranchesTotal();
        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            exist = Temp1->existence();
            if (exist)
                branches += Temp1->getBranchesTotal();
        }
        return branches;
    }
}

unsigned int GARDEN_CLASS::getFruitsTotal() {

    unsigned int fruits = 0;
    if (first == NULL) {
        return 0;
    } else {

        WOOD_CLASS *Temp1 = this->first;
        bool exist = Temp1->existence();
        if (exist)
            fruits += this->first->getFruitsTotal();
        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            exist = Temp1->existence();
            if (exist)
                fruits += Temp1->getFruitsTotal();
        }
        return fruits;
    }

}

unsigned int GARDEN_CLASS::getWeightsTotal() {

    unsigned int weights = 0;
    if (first == NULL) {
        return 0;
    } else {


        WOOD_CLASS *Temp1 = this->first;
        bool exist = Temp1->existence();
        if (exist)
            weights += this->first->getWeightsTotal();
        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            exist = Temp1->existence();
            if (exist)
                weights += Temp1->getWeightsTotal();
        }
        return weights;
    }
}

void GARDEN_CLASS::plantWood() {
    if (free == 0) {
        if (first == NULL) {
            first = new WOOD_CLASS(this,NULL,NULL,0);
            last = first;
            first->setNext(NULL);
            last->setPrev(NULL);
        } else {
            WOOD_CLASS *newTree = new WOOD_CLASS(this,last,NULL, last->getNumber() + 1);
            last->setNext(newTree);
            newTree->setPrev(last);
            newTree->setNext(NULL);
            last = newTree;
        }
    } else if (free > 0) {
        WOOD_CLASS *Temp1 = first;
        unsigned int count = 0;
        while (Temp1 != NULL && Temp1->getNumber() == count) {
            Temp1 = Temp1->getNext();
            count++;
        }
        WOOD_CLASS *newTree;
        if (Temp1 == first) {
            newTree = new WOOD_CLASS(this,NULL,NULL, 0);
            newTree->setNext(first);
            first->setPrev(newTree);
            newTree->setPrev(NULL);
            first = newTree;
        } else {
            newTree = new WOOD_CLASS(this, NULL, NULL, Temp1->getNumber() - 1);
            newTree->setNext(Temp1);
            Temp1->getPrev()->setNext(newTree);
            newTree->setPrev(Temp1->getPrev());
            Temp1->setPrev(newTree);
        }
        if (free > 0)
            free--;
    }
}
void GARDEN_CLASS::extractWood(unsigned int i) {
    WOOD_CLASS *Temp1;
    if (last == NULL) return;
    if (i < last->getNumber()) {
        if (i == first->getNumber()) {
            Temp1 = first;
            first = first->getNext();
            first->setPrev(NULL);
            delete Temp1;
            free++;
        } else {
            Temp1 = first;
            while (Temp1 != NULL && Temp1->getNumber() < i) {
                Temp1 = Temp1->getNext();
            }
            if (Temp1 != NULL && Temp1->getNumber() == i) {
                Temp1->getNext()->setPrev(Temp1->getPrev());
                Temp1->getPrev()->setNext(Temp1->getNext());
                delete Temp1;
                free++;
            }
        }
    } else if (i == last->getNumber()) {
        Temp1 = last;
        if (first == last) {
            delete Temp1;
            first = NULL;
            last = NULL;
        } else {
            last = last->getPrev();
            last->setNext(NULL);
            delete Temp1;
        }
    }
}
void GARDEN_CLASS::fadeGarden() {

    if (this->first != NULL) {
        WOOD_CLASS *Temp1 = this->first;
        bool exist = Temp1->existence();
        if (exist)
            Temp1->fadeWood();
        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            exist = Temp1->existence();
            if (exist)
                Temp1->fadeWood();
        }
    }
}

void GARDEN_CLASS::harvestGarden(unsigned int i) {

    if (this->first != NULL) {

        WOOD_CLASS *Temp1 = this->first;
        bool exist = Temp1->existence();
        if (exist)
            Temp1->harvestWood(i);

        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            exist = Temp1->existence();
            if (exist) {
                Temp1->harvestWood(i);
            }
        }
    }
}

void GARDEN_CLASS::cloneWood(unsigned int i) {
    WOOD_CLASS *Tree = first;
    while (Tree != NULL && Tree->getNumber() < i) {
        Tree = Tree->getNext();
    }
    if (Tree == NULL || Tree->getNumber() != i) return;
    WOOD_CLASS *newTree;
    if (free == 0) {
        if (first == NULL) {
            newTree = new WOOD_CLASS(*Tree, this);
            newTree->setNumber(0);
            first = newTree;
            last = first;
        } else {
            newTree = new WOOD_CLASS(*Tree, this);
            newTree->setNumber(last->getNumber() + 1);
            last->setNext(newTree);
            newTree->setPrev(last);
            last = newTree;
        }
    } else if (free > 0) {
        WOOD_CLASS *Temp1 = first;
        unsigned int count = 0;
        while (Temp1 != NULL && Temp1->getNumber() == count) {
            Temp1 = Temp1->getNext();
            count++;
        }
        if (Temp1 == first) {
            newTree = new WOOD_CLASS(*Tree, this);
            newTree->setNumber(0);
            newTree->setNext(first);
            first->setPrev(newTree);
            first = newTree;
        } else if (Temp1 == last) {
            newTree = new WOOD_CLASS(*Tree, this);
            newTree->setNumber(last->getNumber() + 1);
            newTree->setPrev(last);
            last->setNext(newTree);
            last = newTree;
        } else {
            newTree = new WOOD_CLASS(*Tree, this);
            newTree->setNumber(Temp1->getNumber() - 1);
            newTree->setNext(Temp1);
            newTree->setPrev(Temp1->getPrev());
            Temp1->getPrev()->setNext(newTree);
            Temp1->setPrev(newTree);
        }
        free--;
    }
}
WOOD_CLASS *GARDEN_CLASS::getWoodPointer(unsigned int i) {

    WOOD_CLASS *Temp1 = this->getFirst();
    unsigned int number;
    bool exist;
    if (Temp1 != NULL) {
        while (Temp1 != NULL) {
            number = Temp1->getNumber();
            exist = Temp1->existence();
            if (number == i && exist == true)
                return Temp1;
            if (number == i && exist == false) {
                return NULL;
            }
            Temp1 = Temp1->getNext();
        }
    }
    return Temp1;

}

void GARDEN_CLASS::growthGarden() {

    WOOD_CLASS *Temp1 = this->first;

    if (Temp1 != NULL) {
        Temp1->growthWood();

        while (Temp1->getNext() != NULL) {
            Temp1 = Temp1->getNext();
            Temp1->growthWood();

        }
    }

}


