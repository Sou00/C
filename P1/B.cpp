//Igor £onak
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    if(N>=0&&N<=10000)
    {double a[N];
    double x[N];
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<N;i++){
    x[i]=a[i];}
    int b;               // dlugosc rozkladu i ilosc elementow maski
    cin>>b;
    if(b>=0&&b<=21&&b<=N&&(b%2)!=0)
    {
        double z[b];
        for(int i=0;i<b;i++)
        {
            cin>>z[i];
        }

        int A,B,C;
        cin>>A>>B>>C;                                         //A-odstep maski B-indeks poczatku filtra C-indeks konca
        if(A>=0&&B>=0&&C>=0)
        {
             double suma=0;
             char F;
             cin>>F;
             if(F=='r'||F=='m'||F=='w')
             {
             if(F=='r')
             {
                 int i1=0;
                 int j1=0;
                 int l1=b;
                 int i2=0;
                 int j2=0;
                 double b1=b;
                while(B>=N){B=B-N;}
                while(C>=N){C=C-N;}
                int k1=B;
                 int m1=C;
                if(B<=C){                                  //pierwszy przypadek
                    double v[(C-B)+1];

                        for(int i=B;i<=C;i++)
                 {
                     v[i2]=a[i];
                     i2++;

                 }
                 i2=0;


                 while(k1!=m1+1)
                 {
                 while((l1-1)>0)
                     {
                         while((j1-A)<=0){j1+=(C-B)+1;}
                         while((i1+A)>=(C-B)){i1-=(C-B)+1;}
                         suma+=v[j1-1-A];
                         suma+=v[i1+1+A];
                         l1=l1-2;
                         i1+=1+A;
                         j1--;
                         j1-=A;

                     }

                     l1=b;
                 suma+=a[k1];
                 x[k1]=(suma/b1);
                 suma=0;
                     k1++;
                     i2++;
                     j2++;
                     i1=i2;
                     j1=j2;}
                  for(int i=0;i<N;i++)
                 {

                     cout<<(double)((int)(x[i]*100))/100<<" ";
                 }

                 }
                if(B>C)                                                  // drugi przypadek
                 {
                    double v[N-B+C+1];
                    for(int i=k1;i!=m1+1;i++)
                 {
                     if(i==N){i=0;}
                     v[i2]=a[i];
                     i2++;
                 }i2=0;
                     while(k1!=m1+1)
                 {

                     while((l1-1)>0)
                      {
                        while((j1-A)<=0){j1+=N-B+C+1;}
                         while((i1+A)>=(N-B+C)){i1-=N-B+C+1;}
                         suma+=v[j1-1-A];
                         suma+=v[i1+1+A];
                         l1=l1-2;
                         i1+=1+A;
                         j1--;
                         j1-=A;

                     }
                     l1=b;
                 suma+=a[k1];
                 x[k1]=(suma/b1);
                 suma=0;
                     k1++;
                     i2++;
                     j2++;
                     if(k1==N){k1=0;}
                     i1=i2;
                     j1=j2;
                 }
                 for(int i=0;i<N;i++)
                 {

                     cout<<(double)((int)(x[i]*100))/100<<" ";
                 }


              }}



             if(F=='m')
             {
                 int i1=0;
                 int j1=0;
                 int l1=b;
                 int i2=0;
                 int j2=0;
                 int i3=0;
                 while(B>=N){B=B-N;}
                while(C>=N){C=C-N;}
                int k1=B;
                 int m1=C;
                    if(B<=C){                                                               //pierwszy przypadek
                    double v[(C-B)+1];

                        for(int i=B;i<=C;i++)
                 {
                     v[i2]=a[i];
                     i2++;
                 }
                 i2=0;
                 double m[b];
                 while(k1!=m1+1)
                 {
                 while((l1-1)>0)
                     {
                         while((j1-A)<=0){j1+=(C-B)+1;}
                         while((i1+A)>=(C-B)){i1-=(C-B)+1;}
                         m[i3]=v[j1-1-A];
                         m[i3+1]=v[i1+1+A];
                         i3+=2;
                         l1=l1-2;
                         i1+=1+A;
                         j1--;
                         j1-=A;
                     }

                     l1=b;
                     m[i3]=a[k1];
                     i3=0;
                     for(int i=1;i<b;i++)                       // sortowanie maski
        {
         int j3,pom;
         j3=i-1 ;
         pom=m[i];
         while( j3 >= 0 && pom < m[j3] )
          {
           m[j3+1]=m[j3];
           j3=j3-1;
          }
         m[j3+1] = pom ;}
         x[k1]=m[(b-1)/2];
         k1++;
         i2++;
         j2++;
         i1=i2;
         j1=j2;
             }
                for(int i=0;i<N;i++)
                 {

                     cout<<(double)((int)(x[i]*100))/100<<" ";
                 }
             }
             else                                                           //drugi przypadek
             {
                 double v[N-B+C+1];
                    for(int i=k1;i!=m1+1;i++)
                 {
                     if(i==N){i=0;}
                     v[i2]=a[i];
                     i2++;
                 }i2=0;
                 double m[b];
                     while(k1!=m1+1)
                 {

                     while((l1-1)>0)
                      {
                         while((j1-A)<=0){j1+=N-B+C+1;}
                         while((i1+A)>=(N-B+C)){i1-=N-B+C+1;}
                         m[i3]=v[j1-1-A];
                         m[i3+1]=v[i1+1+A];
                         i3+=2;
                         l1=l1-2;
                         i1+=1+A;
                         j1--;
                         j1-=A;
                     }
                     l1=b;
                m[i3]=a[k1];
                     i3=0;
                     for(int i=1;i<b;i++)                       // sortowanie maski
        {
         int j3,pom;
         j3=i-1 ;
         pom=m[i];
         while( j3 >= 0 && pom < m[j3] )
          {
           m[j3+1]=m[j3];
           j3=j3-1;
          }
         m[j3+1] = pom ;}
         x[k1]=m[(b-1)/2];
                     k1++;
                     i2++;
                     j2++;
                     if(k1==N){k1=0;}
                     i1=i2;
                     j1=j2;
                 }
                 for(int i=0;i<N;i++)
                 {

                     cout<<(double)((int)(x[i]*100))/100<<" ";
                 }

             }
             }
             if(F=='w')
             {
                int i1=0;
                 int j1=0;
                 int l1=b;
                 int i2=0;
                 int j2=0;
                 int j3=0;
                 int srodek=(b-1)/2;
                while(B>=N){B=B-N;}
                while(C>=N){C=C-N;}
                int k1=B;
                 int m1=C;
                if(B<=C){                                       //pierwszy przypadek
                    double v[(C-B)+1];
                        for(int i=B;i<=C;i++)
                 {
                     v[i2]=a[i];
                     i2++;
                 }
                 suma=0;
                 i2=0;

                 while(k1!=m1+1)
                 {
                 while((l1-1)>0)
                     {
                         while((j1-A)<=0){j1+=(C-B)+1;}
                         while((i1+A)>=(C-B)){i1-=(C-B)+1;}
                         suma+=((v[j1-1-A])*(z[srodek-1-j3]));
                         suma+=((v[i1+1+A])*(z[srodek+1+j3]));
                         l1=l1-2;
                         i1+=1+A;
                         j1--;
                         j1-=A;
                         j3++;
                            }
                            j3=0;
                     l1=b;
                 suma+=((a[k1])*(z[srodek]));
                 x[k1]=suma;

                 suma=0;
                     k1++;
                     i2++;
                     j2++;
                     i1=i2;
                     j1=j2;}
                  for(int i=0;i<N;i++)
                 {

                     cout<<(double)((int)(x[i]*100))/100<<" ";
                 }

                 }
                 if(B>C)                                                    //drugi przypadek
                 {
                     double v[N-B+C+1];
                    for(int i=k1;i!=m1+1;i++)
                 {
                     if(i==N){i=0;}
                     v[i2]=a[i];
                     i2++;

                 }i2=0;


                     while(k1!=m1+1)
                 {

                     while((l1-1)>0)
                      {
                         while((j1-A)<=0){j1+=N-B+C+1;}
                         while((i1+A)>=(N-B+C)){i1-=N-B+C+1;}
                         suma+=((v[j1-1-A])*(z[srodek-1-j3]));
                         suma+=((v[i1+1+A])*(z[srodek+1+j3]));
                         l1=l1-2;
                          i1+=1+A;
                         j1--;
                         j1-=A;
                         j3++;


                     }
                     j3=0;
                     l1=b;
                 suma+=((a[k1])*(z[srodek]));
                 x[k1]=suma;
                 suma=0;
                     k1++;
                     if(k1==N){k1=0;}
                     i2++;
                     j2++;
                     i1=i2;
                     j1=j2;
                 }
                 for(int i=0;i<N;i++)
                 {

                     cout<<(double)((int)(x[i]*100))/100<<" ";
                 }
                 }
             }
             }
             else{return 1;}

        }

    }

    }
    return 0;
}
