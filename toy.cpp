#include <cstdio>
#define MAX (1000010)

using namespace std;

int num;
bool X[MAX];
int arr[MAX];
const int all = MAX-10;
int ans[MAX];
int cnt = 0;
int add = 0;

int main(){
    scanf("%d",&num);
    int a;
    for(int x = 0;x<num;x++){
        scanf("%d",&a);
        X[a] = true;
        arr[x] = a;
    }
    for(int x = 0;x<num;x++){
        if(!X[all-arr[x]+1]) ans[cnt++] = all-arr[x]+1;
        else add++;
    }
    add/=2;
    for(int x = 1;x<MAX;x++){
        if(add==0) break;
        if(!X[x]&&!X[all-x+1]){
            ans[cnt++] = x;
            ans[cnt++] = all-x+1;
            add--;
        }
    }
    printf("%d\n",cnt);
    for(int x = 0;x<cnt;x++) printf("%d\n",ans[x]);
}
