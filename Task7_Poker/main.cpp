#include <windows.h>

void Initialise();
void DrawCards();
void GetInput();
void Update();
void Render();
void ShutDown();


int main() 
{
    Initialise();
    DrawCards();
    GetInput();

    while (true) {
        Update();
        Render();
        Sleep(500);
    }
    return 0;
    ShutDown();
}


void Initialise()
{
    // Add 4 times all 13 cards to the pile
}

void DrawCards()
{
    // DrawMaxFive()
    // Use rand() to add cards to the deck of max 5 cards
    // Sort those 5 cards
    // Display them
}

void GetInput() 
{
    // Player writtes numbers 1-5 one by one (pop/append?) or writes 0 to end choosing phase
    // ( check if the number is from 1-5 or is it 0 else error wrong input or you already got rid of this card)
    // 
}

void Update() 
{
    // DrawMaxFive()
    // Use rand() to add cards to the deck of max 5 cards
    // Sort those 5 cards
    // Display them

    // Count score from every deck
    // Compare and choose winner
}

void Render() 
{

}

void ShutDown() 
{

}