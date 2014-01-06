#include <utility>
#include <set>
#include <cstdio>
#include <vector>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

int num,gangs;

int cnt[100];
vector<int> seq;
set<pii> cou;
set<int> alive;
void bot(){
        set<int>::iterator cur = alive.begin();
        int x = *cur;
        cou.erase(pii(cnt[x],x));
        cnt[x]--;
        cou.insert(pii(cnt[x],x));
        if(cnt[x]==0){
            ++cur;
            alive.erase(x);
        }

        seq.push_back(x+1);
        x = *cur;
        cou.erase(pii(cnt[x],x));
        cnt[x]--;
        cou.insert(pii(cnt[x],x));
        if(cnt[x]==0) alive.erase(x);
        seq.push_back(x+1);
}
void end(){
    int first = *(alive.begin());
    int second = *(++alive.begin());
    for(int x = 0;x<cnt[first];x++){
        seq.push_back(first+1);
    }
    for(int x = 0;x<cnt[second];x++) seq.push_back(second+1);

}
int m(){
    set<pii>::iterator it = cou.end();
    --it;
    return (*it).A;    
}
int mindex(){
    set<pii>::iterator it = cou.end();
    --it;
    return (*it).B;    
}

int main(){
    freopen("gangs.in","r",stdin);
    freopen("gangs.out","w",stdout);
    scanf("%d%d",&num,&gangs);
    int max = 0;
    int left = gangs-1;
    int index = -1;
    if(num==1){
        printf("YES\n");
        printf("%d\n",num);
        for(int x = 0;x<num;x++){
            printf("1\n");
        }
    }
    for(int x = 0;x<gangs;x++){
        scanf("%d",cnt+x);
        if(x!=0&&cnt[x]>max){
            index = x;
            max = cnt[x];
        }
    }
    if(max>=num-max){
        printf("NO\n");
        return 0;
    }
    else printf("YES\n");
    left = num-max-cnt[0];
    if(left==max){
        printf("%d\n",cnt[0]);
    }
    else if(left>max){
        if((left-max)%2==0){
            printf("%d\n",cnt[0]);
        }
        else{
            cnt[0]--;
            cnt[1]--;
            if(cnt[1]==0) left--;
            seq.push_back(1);
            seq.push_back(2);
            printf("%d\n",cnt[0]);
            num-=2;
        }
    }
    else if(left<max){
        int use = cnt[0]-max+left;
        cnt[0]-=use;
        cnt[index]-=use;
        if(cnt[index]==0) left--;
        num-=(2*use);
        for(int x = 0;x<use;x++) seq.push_back(1);    
        for(int x = 0;x<use;x++) seq.push_back(index+1);    
        printf("%d\n",cnt[0]);
    }
    int crit = (num-cnt[0])/2;
    for(int x = 1;x<gangs;x++){
        if(cnt[x]!=0){
            cou.insert(pii(cnt[x],x));
            alive.insert(x);
        }
    }
    while(crit>0){
        if(m()<crit){
            bot();
        }
        else if(m()==crit){
            if(alive.size()==2){
                end();//alternate low and high
            }
            else{
                if(mindex()==*(alive.begin)()) bot();
                else{
                    index = *(alive.begin());
                    cou.erase(pii(cnt[index],index));
                    cnt[index]--;
                    cou.insert(pii(cnt[index],index));
                    if(cnt[index]==0) alive.erase(index);
                    seq.push_back(index+1);
                    index = mindex();
                    cou.erase(pii(cnt[index],index));
                    cnt[index]--;
                    cou.insert(pii(cnt[index],index));
                    if(cnt[index]==0) alive.erase(index);
                    seq.push_back(index+1);
                }
                //dec max
                //then dec min if not max
            }
        }
        crit--;
    }
    for(int x = 0;x<cnt[0];x++) seq.push_back(1);
    for(vector<int>::iterator i = seq.begin();i!=seq.end();++i) printf("%d\n",*i);

    return 0;
}
