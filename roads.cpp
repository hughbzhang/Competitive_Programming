#include <cstdio>
#include <iostream>

#define MAX 303

using namespace std;
typedef long long ll;

int num,plan;

ll mat[MAX][MAX];


ll sum(){
    ll ans = 0;
    for(int y = 0;y<num;y++){
        for(int x = y+1;x<num;x++){
            ans+=mat[y][x];
        }
    }
    return ans;
}

int main(){
    cin >> num;
    for(int y = 0;y<num;y++){
        for(int x = 0;x<num;x++){
            cin >> mat[y][x];
        }
    }
    cin >> plan;
    int start,end,length;
    for(int x = 0;x<plan;x++){
        cin >> start >> end >> length;
        start--;
        end--;
        if(mat[start][end]<=length){
            cout << sum() << " ";
            continue;
        }
        mat[start][end] = length;
        mat[end][start] = length;
        for(int y = 0;y<num;y++){
            for(int x = 0;x<num;x++){
                ll pos = mat[y][start]+mat[start][end]+mat[end][x];
                if(pos<mat[y][x]){
                    mat[y][x] = pos;
                    mat[x][y] = pos;
                }
            }
        }
        cout << sum() << " ";
    }
    cout << endl;
}
