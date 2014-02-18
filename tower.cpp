#include <cstdio>
#include <map>

#define MAX 100010
#define LARGE (1e7)

using namespace std;

int num;
int narrow[MAX];
int hay[MAX];
int height[MAX];
map<int,int> pre;
int q[MAX];
int front = 0;
int back = 0;

int main(){
    freopen("tower.in","r",stdin);
    freopen("tower.out","w",stdout);
    scanf("%d",&num);
    for(int x = 0;x<num;x++) scanf("%d",hay+x);
    pre[-1] = 0;
    for(int x = 0;x<num;x++) pre[x] = pre[x-1]+hay[x];
    /*for(int x = num-1;x>=0;x--){
        int cur = 0;
        bool back = false;
        for(int y = x;y<num;y++){
            if(back) break; 
            cur+=hay[y];
            if(cur>=narrow[y+1]){
                narrow[x] = cur;
                height[x] = height[y+1]+1;
                back = true;
            }
        }
    }*/
    narrow[num] = 0;
    height[num] = 0;
    q[back] = num;
    back++;

    for(int x = num-1;x>=0;x--){
        while(front<back&&narrow[q[front]]<=pre[q[front]-1]-pre[x-1]) front++;
        front--;
        narrow[x] = pre[q[front]-1]-pre[x-1];
        height[x] = height[q[front]]+1;
        while(back>front&&narrow[q[back-1]]>=narrow[x]+pre[q[back-1]-1]-pre[x-1]) back--;
        q[back] = x;
        back++;
    }

    printf("%d\n",height[0]);
    return 0;
}
