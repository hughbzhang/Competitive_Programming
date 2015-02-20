#include <cstdio>
#include <queue>
#include <set>
#include <iostream>
#include <utility>
#include <algorithm>

#define A first
#define B second

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,bool> piii;

piii all[600];
int N;
int ans = 0;
int best = 1000000;
int BIT[5000];
set <int> cur;
priority_queue<int> high;
priority_queue<int,vector<int>,greater<int> > low;

void add(int num){
    if(num<=0) return;
    while(num<5000){
        BIT[num]++;
        num+=(num&-num);
    }
}

int query(int num){
    int ret = 0;
    while(num>0){
        ret+=BIT[num];
        num-=(num&-num);
    }
    return ret;
}

int main(){
    freopen("cowrect.in","r",stdin);
    freopen("cowrect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int x = 0;x<N;x++){
        int a,b;
        char c;
        cin >> a >> b >> c;
        if(c=='H') all[x] = piii(pii(a,b),true);
        else all[x] = piii(pii(a,b),false);
    }
    sort(all,all+N);
    for(int x = 0;x<N;x++){
        if(!all[x].B) continue; //guernsey
 //       cout << endl;
        for(int a = 0;a<5000;a++) BIT[a] = 0;
        cur.clear();
        while(!high.empty()) high.pop();
        while(!low.empty()) low.pop();
        int top = 1002;
        int bot = 0;
        int tops = all[x].A.B;
        int bots = all[x].A.B;
        int left = all[x].A.A;
        int line = all[x].A.B;
        int right = all[x].A.A;
        for(int a = x;a<N;a++){
            if(all[a].B&&all[a].A.B<=top&&all[a].A.B>=bot){
                low.push(all[a].A.B);
                high.push(all[a].A.B);
                add(all[a].A.B);
                cur.insert(all[a].A.B);
                right = all[a].A.A;
                bots = min(bots,all[a].A.B);
                tops = max(tops,all[a].A.B);
//                cout << all[a].A.A << " ";
            }
            else if(!all[a].B){
                if(all[a].A.B>top||all[a].A.B<bot) continue;
//                for(int b = 0;b<10;b++) cout << BIT[b] << " ";
//                cout << endl;
                int num = query(top)-query(bot-1);
                int area = (right-left)*(tops-bots);
//                cout << num << " " << area << endl;
                if(num==ans) best = min(best,area);
                if(num>ans){
                    ans = num;
                    best = area;
                }
                if(all[a].A.B==line) break;
                if(all[a].A.B>line){
                    top = all[a].A.B-1;
                    while(high.top()>top) high.pop();
                    tops = high.top();
                    //set<int>::iterator it = cur.lower_bound(all[a].A.B);
                    //--it;
                    //tops = *it;
//                    cout << tops << endl;
                    //if(tops>=top) tops = line;
                }
                if(all[a].A.B<line){
                    bot = all[a].A.B+1;
                    while(low.top()<bot) low.pop();
                    bots = low.top();
                    //set<int>::iterator it = cur.upper_bound(all[a].A.B);
                    //bots = *it;
                    //if(bots<=bot) bots = line;
                }
            }
            
        }
        int num = query(top)-query(bot-1);
        int area = (right-left)*(tops-bots);
        if(num==ans) best = min(best,area);
        if(num>ans){
            ans = num;
            best = area;
        }
    }
    cout << ans << "\n" << best << "\n";
}
