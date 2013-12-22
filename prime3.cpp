/*
ID:bigfish2
LANG:C++
TASK:prime3
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#define MAX 100000

using namespace std;
typedef vector<int> vi;
typedef vi::iterator it;

int small[] = {5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};

vi primes;
vi m[11][11][11][11][11];//10 is wild card
int dig[5],temp[5];
string ANS[1000];
int cnt = 0;
int f[5][5];//field
int sum,begin;
bool valid[MAX];

void isPrime(int in){
    for(int x = 0;x<63;x++){
        if(in%small[x]==0) return;
    }
    primes.push_back(in);
}

void init(){
    for(int x = 1667;x<16667;x++){
        isPrime(6*x-1);
        isPrime(6*x+1);
    }
}
void filter(int origin){
    int total = 0;
    int num = origin;
    for(int x = 4;x>=0;x--){
        dig[x] = num%10;
        total+=dig[x];
        num/=10;
    }
    if(total!=sum) return;
    valid[origin] = true;
    for(int x = 0;x<32;x++){
        for(int a = 0;a<5;a++){
            if(x&(1<<a)) temp[a] = dig[a];
            else temp[a] = 10;
        }
//        printf("%d %d %d %d %d ANS: %d\n",temp[0],temp[1],temp[2],temp[3],temp[4],origin);
        m[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]].push_back(origin);
    }

}
void row(int index, int num){
    for(int x = 4;x>=0;x--){
        f[index][x] = num%10;
        num/=10;
    }        
}
void col(int index, int num){
    for(int y = 4;y>=0;y--){
        f[y][index] = num%10;
        num/=10;
    }
}
void down(int num){//the down diagnonal
    for(int a = 4;a>=0;a--){
        f[a][a] = num%10;
        num/=10;
    }
}
void up(int num){//up diagonal
    for(int a = 0;a<5;a++){
        f[a][4-a] = num%10;
        num/=10;
    }
}
void print(string p){
    for(int y = 0;y<25;y++){
        if(y%5==0&&y!=0) printf("\n");
        printf("%c",p.at(y));
    }
    printf("\n");
}
void answer(){
    string next = "";
    for(int y = 0;y<5;y++){
        for(int x = 0;x<5;x++){
            next.push_back((char)(f[y][x]+'0'));
        }
    }
    ANS[cnt] = next;
    cnt++;
}

void check(){
    int one = 0, two = 0;
    for(int y = 0;y<5;y++){
        one+=f[y][0];
        two+=f[y][4];
        one*=10;
        two*=10;
    }
    one/=10;
    two/=10;
    if(valid[one]&&valid[two]){
        answer();
    }
}

    


int main(){
    freopen("prime3.in","r",stdin);
    freopen("prime3.out","w",stdout);
    scanf("%d%d",&sum,&begin);
    init();
    for(it i = primes.begin();i!=primes.end();++i){
        filter(*i);
    }
    /*int a,b,c,d,e;
    while(true){
        
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        if(a==0) return 0;
        int t = m[a][b][c][d][e].size();
        printf("%d\n",t);
    }*/


    f[0][0] = begin;
    for(it a = m[begin][10][10][10][10].begin();a!=m[begin][10][10][10][10].end();++a){
        down(*a);
        for(it b = m[10][10][(f[2][2])][10][10].begin();b!=m[10][10][(f[2][2])][10][10].end();++b){//CAN BE OPTIMIZED BY 2
            up(*b);
            for(it c = m[begin][10][10][10][(f[0][4])].begin();c!=m[begin][10][10][10][(f[0][4])].end();++c){
                row(0,*c);
                for(it d = m[(f[0][1])][(f[1][1])][10][(f[3][1])][10].begin();d!=m[(f[0][1])][(f[1][1])][10][(f[3][1])][10].end();++d){
                    col(1,*d);
                    for(it e = m[(f[0][3])][(f[1][3])][10][(f[3][3])][10].begin();e!=m[(f[0][3])][(f[1][3])][10][(f[3][3])][10].end();++e){
                        col(3,*e);
                        for(it k = m[(f[4][0])][(f[4][1])][10][(f[4][3])][(f[4][4])].begin();k!=m[(f[4][0])][(f[4][1])][10][(f[4][3])][(f[4][4])].end();++k){
                            row(4,*k);
                            for(it g = m[(f[0][2])][10][(f[2][2])][10][(f[4][2])].begin();g< m[(f[0][2])][10][(f[2][2])][10][(f[4][2])].end();++g){
                                col(2,*g);
                                for(it h = m[10][(f[1][1])][(f[1][2])][(f[1][3])][10].begin();h<m[10][(f[1][1])][(f[1][2])][(f[1][3])][10].end();++h){
                                    row(1,*h);
                                    for(it i = m[10][(f[2][1])][(f[2][2])][(f[2][3])][10].begin();i< m[10][(f[2][1])][(f[2][2])][(f[2][3])][10].end();++i){
                                        row(2,*i);
                                        for(it j = m[10][(f[3][1])][(f[3][2])][(f[3][3])][10].begin();j<m[10][(f[3][1])][(f[3][2])][(f[3][3])][10].end();++j){
                                            row(3,*j);
                                            check();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } 
    if(!cnt){
        printf("NONE\n");
        return 0;
    }
    sort(ANS,ANS+cnt);
    print(ANS[0]);
    for(int x = 1;x<cnt;x++){
        printf("\n");
        print(ANS[x]);
    }


    return 0;
}
