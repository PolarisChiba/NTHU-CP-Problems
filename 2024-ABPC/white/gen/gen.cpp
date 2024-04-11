#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	
    int n = atoi(argv[1]);
	println(n);

    vector<int> v(n);
    for (auto &i : v) i = rnd.next(1, 1'000'000'000);
    println(v);
}
