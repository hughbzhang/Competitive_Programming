#include <cstdio>
#include <iostream>
#include <vector>

#define MAX 300100
#define NUMPRIME 26010 

using namespace std;


int Q,N = 0;
char in[3];

bool sieve[MAX];
vector<int> primes;
int list[MAX];
int sub[NUMPRIME][MAX];
int BOT,TOP,DIV;


int main(){
    sieve[0] = true;
    sieve[1] = true;
    int prime = 2;
    int oldprime = 2;
    while(prime<MAX){
        primes.push_back(prime);
        for(int x = 2*prime;x<MAX;x+=prime){
            sieve[x] = true;
        }
        oldprime = prime;
        prime = MAX;
        for(int x = oldprime+1;x<MAX;x++){
            if(!sieve[x]){
                prime = x;
                break;
            }
        }
    }
    scanf("%d",&Q);
    for(int q = 0;q<Q;q++){
        scanf("%s",in);
        if(in[1]=='D'){
            scanf("%d",&list[N]);
            N++;
            for(int x = 0;x<NUMPRIME;x++){
                sub[x][N] = sub[x][N-1] + (list[N]%prime[x])==0;
            }
        }
        else{
            scanf("%d%d%d",&BOT,&TOP,&DIV);

        }
    }
    cout << primes.size() << endl;
}


    
