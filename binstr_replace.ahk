#Persistent

; 调用DLL函数
binstr_replace(file_path, old_str, new_str) {
    ; 加载DLL
    hModule := DllCall("LoadLibrary", "Str", "binstr_replace.dll", "Ptr")

    ; 检查加载DLL是否成功
    if (ErrorLevel != 0) {
        MsgBox "Failed to load DLL"
        return -1
    }

    ; 获取函数地址
    fnAddress := DllCall("GetProcAddress", "Ptr", hModule, "AStr", "binstr_replace", "Ptr")

    ; 检查获取函数地址是否成功
    if (ErrorLevel != 0) {
        MsgBox "Failed to get function address"
        DllCall("FreeLibrary", "Ptr", hModule)
        return -1
    }

    ; 调用函数
    result := DllCall(fnAddress, "AStr", file_path, "AStr", old_str, "AStr", new_str, "Int")

    ; 释放DLL
    DllCall("FreeLibrary", "Ptr", hModule)

    ; 返回处理后的字符串长度
    return result
}

; 示例调用
file_path := "clipboard.bin"
old_str := "webp"
new_str := "helloworld"
result := binstr_replace(file_path, old_str, new_str)

; 输出结果
if (result != -1) {
    MsgBox % "处理后的字符串长度为：" result
} else {
    MsgBox "Failed to process clipboard"
}

ExitApp