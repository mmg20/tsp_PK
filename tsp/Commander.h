#pragma once
#include <vector>
#include <string>

using namespace std;

class Commander
{
	public:
		Commander(int, char*[]);
		string getParameter(string, string);
	private:
		vector<string> tokens;
		string getCmdOption(string);
		bool cmdOptionExists(string);
};

