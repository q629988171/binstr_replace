#pragma once

#ifndef  BINSTR_REPLACE_H
#define  BINSTR_REPLACE_H

#ifdef __cplusplus
extern "C" {
#endif

	__declspec(dllexport) int binstr_replace(const char* file_path, const char* old_str, const char* new_str);

#ifdef __cplusplus
}
#endif

#endif //  BINSTR_REPLACE_H