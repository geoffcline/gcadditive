// additive1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

void additivenumbers(const int &min, const int &max);
bool checkadditive(const int &inp);
bool intsegment(const string ins, const int v1, const int v2);

int main()
{
	string x;
	additivenumbers(0, 1000000);


	cout << "fin." << endl;
	cin >> x;

	return 0;
}

void additivenumbers(const int &min, const int &max)
{
	ofstream fout;
	fout.open("test1.txt");

	for (int i = min; i <= max; i++)
	{
		if (checkadditive(i))
		{
			fout << i << endl;
			cout << i << endl;
		}
	}

	fout.close();
}

bool checkadditive(const int &inp)
{
	string ins = to_string(inp);
	unsigned int j, tv;
	bool ltest;
	stack<int> possible;

	for (unsigned int i = 1; i < ins.length()/2; i++)
	{
		j = 0;
		ltest = true;
		while (j < i && ltest)
		{
			if (ins[j] != ins[i + j])
				ltest = false;
			j++;
		}
		if (ltest)
			possible.push(i);
			
	}

	while (!possible.empty())
	{
		j = possible.top();
		possible.pop();
		tv = stoi(ins.substr(0, j));
		return intsegment(ins.substr(j*2), tv, tv);
	}

	return false;
}

bool intsegment(const string ins, const int v1, const int v2)
{
	int target = v1 + v2;
	string starget = to_string(target);
	for (unsigned int i = 1; i <= ins.length(); i++)
	{
		if (ins.substr(0, i) == starget)
		{
			if (i == ins.length())
				return true;
			else
				return intsegment(ins.substr(i), v2, target);
		}
			
	}

	return false;
}