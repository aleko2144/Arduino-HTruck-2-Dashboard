#include "core.h"

Vehicle Car;

char data[21];
int data_size = 21;

Port COM;

int prev_count = 0;

bool port_state;
bool port_lock = true;

int km_total;  //общий пробег автомобиля, кроме того, эта переменная использутся для расчётов
float km_total_prev;
float km_local;  //текущий (суточный) пробег автомобиля, который можно сбросить
int km_total_nums[6]; //общий пробег, но каждая цифра по отдельности
int km_local_nums[5]; //текущий пробег, но каждая цифра по отдельности

int keyConnect;
int keyResetKM;

int ValueToServo(float input_value, float value_max, float deg_max){
    int result;

    if (input_value > value_max){
        input_value = value_max;
    }

    if (input_value < 0){
        input_value = 0;
    }

    //0.0 ... 1.0, насколько повёрнута стрелка к макс. значению
    float value_coeff = (input_value / value_max);

    //float deg_coeff = (rotation_coeff * deg_max) / servo_max_deg; //360.0; //0...1, насколько угол близок к 360 градуса
    //result = 180 * deg_coeff;

    result = deg_max * value_coeff;

    return result;
}

void prepare_kilometrage(){
    km_total = Car.m_kilometrage / 1000; //983041; //общий километраж
    km_local += (Car.m_kilometrage - km_total_prev) / 1000.0;
    km_total_prev = Car.m_kilometrage;

    for (int i = 5; i >= 0; i--){
        km_total_nums[i] = km_total % 10;
        km_total /= 10;
    }

    km_total = km_local; //суточный километраж

    for (int i = 3; i >= 0; i--){
        km_local_nums[i] = km_total % 10;
        km_total /= 10;
        //std::cout << km_total_nums[i] << " ";
        //std::cout << km_local_nums[i] << " ";
    }
    km_local_nums[4] = (km_local - (int)km_local) * 10; //десятичный разряд

    //std::cout << std::endl;
    //std::cout << km_total_nums[0] + km_total_nums[1] * 10 << " ";
    //std::cout << km_total_nums[2] + km_total_nums[3] * 10 << " ";
    //std::cout << km_total_nums[4] + km_total_nums[5] * 10 << std::endl;
    //std::cout << "|" << Car.m_kilometrage << std::endl;

}

void TimedProcess(int execute_time_ms){
    if ((GetTickCount() - prev_count) >= execute_time_ms){

        prev_count = GetTickCount();
        prepare_kilometrage();

        data[0] = 232;
        data[1] = 10 + ValueToServo(Car.m_speed, 140, 170);
        data[2] = 180 - ValueToServo(Car.m_rpm, 30, 180);
        data[3] = Car.m_currentGear;
        data[4] = 10 + (95 * Car.m_fuelLevel);
        data[5] = 255 * Car.m_damageLevel;
        data[6] = Car.m_lightsState;
        data[7] = Car.m_handbrakeState;
        data[8] = 0;  //указатели поворота
        //пробег общий
        data[9]  = km_total_nums[0];
        data[10] = km_total_nums[1];
        data[11] = km_total_nums[2];
        data[12] = km_total_nums[3];
        data[13] = km_total_nums[4];
        data[14] = km_total_nums[5];
        //пробег дневной
        data[15] = km_local_nums[0];
        data[16] = km_local_nums[1];
        data[17] = km_local_nums[2];
        data[18] = km_local_nums[3];
        data[19] = km_local_nums[4];

        data[20] = 210; //проверочное число

        if (!port_state){
            COM.Open();
            port_state = true;
        }

        COM.Write(data, data_size);
    }
}

namespace Core
{
    void Prepare(HANDLE hProcess){
        COM.Close();
        keyConnect = GetPrivateProfileIntA("keybindings", "key_connect", 0x79, ".\\server.cfg");
        keyResetKM = GetPrivateProfileIntA("keybindings", "key_resetKM", 0x7A, ".\\server.cfg");
    }
    void Update(HANDLE hProcess){
        Car.Prepare(hProcess);
        Car.Update(hProcess);

        if (!port_lock){
            TimedProcess(50); //50 | 10 //70 | 25
        }

        if (IsKeyJustPressed(keyConnect)){ //F10
            COM.Close();
            port_state = false;
            port_lock = !port_lock;

        }

        if (IsKeyJustPressed(keyResetKM)){ //F11
            km_local = 0;
        }
    }
}
