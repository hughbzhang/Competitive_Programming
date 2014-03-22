#include <iostream>

using namespace std;
typedef long double ld;

int speed, drag, start, straight, total;

ld cur = 0.0;
int ans = 0;

int main(){
    cin >> speed >> drag >> start >> straight >> total;
    if(drag<=speed){
        cout << 0 << endl;
        return 0;
    }
    cur = drag*speed*start/(ld)(drag-speed);//when they first meet
    while(cur<total){
        ans++;
        cur += ((cur/drag+straight)*speed);
        cur += speed*cur/(drag-speed);
    }
    cout << ans << endl;

    return 0;
}
