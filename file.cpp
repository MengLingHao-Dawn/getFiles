#include "file.h"
#include <io.h>

File::File() {

}

File::~File() {

}

/// <summary>
/// ��ȡĳ·���µ������ļ�
/// </summary>
/// <param name="path">Ҫ��ѯ��·��</param>
/// <param name="files">�洢�ļ���·��������</param>
/// <param name="ownName">�洢�ļ�������</param>
void File::getFiles(string path, vector<string>& files, vector<string>& ownName) {
	// �ļ����
	long hFile = 0;
	// �ļ���Ϣ
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
		do
		{
			// �����Ŀ¼������֮
			// ������ǣ������б�
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