#include <cstdio>
#include <algorithm>
#include <utility>
#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

int num, pairs;
pii list[1001];
int cnt = 0;

int main(){
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);
    scanf("%d%d",&num,&pairs);
    int a,b,temp;
    bool flag = false;
   for(int x = 0;x<pairs;x++){
        scanf("%d%d",&a,&b);
        if(a>b){
            temp = a;
            a = b;
            b = temp;
        }
        list[x] = pii(a,b);
       
    }
    int start = 1, end = num;
    while(start<=num){
        for(int x = 0;x<pairs;x++){
            if(list[x].A>=start&&list[x].B<=end) end = list[x].B-1;
        }
        cnt++;

        start = end+1;
        end = num;

    }
    
    
    printf("%d\n",cnt);

    return 0;

}
