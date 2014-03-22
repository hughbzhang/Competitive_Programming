#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#define MAX 310

using namespace std;
typedef long long ll;

bool good[MAX][MAX][MAX];// a b c represents good from column a, row b to roc is clear
vector<int> ok[MAX][MAX];//left most from row A to row B
bool field[MAX][MAX];
int num;
long long best = 0;

int first(bool one,int a,int b){
    if(one) return *(ok[a][b].begin());
    else return *(--(--ok[a][b].end()));
}

int main(){
    freopen("eight.in","r",stdin);
//    freopen("eight.out","w",stdout);
    cin >> num;
    string in;
    for(int y = 0;y<num;y++){
        cin >> in;
        for(int x = 0;x<num;x++){
            if(in.at(x)=='.') field[y][x] = true;
            else field[y][x] = false;
        }
    }
    /*for(int y = 0;y<num;y++){
        for(int x = 0;x<num;x++){
            cout << field[y][x];
        }
        cout << endl;
    }*/
    for(int a = 0;a<num;a++){
        for(int y = 0;y<num;y++){
            if(field[y][a]) good[a][y][y] = true;
            else good[a][y][y] = false;
            for(int x = y+1;x<num;x++){
                good[a][y][x] = (good[a][y][x-1]&&field[x][a]);
            }
        }
    }
    for(int a = 0;a<num;a++){
        for(int b = a+1;b<num;b++){
            for(int x = 0;x<num;x++){
                if(good[x][a][b]){
                    ok[a][b].push_back(x);
                }
            }
            ok[a][b].push_back(MAX);
        }
    }
    /*for(int x = 0;x<num;x++){
        for(int y = x;y<num;y++){
            cout << x << " " << y << " " << good[0][x][y] << endl;
        }
    }*/
    for(int top = 0;top<num;top++){
        for(int mid = top+2;mid<num;mid++){
            for(int bot = mid+2;bot<num;bot++){
                
                int left = first(true,mid,bot);
                int right = first(false,mid,bot);
                ll pos = (bot-mid-1)*(right-left-1);
                int topleft = *lower_bound(ok[top][mid].begin(),ok[top][mid].end(),left);
                int topright;
                
                vector<int>::iterator index = upper_bound(ok[top][mid].begin(),ok[top][mid].end(),right);
                if(*index>right) index--;
                topright = *index;
                if(left==MAX||right==MAX||topleft==MAX||topright==MAX) continue;
                pos*=(mid-top-1)*(topright-topleft-1);
                if(pos>best){
                    best = pos;
                    cout << top << " " << mid << " " << bot << endl;
                    cout << left << " " << right << " " << topleft << " " << topright <<  endl;
                    cout << endl;
                }
                /*if(top==0&&mid==7&&bot==14){
                    cout << left << " " << right << endl;
                    cout << topleft << " " << topright <<  endl;
                    //    cout << ok[top][mid][x] << endl;
                    //cout << *upper_bound(ok[top][mid].begin(),ok[top][mid].end(),11) << endl; 
                }*/
            }
        } 
    }
    cout << best << endl;
    



    return 0;
}
