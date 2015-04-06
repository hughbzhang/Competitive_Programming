#include <iostream>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;
typedef pair<int,int> pii;

string one,two;

vector<int> A[26];
vector<int> B[26];
int N;
int ham = 0;
int best = 0;
int i = -1;
int j = -1;
int vis[26];
map<pii,int> m;
set<pii> s;

int main(){
    cin >> N;
    cin >> one >> two;
    for(int x = 0;x<26;x++) vis[x] = -1;

    for(int x = 0;x<N;x++){
        if(one.at(x)!=two.at(x)){
            ham++;
            pii cur = pii(one.at(x),two.at(x));
            s.insert(cur);
            m[cur] = x;
            vis[two.at(x)-'a'] = x;
        }
    }
    for(int x = 0;x<N;x++){
        if(one.at(x)!=two.at(x)){
            pii cur = pii(two.at(x),one.at(x));
            if(s.count(cur)>0){
                cout << ham-2 << endl;
                cout << x+1 << " " << m[cur]+1 << endl;
                return 0;
            }
            if(vis[one.at(x)-'a']>-1){
                best = 1;
                i = x+1;
                j = vis[one.at(x)-'a']+1;
            }
        }
    }
    cout << ham-best << endl;
    cout << i << " " << j << endl;
}
 
