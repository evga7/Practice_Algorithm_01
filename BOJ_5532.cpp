#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	int L,A, B, C, D;
	cin >> L>> A >> B >> C >> D;
	
	while (1)
	{
		if (A <=0 && B <=0)
			break;
		A -= C;
		B -= D;
		L--;
	}
	cout << L;
}

