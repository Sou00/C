//Igor Łonak

int i=0;
int power=0;
int first=1;

void Emplace (char* tab, int* set){
    if(i==0)
        *set=0;

    if(*(tab+i)=='0' || *(tab+i)=='1' || *(tab+i)==' '){

        if(*(tab+i)=='1' || *(tab+i)=='0'){
            int temp=1;

            if(*(tab+i)=='1') temp<<=16;
            i++;
            if(*(tab+i)=='1') temp<<=8;
            i++;
            if(*(tab+i)=='1') temp<<=4;
            i++;
            if(*(tab+i)=='1') temp<<=2;
            i++;
            if(*(tab+i)=='1') temp<<=1;


            *set |=temp;

        }
        i++;
        Emplace(tab, set);
    }
    else{
        i=0;
    }

}

void Insert (char* tab, int* set){

    if(*(tab+i)=='0' || *(tab+i)=='1' || *(tab+i)==' '){

        if(*(tab+i)=='1' || *(tab+i)=='0'){
            int temp=1;

            if(*(tab+i)=='1') temp<<=16;
            i++;
            if(*(tab+i)=='1') temp<<=8;
            i++;
            if(*(tab+i)=='1') temp<<=4;
            i++;
            if(*(tab+i)=='1') temp<<=2;
            i++;
            if(*(tab+i)=='1') temp<<=1;

            *set |=temp;
        }
        i++;
        Insert(tab, set);
    }
    else{
        i=0;
    }
}

void Erase (char* tab, int* set){
    if(*(tab+i)=='0' || *(tab+i)=='1' || *(tab+i)==' '){

        if(*(tab+i)=='1' || *(tab+i)=='0'){
            int temp=1;

            if(*(tab+i)=='1') temp<<=16;
            i++;
            if(*(tab+i)=='1') temp<<=8;
            i++;
            if(*(tab+i)=='1') temp<<=4;
            i++;
            if(*(tab+i)=='1') temp<<=2;
            i++;
            if(*(tab+i)=='1') temp<<=1;

            temp=~temp;
            *set &=temp;
        }
        i++;
        Erase(tab, set);
    }
    else{
        i=0;
    }
}

void Print (int set, char* tab){
    if(set==0){
        *(tab+0)='e';
        *(tab+1)='m';
        *(tab+2)='p';
        *(tab+3)='t';
        *(tab+4)='y';
        *(tab+5)='\0';
    }
    else {
        if (set & (1 << 31)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
        }
        if (set & (1 << 30)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
        }
        if (set & (1 << 29)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
        }
        if (set & (1 << 28)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
        }
        if (set & (1 << 27)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
        }
        if (set & (1 << 26)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
        }
        if (set & (1 << 25)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
        }
        if (set & (1 << 24)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
        }
        if (set & (1 << 23)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
        }
        if (set & (1 << 22)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
        }
        if (set & (1 << 21)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
        }
        if (set & (1 << 20)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
        }
        if (set & (1 << 19)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
        }
        if (set & (1 << 18)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
        }
        if (set & (1 << 17)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
        }
        if (set & (1 << 16)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
        }
        if (set & (1 << 15)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
        }
        if (set & (1 << 14)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
        }
        if (set & (1 << 13)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
        }
        if (set & (1 << 12)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
        }
        if (set & (1 << 11)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
        }
        if (set & (1 << 10)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
        }
        if (set & (1 << 9)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
        }
        if (set & (1 << 8)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
        }
        if (set & (1 << 7)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
        }
        if (set & (1 << 6)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
        }
        if (set & (1 << 5)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
        }
        if (set & (1 << 4)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
        }
        if (set & (1 << 3)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='1';
        }
        if (set & (1 << 2)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='1';
            *(tab+(i++))='0';
        }
        if (set & (1 << 1)){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='1';

        }
        if (set & 1){
            if(first==0)
                *(tab+(i++))=' ';
            else first=0;
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='0';
            *(tab+(i++))='0';

        }
        *(tab+i)='\0';
    }
    first=1;
    i=0;
}

bool Emptiness(int set){
    return set==0;
}

bool Nonempty(int set){
    return set!=0;
}

bool Member(char* tab, int set){

    if(*(tab+i)=='0' || *(tab+i)=='1' || *(tab+i)==' '){

        if(*(tab+i)=='1' || *(tab+i)=='0'){
            int temp=1;

            if(*(tab+i)=='1') temp<<=16;
            i++;
            if(*(tab+i)=='1') temp<<=8;
            i++;
            if(*(tab+i)=='1') temp<<=4;
            i++;
            if(*(tab+i)=='1') temp<<=2;
            i++;
            if(*(tab+i)=='1') temp<<=1;

            i=0;
            return set & temp;
        }
        i++;
        Member(tab, set);
    }
    else{
        i=0;
        return false;
    }
}

bool Disjoint(int set1, int set2){
    return !(set1 & set2);
}

bool Conjunctive(int set1, int set2){
    return set1 & set2;
}

bool Equality(int set1, int set2){
    return set1 == set2;
}

bool Inclusion(int set1, int set2){
    return (set1 & set2) == set1;

}

void Union(int set1, int set2, int* set){
    *set = set1 | set2;
}

void Intersection (int set1, int set2, int* set){
    *set= set1 & set2;
}

void Symmetric(int set1, int set2, int* set){
    *set = set1 ^ set2;
}

void Difference(int set1, int set2, int* set){
    *set= set1 & (~set2);
}

void Complement(int set1, int* set){
    *set=~set1;
}


int Cardinality(int set){
    if(i==0){
        power=0;
    }
    if(i<32){
        int temp=1;
        temp<<=i;
        i++;
        if(set & temp)
            power++;
        return Cardinality(set);
    }
    i=0;
    return power;
}

bool LessThen(int set1, int set2){
    return Cardinality(set1)<Cardinality(set2) || (Cardinality(set1)==Cardinality(set2)&& set1<set2);
}

bool LessEqual(int set1, int set2){
    return Cardinality(set1)<Cardinality(set2) || (Cardinality(set1)==Cardinality(set2)&& set1<=set2);
}

bool GreatEqual(int set1, int set2){
    return Cardinality(set1)>Cardinality(set2) || (Cardinality(set1)==Cardinality(set2)&& set1>=set2);
}

bool GreatThen(int set1, int set2){
    return Cardinality(set1)>Cardinality(set2) || (Cardinality(set1)==Cardinality(set2)&& set1>set2);
}

