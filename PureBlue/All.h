#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <urlmon.h>
#include <tchar.h>
#include <atlbase.h>
#include <algorithm>
#include <stdlib.h> 
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"wininet.lib")


using namespace std;
class All
{
public:
	//standard constructor
	All();
	//vector of symbol names and original company names
	vector <vector <string>> sname;
	//function used to read symbol names from .txt file
	vector <string> read();
	//function used to parse data read from file into sname vector
	vector <vector <string>> parser();
	//function downloading single file
	void downloader(string, string);



	virtual ~All();
};

