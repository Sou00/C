//Igor Łonak

#include <iostream>


class GARDEN_CLASS;
class WOOD_CLASS;
class BRANCH_CLASS;
class FRUIT_CLASS;

class FRUIT_CLASS{
private:

    unsigned int length;
    unsigned int weight;
    BRANCH_CLASS* branch;
    FRUIT_CLASS* next;

public:
    FRUIT_CLASS(unsigned int l=0, unsigned int w=0, BRANCH_CLASS *a=NULL);

    FRUIT_CLASS(const FRUIT_CLASS& a, BRANCH_CLASS* b=NULL);

    unsigned int getLength();

    unsigned int getWeight();

    void growthFruit();

    void fadeFruit();

    void pluckFruit();

    BRANCH_CLASS* getBranchPointer();

    FRUIT_CLASS *getNext();

    void setNext(FRUIT_CLASS *a);
};

class BRANCH_CLASS{
private:


    unsigned int height;
    unsigned int length;
    unsigned int fruitcount;
    unsigned int fruitweightcount;
    WOOD_CLASS* tree;
    BRANCH_CLASS* next;
    FRUIT_CLASS* first;

public:
    BRANCH_CLASS(unsigned int h=0,BRANCH_CLASS* n=NULL, WOOD_CLASS* a=NULL);

    BRANCH_CLASS(const BRANCH_CLASS& a,unsigned int h=0,BRANCH_CLASS* n=NULL,WOOD_CLASS* b=NULL);

    ~BRANCH_CLASS(){
        FRUIT_CLASS* temp=first;
        while(temp){
            FRUIT_CLASS* temp1=temp->getNext();
            delete temp;
            temp=temp1;
        }
        first=NULL;
        height=0;
        length=0;
        fruitcount=0;
        fruitweightcount=0;
        next=NULL;
        tree=NULL;

    }

    unsigned int getFruitsTotal();

    unsigned int getWeightsTotal();

    unsigned int getHeight();

    unsigned int getLength();

    FRUIT_CLASS* getFruitPointer(unsigned int a);

    WOOD_CLASS* getWoodPointer ();

    void addWeight(unsigned int a);

    void removeWeight(unsigned int a);

    void growthBranch();

    void fadeBranch();

    void harvestBranch(unsigned int a);

    void cutBranch(unsigned int a);

    BRANCH_CLASS *getNext();

    void setNext(BRANCH_CLASS *a);


};

class WOOD_CLASS{
private:
    unsigned int number;
    unsigned int height;
    unsigned int branchcount;
    unsigned int fruitcount;
    unsigned int fruitweightcount;
    GARDEN_CLASS* garden;
    WOOD_CLASS* next;
    WOOD_CLASS* prev;
    BRANCH_CLASS* first;

public:

    WOOD_CLASS(unsigned int num=0,WOOD_CLASS* n=NULL,WOOD_CLASS* p =NULL, GARDEN_CLASS* a=NULL);

    WOOD_CLASS(const WOOD_CLASS& a,WOOD_CLASS* n=NULL,WOOD_CLASS* p=NULL,GARDEN_CLASS* b=NULL);

    ~WOOD_CLASS(){
        BRANCH_CLASS* temp=first;
        while(temp){
            BRANCH_CLASS* temp1=temp->getNext();
            delete temp;
            temp=temp1;
        }
        first=NULL;
        height=0;
        fruitcount=0;
        fruitweightcount=0;
        branchcount=0;

        next=NULL;
        prev=NULL;
        garden=NULL;
    }

    unsigned int getBranchesTotal();

    unsigned int getFruitsTotal();

    unsigned int getWeightsTotal();

    unsigned int getNumber();

    unsigned int getHeight();

    GARDEN_CLASS* getGardenPointer();

    void addWeight(unsigned int a);

    void removeWeight(unsigned int a);

    void addFruit(unsigned int a);

    void removeFruit(unsigned int a);

    BRANCH_CLASS *getBranchPointer(unsigned int a);

