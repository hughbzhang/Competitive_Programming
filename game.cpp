#include <cstdio>
#include <iostream>

using namespace std;

int num;

int arr[1010];
int score[2];

int main(){
    cin >> num;
    for(int x = 0;x<num;x++) cin >> arr[x];
    int start = 0;
    int end = num-1;
    bool turn = false;
    while(start<=end){
        if(arr[start]>arr[end]){
            score[turn]+=arr[start];
            start++;
        }
        else{
            score[turn]+=arr[end];
            end--;
        }
        turn = !turn;
    }
    cout << score[0] << " " << score[1] << "\n";

}
