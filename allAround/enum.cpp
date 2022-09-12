#include <iostream>

int main() {
  enum Monster {
    MONSTER_ORC      = 0,
    MONSTER_GOBLIN   = 1,
    MONSTER_TROLL    = 2,
    MONSTER_OGRE     = 3,
    MONSTER_SKELETON = 4
  };

  Monster monster = MONSTER_TROLL;

  std::cout << monster << '\n';

  return 0;
}
