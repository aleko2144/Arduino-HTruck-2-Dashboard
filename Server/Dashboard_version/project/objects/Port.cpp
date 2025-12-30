#include "Port.h"

//https://blablacode.ru/programmirovanie/392
//https://ru.wikibooks.org/wiki/COM-%D0%BF%D0%BE%D1%80%D1%82_%D0%B2_Windows_(%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5)#%D0%9F%D1%80%D0%B8%D0%BC%D0%B5%D1%80_%D0%BE%D1%82%D0%BA%D1%80%D1%8B%D1%82%D0%B8%D1%8F/%D0%B7%D0%B0%D0%BA%D1%80%D1%8B%D1%82%D0%B8%D1%8F_%D0%BD%D0%B0_%D1%8F%D0%B7%D1%8B%D0%BA%D0%B5_C
Port::Port(){
    isOpened = false;
};

Port::~Port(){
};

void Port::Open(){
    if (!isOpened){
        CloseHandle(hPort); //если ранее порт был открыт

        char* returnedString = new char[256];
        GetPrivateProfileStringA("common", "port", "COM1", returnedString, 256, ".\\server.cfg");

        sPortName = LPCTSTR(returnedString);
        //sPortName = LPCTSTR("COM3"); //COM3
        hPort = CreateFile(sPortName,GENERIC_READ | GENERIC_WRITE,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);

        //dcbSerialParams = {0};

        if (hPort == INVALID_HANDLE_VALUE) {
            //MessageBox(NULL, "Failed to open port / Не удалось открыть порт", "Error / Ошибка", MB_OK);
            std::cout << "Failed to open port " << sPortName << std::endl;
            return;
        }

        dcbSerialParams.DCBlength=sizeof(dcbSerialParams);

        if (!GetCommState(hPort, &dcbSerialParams))
        {
            //MessageBox(NULL, "Failed to get port params / Ошибка получения параметров порта", "Error / Ошибка", MB_OK);
            std::cout << "Failed to get port " << sPortName << " params" << std::endl;
            return;
        }

        dcbSerialParams.BaudRate=CBR_115200; //CBR_9600; //115200
        dcbSerialParams.ByteSize=8;
        dcbSerialParams.StopBits=ONESTOPBIT;
        dcbSerialParams.Parity=NOPARITY;

        if(!SetCommState(hPort, &dcbSerialParams))
        {
            //MessageBox(NULL, "Failed to set port params / Ошибка установки параметров порта", "Error / Ошибка", MB_OK);
            std::cout << "Failed to set port " << sPortName << " params" << std::endl;
            return;
        }

        std::cout << "Connected to " << sPortName << std::endl;
        isOpened = true;
    }
};

void Port::Close(){
    if (isOpened){
        CloseHandle(hPort);

        std::cout << "Disconnected from " << sPortName << std::endl;
        isOpened = false;
    }
};

//https://blablacode.ru/programmirovanie/392
void Port::Write(char* data, int dataSize){
    DWORD dwSize = dataSize;
    DWORD dwBytesWritten;

    BOOL iRet = WriteFile(hPort, data, dwSize, &dwBytesWritten, NULL);

}

void Port::Read(){
    DWORD iSize;
    char sReceivedChar;
    int counter = 0;
    while(counter <= 4) {
        ReadFile(hPort, &sReceivedChar, 1, &iSize, 0);  // получаем 1 байт
        if(iSize > 0){   // если что-то принято, выводим
            std::cout << sReceivedChar;
            counter++;
        }
    }
    std::cout << std::endl;
}
