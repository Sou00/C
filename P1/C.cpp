//Igor £onak
#include <iostream>

using namespace std;

void Add (int liczba, int a[])
{
    int k=0;
    int i=0;
    if (liczba>0&&liczba<4096)
    {
        while(a[i]!=(-1))
        {
            if(a[i]==liczba)
            {
                k=1;
            }
            i++;

        }
        if(k==0)
        {
           a[i]=liczba;
           a[i+1]=(-1);
        }
    }
}




void Create(int liczba, int a[], int b[])
{
    int k=0;
    int j=0;

    for (int i=0;i<liczba;i++)
    {
        for(int l=i+1;l<liczba;l++)
        {
            if(a[i]==a[l])
            {
                k=1;
            }
        }
        if(k==0&&a[i]<4096&&a[i]>0)
        {
            b[j]=a[i];
            j++;
        }
        k=0;
    }
    b[j]=(-1);

}



void Union (int a[], int b[], int c[])
{
    int j=0;
    int l=0;
    for (int i=0;a[i]!=(-1);i++)
    {
        c[i]=a[i];
        j++;
    }
    for (int i=0;b[i]!=(-1);i++)
    {
        for(int k=0;a[k]!=(-1);k++)
        {
            if(a[k]==b[i])
            {
              l=1;
            }
        }
        if(l==0)
            {
                c[j]=b[i];
                j++;
            }
            l=0;
            }
            c[j]=(-1);
}




void Intersection (int a[], int b[], int c[])
{
    int j=0;
    for(int i=0;a[i]!=(-1);i++)
    {
        for(int k=0;b[k]!=(-1);k++)
        {
           if(a[i]==b[k])
           {
               c[j]=a[i];
               j++;
           }

        }
    }
    c[j]=(-1);
}



void Difference (int a[], int b[], int c[])
{
    int j=0;
    int l=0;
    for(int i=0;a[i]!=(-1);i++)
    {
        for(int k=0;b[k]!=(-1);k++)
        {
            if(a[i]==b[k])
            {
                l=1;
            }
        }
        if(l==0)
        {
            c[j]=a[i];
            j++;
        }
        l=0;
    }
    c[j]=(-1);

}


void Symmetric (int a[], int b[], int c[])
{
    int j=0;
    int l=0;
    for(int i=0;a[i]!=(-1);i++)
    {
        for(int k=0;b[k]!=(-1);k++)
        {
            if(a[i]==b[k])
            {
                l=1;
            }
        }
        if(l==0)
        {
            c[j]=a[i];
            j++;
        }
        l=0;
    }
    for(int i=0;b[i]!=(-1);i++)
    {
        for(int k=0;a[k]!=(-1);k++)
        {
            if(b[i]==a[k])
            {
                l=1;
            }
        }
        if(l==0)
        {
            c[j]=b[i];
            j++;
        }
        l=0;
    }
    c[j]=(-1);
}


void Complement(int a[],int b[])
{
    int j=0;
    int l=1;
    int m=0;
    int n=0;
    for(int i=0;a[i]!=(-1);i++)
    {
        j++;
    }
    for(int i=0;i<(4095-j);i++)
    {
        for(int k=0;a[k]!=(-1);k++)
        {
            if(a[k]==l)
            {
              m=1;

            }

        }
        if(m==0)
        {
            b[i]=l;
            l++;
        }
        else{l++;i--;n--;}
        m=0;
        n++;
    }
    b[n]=(-1);
}


bool Subset (int a[], int b[])
{
    bool k=0;
    bool l=true;
    for(int i=0;a[i]!=(-1);i++)
    {
        for(int j=0;b[j]!=(-1);j++)
        {
            if(a[i]==b[j])
            {
               k=1;
            }

        }
        if(k==0)
        {
         l=false;
        }
        k=0;

    }

    return l;
}


bool Equal (int a[], int b[])
{
    int k=0;
    bool l=1;
    for(int i=0;a[i]!=(-1);i++)
    {
        for(int j=0;b[j]!=(-1);j++)
        {
            if(a[i]==b[j])
            {
               k=1;
            }

        }
        if(k==0)
        {
         l=0;

        }
        k=0;

    }


    for(int i=0;b[i]!=(-1);i++)
    {
        for(int j=0;a[j]!=(-1);j++)
        {
            if(a[i]==b[j])
            {
               k=1;
            }

        }
        if(k==0)
        {
         l=0;

        }
        k=0;

    }

    return l;
}

bool Empty (int a[])
{

    if(a[0]!=(-1))
    {
        return 0;
    }
    return 1;
}

bool Nonempty (int a[])
{
    if(a[0]==(-1))
    {
        return 0;
    }
    return 1;
}

bool Element (int liczba, int a[])
{
    for(int i=0;a[i]!=(-1);i++)
    {
        if(liczba==a[i])
        {
            return 1;
        }
    }
    return 0;
}

double Arithmetic (int a[])
{
    double k=0;
    double suma=0;
    if(a[0]!=(-1)){
    for(int i=0;a[i]!=(-1);i++)
    {
        suma+=a[i];
        k++;
    }
    return suma/k;
    }
    return 0;}



double Harmonic (int a[])
{
    double k=0;
    double suma=0;
    if(a[0]!=(-1))
    {
        for(int i=0;a[i]!=(-1);i++)
        {
            suma+=(1./(a[i]));
            k++;
        }
        return k/suma;
    }
    return 1;
}


void MinMax (int a[], int* mini , int& maxi)
{
    if(a[0]!=(-1)){
            *mini=a[0];
    maxi=a[0];
    for(int i=0;a[i]!=(-1);i++)
    {
        if(a[i]<*mini)
        {
            *mini=a[i];
        }
        if(a[i]>maxi)
        {
            maxi=a[i];
        }
    }
    }
}

void Cardinality (int a[], int* liczba)
{
    int k=0;
    for(int i=0;a[i]!=(-1);i++)
    {
        k++;
    }
    *liczba=k;
}

void Properties(int a[], char b[], double& aryt, double* harm, int& mini, int* maxi, int& moc)
{
    int ar=0,h=0,m=0,c=0;
    for(int i=0;b[i]!=('\0');i++)
    {
        if(b[i]=='a'){ar=1;}
        if(b[i]=='h'){h=1;}
        if(b[i]=='m'){m=1;}
        if(b[i]=='c'){c=1;}
    }
    if(ar==1)
    {
    double k=0;
    double suma=0;
    if(a[0]!=(-1)){
    for(int i=0;a[i]!=(-1);i++)
    {
        suma+=a[i];
        k++;
    }
    aryt=suma/k;
    }
    else{aryt=0;}
    }
    if(h==1)
    {
        double k=0;
    double suma=0;
    if(a[0]!=(-1))
    {
        for(int i=0;a[i]!=(-1);i++)
        {
            suma+=(1./(a[i]));
            k++;
        }
        *harm=k/suma;
    }
    else{*harm=1;}
    }
    if(m==1)
    {
         if(a[0]!=(-1)){
            mini=a[0];
    *maxi=a[0];
    for(int i=0;a[i]!=(-1);i++)
    {
        if(a[i]<mini)
        {
            mini=a[i];
        }
        if(a[i]>*maxi)
        {
            *maxi=a[i];
        }
    }
    }
    }
    if(c==1)
    {
    int k=0;
    for(int i=0;a[i]!=(-1);i++)
    {
        k++;
    }
    moc=k;
    }

}




