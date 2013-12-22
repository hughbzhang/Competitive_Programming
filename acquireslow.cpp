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

int cmp(int a, int b){
    if(width[a]==width[b]) return height[a]<height[b];
    return width[a]<width[b];
}



int main(){

    //freopen("acquire.in", "r", stdin);
    freopen("acquire.out", "w", stdout);
    int num;
    scanf("%d", &num);
    for(int x = 1;x<=num;x++){
        scanf("%lld%lld",width+x, height+x);
    }
    for(int a = 1;a<MAXN;a++){
        arr[a] = a;
    }
    sort(arr+1, arr+num+1, cmp);
    for(int x = num;x>0;x--){
        H[x-1] = height[arr[x]];
        if(H[x]>H[x-1]) H[x-1] = H[x];    
    }

    for(int x = 1;x<=num;x++){
        DP[x] = DP[x-1] + width[arr[x]]*H[x-1];
        for(int y = x-2;y>=0;y--){
            ll pos = DP[y]+ width[arr[x]]*H[y];
            if(pos<DP[x]) DP[x] = pos;
        }
    }

    printf("%lld\n", DP[num]);



    return 0;
}
