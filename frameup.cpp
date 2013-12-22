/*
ID:bigfish2
LANG:C++
TASK:frameup
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 40

using namespace std;


class node{
    public:
        node(char in){
            name = in;
        }
    char name;
    vector<int> par;
    vector<int> chil;
};
int ans[26];
bool vis[26];
bool arr[26];
char field[MAX][MAX];
node* all[MAX];
int cnt = 0;
int COUNT = 0;
int pnt = 0;
string last[10000];
int h,w;
int num;

void print(){
    for(int y = 0;y<h;y++){
        for(int x = 0;x<w;x++){
            cout << field[y][x];
        }
        cout << "\n";
    }
}
void add(char first, char second){
    int index = first-'A';
    int sec = second-'A';
    (all[index]->chil).push_back(sec);
    (all[sec]->par).push_back(index);
}
void order(int left, int right, int up, int bot,char start){//these are the borders of the frame
    for(int x = left;x<=right;x++){
        if(field[up][x]!=start) add(start,field[up][x]);// something is covering me
        if(field[bot][x]!=start) add(start,field[bot][x]);
    }
    for(int y = up;y<=bot;y++){
        if(field[y][left]!=start) add(start,field[y][left]);
        if(field[y][right]!=start) add(start,field[y][right]);
    }
}

void find(char start){
    int left = w;
    int right = 0;
    int up = h;
    int bot = 0;
    for(int x = 0;x<w;x++){
        for(int y = 0;y<h;y++){
            if(field[y][x]==start){
                if(x<left) left = x;
                if(x>right) right = x;
                if(y>bot) bot = y;
                if(y<up) up = y;
            }
        }
    }
    if(left==w&&right==0&&up==h&&bot==0){
        all[int(start-'A')] = NULL;
        return;
    }
    COUNT++;
    order(left,right,up,bot,start);
}
void clear(){
    for(int x = 0;x<26;x++) arr[x] = false;
}
void dup(){
    for(int x = 0;x<num;x++){
        if(all[x]==NULL) continue;
        clear();
        vector<int>::iterator it = all[x]->chil.begin();
        vector<int>::iterator end = all[x]->chil.end();
        while(it!=end){
            arr[*it] = true;
            ++it;
        }
        all[x]->chil.clear();
        for(int a = 0;a<26;a++){
            if(arr[a]) all[x]->chil.push_back(a);
        }
        
        clear();
        it = (all[x]->par).begin();
        end = (all[x]->par).end();
        while(it!=end){
            arr[*it] = true;
            ++it;
        }
        (all[x]->par).clear();
        for(int a = 0;a<26;a++){
            if(arr[a]) all[x]->par.push_back(a);
        }
    }
}
void done(){
    string pos = "";
    for(int x = cnt-1;x>=0;x--){
        pos.push_back(char(ans[x]+'A'));
    }
    last[pnt] = pos;
    pnt++;    
}
void rem(int index){//remove all the times index is a child
    vector<int>::iterator it = all[index]->par.begin();
    vector<int>::iterator end = all[index]->par.end();
    while(it!=end){
        vector<int>::iterator start = all[*it]->chil.begin();
        while(*start!=index) ++start;
        all[*it]->chil.erase(start); 
        ++it;
    }
}
void unrem(int index){//restore index as a child
    vector<int>::iterator it = all[index]->par.begin();
    vector<int>::iterator end = all[index]->par.end();
    while(it!=end){
        all[*it]->chil.push_back(index);
        ++it;
    }
}
void search(){
    if(cnt==COUNT){
        done();
        return;
    }
    for(int x = 0;x<num;x++){
        if(all[x]==NULL) continue;
        if(!all[x]->chil.size()&&!vis[x]){//if you have no children
            rem(x);
           
            ans[cnt] = x;
           cnt++;
           vis[x] = true;
           search();
           vis[x] = false;
           cnt--;
           unrem(x); 
        }
    }
}
    
int main(){
    freopen("frameup.in","r",stdin);
    freopen("frameup.out","w",stdout);
    cin >> h >> w;
    string temp;
    for(int y = 0;y<h;y++){
        cin >> temp;
        for(int x = 0;x<temp.length();x++){
            field[y][x] = temp.at(x);
        }
    }
    for(int x = 0;x<26;x++){
        all[x] = new node((char)(x+'A'));
    }
    num = 26;
    char start = 'A';
    for(int x = 0;x<26;x++){
        find(start);
        start++;
    }
    dup();
        /*for(int x = 0;x<num;x++){
        cout << char(x+'A') << " ";
        cout << "PAR ";
        vector<int>::iterator it = all[x]->chil.begin();
        vector<int>::iterator end = all[x]->chil.end();
        while(it!=end){
            cout << char(*it+'A') << " ";
            ++it;
        }
        cout << endl;       
    }*/
   search(); 
   sort(last,last+pnt);
   for(int x = 0;x<pnt;x++){
        cout << last[x] << endl;
   }
   return 0;
}
