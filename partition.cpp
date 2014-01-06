#include <cstdio>
#include <algorithm>
#define LARGE 999999

using namespace std;

int num,fences;
int field[16][16];
int dp[16][30];
bool perm[15];
int cum[16][30];

int find(int spot,int left,int length){
    if(spot==0) return 0;
    if(left<0||spot<0) return LARGE;
    if(dp[spot][left]!=-1) return dp[spot][left];
    int min = LARGE;
    for(int x = 0;x<spot;x++){
            int pos = find(x,left-1,length);
            for(int y = 0;y<length;y++){
                if(cum[spot][y]-cum[x][y]>pos) pos = cum[spot][y]-cum[x][y];
            }
            //if(pos==0) printf("%d %d\n",spot,left);
    //        printf("%d\n",pos);
            if(pos<min) min = pos;
        }
    return dp[spot][left] = min;
}
void clear(){
    for(int y = 0;y<16;y++){
        for(int x = 0;x<30;x++){
            dp[y][x] = -1;
            cum[y][x] = 0;
        }
    }
    for(int x = 0;x<30;x++) dp[0][x] = 0;
}

void print(){
    for(int y = 0;y<4;y++){
        for(int x = 0;x<3;x++) printf("%d ",dp[y][x]);
        printf("\n");
    }
    printf("\n");
    
    for(int y = 0;y<4;y++){
        for(int x = 0;x<3;x++) printf("%d ",cum[y][x]);
        printf("\n");
    }
    printf("\n");
}

int main(){
    freopen("partition.in","r",stdin);
    freopen("partition.out","w",stdout);
    scanf("%d%d",&num,&fences);
    for(int y = 0;y<num;y++){
        for(int x = 0;x<num;x++){
            scanf("%d",&field[y][x]);
        }
    }
    /*for(int y = 0;y<num;y++){
        for(int x = 0;x<num;x++){
            printf("%d ",field[y][x]);

        }
        printf("\n");
    }*/
    int min = LARGE;
    for(int x = 0;x<=fences;x++){
        //num to use for vertical
        for(int y = num-2;y>=0;y--){
            if(y>=num-1-x) perm[y] = true;
            else perm[y] = false;
        }

       
        do{
            clear();
            for(int length = 1;length<=num;length++){
                int cnt = 0;
                cum[length][0]+=field[length-1][0];
                for(int width = 0;width<num-1;width++){
                    if(perm[width]) cnt++;
                    cum[length][cnt]+=field[length-1][width+1];
                }
                for(int a = 0;a<=cnt;a++){
                    cum[length][a]+=cum[length-1][a];
                }
            }
            int pos = find(num,fences-x,x+1);
            if(pos<min) min = pos;
            //printf("%d\n",pos);
            //for(int a = 0;a<num-1;a++) printf("%d ",perm[a]);
            //printf("\n");
            //print();

        }while(next_permutation(perm,perm+num-1));
    }
    printf("%d\n",min);


    return 0;
}
