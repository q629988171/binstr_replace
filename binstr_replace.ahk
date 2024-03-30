#Persistent

; ����DLL����
binstr_replace(file_path, old_str, new_str) {
    ; ����DLL
    hModule := DllCall("LoadLibrary", "Str", "binstr_replace.dll", "Ptr")

    ; ������DLL�Ƿ�ɹ�
    if (ErrorLevel != 0) {
        MsgBox "Failed to load DLL"
        return -1
    }

    ; ��ȡ������ַ
    fnAddress := DllCall("GetProcAddress", "Ptr", hModule, "AStr", "binstr_replace", "Ptr")

    ; ����ȡ������ַ�Ƿ�ɹ�
    if (ErrorLevel != 0) {
        MsgBox "Failed to get function address"
        DllCall("FreeLibrary", "Ptr", hModule)
        return -1
    }

    ; ���ú���
    result := DllCall(fnAddress, "AStr", file_path, "AStr", old_str, "AStr", new_str, "Int")

    ; �ͷ�DLL
    DllCall("FreeLibrary", "Ptr", hModule)

    ; ���ش������ַ�������
    return result
}

; ʾ������
file_path := "clipboard.bin"
old_str := "webp"
new_str := "helloworld"
result := binstr_replace(file_path, old_str, new_str)

; ������
if (result != -1) {
    MsgBox % "�������ַ�������Ϊ��" result
} else {
    MsgBox "Failed to process clipboard"
}

ExitApp