#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;

long long N,M;

priority_queue<pii,vector<pii>,greater<pii> > q;
long long sum = 0;
long long best = 0;
piii arr[10001001];
long long a,b,c;


int main(){
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for(int x = 0;x<M;x++){
        cin >> a >> b >> c;
        arr[x] = piii(pii(a,b),c);
    }
    sort(arr,arr+M);
    int cur = 0;
    for(int x = 1;x<=N;x++){
        while(cur<M&&arr[cur].A.A==x){
            sum+=arr[cur].B;
            q.push(pii(arr[cur].A.B+1,arr[cur].B));
            cur++;
        }
        while(!q.empty()&&q.top().A==x){
            sum-=q.top().B;
            q.pop();
        }
        if(best<sum) best = sum;
    }
    cout << best << endl;
}
