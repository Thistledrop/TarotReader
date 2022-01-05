#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include "Functions.h"
#include "Card.h"

using namespace std;

vector<Card> deck;
bool randSet = false;

string types[] = {"Wands", "Cups", "Swords", "Pentacles", "Major Arcana"};

string titles[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Page", "Knight", "Queen", "King"};

string majorTitles[] = {"The Fool", "The Magician", "The High Priestess", "The Empress", "The Emperor", "The Hierophant",
"The Lovers", "The Chariot", "Strength", "The Hermit", "Wheel of Fortune", "Justice", "The Hanged Man", "Death", 
"Temperance", "The Devil", "The Tower", "The Star", "The Moon", "The Sun", "Judgement", "The World"};

string keywords[234];

string order[] = {"First", "Second", "Third", "Fourth", "Fifth", "Sixth", "Seventh", "Eighth", "Ninth", "Tenth"};

string CC[] = {"You", "Your Challenge", "the Root of the Issue", "the Past", "the Surface", "the Future", "your Affects", "Others' Affects", "your Hopes", "the Outcome"};

string DM[] = {"Your Motivations", "The Ideal Outcome", "Your Values", "Option 1's Outcome", "Option 2's Outcome"};

void PrintBlankCards(int num)
{
    for (int i = 0; i < num; i++)
        cout << ".------. ";
    
    cout << endl;
        
    for (int i = 0; i < num; i++)
        cout << "|*.--.*| ";
        
    cout << endl;
        
    for (int i = 0; i < num; i++)
        cout << "| :  : | ";
    
    cout << endl;

    for (int i = 0; i < num; i++)
        cout << "| :  : | ";
        
    cout << endl;
        
    for (int i = 0; i < num; i++)
        cout << "|*.--.*| ";
        
    cout << endl;
        
    for (int i = 0; i < num; i++)
        cout << "`------' ";
        
    cout << endl;
}

string helper(int width, const string& str) //Credit to Masked Man on Stack Overflow 
                                            //https://stackoverflow.com/questions/14861018/center-text-in-fixed-width-field-with-stream-manipulators-in-c
{                                           //For this Function
  int len = str.length();
  if(width < len) { return str; }

  int diff = width - len;
  int pad1 = diff/2;
  int pad2 = diff - pad1;
  return string(pad1, ' ') + str + string(pad2, ' ');
}

void MakeDeck()
{
    Card c;
    for (int j = 0; j<4 ; j++)
    {
      for (int i = 0; i<14; i++)
      {
          c.suit = j;
          c.num = i;
          c.title = titles[i] + " of " + types[j];
          deck.push_back(c);
      }
    }
    
    for (int i = 0; i < 22; i++)
    {
      c.suit = 4;
      c.num = i;
      c.title = majorTitles[i];
      deck.push_back(c);
    }

    int i = 0;

    for (int j = 0; j < 78; j++)
    {
      deck[j].keyword1 = keywords[i];
      i++;
      deck[j].keyword2 = keywords[i];
      i++;
      deck[j].keyword3 = keywords[i];
      i++;
    }
}

void GetKeywords()
{
  string word;
  int i = 0;
  fstream file("Keywords.txt");
  if(!file)
  {cerr << "Unable to get keywords" << endl; exit(0);}
  
  while (file)
  {
    getline(file, word);
    if(word == "")
      {getline(file, word);}
    
    keywords[i] = word;
    i++;
  }

  file.close();
}

void PrintDeck(vector<Card> &cards)
{
  for (int i = 0; i < cards.size(); i++)
    cards[i].printCardL1();
  cout << endl;
  for (int i = 0; i < cards.size(); i++)
    cards[i].printCardL2();
  cout << endl;
  for (int i = 0; i < cards.size(); i++)
    cards[i].printCardL3();
  cout << endl;
  for (int i = 0; i < cards.size(); i++)
    cards[i].printCardL4();
  cout << endl;
  for (int i = 0; i < cards.size(); i++)
    cards[i].printCardL5();
  cout << endl;
  for (int i = 0; i < cards.size(); i++)
    cards[i].printCardL6();
  cout << endl;
}

void PrintDeckList(vector<Card> &cards)
{
  for (int i = 0; i < cards.size(); i++)
  {
    cout << to_string(i+1) + "- " << cards[i].title << endl;
  }
}

char getChar()
{
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  char input;
  cin >> input;
  return input;
}

int getInt(int min, int max)
{
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  int input;
  if(cin >> input && input >= min && input <= max)
      return input;
  else
      {throw runtime_error("Bad Integer");}
}

void PrintCelticCross()
{
  cout << R"(
                                 .------.
                                 |**--. |
                                 | :  : |
            .------.             | :  : |
            |**--. |             | '--**|
            | :  : |             `------'
            | :  : |             .------.
            | '--**|             |**--. |
            `------'             | :  : |
 .------.   .------.   .------.  | :  : |
 |**--. | .-|**--. |-. |**--. |  | '--**|
 | :  : | : | :  : | : | :  : |  `------'
 | :  : | : | :  : | : | :  : |  .------.
 | '--**| '-| '--**|-' | '--**|  |**--. |
 `------'   `------'   `------'  | :  : |
            .------.             | :  : |
            |**--. |             | '--**|
            | :  : |             `------'
            | :  : |             .------.
            | '--**|             |**--. |
            `------'             | :  : |
                                 | :  : |
                                 | '--**|
                                 `------'
    )" << endl;
}

