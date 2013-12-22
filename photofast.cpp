#include <cstdio>
#include <algorithm>
#include <utility>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

pii list[1001];
int num, pairs;

int compare(pii one, pii two){
    return one.B<two.B;
}



int main(){
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);
    scanf("%d%d",&num,&pairs);
    int a,b,temp;
    for(int x = 0 ;x<pairs;x++){
        scanf("%d%d",&a,&b);
        if(a>b){
            temp = a;
            a = b;
            b = temp;
        }
        list[x] = pii(a,b);
    }
    sort(list,list+pairs,compare);
    int cnt = 1;
    int start = list[0].B;
    int end = num;
    for(int x = 1;x<pairs;x++){
        if(list[x].A<start) continue;   
        cnt++;
        start = list[x].B;
    }
    cnt++;

    printf("%d\n",cnt);





    return 0;
}

