#include <iostream>

using namespace std;

int a,b,c,d;
int num;

bool arr[100005];

int main(){
    cin >> a >> b >> c >> d >> num;
    for(int x = a;x<=num;x+=a){
        arr[x] = true;
    }
    for(int x = b;x<=num;x+=b){
        arr[x] = true;
    }
    for(int x = c;x<=num;x+=c){
        arr[x] = true;
    }
    for(int x = d;x<=num;x+=d){
        arr[x] = true;
    }
    int cnt = 0;
    for(int x = 1;x<=num;x++){
        if(arr[x]) cnt++;
    }
    cout << cnt << endl;



    return 0;
}
