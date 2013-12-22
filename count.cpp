#include <cstdio>
#include <string>

using namespace std;

int base [10] = {0,3,3,5,4,4,3,5,5,4};//letter counts in the base digits
int ten[10] = {3,6,6,8,8,7,7,9,8,8};
int rest[10] = {0,0,6,6,5,5,5,7,6,6};
string BASE [10] = {"","one","two","three","four","five","six","seven","eight","nine"};
string TEN[10] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string REST[10] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};


int main(){
    
    int answer = 0,done=0;

    for(int x = 1;x<1000;x++){
        string now = "";
        answer = 0;
        int cur = x;
        int key = cur%10;
        answer+=base[key];
        now.insert(0,BASE[key]);
        cur/=10;
        if(cur==0){
            printf("%d %d %s\n",x,answer,now.c_str());
            done+=answer;
            continue;
        }
        if(cur%10==1){
            answer-=base[key];
            answer+=ten[key];
            now.clear();
            now.append(TEN[key]);
        }
        else{
            answer+=rest[cur%10];
            now.insert(0,REST[cur%10]);
        }
        cur/=10;
        if(cur==0){
            printf("%d %d %s\n",x,answer,now.c_str());
            done+=answer;
            continue;
        }
        answer+=10;//hundred and

        answer+=base[cur];
        now.insert(0,"hundredand");
        now.insert(0,BASE[cur]);
        printf("%d %d %s\n",x,answer,now.c_str());
        done+=answer;
    }
    done+=11;
    done-=27;
    printf("%d\n",done);
}
