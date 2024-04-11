#include "testlib.h"
using namespace std;

int main() {
	registerValidation();

	int n = inf.readInt(3, 200000, "n");
	inf.readEoln();
	
	for (int i = 0; i < n; ++ i) {
		inf.readInt(-1e9, 1e9, "x");
		inf.readSpace();
		inf.readInt(-1e9, 1e9, "y");
		inf.readEoln();
	}

	inf.readEof();

	return 0;
}
