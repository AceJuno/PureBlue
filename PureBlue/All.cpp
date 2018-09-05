#include "pch.h"
#include "All.h"

using namespace std;

All::All()
{
}

vector <string> All::read()
{
	vector <string> read_from_file;
	ifstream mf;
	string line;
	mf.open("NASDAQ.txt");
	while (getline(mf, line))
	{
		read_from_file.push_back(line);
	}
	mf.close();
	return read_from_file;
}

vector <vector <string>> All::parser()
{
	vector <string> input = this->read();
	vector <vector <string>> temp;
	
	for (int i = 0; i < input.size(); i++) 
	{
		vector <string> init;
		string sname, name, line;
		int counter = 0;
		line = input[i];
		char sep = '\t';
		for (int k = 0; k < line.size(); k++)
		{
			counter++;
			if (line[k] == sep) break;
			else sname += line[k];
		}
		init.push_back(sname);

		for (counter; counter < line.size(); counter++)
		{
			 name += line[counter];
		}
		init.push_back(name);
		temp.push_back(init);
	}
	return temp;
}

void All::downloader(string input_sname,string input_name)
{
	string file_name = "D:\\data\\" + input_name + ".csv";
	transform(input_name.begin(), input_name.end(), input_name.begin(), ::toupper);
	string input_url = "http://markets.financialcontent.com/stocks/action/gethistoricaldata?Month=12&Symbol=" + input_sname + "&Range=400&Year=2018";
	USES_CONVERSION;
	HRESULT hr;
	LPCSTR Url = input_url.c_str(), File = file_name.c_str();
	LPCTSTR new_url = A2W(Url), new_file = A2W(File);
	hr = URLDownloadToFile(0, new_url, new_file, 0, 0);
	switch (hr)
	{
	case S_OK:
		cout << "Successful download of " << input_name <<endl;
		break;
	case E_OUTOFMEMORY:
		cout << "Out of memory error" << endl;
		break;
	case INET_E_DOWNLOAD_FAILURE:
		cout << "Cannot access server data" << endl;
		break;
	default:
		cout << "Unknown error" << endl;
		break;
	}

}


All::~All()
{
}
