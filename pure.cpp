#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int N;

int row[150];
int R[150];
int C[150];
int col[150];
string temp;

int main(){
    cin >> N;
    for(int x = 0;x<N;x++){
        cin >> temp;
        for(int a = 0;a<N;a++){
            if(temp.at(a)=='.'){
                row[x]++;
                col[a]++;
                if(R[x]==0) R[x] = a+1;
                if(C[a]==0) C[a] = x+1;
            }
        }
    }
    bool flag = true;
    for(int x = 0;x<N;x++){
        if(row[x]==0){
            flag = false;
            break;
        }
    }
    if(flag){
        for(int x = 0;x<N;x++){
            cout << x+1 << " " << R[x] << endl;
        }
        return 0;
    }
    flag = true;
    for(int x = 0;x<N;x++){
        if(col[x]==0){
            flag = false;
            break;
        }
    }
    if(flag){
        for(int x = 0;x<N;x++){
            cout << C[x] << " " << x+1 << endl;
        }
    }
    else cout << -1 << endl;

    return 0;
}
