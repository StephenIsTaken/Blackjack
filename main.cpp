#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

enum Cards
{
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Ace,
    King,
    Queen
};

string translateToString(Cards card)
{
    if(card == Two)
    {
        return "Two";
    }
    if(card == Three)
    {
        return "Three";
    }
    if(card == Four)
    {
        return "Four";
    }
    if(card == Five)
    {
        return "Five";
    }
    if(card == Six)
    {
        return "Six";
    }
    if(card == Seven)
    {
        return "Seven";
    }
    if(card == Eight)
    {
        return "Eight";
    }
    if(card == Nine)
    {
        return "Nine";
    }
    if(card == Ten)
    {
        return "Ten";
    }
    if(card == King)
    {
        return "King";
    }
    if(card == Queen)
    {
        return "Queen";
    }
    if(card == Ace)
    {
        return "Ace/One";
    }
    else
    {
        return "Restart I broke it";
    }
}

int translateToInt(Cards card)
{
    if(card == Two)
    {
        return 2;
    }
    if(card == Three)
    {
        return 3;
    }
    if(card == Four)
    {
        return 4;
    }
    if(card == Five)
    {
        return 5;
    }
    if(card == Six)
    {
        return 6;
    }
    if(card == Seven)
    {
        return 7;
    }
    if(card == Eight)
    {
        return 8;
    }
    if(card == Nine)
    {
        return 9;
    }
    if(card == Ten)
    {
        return 10;
    }
    if(card == King)
    {
        return 10;
    }
    if(card == Queen)
    {
        return 10;
    }
    if(card == Ace)
    {
        return 11;
    }
}
void stand(int yourSum,int dealerSum)
{
    cout<<"New dealer cards: ";
    while(dealerSum < 17)
    {
        Cards dealerCard = Cards((rand()%12));
        cout<<translateToString(dealerCard)<<" ";
        dealerSum += translateToInt(dealerCard);
    }
    cout<<'\n';
    cout<<"New dealer sum: "<<dealerSum;
    cout<<'\n';
    if(yourSum > 21)
    {
        cout<<"You lost";
    }
    else if(dealerSum > 21)
    {
        cout<<"You won";
    }
    else if(yourSum > dealerSum)
    {
        cout<<"You won";
    }
    else if(dealerSum > yourSum)
    {
        cout<<"You lost";
    }
    else
    {
        cout<<"Its a draw";
    }
}
void hit(int yourSum,int dealerSum)
{
    // Generate a new card
    Cards yourCard = Cards((rand()%12));
    cout<<"New card: " << translateToString(yourCard);
    cout<<'\n';
    // Calculate the new sum
    int newSum;
    if(translateToInt(yourCard)!=-1)
        newSum = translateToInt(yourCard) + yourSum;
    else
    {
        if(11 + yourSum > 21)
        {
            newSum = yourSum + 1;
        }
        else
        {
            newSum = yourSum + 11;
        }
    }
    cout<<"New sum: " << newSum;
    cout<<'\n';
    if(newSum > 21)
    {
        cout<<"You lost";
    }
    else if(newSum == 21)
    {
        cout<<"You won";
    }
    else
    {
        // Retry
        cout<<"Press 1 to hit, 2 to stand"<<'\n';

        int ans;
        cin>>ans;
        if(ans == 1)
        {
            hit(newSum,dealerSum);
        }
        if(ans == 2)
        {
            stand(newSum,dealerSum);
        }
    }
}

int main()
{
    // Generate four cards
    srand((unsigned)time(0));
    Cards yourCard1 = Cards((rand()%12));
    if(translateToInt(yourCard1) < 2 or translateToInt(yourCard1) > 21)
    {
        while(translateToInt(yourCard1) < 2)
            yourCard1 = Cards((rand()%12));
    }
    Cards yourCard2 = Cards((rand()%12));
    if(translateToInt(yourCard2) < 2 or translateToInt(yourCard2) > 21)
    {
        while(translateToInt(yourCard2) <2)
            yourCard2 = Cards((rand()%12));
    }
    Cards dealerCard1 = Cards((rand()%12));
    Cards dealerCard2 = Cards((rand()%12));
    // Display your cards
    cout<<"Your cards: " << translateToString(yourCard1) << " "<< translateToString(yourCard2);
    cout<<'\n';
    // Display your sum
    int yourSum = translateToInt(yourCard1) + translateToInt(yourCard2);
    cout<<"Your sum: " << yourSum;


    cout<<'\n';
    // Display dealer cards
    cout<<"Dealer cards: " << translateToString(dealerCard1) << " "<< translateToString(dealerCard2);
    cout<<'\n';
    // Display dealer sum
    int dealerSum = translateToInt(dealerCard1) + translateToInt(dealerCard2);
    cout<<"Dealer sum: " << dealerSum;
    cout<<'\n';
    cout<<"Press 1 to hit, 2 to stand"<<'\n';

    int ans;
    cin>>ans;
    if(ans == 1)
    {
        hit(yourSum,dealerSum);
    }
    if(ans == 2)
    {
        stand(yourSum,dealerSum);
    }
    return 0;
}
