//
//  cards.h
//  FIT1048Assignment2_v1
//
//  Created by Sanaya Sharma on 10/09/2016.
//  Copyright � 2016 Sanaya Sharma. All rights reserved.
//

#ifndef CARDS_H
#define CARDS_H

#include <string>

using namespace std;

class Card{
private:
    int cardValue;
    int cardSuit;
    
    
public:
    Card();
    Card(int v, int s);
    ~Card();
    int getCardValue();
    string getSuitValue();
};
#endif