//Igor £onak
#include <iostream>

using namespace std;

void cuboid(int a,int cube[][33][33],int l, int v, int p, int h, int w ,int d)
{
    long long suma=0;
    int b=l,c=v,e=p;
    if(l<(a/2)&&v<(a/2)&&p<(a/2))               //1
    {
        for(int i=0;i<=h;i++)
        {
            for(int j=0;j<=w;j++)
            {
                for(int k=0;k<=d;k++)
                {
                    if(b>=0&&b<a&&c>=0&&c<a&&e>=0&&e<a)
                    {
                        suma+=cube[b][c][e];
                    }
                    e++;
                }
                e=p;
                c++;
            }
            c=v;
            b++;
        }
    }
    if(l<(a/2)&&v<(a/2)&&p>=(a/2))                  //2
    {
        for(int i=0;i<=h;i++)
        {
            for(int j=0;j<=w;j++)
            {
                for(int k=0;k<=d;k++)
                {
                    if(b>=0&&b<a&&c>=0&&c<a&&e>=0&&e<a)
                    {
                        suma+=cube[b][c][e];
                    }
                    e--;
                }
                e=p;
                c++;
            }
            c=v;
            b++;
        }
    }
     if(l<(a/2)&&v>=(a/2)&&p>=(a/2))                        //3
    {
        for(int i=0;i<=h;i++)
        {
            for(int j=0;j<=w;j++)
            {
                for(int k=0;k<=d;k++)
                {
                    if(b>=0&&b<a&&c>=0&&c<a&&e>=0&&e<a)
                    {
                        suma+=cube[b][c][e];
                    }
                    e--;
                }
                e=p;
                c--;
            }
            c=v;
            b++;
        }
    }


    if(l<(a/2)&&v>=(a/2)&&p<(a/2))                          //4
    {
        for(int i=0;i<=h;i++)
        {
            for(int j=0;j<=w;j++)
            {
                for(int k=0;k<=d;k++)
                {
                    if(b>=0&&b<a&&c>=0&&c<a&&e>=0&&e<a)
                    {
                        suma+=cube[b][c][e];
                    }
                    e++;
                }
                e=p;
                c--;
            }
            c=v;
            b++;
        }
    }
     if(l>=(a/2)&&v<(a/2)&&p<(a/2))             //5
    {
        for(int i=0;i<=h;i++)
        {
            for(int j=0;j<=w;j++)
            {
                for(int k=0;k<=d;k++)
                {
                    if(b>=0&&b<a&&c>=0&&c<a&&e>=0&&e<a)
                    {
                        suma+=cube[b][c][e];
                    }
                    e++;
                }
                e=p;
                c++;
            }
            c=v;
            b--;
        }
    }

     if(l>=(a/2)&&v<(a/2)&&p>=(a/2))                        //6
    {
        for(int i=0;i<=h;i++)
        {
            for(int j=0;j<=w;j++)
            {
                for(int k=0;k<=d;k++)
                {
                    if(b>=0&&b<a&&c>=0&&c<a&&e>=0&&e<a)
                    {
                        suma+=cube[b][c][e];
                    }
                    e--;
                }
                e=p;
                c++;
            }
            c=v;
            b--;
        }
    }

     if(l>=(a/2)&&v>=(a/2)&&p>=(a/2))                       //7
    {
        for(int i=0;i<=h;i++)
        {
            for(int j=0;j<=w;j++)
            {
                for(int k=0;k<=d;k++)
                {
                    if(b>=0&&b<a&&c>=0&&c<a&&e>=0&&e<a)
                    {
                        suma+=cube[b][c][e];
                    }
                    e--;
                }
                e=p;
                c--;
            }
            c=v;
            b--;
        }
    }

     if(l>=(a/2)&&v>=(a/2)&&p<(a/2))                        //8
    {
        for(int i=0;i<=h;i++)
        {
            for(int j=0;j<=w;j++)
            {
                for(int k=0;k<=d;k++)
                {
                    if(b>=0&&b<a&&c>=0&&c<a&&e>=0&&e<a)
                    {
                        suma+=cube[b][c][e];
                    }
                    e++;
                }
                e=p;
                c--;
            }
            c=v;
            b--;
        }
    }
    cout<<suma<<endl;
}


