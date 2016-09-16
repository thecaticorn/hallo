//
//  cards.cpp
//  FIT1048Assignment2_v1
//
//  Created by Sanaya Sharma on 10/09/2016.
//  Copyright � 2016 Sanaya Sharma. All rights reserved.
//

#include "cards.h"

Card::Card(){
    
}

Card::Card(int v, int s){
    cardValue = v;
    cardSuit = s;
}

Card::~Card(){
    
}

int Card::getCardValue(){
    return cardValue;
}

string Card::getSuitValue(){
    
    if (cardSuit == 0){
        return "of hearts";
    }
    else if (cardSuit == 1){
        return "of spades";
    }
    else if (cardSuit == 2){
        return "of clubs";
    }
    else{
        return "of diamonds";
    }
    
    return "";
}