#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int T,N;
int arr[1001000];
int start[1001000];
int s = 0;
int e = 0;

int main(){
    ios::sync_with_stdio(0);
    cin >> T;
    for(int t = 0;t<T;t++){
        cin >> N;
        if(N==0){
            cout << 0 << "\n";
            continue;
        }
        for(int x = 0;x<N;x++) cin >> arr[x];
        sort(arr,arr+N);




        s = 0, e = 0;
        int small = N;
        start[e++] = arr[0];
        int place = 1;
        int target = arr[0]+1;
        int cur = arr[0];
        int next = 0;

        while(place<N){

            if(arr[place]==cur){
                start[e++] = cur;
            }
            else if(arr[place]==target){
                next++;
            }
            else if(next>0&&arr[place]==target+1){//close tabs
                if(next<e-s){
                    small = min(small,cur-start[e-next-1]+1);//update smallest and close the tab
                    s+=(e-s-next);
                }
                else{//open tabs
                    int diff = next-(e-s);
                    for(int x = 0;x<diff;x++){
                        start[e++] = target;
                    }
                }
                cur = target;
                target++;
                next = 1;//first next thing
            }
            else{//close all tabs since there is a gap
                int pos = cur-start[e-1]+1;
                if(next>0) pos++;
                small = min(small,pos);
                cur = arr[place];
                target = cur+1;
                start[0] = arr[place];
                e = 1;
                s = 0;
                next = 0;
            }
            place++;
        }
        if(next>e-s) small = 1;
        if(next<e-s) small = min(small,min(cur-start[e-next-1]+1,cur-start[e-1]+2));
        if(next==e-s) small = min(small,arr[N-1]-start[e-1]+1);


        cout << small << "\n";
    }
}

