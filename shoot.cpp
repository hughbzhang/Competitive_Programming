#include <cmath>
#include <cstdio>
#define start 8000000

using namespace std;

int best = start;
int X,Y;

void val(int a,int b){
    int tar = a*(a+1)*b*(b+1);
    int compare = tar-start;
    if(compare<0) compare*=-1;
    if(compare<best){
        X = a;
        Y = b;
        best = compare;
    }
}

int main(){
    for(int x = 1;x<1000000;x++){
        int pos = sqrt(start/(x*x+x));
        val(pos,x);
        val(pos-1,x);
        val(pos+1,x);
    }
    printf("%d %d\n",X,Y);

    return 0;
}