    void growthWood();

    void fadeWood();

    void harvestWood(unsigned int a);

    void cutWood(unsigned int a);

    void cloneBranch(BRANCH_CLASS *a);

    WOOD_CLASS *getNext();

    void setNext(WOOD_CLASS *a);

    WOOD_CLASS *getPrev();

    void setPrev(WOOD_CLASS *a);

};

class GARDEN_CLASS{
private:
    unsigned int treecount;
    unsigned int branchcount;
    unsigned int fruitcount;
    unsigned int fruitweightcount;
    unsigned int deleted;
    WOOD_CLASS* first;
    WOOD_CLASS* last;

public:

    GARDEN_CLASS(){
        treecount=0;
        branchcount=0;
        fruitcount=0;
        fruitweightcount=0;
        deleted=0;
        first=NULL;
        last=NULL;
    }

    ~GARDEN_CLASS(){
        WOOD_CLASS* temp=first;
        while(temp){
            WOOD_CLASS* temp1=temp->getNext();
            delete temp;
            temp=temp1;
        }

        first=NULL;
        last=NULL;
        fruitcount=0;
        fruitweightcount=0;
        treecount=0;
        branchcount=0;
    }

    unsigned int getWoodsTotal(){
        return treecount;
    }

    unsigned int getBranchesTotal(){
        return branchcount;
    }

    unsigned int getFruitsTotal(){
        return fruitcount;
    }

    unsigned int getWeightsTotal(){
        return fruitweightcount;
    }

    void addWeight(unsigned int a){
        if(this)
        fruitweightcount+=a;
    }

    void removeWeight(unsigned int a){
        if(this)
        fruitweightcount-=a;
    }

    void addFruit(unsigned int a){
        if(this)
        fruitcount+=a;
    }

    void removeFruit(unsigned int a){
        if(this)
        fruitcount-=a;
    }

    void addBranch(unsigned int a){
        if(this)
        branchcount+=a;
    }

    void removeBranch(unsigned int a){
        if(this)
        branchcount-=a;
    }

    void plantWood(){
        WOOD_CLASS* temp=first;
            if (temp) {
                if(deleted==0){
                    last->setNext(new WOOD_CLASS(last->getNumber() + 1, NULL, last, this));
                    last=last->getNext();
                }
                else if(first->getNumber()!=0){
                    first=new WOOD_CLASS(0, temp, NULL, this);
                    temp->setPrev(first);
                    deleted--;
                }
                else {
                    while (temp->getNext() && temp->getNumber() + 1 == temp->getNext()->getNumber()) {
                        temp = temp->getNext();
                    }
                    if (temp->getNext()) {
                        WOOD_CLASS *temp1 = temp->getNext();
                        temp->setNext(new WOOD_CLASS(temp->getNumber() + 1, temp1, temp, this));
                        temp1->setPrev(temp->getNext());
                        deleted--;

                    }
                    //else {
                    //    temp->setNext(new WOOD_CLASS(temp->getNumber() + 1, NULL, temp, this));
                   //     last = temp->getNext();
                   // }
                }
            } else {
                first = new WOOD_CLASS(0, NULL, NULL, this);
                last = first;
            }

        treecount++;

    }

