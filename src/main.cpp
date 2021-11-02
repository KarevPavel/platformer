//
// Created by yacopsae on 12/10/2021.
//

#include <cstdlib>
#include <ctime>
#include "engine.hpp"


int main(int argc, char *argv[]) {
  std::srand(std::time(nullptr));
  Engine engine;

  engine.start();

  return 0;
}