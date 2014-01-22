#include <cstdio>
#include <iostream>

using namespace std;

int N,M,I,J,A,B;

int abs(int a){
    if(a<0) return -a;
    else return a;
}
int max(int a, int b){
    if(a<b) return b;
    else return a;
}
int best = 999999;

int main(){
    cin >> N >> M >> I >> J >> A >> B;
    if(N-I<A&&I-1<A&&J!=M&&J!=1){
        cout << "Poor Inna and pony!\n";
        return 0; 
    }
    if(M-J<B&&J-1<B&&I!=N&&I!=1){
        cout << "Poor Inna and pony!\n";
        return 0;       
    }
    if(abs(I-1)%A==0&&abs(J-1)%B==0){

        int one = abs(I-1)/A;
        int two = abs(J-1)/B;
        if(!one&&!two) best = 0;
        else if(one%2==two%2&&max(one,two)<best) best = max(one,two);
    }
    if(abs(I-1)%A==0&&abs(M-J)%B==0){
        int one = abs(I-1)/A;
        int two = abs(J-M)/B;
        if(!one&&!two) best = 0;
        
        else if(one%2==two%2&&max(one,two)<best) best = max(one,two);
    }
    if(abs(I-N)%A==0&&abs(M-J)%B==0){
        int one = abs(I-N)/A;
        int two = abs(J-M)/B;
        if(!one&&!two) best = 0;
        
        else if(one%2==two%2&&max(one,two)<best) best = max(one,two);
    }
    if(abs(I-N)%A==0&&abs(J-1)%B==0){
        int one = abs(I-N)/A;
        int two = abs(J-1)/B;
        if(!one&&!two) best = 0;
        else if(one%2==two%2&&max(one,two)<best) best = max(one,two);
    }
    if(best==999999) cout << "Poor Inna and pony!\n";
    else cout << best << "\n";


    return 0;
}
