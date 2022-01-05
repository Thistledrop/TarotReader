#ifndef CARDS
#define CARDS

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Card {
  public:
  int suit;
  int num;
  string title;
  string keyword1;
  string keyword2;
  string keyword3;

  Card()
  {suit = 1, num = 1; title = "ERROR"; keyword1 = "ERROR1"; keyword2 = "ERROR2"; keyword3 = "ERROR3";}

  Card (int s, int n, string t, string k1, string k2, string k3)
  {suit = s; num = n; title = t; keyword1 = k1; keyword2 = k2; keyword3 = k3;}

  void printCardL1();
  void printCardL2();
  void printCardL3();
  void printCardL4();
  void printCardL5();
  void printCardL6();

  void printCard();
  string getAbrev();

  Card& operator=(const Card&);
};

#endif