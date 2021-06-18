//Igor Łonak
#include <iostream>
#include <string>
#include <cstdarg>

using namespace std;

int i=0;
int j=-2;
int k=-2;
int l=0;
int m=0;
int n=0;
string result="";
string result1="";
int carry=0;
va_list arg;
string tab1[2];

int Countzero(string a){

    if(a[j+2]=='0'&&j+2<a.length()-1){
        j++;
        k++;
        Countzero(a);
    }
    j=-2;
    return k+2;
}

int Compare (string a, string b)
{
    if(a.length()>b.length())k=1;
    else if(a.length()==b.length()){
        if(j+2<a.length()){
            if(a[j+2]>b[j+2]){
                k=1;

            }
            else if(a[j+2]==b[j+2]){
                j++;
                Compare(a,b);
            }
            else{
                k=-1;

            }
        }
        else{
            k=0;

        }
    }
    else{
        k=-1;
    }
    j=-2;
    return k;

}

string Add(string a, string b){
    if (a.length() > b.length())
        swap(a, b);


    int diff = b.length() - a.length();

    if(j==-2){
        result1="";
        j=a.length()-1;
    }
    if (j>=0)
    {
        int sum = ((a[j]-'0') +(b[j+diff]-'0') + carry);
        char sum1=sum % 10 + '0';
        result1=sum1 + result1;
        carry = sum/10;
        j--;
        Add(a,b);
    }
    if(k==-2)k=b.length()-a.length()-1;
    if (k>=0)
    {
        int sum = ((b[k]-'0')+carry);
        char sum1=sum % 10 + '0';
        result1=sum1 + result1;
        carry = sum/10;
        k--;
        Add(a,b);
    }

    if (carry)
        result1=(char)(carry+'0')+result1;

    j=-2;
    carry=0;

    return result1;
}

