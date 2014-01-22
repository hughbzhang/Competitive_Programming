#include <cstdio>
#include <iostream>

using namespace std;


int num;

int arr[3000];

int abs(int a){
    if(a<0) return -a;
    else return a;
}


int min(int a, int b){
    if(abs(a)<=abs(b)) return a;
    else return b;
}

int main(){
    cin >> num;
    for(int x = 0;x<num;x++) cin >> arr[x];
    

    int first = arr[1]-arr[0];
    int sec = arr[2]-arr[1];
    int diff = min(first,sec);
    for(int x = 1;x<num;x++){
        if(arr[x]-arr[x-1]!=diff){
            cout << arr[x-1]+diff << "\n";
        }
    }


    return 0;
}

