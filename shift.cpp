#include <cstdio>
#include <iostream>
#define MAX 1000001

using namespace std;
typedef long long ll;

int tests;
long long BIT[MAX];

void add(int x){
    while(x<MAX){
        BIT[x]++;
        x+=(x&-x);
    }
}
long long query(int x){
    long long sum = 0;
    while(x>0){
        sum+=BIT[x];
        x-=(x&-x);
    }
    return sum;
}
void clear(){
    for(int x = 0;x<MAX;x++){
        BIT[x] = 0;
    }
}


int main(){
    freopen("in.txt","r",stdin);


    cin >> tests;
    for(int x = 0;x<tests;x++){
        clear();
        int num,temp,total = 0;
        ll ans = 0;
        cin >> num;
        
        for(int x = 0;x<num;x++){
            cin >> temp;
            ans+=(total-query(temp));
            add(temp);
            total++;
        }
        cout << ans << "\n";








    }
}
