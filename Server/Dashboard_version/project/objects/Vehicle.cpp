#include "Vehicle.h"

Vehicle::Vehicle(){
};

Vehicle::~Vehicle(){
};

void Vehicle::Prepare(HANDLE hProcess){
    ReadProcessMemory(hProcess, (LPVOID)0x6D2098, &m_Viewer, sizeof(m_Viewer), 0);
    ReadProcessMemory(hProcess, (LPVOID)(m_Viewer + 0x268), &m_offset, sizeof(m_offset), 0);
    ReadProcessMemory(hProcess, (LPVOID)(m_offset + 0x10), &m_task, sizeof(m_task), 0);
    ReadProcessMemory(hProcess, (LPVOID)(m_offset + 0x5460), &m_CarV, sizeof(m_CarV), 0);
    //ReadProcessMemory(hProcess, (LPVOID)(*(int *)m_Viewer + 0x268), &m_offset, sizeof(m_offset), 0);

	//m_offset = *(int *)(*(int *)m_Viewer + 0x268);
	//m_task = (m_offset + 0x10);

	//std::cout << "m_Viewer=" << m_Viewer << std::endl;
	//std::cout << "m_offset=" << m_offset << std::endl;
	//std::cout << "m_task=" << m_task << std::endl;
	//std::cout << "m_CarV=" << m_CarV << std::endl;
}

void Vehicle::Update(HANDLE hProcess){
    ReadProcessMemory(hProcess, (LPVOID)(m_CarV + 13100), &m_speed_ms, sizeof(m_speed_ms), 0);
    m_speed = m_speed_ms * 3.6;

    ReadProcessMemory(hProcess, (LPVOID)(m_offset + 20968), &m_rpm, sizeof(m_rpm), 0);
    m_rpm *= 0.60000002;

    ReadProcessMemory(hProcess, (LPVOID)(m_offset + 20988), &m_fuelLevel, sizeof(m_fuelLevel), 0);
    ReadProcessMemory(hProcess, (LPVOID)(m_offset + 20992), &m_damageLevel, sizeof(m_damageLevel), 0);
    ReadProcessMemory(hProcess, (LPVOID)(m_offset + 20980), &m_kilometrage, sizeof(m_kilometrage), 0);
    ReadProcessMemory(hProcess, (LPVOID)(m_offset + 20996), &m_currentGear, sizeof(m_currentGear), 0);
    ReadProcessMemory(hProcess, (LPVOID)(m_offset + 20920), &m_lightsState, sizeof(m_lightsState), 0);
    ReadProcessMemory(hProcess, (LPVOID)(m_offset + 21020), &m_handbrakeState, sizeof(m_handbrakeState), 0);
};
