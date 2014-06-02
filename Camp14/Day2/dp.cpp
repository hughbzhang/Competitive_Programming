#include <cstdio>
#include <vector>
#include <iostream>
#define MAX 255

using namespace std;
typedef long long ll;

ll dp[MAX][MAX][5];//curnode + e used
ll ans = 0;
char letter[MAX];
vector<int> child[MAX];
int N,M;
string target = "bessi";
int main(){
    freopen("find.in","r",stdin);
    freopen("find.out","w",stdout);
    cin >> N >> M;
    for(int x = 1;x<=N;x++){
         cin >> letter[x];
         if(letter[x]=='b') dp[x][0][0]++;
    }
    int a,b;
    for(int x = 1;x<=M;x++){
        cin >> a >> b;
        child[a].push_back(b);
        child[b].push_back(a);
    }
    for(int x = 1;x<=N;x++){
        if(letter[x]!='e') continue;
        for(int a = 0;a<child[x].size();a++){
            if(letter[child[x][a]]=='b') dp[x][x][1]++;
        }
    }
    
    for(int x = 2;x<5;x++){
        for(int a = 1;a<=N;a++){
            if(letter[a]!=target.at(x)) continue;
            for(int b = 0;b<child[a].size();b++){
                 if(letter[child[a][b]]==target.at(x-1)){
                    for(int c = 1;c<=N;c++){
                        dp[a][c][x] += dp[child[a][b]][c][x-1];
                    }
                 }
            }
        }
    }
    for(int a = 1;a<=N;a++){
        if(letter[a]!='e') continue;
        for(int b = 0;b<child[a].size();b++){
            if(letter[child[a][b]]=='i'){
                for(int c = 0;c<=N;c++){
                    if(c==a) continue;
                    ans+=dp[child[a][b]][c][4];
                }
            }
        }
    }
    for(int x = 1;x<=N;x++){
//        cout << dp[x][x][1] << endl;
    }
    cout << ans << endl;


    return 0;
}