    void extractWood(unsigned int a){
        WOOD_CLASS* temp=first;

            if (temp) {
                if (a <= last->getNumber()) {
                    if((first->getNumber()+last->getNumber())/2>=a) {
                        while (temp && temp->getNumber() < a) {
                            temp = temp->getNext();
                        }
                    }
                    else{
                        temp=last;
                        while (temp && temp->getNumber() > a) {
                            temp = temp->getPrev();
                        }
                    }

                    if (temp && temp->getNumber()==a) {
                        if (temp != first && temp != last) {
                            branchcount-=temp->getBranchesTotal();
                            fruitcount-=temp->getFruitsTotal();
                            fruitweightcount-=temp->getWeightsTotal();
                            temp->getPrev()->setNext(temp->getNext());
                            temp->getNext()->setPrev(temp->getPrev());
                            delete temp;
                            treecount--;
                            deleted++;
                        } else if (temp == first) {
                            branchcount-=temp->getBranchesTotal();
                            fruitcount-=temp->getFruitsTotal();
                            fruitweightcount-=temp->getWeightsTotal();
                            first = first->getNext();
                            if (first) {
                                first->setPrev(NULL);
                                deleted++;
                            }
                            delete temp;
                            treecount--;
                        } else if (temp == last) {
                            branchcount-=temp->getBranchesTotal();
                            fruitcount-=temp->getFruitsTotal();
                            fruitweightcount-=temp->getWeightsTotal();
                            last = last->getPrev();
                            delete temp;
                            if (last)
                                last->setNext(NULL);
                            treecount--;
                        }
                    }
                }
            }

    }

    void growthGarden (){
        WOOD_CLASS* temp=first;
        while(temp){
            temp->growthWood();
            temp=temp->getNext();
        }
    }

    void fadeGarden(){
        WOOD_CLASS* temp=first;
        while(temp){
            temp->fadeWood();
            temp=temp->getNext();
        }
    }

    void harvestGarden(unsigned int a){
        WOOD_CLASS* temp=first;
        while(temp){
            temp->harvestWood(a);
            temp=temp->getNext();
        }
    }

    WOOD_CLASS* getWoodPointer(unsigned int a){
        WOOD_CLASS* temp=first;
        while(temp && temp->getNumber()!=a){
            temp=temp->getNext();
        }
        return temp;
    }

    void cloneWood(unsigned int a){
        WOOD_CLASS* temp=first;
        while(temp && temp->getNumber()!=a){
            temp=temp->getNext();
        }
        if(temp){
            WOOD_CLASS* temp1=first;
            if(temp1) {
                if(temp1->getNumber()!=0){
                    first=new WOOD_CLASS(*temp, temp1, NULL, this);
                    temp1->setPrev(first);
                    treecount++;
                }
                else {
                    while (temp1->getNext() && temp1->getNumber() + 1 == temp1->getNext()->getNumber()) {
                        temp1 = temp1->getNext();
                    }
                    if (temp1->getNext()) {
                        WOOD_CLASS *temp2 = temp1->getNext();

                        temp1->setNext(new WOOD_CLASS(*temp, temp2, temp1, this));
                        temp2->setPrev(temp1->getNext());
                        treecount++;

                    } else {
                        temp1->setNext(new WOOD_CLASS(*temp, NULL, temp1, this));
                        last = temp1->getNext();
                        treecount++;
                    }
                }
            }
        }
    }


};

//                                                                                            WOOD_CLASS

WOOD_CLASS::WOOD_CLASS(unsigned int num,WOOD_CLASS* n,WOOD_CLASS* p , GARDEN_CLASS* a){
    number=num;
    height=0;
    fruitcount=0;
    fruitweightcount=0;
    branchcount=0;
    first=NULL;
    next=n;
    prev=p;
    garden=a;
}

WOOD_CLASS::WOOD_CLASS(const WOOD_CLASS& a,WOOD_CLASS* n,WOOD_CLASS* p,GARDEN_CLASS* b){
    if(p)
    number=p->number+1;
    else number=0;
    height=a.height;
    fruitcount=0;
    fruitweightcount=0;
    branchcount=a.branchcount;
    garden=b;
    first=NULL;
    next=n;
    prev=p;
    BRANCH_CLASS* temp=a.first;
    int h=3;
    if(temp) {
        first = new BRANCH_CLASS(*temp,h,NULL, this);
        h += 3;
        getGardenPointer()->addBranch(1);
        temp=temp->getNext();
    }
    BRANCH_CLASS* temp1=first;
    while(temp && h<=height){
        temp1->setNext(new BRANCH_CLASS(*temp,h,NULL,this));
        temp=temp->getNext();
        temp1=temp1->getNext();
        getGardenPointer()->addBranch(1);
        h+=3;

    }



}

