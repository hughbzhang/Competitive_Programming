#include <cstdio>
#include <iostream>
#include <utility>
#define MAX 1010
#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

int head[MAX];
int num;
int change = 0;
pii rem[MAX];
pii make[MAX];

int par(int a){
    if(head[a]==a) return a;
    else return head[a] = par(head[a]);
}
bool same(int a,int b){ return par(a)==par(b);}

void merge(int a,int b){
    par(a);
    par(b);
    head[head[a]] = head[b];
}

int main(){
    for(int x = 0;x<MAX;x++) head[x] = x;
    cin >> num;
    int temp, temp1;
    for(int x = 1;x<num;x++){
        cin >> temp >> temp1;
        if(same(temp,temp1)){
            rem[change] = pii(temp,temp1);
            change++;
        }
        else merge(temp,temp1);

//    cout << head[1] << " " << head[2] << " " << head[3] << endl;
    }
    //par(1); par(2); par(3);
    //cout << head[1] << " " << head[2] << " " << head[3] << endl;
 
    cout << change << endl;
    for(int x = 2;x<=num;x++){
        if(!same(1,x)){
        //    cout << "hi";
            change--;
            cout << rem[change].A << " " << rem[change].B << " ";
            cout << 1 << " " << x << endl; 
            merge(1,x);
        }
    }

    return 0;
}
