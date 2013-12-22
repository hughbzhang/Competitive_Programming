#include <cstdio>
#include <cmath>
#define MAX 1000000


using namespace std;

bool sieve[MAX];//index x corresponds to 2*x+1 Even numbers are nonexistent


int main(){
    
    int stop = sqrt(MAX);

    for(int x = 1;x<stop;x++){
        if(sieve[x]==false){//we are prime
            int square = 2*x*(x+1);//(2x+1)^2 => 4x^2+4x+1 => 2[2*x*(x+1)]+1
            int val = 2*x+1;
            for(int a = square;a<MAX;a+=val){
                sieve[a] = true;//we are composite
            }
        }
    }
    int x = 0;
    int max = 0;
    int ans = 0;
    int A,B;
    for(int a = -999;a<1000;a++){
        
        for(int b = -999;b<1000;b++){
           //x^2+ax+b
           for(x = 0;x<2000;x++){
               int pos = x*x+a*x+b;
               if(pos<0) break;
               if(pos%2==0&&pos!=2) break;
               int index = (pos-1)/2;
               if(sieve[index])break;
           }
           if(x>max){
               A=a;
               B=b;
               ans = a*b;
               max = x;
           }
        }
    }
    printf("%d\n",ans);
    printf("x^2+%dx+%d MAX=%d",A,B,max);

    return 0;
}
