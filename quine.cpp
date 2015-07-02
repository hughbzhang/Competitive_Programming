#include <iostream>
#include <fstream>
using namespace std;
int main(){
    freopen("quine.cpp","r",stdin);
    string s, master="";
    int rep = 4;
    int N = 22, line = 6; // change this line
    for(int x = 0;x<N;x++){
        getline(cin,s);
        if(x==line){
            for(int a = 0;a<s.length();a++){
                if(s[a]=='9') s[a] = '0';
                else if(s[a]>='0'&&s[a]<'9') s[a]++;
            }
        }
        master = master + s + "\n";
    }
    cout << "Repeat: " << rep << endl;
    ofstream fout("quine.cpp");
    fout << master;
}
