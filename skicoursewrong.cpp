#include <cstdio>
#include <iostream>
#include <string>



//procedure
//
/*
 * If a row or column has a max length sequence of 3, a block of length three can fill it
 *
 * Algorithm is:
 *
 * for each row and column, find the max length sequence
 * Also find the largest square in the thingy. NOT SURE IF THIS IS IMPLICIT BUT LETS JUST BE SAFE
 *
 * Answer is minimum of all of these
 *
 *
*/

int M, N;
bool arr[150][150];
int ans = 100;
int square[150][150];

using namespace std;

void print(){
    for(int y = 0;y<M;y++){
        for(int x = 0;x<N;x++){
            cout << square[y][x] <<  " ";
        }
        cout << "\n";
    }
}
int min(int a,int b){
    if(a<=b) return a;
    else return b;
}
int min(int a,int b,int c){
    return min(min(a,b),c);
}

int main(){
    ios::sync_with_stdio(false);
    freopen("skicourse.in","r",stdin);
    freopen("skicourse.out","w",stdout);
    cin >> M >> N;
    string in;
    for(int x = 0;x<M;x++){
        cin >> in;
        for(int a = 0;a<N;a++){
            if(in.at(a)=='R') arr[x][a] = 0;
            else arr[x][a] = 1;
        }
    }
    for(int y = 0;y<M;y++){
        bool cur  = arr[y][0];
        int cnt = 1;
        int rec = 1;
        for(int x = 1;x<N;x++){
            if(cur==arr[y][x]) cnt++;
            else{
                if(cnt>rec) rec = cnt;
                cnt = 1;
                cur = arr[y][x];
            }
        }
        if(cnt>rec) rec = cnt;
        if(rec<ans) ans = rec;
    }

    for(int x = 0;x<N;x++){
        bool cur  = arr[0][x];
        int cnt = 1;
        int rec = 1;
        for(int y = 1;y<M;y++){
            if(cur==arr[y][x]) cnt++;
            else{
                if(cnt>rec) rec = cnt;
                cnt = 1;
                cur = arr[y][x];
            }
        }
        if(cnt>rec) rec = cnt;
        if(rec<ans) ans = rec;
    }
    for(int x = 0;x<N;x++) square[0][x] = 1;
    for(int y = 0;y<M;y++) square[y][0] = 1;
    int best = 1;
    for(int y = 1;y<M;y++){
        for(int x = 1;x<N;x++){
            if(arr[y][x]==arr[y][x-1]&&arr[y][x]==arr[y-1][x]&&arr[y][x]==arr[y-1][x-1]){
                square[y][x] = min(square[y][x-1],square[y-1][x],square[y-1][x-1])+1;
            }
            else square[y][x] = 1;
            if(square[y][x]>best) best = square[y][x];
        }
    }
    if(best<ans) ans = best;
    cout << ans << "\n";
}
