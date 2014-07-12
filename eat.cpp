#include <cstdio>
#include <queue>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

int N,X;
int a,b,c;

priority_queue<int> one;
priority_queue<int> two;
vector<pii> ONE;
vector<pii> TWO;

int main(){
    //freopen("in.txt","r",stdin);

    cin >> N >> X;
    for(int x = 0;x<N;x++){
        cin >> a >> b >> c;
        if(a) ONE.push_back(pii(b,c));
        else TWO.push_back(pii(b,c));
    }
    sort(ONE.begin(),ONE.end());
    sort(TWO.begin(),TWO.end());
    bool start = true;
    int cntA = 0,cntB = 0;
    int ans = 0;
    int jump = X;
    while(true){
        if(start){
            while(cntA<ONE.size()&&ONE[cntA].A<=jump){
                one.push(ONE[cntA].B);
                cntA++;
            }
            if(one.size()==0) break;
            ans++;
            jump+=one.top();
            one.pop();
        }
        else{
            while(cntB<TWO.size()&&TWO[cntB].A<=jump){
                two.push(TWO[cntB].B);
                cntB++;
            }
            if(two.size()==0) break;
            ans++;
            jump+=two.top();
            two.pop();
        }
        start = !start;
    }
    start = false;
    int best = ans;
    cntA = 0;
    cntB = 0;
    ans = 0;
    jump = X;
    while(one.size()>0) one.pop();
    while(two.size()>0) two.pop();

    while(true){
        if(start){
            while(cntA<ONE.size()&&ONE[cntA].A<=jump){
                one.push(ONE[cntA].B);
                cntA++;
            }
            if(one.size()==0) break;
            ans++;
            jump+=one.top();
            one.pop();
        }
        else{
            while(cntB<TWO.size()&&TWO[cntB].A<=jump){
                two.push(TWO[cntB].B);
                cntB++;
            }
            if(two.size()==0) break;
            ans++;
            jump+=two.top();
            two.pop();
        }
        start = !start;
    }
   cout << max(ans,best) << endl;
    //
}

