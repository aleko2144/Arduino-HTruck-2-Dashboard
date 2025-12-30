#include <iostream>
#include "windows.h"

#include "project/core/core.h"

using namespace std;

HANDLE hProcess;
int ViewerPtr;
int ViewerPtrVal_old;
int ViewerPtr_current;

void Process(){
    ReadProcessMemory(hProcess, (LPVOID)0x6D2098, &ViewerPtr_current, sizeof(ViewerPtr), 0); // читаем наш адресс из памяти

    if (ViewerPtr_current && ViewerPtrVal_old != ViewerPtr_current && ViewerPtr_current) { //если указатель не пустой и указатели разные
        //cout << "Viewer pointer updated / Указатель на Viewer обновлён" << endl;
        cout << "Player data found\nОбнаружены данные игрока\n\n" << endl;

        cout << "Waiting for user's command to connect to device\nОжидание команды пользователя на подключение к панели\n\n" << endl;

        ReadProcessMemory(hProcess, (LPVOID)0x6D2098, &ViewerPtr, sizeof(ViewerPtr), 0); //ViewerPtr = (int*)0x6D2098;
        ViewerPtrVal_old = ViewerPtr;
        Core::Prepare(hProcess);
    } else {
        Core::Update(hProcess);
    }

    //if (IsKeyJustPressed(0x4E)){ //N
    //    std::cout << "ViewerPtr=" << *ViewerPtr << " | 0x6D2098=" << *(int*)0x6D2098 << std::endl;
    //}
}

//https://yougame.biz/threads/34648/
void FindEXE(){
    HWND hwnd = FindWindowA(NULL, "King of the Road");
    if (hwnd != NULL){
        DWORD ProcId; // Переменная хранящая в себе ID процесса
        GetWindowThreadProcessId(hwnd, &ProcId); // получение ID процесса
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcId); // handle будет открывать для вашей программы вход в окно (если что поправьте)

        if (ProcId != NULL){
            cout << "Connected to game, waiting...\nПодключение с игрой установлено, ожидание...\n\n" << endl;
            while(true){
                Process();
            }
        }
        else{
            cout << "Process not found\nПроцесс не обнаружен (игра не запущена?)\n\n" << endl;
            system("pause");
            exit(1);
        }
    } else {
        cout << "Window not found\nОкно игры не найдено (игра не запущена?)\n\n" << endl;
        system("pause");
        exit(1);
    }
}

int main()
{
    setlocale(0, "");
    system("title dashboard-server");

    FindEXE();

    return 0;
}
