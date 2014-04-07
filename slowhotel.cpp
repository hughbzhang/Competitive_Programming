#include <cstdio>
#define TOTAL (1<<16)
#define MAX (TOTAL*2)

using namespace std;

bool rooms[TOTAL];


void update(int left,int right, bool flag){
    for(int x = left;x<right;x++) rooms[x] = flag;
}

int find(int goal){
    int past = 0;
    int best = 0;
    for(int x = 0;x<TOTAL;x++){
        if(!rooms[x]) past++;
        else past = 0;
        if(past>=goal) return x-goal+1;
    }
    return -1;
}

int num, queries;


int main(){
    freopen("hotel.in","r",stdin);
    freopen("checker.out","w",stdout);
    scanf("%d%d",&num,&queries);
    update(num,TOTAL,1);
    int a,b,c;
    for(int x = 0;x<queries;x++){
        scanf("%d",&a);
        if(a==1){
            scanf("%d",&b);
            int start = find(b);
            printf("%d\n",start+1);
            if(start!=-1) update(start,start+b,1);
        }
        else{
            scanf("%d%d",&b,&c);
            update(b-1,b+c-1,0);
        }
    }
    return 0;
}


