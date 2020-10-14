#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;
int N,M;
typedef pair<int,int>pi;
#define MAX 987654321
vector<string>s;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);	
	cin>>N>>M;
	
	int i,j;
	string str;

	for (i=0;i<N;i++)
	{
		cin>>str;
		s.push_back(str);
	}
	int count=0;
	set<string>st;
	vector<string>v;
	for (j=0;j<M;j++)
		{
			string temp="";
			for (i=0;i<N;i++)
			{
				temp=temp+s[i][j];
			}
			v.push_back(temp);
		}
	while(1)
	{
		
		int flag=0;
		for (i=0;i<v.size();i++)
		{
			v[i].erase(0,1);
		}
		set<string>st;
		for (i=0;i<v.size();i++)
		{
			if (st.find(v[i])==st.end())
				st.insert(v[i]);
				else
				{
					flag=1;
					break;
				}
		}
		if(flag)
			break;
		count++;
		if (count>=N)
			break;
	}
	cout<<count;
}

