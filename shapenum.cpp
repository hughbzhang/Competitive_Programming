#include <cstdio>

using namespace std;
typedef long long ll;

ll num[3];

int main(){
    ll tri = 286;
    ll pent = 165;
    ll hex = 143;
    num[0] = tri*(tri+1)/2;
    num[1] = pent*(3*pent-1)/2;
    num[2] = hex*(2*hex-1);
    while(num[0]!=num[1]||num[1]!=num[2]){
        int min = 0;
        if(num[1]<num[min]) min = 1;
        if(num[2]<num[min]) min = 2;
        if(min==0){
            tri++;
            num[0] = tri*(tri+1)/2;
        }
        else if(min==1){
            pent++;
            num[1] = pent*(3*pent-1)/2;
        }
        else{
            hex++;
            num[2] = hex*(2*hex-1);
        }
        
    }
    printf("%lld\n",num[0]);
    return 0;


}

