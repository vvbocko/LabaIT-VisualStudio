#include <windows.h>
#include "Deck.h"
#include "Hand.h"
#include "ScoreLogic.h"

using namespace std;

Deck deck;
Hand hand;
ScoreLogic logic;

void Initialise();
void GetInput();
void Update();
void Render();
void ShutDown();
void RefillHand();


int main() 
{
    Initialise();
    GetInput();
    RefillHand();
    Render();

}


void Initialise()
{
    deck.shuffleDeck();
    RefillHand();
}

void GetInput()
{
    int choice = -1;
    int exchangedCount = 0;

    while (exchangedCount < 5)
    {
        Render();
        cout << "\nExchange count: " << exchangedCount<<  "/5" << endl;
        cout << "\nEnter card number to exchange (1-5)" << endl;
        cout << "Enter 0 to finish exchanging ";
        cin >> choice;

        if (choice == 0)
        {
            break;
        }

        if (choice >= 1 && choice <= 5)
        {
            hand.handCards[choice - 1] = deck.GetCard();
            exchangedCount++;
            cout << "Card #" << choice << " exchanged!" << endl;
        }
        else
        {
            cout << "Wrong number" << endl;
        }
    }
    cout << "\nExchanges ended" << endl;
}

void Update() 
{

}

void Render() 
{
    cout << "Your cards:" << endl;

    for (int i = 0; i < hand.handCards.size(); i++) 
    {
        cout << hand.handCards[i].toString() << endl;
    }

    Rank rank = logic.checkHandRank(hand);
    cout << "\nRank:" << logic.toString(rank) << endl;
}

void RefillHand()
{
    while (hand.handCards.size() < 5)
    {
        hand.handCards.push_back(deck.GetCard());
    }
}

void ShutDown()
{

}