#include <cstdio>
#include <algorithm>



using namespace std;
typedef long long ll;

const int MAXN = 50500;
ll width[MAXN];
ll height[MAXN];
int arr[MAXN];//the keys to width and height
int H[MAXN];//maximum height AFTER x
ll DP[MAXN];//answer
int deque[MAXN];//deque for convex hull
int a = 0,b=0;//start and end of the deque

int cmp(int a, int b){
    if(width[a]==width[b]) return height[a]<height[b];
    return width[a]<width[b];
}
ll eval(ll w, int fix){
    return DP[fix]+w*H[fix];
}
bool sect(int a, int b, int c){
    ll one = (DP[a]-DP[c])*(H[c]-H[b]);
    ll two = (DP[b]-DP[c])*(H[c]-H[a]);
    return one<=two;


}

int main(){
     
    freopen("acquire.in", "r", stdin);
    freopen("acquire.out", "w", stdout);
    int num;
    scanf("%d", &num);
    for(int x = 1;x<=num;x++){
        scanf("%lld%lld",width+x, height+x);
    }
    for(int h = 1;h<MAXN;h++){
        arr[h] = h;
    }
    sort(arr+1, arr+num+1, cmp);
    for(int x = num;x>0;x--){
        H[x-1] = height[arr[x]];
        if(H[x]>H[x-1]) H[x-1] = H[x];    
    }
    deque[0] = 0;
    b++;

    for(int x = 1;x<=num;x++){
        ll w = width[arr[x]];
        while(a+1<b){
            if(eval(w,deque[a])>=eval(w,deque[a+1])) a++;
            else break;
            //if earlier line is greater than the next line at this point, then we can toss it
        }
        
        DP[x] = eval(w,deque[a]);
        while(b-2>=a){
            if(sect(x,deque[b-1],deque[b-2])){//if you can invalidate it, remove it
                b--;
            }
            else break;

        }
        
        deque[b] = x;
        b++;
    }
    
    printf("%lld\n", DP[num]);



    return 0;
}
