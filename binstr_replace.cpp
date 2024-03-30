#include "binstr_replace.h"
#include <iostream>
#include <fstream>
#include <string>

int binstr_replace(const char* file_path, const char* old_str, const char* new_str) {
	// ��һ���������ļ�(�����ļ�������)
	std::ifstream file(file_path, std::ios::binary);
	if (!file.is_open()) {
		std::cerr << "Can't open file: " << file_path << std::endl;
		return -1;
	}

	// ��ȡ�ļ�����(�����ļ�������)���ַ���
	std::string data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();

	// �滻���ַ���Ϊ���ַ���
	size_t pos = 0;
	while ((pos = data.find(old_str, pos)) != std::string::npos) {
		data.replace(pos, strlen(old_str), new_str);
		pos += strlen(new_str);
	}

	// ������������д���ļ�(����ļ�������)
	std::ofstream outfile(file_path, std::ios::binary);
	if (!outfile.is_open()) {
		std::cerr << "Error writing to file: " << file_path << std::endl;
		return -1;
	}

	// д�봦��������
	outfile.write(data.c_str(), data.size());
	// �ر��ļ�
	outfile.close();

	// ���ش������ַ�������
	return data.size();
}