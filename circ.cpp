#include <cstdio>
#include <cmath>
#define MAX 499999


using namespace std;

bool sieve[MAX];//index x corresponds to 2*x+1 Even numbers are nonexistent
int cnt = 0;

int pow(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    
    int half = pow(a,b/2);
    if(b%2==0) return half*half;
    else return half*half*a;
}

void check(int origin){
    //printf("%d\n",origin);
    int length = log10(origin);
    int buff = pow(10,length);

    int start = origin;
    int temp = start%10;
    start/=10;
    start+=buff*temp;
    while(start!=origin){
        //printf("%d\n",start);
        if(start%2==0&&start!=2) return;
        if(sieve[(start-1)/2]) return;//if composite return
        //operate again
        temp = start%10;
        start/=10;
        start+=buff*temp;
    }
    cnt++;
    printf("%d\n",origin);
    //ITS A CIRCULAR PRIME
}


int main(){
    
    int stop = sqrt(MAX);

    for(int x = 1;x<stop;x++){
        if(sieve[x]==false){//we are prime
            int square = 2*x*(x+1);//(2x+1)^2 => 4x^2+4x+1 => 2[2*x*(x+1)]+1
            int val = 2*x+1;
            for(int a = square;a<MAX;a+=val){
                sieve[a] = true;//we are composite
            }
        }
    }
    for(int x = 1;x<MAX;x++){
        if(sieve[x]==false) check(2*x+1);
    }
    cnt++;//DONT FORGET ABOUT 2
    printf("%d\n",cnt);
    return 0;
}
