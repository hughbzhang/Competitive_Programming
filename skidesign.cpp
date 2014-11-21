/*
ID: bigfish2
LANG:C++
TASK:skidesign
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int N;
int hill[1500];
long long best = 99999999;

int main(){
    freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    cin >> N;
    for(int x = 0;x<N;x++) cin >> hill[x];
    sort(hill,hill+N);
    if(hill[0]+17>=hill[N-1]) best = 0;
    for(int x = hill[0];x<=hill[N-1]-17;x++){
        long long temp = 0;
        for(int a = 0;a<N;a++){
            if(hill[a]<x) temp+=(x-hill[a])*(x-hill[a]);
            if(hill[a]>x+17) temp+=(hill[a]-x-17)*(hill[a]-x-17);
        }
        if(temp<best) best = temp;
    }
    
    cout << best << endl;
}
