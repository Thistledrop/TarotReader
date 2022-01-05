#include <vector>
#include <string> 
#include "Menu.h"
#include "Functions.h"
#include "Card.h"

using namespace std;

void mainMenu()
{
  bool menu = false;

  while(!menu)
  {
  char n;
  cout << "What would you like to do?" << endl;
  cout << "0. I'm Finished here" << endl;
  cout << "1. Read my cards" << endl;
  cout << "2. Teach me about cards";
  n = getChar();
  
  switch(n)
    {
      case'0':
          cout << "\nOkay, come visit again soon!" << endl;
          menu = true;
          break;
      case '1': 
          ReadCards();
          break;
      case '2': 
          TeachCards();
          break;
      default: 
          cout << "I'm sorry, I didn't understand..." << endl;
          cout << endl;
          break;
    }
  }

  cout << endl;
}

void ReadCards()
{
  cout << endl;
  
  bool menu = false;
    
  while(!menu)
  {
    char input1;
    cout << "Before your reading, Let's talk about card spreads" << endl;
    cout << "0. Wait, go back" << endl;
    cout << "1. Tell me about spreads" << endl;
    cout << "2. Show me a spread" << endl;
    cout << "3. Let me choose a spread" << endl;
    input1 = getChar();
    
    switch(input1)
    {
    case '0':
      cout << "Alright" << endl;
      menu = false;
      return;
    case '1':
      TalkSpreads();
      break;
    case '2':
      ShowMe();
      break;
    case '3':
      LetMeChoose();
      menu = true;
      break;
    default:
      cout << "I'm sorry, I didn't understand that." << endl;
    }
  }

  cout << endl;
}

void TeachCards()
{
  bool menu = false;
  while(!menu)
  {
    char input1;
    cout << "What would you like to learn about?" << endl;
    cout << "0. Wait, go back" << endl;
    cout << "1. Tell me about spreads" << endl;
    cout << "2. Tell me about types of cards" << endl;
    cout << "3. Tell me about a specific card" << endl;
    input1 = getChar();
    switch(input1)
    {
      case '0':
        cout << "Alright" << endl;
        menu = false;
        return;
      case '1':
        TalkSpreads();
        break;
      case '2':
        TalkCardTypes();
        break;
      case'3':
        TalkCard();
        break;
      default:
        cout << "I'm sorry, I didn't understand that." << endl;
    }
  }

  cout << endl;
}

void TalkSpreads()
{
  bool TellMe = true;
  char input2;

  cout << "Tarot card spreads are how the cards are arranged. They can indicate the cards relationship to each other, and they can help you visualize their meanings to you personaly. There are hundred of spreads out there, ranging from simple to complex. These are some of the more common ones." << endl;

  while(TellMe)
  {
    cout << "Which of these sounds interesting to you?" << endl;
    cout << "0. That's all I wanted to know." << endl;
    PrintSpreads();
    input2 = getChar();
                      
    switch(input2)
      {
      case '0':
        cout << "Okay, Moving on..." << endl;
        TellMe = false;
        break;
      case '1':
        cout << "A three card spread is a basic spread that can cover a wide range of topics: Past/Present/Future, Situation/Action/Outcome, Think/Feel/Do, etc." << endl; 
         
        break;
      case '2':
        cout << "The Celtic Cross spread is a complex spread that deals with all the aspects of a single issue, including your strengths and weaknesses and where to direct your focus." << endl;
        break;
      case '3':
        cout << "A Making decisions spread does exactly as it says. Five cards to help you establish factors and outcomes of a choice between two options." << endl;
        break;
      default: 
        cout << "I'm sorry, I didn't understand that." << endl;
      }
  }

  cout << endl;
}

void ShowMe()
{
  bool ShowMe = true;
  char input2;

  while(ShowMe)
  {
    cout << "Which of these sounds interesting to you?" << endl;
    cout << "0. I'm Finished here" << endl;
    PrintSpreads();
    input2 = getChar();
    switch(input2)
    {
    case '0':
      cout << "Okay, moving on..." << endl;
      ShowMe = false; break;
    case '1':
      PrintBlankCards(3);
      break;
    case'2':
      PrintCelticCross();
    case '3':
      PrintDecisionSpread();
    default: 
      cout << "I'm sorry, I didn't understand that." << endl;
    }
  }
  cout << endl;
}

