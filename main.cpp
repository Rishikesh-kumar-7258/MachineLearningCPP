#include <iostream>
#include "visualcpp/window.hpp"

int main()
{
	visualcpp::Window *window = new visualcpp::Window(500, 500, "My Window");

	std::cout << "Creating Window\n";
	bool running = true;
	while (running)
	{
		if (!window->processMessages())
		{
			std::cout << "Closing window\n";
			running = false;
		}
	}

	delete window;

	return 0;
}