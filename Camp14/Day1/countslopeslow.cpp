#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAX 100

using namespace std;
typedef long double ld;
ld A[MAX];
ld B[MAX];
ld slope[MAX*MAX];
int cnt = 0;
int num;
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&num);
    int a,b;
    for(int x = 0;x<num;x++){
        scanf("%d%d",&a,&b);
        A[x] = a;
        B[x] = b;
    }
    for(int x = 0;x<num;x++){
        for(int y = x+1;y<num;y++){
            slope[cnt++] = (B[y]-B[x])/(A[y]-A[x]);
        }
    }
    sort(slope,slope+cnt);
    cout << slope[0] << endl;
}
