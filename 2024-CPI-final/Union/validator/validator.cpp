#include "testlib.h"
using namespace std;

const int MAXN = 200'000;
const int MAXX = 1'000'000;

int main() {
	registerValidation();

	int n = inf.readInt(1, MAXN, "n");
	inf.readEoln();

	map<pair<int, int>, int> cnt;
	for (int i = 0; i < n; ++ i) {
		int x1 = inf.readInt(-MAXX, MAXX, "x1");
		inf.readSpace();
		int x2 = inf.readInt(x1 + 1, MAXX, "x2");
		inf.readSpace();
		int val = inf.readInt(-1, 1, "val");
		inf.readEoln();

		ensure((val == 1 || val == -1));
		cnt[{x1, x2}] += val;
		// ensure((cnt[{x1, x2}] >= 0), "cnt");
	}

	inf.readEof();

	return 0;
}
