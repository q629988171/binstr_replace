#include "binstr_replace.h"
#include <iostream>
#include <fstream>
#include <string>

int binstr_replace(const char* file_path, const char* old_str, const char* new_str) {
	// 打开一个二进制文件(输入文件流类型)
	std::ifstream file(file_path, std::ios::binary);
	if (!file.is_open()) {
		std::cerr << "Can't open file: " << file_path << std::endl;
		return -1;
	}

	// 读取文件内容(输入文件流类型)到字符串
	std::string data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();

	// 替换旧字符串为新字符串
	size_t pos = 0;
	while ((pos = data.find(old_str, pos)) != std::string::npos) {
		data.replace(pos, strlen(old_str), new_str);
		pos += strlen(new_str);
	}

	// 将处理后的数据写回文件(输出文件流类型)
	std::ofstream outfile(file_path, std::ios::binary);
	if (!outfile.is_open()) {
		std::cerr << "Error writing to file: " << file_path << std::endl;
		return -1;
	}

	// 写入处理后的数据
	outfile.write(data.c_str(), data.size());
	// 关闭文件
	outfile.close();

	// 返回处理后的字符串个数
	return data.size();
}