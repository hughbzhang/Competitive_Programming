#include <cstdio>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>

#define A first
#define B second
#define MAXN 100100

using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

class data{
	public:
		vector<piii> left;
		vector<piii> right;
		vector<piii> both;
		data(){

		}
};


pii loc[MAXN];
int N;
map<pii,bool> m;

/*void print(data in){
	cout << "LEFT\n";
	for(int x = 0;x<in.left.size();x++){
		cout << in.left[x] << endl;
	}
	cout << "RIGHT" << endl;
	for(int x = 0;x<in.right.size();x++){
		cout << in.right[x] << endl;
	}
}*/


data split(int start, int end){ //needR and needL are what you need to break the barrier ALL THE WAY ON THE LEFT OR RIGHT
	//cout << start << " " << end << endl;
	

	if(end<=start) return data(); //nothing here

	if(end==start+1){
		data cur = data();
		int pw = loc[end].A-loc[start].A;
		if(pw>loc[start].B) cur.left.push_back(piii(pw,pii(start,end)));
		if(pw>loc[end].B) cur.right.push_back(piii(pw,pii(start,end)));
		if(pw>loc[start].B&&pw>loc[end].B) cur.both.push_back(piii(pw,pii(start,end)));
		return cur;
	}


	int mid = start+(end-start)/2;
	data one = split(start,mid);
	data two = split(mid,end);
	
	int bigL = -1;
	int bigR = -1;
	for(int x = mid-1;x>=start;x--)	bigL = max(loc[x].B-(loc[mid].A-loc[x].A),bigL);
	for(int x = mid+1;x<=end;x++) bigR = max(loc[x].B-(loc[x].A-loc[mid].A),bigR);

	data cur = data();
	for(int x = 0;x<one.right.size();x++){
		if(one.right[x].A>bigR) cur.right.push_back(piii(one.right[x].A+loc[end].A-loc[mid].A,one.right[x].B));
		if(one.right[x].A>bigR&&one.right[x].A>bigL) cur.both.push_back(piii(loc[end].A-loc[start].A,one.right[x].B));
	}

	for(int x = 0;x<two.left.size();x++){
		if(two.left[x].A>bigL) cur.left.push_back(piii(two.left[x].A+loc[mid].A-loc[start].A,two.left[x].B));
		if(two.left[x].A>bigR&&two.left[x].A>bigL) cur.both.push_back(piii(loc[end].A-loc[start].A,two.left[x].B));
	}

	for(int x = 0;x<one.both.size();x++){
		if(one.both[x].A>bigR&&one.both[x].A>bigL) cur.both.push_back(piii(loc[end].A-loc[start].A,one.both[x].B));
		else{
			if(one.both[x].A>bigR) cur.right.push_back(piii(loc[end].A-loc[mid].A+one.both[x].A,one.both[x].B));
			if(one.both[x].A>bigL) cur.left.push_back(piii(loc[mid].A-loc[start].A+one.both[x].A,one.both[x].B));
		}
	}

	for(int x = 0;x<two.both.size();x++){
		if(two.both[x].A>bigR&&two.both[x].A>bigL) cur.both.push_back(piii(loc[end].A-loc[start].A,two.both[x].B));
		else{

			if(two.both[x].A>bigR) cur.right.push_back(piii(loc[end].A-loc[mid].A+two.both[x].A,two.both[x].B));
			if(two.both[x].A>bigL) cur.left.push_back(piii(loc[mid].A-loc[start].A+two.both[x].A,two.both[x].B));
		
		}
	}

	for(int x = 0;x<one.left.size();x++) cur.left.push_back(one.left[x]);
	for(int x = 0;x<two.right.size();x++) cur.right.push_back(two.right[x]);


	return cur;


}




/*
	int nextL = max(-1,loc[start].B-(loc[mid].A-loc[start].A));// how much extra room you need
	int nextR = max(-1,loc[end].B-(loc[end].A-loc[mid].A));
	int bonusR = loc[mid+1].A-loc[mid].A;
	int bonusL = loc[mid].A-loc[mid-1].A;
*/

int main(){
	freopen("trapped.in","r",stdin);
	freopen("trapped.out","w",stdout);
	cin >> N;
	for(int x = 0;x<N;x++){
		int a,b;
		cin >> a >> b;
		loc[x] = pii(b,a);
	}
	sort(loc,loc+N);
	data in = split(0,N-1);
	int total = loc[N-1].A-loc[0].A;
	int RIGHT = 0;
	int LEFT = 0;
	int BOTH = 0;

	for(int x = 0;x<in.left.size();x++){
		//cout << (in.left[x].B.B-in.left[x].B.A) << " s";
		if(m[in.left[x].B]) continue;
		m[in.left[x].B] = true;
		total-=(loc[in.left[x].B.B].A-loc[in.left[x].B.A].A);
	}
	for(int x = 0;x<in.right.size();x++){
		//cout<< (in.right[x].B.B-in.right[x].B.A) << " s";
		if(m[in.right[x].B]) continue;
		m[in.right[x].B] = true;
		total-=(loc[in.right[x].B.B].A-loc[in.right[x].B.A].A);
	}

	for(int x = 0;x<in.both.size();x++){
		if(m[in.both[x].B]) continue;
		m[in.both[x].B] = true;
		total-=(loc[in.both[x].B.B].A-loc[in.both[x].B.A].A);
	}

	cout << total << endl;
	//cout << total << " " << RIGHT << " " << LEFT << " " << BOTH << endl;

	//cout << ans.A.A << " " << ans.A.B << " " << ans.B << endl;
	//cout << total-(ans.A.A+ans.A.B-ans.B) << endl;
}
