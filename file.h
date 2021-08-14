#pragma once

#include <vector>
#include <iostream>
using namespace std;

class File {
public:
	File();
	~File();
	void getFiles(string path, vector<string>& files, vector<string>& ownName);
};