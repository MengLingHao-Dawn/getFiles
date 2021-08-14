#include "file.h"

int main() {
	string path = "D:\\C++Code\\File";
	vector<string> files;
	vector<string> ownName;
	File* file = new File();
	file->getFiles(path, files, ownName);

	// 迭代查询files和ownName
	cout << "文件路径：" << endl;
	for (int i = 0; i < files.size(); i++) {
		cout << files[i] << endl;
	}
	cout << endl << "文件名：" << endl;
	for (int i = 0; i < ownName.size(); i++) {
		cout << ownName[i] << endl;
	}

	system("pause");
	return 0;
}