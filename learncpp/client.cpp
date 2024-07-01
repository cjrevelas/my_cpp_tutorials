#include <iostream>

#include "./include/client.h"

Client &ReadDataFromUser(Client &client) {
  std::cout << "Enter the number of ads.\n";
  std::cin  >> client.shownAds;

  std::cout << "Enter the percentage of ads clicked.\n";
  std::cin  >> client.perCentClickedAds;

  std::cout << "Enter the average income.\n";
  std::cin  >> client.avgIncomePerClick;

  return client;
}

void PrintUserData(Client &client) {
  std::cout << '\n';
  std::cout << "--------------------------------------" << '\n';

  std::cout << "The number of ads is: " << client.shownAds << '\n';
  std::cout << "The percentage of ads clicked is: " << client.perCentClickedAds << '\n';
  std::cout << "The average income per ad clicked is: " << client.avgIncomePerClick << '\n';

  std::cout << "Day income is equal to: " << (client.shownAds) * (client.perCentClickedAds) *
               (client.avgIncomePerClick) << '\n';

  std::cout << "--------------------------------------" << '\n';
  std::cout << '\n';
}

int main() {
  Client cl;

  ReadDataFromUser(cl);
  PrintUserData(cl);

  return 0;
}
