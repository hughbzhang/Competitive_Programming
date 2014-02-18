#include <cstdio>
#include <iostream>
using namespace std;

int arr[2000];

int main(){
    freopen("cipher.txt","r",stdin);
    int cnt = 0, num;
    while(cin >> num){
        arr[cnt] = num;
        cnt++;
    }
    for(int x = 0;x<cnt;x++){
//        cout << arr[x] << endl;
    }
    //for(int a = 97;a<123;a++){
    int a = 103;    
    int b = 111;
        int c = 100;
        //for(int b = 97;b<123;b++){
            //for(int c = 97;c<123;c++){
                bool flag = true;
                string pos = "";
                int e = 0;
                int total = 0;
                for(int x = 0;x<cnt;x++){
                    int out;
                    if(x%3==0) out = (a^arr[x]);
                    else if(x%3==1) out = (b^arr[x]);
                    else out = (c^arr[x]);
                    pos.push_back(char(out));
                    if(out==69||out==101) e++;
                    if(out<32){
                        flag = false;
                        break;
                    }
                    total+=out;
                }
                if(flag&&e>cnt/20){ cout << pos << endl;
                cout << a << " " << b << " " << c << endl;}
            //}
            cout << total << endl;
        //}
    //}
    

}
