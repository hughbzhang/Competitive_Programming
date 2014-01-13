#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    freopen("test.in","w",stdout);
    printf("%d\n",200);
    int num = 1;
    for(int x = 0;x<200;x++){
        int index = rand()%10;
        if(index==0) index = 3;
        else if(index%2==0) index = 1;
        else index = 2;
        if(index==3&&num==1) continue;
        printf("%d ",index);
        if(index==3){
            num--;
        }
        else if(index==2){
            int ran = rand()%2000-1000;
            num++;
            printf("%d",ran);
        }
        else{
            printf("%d %d",rand()%(num-1)+1,rand()%2000-1000);
        }
        printf("\n");
    }


}
