#include <cstdio>
#include <set>

using namespace std;

int arr[12];//position of the cows in the line
int place[12];//reverse index
//place[c] tells where cow c is located

bool used[12];//false is unused true is used
int num;
int f[12][3];
int best = 1000000;


void recurse(int cur, int cost, int unsolved){
    if(cost>=best) return;
    if(cur==num){
        best = cost;
        if(unsolved!=0) printf("BIG PROBLEM");
        return;
    }
    for(int x = 0;x<num;x++){
        if(used[x]) continue;
        used[x] = true;
        arr[cur] = x;
        place[x] = cur;
        int next = unsolved;
        for(int a = 0;a<3;a++){
            if(place[f[x][a]]==-1) next++;
            else next--;
        }
        recurse(cur+1,cost+next,next);
        used[x] = false;
        arr[cur] = -1;
        place[x] = -1;
    }

}

int main(){
    freopen("haywire.in","r",stdin);
    freopen("haywire.out","w",stdout);
    scanf("%d",&num);
    for(int x = 0;x<num;x++){
        place[x] = -1;
        arr[x] = -1;
        scanf("%d%d%d",&f[x][0],&f[x][1],&f[x][2]);
    }
    for(int y = 0;y<num;y++){
        for(int x = 0;x<3;x++){
            f[y][x]--;
        }
    }
    recurse(0,0,0);
    printf("%d\n",best);

    return 0;
}
