#include <cstdio>
#include <iostream>

using namespace std;

int rev[100100];
int t[100100];
int fw[100100];
int done[100100];

int ind = -1;
int skip = 0;
int pre = 0;
int N,M,Q;
int temp;

int main(){
    freopen("shufflegold.in","r",stdin);
    
    cin >> N >> M >> Q;
    for(int x = 0;x<100100;x++) done[x] = -1;
    for(int x = 0;x<M;x++){
        cin >> temp;
        temp--;
        rev[temp] = x;
        fw[x] = temp;
    }
    done[0] = rev[0];
    bool cycle = false;
    int loop = 0;
    while(true){
        loop++;
        if(t[loop]!=0){
            cycle = true;
            pre = t[cur];
            skip = loop-t[cur];
            break;
            //CYCLE

        }
        t[cur] = loop;
        if(cur>=M) cout << "WRONG" << endl;
        if(cur==M-1){
            cycle = false;
            skip = loop;
            break; //WE ARE DONE NO CYCLE
        }
        else{
            done[cur] = rev[cur+1];
            cur = done[cur];
        }
    }

}


