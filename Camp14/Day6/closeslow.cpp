#include <cstdio>
#include <iostream>
#include <cmath>

#define MAX 20000

using namespace std;
typedef long double ld;

int num;
ld best = 1000000000000;
ld X[MAX];
ld Y[MAX];

inline ld dist(int x, int y){
    return sqrt(pow(X[x]-X[y],2)+pow(Y[x]-Y[y],2));
}

int main(){
    freopen("in.txt","r",stdin);
    cin >> num;
    for(int x = 0;x<num;x++){
        cin >> X[x] >> Y[x]; 
    }
    for(int x = 0;x<num;x++){
        for(int y = x+1;y<num;y++){
            if(dist(x,y)<best) best = dist(x,y);
        }
    }
    cout << best << endl;


    return 0;
}
