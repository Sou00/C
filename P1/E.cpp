//Igor £onak
#include <iostream>

using namespace std;

unsigned long long ware=0;

struct place
{
    unsigned short quantity;
    char label[2]={'-','-'};
    void wipe()
    {
        ware-=quantity;
        quantity=0;
        label[0]='-';
        label[1]='-';
    }
};

struct shelf
{
    place a[128];
    unsigned short placeamount;
    void wipe(unsigned short x,unsigned short y)
    {
        for(int i=x;i<y;i++)
        {
            a[i].wipe();
        }
    }
};

struct rack
{
    shelf b[128];
    unsigned short shelfamount;
    void wipe(unsigned short x,unsigned short y)
    {
        for(int i=x;i<y;i++)
        {
            b[i].wipe(0,128);
        }
    }
};

struct warehouse
{
    rack c[128];
    unsigned short rackamount;
    shelf handyshelf;
    void wipe(unsigned short x,unsigned short y)
    {
        for(int i=x;i<y;i++)
        {
            c[i].wipe(0,128);
        }
    }

};
struct team
{
    warehouse d[128];
    unsigned short warehouseamount;
    shelf handyshelf;
    rack handyrack;
    void wipe(unsigned short x, unsigned short y)
    {
        for(int i=x;i<y;i++)
        {
            d[i].wipe(0,128);
        }
    }

    void SET_AP (unsigned short w,unsigned short r, unsigned short s,unsigned short p)
    {
        if(w<warehouseamount&&r<d[w].rackamount&&
           s<d[w].c[r].shelfamount)
        {
            int sup = d[w].c[r].b[s].placeamount;
            d[w].c[r].b[s].wipe(p, sup);
            d[w].c[r].b[s].placeamount=p;
        }
        else{cout<<"error"<<endl;}
    }

    void SET_AS (unsigned short w,unsigned short r, unsigned short s,unsigned short p)
    {
        if(w<warehouseamount&&r<d[w].rackamount)
        {
            int sup = d[w].c[r].shelfamount;
            d[w].c[r].wipe(s,sup);
            d[w].c[r].shelfamount = s;

            for(int i=0;i<s;i++)
            {
                SET_AP(w,r,i,p);
            }

        }
        else{cout<<"error"<<endl;}
    }

    void SET_AR (unsigned short w,unsigned short r, unsigned short s,unsigned short p)
    {
        if(w<warehouseamount)
        {
            int sup = d[w].rackamount;
            d[w].wipe(r,sup);
            d[w].rackamount = r;

            for (int i=0;i<r;i++)
            {
                SET_AS(w,i,s,p);
            }
        }
        else{cout<<"error"<<endl;}
    }

    void SET_AW (unsigned short w,unsigned short r, unsigned short s,unsigned short p)
    {
        int sup = warehouseamount;
        wipe(w,sup);
        warehouseamount = w;

        for (int i=0;i<w;i++)
        {
            SET_AR(i,r,s,p);
        }
    }
    void SET_HW (unsigned short w,unsigned short p)
    {
        if(w<warehouseamount){
        int sup = d[w].handyshelf.placeamount;
        d[w].handyshelf.wipe(p,sup);
        d[w].handyshelf.placeamount = p;}
        else{cout<<"error"<<endl;}
    }

    void SET_HR (unsigned short s,unsigned short p)
    {
         int supp = handyrack.shelfamount;
        handyrack.wipe(s,supp);
        handyrack.shelfamount = s;

        for(int i=0;i<s;i++)
        {
             supp = handyrack.b[i].placeamount;
             handyrack.b[i].wipe(p,supp);
             handyrack.b[i].placeamount = p;
        }

    }

    void SET_HS (unsigned short p)
    {
        int supp=handyshelf.placeamount;
        handyshelf.wipe(p,supp);
        handyshelf.placeamount = p;
    }

