#ifndef ABORT_H
#define ABORT_H

#include <iostream>
#include <string>

void Stop(const std::string error_message){
	std::cerr << error_message << std::endl;
	exit(1);
}

#endif