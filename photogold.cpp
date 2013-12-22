#include <fstream>
#include <algorithm>

#define MAX 1000

using namespace std;

int n,k,a[MAX],b[MAX];

int main()
{
	ifstream fin("photo.in");
	fin >> n >> k;
	for (int i=0; i<k; i++)
	{
		fin >> a[i] >> b[i];
		if (a[i]>b[i]) swap(a[i],b[i]);	// keep as a_i < b_i
	}
	fin.close();

	int cnt=0,left=1,right;
	do
	{
		right=n;
		// find the right end of the current photo
		for (int i=0; i<k; i++)
			// if two unfriendly cows are in the photo
			//    shrink the right end by excluding the cow on the right
			if (left<=a[i] && right>=b[i])
				right=b[i]-1;
		cnt++;
		left=right+1;	// the left end of the next photo starts from right+1
	}
	while (left<=n);

	ofstream fout("photo.out");
	fout << cnt << endl;
	fout.close();
}