    void PUT_W (unsigned short w, unsigned short r, unsigned short s, unsigned short p,long long e)
    {
        if(w<warehouseamount&&r<d[w].rackamount&&
           s<w[d].c[r].shelfamount&&p<w[d].c[r].b[s].placeamount)
        {
        if(e+d[w].c[r].b[s].a[p].quantity>65535)
        {
            ware+=65535-(d[w].c[r].b[s].a[p].quantity);
            d[w].c[r].b[s].a[p].quantity=65535;
        }
        else
        {
            ware+=e;
            d[w].c[r].b[s].a[p].quantity+=e;
        }
        }
        else{cout<<"error"<<endl;}
    }

    void PUT_H (unsigned short w,unsigned short p, long long e)
    {
        if(w<warehouseamount&&p<d[w].handyshelf.placeamount)
        {
        if(e+d[w].handyshelf.a[p].quantity>65535)
        {
            ware+=65535-(d[w].handyshelf.a[p].quantity);
            d[w].handyshelf.a[p].quantity=65535;
        }
        else
        {
            ware+=e;
            d[w].handyshelf.a[p].quantity+=e;
        }
        }
        else{cout<<"error"<<endl;}
    }

    void PUT_R (unsigned short s, unsigned short p, long long e)
    {
        if(s<handyrack.shelfamount&&p<handyrack.b[s].placeamount)
        {
        if(e+handyrack.b[s].a[p].quantity>65535)
        {
            ware+=65535-(handyrack.b[s].a[p].quantity);
            handyrack.b[s].a[p].quantity=65535;
        }
        else
        {
            ware+=e;
            handyrack.b[s].a[p].quantity+=e;
        }
        }
        else{cout<<"error"<<endl;}
    }

    void PUT_S (unsigned short p, long long e)
    {
        if(p<handyshelf.placeamount)
        {
        if(e+handyshelf.a[p].quantity>65535)
        {
            ware+=65535-(handyshelf.a[p].quantity);
            handyshelf.a[p].quantity = 65535;
        }
        else
        {
            ware+=e;
            handyshelf.a[p].quantity+=e;
        }
        }
        else{cout<<"error"<<endl;}
    }

    void FILL (unsigned short w, unsigned short r, unsigned short s, unsigned short p, long long e)
   {
       handyshelf.wipe(0,128);
       handyrack.wipe(0,128);
       wipe(0,warehouseamount);
       SET_AW(w,r,s,p);
       SET_HR(s,p);
       SET_HS(p);
       for (int i=0;i<w;i++)
       {
           for (int j=0;j<r;j++)
           {
               for (int k=0;k<s;k++)
               {
                   for (int l=0;l<p;l++)
                   {
                       d[i].c[j].b[k].a[l].quantity=e;
                       handyshelf.a[l].quantity=e;
                       handyrack.b[k].a[l].quantity = e;
                       d[i].handyshelf.a[l].quantity=e;
                       d[i].handyshelf.a[l].label[0]='-';
                       d[i].handyshelf.a[l].label[1]='-';
                       d[i].handyshelf.placeamount=p;
                   }
               }
           }
       }
       ware=w*r*s*p*e;
       ware+=p*e+s*p*e+w*p*e;
   }

void POP_W (unsigned short w, unsigned short r, unsigned short s, unsigned short p,long long e)
    {
        if(w<warehouseamount&&r<d[w].rackamount&&
           s<w[d].c[r].shelfamount&&p<w[d].c[r].b[s].placeamount)
        {
        if(d[w].c[r].b[s].a[p].quantity<e)
        {
            ware-=d[w].c[r].b[s].a[p].quantity;
            d[w].c[r].b[s].a[p].quantity=0;
        }
        else
        {
            ware-=e;
            d[w].c[r].b[s].a[p].quantity-=e;
        }
        }
        else{cout<<"error"<<endl;}
    }

