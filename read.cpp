#include <cstdio>
#include <algorithm>
#include <iostream>

#define MAX 100100

using namespace std;
typedef long long ll;

int num,goals;

ll head[MAX];
ll track[MAX];

bool check(ll best){
    int s = 0;
    for(int x = 0;x<num;x++){
        if(s==goals) break;
        ll you = head[x];
        if(track[s]>=head[x]) you = best+head[x];
        else{
            if(head[x]-track[s]>best) return false;
            you = max(you,best-head[x]+track[s]+track[s]);
            if((best-head[x]+track[s])/2+head[x]>you) you = (best-head[x]+track[s])/2+head[x];
        }
        ////cout << you << " " << head[x] << " " << track[s] << endl;
        while(s<goals&&track[s]<=you) s++;
    }
    if(s==goals) return true;
    else return false;

}


int main(){
    //ios::sync_with_stdio(0);
    cin >> num >> goals;
    for(int x = 0;x<num;x++) cin >> head[x];
    for(int x = 0;x<goals;x++) cin >> track[x];
    sort(head,head+num);
    sort(track,track+goals);
    ll top = max(track[goals-1],head[num-1])*3;
    ll bot = 0;
    while(bot<top){
        ll mid = bot + (top-bot)/2;
        if(check(mid)) top = mid;
        else bot = mid+1;
    }
    cout << bot << endl;
}

