#include <cstdio>
#include <iostream>

using namespace std;

int num, oh, wow;

int main(){
    
    cin >> num >> oh >> wow;
    if(num==1&&oh==0&&wow==0){
        cout << 1 << endl;
        return 0;
    }
    if(oh+wow>=num||num<=oh+1){
        cout << -1 << endl;
        return 0;
    }
    cout << 1 << " ";
    int sum = 1;
    for(int x = 0;x<wow;x++){
        cout << sum+1 << " ";
        sum+=(sum+1);
    }
    sum = (sum-1)/2;
    if(wow==0){
        cout << 1 << " "; 
        wow++;
    }
    for(int x = 1;x<=oh;x++){
        cout << sum+1+x << " ";
    }
    for(int x = oh+wow+1;x<num;x++){
        cout << 1 << " ";
    }
    
    cout << endl;


}
