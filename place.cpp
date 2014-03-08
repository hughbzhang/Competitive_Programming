#include <cstdio>

using namespace std;

int main(){
    int a,b;
    scanf("%d%d", &a, &b);
    int junk;
    for(int x = 0;x<b-1;x++){
        scanf("%d",&junk);
        if(junk<=0){
            printf("%d",x);
            return 0;
        }
    }
    int num;
    int counter = b;
    scanf("%d",&num);
    if(num<=0) counter--;
    else{
        while(b<a){
            scanf("%d",&junk);
            if(junk==num&&junk>=0) counter++;
            else break;
            b++;
        }
    }
    printf("%d", counter);
    return 0;
}
