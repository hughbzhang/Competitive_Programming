#include <cstdio>
#include <iomanip>
#include <iostream>

using namespace std;
typedef long long ll;
typedef long double ld;

ll diff[1000000];
ll num;
long long total = 1;
long double sum = 0.0;
ll last = 0;

int main(){
//    freopen("test.in","r",stdin);
    cin >> num;
    int index;
    ll a,b;
    for(int x = 0;x<num;x++){
        cin >> index;
        if(index==1){
            cin >> a >> b;
            sum+=a*(ld)b;
            diff[a]+=b;
            if(a==total){
                diff[a]-=b;
                last+=b;
            }
        }
        if(index==2){
            cin >> a;
            diff[total] += last-a;
            total++;
            last = a;
            sum+=a;
        }
        if(index==3){
            sum-=last;
            total--;
            last+=diff[total];
            diff[total] = 0;
        }
//        cout << sum << " " << total << "\n";
        ld print = sum/total;
        cout << setprecision(20) << print << "\n";
        //cout << sum << " " << total << "\n";
    }


}
