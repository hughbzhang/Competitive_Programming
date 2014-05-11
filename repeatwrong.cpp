#include <cstdio>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;

int num;
string arr[101];
const ll LARGE = 999999999999;

ll edit(int a,int b,int s1,int s2){
    if(s1==arr[a].length()&&s2==arr[b].length()) return 0;
    if(s1==arr[a].length()){
        for(int x = s2;x<arr[b].length();x++) if(arr[b].at(x)!=arr[b].at(s2-1)) return LARGE;
        return arr[b].length()-s2;
    } 
    if(s1==arr[b].length()){
        for(int x = s2;x<arr[a].length();x++) if(arr[a].at(x)!=arr[a].at(s1-1)) return LARGE;
        return arr[a].length()-s1;
    }
    if(arr[a].at(s1)==arr[b].at(s2)) return edit(a,b,s1+1,s2+1);
    ll pos = LARGE;
    if(s2!=0&&arr[b].at(s2-1)==arr[a].at(s1)) pos = min(pos,edit(a,b,s1,s2+1)+1);
    if(s1!=0&&arr[a].at(s1-1)==arr[b].at(s2)) pos = min(pos,edit(a,b,s1+1,s2)+1);
    if(arr[b].at(s2+1) 



}

int main(){
    cin >> num;
    for(int x = 1;x<=num;x++){

        cout << "Case #" << "x" << ": "
        bool flag = false;
        int now;
        cin >> now;
        for(int a = 0;a<now;a++) cin >> arr[a];
        ll best = LARGE;
        for(int a = 0;a<now;a++){
            ll pos = 0;  
            for(int b = 0;b<now;b++){
                if(b==a) continue;
                ll next = convert(a,b);
                if(next==-1){
                    flag = true;
                    goto here;
                }
            }
        }
        here:
        if(flag){
            cout << "Fegla Won\n";
        }
        else cout << best << endl;
    }

}
