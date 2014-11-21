/*
ID:bigfish2
LANG:C++
TASK:theme
*/
#include <cstdio>
#include <utility>
#include <iostream>
#include <algorithm>
#define A first
#define B second


using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;

const ll prime = 1e9+7;
int arr[10000];
ll p[10000];
ll key[10000];
pii s[10000];
int N;

void reset(){
    for(int x = 0;x<10000;x++) key[x] = 0;
    for(int x = 0;x<10000;x++) s[x] = pii(0,0);
}

bool check(int length){
    reset();
    ll trans = 0;
    for(int x = 0;x<length;x++){
        trans+=p[x];
    }
    for(int x = 0;x<length;x++){
        key[0]+=arr[x]*p[length-1-x];
    }
    for(int x = 0;x<N-length;x++){
        key[x+1] = prime*(key[x]-arr[x]*p[length-1])+arr[x+length];
    }
    for(int x = 0;x<N-length+1;x++){
        for(int a = 0;a<arr[x];a++){
            key[x]-=trans;
        }
    }
    for(int x = 0;x<N-length+1;x++){
        s[x] = pii(key[x],x);
    }
    sort(s,s+N-length+1);
    int start = 0;
    int cur;

/*    for(int x = 0;x<N-length+1;x++){
        cout << s[x].A << " ";
    }
    cout << endl;
*/




    while(start<N-length+1){
        cur = start+1;
        while(cur<N-length+1&&s[cur].A==s[start].A) cur++;
        cur--;
        if(s[cur].B-s[start].B>=length) return true;
        start = cur+1;
    }
    
    return false;
}




int main(){
    freopen("theme.in","r",stdin);
    freopen("theme.out","w",stdout);
    cin >> N;
    for(int x = 0;x<N;x++) cin >> arr[x];
    p[0] = 1;
    for(int x = 1;x<10000;x++) p[x] = p[x-1]*prime;
    int bot = 1;
    int top = N;
    
    while(bot<top){
        int mid = bot+(top-bot)/2;
        if((bot+top)%2==1) mid++;
        if(check(mid)) bot = mid;
        else top = mid-1;
    }
    if(bot<5) bot = 0;
    cout << bot << endl;
}
