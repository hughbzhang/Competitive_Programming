#include <cstdio>
#include <algorithm>
#include <utility>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

pii arr[100100];

int num,dist;

int main(){
    freopen("lazy.in","r",stdin);
    freopen("lazy.out","w",stdout);
    scanf("%d%d",&num,&dist);
    dist*=2;
    int a,b;
    for(int x = 0;x<num;x++){
        scanf("%d%d",&a,&b);
        arr[x] = pii(b,a);
    }
    sort(arr,arr+num);
    int end = 0;
    long long point = 0;
    long long best = 0;
    for(int start = 0;start<num;start++){
        while(end<num&&arr[end].A-arr[start].A<=dist){
            point+=arr[end].B;
            end++;
        }
        if(point>best) best = point;
        point-=arr[start].B;
    }
    printf("%lld\n",best);
    return 0;

}

