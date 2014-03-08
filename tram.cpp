#include<cstdio>

using namespace std;

int main(){
    int num;
    scanf("%d", &num);
    int a, b, p = 0, max = 0;
    for(int x = 0;x<num;x++){
        scanf("%d%d", &a, &b);
        p-=a;
        p+=b;
        if(p>max) max = p;
    }
    printf("%d",max);



    return 0;
}
