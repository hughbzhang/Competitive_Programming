#include <cstdio>
#include <time.h>
#include <string>
#include <iostream>

using namespace std;

class node{
    public:
        node(){
            for(int x = 0;x<26;x++){
                arr[x] = NULL;
            } 
            ok = false;
        }
        bool ok;//whether a word ends here
        node* arr[26];//one for each letter (children)
};

int N;
string input;
int s[101000];
int n[101000];
int p[101000];
int slength;
int record = 0;
int BEGIN = 0;

node* start;

int length;
void print(){
    for(int x = 1;x<slength;x++){
        cout << char('a'+s[x]);
    }
    cout << endl;
    int a = n[0];
    while(a<slength){
        cout << char(s[a]+'a');
        a = n[a];
    }
    cout << endl;
}

int main(){
    start = new node;
    freopen("censor.in","r",stdin);
    freopen("censor.out","w",stdout);
    cin >> input;
    length = input.length()+1;
    slength = length;
    for(int x = 1;x<=input.length();x++){
        n[x] = x+1;
        p[x+1] = x;
        s[x] = input.at(x-1)-'a';
    }
    n[length] = -1;
    n[0] = 1;
    p[1] = 0;
    p[0] = 0;
    s[0] = -1;
    cin >> N;
    for(int x = 0;x<N;x++){
        cin >> input;
        if(input.length()>record) record = input.length();
        node* cur = start;
        for(int a = 0;a<input.length();a++){
            int ind = input.at(a)-'a';
            if(cur->arr[ind]==NULL) cur->arr[ind] = new node;
            cur = cur->arr[ind];
        }
        cur->ok = true;
    }
    bool flag = true;
    while(flag){
        //cout << "LOL\n";
        //print();
        flag = false;
        int beg = BEGIN;
        while(beg<slength){
            bool found = false;
            beg = n[beg];
            if(start->arr[s[beg]]==NULL) continue;
            node* cur = start->arr[s[beg]];
            int cnt = 1;
            int a = beg;
            while(a<slength){
                if(cur->ok){
                    //cout << cnt << endl;
                    //
                    length-=cnt;
                    int skip = n[a];
                    while(cnt>0){
                        //cout << char(s[a]+'a');
                        a = p[a];
                        cnt--;
                    }
                    if(n[a]==skip) break;
                    n[a] = skip;
                    BEGIN = a;
                    for(int y = 0;y<record;y++){
                        BEGIN = p[BEGIN];
                        if(BEGIN==0) break;
                    }
                    p[skip] = a;
                    found = true;
                    flag = true;
                    break;
                }

                a = n[a];
                if((cur->arr[s[a]])==NULL) break;
                cur = cur->arr[s[a]];
                cnt++;
                
            }
            if(found) break;
        }
    }
//    print();
    int a = n[0];
    while(a<slength){
        cout << char(s[a]+'a');
        a = n[a];
    }
    cout << endl;
}