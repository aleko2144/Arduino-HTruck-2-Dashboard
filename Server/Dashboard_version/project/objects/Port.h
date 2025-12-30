#ifndef PORT_H
#define PORT_H

#include <windows.h>
#include <iostream>

class Port{
private:
    HANDLE hPort;
    LPCTSTR sPortName;
    DCB dcbSerialParams;
public:
    bool isOpened;
    Port();
    ~Port();
    void Open();
    void Close();
    void Write(char* data, int dataSize);
    void Read();
};

#endif

