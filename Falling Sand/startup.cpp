#include "pch.h"

int height;
int width;


int worldheight;
int worldwidth;




void startup(bool& fullscreen)
{

	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();




	std::string choice = "w";

	



		do
		{
			//std::system("cls");
			std::cout << "Welcome to Falling Sand by Rick.\nHit Enter for quickstart\nStart Windowed: w\nStart in Fullscren: f\nStart with custom settings: c\n\nEnter Choice: ";
			std::cin >> choice;


			if (choice == "q") {
				height = 1000;
				width = 1500;
				pixelsize = 5;
				worldheight = height / pixelsize;
				worldwidth = width / pixelsize;

				std::cout << "\n\nGridsize: " << worldheight * worldwidth << " Elements\n";

				std::cout << "\nStartup Succesfull!\n\n\n\n\n";

			}
			if (choice == "w")
			{
				height = 1000;
				width = 1500;

				std::cout << "\nPlease enter pixelsize: ";
				std::cin >> pixelsize;
				if (pixelsize < 1) {
					pixelsize = 1;
				}
				worldheight = height / pixelsize;
				worldwidth = width / pixelsize;

				std::cout << "\n\nGridsize: "<< worldheight * worldwidth << " Elements\n";

				std::cout << "\nStartup Succesfull!\n\n\n\n\n";


			}
			if (choice == "f")
			{
				fullscreen = true;
				height = desktopMode.height;
				width = desktopMode.width;

				std::cout << "\nPlease enter pixelsize: ";
				std::cin >> pixelsize;
				if (pixelsize < 1) {
					pixelsize = 1;
				}

				worldheight = height / pixelsize;
				worldwidth = width / pixelsize;

				std::cout << "Creating Window with height: " << height << " and width: " << width;
				std::cout << "\n\nGridsize: " << worldheight * worldwidth << " Elements\n";

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
				if (pixelsize < 1) {
					pixelsize = 1;
				}
				worldheight = height / pixelsize;
				worldwidth = width / pixelsize;
				std::cout << "\n\nGridsize: " << worldheight * worldwidth << " Elements\n";

				std::cout << "\nStartup Succesfull!\n\n\n\n\n";

			}
			if (choice != "w" && choice != "f" && choice != "c")
			{
				std::cout << "Wrong input please try again";
			}

		} while (choice != "w" && choice != "f" && choice != "c" && choice !="q");
	}


	

