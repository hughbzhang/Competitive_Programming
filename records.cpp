#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int num;

string dict[3000];
int cnt = 0;
int ind[3];
int sol[1000][1000][1000];
long long done = 0;
int main(){
    freopen("records.in","r",stdin);
    freopen("records.out","w",stdout);
    cin >> num;
    string temp;
    bool pass = true;
    for(int x = 0;x<num;x++){
        for(int a = 0;a<3;a++){
            pass = false;
            cin >> temp;
            for(int y = 0;y<cnt;y++){
                if(dict[y]==temp){
                    ind[a] = y;
                    pass = true;    
                }
            }
            if(!pass){
                ind[a] = cnt;
                dict[cnt] = temp;
                cnt++;
            }
        }          
        sort(ind,ind+3);
        sol[ind[0]][ind[1]][ind[2]]++;
        if(sol[ind[0]][ind[1]][ind[2]]>done) done = sol[ind[0]][ind[1]][ind[2]];

    }
    printf("%lld\n",done);

    return 0;
}
