/*
ID: bigfish2
LANG:C++
TASK:combo
*/


#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int N;
int cnt = 0;
int far[3];
int mas[3];

int dist(int a, int b){
    return min(abs(b-a),abs(min(a,b)-max(a,b)+N));
}

bool val(int a, int b, int c){
    if(dist(far[0],a)>2||dist(far[1],b)>2||dist(far[2],c)>2){
        if(dist(mas[0],a)>2||dist(mas[1],b)>2||dist(mas[2],c)>2){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    cin >> N;
    cin >> far[0] >> far[1] >> far[2];
    cin >> mas[0] >> mas[1] >> mas[2];

    for(int a = 1;a<=N;a++){
        for(int b = 1;b<=N;b++){
            for(int c = 1;c<=N;c++){
                if(val(a,b,c)) cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
