#include <cstdio>
#include <utility>
#include <algorithm>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

int num;

pii arr[200];
int cnt = 0;
int main(){
    freopen("recording.in","r",stdin);
    freopen("recording.out","w",stdout);
    scanf("%d",&num);
    int a,b;
    for(int x = 0;x<num;x++){
        scanf("%d%d",&a,&b);
        arr[x] = pii(b,a);
    }
    int end1 = 0;
    int end2 = 0;
    sort(arr,arr+num);
    for(int x = 0;x<num;x++){
        if(arr[x].B>=end2){
            end2 = arr[x].A;
            cnt++; 
            //printf("%d %d\n",arr[x].B,arr[x].A);
        }
        else if(arr[x].B>=end1){
            end1 = arr[x].A;
            cnt++;
        }
        if(end2<end1){
            int temp = end1;
            end1 = end2;
            end2 = temp;
        }

    }
    printf("%d\n",cnt);
}
