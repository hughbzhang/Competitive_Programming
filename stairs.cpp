#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int num;
int arr[MAX];
int NEXT[MAX];
int cnt = 0;
int ans = 0;
int past = -1;
int seq[MAX];
int seqc = 0;

int main(){
    cin >> num;
    for(int x = 0;x<num;x++) cin >> arr[x];
    sort(arr,arr+num);
    seq[0] = arr[0];
    seqc++;
    past = arr[0];
    ans = 1;
    for(int a = 1;a<num;a++){
        if(arr[a]!=past){
            ans++;
            past = arr[a];
            seq[seqc] = past;
            seqc++;
        }
        else{
            NEXT[cnt] = arr[a];
            cnt++;
        }
    }


    for(int a = cnt-1;a>=0;a--){
        if(NEXT[a]!=past){
            ans++;
            past = NEXT[a];
            seq[seqc] = past;
            seqc++;
        }
    }
    cout << ans << "\n";
    for(int x = 0;x<seqc;x++) cout << seq[x] << " ";


    return 0;
}