void LetMeChoose()
{
  bool LMC = true;
  char input;

  while(LMC)
  {
    cout << "Which of these sounds interesting to you?" << endl;
    cout << "0. I'm Finished here" << endl;
    PrintSpreads();
    input = getChar();
    switch(input)
    {
      case '0':
        LMC = false; break;
      case '1':
        cout << "A Three Card Spread it is, then." << endl;
        ThreeCardReading();
        LMC = false;
        break;
      case'2':
        cout << "Celtic Cross it is, then." << endl;
        CelticCrossReading();
        LMC = false;
        break;
      case '3':
        cout << "A decision making spread for you." << endl;
        DecisionReading();
        LMC = false;
        break;
      default: 
        cout << "I'm sorry, I didn't understand that." << endl;
        break;
    }
  }

  cout << endl;
}

void ThreeCardReading() 
{
    string st[] = {"Past", "Present", "Future"};
    Card card1;
    Card card2;
    Card card3;

    setRand();
    bool chosen = false;
    bool extraMenu = false;

    while(!chosen)
    {
      cout << "In the most common three-card spread, the cards represent your past, present, and future. Would you like to use these keywords for your spread, or another common set, or design your own?" << endl;
      cout << "1. Use Past/Present/Future" << endl;
      cout << "2. Use another set" << endl;
      cout << "3. Design your own set" << endl;
      char choice = getChar();

      switch(choice)
      {
      case'1': chosen = true; break;
      case'2': chosen = true; extraMenu = true; break;
      case'3': 
        cout << "Okay, remember to keep your keywords short." << endl;
        cout << "What would you like The first card to represent?" << endl;
        cin >> st[0];
        cout << "What would you like The second card to represent?" << endl;
        cin >> st[1];
        cout << "What would you like The third card to represent?" << endl;
        cin >> st[2];
        chosen = true;
        break;
      default: cout << "Im sorry, I didn't understand" << endl; break;
      }
    }

    cout << endl;

    if(extraMenu)
    {
      cout << "Here are some other common three-card spreads." << endl;
      cout << "1. Mind, Body, Spirit" << endl;
      cout << "2. Me, You, A Connection" << endl;
      cout << "3. Problem, Cause, Solution" << endl;
      char spread = getChar();
      switch(spread)
      {
        case'1':
          st[0] = "Mind";
          st[1] = "Body";
          st[2] = "Spirit";
          break;
        case'2':
          st[0] = "Me";
          st[1] = "You";
          st[2] = "Connection";
          break;
        case'3':
          st[0] = "Problem";
          st[1] = "Cause";
          st[2] = "Solution";
          break;
        default :cout << "Sorry, I didn't understand." << endl; break;
      }

      cout << endl;
    }
    PullAndRead(st, 3);
    cout << "I hope that helps..." << endl;
    cout << endl;
}

void CelticCrossReading()
{
  setRand();

  cout << "A Celtic Cross has ten cards, each with their own meaning. I'll remind you of the meanings after I pull the cards, but keep these keywords in mind as you pull each card" << endl;
  cout << "1. You, or your situation" << endl;
  cout << "2. The Challenge or problem" << endl;
  cout << "3. The Foundation, or Root of the issue" << endl;
  cout << "4. The Past" << endl;
  cout << "5. Above you, the Surface, the Crowning Issue" << endl;
  cout << "6. The Future" << endl;
  cout << "7. How you're affecting the situation" << endl;
  cout << "8. Other's influences" << endl;
  cout << "9. Your hopes, Best Case scenario" << endl;
  cout << "10. An Overall Outcome" << endl;

  PullAndRead(CC, 10);

  cout << "I hope that helps..." << endl;
  cout << endl;
}

