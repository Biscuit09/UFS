#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int p[50010];
int val[50010];
int find(int x)
{
    if(p[x]==-1)
        return x;
    int tmp=find(p[x]);
    val[x]+=val[p[x]];
    val[x]%=3;
    return p[x]=tmp;
}


int main()
{
    int n,m;
    int t,x,y;
    scanf("%d%d",&n,&m);
    memset(p,-1,sizeof(p));
    memset(val,0,sizeof(val));
    int ans=0;
    while(m--)
    {
        scanf("%d%d%d",&t,&x,&y);
        if(x>n||y>n)
        {
            ans++;
            continue;
        }
        int t1=find(x);
        int t2=find(y);
        if(t1==t2)
        {
            if(t == 1)
            {
                if(val[x]!=val[y])ans++;
            }
            else if(t == 2)
            {
                if((val[x]+1)%3!=val[y])ans++;
            }
        }
        else
        {
            //t==1Õ¨¿‡ t==2 x≥‘y
            if(t==1)
            {
                p[t2]=t1;
                val[t2]=val[x]-val[y];
                val[t2]=(val[t2]+3)%3;
            }
            else if(t==2)
            {
                p[t2]=t1;
                val[t2]=val[x]-val[y]+1;
                val[t2]=(val[t2]+3)%3;
            }
        }

    }
    printf("%d\n",ans);
    return 0;
}
