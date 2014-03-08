#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    
    char word[200];
    int num;
    scanf("%d", &num);
    for(int x = 0;x<num;x++){
        scanf("%s",word);
        int length = strlen(word);
        if(length>10) printf("%c%d%c\n",word[0],length-2,word[length-1]);
        else printf("%s\n",word);
    }


    return 0;
}
