#include<cstdio>
#include<string>

using namespace std;

int main(){
    int num;
    int x = 0;
    scanf("%d", &num);
    char s[5];
    for(int h = 0;h<num;h++){
       scanf("%s", s);
       if(s[0]=='+'||s[1]=='+') x++;
       else x--;
    }
    printf("%d", x);

}
