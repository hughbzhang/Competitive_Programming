#include <cstdio>


using namespace std;

int num;

bool vis[20];

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&num);
    
    for(int a = 1;a<=num;a++){
        for(int x = 0;x<20;x++) vis[x] = false;
        int row;
        scanf("%d",&row);
        for(int y = 1;y<=4;y++){
            for(int x = 0;x<4;x++){
                int now;
                scanf("%d",&now);
                if(row==y) vis[now] = true;
            }
        }
        int cnt = 0;
        int ans = -1;
        scanf("%d",&row);
        for(int y = 1;y<=4;y++){
            for(int x = 0;x<4;x++){
                int now;
                scanf("%d",&now);
                if(row==y&&vis[now]){
                    cnt++;
                    ans = now;
                }
            }
        }
        printf("Case #%d: ",a);
        if(cnt==0) printf("Volunteer cheated!\n");
        else if(cnt==1) printf("%d\n",ans);
        else printf("Bad magician!\n");
    }

    return 0;
}
