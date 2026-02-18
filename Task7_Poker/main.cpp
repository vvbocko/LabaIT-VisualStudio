#include <windows.h>
#include <map>
#include "Card.h"
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
void BotLogic();
void Render();
void ShutDown();
void RefillHand(std::vector<Card>& playerCards);


int main() 
{
    Initialise();
    BotLogic();
    GetInput();
    Render();
    ShutDown();
}


void Initialise()
{
    deck.shuffleDeck();
    RefillHand(hand.humanCards);
    RefillHand(hand.botCards);
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
            hand.humanCards[choice - 1] = deck.GetCard();
            exchangedCount++;
            cout << "Card #" << choice << " exchanged!" << endl;
        }
        else
        {
            cout << "Wrong number" << endl;
        }
    }
    cout << "\nExchanges ended" << endl;
    RefillHand(hand.humanCards);
}

void BotLogic() 
{
    std::map<CardType, int> counts;

    for (const Card& card : hand.getPlayerCards(hand.botCards)) 
    {
        counts[card.getType()]++;
    }

    std::vector<int> cardsToExchange;
    for (int i = 0; i < hand.botCards.size(); ++i) 
    {
        if (counts[hand.botCards[i].getType()] == 1) 
        {
            cardsToExchange.push_back(i);
        }
    }

    for (int num : cardsToExchange) 
    {
        hand.botCards[num] = deck.GetCard();
    }

}

void Update() 
{

}

void Render() 
{
    cout << "Your cards:" << endl;

    for (int i = 0; i < hand.humanCards.size(); i++) 
    {
        cout << hand.humanCards[i].toString() << endl;
    }

    Rank rank = logic.checkHandRank(hand.humanCards);
    cout << "\nRank:" << logic.toString(rank) << endl;
}

void RefillHand(std::vector<Card>& playerCards)
{
    while (playerCards.size() < 5)
    {
        playerCards.push_back(deck.GetCard());
    }
}

void ShutDown()
{
    Rank humanRank = logic.checkHandRank(hand.humanCards);
    Rank botRank = logic.checkHandRank(hand.botCards);

    cout << "\nYour Rank:       " << logic.toString(humanRank);
    cout << "\nOpponent's Rank: " << logic.toString(botRank) << endl;

    if ((int)humanRank > (int)botRank) 
    {
        cout << "\nYOU WON! " << endl;

    }
    else if ((int)humanRank < (int)botRank) 
    {
        cout << "\nYOU LOST! " << endl;
    }
    else {
        cout << "\nTIE! " << endl;
    }
}