    void POP_H (unsigned short w,unsigned short p, long long e)
    {
        if(w<warehouseamount&&p<w[d].handyshelf.placeamount)
        {
        if(d[w].handyshelf.a[p].quantity<e)
        {
            ware-=d[w].handyshelf.a[p].quantity;
            d[w].handyshelf.a[p].quantity=0;
        }
        else
        {
            ware-=e;
            d[w].handyshelf.a[p].quantity-=e;
        }

        }
        else{cout<<"error"<<endl;}
    }

    void POP_R (unsigned short s, unsigned short p, long long e)
    {
        if(s<handyrack.shelfamount&&p<handyrack.b[p].placeamount)
        {
        if(handyrack.b[s].a[p].quantity<e)
        {
            ware-=handyrack.b[s].a[p].quantity;
            handyrack.b[s].a[p].quantity=0;
        }
        else
        {
            ware-=e;
            handyrack.b[s].a[p].quantity-=e;
        }
        }
        else{cout<<"error"<<endl;}
    }

    void POP_S (unsigned short p, long long e)
    {
        if(p<handyshelf.placeamount)
        {
        if(handyshelf.a[p].quantity<e)
        {
            ware-=handyshelf.a[p].quantity;
            handyshelf.a[p].quantity = 0;
        }
        else
        {
            ware-=e;
            handyshelf.a[p].quantity-=e;
        }
        }
        else{cout<<"error"<<endl;}
    }

    void MOV_W (unsigned short w,unsigned short r,unsigned short s,unsigned short w1,unsigned short r1,unsigned short s1,unsigned short p,unsigned short e)
    {
        if(w<warehouseamount&&r<d[w].rackamount&&
           s<w[d].c[r].shelfamount&&p<w[d].c[r].b[s].placeamount&&
           w<warehouseamount&&r<d[w].rackamount&&
           s<w[d].c[r].shelfamount&&p<w[d].c[r].b[s].placeamount&&
           w1<warehouseamount&&r1<d[w1].rackamount&&
           s1<d[w1].c[r1].shelfamount&&p<d[w1].c[r1].b[s1].placeamount)
        {unsigned short b=d[w].c[r].b[s].a[p].quantity;
        unsigned short c=d[w1].c[r1].b[s1].a[p].quantity;
        if(e>b)
        {
            e=b;
        }
        if(e>(65535-c))
        {
            e=65535-c;
        }
        POP_W(w,r,s,p,e);
        PUT_W(w1,r1,s1,p,e);}
        else{cout<<"error"<<endl;}
    }

    void MOV_H (unsigned short w,unsigned short r,unsigned short s, unsigned short p,unsigned short e)
    {
        if(w<warehouseamount&&r<d[w].rackamount&&
           s<w[d].c[r].shelfamount&&p<w[d].c[r].b[s].placeamount)
        {unsigned short b=d[w].c[r].b[s].a[p].quantity;
        unsigned short c= d[w].handyshelf.a[p].quantity;
        if(e>b)
        {
            e=b;
        }
        if(e>(65535-c))
        {
            e=65535-c;
        }
        POP_W(w,r,s,p,e);
        PUT_H(w,p,e);}
        else{cout<<"error"<<endl;}
    }

    void MOV_R (unsigned short w,unsigned short r,unsigned short s,unsigned short s1,unsigned short p,unsigned short e)
    {
        if(w<warehouseamount&&r<d[w].rackamount&&
           s<w[d].c[r].shelfamount&&p<w[d].c[r].b[s].placeamount
           &&s1<handyrack.shelfamount&&p<handyrack.b[s1].placeamount)
        {unsigned short b=d[w].c[r].b[s].a[p].quantity;
        unsigned short c= handyrack.b[s1].a[p].quantity;
        if(e>b)
        {
            e=b;
        }
        if(e>(65535-c))
        {
            e=65535-c;
        }
        POP_W(w,r,s,p,e);
        PUT_R(s1,p,e);}
        else{cout<<"error"<<endl;}
    }

