#include <fstream>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#define cin fi
#define cout fo
using namespace std;
ifstream fi ("KFIB.INP");
ofstream fo ("KFIB.OUT");
struct data
{
    long long U;//day co so X
    long long vt;
};
long long m,a,b,X;
data A[100001];
typedef long long matrix[3][3];
matrix E,R;
bool cmp(data a,data b )
{
    return ((a.U<b.U));
}
void Nhan(matrix Z,matrix Y,matrix X)
{
    long long i,j,k;
    matrix T;
    for (int i=1; i<=2; i++)
        for (int j=1; j<=2; j++)
        {
            T[i][j]=0;
            for (k=1; k<=2; k++)
                T[i][j]=(Z[i][k]*Y[k][j]+T[i][j])%m;
        }
    for (i=1; i<=2; i++)
        for (j=1; j<=2; j++)
            X[i][j]=T[i][j];
}
void Luythua(long long n)
{
    if (n==1)
    {
        for (int i=1; i<=2; i++)
            for (int j=1; j<=2; j++)
                R[i][j]=E[i][j];
    }
    else
    {
        Luythua(n/2);
        Nhan(R,R,R);
        if (n%2!=0)
            Nhan(R,E,R);
    }
}

long long B[100001];
int main()
{
    long long t;
    fi >>t;
    while (t>0)
    {
        R[1][2]=0;
        R[1][1]=0;
        t--;
        bool o=0;
        fi >>m>>a>>b;
        X=sqrt(6*m);
        B[0]=b%m;
        B[1]=a%m;
        for (int i=2; i<=X; i++)
        {
            B[i]=(B[i-2]-B[i-1])%m;
            if (B[i]<0)
            {
                B[i]=(B[i-2]+m-B[i-1])%m;
            }
        }
        for (int i=0; i<=X; i++)
        {
            A[i].U=B[i+1]*X+B[i];
            A[i].vt=i;
        }
        /*for (int i=0;i<X;i++) cout <<A[i].U<<" ";
        cout <<endl;*/
        sort(A+1,A+X+1,cmp);
        int u=0,v=1;
        int Y=(B[1]*X+B[0]);
        int d=0,c=X,g;
        int vt=0,e=0;
        do
        {
            g=(d+c)/2;
            if (A[g].U>Y)
            {
                c=g-1;
            }
            if (A[g].U<Y)
            {
                d=g+1;
            }
            if (A[g].U==Y)
            {
                vt=A[g].vt;
                e=1;
            }
        }
        while (d<=c && e!=1);
        if (e==1)
        {
            cout <<vt<<endl;
            o=1;
        }
        else
        {
            for (int x=1; x<=X; x++)
            {
                E[1][1]=1;
                E[1][2]=1;
                E[2][1]=1;
                E[2][2]=0;
                Luythua(x*X);
                //cout <<R[1][2]<<" "<<R[1][1]<<endl;
                Y=(R[1][2]*m+R[1][1]);
                e=0;
                d=0,c=X-1;vt=0;
                do
                {
                    g=(d+c)/2;
                    if (A[g].U>Y)
                    {
                        c=g-1;
                    }
                    if (A[g].U<Y)
                    {
                        d=g+1;
                    }
                    if (A[g].U==Y)
                    {
                        vt=A[g].vt;
                        e=1;
                    }
                }
                while (d<=c && e!=1);
                if (e==1)
                {
                    cout <<(x*X)+vt<<endl;
                    o=1;
                    break;
                }
            }
        }
        if (o==0)
            cout <<-1<<endl;
    }
    return 0;
}
