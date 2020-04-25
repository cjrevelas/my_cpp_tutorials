#include <iostream>
#include <sstream>
#include <string>

int main(){

    std::cout << "ex. 1" << std::endl;

    // os is an object of the stringstream class which belongs in the std namespace
    // this object funtions as an I/O buffer
    std::stringstream os;
    os.str("en garde");                 //first way to import data into a buffer
    std::cout << os.str() << std::endl; //firts way to extract data from a buffer

    os.str("123456 67.8");
    std::string string_1;
    std::string string_2;

    //second way of exporting data from a buffer 
    os >> string_1;
    os >> string_2;

    std::cout << string_1 << std::endl;
    std::cout << os.str() << std::endl; //first one returns all buffer data regardless if some of them have already been extracted
    std::cout << string_2 << std::endl;

    std::cout << "ex. 2" << std::endl;

    //converting numbers into strings
    os.str(""); //erase buffer data
    os.clear(); //reset error flags

    int intValue = 1234567;
    float floatValue = 67.8;

    os << intValue << " " << floatValue;   //second way to import data into a buffer

    std::string stringValue_1, stringValue_2;

    os >> stringValue_1;
    os >> stringValue_2;

    std::cout << stringValue_1 << " " << stringValue_2 << std::endl;


    std::cout << "ex. 3" << std::endl;

    //converting numerical strings into buffers
    os.str(""); //erase buffer data
    os.clear(); //reset error flags

    os << "1234567 67.8"; //or os.srt(...)

    int intValue2;
    float floatValue2;

    os >> intValue2;
    os >> floatValue2;

    std::cout << intValue2 << " " << floatValue2 << std::endl;
    return 0;
}
