#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int p[10010];
int in[10010];
int a[10010];
int used[10010];
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
    int u,v;
    int T=1;
    while(~scanf("%d%d",&u,&v))
    {
        int flag=true;
        int cnt=0;
        if(u==-1&&v==-1)
            break;
        if(u==0&&v==0)
        {
            printf("Case %d is a tree.\n",T++);
            continue;
        }
        memset(p,-1,sizeof(p));
        memset(used,0,sizeof(used));
        memset(in,0,sizeof(in));
        int t0=0;
        while(u!=0&&v!=0)
        {
            if(used[u]==0)
            {
                used[u]++;
                a[cnt++]=u;
            }
            if(used[v]==0)
            {
                used[v]++;
                a[cnt++]=v;
            }
            if(find(u)==find(v))flag=false;//成环
            else
            {
                bing(u,v);
                in[v]++;
            }
            scanf("%d%d",&u,&v);
        }
        for(int i = 0; i < cnt; i++)
        {
            //判断是否一个父节点
            if(find(a[i])!=find(a[0]))
            {
                flag=false;
                break;
            }
            //判断每个点的入度
            if(in[a[i]]==0)t0++;
            else if(in[a[i]]>1)
            {
                flag=false;
                break;
            }
        }
        if(t0!=1)flag=false;
        if(flag==true)printf("Case %d is a tree.\n",T++);
        else printf("Case %d is not a tree.\n",T++);

    }
    return 0;
}
