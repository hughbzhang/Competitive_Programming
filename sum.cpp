#include <cstdio>
#include <vector>
#define MAX 30000

using namespace std;

bool sieve[MAX];
vector<int> prime;
int abun[MAX];
int cnt = 0;
bool sum[MAX];

void init(){
    //false is prime
    //true is composite
    sieve[0] = true;
    sieve[1] = true;
    int cur = 2;
    bool quit = false;
    while(!quit){
        quit = true;
        for(int x = 2*cur;x<MAX;x+=cur){
            sieve[x] = true;
        }
        for(int x = cur+1;x<MAX;x++){
            if(!sieve[x]){
                cur = x;
                quit = false;
                break;
            }
        }
    }
    for(int x = 2;x<MAX;x++){
        if(!sieve[x]) prime.push_back(x);
    }

        
}
void check(int cur){
    vector<int>::iterator begin = prime.begin();
    vector<int>::iterator end = prime.end();
    int sum = 0;
    for(int x = 1;x<cur;x++){
        if(cur%x==0) sum+=x;
    } 
    if(sum>cur){
        abun[cnt] = cur;
        cnt++;
    }
}


int main(){
    init();
    /*vector<int>::iterator begin = prime.begin();
    vector<int>::iterator end = prime.end();
    while(begin!=end){
        printf("%d\n",*begin);
        ++begin;

    }*/
    for(int x = 12;x<MAX;x++){check(x);}
    for(int x = 0;x<cnt;x++){
        for(int y = x;y<cnt;y++){
            if(abun[x]+abun[y]>MAX) continue;
            sum[abun[x]+abun[y]] = true;
        }
    } 
    long long ans = 0;
    for(int x = 0;x<MAX;x++){
        //printf("%d\n",abun[x]);
//        if(sum[x]) printf("%d\n",x);
        if(!sum[x]) ans+=x; 
    }
    printf("%lld\n",ans);



    return 0;
}