unsigned int WOOD_CLASS::getBranchesTotal(){
    return branchcount;
}

unsigned int WOOD_CLASS::getFruitsTotal(){
    return fruitcount;
}

unsigned int WOOD_CLASS::getWeightsTotal(){
    return fruitweightcount;
}

unsigned int WOOD_CLASS::getNumber(){
    return number;
}

unsigned int WOOD_CLASS::getHeight(){
    return height;
}

void WOOD_CLASS::growthWood(){
    unsigned int temp=height;
    BRANCH_CLASS* temp1=first;
    while(temp>2){
        temp1->growthBranch();
        if(temp1->getNext())
            temp1=temp1->getNext();
        temp-=3;
    }
    height++;

    if(height%3==0){
        if(temp1) {
            temp1->setNext(new BRANCH_CLASS(height, NULL, this));
            branchcount++;
            getGardenPointer()->addBranch(1);
        }
        else {
            first = new BRANCH_CLASS(height, NULL, this);
            branchcount++;
            getGardenPointer()->addBranch(1);
        }
    }
}

void WOOD_CLASS::fadeWood(){
    if(height>0){
        unsigned int temp=height;
        BRANCH_CLASS* temp1=first;

        while(temp>2){
            temp1->fadeBranch();
            if(temp1->getNext())
                temp1=temp1->getNext();
            temp-=3;
        }
        temp=height;
        temp1=first;
        while(temp>5){
            if(temp1->getNext()->getNext())
                temp1=temp1->getNext();
            temp-=3;
        }
        if(height%3==0){
            if(height==3){
                first->removeWeight(first->getWeightsTotal());
                fruitcount-=first->getFruitsTotal();
                getGardenPointer()->removeFruit(first->getFruitsTotal());
                delete first;
                first=NULL;
                branchcount--;
                getGardenPointer()->removeBranch(1);

            }
            else {
                temp1->getNext()->removeWeight(temp1->getNext()->getWeightsTotal());
                fruitcount -= temp1->getNext()->getFruitsTotal();
                getGardenPointer()->removeFruit(temp1->getNext()->getFruitsTotal());
                delete temp1->getNext();
                temp1->setNext(NULL);
                branchcount--;
                getGardenPointer()->removeBranch(1);

            }
        }
        height--;
    }
}

void WOOD_CLASS::harvestWood(unsigned int a){
    BRANCH_CLASS* temp =first;
    while(temp){
        temp->harvestBranch(a);
        temp=temp->getNext();
    }
}

void WOOD_CLASS::cutWood(unsigned int a){
    while(height>a){
        if(height%3==0){
            if(height==3){
                while (first->getLength()) {
                    first->fadeBranch();
                }
                delete first;
                first=NULL;
                branchcount--;
                getGardenPointer()->removeBranch(1);
            }
            else {
                BRANCH_CLASS *temp = getBranchPointer(height - 3);
                while (temp->getNext()->getLength()) {
                    temp->getNext()->fadeBranch();
                }
                delete temp->getNext();
                temp->setNext(NULL);
                branchcount--;
                getGardenPointer()->removeBranch(1);
            }
        }
        height--;
    }
}

void WOOD_CLASS::cloneBranch(BRANCH_CLASS* a){
    BRANCH_CLASS* temp=first;
    if(temp) {
        if(temp->getLength()==0){
            BRANCH_CLASS* temp1=temp->getNext();
            delete temp;
            first=new BRANCH_CLASS(*a,3,temp1,this);
            first->setNext(temp1);

        }
        else if (temp->getNext()->getLength()==0){
            BRANCH_CLASS* temp1=temp->getNext()->getNext();
            unsigned int h=temp->getNext()->getHeight();
            delete temp->getNext();
            temp->setNext(new BRANCH_CLASS(*a,h,temp1,this));

        }
        else {
            while (temp->getNext() && temp->getNext()->getLength() != 0) {
                temp = temp->getNext();

            }
            if(temp->getNext()){
                BRANCH_CLASS* temp1=temp->getNext()->getNext();
                unsigned int h=temp->getNext()->getHeight();
                delete temp->getNext();
                temp->setNext(new BRANCH_CLASS(*a,h,temp1,this));

            }
        }
    }


}

