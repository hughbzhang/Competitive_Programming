#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool boy[110];
bool girl[110];
int N,M,b,g,temp;

int prm(int a, int b){
    if(a<b){
        temp = a;
        a = b;
        b = temp;
    }
    if(b==0) return a;
    return prm(b,a%b);
}
       

int main(){
    ios::sync_with_stdio(0);
    cin >> N >> M;
    cin >> b;
    for(int x = 0;x<b;x++){
        cin >> temp;
        boy[temp] = true;
    }
    cin >> g;
    for(int x = 0;x<g;x++){
        cin >> temp;
        girl[temp] = true;
    }
    if(prm(N,M)==1){
        cout << "Yes\n";
        return 0;
    }
    int m = N*M/prm(N,M);
    bool flag = true;
    while(flag){
        flag = false;
        for(int x = 0;x<m;x++){
            if(boy[x%N]^girl[x%M]){
                boy[x%N] = true;
                girl[x%M] = true;
                flag = true;
            }
        }
    }
    for(int x = 0;x<N;x++){
        if(!boy[x]){
            cout << "No\n";
            return 0;
        }
    }
    for(int x = 0;x<M;x++){
        if(!girl[x]){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}