    void MOV_S (unsigned short s, unsigned short p,unsigned short e)
    {
        if(s<handyrack.shelfamount&&p<handyrack.b[s].placeamount
           &&p<handyshelf.placeamount)
        {unsigned short b= handyrack.b[s].a[p].quantity;
        unsigned short c= handyshelf.a[p].quantity;
        if(e>b)
        {
            e=b;
        }
        if(e>(65535-c))
        {
            e=65535-c;
        }
        POP_R(s,p,e);
        PUT_S(p,e);}
        else{cout<<"error"<<endl;}
    }

    void GET_E ()
    {
        cout<<ware<<endl;
    }

void GET_W (unsigned short w)
    {
        long long suma=0;
        if(w<warehouseamount){
        for (int i=0;i<128;i++)
        {
            for (int j=0;j<128;j++)
            {
                for (int k=0;k<128;k++)
                {
                    suma+= d[w].c[i].b[j].a[k].quantity;
                }
            }
        }
        for (int i=0;i<128;i++)
        {
            suma+=d[w].handyshelf.a[i].quantity;
        }


        cout<<suma<<endl;}
        else{cout<<"error"<<endl;}
    }

    void GET_RW (unsigned short w, unsigned short r)
    {
        long long suma=0;
        if(w<warehouseamount&&r<d[w].rackamount){
        for (int i=0;i<128;i++)
        {
            for (int j=0;j<128;j++)
            {
                suma+=d[w].c[r].b[i].a[j].quantity;
            }
        }
        cout<<suma<<endl;}
        else{cout<<"error"<<endl;}
    }

    void GET_RH ()
    {
       long long suma=0;
        for (int i=0;i<128;i++)
        {
            for (int j=0;j<128;j++)
            {
                suma+=handyrack.b[i].a[j].quantity;
            }
        }
        cout<<suma<<endl;
    }

    void GET_SW (unsigned short w, unsigned short r, unsigned short s)
    {
        long long suma=0;
        if(w<warehouseamount&&r<d[w].rackamount&&s<d[w].c[r].shelfamount)
        {for (int i=0;i<128;i++)
        {
            suma+=d[w].c[r].b[s].a[i].quantity;
        }
        cout<<suma<<endl;}
        else{cout<<"error"<<endl;}
    }

    void GET_SH (unsigned short w)
    {
        long long suma=0;
        if (w<warehouseamount){
        for (int i=0;i<128;i++)
        {
            suma+= d[w].handyshelf.a[i].quantity;
        }
        cout<<suma<<endl;}
        else{cout<<"error"<<endl;}
    }

    void GET_SR (unsigned short s)
    {
        long long suma=0;
        if(s<handyrack.shelfamount){
        for (int i=0;i<128;i++)
        {
            suma+=handyrack.b[s].a[i].quantity;
        }
        cout<<suma<<endl;}
        else{cout<<"error"<<endl;}
    }

    void GET_S ()
    {
        long long suma=0;
        for (int i=0;i<128;i++)
        {
            suma+=handyshelf.a[i].quantity;
        }
        cout<<suma<<endl;
    }

    void SET_LW (unsigned short w, unsigned short r, unsigned short s, unsigned short p,char e[2])
    {
        if(w<warehouseamount&&r<d[w].rackamount&&s<d[w].c[r].shelfamount
           &&p<w[d].c[r].b[s].placeamount)
        {
            d[w].c[r].b[s].a[p].label[0] = e[0];
            d[w].c[r].b[s].a[p].label[1] = e[1];
        }
        else{cout<<"error"<<endl;}
    }
    void SET_LH (unsigned short w, unsigned short p, char e[2])
    {
        if(w<warehouseamount&&p<w[d].handyshelf.placeamount)
        {d[w].handyshelf.a[p].label[0] = e[0];
        d[w].handyshelf.a[p].label[1] = e[1];}
        else{cout<<"error"<<endl;}
    }

    void SET_LR (unsigned short s, unsigned short p, char e[2])
    {
        if(s<handyrack.shelfamount&&p<handyrack.b[s].placeamount)
        {handyrack.b[s].a[p].label[0]=e[0];
        handyrack.b[s].a[p].label[1]=e[1];}
        else {cout<<"error"<<endl;}
    }

