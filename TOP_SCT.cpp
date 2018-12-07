#include <fstream>
#include <iostream>
#include <cmath>
#define cin fi
#define cout fo
using namespace std;
ifstream fi ("TOP_SCT.inp");
ofstream fo ("TOP_SCT.OUT");
long long oo=1001;
long long n,m,k,i,j,res1,res2,b,ddres1,ddres2;
struct data
{
    long long a,cx;
};
data a[1001];
int main()
{
    cin >>n>>m>>k;
    for (i=1;i<=n;i++) cin >>a[i].a;
    for (i=1;i<=n;i++) a[i].cx=1;
    for (i=1;i<=m;i++)
    {
        cin >>b;
        res1=-1;
        res2=oo;
        ddres1=0;
        ddres2=0;
        for (j=k;j>0;j--)
        {
            if (b==a[j].a && a[j].cx==1)
            {
                res1=j;
                ddres1=1;
                break;
            }
            if (b<a[j].a && a[j].cx==1)
            {
                if (j>res1) res1=j;
            }
        }
        for (j=k+1;j<=n;j++)
        {
            if (b==a[j].a && a[j].cx==1)
            {
                res2=j;
                ddres2=1;
                break;
            }
            if (b<a[j].a && a[j].cx==1)
            {
                if (j<res2) res2=j;
            }
        }
        if ((res1!=-1 && res2!=oo))
        {
            if ((ddres1==1 && ddres2==1)||(ddres1!=1 && ddres2!=1))
            {
                if (abs(res1-k)<=abs(res2-k-1))
                {
                    cout <<res1<<" ";
                    a[res1].cx=0;
                }
                else
                {
                    cout <<res2<<" ";
                    a[res2].cx=0;
                }
            }
            if (ddres1==1 && ddres2!=1)
            {
                cout <<res1<<" ";
                a[res1].cx=0;
            }
            if (ddres1!=1 && ddres2==1)
            {
                cout <<res2<<" ";
                a[res2].cx=0;
            }
        }
        if (res1!=-1 && res2==oo)
        {
            cout <<res1<<" ";
            a[res1].cx=0;
        }
        if (res1==-1 && res2!=oo)
        {
            a[res2].cx=0;
            cout <<res2<<" ";
        }
        if (res1==-1 && res2==oo)
        {
            cout <<-1<<" ";
        }
    }
    return 0;
}
