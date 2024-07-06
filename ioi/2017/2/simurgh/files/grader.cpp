#include "simurgh.h"

#include <cstdio>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

static int MAXQ = 30000;

static int n, m, q = 0;
static vector<int> u, v;
static vector<bool> goal;
static vector<int> parent;

static int find(int node) {
	return (parent[node] == node ? node : parent[node] = find(parent[node]));
}

static bool merge(int v1, int v2) {
	v1 = find(v1);
	v2 = find(v2);
	if (v1 == v2)
		return false;
	parent[v1] = v2;
	return true;
}

static void wrong_answer() {
	printf("NO\n");
	exit(0);
}

static bool is_valid(const vector<int>& r) {
	if(int(r.size()) != n - 1)
		return false;

	for(int i = 0; i < n - 1; i++)
		if(r[i] < 0 || r[i] >= m)
			return false;

	parent.resize(n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n - 1; i++) {
		if (!merge(u[r[i]], v[r[i]])) {
			return false;
		}
	}
	return true;
}

static int _count_common_roads_internal(const vector<int>& r) {
	if (!is_valid(r))
		wrong_answer();

	int common = 0;
	for(int i = 0; i < n - 1; i++) {
		bool is_common = goal[r[i]];
		if (is_common)
			common++;
	}

	return common;	
}

int count_common_roads(const vector<int>& r) {
	q++;
	if(q > MAXQ)
		wrong_answer();

	return _count_common_roads_internal(r);
}

int main() {
	assert(2 == scanf("%d %d", &n, &m));
	assert(1 == scanf("%d", &MAXQ));

	u.resize(m);
	v.resize(m);

	for(int i = 0; i < m; i++)
		assert(2 == scanf("%d %d", &u[i], &v[i]));

	goal.resize(m, false);

	for(int i = 0; i < n - 1; i++) {
		int id;
		assert(1 == scanf("%d", &id));
		goal[id] = true;
	}

	vector<int> result = find_roads(n, u, v);

	if(_count_common_roads_internal(result) != n - 1)
		wrong_answer();
		
    printf("OK\n");
	for(int i = 0; i < (int)result.size(); i++){
		if(i)
			printf(" ");
		printf("%d", result[i]);
	}
	printf("\n");

	return 0;
}

