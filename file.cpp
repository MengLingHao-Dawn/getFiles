#include "file.h"
#include <io.h>

File::File() {

}

File::~File() {

}

/// <summary>
/// 获取某路径下的所有文件
/// </summary>
/// <param name="path">要查询的路径</param>
/// <param name="files">存储文件的路径和名称</param>
/// <param name="ownName">存储文件的名称</param>
void File::getFiles(string path, vector<string>& files, vector<string>& ownName) {
	// 文件句柄
	long hFile = 0;
	// 文件信息
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
		do
		{
			// 如果是目录，迭代之
			// 如果不是，加入列表
			if (fileinfo.attrib & _A_SUBDIR) {
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files, ownName);
				}
			}
			else {
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
				ownName.push_back(fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);
	}
}
