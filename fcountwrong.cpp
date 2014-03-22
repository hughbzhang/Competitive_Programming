#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int num;
int arr[550];
int ori[550];
int diff[550];//positive means decrease
int done[550];
bool good[550];
bool vis[550];
int ans = 0;
int sum = 0;

void print(){
    for(int x = 0;x<num-1;x++){
        printf("%d ",arr[x]);
    }
    printf("\n");
}
void clear(){
    for(int x = 0;x<550;x++) diff[x] = 0;
}

bool check(){
    //print();
    clear();
    int cur = 0;
    for(int x = num-2;x>0;x--){
        cur+=diff[x];
        diff[x-1]++;
        int stop = -1;
        if(arr[x]-cur>=0) stop = x-(arr[x]-cur)-1;
        else{
            diff[x-1]--;
            diff[x-1]+=(cur-arr[x]);
            if(x-2>=0) diff[x-2]-=(cur-arr[x]);
        }
        //else stop = x-(cur-arr[x])-1;
//        printf("CURRENT VAL: %d DIFF: %d CURRENT SUBTR: %d\n",arr[x]-cur,diff[x],cur);
        if(stop>=0) diff[stop]--;    
        if(stop<-1) return false;

        //printf("DIFF0 = %d\n",diff[0]);

    }
    cur+=diff[0];
    //printf("%d\n",cur);
    if(arr[0]-cur!=0) return false;
    else return true;
}

int main(){
    //freopen("fcount.in","r",stdin);
    //freopen("fcount.out","w",stdout);
    scanf("%d",&num);
    num++;
    for(int x = 0;x<num;x++){
        scanf("%d",arr+x);
        ori[x] = arr[x];
        sum+=arr[x];
    }
    sort(arr,arr+num);
   
    int past = arr[num-1];
    for(int x = num-1;x>=0;x--){
        int temp = arr[x];
        arr[x] = past;
        past = temp;
        if((sum-past)%2!=0||vis[past]) continue;
        vis[past] = true;
        if(check()){
            good[past] = true;
        } 
    }
    for(int x = 0;x<num;x++){
        if(good[ori[x]]){
            done[ans] = x+1;
            ans++;
        }
    }
    printf("%d\n",ans);
    for(int x = 0;x<ans;x++){
        printf("%d\n",done[x]);
    }

    return 0;
}
