#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double V, W;
	int D;
	scanf("%lf %lf %d", &V, &W, &D);
	double pos = 0;
	double op = 1;
	long long res = 0;
	while (1)
	{
		double t = W / V;
		pos += 5 * pow(t,2);
		if (pos >= D)
			break;
		V = V*8 / 10;
		res++;
	}
	printf("%lld", res);
}