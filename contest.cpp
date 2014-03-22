#include <cstdio>
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>

#define A first
#define B second

using namespace std;

typedef pair<int,int> pii;

pii arr[5000];
int num;
int low = 0,high = 0;

int main(){
    arr[0] = pii(0,1);
    int in, cnt = 2;
    cin >> in;
    arr[1] = pii(in,in+1);
    cin >> num;
    for(int x = 0;x<num;x++){
        int temp, temp1, temp2;
        cin >> temp;
        if(temp==1){
            cin >> temp1 >> temp2;
            arr[cnt] = pii(temp1,temp2+1);
            cnt++;
        }
        else{
            cin >> temp1;
            arr[cnt] = pii(temp1,temp1+1);
            cnt++;
        }
    }
    sort(arr,arr+cnt);
    for(int x = 1;x<cnt;x++){
        int space = arr[x].A-arr[x-1].B;
        high+=space;
        low+=ceil(.5*space);
    }
    cout << low << " " << high << endl;
    


    return 0;
}
