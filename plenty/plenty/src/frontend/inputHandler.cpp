#include "include/frontend/inputHandler.h"

#include <iostream>
#include <string>

InputHandler::InputHandler()
	: isRunning(true), isPriv(false)
{

}

void InputHandler::handleInput()
{

}


// command function implementations
void InputHandler::ping()
{
	std::cout << "pong!" << std::endl;
}