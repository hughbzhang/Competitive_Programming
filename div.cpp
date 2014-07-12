#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#define MAX 50010

using namespace std;

int p[2*MAX];
int out = 0;
bool vis[2*MAX];
vector<int> primes;
int N;
bool sieve[2*MAX];

bool check(int in){
    int ans = 1;
    for(int x = 0;x<primes.size();x++){
        /*if(primes[x]>ceil(sqrt((double)in))){
            if(!sieve[in]) ans*=2;
            break;
        }*/
        if(primes[x]>in) break;
        p[x]= 0;
        while(in%primes[x]==0){
            in/=primes[x];
            p[x]++;
        }
        ans*=(p[x]+1);
    }
    if(!vis[ans]){
        vis[ans] = true;
        return true;
    }
    else return false;
}

int main(){
    cin >> N;
    
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
    //cout << "LOL" << endl;
    primes.push_back(2);
    for(int x = 1;x<MAX;x++){
    	if(!sieve[x]) primes.push_back(2*x+1);
    }
    
    for(int x = 1;x<=N;x++){
        if(check(x)) out += x; 
    }
    cout << out << endl;


    return 0;
}
