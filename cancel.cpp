#include <cstdio>

using namespace std;

int simplify(int a,int b){//a/b
    int temp;
    while(a>0){
        temp = b%a;
        b = a;
        a = temp;
    }
    return b;
}

int main(){
    
    int TOP = 1;
    int BOT = 1;

    for(int bot = 10;bot<100;bot++){
        for(int top = 10;top<bot;top++){
            int a = bot%10;//bot ba
            int b = bot/10;
            int c = top%10;//top dc
            int d = top/10;
            if(a==0||b==0||c==0||d==0) continue;
            if(a==c&&d*bot==b*top){
                TOP*=d;
                BOT*=b;
            } 
            else if(a==d&&c*bot==b*top){
                TOP*=c;
                BOT*=b;
            } 
            else if(b==c&&d*bot==a*top){
                TOP*=d;
                BOT*=a;
            } 
            else if(b==d&&c*bot==a*top){
                TOP*=c;
                BOT*=a;
            } 
        }
    }
    printf("%d %d\n",TOP,BOT);
    printf("%d\n",BOT/simplify(TOP,BOT));

    return 0;
}
