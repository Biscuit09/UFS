#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int p[1000];
int cnt;
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
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(p,-1,sizeof(p));
        int n,m;
        int a,b;
        cnt=0;
        int ans=0;
        scanf("%d%d",&n,&m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d",&a,&b);
            bing(a,b);

        }
        for(int i = 1; i < n+1; i++)
        {
            int k=find(i);
            if(k==i)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
