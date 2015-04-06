#include <iostream>
#include <vector>
#include <string>

using namespace std;

string one,two;

vector<int> A[26];
vector<int> B[26];
int N;
int ham = 0;
int best = 0;
int i = -1;
int j = -1;

int main(){
    cin >> N;
    cin >> one >> two;

    for(int x = 0;x<N;x++){
        if(one.at(x)!=two.at(x)){
            ham++;
            A[one.at(x)-'a'].push_back(x);
            B[two.at(x)-'a'].push_back(x);
        }
    }
    for(int x = 0;x<26;x++){

        for(int a = 0;a<A[x].size();a++){
            for(int b = 0;b<B[x].size();b++){
                if(one.at(B[x][b])==two.at(A[x][a])){
                    best = 2;
                    i = min(A[x][a]+1,B[x][b]+1);
                    j = max(A[x][a]+1,B[x][b]+1);
                    cout << ham-best << endl;
                    cout << i << " " << j << endl;
                    return 0;
                }
                else{
                    if(best==0){
                        best = 1;
                        i = min(A[x][a]+1,B[x][b]+1);
                        j = max(A[x][a]+1,B[x][b]+1);
                    }
                }
            }
        }
    }
    cout << ham-best << endl;
    cout << i << " " << j << endl;
}
 
