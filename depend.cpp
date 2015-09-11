#include <cstdio>




string dependencies(map<string,vector<string> > depend, string root, map<string,bool>& isCurVisit, map<string, bool>& didPrint){ //recursively do it
	if(didVisit[root]) return NULL;

	didVisit[root] = true;

	string ans = "";
	for(int x = 0;x<depend[root].length();x++){
		string next = dependencies(depend, depend[root][x]);
		if(next==NULL) return NULL;
		ans+= next;
	}
	ans+=root;
	ans+="\n";
	didVisit[root] = false;
	return ans;
}

//so originally without didVisit, but cycles.
