#ifndef ABORT_H
#define ABORT_H

#include <iostream>
#include <string>

void Stop(const std::string &errorMessage){
  std::cerr << errorMessage << '\n';
  exit(1);
}

#endif
