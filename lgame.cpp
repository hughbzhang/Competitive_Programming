/*
ID: bigfish2
LANG: C++
TASK: lgame
*/

#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#define A first
#define B second

using namespace std;
typedef pair<int,string> pp;



class node{
    public:
        node(){
            for(int x = 0;x<26;x++){
                arr[x] = NULL;
            } 
            end = false;
        }
        bool end;//whether a word ends here
        node *arr[26];//one for each letter (children)
};

node start;
string origin;
string done[10000];
int cnt = 0;
int record = 0;
int key[10];
int length;
int s[] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
void print(int end = length-1){
    for(int x = 0;x<=end;x++){
        cout << (char)(key[x]+'a');
    }
    cout << "\n";
}
void create(string in){
    string::iterator begin = in.begin();
    string::iterator end = in.end();
    node *cur = &start;
    while(begin!=end){
        int next = (int)((*begin)-'a');
        if((cur->arr)[next]==NULL) (cur->arr)[next] = new node;
        cur = (cur->arr)[next];
        ++begin;
    }
    cur->end = true;
}
int score(int begin,int x){
    int sum = 0;
    for(int a = begin;a<=x;a++){
        sum+=s[key[a]];
    }
    return sum; 
}
string make(int start,int end){//start and end both inclusive

    string ans = "";
    for(int x = start;x<=end;x++){
        ans.push_back((char)(key[x]+'a'));
    }
    return ans;

}

pp query(int begin = 0){
    node *cur = &start;
    pp best = pp(0,"");
    for(int x = begin;x<length;x++){
        if((cur->arr)[key[x]]==NULL) return best;
        else cur = (cur->arr)[key[x]];
        if(cur->end){
            pp now = query(x+1);
            int temp = score(begin,x) + now.A;
            if(temp>=best.A){
                string next = make(begin,x)+" "+now.B;
                best = pp(temp,next);
            }
        }
    }
    return best;
}
string ssort(string in){
    string cur[10];
    int pnt = 0;
    int old = 0;
    for(int x = 0;x<in.length();x++){
        if(in.at(x)==' '){
            cur[pnt] = in.substr(old,x-old);
            old = x+1;
            pnt++;
        }
    }
    sort(cur,cur+pnt);
    string done = "";
    done+=cur[0];
    for(int x = 1;x<pnt;x++){
        done+=" ";
        done+=cur[x];
    }
    return done;
}

int main(){
    ifstream fin ("lgame.in");
    ifstream dict ("lgame.dict");
    ofstream fout ("lgame.out");
    fin >> origin;
    length = origin.length();
    string temp;
    dict >> temp;
    int cnt = 0;
    while(temp!="."){
        create(temp);
        dict >> temp;
    }
    for(int x = 0;x<origin.length();x++){
        key[x] = origin.at(x)-'a';
    }
    sort(key,key+origin.length());
    do{
        pp best = query();
    if(best.A==record&&record!=0){
            done[cnt] = best.B;
            cnt ++;
        }
        if(best.A>record&&best.A!=0){
            record = best.A;
            cnt = 0;
            done[cnt] = best.B;
            cnt++;
        }
    }while(next_permutation(key,key+origin.length()));    
    for(int x = 0;x<cnt;x++){
        done[x] = ssort(done[x]);
    }
    sort(done,done+cnt);
    string past = done[0];
    fout << record << "\n";
    fout << done[0] << "\n";
    for(int x = 1;x<cnt;x++){
        if(done[x]!=past) fout << done[x] << "\n";
        past = done[x];
    }
    return 0;
}