void PrintDecisionSpread()
{
  cout << R"(
            .------.
            |**--. |
            | :  : |
            | :  : |
            | '--**|
            `------'
 .------.   .------.   .------.
 |**--. |   |**--. |   |**--. |
 | :  : |   | :  : |   | :  : |
 | :  : |   | :  : |   | :  : |
 | '--**|   | '--**|   | '--**|
 `------'   `------'   `------'
            .------.
            |**--. |
            | :  : |
            | :  : |
            | '--**|
            `------'
)" << endl;
}

vector<Card> PullRandomCards(int num)
{
  vector<Card> randCards;
  Card temp;
  
  for (int i = 0; i < num; i++)
  {
      int random = (rand() % deck.size());
      temp = deck[random];
      randCards.push_back(temp);
      deck.erase(deck.begin() + random);

      cout << helper(9, to_string(i+1));
  }

  cout << endl;
  PrintBlankCards(num);
  return randCards;
}

void returnCards(vector<Card> &ret)
{
  for (int i = 0; i < ret.size(); i++)
    {deck.push_back(ret[i]);}

  ret.clear();
}

void PrintSpreads()
{
  cout << "1. A Three Card Spread" << endl;
  cout << "2. Celtic Cross Spread" << endl;
  cout << "3. Making Decisions Spread" << endl;
}

void setRand()
{
  if(!randSet)
  {
    bool rand = true;
    while (rand)
    {
      rand = false;
      int favorite;
      cout << "Okay, to start, what's you're favorite number?" << endl;
      try{favorite = cin.get();}
      catch(exception e)
      {
        cerr << "rand-fail: " << e.what() << endl;
        cout << "Try again" << endl;
        rand = true;
      }
      srand(favorite * time(NULL));
      randSet = true;
    }
  }
  cin.clear();
}

void PullAndRead(string* rep, int num)
{
  cout << "Ready?" << endl;
  vector<Card> reading;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
	vector<Card> randCards = PullRandomCards(5);
  Card temp;
  int get;
  bool badIn = true;

  for(int i = 0; i < num; i++)
  {
    while(badIn)
      {
        badIn = false;
        
        cout << "Choose your " << order[i] <<" card, representing " << rep[i] << endl;
        try{get = getInt(1, 5);}
        catch(runtime_error e)
        {cout << "\nBad Integer\n" << endl; badIn = true;}
      }
      temp = randCards[get-1];
      reading.push_back(temp);
      returnCards(randCards);
      badIn = true;

      if(i != num)
        randCards = PullRandomCards(5);
  }

  PrintDeck(reading);

	for (int i = 0; i < num; i++)
  {
	  cout << "Your " << order[i] << " Card, representing " << rep[i] << ", is " << reading[i].title << ". It stands for " <<  reading[i].keyword1 << ", " << reading[i].keyword2 << ", and " << reading[i].keyword3 << "." << endl;
  }
}