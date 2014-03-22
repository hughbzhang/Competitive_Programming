#include <cstdio>
#include <iostream>
#define MAX 10010

using namespace std;

int shelves, total;

int arr[MAX];
int dp[110][MAX];
int best[MAX];
int front[MAX];
int back[MAX];
int ans[MAX];

int main(){
    cin >> shelves >> total;
    int num;
    for(int x = 0;x<shelves;x++){
        cin >> num;
        for(int x = 0;x<num;x++) cin >> arr[x];
        for(int x = 1;x<=num;x++){
            front[x] = arr[x-1]+front[x-1];
            back[x] = arr[num-x]+back[x-1];
        }
        for(int x = 1;x<=total;x++){
            if(x>num) break;
            best[x] = 0;
            for(int a = 0;a<=x;a++){
                if(front[a]+back[x-a]>best[x]) best[x] = front[a]+back[x-a];
            }
        }
        for(int x = total;x>0;x--){
            for(int a = x-1;a>=0;a--){
                if(x-a>num) break;
                if(ans[a]+best[x-a]>ans[x]) ans[x] = ans[a]+best[x-a];
            }
        }
        for(int x = 0;x<=total;x++){
//            cout << ans[x] << endl;
        }
    }
    cout << ans[total] << endl; 


    return 0;
}
