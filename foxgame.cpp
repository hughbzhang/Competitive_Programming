#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int decks;
int first = 0, sec = 0;

int arr[100];
int END = 0;

int main(){
    cin >> decks;
    int cards,temp;
    for(int x = 0;x<decks;x++){
        cin >> cards;
        for(int a = 0;a<cards/2;a++){
            cin >> temp;
            first+=temp;
        }
        int start = cards/2;
        if(cards%2==1){
            cin >> arr[END];
            END++;
            start++;
        }
        for(int a = start;a<cards;a++){
            cin >> temp;
            sec+=temp;
        }
    }
    sort(arr,arr+END);
    for(int x = 0;x<END;x++){
        if(x%2==0) first+=arr[END-x-1];
        else sec+=arr[END-x-1];    
    }
    cout << first << " " << sec << endl;

    return 0;
}
