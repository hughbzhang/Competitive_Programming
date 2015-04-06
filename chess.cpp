#include <iostream>
#include <string>

using namespace std;

string board[8];
int ans = 0;



int main(){
    for(int x = 0;x<8;x++) cin >> board[x];
    for(int y = 0;y<8;y++){
        for(int x = 0;x<8;x++){
            char cur = board[y].at(x);    
            switch(cur){
                case 'Q': ans+=9; break;
                case 'q': ans-=9; break;
                case 'R': ans+=5; break;
                case 'r': ans-=5; break;
                case 'B': case 'N': ans+=3; break;
                case 'b': case 'n': ans-=3; break;
                case 'P': ans++; break;
                case 'p': ans--; break;
            }
        }
    }
    if(ans==0) cout << "Draw\n";
    else if(ans>0) cout << "White\n";
    else cout << "Black\n";
    return 0;
}