    void SET_LS (unsigned short p, char e[2])
    {
        if(p<handyshelf.placeamount)
        {handyshelf.a[p].label[0]=e[0];
        handyshelf.a[p].label[1]=e[1];}
        else {cout<<"error"<<endl;}
    }

    void GET_LW (unsigned short w, unsigned short r, unsigned short s, unsigned short p)
    {if(w<warehouseamount&&r<d[w].rackamount&&s<d[w].c[r].shelfamount
           &&p<w[d].c[r].b[s].placeamount)
        {cout<<d[w].c[r].b[s].a[p].label[0]<<d[w].c[r].b[s].a[p].label[1]<<endl;}
        else{cout<<"error"<<endl;}
    }

    void GET_LH (unsigned short w, unsigned short p)
    {
        if(w<warehouseamount&&p<w[d].handyshelf.placeamount)
       {cout<<d[w].handyshelf.a[p].label[0]<<d[w].handyshelf.a[p].label[1]<<endl;}
       else {cout<<"error"<<endl;}
    }

    void GET_LR (unsigned short s, unsigned short p)
    {
        if(s<handyrack.shelfamount&&p<handyrack.b[s].placeamount)
        {cout<<handyrack.b[s].a[p].label[0]<<handyrack.b[s].a[p].label[1]<<endl;}
        else{cout<<"error"<<endl;}
    }

    void GET_LS (unsigned short p)
    {
        if(p<handyshelf.placeamount)
        {cout<<handyshelf.a[p].label[0]<<handyshelf.a[p].label[1]<<endl;}
        else{cout<<"error"<<endl;}
    }

}depot;

bool check (long long a, long long b,long long c)
{
    if(b>=a&&b<c)
    {
        return true;
    }
    else{return false;}
}

