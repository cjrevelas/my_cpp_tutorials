#include <iostream>
#include "struct_ad.h"

Advert& readDataFromUser(Advert &client)
{
	std::cout << "Enter the number of ads.\n";
	std::cin  >> client.shownAds;

	std::cout << "Enter the percentage of ads clicked.\n";
	std::cin  >> client.perCentClickedAds;

	std::cout << "Enter the average income.\n";
	std::cin  >> client.avgIncomePerClick;

	return client;
}


void printUserData(Advert &client)
{
	std::cout << "\n";
	std::cout << "--------------------------------------" << std::endl;

	std::cout << "The number of ads is: " << client.shownAds << std::endl;
	std::cout << "The percentage of ads clicked is: " << client.perCentClickedAds << std::endl;
	std::cout << "The average income is: " << client.avgIncomePerClick << std::endl;

	std::cout << "Day income is equal to: " << (client.shownAds)*(client.perCentClickedAds)*(client.avgIncomePerClick) << std::endl;

	std::cout << "--------------------------------------" << std::endl;
	std::cout << "\n";
}


int main()
{
	Advert client_1;

	readDataFromUser(client_1);
	printUserData(client_1);

	return 0;
}