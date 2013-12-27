#include <cstdio>
#include <map>
#include <set>
#include <utility>

#define A first
#define B second

using namespace std;
map<int,int> cnt;
typedef pair<int,int> pii;


int num, change;
int list[100100];
set<pii> pos;

int max(){
    if(pos.empty()) return 0;
    set<pii>::iterator it = pos.end();
    --it;
    return (*it).A;
}

int main(){
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    scanf("%d%d",&num,&change);
    for(int x = 0;x<num;x++){
        scanf("%d",list+x);
    }
    int start = 0;
    int end = 0;
    int ans = 0;
    set<pii>::iterator it;
    while(pos.size()<=change&&end<num){
        if(cnt[list[end]]==0) pos.insert(pii(1,list[end]));
        else{
            pos.erase(pii(cnt[list[end]],list[end]));
            pos.insert(pii(cnt[list[end]]+1,list[end]));
        }
        cnt[list[end]]++;
        ++end;
    }
    if(ans<max()) ans = max();
    bool exit = false;
    
    while(end<num){
        
        //printf("FIRST = %d\n",start);

        //printf("END: %d\n",end);
        exit = false;
        while(start<num&&!exit){//contract
            cnt[list[start]]--;
            if(cnt[list[start]]==0){
                pos.erase(pii(1,list[start]));
                exit = true;
            }
            else{
                pos.erase(pii(cnt[list[start]]+1,list[start]));
                pos.insert(pii(cnt[list[start]],list[start]));
        
            }
            start++;
            if(start==end){
                printf("WRONG\n");
                break;
            }
        }
        //printf("Con: %d\n",start);
        exit = false;
        while(end<num){//expand
            if(!cnt[list[end]]){
                if(exit) break;
                exit = true;
                pos.insert(pii(1,list[end]));
            }
            else{
                pos.erase(pii(cnt[list[end]],list[end]));
                pos.insert(pii(cnt[list[end]]+1,list[end]));
            }
            cnt[list[end]]++;
            ++end;
            
        }
        if(ans<max()) ans = max();
        
    }
    printf("%d\n",ans);
    for(int x = 0;x<10;x++){
//        printf("%d\n",cnt[x]);
    }

    return 0;
}
