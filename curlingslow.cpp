#include <cstdio>
#include <cmath>
#include <algorithm>

#define MAX 100000
#define A first
#define B second

using namespace std;
typedef long double ld;
typedef pair<ld,ld> pii;

int hull[MAX];
ld angle[MAX];
int s = 0, e = 0;
int red = 0;
int blue = 0;
ld left,right,up,down;

pii temp[MAX];
pii pnt[MAX];
pii other[MAX];
int num;
const ld PI = 3.14159265358979;
const ld LARGE = 50000;

pii mid;

ld A(pii in){ return atan2(in.B-mid.B,in.A-mid.A);} // return the A this point makes with middle
int comp(pii one,pii two){ return A(one)<A(two);} //comparator

void swap(){
    for(int x = 0;x<num;x++){
        temp[x] = pnt[x];
        pnt[x] = other[x];
        other[x] = temp[x];
    }
}

ld cross(pii one, pii two){
    return one.A*two.B-one.B*two.A;
}
ld cross(int one, int two, int thr){ return (pnt[two].A-pnt[one].A)*(pnt[thr].B-pnt[one].B)-(pnt[two].B-pnt[one].B)*(pnt[thr].A-pnt[one].A);}
//cross product
//negative if right turn
//positive if left turn
//return 0 if collinear

void build(){// built the hull
    right = -LARGE;
    left = LARGE;
    up = -LARGE;
    down = LARGE;
    mid = pii(0,0);
    for(int x = 0;x<num;x++){
        mid.A+=pnt[x].A;
        mid.B+=pnt[x].B;
    }
    mid.A/=num;
    mid.B/=num;
    sort(pnt,pnt+num,comp);
    hull[0] = 0;
    hull[1] = 1;
    e = 2;
    for(int x = 2;x<num;x++){
        while(e>s+1&&cross(hull[e-2],hull[e-1],x)<=0) e--;
        hull[e++] = x;
    }
    bool flag = true;
    while(flag){
        flag = false;
        while(e>s+1&&cross(hull[e-2],hull[e-1],hull[s])<=0){
            e--;
            flag = true;
        }
        while(e>s+1&&cross(hull[e-1],hull[s],hull[s+1])<=0){
            s++;
            flag = true;
        }
    }
    for(int x = s;x<e;x++){
        angle[x] = A(pnt[hull[x]]); 
    }
    for(int x = 0;x<num;x++){
        if(pnt[x].A>right) right = pnt[x].A;
        if(pnt[x].A<left)  left  = pnt[x].A;
        if(pnt[x].B>up) up = pnt[x].B;
        if(pnt[x].B<down) down = pnt[x].B;
    }
    hull[e] = hull[s];//wrap around
    angle[e] = A(pnt[hull[s]])+2*PI;
    for(int x = s;x<e;x++){
    //    printf("%Lf %Lf\n",pnt[hull[x]].A,pnt[hull[x]].B);
    }
//    printf("%Lf %Lf %Lf %Lf\n",left,right,up,down);
}
bool same(pii one, pii two, pii first, pii sec){
    pii BA = pii(sec.A-first.A,sec.B-first.B);
    pii CA = pii(one.A-first.A,one.B-first.B);
    pii DA = pii(two.A-first.A,two.B-first.B);
    return cross(BA,CA)*cross(BA,DA)>=0;
}

bool tri(pii cur,pii bot,pii top){
    pii average = pii((mid.A+bot.A+top.A)/3,(mid.B+bot.B+top.B)/3);
    return same(average,cur,bot,top)&&same(average,cur,mid,top)&&same(average,cur,bot,mid);
}


bool query(pii cur){//check if point is within hull
    if(cur.A>right||cur.A<left||cur.B>up||cur.B<down) return false;
    for(int x = s;x<e;x++){
        if(!same(mid,cur,pnt[hull[x]],pnt[hull[x+1]])) return false;
    }
    return true;
}
void print(pii in){
    printf("%Lf %Lf\n",in.A,in.B);
}

int main(){
    freopen("curling.in","r",stdin);
    freopen("curling.out","w",stdout);
    scanf("%d",&num);
    int a,b;
    for(int x = 0;x<num;x++){
        scanf("%d%d",&a,&b); 
        pnt[x] = pii(a,b);
    }
    for(int x = 0;x<num;x++){
        scanf("%d%d",&a,&b); 
        other[x] = pii(a,b);
    }
    build();
    for(int x = 0;x<num;x++) if(query(other[x])) red++;        
    swap();
    build();
    for(int x = 0;x<num;x++) if(query(other[x])) blue++;
    printf("%d %d\n",red,blue); 
}