int main()
{
    string f;
    while(f!="END"){
    cin>>f;
    if(f=="SET-AP")
    {
        int w,r,s,p;
        cin>>w>>r>>s>>p;
        if((check(0,w,128))&&
           (check(0,r,128))&&
           (check(0,s,128))&&
           (check(0,p,129)))
        {depot.SET_AP(w,r,s,p);}
    else{cout<<"error"<<endl;}
    }
    if(f=="SET-AS")
    {
        int w,r,s,p;
        cin>>w>>r>>s>>p;
        if((check(0,w,128))&&
           (check(0,r,128))&&
           (check(0,s,129))&&
           (check(0,p,129)))
        depot.SET_AS(w,r,s,p);
         else{cout<<"error"<<endl;}
    }
    if(f=="SET-AR")
    {
        int w,r,s,p;
        cin>>w>>r>>s>>p;
        if((check(0,w,128))&&
           (check(0,r,129))&&
           (check(0,s,129))&&
           (check(0,p,129)))
        depot.SET_AR(w,r,s,p);
        else{cout<<"error"<<endl;}
    }
    if(f=="SET-AW")
    {
        int w,r,s,p;
        cin>>w>>r>>s>>p;
        if((check(0,w,129))&&
           (check(0,r,129))&&
           (check(0,s,129))&&
           (check(0,p,129)))
        depot.SET_AW(w,r,s,p);
         else{cout<<"error"<<endl;}
    }
    if(f=="SET-HW")
    {
        int w,p;
        cin>>w>>p;
        if((check(0,w,128))&&
           (check(0,p,129)))
        depot.SET_HW(w,p);
        else{cout<<"error"<<endl;}
    }
    if(f=="SET-HR")
    {
        int s,p;
        cin>>s>>p;
        if((check(0,s,129))&&
           (check(0,p,129)))
        {depot.SET_HR(s,p);}
        else{cout<<"error"<<endl;}
    }
    if(f=="SET-HS")
    {
        int p;
        cin>>p;
        if(check(0,p,129))
        depot.SET_HS(p);
        else{cout<<"error"<<endl;}
    }
    if (f=="PUT-W")
    {
        int w,r,s,p;
        long long a;
        cin>>w>>r>>s>>p>>a;
        if((check(0,w,128))&&
           (check(0,r,128))&&
           (check(0,s,128))&&
           (check(0,p,128))&&
           a>=0)
        depot.PUT_W(w,r,s,p,a);
        else{cout<<"error"<<endl;}
    }
    if (f=="PUT-H")
    {
        int w,p;
        long long a;
        cin>>w>>p>>a;
        if((check(0,w,128))&&
           (check(0,p,128))&&
           a>=0)
        {depot.PUT_H(w,p,a);}
        else{cout<<"error"<<endl;}
    }
    if(f=="PUT-R")
    {
        int s,p;
        long long a;
        cin>>s>>p>>a;
        if((check(0,s,128))&&
           (check(0,p,128))&&
           a>=0)
        depot.PUT_R(s,p,a);
        else{cout<<"error"<<endl;}
    }
    if(f=="PUT-S")
    {
        int p;
        long long a;
        cin>>p>>a;
        if((check(0,p,128))&&
           a>=0)
        depot.PUT_S(p,a);
        else{cout<<"error"<<endl;}
    }
    if (f=="FILL")
    {
        int w,r,s,p;
        long long a;
        cin>>w>>r>>s>>p>>a;
        if((check(0,w,129))&&
           (check(0,r,129))&&
           (check(0,s,129))&&
           (check(0,p,129))&&
           a>=0)
        {depot.FILL(w,r,s,p,a);}
        else{cout<<"error"<<endl;}
    }
    if (f=="POP-W")
    {
        int w,r,s,p;
        long long a;
        cin>>w>>r>>s>>p>>a;
        if((check(0,w,128))&&
           (check(0,r,128))&&
           (check(0,s,128))&&
           (check(0,p,128))&&
           a>=0)
        depot.POP_W(w,r,s,p,a);
        else{cout<<"error"<<endl;}
    }
    if (f=="POP-H")
    {
        int w,p;
        long long a;
        cin>>w>>p>>a;
        if((check(0,w,128))&&
           (check(0,p,128))&&
           a>=0)
        depot.POP_H(w,p,a);
        else{cout<<"error"<<endl;}
    }
    if(f=="POP-R")
    {
        int s,p;
        long long a;
        cin>>s>>p>>a;
        if((check(0,s,128))&&
           (check(0,p,128))&&
           a>=0)
        depot.POP_R(s,p,a);
        else{cout<<"error"<<endl;}
    }
    if(f=="POP-S")
    {
        int p;
        long long a;
        cin>>p>>a;
        if((check(0,p,128))&&
           a>=0)
        depot.POP_S(p,a);
        else{cout<<"error"<<endl;}
    }
    if(f=="MOV-W")
    {
        int w,r,s,w1,r1,s1,p,a;
        cin>>w>>r>>s>>w1>>r1>>s1>>p>>a;
        if((check(0,w,128))&&
           (check(0,r,128))&&
           (check(0,s,128))&&
           (check(0,w1,128))&&
           (check(0,r1,128))&&
           (check(0,s1,128))&&
           (check(0,p,128))&&
           a>=0)
        depot.MOV_W(w,r,s,w1,r1,s1,p,a);
        else{cout<<"error"<<endl;}
    }
    if(f=="MOV-H")
    {
        int w,r,s,p,a;
        cin>>w>>r>>s>>p>>a;
        if((check(0,w,128))&&
           (check(0,r,128))&&
           (check(0,s,128))&&
           (check(0,p,128))&&
           a>=0)
        depot.MOV_H(w,r,s,p,a);
        else{cout<<"error"<<endl;}
    }
    if(f=="MOV-R")
    {
        int w,r,s,s1,p,a;
        cin>>w>>r>>s>>s1>>p>>a;
        if((check(0,w,128))&&
           (check(0,r,128))&&
           (check(0,s,128))&&
           (check(0,s1,128))&&
           (check(0,p,128))&&
           (check(0,a,65535)))
        depot.MOV_R(w,r,s,s1,p,a);
        else{cout<<"error"<<endl;}
    }
    if(f=="MOV-S")
    {
        int s,p,a;
        cin>>s>>p>>a;
        if((check(0,s,128))&&
           (check(0,p,128))&&
           (check(0,a,65535)))
        depot.MOV_S(s,p,a);
        else{cout<<"error"<<endl;}
    }
    if(f=="GET-E")
    {
        depot.GET_E();
    }
    if(f=="GET-W")
    {
        int w;
        cin>>w;
        if(check(0,w,128))
        depot.GET_W(w);
        else{cout<<"error"<<endl;}
    }
    if (f=="GET-RW")
    {
        int w,r;
        cin>>w>>r;
        if(check(0,w,128)&&
           (check(0,r,128)))
        depot.GET_RW(w,r);
        else{cout<<"error"<<endl;}
    }
    if(f=="GET-RH")
    {
        depot.GET_RH();
    }
    if(f=="GET-SW")
    {
        int w,r,s;
        cin>>w>>r>>s;
        if(check(0,w,128)&&
           (check(0,r,128))&&
           (check(0,s,128)))
        depot.GET_SW(w,r,s);
        else{cout<<"error"<<endl;}
    }
    if(f=="GET-SH")
    {
        int w;
        cin>>w;
        if(check(0,w,128))
        depot.GET_SH(w);
        else{cout<<"error"<<endl;}
    }
    if(f=="GET-SR")
    {
        int s;
        cin>>s;
        if(check(0,s,128))
        depot.GET_SR(s);
        else{cout<<"error"<<endl;}
    }
    if(f=="GET-S")
    {
        depot.GET_S();
    }
    if(f=="SET-LW")
    {
        int w,r,s,p;
        char  e[2];
        cin>>w>>r>>s>>p>>e[0]>>e[1];
        if((check(0,w,128))&&
           (check(0,r,128))&&
           (check(0,s,128))&&
           (check(0,p,128)))
        depot.SET_LW(w,r,s,p,e);
        else{cout<<"error"<<endl;}
    }
    if(f=="SET-LH")
    {
        int w,p;
        char  e[2];
        cin>>w>>p>>e[0]>>e[1];
        if((check(0,w,128))&&
           (check(0,p,128)))
        depot.SET_LH(w,p,e);
        else{cout<<"error"<<endl;}
    }
    if(f=="SET-LR")
    {
        int s,p;
        char  e[2];
        cin>>s>>p>>e[0]>>e[1];
        if((check(0,s,128))&&
           (check(0,p,128)))
        depot.SET_LR(s,p,e);
        else{cout<<"error"<<endl;}
    }
    if(f=="SET-LS")
    {
        int p;
        char  e[2];
        cin>>p>>e[0]>>e[1];
        if(check(0,p,128))
        depot.SET_LS(p,e);
        else{cout<<"error"<<endl;}
    }
    if(f=="GET-LW")
    {
        int w,r,s,p;
        cin>>w>>r>>s>>p;
        if((check(0,w,128))&&
           (check(0,r,128))&&
           (check(0,s,128))&&
           (check(0,p,128)))
        depot.GET_LW(w,r,s,p);
        else{cout<<"error"<<endl;}
    }
    if(f=="GET-LH")
    {
        int w,p;
        cin>>w>>p;
        if((check(0,w,128))&&
           (check(0,p,128)))
        depot.GET_LH(w,p);
        else{cout<<"error"<<endl;}
    }
    if(f=="GET-LR")
    {
        int s,p;
        cin>>s>>p;
        if((check(0,s,128))&&
           (check(0,p,128)))
        depot.GET_LR(s,p);
        else{cout<<"error"<<endl;}
    }
    if(f=="GET-LS")
    {
        int p;
        cin>>p;
        if(check(0,p,128))
        depot.GET_LS(p);
        else{cout<<"error"<<endl;}
    }}

    return 0;
}

