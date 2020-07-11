#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
int N,K;
deque<char> dq;
char s[500001];
int main()
{
	cin >>N>>K;
	scanf("%s",s);
	int i;
	for (i=0;i<N;i++)
	{
		while(K&&!dq.empty()&&dq.back()<s[i])
		{
			dq.pop_back();
			K--;
		}
		dq.push_back(s[i]);
	}
	
	for (i=0;i<dq.size()-K;i++)
	{
		cout<<dq[i];
	}
}

