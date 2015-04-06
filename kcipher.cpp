#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool vis[26];

char mat[30][30];
int N;
string word;

int code[26];
string in;

string target;


void clear(){
    for(int y = 0;y<20;y++) for(int x = 0;x<20;x++) mat[y][x] = 0;
    for(int x = 0;x<26;x++){
        vis[x] = false;
    }
}

int main(){
    getline(cin,in);
    N = stoi(in);
    for(int t = 0;t<N;t++){
        clear();
        getline(cin,word);
        getline(cin,target);
        string key = "";
        for(int x = 0;x<word.length();x++){
            if(vis[word.at(x)-'A']) continue;
            vis[word.at(x)-'A'] = true;
            key+=word.at(x);
        }

        char cur = 'a';
        for(int x = 0;x<key.length();x++) mat[0][x] = key.at(x);
        int cnt = 0;
        for(int x = 0;x<26;x++){
            if(vis[x]) continue;
            mat[1+(int)cnt/key.length()][cnt%key.length()] = (char)(x+'A');
            cnt++;
        }
        /*for(int y = 0;y<20;y++){
            for(int x = 0;x<20;x++){
                if(mat[y][x]>0&&mat[y][x]<'A') cout << "HI" << endl;
            }
            cout << endl;
        }*/
        sort(key.begin(),key.end());
        int idx = 0;
        for(int x = 0;x<key.length();x++){
            for(int a = 0;a<key.length();a++){
                if(mat[0][a]==key.at(x)){
                    int lol = 0;
                    while(mat[lol][a]!=0){
                        if(mat[lol][a]-'A'<0) cout << lol << " " << a  << endl;
                        code[mat[lol][a]-'A'] = idx;
                        lol++;
                        idx++;
                    }
                    break;
                }
            }
        }
//        for(int x = 0;x<26;x++) cout << (char)(code[x]+'A');
 //       cout << endl;
  //      continue;

        for(int x = 0;x<target.length();x++){
            if(target.at(x)==' ') cout << ' ';
            else cout << (char)(code[target.at(x)-'A']+'A');
        }
        cout << endl;
        //`for(int x = 0;x<256;x++) cout << target[x];
        //oooioi
    }

}




