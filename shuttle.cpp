/*
ID:bigfish2
LANG:C++
TASK:shuttle
*/

#include <cstdio>
#include <iostream>
#define MAX 1000000

using namespace std;

int num;
int cnt = 0;
int sol[MAX];

void p(int ans){
    sol[cnt] = ans;
    cnt++;
}
void print(){
    for(int x = 0;x<cnt-1;x++){
        if(x%20==19) cout << sol[x] << "\n";
        else cout << sol[x] << " ";
    }
    cout << sol[cnt-1] << "\n";
}


int main(){
    freopen("shuttle.in","r",stdin);
    freopen("shuttle.out","w",stdout);
    scanf("%d",&num);
    bool color = false;//false = black true = white
    int cur = num;
    bool start= true;
    for(int x = 2;x<=num+1;x++){
        p(cur);
        for(int a = 1;a<x;a++){
            if(color) cur-=2;//if W go down two
            else cur+=2;
            p(cur);
        }
        if(color) cur--;
        else cur++;
        color = !color;//flip color
    }
    color = !color;
    if(color) cur+=2;
    else cur-=2;

    for(int x = num;x>0;x--){
        p(cur);
        for(int a = 1;a<x;a++){
            if(color) cur+=2;//if W go down two
            else cur-=2;
            p(cur);
        }
        if(color) cur--;
        else cur++;
        color = !color;//flip color
    }
    print();
    return 0;
}
