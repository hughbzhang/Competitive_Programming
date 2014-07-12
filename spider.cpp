#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int N,M,K;
string in;
int cnt[2010];

int main(){
    cin >> N >> M >> K;
    for(int y = 0;y<N;y++){
        cin >> in;
        for(int x = 0;x<M;x++){
            if(in.at(x)=='.'||in.at(x)=='D') continue;
            if(in.at(x)=='R'&&x+y<M) cnt[y+x]++;
            if(in.at(x)=='L'&&x-y>=0) cnt[x-y]++;
            if(in.at(x)=='U'&&y%2==0) cnt[x]++;
        }
    }
    for(int x = 0;x<M;x++) cout << cnt[x] << " ";
    cout << endl;
}
