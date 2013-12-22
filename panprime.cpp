#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX 500000000


using namespace std;

bool sieve[MAX];//index x corresponds to 2*x+1 Even numbers are nonexistent
int perm[] = {9,8,7,6,5,4,3,2,1};
int buff[] = {100000000,10000000,1000000,100000,10000,1000,100,10,1};
int start = 0;

bool find(){
    int sum = 0;
    
    for(int x = start;x<10;x++){
       sum+=buff[x]*perm[x]; 
    }
    if(sum==2143) printf("HERE");
    if(sum%2==0) return false;
    else if(sieve[(sum-1)/2]) return false;
    //PRIME
    printf("%d\n",sum);
    return true;

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
    for(int x = 0;x<9;x++){
        start = x;
        do{
            if(find()) return 0; 
        } 
        while(prev_permutation(perm+x,perm+9));
    }






    return 0;
}