GARDEN_CLASS* WOOD_CLASS::getGardenPointer(){
    return garden;
}

BRANCH_CLASS* WOOD_CLASS::getBranchPointer(unsigned int a){
    if(a%3==0 && a!=0 && a<=height ){
        BRANCH_CLASS *temp = first;
        while (a > 5 && temp) {
            temp = temp->getNext();
            a -= 3;
        }
        return temp;
    }
    else return NULL;
}

void WOOD_CLASS::addWeight(unsigned int a){
    if(this) {
        fruitweightcount += a;
        getGardenPointer()->addWeight(a);
    }
}

void WOOD_CLASS::removeWeight(unsigned int a){
    if(this) {
        fruitweightcount -= a;
        getGardenPointer()->removeWeight(a);
    }
}

void WOOD_CLASS::addFruit(unsigned int a){
    if(this) {
        fruitcount += a;
        getGardenPointer()->addFruit(a);
    }
}

void WOOD_CLASS::removeFruit(unsigned int a){
    if(this) {
        fruitcount -= a;
        getGardenPointer()->removeFruit(a);
    }
}

WOOD_CLASS* WOOD_CLASS::getNext(){
    return next;
}

void WOOD_CLASS::setNext(WOOD_CLASS* a){
    next=a;
}

WOOD_CLASS* WOOD_CLASS::getPrev(){
    return prev;
}

void WOOD_CLASS::setPrev(WOOD_CLASS* a){
    prev=a;
}

///////////////////////////////////////////////////////////////////////////////////////////////////  BRANCH_CLASS

BRANCH_CLASS::BRANCH_CLASS(unsigned int h,BRANCH_CLASS* n, WOOD_CLASS* a) {
    height=h;
    length=0;
    fruitweightcount=0;
    fruitcount=0;
    tree=a;
    next=n;
    first=NULL;
}

BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS& a,unsigned int h,BRANCH_CLASS* n,WOOD_CLASS* b){
height=h;
length=a.length;
fruitcount=a.fruitcount;
fruitweightcount=a.fruitweightcount;
next=n;
tree=b;
tree->addFruit(fruitcount);
tree->addWeight(fruitweightcount);
first=NULL;


FRUIT_CLASS* temp1=a.first;
if(temp1) {
    first = new FRUIT_CLASS(*temp1, this);

    FRUIT_CLASS* temp=first;
    temp1 = temp1->getNext();
    while (temp1) {
        temp->setNext(new FRUIT_CLASS(*temp1, this));
        temp1 = temp1->getNext();
        temp = temp->getNext();
    }
}
}


unsigned int BRANCH_CLASS::getFruitsTotal(){
    return fruitcount;
}

unsigned int BRANCH_CLASS::getWeightsTotal(){
    return fruitweightcount;
}

unsigned int BRANCH_CLASS::getHeight(){
    return height;
}

unsigned int BRANCH_CLASS::getLength(){
    return length;
}

void BRANCH_CLASS::growthBranch(){
    unsigned int temp=length;
    FRUIT_CLASS* temp1=first;
    while(temp>1){
        temp1->growthFruit();
        if(temp1->getNext())
            temp1=temp1->getNext();
        temp-=2;
    }
    length++;

    if(length%2==0){
        if(temp1) {
            temp1->setNext(new FRUIT_CLASS(length, 0, this));
            getWoodPointer()->addFruit(1);
            fruitcount++;
        }
        else{
            first=new FRUIT_CLASS(length, 0, this);
            getWoodPointer()->addFruit(1);
            fruitcount++;
        }
    }

}

