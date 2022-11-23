#include <iostream>
#include <string>
#include <vector>

bool overTwentyOne(std::vector<char>& cards);

int main()
{
    //char* ch = "84545";
    //char ch2 = '3';
    //int num = atoi(ch);
    //int num2 = atoi(&ch2);
    //std::cout << num << std::endl;
    //std::cout << num2 << std::endl;

    //std::vector<char> cards{'A','J','K'};
    std::vector<char> cards{'A','9','9','A','A'};
    std::cout << overTwentyOne(cards) << std::endl;

    return 0;
}

bool overTwentyOne(std::vector<char>& cards) {
    int sum    = 0;
    int countA = 0;
    bool memoA = false;

	for (char ch : cards){
	    if (ch == 'J' || ch == 'Q' || ch == 'K'){
            sum += 10;
        }else if (ch == 'A'){
            memoA = true;
            ++countA;
            sum += 11;
        }else{
            sum += atoi(&ch);
        }

        std::cout << sum << std::endl;
        std::cout << (memoA && sum>21) << std::endl;
        std::cout << std::endl;
    }

    if (memoA && sum>21) sum -= countA*10;
    std::cout << sum << std::endl;
    return (sum>21);
}
