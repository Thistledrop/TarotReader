#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include "Menu.h"
#include "Card.h"
#include "Functions.h"

using namespace std;

int main()
{
  GetKeywords();
  MakeDeck();
  cout << R"(
     ___
  .-" __"-.
 /:.'`__`'.\
|:: .'_ `. :|
|:: '._' : :|
 \:'.__.' :/
  /`-...-'\
 /         \
 `-.,___,.-'
    )" << endl;

  mainMenu();
}
