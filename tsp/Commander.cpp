#include "Commander.h"
#include <iostream>

Commander::Commander(int argc, char* argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		this->tokens.push_back(string(argv[i]));
	}
};

string Commander::getParameter(string parameterName, string description)
{
	try
	{
		if (!this->cmdOptionExists(parameterName) && this->getCmdOption(parameterName).empty())
			throw "File parameter [" + parameterName + "] invalid format. " + description;
	}

	catch (string msg)
	{
		cout << msg << endl;
	}

	return this->getCmdOption(parameterName);
}

string Commander::getCmdOption(string option) // -v 10
{
	vector<string>::iterator iterator;
	// przypisujemy do iteratora indeks miêdzy tokens[0 - tokens.size()-1] pod którym znajduje siê wartoœæ "option"
	iterator = find(this->tokens.begin(), this->tokens.end(), option);

	if (iterator != this->tokens.end() && ++iterator != this->tokens.end())
	{
		return *iterator;
	}

	return string("");
};

bool Commander::cmdOptionExists(string option)
{
	return find(this->tokens.begin(), this->tokens.end(), option) != this->tokens.end();
}