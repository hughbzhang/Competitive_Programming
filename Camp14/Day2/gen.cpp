#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    freopen("find.in","w",stdout);
    int num = 25;
    printf("%d %d\n", num,num*(num-1)/2);
    srand(time(NULL));
    for(int x = 1;x<=num;x++){
        int lol = rand()%6;
        if(lol==0) printf("b\n");
        if(lol==1||lol==4) printf("e\n");
        if(lol==2||lol==5) printf("s\n");
        if(lol==3) printf("i\n");
    }
    for(int x = 1;x<=num;x++){
        for(int y = x+1;y<=num;y++){
            printf("%d %d\n",x,y);
        }
    }
}
