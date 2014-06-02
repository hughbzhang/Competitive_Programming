#include <cstdio>
#include <iostream>
#define jump 200
#define MAX 100100

int past[MAX];//jump ancestor
int par[MAX];
//ONE INDEX HERE

int root(int cur){
    if(past[cur]!=-1&&past[cur]!=0) return past[cur];
    else{
        past[cur] = cur;
        for(int x = 0;x<jump;x++) past[cur] = par[past[cur]];
    }
    return past[cur];
}

int depth(int cur){
    int ans = 0;
    while(root(cur)!=0){
        cur = root(cur);
        ans+=jump;
    }
    while(cur!=0){
        cur = par[cur];
        ans++;
    }
    return ans;
}

/*
 * Specifies the integer N.
 */
void init(int N) {
    for(int x = 0;x<=N;x++){
        past[x] = -1;
    }
}

/*
 * Make A the parent of B.
 */
void make_parent(int A, int B) {
    par[B] = A;
    past[B] = -1;
}


/*
 * Return true if A is an ancestor of B.
 */
bool is_ancestor(int A, int B) {
    int depthA = depth(A);
    int depthB = depth(B);
    if(depthA>depthB) return false;
    int diff = depthB-depthA;
    while(diff>=jump){
        diff-=jump;
        B = root(B);
    }
    for(int x = 0;x<diff;x++) B = par[B];
    if(B==A) return true;
    return false;
}