string Sub(string a, string b){


    int diff = a.length() - b.length();

    if(j==-2){
        result1="";
        j=b.length()-1;
    }
    if (j>=0) {

        int sub = ((a[j + diff] - '0') - (b[j] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;


        result1=(char)(sub+'0')+result1;
        j--;
        Sub(a,b);

    }
    if(k==-2)
        k=a.length()-b.length()-1;
    if (k>=0) {
        if (a[k] == '0' && carry) {
            result1='9'+result1;

        }
        else{
            int sub = ((a[k] - '0') - carry);
            if (i > 0 || sub > 0)
                result1=(char)(sub+'0')+result1;
            carry=0;
        }


        k--;
        Sub(a,b);
    }


    j=-2;
    carry=0;

    return result1;
}

void Multi2(string b,int n1){

    if(j==-2)j=b.length()-1;
    if(j>=0){

        int n2 = b[j] - '0';
        int sum = n1*n2 + result1[l + m - 1 ] - '0' + carry;

        carry = sum/10;
        result1[l + m - 1] = sum % 10 + '0';



        m--;

        j--;
        Multi2(b,n1);
    }

}

string Multi(string a, string b){
    int len1 = a.length();
    int len2 = b.length();


    if(k==-2){

        result1.resize(len1 + len2, '0');

        l = a.length();
         m = b.length();
         k=len1-1;
    }
    if(k>=0){

        carry = 0;
        int n1 = a[k] - '0';

        m = b.length();
        j=-2;
        Multi2(b,n1);

        if (carry > 0)
            result1[l + m -1] += carry ;


        l--;
        k--;
        Multi(a,b);
    }
    j=-2;
    return result1;
}

string Sum(int size,const string* tab){
    if(i==0){
        result=tab[0];
        i++;
    }
    if(i<size){
        string number=tab[i];

        if(result[0]=='-' && number[0]=='-'){

            result.erase(0,1);
            number.erase(0,1);
            result.erase(0,Countzero(result));
            k=-2;
            number.erase(0,Countzero(number));
            k=-2;
            result=Add(result,number);
            k=-2;
            if(result[0]!='0')
            result="-"+result;
            i++;
            Sum(size,tab);
        }
        else if(result[0]!='-'&& number[0]!='-'){
            if(result[0]=='+')
                result.erase(0,1);
            if(number[0]=='+')
                number.erase(0,1);
            result.erase(0,Countzero(result));
            k=-2;
            number.erase(0,Countzero(number));
            k=-2;
            result=Add(result,number);
            k=-2;
            i++;
            Sum(size,tab);
        }
        else{
            bool first=0;
            if(result[0]!='-')first=1;
            if(result[0]=='+' ||result[0]=='-'){
                result.erase(0,1);
            }
            if(number[0]=='+'||number[0]=='-')
                number.erase(0,1);
            result.erase(0,Countzero(result));
            k=-2;
            number.erase(0,Countzero(number));
            k=-2;

            if(Compare(result,number)==0){
                result="0";
                k=-2;
            }
            else if(Compare(result,number)==-1){
                swap(result,number);
                k=-2;
                result=Sub(result,number);
                k=-2;
                result.erase(0,Countzero(result));
                k=-2;
                if(first){
                    result="-"+result;
                }
            }
            else{
                k=-2;
                result=Sub(result,number);
                k=-2;
                result.erase(0,Countzero(result));
                k=-2;
                if(!first)
                    result="-"+result;
            }
            i++;
            Sum(size,tab);
        }

    }
    result1="";
    i=0;
    return result;
}

string Sum(int size, ...){

    if(i==0){
        va_start(arg,size);
        result=va_arg(arg,char*);
        i++;
    }
    if(i<size){
        string number=va_arg(arg,char*);

        if(result[0]=='-' && number[0]=='-'){

            result.erase(0,1);
            number.erase(0,1);
            result.erase(0,Countzero(result));
            k=-2;
            number.erase(0,Countzero(number));
            k=-2;
            result=Add(result,number);
            k=-2;
            if(result[0]!='0')
                result="-"+result;
            i++;
            Sum(size,arg);
        }
        else if(result[0]!='-'&& number[0]!='-'){
            if(result[0]=='+')
                result.erase(0,1);
            if(number[0]=='+')
                number.erase(0,1);
            result.erase(0,Countzero(result));
            k=-2;
            number.erase(0,Countzero(number));
            k=-2;
            result=Add(result,number);
            k=-2;
            i++;
            Sum(size,arg);
        }
        else{
            bool first=0;
            if(result[0]!='-')first=1;
            if(result[0]=='+' ||result[0]=='-'){
                result.erase(0,1);
            }
            if(number[0]=='+'||number[0]=='-')
                number.erase(0,1);
            result.erase(0,Countzero(result));
            k=-2;
            number.erase(0,Countzero(number));
            k=-2;

            if(Compare(result,number)==0){
                result="0";
                k=-2;
            }
            else if(Compare(result,number)==-1){
                swap(result,number);
                k=-2;
                result=Sub(result,number);
                k=-2;
                result.erase(0,Countzero(result));
                k=-2;
                if(first){
                    result="-"+result;
                }
            }
            else{
                k=-2;
                result=Sub(result,number);
                k=-2;
                result.erase(0,Countzero(result));
                k=-2;
                if(!first)
                    result="-"+result;
            }
            i++;
            Sum(size,arg);
        }
    }
    i=0;
    result1="";
    va_end(arg);
    return result;
}

void Sum (string* res,int size,const string* tab){
    *res=Sum(size,tab);
}

void Sum (string* res, int size,...){


    if(l==0){
        va_start(arg,size);
        tab1[0]=va_arg(arg,char*);
        l++;
    }
    if(l<size){
        tab1[1]=va_arg(arg,char*);
        *res=Sum(2,tab1);
        tab1[0]=*res;
        l++;
        Sum(res,size,arg);
    }
    va_end(arg);
    l=0;
}

void Sum(string& res,int size, const string* tab){
    res=Sum(size,tab);
}

void Sum(string& res, int size, ...){


    if(l==0){
        va_start(arg,size);
        tab1[0]=va_arg(arg,char*);
        l++;
    }
    if(l<size){
        tab1[1]=va_arg(arg,char*);
        res=Sum(2,tab1);
        tab1[0]=res;
        l++;
        Sum(res,size,arg);
    }
    va_end(arg);
    l=0;
}

string Mult(int size, const string* tab){
    if(i==0){
        result=tab[0];
        i++;
    }
    if(i<size){
        string number=tab[i];

        if(result[0]=='-' && number[0]=='-'){

            result.erase(0,1);
            number.erase(0,1);
            result.erase(0,Countzero(result));
            k=-2;
            number.erase(0,Countzero(number));
            k=-2;
            if(Compare(result,number)==-1){
                swap(result,number);
            }
            k=-2;
            result=Multi(result,number);
            result1="";
            k=-2;
            result.erase(0,Countzero(result));
            k=-2;
            i++;
            Mult(size,tab);
        }
        else if(result[0]!='-'&& number[0]!='-'){
            if(result[0]=='+')
                result.erase(0,1);
            if(number[0]=='+')
                number.erase(0,1);
            result.erase(0,Countzero(result));
            k=-2;
            number.erase(0,Countzero(number));
            k=-2;
            if(Compare(result,number)==-1){
                swap(result,number);
            }
            k=-2;

            result=Multi(result,number);
            result1="";
            k=-2;
            result.erase(0,Countzero(result));

            k=-2;
            i++;
            Mult(size,tab);
        }
        else{
            if(result[0]=='+' ||result[0]=='-'){
                result.erase(0,1);
            }
            if(number[0]=='+'||number[0]=='-')
                number.erase(0,1);
            result.erase(0,Countzero(result));
            k=-2;
            number.erase(0,Countzero(number));
            k=-2;
            if(Compare(result,number)==-1){
                swap(result,number);
            }
            k=-2;
            result=Multi(result,number);
            result1="";
            k=-2;
            result.erase(0,Countzero(result));
            k=-2;
            if(result[0]!='0')
            result='-'+result;

            i++;
            Mult(size,tab);
        }

    }
    i=0;
    return result;
}

string Mult(int size,...){
    if(i==0){
        va_start(arg,size);
        result=va_arg(arg,char*);
        i++;
    }
    if(i<size){
        string number=va_arg(arg,char*);

        if(result[0]=='-' && number[0]=='-'){

            result.erase(0,1);
            number.erase(0,1);
            result.erase(0,Countzero(result));
            k=-2;
            number.erase(0,Countzero(number));
            k=-2;
            if(Compare(result,number)==-1){
                swap(result,number);
            }
            k=-2;
            result=Multi(result,number);
            result1="";
            k=-2;
            result.erase(0,Countzero(result));
            k=-2;
            i++;
            Mult(size,arg);
        }
        else if(result[0]!='-'&& number[0]!='-'){
            if(result[0]=='+')
                result.erase(0,1);
            if(number[0]=='+')
                number.erase(0,1);
            result.erase(0,Countzero(result));
            k=-2;
            number.erase(0,Countzero(number));
            k=-2;
            if(Compare(result,number)==-1){
                swap(result,number);
            }
            k=-2;

            result=Multi(result,number);
            result1="";
            k=-2;
            result.erase(0,Countzero(result));

            k=-2;
            i++;
            Mult(size,arg);
        }
        else{
            if(result[0]=='+' ||result[0]=='-'){
                result.erase(0,1);
            }
            if(number[0]=='+'||number[0]=='-')
                number.erase(0,1);
            result.erase(0,Countzero(result));
            k=-2;
            number.erase(0,Countzero(number));
            k=-2;
            if(Compare(result,number)==-1){
                swap(result,number);
            }
            k=-2;
            result=Multi(result,number);
            result1="";
            k=-2;
            result.erase(0,Countzero(result));
            k=-2;
            if(result[0]!='0')
                result='-'+result;

            i++;
            Mult(size,arg);
        }

    }
    i=0;
    va_end(arg);
    return result;
}

void Mult(string* res,int size, const string* tab) {
    *res=Mult(size,tab);
}

void Mult(string* res, int size,...){
    if(n==0){
        va_start(arg,size);
        tab1[0]=va_arg(arg,char*);
        n++;
    }
    if(n<size){
        tab1[1]=va_arg(arg,char*);
        *res=Mult(2,tab1);
        tab1[0]=*res;
        n++;
        Mult(res,size,arg);
    }
    va_end(arg);
    n=0;
}

void Mult(string& res,int size, const string* tab) {
    res=Mult(size,tab);
}

void Mult(string& res, int size,...){
    if(n==0){
        va_start(arg,size);
        tab1[0]=va_arg(arg,char*);
        n++;
    }
    if(n<size){
        tab1[1]=va_arg(arg,char*);
        res=Mult(2,tab1);
        tab1[0]=res;
        n++;
        Mult(res,size,arg);
    }
    va_end(arg);
    n=0;
}

string Operation(string(*f)(int ,const string* ),int size,const string* tab){
    return f(size,tab);
}

void CreateTab(int size,string* tab){

    if(i<size){
        tab[i]=va_arg(arg,char*);
        i++;
        CreateTab(size,tab);
    }
    i=0;
}

string Operation (string(*f)(int ,const string* ),int size, ...){
    va_start(arg,size);
    string tab[size];
    CreateTab(size,tab);
    va_end(arg);
    return f(size,tab);
}

void Operation(string* res,string(*f)(int ,const string* ),int size,...){
    va_start(arg,size);
    string tab[size];
    CreateTab(size,tab);
    va_end(arg);
    *res= f(size,tab);

}

void Operation(string* res, string(*f)(int ,const string* ),int size,const string* tab){
    *res=f(size,tab);
}

void Operation(string& res, string(*f)(int ,const string* ),int size,const string* tab){
    res=f(size,tab);

}

void Operation(string& res,string(*f)(int ,const string* ),int size,...){
    va_start(arg,size);
    string tab[size];
    CreateTab(size,tab);
    va_end(arg);
    res= f(size,tab);

}


int main(){

    string arr2[] = { "+0000000000000000", "-00000000000000000", "+3333333333333333", "-234121212123", "-5298592312354352", "+99657452352300005403405349", "-1423900000000000000000000000000000000000000000000000000000000000000000"};
    string* napis = &arr2[0];
    std::cout << Sum(7, napis) << std::endl;

    string arr3[] = { "321312222", "-4234320000000", "+0000000000000"};
    napis = &arr3[0];
    std::cout << Sum(3, napis) << std::endl;

    string tab[3]={"0","3333333","123123123"};

    cout<<Mult(3,tab)<< endl;

    return 0;
}
