#include <cstdio>
#include <iostream>

using namespace std;

int N;
int T1, T2, T3;
int A[21];
int B[21];
int C[21];
int T;
bool ans = false;
int t1,t2,t3;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin >> T;
    for(int x = 1;x<=T;x++){
        ans = false;
        cin >> T1 >> T2 >> T3;
        cin >> N;
        for(int t = 0;t<N;t++){
            cin >> A[t] >> B[t] >> C[t];
        }
        for(int a = 0;a<(1<<N);a++){
            t1 = 0;
            t2 = 0;
            t3 = 0;
            for(int b = 0;b<N;b++){
                if((1<<b)&a){
                    t1+=A[b];
                    t2+=B[b];
                    t3+=C[b];
                }
            }
            if(t1==T1&&t2==T2&&t3==T3){
                ans = true;
                break;
            }
        }
        cout << "Case #" << x << ": ";
        if(ans) cout << "yes\n";
        else cout << "no\n";
    }
}
        
