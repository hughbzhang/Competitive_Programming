#include <cstdio>
#include <algorithm>
#include <utility>
#include <set>
#define A first
#define B second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,set<pii> > ret;//first is cost second is unmatched friends with the first guy is the main friend
typedef set<pii>::iterator it;
int num;
int f[100][3];//friends
pii loc[100];//ranges of each element
set<pii> empty;
ret null = ret(0,empty);
ret LARGE = ret(10000,empty);

bool include(pii one, pii two){
    return one.A<=two.A&&one.B>=two.B;
}

ret merge(ret one,ret two,pii l, pii r){
    int total = one.A+two.A;
    set<pii> merged;
    for(it i = one.B.begin();i!=one.B.end();++i){
        if(!include(r,loc[(*i).B])){//if you are not already connected
    //        printf("FIRST: %d %d SECOND: %d %d\n",loc[(*i).B].A,(*i).B,r.A,r.B);
            if(loc[(*i).B].A>=l.B) total+=(r.B-r.A);//go to the end
            merged.insert(*i);
        }
    }
    for(it i = two.B.begin();i!=two.B.end();++i){
        if(!include(l,loc[(*i).B])){
      //      printf("FIRST: %d %d SECOND: %d %d\n",loc[(*i).B].A,(*i).B,l.A,l.B);
            if(loc[(*i).B].B<=r.A) total+=(l.B-l.A);
            merged.insert(*i);
        }
    }
    return ret(total,merged);
}

ret divide(set<int> s, int left, int right){
    if(s.size()!=right-left) printf("MISMATCH\n");
    if(right<left+1) return null;//out of bounds
    if(right==left+1){//base case of 1
        int cur = *(s.begin());
        int cost = 0;
        set<pii> unmatched;
        for(int x = 0;x<3;x++){
            if(loc[f[cur][x]].A>=right) cost++;//if you are on the left increase cost
            //other side has cost of 0
            unmatched.insert(pii(cur,f[cur][x]));
        }
        return ret(cost,unmatched);
    }
    //divide and conquer
    int length = s.size();//filling up the permutation thingy
    int mid = (right+left)/2;
    int end = length/2;
    pii l = pii(left,mid);
    pii r = pii(mid,right);//ranges
    set<int> LEFT;
    set<int> RIGHT;
    ret best = LARGE;
    bool * perm = new bool[length];
    for(int x = 0;x<end;x++){ perm[x] = false;}
    for(int x = end;x<length;x++){ perm[x] = true;}
    do{
        LEFT.clear();//the way we split
        RIGHT.clear();
        set<int>::iterator i = s.begin();
        for(int x = 0;x<length;x++){
            
            if(perm[x]){
                RIGHT.insert(*i);
                loc[*i] = r;
            }
            else{
                LEFT.insert(*i);
                loc[*i] = l;
            }
            ++i;
        }
        ret one = divide(LEFT,l.A,l.B);
        ret two = divide(RIGHT,r.A,r.B);
        if(one==null&&two==null) continue;
        ret temp;
        if(one==null) temp = two;
        else if(two==null) temp = one;
        else temp = merge(one,two,l,r);
        if(temp.A<best.A) best = ret(temp.A,temp.B);

    } while(next_permutation(perm,perm+length));
    delete [] perm;
    return best;
}

int main(){
    freopen("haywire.in","r",stdin);
    freopen("haywire.out","w",stdout);
    scanf("%d",&num);
    set<int> all;
    for(int x = 0;x<num;x++){
        all.insert(x);
        scanf("%d%d%d",&f[x][0],&f[x][1],&f[x][2]);
    }
    for(int y = 0;y<num;y++){
        for(int x = 0;x<3;x++){
            f[y][x]--;
        }
    }
    ret done = divide(all,0,num);
    printf("%d\n",done.A);

    return 0;
}
