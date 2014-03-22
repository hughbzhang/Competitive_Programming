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

bool check(){//from wikipedia
    int sum = 0;
    int total = 0;
    for(int a = 0;a<num-1;a++){
        sum+=arr[a];
        total = 0;
        for(int x = a+1;x<num-1;x++){
            total+=min(arr[x],a+1);    
        }
        //if(arr[0]!=10) printf("%d %d\n",sum, a*(a+1)+total);
        if(sum>(a*(a+1)+total)) return false;
    }

    //print();
    return true;
}

int main(){
    freopen("fcount.in","r",stdin);
    freopen("fcount.out","w",stdout);
    scanf("%d",&num);
    num++;
    for(int x = 0;x<num;x++){
        scanf("%d",arr+x);
        ori[x] = arr[x];
        sum+=arr[x];
    }
    sort(arr,arr+num);
    reverse(arr,arr+num);
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
