// PureBlue.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "All.h"
#include <ctime>
#include <future>

using namespace std;

int main()
{
	All test;
	vector <vector<string>> check;
	struct thread_args { string filesname, filename; };
	thread t[50];
	check = test.parser();
	for (int i = 0; i < check.size(); i++)
	{
		thread_args th;
		th.filesname = check[i][0];
		th.filename = check[i][1];
		for(int k = 0; k < 50; k++)
		{
			t[k] = thread(&All::downloader, test, check[k+i][0], check[k+i][1]);
			if (k == 49) t[k].join();
			else t[k].detach();
			i++;
			
		}

		//future<void> download1 = async(std::launch::async, &All::downloader, test, check[i][0], check[i][1]);
	}
	test.downloader(check[6][0], check[6][1]);
}

