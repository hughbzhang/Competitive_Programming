#include <cstdio>
#include <vector>
#include <utility>
#define MAX 100010
#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;
typedef vector<int>::iterator vi;

vector<int> edge[MAX];
vector<int> MST[MAX];
int num, con;
int DAD[MAX];

int dad(int in){
    if(in==DAD[in]) return in;
    return DAD[in] = dad(DAD[in]);
}
bool same(int a,int b){
    return dad(a)==dad(b);
}
void merge(int a, int b){
    if(same(a,b)) return;
    a = dad(a);
    b = dad(b);
    DAD[a] = b;
}

bool find(int now,int past){
    for(vi it = MST[now].begin();it!=MST[now].end();++it){
        if(*it!=past){
            if(find(*it,now)) edge[now].push_back(*it);
            else edge[*it].push_back(now);
        }
    }
    if(edge[now].size()%2==0) return true;
    else return false;
}


int main(){
    for(int x = 0;x<MAX;x++) DAD[x] = x;
    scanf("%d%d",&num,&con);
    if(con%2==1){
        printf("No solution\n");
        return 0;
    }
    int a,b,last = 0;
    for(int x = 0;x<con;x++){
        scanf("%d%d",&a,&b);
        if(same(a,b)) edge[a].push_back(b);
        else{
            merge(a,b);
            MST[a].push_back(b);
            MST[b].push_back(a);
        }
    }
    find(1,1);
    for(int x = 1;x<=num;x++){
        for(int a = 0;a<edge[x].size();a+=2){
            printf("%d %d %d\n",edge[x][a],x,edge[x][a+1]);
        }
    }
    



    return 0;
}
