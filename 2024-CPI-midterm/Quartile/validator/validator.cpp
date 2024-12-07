#include "testlib.h"
using namespace std;

const int MAXN = 100'000;
const int MAXA = 1'000'000'000;

int main() {
	registerValidation();

	int n = inf.readInt(1, MAXN, "n");
	inf.readEoln();
	
	for (int i = 0; i < n; ++ i) {
		inf.readInt(1, MAXA);
		inf.readEoln();
	}

	inf.readEof();

	return 0;
}
