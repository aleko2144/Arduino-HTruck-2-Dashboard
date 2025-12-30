#ifndef VEHICLE_H
#define VEHICLE_H

#include <windows.h>
#include <iostream>

class Vehicle{
public:
    int m_Viewer;        //указатель на обозревателя
	int m_offset;        //указатель на машину игрока
	int m_task;          //параметры автомобиля
	int m_CarV;          //параметры из tech

	float m_speed_ms;    //скорость автомобиля игрока, м/с
	float m_speed;       //скорость либо в км/ч, либо в миль/ч
	float m_rpm;         //4...80
	float m_fuelLevel;   //0...1
	float m_damageLevel; //0...1
	float m_kilometrage; //пробег автомобиля
	int m_currentGear;   //текущая передача (0 - зх, 1 - нейтраль, 2 - первая и т.д.)
	int m_lightsState;   //0 - выкл., 1 - ближний, 2 - дальний
	int m_handbrakeState;

    Vehicle();
    ~Vehicle();
    void Prepare(HANDLE hProcess);
    void Update(HANDLE hProcess);
};

#endif
