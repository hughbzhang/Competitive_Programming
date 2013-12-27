#include <cstdio>

#define MAXN 3000300

using namespace std;

int circle[MAXN];

long long num,lines;

int main(){
    freopen("empty.in","r",stdin);
    freopen("empty.out","w",stdout);
    scanf("%lld%lld",&num,&lines);
    long long a,b,c,d,temp;
    long long cur = 0;
    long long place = num+5;//lowest index with excess cows
    for(int x = 0;x<lines;x++){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        for(int y = 1;y<=b;y++){
            temp = (c*y+d)%num;
            circle[temp]+=a;
            if(temp<place&&circle[temp]>1) place = temp;
        }
    }
    bool vis = false;//true when we have visited everything
    long long start = place;
    if(place<num){
        cur+=(circle[place]-1);
        circle[place] = 1;
        place++;
        while(cur>0||!vis){
            if(place>=num) place-=num;
            if(start == place) vis = true;
            if(!circle[place]&&cur>0){
                circle[place] = 1;
                cur--;
            }
            else if(circle[place]>1){
                cur+=(circle[place]-1);
                circle[place] = 1;
            }
            place++;
        }
    }
    //find lowest unoccupied
    long long ans = -1;
    for(long long x = 0;x<num;x++){
        if(!circle[x]){
            ans = x;
            break;
        }
    }
    printf("%lld\n",ans);

    return 0;
}
