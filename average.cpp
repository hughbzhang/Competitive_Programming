#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;


ll list[2000000];
ll total = 1;
ll sum = 0;
ll num;

int main(){
    freopen("test.in","r",stdin);
    cin >> num;
    int index;
    ll a,b;
    for(int x = 0;x<num;x++){
        cin >> index;
        if(index==1){
            cin >> a >> b;
            sum+=a*b;
            for(int x = 0;x<a;x++) list[x]+=b;
        }
        else if(index==2){
            cin >> a;
            list[total] = a;
            total++;
            sum+=a;
        }
        else{
            total--;
            sum-=list[total];
            list[total] = 0;
        }
        cout << sum << " " << total << "\n";
    }
}

