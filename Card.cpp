#include "Card.h"

using namespace std;

string abrev[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "P", "N", "Q", "K"};

void Card::printCardL1()
{cout << ".------. ";}

void Card::printCardL2()
{cout << "|" << setw(2) << right << getAbrev() << "--. | ";}

void Card::printCardL3()
{
  if (suit == 0) //Wands
      cout << R"(| :(): | )";
  if (suit == 1) //Cups
      cout << R"(| (\/) | )";
  if (suit == 2) //Swords
      cout << R"(| :/\: | )";
  if (suit == 3) //Pentacles
      cout << R"(| :/\: | )";
  if (suit == 4) //Major
      cout << R"(| :  : | )";
}

void Card::printCardL4()
{
  if (suit == 0) //Wands
    cout << R"(| ()() | )";
  if (suit == 1) //Cups
    cout << R"(| :\/: | )";
  if (suit == 2) //Swords
    cout << R"(| (__) | )";
  if (suit == 3) //Pentacles
    cout << R"(| :\/: | )";
  if (suit == 4) //Major
    cout << R"(| :  : | )";
}

void Card::printCardL5()
{cout <<  "| '--" << left << setw(2) << getAbrev() << "| ";}

void Card::printCardL6()
{cout << "`------' ";}

void Card::printCard()
{
  printCardL1();
  cout << endl;
  printCardL2();
  cout << endl;
  printCardL3();
  cout << endl;
  printCardL4();
  cout << endl;
  printCardL5();
  cout << endl;
  printCardL6();
  cout << endl;
}

string Card::getAbrev()
{
  if(suit != 4)
    return abrev[num];
  else
    return to_string(num);;
}

Card& Card::operator= (const Card& c)
{
  num = c.num;
  suit = c.suit;
  title = c.title;
  keyword1 = c.keyword1;
  keyword2 = c.keyword2;
  keyword3 = c.keyword3;
  return *this;
}