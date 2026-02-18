#pragma once

enum class Rank : int
{
    HighCard = 0,   // Any hand that does not qualify as any of the above.The value is determined by the highest card in the hand.

    OnePair,        // Two cards of the same rank, along with three unrelated cards.

    TwoPair,        // Two different pairs of cards in the same hand, plus a fifth card.

    ThreeOfAKind,   // Three cards of the same rank, with two unrelated side cards.

    Straight,       // 5 kart u³o¿onych sekwencyjnie po kolei -->  5,6,7,8,9   albo   8,9,10,J,K

    Flush,          // Just 5 cards of the same suit

    FullHouse, // 3 cards of one rank combined with 2 cards of another rank.

    FourOfAKind,    // Four cards of the same rank, plus any fifth card(the kicker).

    StraightFlush, // Any 5 consecutive cards of the same suit.

    RoyalFlush, //A, K, Q, J, and 10 of the exact same suit.


    RankNumber
};