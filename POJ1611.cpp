#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int p[30010];
int num[30010];
int find(int x)
{
    if(p[x]==-1)
        return x;
    return p[x]=find(p[x]);
}

void bing(int x,int y)
{
    int t1=find(x);
    int t2=find(y);
    if(t1!=t2)
    {
        p[t1]=t2;
        num[t2]+=num[t1];
    }
}

int main()
{
    int n,m;
    int i,j;
    int a,a0,k;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)
        {
            break;
        }
        for(i = 0; i < n; i++)
        {
            p[i]=-1;
            num[i]=1;
        }
        while(m--)
        {
            scanf("%d",&k);
            for(i = 0; i < k; i++)
            {
                if(i == 0)scanf("%d",&a0);
                else
                {
                    scanf("%d",&a);
                    bing(a,a0);
                }
            }
        }
        printf("%d\n",num[find(0)]);
    }
    return 0;
}
