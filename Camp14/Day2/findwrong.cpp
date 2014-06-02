#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <vector>
#include <set>
#define MAX 260
#define A first
#define B second

using namespace std;
typedef pair<int,string> key;
typedef multiset<int>::iterator vi;
typedef long long ll;
struct hist{
    ll num;
    ll *past;
};


ll ans = 0;
int N,M;
char letter[MAX];
vector<int> child[MAX];
string goal = "bessi";
map<key,hist> all;

int main(){
    freopen("find.in","r",stdin);
//    freopen("find.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for(int x = 0;x<N;x++){
        cin >> letter[x];
        if(letter[x]=='b'){
             all[key(x,"b")].num++;
             all[key(x,"b")].past = new ll[MAX];
        }
    }
    for(int x = 0;x<N;x++){
    //    if(all[key(x,"b")].num!=0) cout << x << endl;
    }
    int a,b;
    for(int x = 0;x<M;x++){
        cin >> a >> b;
        a--;
        b--;
        child[a].push_back(b);
        child[b].push_back(a);    
    }
    string cur = "b";
    string past = "";
    
    for(int x = 1;x<goal.length();x++){
        cur+=goal.at(x);
        past+=goal.at(x-1);
        for(int a = 0;a<N;a++){
            if(letter[a]!=goal.at(x)) continue;
            for(int b = 0;b<child[a].size();b++){
                if(letter[child[a][b]]!=goal.at(x-1)) continue;
                //if(cur=="bess") cout << "HERE " << a << " " << child[a][b] << endl;
                key now = key(a,cur);
                key old = key(child[a][b],past);
                all[now].num+=all[old].num;
                all[now].past = new ll[MAX];
                //for(vi it = (*(all[old].past)).begin();it!=(*(all[old].past)).end();++it) (*(all[now].past)).insert(*it);
                //for(vi it = all[old].past->begin();it!=all[old].past->end();++it) all[now].past->insert(*it);
                for(int y = 0;y<N;y++) all[now].past[y]+=all[old].past[y];
                if(letter[a]=='e') all[now].past[a]+=all[now].num;
            }
        }
    }
    cur+="e";
    past+="i";
    for(int a = 0;a<N;a++){
        if(letter[a]!='e') continue;
        for(int b = 0;b<child[a].size();b++){
            if(letter[child[a][b]]!='i') continue;
            //if(cur=="bess") cout << "HERE " << a << " " << child[a][b] << endl;
            key now = key(a,cur);
            key old = key(child[a][b],past);
            all[now].num+=all[old].num;
            all[now].num-=all[old].past[a];
        }
        cout << a << " " << all[key(a,"bessie")].num << endl;
    }
    for(int x = 0;x<N;x++){
        cout << x << " " << all[key(x,"bessie")].num <<endl;
        ans+=all[key(x,"bessie")].num;
    }
    cout << ans << endl;
}
