#ifndef FUNCTIONS
#define FUNCTIONS

#include <string>
#include <vector>
#include "Card.h"

using namespace std;

extern vector<Card> deck;
extern bool randSet;

void PrintBlankCards(int num);

extern string types[];
extern string titles[];
extern string majorTitles[];
extern string keywords[];
extern string order[];
extern string CC[];
extern string DM[];

char getChar();
int getInt(int min, int max);
string helper(int width, const string& str);
void MakeDeck();
void TempMakeDeck();
void GetKeywords();
void PrintDeck(vector<Card> &cards);
void PrintDeckList(vector<Card> &cards);
void PrintCelticCross();
void PrintDecisionSpread();

vector<Card> PullRandomCards(int num);
void returnCards(vector<Card>&);
void PrintSpreads();
void setRand();
void PullAndRead(string* rep, int num);

#endif