void DecisionReading()
{
  setRand();

  cout << "Keep the options of your decision in mind for this one. Most decisions in life have more than two options, but this spread is designed to help you pick between two." << endl;

  PullAndRead(DM, 5);

  cout << "I hope that helps..." << endl;
  cout << endl;
}

void TalkCardTypes()
{
  cout << "Tarot cards are divided into four suits, similar to a deck of playing cards, and the major arcana cards. Each suit and the arcana represent an element as well as a facet of life. Numerology also plays into the meaning of the minor arcana. Once you know the meanings of both the number and the suit, you can harbor a guess to the meanings of the minor cards." << endl;
  bool menu = true;
  
  while (menu)
  {
    cout << "Choose something to learn more about" << endl;
    cout << "0. Wait, go back" << endl;
    cout << "1. Suit of Wands" << endl;
    cout << "2. Suit of Cups" << endl;
    cout << "3. Suit of Swords" << endl;
    cout << "4. Suit of Pentacles" << endl;
    cout << "5. The Major Arcana" << endl;
    cout << "6. Court Cards" << endl;
    cout << "7. Numerology" << endl;

    char spread = getChar();
    switch(spread)
    {
      case'0':
        menu = false;
        cout << endl;
        break;
      case'1':
        cout << "Wand(rods, or staves) are associated with Fire, as well as creativity and passion. The soul the the deck." << endl;
         
        break;
      case'2':
        cout << "Cups(chalices, or goblets) are associated with Water, as well as emotions and intuition. The heart of the deck." << endl;
         
        break;
      case'3':
        cout << "Swords(athames, or blades) are associated with Air, as well as thoughts and challenges. The mind of the deck." << endl;
         
        break;
      case'4':
        cout << "Pentacles(disks, or coins) are asscociated with Earth, as well as the home or wealth. The body of the deck." << endl;
         
        break;
      case'5':
        cout << "Major Arcana cards represent the element of spirit, and are a bit different from the other suits. They do not have court cards, and there are many more major arcana cards than in any other suit. Each major arcana card also has a title, such as The Emperor, or Death. In a reading, major arcana cards can represent powerful forces or important events. Some card readers will choose to read only major arcana cards, or to eliminate them from the deck, if the reading calls for it." << endl;
         
        break;
      case '6':
        cout << "Each minor suit has four court cards, These typically represent people in your life or attributes of others or yourself that fulfil the role the card is filling. They can also represent situations that call those atributes into play. Pages, the 'youngest' court card, are young and playful with the energies of the suit they're from. They're often seen as immature, but they can also bring a fresh perspective. Knights can bring balance and maturity in comparison, but they're prone to erratic changes and stubborness. Queens turn the suits energy inward, always full of introspection. Kings turn their energy outward, interacting with others and imposing their will on the world." << endl;
         
        break;
      case '7':
        numerology();
        break;
      default:
        cout << "Im sorry, I didn't understand..." << endl;
        break;
    }
  }

    cout << "Remember, always use your intuition when interpreting cards. They're meant to have personal meaning to you!" << endl;
    cout << endl;

}

