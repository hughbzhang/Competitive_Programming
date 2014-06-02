#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <utility>

#define A first
#define B second

using namespace std;
typedef long double ld;
typedef pair<int,int> pii;

ld old[28];
ld now[28];
pii arr[669];

int main(){
    freopen("markerdata.txt","r",stdin);
    string in;
    int trash;
    for(int x = 0;x<28;x++){
        cin >> in;
    }
    for(int y = 1;y<670;y++){
        ld dist = 0;
        cin >> trash;
        for(int x = 0;x<27;x++) cin >> now[x]; 
        for(int x = 0;x<27;x++){
            dist+=(now[x]-old[x])*(now[x]-old[x]);
        }
        swap(old,now);
        cout << floor(dist) << endl;
        arr[y-1] = pii(floor(dist),y);
    }
    sort(arr,arr+669);
    cout << arr[0].B << " " << arr[1].B << " " << arr[2].B << endl;
}
