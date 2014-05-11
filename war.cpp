#include <cstdio>
#include <iostream>
#include <algorithm>


using namespace std;
typedef long double ld;

int num;
int deck;
ld me[1050];
ld you[1050];

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin >> num;
    for(int a = 1;a<=num;a++){
        int cheat = 0;
        int fair = 0;
        cin >> deck;
        for(int x = 0;x<deck;x++) cin >> me[x];
        for(int x = 0;x<deck;x++) cin >> you[x];
        sort(me,me+deck);
        sort(you,you+deck);
        int rec = 0;
        for(int x = 0;x<deck;x++){
            while(rec<deck&&you[rec]<me[x]){
                fair++;
                rec++;
            }
            rec++;
        }
        for(int buffer = 0;buffer<deck;buffer++){
            bool flag = true;
            for(int x = buffer;x<deck;x++){
                if(you[x-buffer]>me[x]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cheat = deck-buffer;
                break;
            }
        }
        printf("Case #%d: %d %d\n",a,cheat,fair);
    }

}
