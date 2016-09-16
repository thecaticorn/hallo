

//  main.cpp
//  FIT1048Assignment2_v1
//
//  Created by Sanaya Sharma on 10/09/2016.
//  Copyright � 2016 Sanaya Sharma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "cards.h"
#include "player.h"
using namespace std;

void game();

int main(){
    game();
    system("pause");
    return 0;
}

void game(){
    string n;
    char answer;
    vector<Card>cDeck;
    vector<Card>c1Deck, c2Deck;
    
    int firstCard = 0;
    for (int i = 2; i <15; i++){
        for (int j = 0; j < 4; j++){ //for every thirteen cards the suits are added for the first group '0' hearts is returned etc.etc.
            Card tempCard(i, j);
            cDeck.push_back(tempCard); //put cards into the vector
        }
    }

    random_shuffle(cDeck.begin(), cDeck.end()); //randomises cards in the vector
    
    cout << "Would you like to view the shuffled deck?" << endl;
    cin >> answer;
    
    
    if (answer == 'Y' || answer == 'y'){
        vector<Card>::iterator iter;
        for (iter = cDeck.begin(); iter != cDeck.end(); iter++){ //view the randomised deck
            cout << iter->getCardValue() << " ";//iter is a pointer arrow ensures it does not give the memory address
            cout << iter->getSuitValue() << endl;
        }
    }
    
    cout << "Would you like to view a simulation of the game? Y/N" << endl;
    cin >> answer;
    
    /*  if(answer == 'N'){
     Player p1;
     Player p2;
     cout << "Enter your name" << endl;
     cin >> n;
     p1.setName(n);
     n = p1.getName();
     }
     //Who goes first
     pStart = rand() % 2; // Pick a random player 0 or 1 thus need to add 1
     pTurn = pStart + 1;
     
     cout << "Player " << pTurn << " you will begin first!" << endl;*/
    
    if (answer == 'Y'){
        Player p1;
        Player p2;
        //make a deck for each player
        cout << "cdeck size" << cDeck.size() << endl;
        
        for (int i = 0; i <26; i++){
            c1Deck.push_back(cDeck[i]);
            cDeck.erase(cDeck.begin()); //removes second value
        }
         random_shuffle(c1Deck.begin(), c1Deck.end()); //randomises cards in the vector
        
        cout << "cdeck size" << cDeck.size() << endl;
        cout << "Player 1! There are " << c1Deck.size() << " cards shuffled in your deck right now!" << endl;
        
        vector<Card>::iterator iter;
        for (iter = c1Deck.begin(); iter != c1Deck.end(); iter++){ //view the randomised deck
            cout << iter->getCardValue() << " ";//iter is a pointer arrow ensures it does not give the memory address
            cout << iter->getSuitValue() << endl;
        }
        
        cout << "cdeck size " << cDeck.size() << endl;
        vector<Card>::iterator iter2;
        for (iter = cDeck.begin(); iter != cDeck.end(); iter++){ //view the randomised deck
            cout << iter->getCardValue() << " ";//iter is a pointer arrow ensures it does not give the memory address
            cout << iter->getSuitValue() << endl;
        }
        
        for (int i = 0; i <26; i++){
            c2Deck.push_back(cDeck[i]);
       //     cDeck.erase(cDeck[i]); //Delete second card of vector. Vector is dynamic so second card then becomes the first card/extra shuffling
        }
         random_shuffle(c2Deck.begin(), c2Deck.end()); //randomises cards in the vector
        cDeck.clear();
        
        cout << "Player 2! There are " << c2Deck.size() << " cards shuffled in your deck right now!" << endl;
        
        vector<Card>::iterator iter3;
        for (iter = c2Deck.begin(); iter != c2Deck.end(); iter++){ //view the randomised deck
            cout << iter->getCardValue() << " ";//iter is a pointer arrow ensures it does not give the memory address
            cout << iter->getSuitValue() << endl;
        }
        
        cout << "cdeck size " << cDeck.size() << endl;
    
      while(!c1Deck.empty() || !c2Deck.empty()){ //While the deck is not empty
                   //draw a card
                 c1Deck.back();
                 c2Deck.back();
          
                c1Deck.push_back(c1Deck[26]);
                c1Deck.erase(c1Deck.begin() + 26);
          
                c2Deck.push_back(c2Deck[26]);
                c2Deck.erase(c2Deck.begin() + 26);
                 cout << "c1Deck.back().getCardValue() " << c1Deck.back().getCardValue() << endl;
                 cout << "c2Deck.back().getCardValue() " << c2Deck.back().getCardValue() << endl;
                 cout<< "Player 1, you have"<< c1Deck.size() << " cards in your deck" << endl;
                 cout<< "Player 2, you have"<< c2Deck.size() << " cards in your deck" << endl;
                 
                if(c1Deck.back().getCardValue() == c2Deck.back().getCardValue()){
                    
                     cout << "You have just entered WAR!! " << endl;
                
        
                     cout << "Player 1, your fourth card is " << (c1Deck.back().getCardValue()-3) <<endl;
                     cout << "Player 2, your fourth card is " << (c2Deck.back().getCardValue()-3) << endl;
                 }
                       if((c1Deck.back().getCardValue()-3)> (c2Deck.back().getCardValue()-3)){
                            cout << "Player 1 just won the war!" << endl;
                            c1Deck.push_back(c2Deck.back());
                            c2Deck.pop_back();
                        }
                        
                        else if((c2Deck.back().getCardValue()-3)> (c1Deck.back().getCardValue()-3)){
                        cout << "Player 2 just won the war!" << endl;
                            c2Deck.push_back(c1Deck.back());
                            c1Deck.pop_back();
                    }
                        else if((c2Deck.back().getCardValue()-3) == (c1Deck.back().getCardValue()-3)){
                            cout << " You drew! " << endl;
                        }
                    
                    else if (c1Deck.back().getCardValue()> c2Deck.back().getCardValue()){
                           c1Deck.push_back(c2Deck.back());
                           c2Deck.pop_back();
                        cout << "Player 1, you had :  " << c1Deck.back().getCardValue() << endl;
                        cout << "Player 2, you had :" << c2Deck.back().getCardValue() << endl;
                        cout<< "Player 1, you have"<< c1Deck.size() << " cards in your deck" << endl;
                        cout<< "Player 2, you have"<< c2Deck.size() << " cards in your deck" << endl;
                    }
               else if (c2Deck.back().getCardValue() > c1Deck.back().getCardValue()){
                    c2Deck.push_back(c1Deck.back());
                    c1Deck.pop_back();
                   cout << "Player 1, you had :  " << c1Deck.back().getCardValue() << endl;
                   cout << "Player 2, you had :" << c2Deck.back().getCardValue() << endl;
                   cout<< "Player 1, you have"<< c1Deck.size() << " cards in your deck" << endl;
                   cout<< "Player 2, you have"<< c2Deck.size() << " cards in your deck" << endl;
                }
             }
        
    /*    while(c1Deck.size() > c2Deck.size() || c1Deck.size() < c2Deck.size()){ //While the deck is not empty
           
            if(c1Deck.size() > c2Deck.size()){
                cout << "Player 1! You have won the game of war!" << endl;
            }
            else if (c1Deck.size() < c2Deck.size()){
                cout << "Player 2! You have just won the game of war!" << endl;
            }
        }*/
        }

}