#include <cstdio>
#include <iostream>

using namespace std;

long long arr[50500];

int num;
long long total = 0;
long long ans = 0;
long long abs(long long a){
    if(a<0) return -a;
    else return a;
}
int main(){
    scanf("%d",&num);
    for(int x = 0;x<num;x++) scanf("%d",arr+x);
    for(int x = 0;x<num;x++){
        total+=arr[x];
    }
    total/=num;
    for(int x = 0;x<num-1;x++){
        ans+=abs(total-arr[x]);
        arr[x+1]+=(arr[x]-total);
    }
    cout << ans << endl;
}
