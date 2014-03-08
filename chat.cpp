#include <cstdio>

using namespace std;

int main(){
    char m[5] = {'h','e','l','l','o'};
    char w[110];
    char* p = m;
    scanf("%s", w);
    char* a = w;
    bool go = false;
    for(int x = 0;x<110;x++){
        if(p==m+5){
            go = true;
            break;
        }
        if(*p==*a) p++;
        a++;
    }
    if(go) printf("YES");
    else printf("NO");

    return 0;
}
