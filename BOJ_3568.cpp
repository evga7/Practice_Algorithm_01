#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

char arr[200][200];
vector<string> v;
char arr2[200][200];
vector<string> v2;
int main()
{
int N;
string str;
getline(cin,str);
int i;
int j=0;
int k=0;
int q=0;
int w=0;
for (i=0;i<str.size();i++)
{
	if (str[i]==','||str[i]==';')
	continue;
	if (str[i]!=' ')
	arr[j][k++]=str[i];
	else
	{
		v.push_back(arr[j]);
		j++;
		k=0;
	}
	
}
v.push_back(arr[j]);
for (i=1;i<v.size();i++)
{
	int num;
	cout <<v[0];
	for (j=v[i].size()-1;j>0;j--)
	{
		if (v[i][j]=='['||v[i][j]==']')
		{
			cout<<"[]";
			j--;
		}
		else if (v[i][j]=='*'||v[i][j]=='&')
		cout<<v[i][j];
	}
	cout<<' ';
	for (j=0;j<v[i].size();j++)
	{
		if ((v[i][j]>='a'&&v[i][j]<='z')||(v[i][j]>='A'&&v[i][j]<='Z'))
			cout<<v[i][j];
			else
			{
				break;
			}
			
	}
	cout<<';'<<endl;
}

}
