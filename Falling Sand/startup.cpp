#include "pch.h"

int height;
int width;


int worldheight;
int worldwidth;

void startup(bool& fullscreen)
{

	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();




	std::string choice = "d";

	std::cout << "Welcome to Falling Sand by Rick.\nStart with defaults: d\nStart in Fullscren: f\nStart with custom settings: c\n\nEnter Choice: ";
	std::cin >> choice;
	


	do
	{
		std::system("cls");

	if (choice == "d")
	{
		height = 1000;
		width = 1500;

		std::cout << "\nPlease enter pixelsize: ";
		std::cin >> pixelsize;

		worldheight = height / pixelsize;
		worldwidth = width / pixelsize;
		std::cout << "\nStartup Succesfull!\n\n\n\n\n";
		
		
	}
	if (choice == "f")
	{
		fullscreen = true;
		height=desktopMode.height;
		width=desktopMode.width;
		
		std::cout << "\nPlease enter pixelsize: ";
		std::cin >> pixelsize;


		worldheight = height / pixelsize;
		worldwidth = width / pixelsize;
		std::cout << "Creating Window with height: " << height << " and width: " << width;
		std::cout << "\n\nStartup Succesfull!\n\n\n\n\n";

	}
	if (choice == "c")
	{
		std::cout << "Enter width: ";
		std::cin >> width;
		std::cout << "Enter height: ";
		std::cin >> height;
		std::cout << "Enter Pixel Size: ";
		std::cin >> pixelsize;
		worldheight = height / pixelsize;
		worldwidth = width / pixelsize;
		std::cout << "\nStartup Succesfull!\n\n\n\n\n";

	}
	if (choice != "d" && choice != "f" && choice != "c")
	{
		std::cout << "Please enter a valid choice!";
		
	}
	} while (choice != "d" && choice != "f" && choice != "c");
	

	
}
