#include <cstdio>
#include <iostream>

using namespace std;

int num, orders;
long long total = 0;

int arr[110];

int main(){
    cin >> num >> orders;
    int a,b,c;
    for(int x = 0;x<orders;x++){
        cin >> a >> b >> c;
        arr[a]+=c;
        arr[b]-=c;
    }
    for(int x = 1;x<=num;x++){
        if(arr[x]>0) total+=arr[x];
    }
    cout << total << "\n";
}
