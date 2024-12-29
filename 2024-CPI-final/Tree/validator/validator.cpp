#include <numeric>
#include "testlib.h"
using namespace std;

const int MAXN = 100'000;
const int MAXW = 1'000;

struct Dsu {
	vector<int> fa;
	Dsu(int n): fa(n) {
		iota(fa.begin(), fa.end(), 0);
	}
	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	void unite(int x, int y) {
		fa[find(y)] = find(x);
	}
};

int main() {
	registerValidation();

	int n = inf.readInt(1, MAXN, "n");
	inf.readEoln();

	Dsu dsu(n);
	for (int i = 0; i < n - 1; ++ i) {
		int a = inf.readInt(1, n, "a") - 1;
		inf.readSpace();
		int b = inf.readInt(1, n, "b") - 1;
		inf.readSpace();
		inf.readInt(-MAXW, MAXW, "w");
		inf.readEoln();
		ensure(dsu.find(a) != dsu.find(b));
		dsu.unite(a, b);
	}

	inf.readEof();

	return 0;
}
