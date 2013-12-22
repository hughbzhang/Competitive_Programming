#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXCOWS (1<<16)
#define MAXG 181000
#define MAXH 1001000
#define MAXS 1<<17//SEG TREE MAX

using namespace std;

int height[MAXCOWS];
int groups[MAXG][2];
int SEG[MAXS];
int MIN[MAXS];

void build(int cur, int l, int r){//l = left range, r = right range
        if(l==r-1){
            MIN[cur] = height[l];
            SEG[cur] = height[l];//if only one element, fill it
        }
        else{
            int mid = (l+r)/2;//otherwise build children first
            build(2*cur, l, mid);
            build(2*cur+1, mid, r);
            SEG[cur] = max(SEG[2*cur],SEG[2*cur+1]);//find yourself
            MIN[cur] = min(MIN[2*cur],MIN[2*cur+1]);//find yourself
        }
}
int find(int left, int right, int cur, int l, int r){
        if(left>=r||right<=l) return 0;//current node out of bounds
        if(left<=l&&r<=right) return SEG[cur];//return yourself
        int mid = (l+r)/2;
        return max(find(left,right,2*cur,l,mid),find(left,right,2*cur+1,mid,r));
}
int look(int left, int right, int cur, int l, int r){
        if(left>=r||right<=l) return MAXH;//current node out of bounds
        if(left<=l&&r<=right) return MIN[cur];//return yourself
        int mid = (l+r)/2;
        int one = look(left,right,2*cur,l,mid);
        int two = look(left,right,2*cur+1,mid,r);
        return min(one, two);
}
int main(){
    
    freopen("lineupg.in", "r", stdin);
    freopen("lineupg.out", "w", stdout);
    int cows, number;
    scanf("%d%d", &cows, &number);
    for(int x = 0;x<cows;x++){
        scanf("%d", &height[x]);
    }
    
    build(1,0,MAXCOWS);
    int a, b;
    for(int x = 0;x<number;x++){
        scanf("%d%d", &a, &b);
        int ans = find(a-1,b,1,0,MAXCOWS);
        int ans1 = look(a-1,b,1,0,MAXCOWS);
        printf("%d\n", ans-ans1); 
    }
    return 0;
}
