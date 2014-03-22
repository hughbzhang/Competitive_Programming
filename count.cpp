#include <cstdio>
#include <cmath>

using namespace std;

bool check(int sum, int target){
    if(sum<=target) return false;
    target*=target;
    int stop = sum/2;
    for(int x = 1;x<=stop;x++){
        if(x*x+(sum-x)*(sum-x)==target){
            //printf("%d %d %d\n",x,sum-x,(int)sqrt(target));
            
            return true;
        }
    }
    return false;
}

int cnt(int total){
    int num = 0;
    for(int x = 1;x<total;x++){
        if(check(x,total-x)) num++;
    }
    return num;
}


int main(){
    int best = 0;
    int ans = -1;
    for(int x = 1;x<1001;x++){
        int pos = cnt(x);
        if(pos>best){
            ans = x;
            best = pos;
        }
    }
    printf("%d %d\n",ans,best);


    return 0; 
}
