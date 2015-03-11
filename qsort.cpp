#include <cstdio>
#include <ctime>
#include <algorithm>
#include <iostream>
#define MAX 1000000

using namespace std;
int arr[MAX];


void print(){
    for(int x = 0;x<MAX;x++) cout << arr[x] << " ";
    cout << endl;
}

void qsort(int s, int e){
    if(s>=e||s<0||e>=MAX) return;
    int beg = s;
    int don = e;
    //int par = arr[s+(rand()%(e-s+1))];
    int par = arr[s];
    s++;
    while(true){
        while(s<don&&arr[s]<par) s++;
        while(e>beg&&arr[e]>par) e--;
        if(e<=s) break;

        int tmp = arr[s];
        arr[s] = arr[e];
        arr[e] = tmp;
        s++;
        e--;
    }
    int tmp = arr[e];
    arr[e] = arr[beg];
    arr[beg] = tmp;
    qsort(beg,e-1);
    qsort(e+1,don);
}
    
void shuffle(){
    for(int x = 0;x<MAX;x++){
        int tmp = arr[x];
        int nxt = arr[x+rand()%(MAX-x)];
        arr[x] = arr[nxt];
        arr[nxt] = tmp;
    }
}


int main(){
    srand(time(NULL));
    for(int x = 0;x<MAX;x++){
        arr[x] = x;
    }
    shuffle();
    //print();    
    double st = clock();
    sort(arr,arr+MAX);
    double ed = clock();

    cout << (ed-st)/CLOCKS_PER_SEC << endl;
    //print();
    for(int x = 0;x<MAX;x++){
        arr[x] = x;
    }
    shuffle();
    //print();
    st = clock();
    qsort(0,MAX-1);
    ed = clock();
    for(int x = 0;x<MAX;x++) if(x!=arr[x]) cout << "BAD\n";
    cout << (ed-st)/CLOCKS_PER_SEC << endl;
    //print();
}



    

