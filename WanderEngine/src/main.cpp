// C++ Headers
#include <string>
#include <iostream>
#include "system\event.h"

void main()
{
	std::cout << sizeof(Wander::EventType::KEY_UP) << std::endl;
	std::cout << sizeof(Wander::EventType::KEY_DOWN) << std::endl;
	std::cout << sizeof(Wander::EventType::MOUSE_MOVE) << std::endl;
	std::cout << sizeof(Wander::EventType::MOUSE_WHEEL) << std::endl;
	std::cout << sizeof(Wander::EventType::MOUSE_BUTTON1_DOWN) << std::endl;
	std::cout << sizeof(Wander::EventType::MOUSE_BUTTON1_UP) << std::endl;
	std::cout << sizeof(Wander::EventType::MOUSE_BUTTON2_DOWN) << std::endl;
	std::cout << sizeof(Wander::EventType::MOUSE_BUTTON2_UP) << std::endl;
	std::cout << sizeof(Wander::EventType) << std::endl;

}