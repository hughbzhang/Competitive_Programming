#include <cstdio>
#include <iostream>
#include <cstring>

#define LARGE 100

using namespace std;

int arr[9];
int dp[9][1<<9][1<<3];//row col square
int num[1<<9];//num of things highlighted
int thr[1<<9];//thr number corresponded with that col score
int temp[3];



int main(){
    freopen("bsudoku.in","r",stdin);
    freopen("bsudoku.out","w",stdout);
    string in;
    for(int y = 0;y<9;y++){
        cin >> in;
        for(int x = 0;x<9;x++){
            if(in.at(x)=='1') arr[y]+=(1<<x);
        }
    }
    for(int y = 0;y<9;y++){
        for(int x = 0;x<(1<<9);x++){
            for(int z = 0;z<(1<<3);z++){
                dp[y][x][z] = LARGE;
            }
        }
    }
    for(int x = 0;x<(1<<9);x++){
        temp[0] = 0;
        temp[1] = 0;
        temp[2] = 0;
        for(int a = 0;a<9;a++){
            if((1<<a)&x){
                num[x]++;
                temp[a/3]++;
            }
        }
        for(int a = 0;a<3;a++){
            temp[a]%=2;
            if(temp[a]) thr[x]+=(1<<a);
        }
    }
    for(int x = 0;x<(1<<9);x++){
        dp[0][x][thr[x]] = num[x^arr[0]];
    }

    for(int y = 1;y<9;y++){//current row
        for(int x = 0;x<(1<<9);x++){//current col state
            for(int a = 0;a<(1<<3);a++){//current box state
                if((y%3)==2&&a!=0) continue;
                for(int now = 0;now<(1<<9);now++){//current row state

                    if(num[now]%2!=0) continue;
                    //printf("%d %d %d\n",now^arr[y],x^now,a^thr[now]);
                    /*if(dp[y][x][a]>num[now^arr[y]]+dp[y-1][x^now][a^thr[now]]){
                        if(x==0&&a==0){
                            printf("%d %d %d %d\n",y,dp[y][0][0],num[now^arr[y]],dp[y-1][x^now][a^thr[now]]);
                            
                        }
                    }*/

                    dp[y][x][a] = min(dp[y][x][a],num[now^arr[y]]+dp[y-1][x^now][a^thr[now]]);
                }
            }
        }
    }
    /*for(int y = 0;y<20;y++){
        for(int a = 0;a<9;a++){
            if((1<<a)&y) printf("1");
            else printf("0");
        }
        printf("\n");
        for(int a = 0;a<3;a++){
            //if((1<<a)&thr[y]) printf("1");
            //else printf("0");
        }
        printf("%d\n",num[y]);
        printf("\n\n");
        
    }
    for(int x = 0;x<30;x++){
        printf("%d\n",dp[1][x][0]);
    }*/
    for(int x = 0;x<9;x++){
        
        //printf("%d\n",dp[x][0][0]); 
    }
    printf("%d\n",dp[8][0][0]);

    return 0;
}
