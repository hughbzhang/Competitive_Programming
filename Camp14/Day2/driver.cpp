#include <cstdio>

void init(int n);
void make_parent(int parent, int child);
bool is_ancestor(int ancestor, int child);

int main() {
	FILE* fin = fopen("buildtree.in", "r");

	int n, q;
	fscanf(fin, "%d", &n);
	fscanf(fin, "%d", &q);

	init(n);
	bool is_bad = false;

	for (int i = 0; i < q; i++) {
		char c;
		do { c = fgetc(fin); } while (c != 'P' && c != 'Q');
		if (c == 'Q') {
			int a, b, intended;
			fscanf(fin, "%d %d %d", &a, &b, &intended);
			bool ans = is_ancestor(a, b);
			if (ans == (bool)intended) {
				printf("OK: is_ancestor(%d, %d) returned %s\n", a, b, intended ? "true" : "false");
			} else {
				is_bad = true;
				printf("BAD: is_ancestor(%d, %d) returned %s, expected %s\n", a, b, ans ? "true" : "false", intended ? "true" : "false");
			}
		} else {
			int a, b;
			fscanf(fin, "%d %d", &a, &b);
			make_parent(a, b);
			printf("OK: make_parent(%d, %d)\n", a, b);
		}
	}

	if (is_bad) {
		printf("BAD\n");
	} else {
		printf("ALL OK\n");
	}
	return 0;
}
