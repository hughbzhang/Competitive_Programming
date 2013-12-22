#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

bool ok[1000000000];
int arr[] = {1,2,3,4,5,6,7,8,9};    

void split(int x,int y){
    int a = 1;
    int one = 0;
    int two = 0;
    int thr = 0;
    for(int q = 0;q<x;q++){
        one+=arr[q]*a;
        a*=10;
    }
    a = 1;
    for(int q = x;q<y;q++){
        two+=arr[q]*a;
        a*=10;
    }
    a = 1;
    for(int q = y;q<9;q++){
        thr+=arr[q]*a;
        a*=10;
    }
    a = 1;
    if(one*two==thr){
        printf("%d x %d = %d\n",one,two,thr);
        ok[thr] = true;
    }
}


int main(){
    do{
        for(int x = 1;x<8;x++){
            for(int y = x+1;y<9;y++){
                 split(x,y);
            }
        }
    } 
    while(next_permutation(arr,arr+9));
    long long sum = 0;
    for(int x = 0;x<100000;x++){
        if(ok[x]) sum+=x;
    }
    printf("%lld\n",sum);
    return 0;
}
