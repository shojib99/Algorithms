
#include <bits/stdc++.h>
using namespace std;

class Card
{
public:
    string suit;
    int rank;

    Card(string s, int r) : suit(s), rank(r) {}
};

void printDeck(const vector<Card>& deck)
{
    for (const Card& card : deck)
    {
        cout << card.suit << " " << card.rank << endl;
    }
    cout << endl;
}

void insertionSort(vector<Card>& deck)
{
    int n = deck.size();
    for (int i = 1; i < n; i++)
    {
        Card key = deck[i];
        int j = i - 1;

        while (j >= 0 && deck[j].suit > key.suit)
        {
            deck[j + 1] = deck[j];
            j--;
        }

        while (j >= 0 && deck[j].suit == key.suit && deck[j].rank > key.rank)
        {
            deck[j + 1] = deck[j];
            j--;
        }
        deck[j + 1] = key;
    }
}

int main()
{
    vector<Card> deck =
    {
        Card("Hearts", 2), Card("Spades", 10), Card("Diamonds", 5),
        Card("Clubs", 1), Card("Spades", 1), Card("Hearts", 13),
        Card("Clubs", 11), Card("Diamonds", 7), Card("Hearts", 4),
        Card("Spades", 3)
    };

    cout << "Shuffled deck of cards:" << endl;
    printDeck(deck);

    insertionSort(deck);

    cout << "Sorted deck of cards:" << endl;
    printDeck(deck);

    return 0;
}
