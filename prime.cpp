#include <cstdio>
#include <cmath>
#define MAX 220


using namespace std;

bool sieve[MAX];
bool val[MAX];//false = 0 true = 1 NUMBER OF TIMES CONTAINED MOD 2
bool test[MAX];
int in;

void factor(int origin){
    int input = origin;
    int start = 2;
    while(start<=input){
        while(input%start==0){
            input/=start;
            val[start] = !val[start];
        }
        do {start++;}
        while(sieve[start]);
    }
    if(input!=1) printf("%d ERROR\n",origin); 
}
void fill(int origin){
    int input = origin;
    int start = 2;
    while(start<=input){
        while(input%start==0){
            input/=start;
            test[start] = !test[start];
        }
        do {start++;}
        while(sieve[start]);
    }
    if(input!=1) printf("%d ERROR\n",origin); 

}
void print(){
    for(int x = 2;x<MAX;x++){
        if(!sieve[x]){
            printf("PRIME:%d NUMBER:%d\n",x,val[x]);
            
        }
    }
}
void compare(int value){
    for(int x = 0;x<MAX;x++){
        if(val[x]!=test[x]) return;
    }
    printf("%d\n",value);
}

int main(){
    
    int stop = sqrt(MAX);
    sieve[0] = true;
    sieve[1] = true;
    for(int x = 2;x<stop;x++){
        if(sieve[x]==false){//we are prime
            for(int a = x*x;a<MAX;a+=x){
                sieve[a] = true;//we are composite
            }
        }
    }
    for(int x = 2;x<=200;x+=2){
        factor(x);
    } 
    print();
    for(int x = 2;x<=96;x++) fill(x);
    for(int x = 97;x<211;x++){
        fill(x);
        compare(x);
    }
    /*while(true){
        
        scanf("%d",&in);
        if(in==-1) break;
        factor(in);
        print(); 
    }*/
    


    return 0;
}