void TalkCard()
{
  int getSuit;
  int getNum;
  cout << "What suit is the card you're looking for from?" << endl;
  cout << "1. Wands" << endl;
  cout << "2. Cups" << endl;
  cout << "3. Swords" << endl;
  cout << "4. Pentacles" << endl;
  cout << "5. Major Arcana" << endl;

  getSuit = getInt(1, 5);
  string suit = types[getSuit-1];

  cout << "What was the number of the card you're looking for?" << endl;
  string num;
  
  if(getSuit <= 4)
  {
    getNum = getInt(1, 14);
    num = titles[getNum-1];
  }
  else
  {
    getNum = getInt(0, 21);
    num = majorTitles[getNum-1];
  }
  string suitKey = "Error";
  string element = "Error";
  bool majorArcana = false;

  switch(getSuit)
  {
    case 1: suitKey = "passionate"; element = "fire";break;
    case 2: suitKey = "emotional"; element = "water";break;
    case 3: suitKey = "mental"; element = "air";break;
    case 4: suitKey = "physical"; element = "earth";break;
    case 5: majorArcana = true; break;
    default: cout << "Error" << endl; break;
  }

  string numKey = "Error";
  bool court = false;

  if(!majorArcana)
  {
    switch(getNum)
    {
      case 1:numKey = "newness";break;
      case 2:numKey = "balance";break;
      case 3:numKey = "growth";break;
      case 4:numKey = "stability";break;
      case 5:numKey = "change";break;
      case 6:numKey = "cooperation";break;
      case 7:numKey = "knowledge";break;
      case 8:numKey = "mastery";break;
      case 9:numKey = "fulfilment";break;
      case 10:numKey = "completion";break;
      case 11:numKey = "playfully";court = true;break;
      case 12:numKey = "stubbornly";court = true;break;
      case 13:numKey = "internally";court = true;break;
      case 14:numKey = "externally";court = true;break;
      default: cout << "Error" << endl; break;
    }
  }
  else
  {
    switch(getNum)
    {
      case 0:numKey = "new beginnings";break;
      case 1:numKey = "inspiration";break;
      case 2:numKey = "intuition";break;
      case 3:numKey = "creativity";break;
      case 4:numKey = "establishment";break;
      case 5:numKey = "tradition";break;
      case 6:numKey = "relationships";break;
      case 7:numKey = "willpower";break;
      case 8:numKey = "courage";break;
      case 9:numKey = "introspection";break;
      case 10:numKey = "fate";break;
      case 11:numKey = "fairness";break;
      case 12:numKey = "surrender";break;
      case 13:numKey = "transformation";break;
      case 14:numKey = "moderation";break;
      case 15:numKey = "materialism";break;
      case 16:numKey = "upheaval";break;
      case 17:numKey = "hope";break;
      case 18:numKey = "illusion";break;
      case 19:numKey = "vitality";break;
      case 20:numKey = "absolution";break;
      case 21:numKey = "completion";break;
    }
  }

  if (majorArcana)
    cout << "Major Arcana cards are significant because they represent the spirit of humanity. They're often significant in a reading, but they should not overpower the other cards. " << majorTitles[getNum] << ", specifically, represents " << numKey << "." << endl;
  else if (court)
    cout << "Court cards often represent people or personalities. The different suits are different families. The " << suit << " family is known for " << suitKey << " energy. The " << num << " of that family expresses that energy " << numKey << ". So look for that kind of personality in your life." << endl;
  else
    cout << num << " of " << suit << " is a " << element << " card. " << element << " cards usually represent " << suitKey << " energy. " << num << "s often represent " << numKey << ". So the " << num << " of " << suit << " represents " << suitKey << " " << numKey << endl;
}

void numerology()
{
  bool menu = true;
  
  while (menu)
  {
    cout << "Type a number you'd like to learn more about, 1-10. Or type 0 to go back." << endl;

    int spread;
    
    try{spread = getInt(0, 10);}
    catch(runtime_error re){cerr << "Bad Integer" << endl; spread = -1;}
    switch(spread)
    {
      case 0:
        menu = false;
        cout << endl;
        break;
      case 1:
        cout << "Ones, or Aces, signify new beginings or potential" << endl;
         
        break;
      case 2:
        cout << "Twos signify a balance or partnership" << endl;
         
        break;
      case 3:
        cout << "Threes signify creativity or growth" << endl;
         
        break;
      case 4:
        cout << "Fours signify stability and structure, think four walls to a home" << endl;
         
        break;
      case 5:
        cout << "Fives signify change or instability" << endl;
         
        break;
      case 6:
        cout << "Sixes signify communication or cooperation" << endl;
         
        break;
      case 7:
        cout << "Sevens signify reflection or knowledge" << endl;
         
        break;
      case 8:
        cout << "Eights signify mastery or acomplishment" << endl;
         
        break;
      case 9:
        cout << "Nines signify fruition, or fulfilment" << endl;
         
        break;
      case 10:
        cout << "Tens signify the end of a cycle, or renewal" << endl;
         
        break;
      default:
        cout << "Im sorry, I didn't understand..." << endl;
        break;
    }
  }

    cout << endl;
}