void BRANCH_CLASS::fadeBranch(){

    if(length>0){
        unsigned int temp=length;
        FRUIT_CLASS* temp1=first;
        while(temp>1){
            temp1->fadeFruit();
            if(temp1->getNext())
                temp1=temp1->getNext();
            temp-=2;
        }
        temp=length;
        temp1=first;
        while(temp>3){
            if(temp1->getNext()->getNext())
                temp1=temp1->getNext();
            temp-=2;
        }
        if(length%2==0){
            if(length==2){
                first->pluckFruit();
                delete first;
                first=NULL;
                fruitcount--;
                getWoodPointer()->removeFruit(1);
            }
            else {
                temp1->getNext()->pluckFruit();
                delete temp1->getNext();
                temp1->setNext(NULL);
                fruitcount--;
                getWoodPointer()->removeFruit(1);
            }
        }
        length--;
    }

}

void BRANCH_CLASS::harvestBranch(unsigned int a){
    FRUIT_CLASS* temp1=first;
    while(temp1){
        if(temp1->getWeight()>=a)
        temp1->pluckFruit();
        temp1=temp1->getNext();
    }
}

void BRANCH_CLASS::cutBranch(unsigned int a) {
    while(length>a){
        if(length%2==0){
            if(length==2){
                while (first->getWeight()) {
                    first->fadeFruit();
                }
                delete first;
                first=NULL;
                fruitcount--;
                getWoodPointer()->removeFruit(1);
            }
            else {
                FRUIT_CLASS *temp = getFruitPointer(length - 2);
                while (temp->getNext()->getWeight()) {
                    temp->getNext()->fadeFruit();
                }
                delete temp->getNext();
                temp->setNext(NULL);
                fruitcount--;
                getWoodPointer()->removeFruit(1);
            }
        }
        length--;
    }
}

FRUIT_CLASS* BRANCH_CLASS::getFruitPointer(unsigned int a){
    if(a%2==0 && a!=0){
        FRUIT_CLASS *temp = first;
        while (a > 3 && temp) {
            temp = temp->getNext();
            a -= 2;
        }
        return temp;
    }
    else return NULL;
}

WOOD_CLASS* BRANCH_CLASS::getWoodPointer (){
    return tree;
}

void BRANCH_CLASS::addWeight(unsigned int a){
    if(this) {
        fruitweightcount += a;
        getWoodPointer()->addWeight(a);
    }
}

void BRANCH_CLASS::removeWeight(unsigned int a){
    if(this){
        fruitweightcount -= a;
        getWoodPointer()->removeWeight(a);
    }
}

BRANCH_CLASS* BRANCH_CLASS::getNext(){
    return next;
}

void BRANCH_CLASS::setNext(BRANCH_CLASS* a){
    next=a;
}

////////////////////////////////////////////////////////////////////////////////////////////////////   FRUIT_CLASS

FRUIT_CLASS::FRUIT_CLASS(unsigned int l,unsigned int w,BRANCH_CLASS* a) {
    length=l;
    weight=w;
    branch=a;
    next=NULL;
}

FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS& a,BRANCH_CLASS* b){
    length=a.length;
    weight=a.weight;
    branch=b;
    next=NULL;
}

unsigned int FRUIT_CLASS::getLength(){
    return length;
}

unsigned int FRUIT_CLASS::getWeight(){
    return weight;
}

void FRUIT_CLASS::growthFruit(){
    weight++;
    getBranchPointer()->addWeight(1);

}

void FRUIT_CLASS::fadeFruit(){
    if(weight>0) {
        weight--;
        getBranchPointer()->removeWeight(1);
    }
}

void FRUIT_CLASS::pluckFruit(){
    getBranchPointer()->removeWeight(weight);
    weight=0;
}

BRANCH_CLASS* FRUIT_CLASS::getBranchPointer(){
    return branch;
}

FRUIT_CLASS* FRUIT_CLASS::getNext(){
    return next;
}

void FRUIT_CLASS::setNext(FRUIT_CLASS* a){
    next=a;
}