void tetrahedron (int a,int cube[][33][33], int l,int v,int p,int e)
{
    long long suma=0;
    int b=l,c=v,d=p;
    if(l<(a/2)&&v<(a/2)&&p<(a/2))               //1
    {
        for(int i=0;i<=e;i++)
        {
            for(int j=0;j<=e;j++)
            {
                for(int k=0;k<=e;k++)
                {
                    if(i+j+k<=e&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d++;
                }
                d=p;
                c++;
            }
            c=v;
            b++;
        }
    }
    if(l<(a/2)&&v<(a/2)&&p>=(a/2))               //2
    {
        for(int i=0;i<=e;i++)
        {
            for(int j=0;j<=e;j++)
            {
                for(int k=0;k<=e;k++)
                {
                    if(i+j+k<=e&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d--;
                }
                d=p;
                c++;
            }
            c=v;
            b++;
        }
    }
    if(l<(a/2)&&v>=(a/2)&&p>=(a/2))               //3
    {
        for(int i=0;i<=e;i++)
        {
            for(int j=0;j<=e;j++)
            {
                for(int k=0;k<=e;k++)
                {
                    if(i+j+k<=e&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d--;
                }
                d=p;
                c--;
            }
            c=v;
            b++;
        }
    }
    if(l<(a/2)&&v>=(a/2)&&p<(a/2))               //4
    {
        for(int i=0;i<=e;i++)
        {
            for(int j=0;j<=e;j++)
            {
                for(int k=0;k<=e;k++)
                {
                    if(i+j+k<=e&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d++;
                }
                d=p;
                c--;
            }
            c=v;
            b++;
        }
    }
    if(l>=(a/2)&&v<(a/2)&&p<(a/2))               //5
    {
        for(int i=0;i<=e;i++)
        {
            for(int j=0;j<=e;j++)
            {
                for(int k=0;k<=e;k++)
                {
                    if(i+j+k<=e&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d++;
                }
                d=p;
                c++;
            }
            c=v;
            b--;
        }
    }
    if(l>=(a/2)&&v<(a/2)&&p>=(a/2))               //6
    {
        for(int i=0;i<=e;i++)
        {
            for(int j=0;j<=e;j++)
            {
                for(int k=0;k<=e;k++)
                {
                    if(i+j+k<=e&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d--;
                }
                d=p;
                c++;
            }
            c=v;
            b--;
        }
    }
    if(l>=(a/2)&&v>=(a/2)&&p>=(a/2))               //7
    {
        for(int i=0;i<=e;i++)
        {
            for(int j=0;j<=e;j++)
            {
                for(int k=0;k<=e;k++)
                {
                    if(i+j+k<=e&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d--;
                }
                d=p;
                c--;
            }
            c=v;
            b--;
        }
    }

    if(l>=(a/2)&&v>=(a/2)&&p<(a/2))               //8
    {
        for(int i=0;i<=e;i++)
        {
            for(int j=0;j<=e;j++)
            {
                for(int k=0;k<=e;k++)
                {

                    if(i+j+k<=e&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];

                    }
                    d++;
                }
                d=p;
                c--;
            }
            c=v;
            b--;
        }
    }
    cout<<suma<<endl;
}


void octal(int a,int cube[][33][33], int l, int v, int p, int r)
{
 long long suma=0;
    int b=l,c=v,d=p;

    if(l<(a/2)&&v<(a/2)&&p<(a/2))               //1
    {
        for(int i=0;i<=r;i++)
        {
            for(int j=0;j<=r;j++)
            {
                for(int k=0;k<=r;k++)
                {
                    if(i*i+j*j+k*k<=r*r&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d++;
                }
                d=p;
                c++;
            }
            c=v;
            b++;
        }
    }
    if(l<(a/2)&&v<(a/2)&&p>=(a/2))               //2
    {
        for(int i=0;i<=r;i++)
        {
            for(int j=0;j<=r;j++)
            {
                for(int k=0;k<=r;k++)
                {
                    if(i*i+j*j+k*k<=r*r&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d--;
                }
                d=p;
                c++;
            }
            c=v;
            b++;
        }
    }
    if(l<(a/2)&&v>=(a/2)&&p>=(a/2))               //3
    {
        for(int i=0;i<=r;i++)
        {
            for(int j=0;j<=r;j++)
            {
                for(int k=0;k<=r;k++)
                {
                    if(i*i+j*j+k*k<=r*r&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d--;
                }
                d=p;
                c--;
            }
            c=v;
            b++;
        }
    }
    if(l<(a/2)&&v>=(a/2)&&p<(a/2))               //4
    {
        for(int i=0;i<=r;i++)
        {
            for(int j=0;j<=r;j++)
            {
                for(int k=0;k<=r;k++)
                {
                    if(i*i+j*j+k*k<=r*r&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d++;
                }
                d=p;
                c--;
            }
            c=v;
            b++;
        }
    }
    if(l>=(a/2)&&v<(a/2)&&p<(a/2))               //5
    {
        for(int i=0;i<=r;i++)
        {
            for(int j=0;j<=r;j++)
            {
                for(int k=0;k<=r;k++)
                {
                    if(i*i+j*j+k*k<=r*r&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d++;
                }
                d=p;
                c++;
            }
            c=v;
            b--;
        }
    }
    if(l>=(a/2)&&v<(a/2)&&p>=(a/2))               //6
    {
        for(int i=0;i<=r;i++)
        {
            for(int j=0;j<=r;j++)
            {
                for(int k=0;k<=r;k++)
                {
                    if(i*i+j*j+k*k<=r*r&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d--;
                }
                d=p;
                c++;
            }
            c=v;
            b--;
        }
    }
    if(l>=(a/2)&&v>=(a/2)&&p>=(a/2))               //7
    {
        for(int i=0;i<=r;i++)
        {
            for(int j=0;j<=r;j++)
            {
                for(int k=0;k<=r;k++)
                {
                    if(i*i+j*j+k*k<=r*r&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d--;
                }
                d=p;
                c--;
            }
            c=v;
            b--;
        }
    }
    if(l>=(a/2)&&v>=(a/2)&&p<(a/2))               //8
    {
        for(int i=0;i<=r;i++)
        {
            for(int j=0;j<=r;j++)
            {
                for(int k=0;k<=r;k++)
                {
                    if(i*i+j*j+k*k<=r*r&&b>=0&&b<a&&c>=0&&c<a&&d>=0&&d<a)
                    {
                        suma+=cube[b][c][d];
                    }
                    d++;
                }
                d=p;
                c--;
            }
            c=v;
            b--;
        }
    }
    cout<<suma<<endl;
}



long long determinant( long long a[][32], int n)
{
    int znak=0;

 for(int i=0; i<n-1; i++){
        if(a[i][i]==0)
                            {
                                    for(int j=i+1;j<n;j++)
                            {
                                if(a[j][i]!=0){
                                        for(int k=0;k<n;k++)
                                            {
                                swap(a[j][k],a[i][k]);
                                }
                              break;


                            }

                            }
                            znak++;}
        for(int j=i+1; j<n; j++){
            for(int k=i+1; k<n; k++){

                a[j][k] = a[i][i]*a[j][k] - a[j][i]*a[i][k];
            }
            a[j][i]=0;
        }

        if(i>=1){
                for(int i=0; i<n-1; i++){
        if(a[i][i]==0)
                            {
                                    for(int j=i+1;j<n;j++)
                            {
                                if(a[j][i]!=0){
                                        for(int k=0;k<n;k++)
                                            {
                                swap(a[j][k],a[i][k]);
                                }
                              break;


                            }

                            }
                            znak++;}}
            for(int j=i+1; j<n; j++){
                for(int k=i+1; k<n; k++){

                  if(a[i-1][i-1]!=0) {a[j][k] = a[j][k]/a[i-1][i-1];}
                }

            }

        }
    }


 if (znak%2==0)  cout<<a[n-1][n-1]<<endl;
    else{cout<<-(a[n-1][n-1])<<endl;}
}


int main()
{
    int a;
    char b;
    cin>>a;
    int cube[a][33][33];
    if(a<=32&&a>0&&a%2==0)
    {

        for(int d=0;d<a;d++)
        {
            for(int h=0;h<a;h++)
            {
                for(int w=0;w<a;w++)
                    {
                        cin>>cube[h][w][d];
                    }
            }
        }
    }
    if(a>32||a<1||a%2!=0){return 1;}
    while(b!='E'){
    cin>>b;
    if(b=='C')
    {
    int l,v,p,h,w,d;
    cin>>l>>v>>p>>h>>w>>d;
   cuboid(a,cube,l,v,p,h,w,d);
    }
    if(b=='T')
    {
        int l,v,p,e;
        cin>>l>>v>>p>>e;
        tetrahedron(a,cube,l,v,p,e);
    }
    if(b=='O')
    {
        int l,v,p,r;
        cin>>l>>v>>p>>r;
        octal(a,cube,l,v,p,r);
    }
    if(b=='D')
    {
        char c;
        int l=0;
        int i;
        cin>>c>>i;
        if (c=='l')
        {
            long long m[a][32];
            for(int j=0;j<a;j++)
            {
                for (int k=0;k<a;k++)
                {
                    m[k][j]=cube[i][k][j];
                }
            }
            determinant(m,a);
        }
        if(c=='v')
        {
           long long  m[a][32];
            for(int j=0;j<a;j++)
            {
                for (int k=0;k<a;k++)
                {
                    m[k][j]=cube[j][i][k];
                }
            }
           determinant(m,a);
        }
        if(c=='p')
        {
            long long m[a][32];
            for(int j=0;j<a;j++)
            {
                for (int k=0;k<a;k++)
                {
                    m[k][j]=cube[k][j][i];
                }
            }
            determinant(m,a);
        }
    }
    }

    return 0;
}
