#include <cstdio>
#define MAX 21
#define LARGE 1e10
#define SIZE 200


using namespace std;
typedef long long ll;

ll mat[MAX][SIZE][SIZE];
bool used[SIZE];
//mat[0] corresponds to 2^0
ll done[MAX][SIZE][SIZE];
int map[SIZE];//map[x] produces a number from 0 to 100
int m[1001];
int number = 0;

int num,trails,start,end;

void init(){
    for(int a = 0;a<MAX;a++){
        for(int x = 0;x<SIZE;x++){
            for(int y = 0;y<SIZE;y++){
                mat[a][x][y] = LARGE;
                done[a][x][y] = LARGE;
            }
        }
    }
    for(int x = 0;x<SIZE;x++){
            done[0][x][x] = 0;
    }
    for(int x = 0;x<1001;x++) m[x] = -1;
    for(int x = 0;x<SIZE;x++){
        map[x] = -1;
    }
}


int main(){
    freopen("relays.in","r",stdin);
    freopen("relays.out","w",stdout);
    init();
    scanf("%d%d%d%d",&num,&trails,&start,&end);
    for(int x = 0;x<trails;x++){
        
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(!used[b]){
            map[number] = b;
            m[b] = number;
            ++number;
        }
        if(!used[c]){
            map[number] = c;
            m[c] = number;
            ++number;
        }
        used[b] = true;
        used[c] = true;
        mat[0][m[b]][m[c]] = a;
        mat[0][m[c]][m[b]] = a;
    }

    for(int x = 1;x<21;x++){
        for(int a = 0;a<number;a++){
            for(int b = 0;b<number;b++){
                for(int c = 0;c<number;c++){
                    //a is mid vertex
                    if(mat[x][b][c]>mat[x-1][b][a]+mat[x-1][a][c]) mat[x][b][c] = mat[x-1][b][a]+mat[x-1][a][c]; 
                }
            }
        }
    }
    int cnt = 0;
    for(int x = 0;x<MAX;x++){
        if(num&(1<<x)){
            cnt++;
            for(int a = 0;a<number;a++){
                for(int b = 0;b<number;b++){
                    for(int c = 0;c<number;c++){
                        //a is mid vertex
                        if(done[cnt][b][c]>mat[x][b][a]+done[cnt-1][a][c]) done[cnt][b][c] = mat[x][b][a]+done[cnt-1][a][c]; 
                    }
                }
            }   
        }
    }
//    printf("%lld\n",mat[1][m[start]][m[end]]);
    printf("%lld\n",done[cnt][m[start]][m[end]]);
}
