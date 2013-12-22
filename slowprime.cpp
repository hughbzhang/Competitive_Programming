#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 100000
using namespace std;
typedef vector<int> vi;
typedef vi::iterator it;

bool sieve[MAX];
vi start;
int sum[10][1000];//first number is sum
//second number is leading digit
int field[25];
int cnt[10];//indcies for the sum matrix
int ADD[MAX];//sums of digits of each number
int begin,SUM;

int cumsum[6];//cumsums of the columns 1-4
//4 and 5 are the diagonals
int add(int x){
    int total = 0;
    while(x>0){
        total+=(x%10);
        x/=10;
    }
    return total;
}

void init(){
    for(int x = 1;x<MAX;x++){
        ADD[x] = add(x);
    }
    sieve[0] = true;
    sieve[1] = true;
    int cur = 2;
    bool flag = true;
    while(flag){
        flag = false;
        for(int x = 2*cur;x<MAX;x+=cur){
            sieve[x] = true;
        }
        for(int x = cur+1;x<MAX;x++){
            if(!sieve[x]){
                cur = x;
                flag = true;
                break;
            }
        }
    }
}



bool check(){
    int total = 0,sum = 0;
    total = field[24]+10*field[18]+100*field[12]+1000*field[6]+10000*field[0];
    sum = field[4]+10*field[8]+100*field[12]+1000*field[16]+10000*field[20];
    if(field[24]+field[18]+field[12]+field[6]+field[0]!=SUM) return false;
    if(field[4]+field[8]+field[12]+field[16]+field[20]!=SUM) return false;
    if(sieve[total]||sieve[sum]) return false;
    
    
    for(int x = 1;x<5;x++){
        total = 0;
        sum = 0;
        for(int y = 0;y<5;y++){
            total+=field[5*y+x];
            total*=10;
            sum+=field[5*y+x];
        }
        total/=10;
        if(sieve[total]||sum!=SUM) return false;
    }
    
    return true;
}



void row(int a, int add){
    
    for(int x = 4;x>=0;x--){
        field[5*a+x] = add%10;
        add/=10;
        if(x!=0) cumsum[x-1]+=field[5*a+x];
    }
    cumsum[4] += field[5*a+a];
    cumsum[5] += field[4*a+4];
    
}
void rem(int a){
    for(int x = 0;x<4;x++){
        cumsum[x]-=field[5*a+x+1];
    }
    cumsum[4]-=field[5*a+a];
    cumsum[5]-=field[4*a+4];
}
    
bool greater(){
    for(int x = 0;x<6;x++){
        if(cumsum[x]>SUM) return true;
    }
    return false;
}

void col(int a, int add){
    for(int x = 4;x>=0;x--){
        field[5*x+a] = add%10;
        add/=10;
    }
}
void print(){
    for(int y = 0;y<5;y++){
        for(int x = 0;x<5;x++){
            printf("%d",field[5*y+x]);
        }
        printf("\n");
    }
    printf("\n");
}
bool zero(int x){
    while(x>0){
        if(x%10==0) return false;
        x/=10;
    }
    return true;
}


int main(){
    scanf("%d%d",&begin,&SUM);
    init();
    for(int x = 10000; x<MAX;x++){
        if(!sieve[x]&&ADD[x]==SUM){
            int f = x/10000;
            sum[f][cnt[f]] = x;
            cnt[f]++;
        }
    }
    for(int x = begin*10000;x<(begin+1)*10000;x++){
        if(!sieve[x]&&ADD[x]==SUM&&zero(x)){
            start.push_back(x);
        }
    }
    for(int x = 0;x<MAX;x++){
        if(!sieve[x]&&ADD[x]!=SUM){
            sieve[x] = true;
        }
    }
    printf("hi\n");
    for(it i = start.begin();i!=start.end();++i){
        
        row(0,*i);
        if(greater()){
            rem(0);
            continue;
        }
        for(it a = start.begin();a!=start.end();++a){
            col(0,*a);
            int one = field[5];
            int two = field[10];
            int thr = field[15];
            int fou = field[20];
            for(int b = 0;b<cnt[one];++b){
                row(1,sum[one][b]);
                if(greater()){
                    rem(1);
                    continue;
                }
                for(int c = 0;c<cnt[two];c++){
                    row(2,sum[two][c]);
                    if(greater()){
                        rem(2);
                        continue;
                    }
                    for(int d = 0;d<cnt[thr];d++){
                        row(3,sum[thr][d]);
                        if(greater()){
                            rem(3);
                            continue;
                        }
                        for(int e = 0;e<cnt[fou];e++){
                            row(4,sum[fou][e]);
                            if(greater()){
                                rem(4);
                                continue;
                            }
                            if(check()) print();
                            rem(4);
                        }
                        rem(3);
                    }
                    rem(2);
                }
                rem(1);
            }
        }
        rem(0);
    }    
    

    return 0;
}
