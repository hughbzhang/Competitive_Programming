#include <cstdio>
#define MAX 1000000

using namespace std;

bool row[MAX];
bool col[MAX];

int cnt, Y,X;

int max(int a,int b){
    if(a<=b) return a;
    else return b;
}

int main(){
    freopen("rook.in","r",stdin);
    scanf("%d%d",&cnt,&Y);
    int a,b;
    for(int x = 0;x<cnt;x++){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        row[a] = true;
        col[b] = true;
    }
    int rows = 0;
    int cols = 0;
    for(int x = 0;x<Y;x++){
 
        if(!row[x]) rows++;
        if(!col[x]) cols++;
    }
    printf("%d\n",max(rows,cols));


}
