#include <iostream>
#include <string>
#include <vector>

bool overTwentyOne(std::vector<char> &cards);

int main() {
  std::vector<char> cards{'A','9','9','A','A'};
  std::cout << overTwentyOne(cards) << '\n';

  return 0;
}

bool overTwentyOne(std::vector<char> &cards) {
  int sum    = 0;
  int countA = 0;
  bool memoA = false;

  for (char ch : cards) {
    if (ch == 'J' || ch == 'Q' || ch == 'K') {
      sum += 10;
    } else if (ch == 'A'){
      memoA = true;
      ++countA;
      sum += 11;
    } else{
      sum += atoi(&ch);
    }

    std::cout << sum << '\n';
    std::cout << (memoA && sum>21) << '\n';
    std::cout << '\n';
  }

  if (memoA && sum>21) sum -= countA*10;
  std::cout << sum << '\n';

  return (sum>21);
}
