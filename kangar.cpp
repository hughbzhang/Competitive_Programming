#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int num;
int arr[1000000];

bool check(int in){
    for(int x = 0;x<in;x++){
        if(2*arr[in-x-1]>arr[num-1-x]) return false;
    }
    return true;
}

int main(){
    cin >> num;
    for(int x = 0;x<num;x++) cin >> arr[x];
    sort(arr,arr+num);
    int start = 0;
    int end = num/2;
    while(start<end){
        int mid = start+(end-start)/2;
        if((end-start)%2==1) mid++;
        if(check(mid)) start = mid;
        else end = mid-1; 
    }
    cout << num-start << endl;
    
    return 0;

}
