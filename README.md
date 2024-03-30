## 项目说明

DLL项目，用于二进制字符串替换



## 开发环境

Windows 10 x64

VC++ 2017



## 使用说明

### 函数

binstr_replace

### 参数

| 参数名称  | 参数类型 | 必填 | 描述     |      |
| --------- | -------- | ---- | -------- | ---- |
| file_path | char*    | Y    | 文件路径 |      |
| old_str   | char*    | Y    | 原字符串 |      |
| new_str   | char*    | Y    | 新字符串 |      |

### 返回

| 参数名称  | 参数类型 | 描述               |
| --------- | -------- | ------------------ |
| data_size | int      | 处理后的字符串个数 |
|           |          |                    |
|           |          |                    |



## 编译说明

cl /LD /EHsc binstr_replace.cpp



## 文件说明

| 文件名             | 描述                |      |
| ------------------ | ------------------- | ---- |
| binstr_replace.cpp | 项目源文件          |      |
| binstr_replace.h   | 项目头文件          |      |
| binstr_replace.ahk | autohotkey 调用示例 |      |
| binstr_replace.dll | dll接口文件         |      |

