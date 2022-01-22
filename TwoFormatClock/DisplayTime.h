#include <ctime>
#include <iostream>
#include <iomanip>
#include <Windows.h>

void inc_hour(tm* curr_tm) {
	curr_tm->tm_hour++;
	if (curr_tm->tm_hour == 24) {
		curr_tm->tm_hour = 0;
	}
}

void inc_min(tm* curr_tm) { 
	curr_tm->tm_min++;
	if (curr_tm->tm_min == 60) { 
		curr_tm->tm_min = 0; 
		inc_hour(curr_tm); 
	} 
}

void inc_sec(tm* curr_tm) {
	curr_tm->tm_sec++;
	if (curr_tm->tm_sec == 60) {
		curr_tm->tm_sec = 0;
		inc_min(curr_tm);
	}
}

void DisplayCurrentTime() {
	bool exitLoop = false;

	time_t timeNow;
	tm* curr_tm;
	char twelveHourClock[100];
	char twentyFourHourClock[100];

	time(&timeNow);
	curr_tm = localtime(&timeNow);

	while (exitLoop != true) {

		strftime(twelveHourClock, 100, "*     %r      *", curr_tm);
		strftime(twentyFourHourClock, 100, "    *      %T       *", curr_tm);

		std::cout << std::setfill('*') << std::setw(24) << "" << std::setfill(' ') << "    " << std::setfill('*') << std::setw(23) << "" << std::endl;
		std::cout << std::setfill(' ');
		std::cout << "*    12-Hour Clock     *    *    24-Hour Clock    *" << std::endl;
		std::cout << twelveHourClock << twentyFourHourClock << std::endl;
		std::cout << std::setfill('*') << std::setw(24) << "" << std::setfill(' ') << "    " << std::setfill('*') << std::setw(23) << "" << std::endl;
		std::cout << std::endl;

		std::cout << "              *************************" << std::endl;
		std::cout << "              *  1 - Add One Hour     *" << std::endl;
		std::cout << "              *  2 - Add One Minute   *" << std::endl;
		std::cout << "              *  3 - Add One Second   *" << std::endl;
		std::cout << "              *  4 - Exit Program     *" << std::endl;
		std::cout << "              *************************" << std::endl;

		if (GetAsyncKeyState('1') || GetAsyncKeyState(VK_NUMPAD1)) {
			std::cout << "Adding one hour...";
			Sleep(5);
			inc_hour(curr_tm);
		}
		else if (GetAsyncKeyState('2') || GetAsyncKeyState(VK_NUMPAD2)) {
			std::cout << "Adding one minute...";
			Sleep(5);
			inc_min(curr_tm);
		}
		else if (GetAsyncKeyState('3') || GetAsyncKeyState(VK_NUMPAD3)) {
			std::cout << "Adding one second...";
			inc_sec(curr_tm);
		}
		else if (GetAsyncKeyState('4') || GetAsyncKeyState(VK_NUMPAD4)) {
			std::cout << "Exiting program..." << std::endl;
			exitLoop = true;
		}

		Sleep(1000);
		inc_sec(curr_tm);
		system("cls");
	}

	std::cout << "Program terminated!" << std::endl;

	return;
}