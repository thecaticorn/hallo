//  player.h
//  FIT1048Assignment2_v1
//
//  Created by Sanaya Sharma on 10/09/2016.
//  Copyright � 2016 Sanaya Sharma. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player{
private:
    string name;
    
public:
    Player();
    Player(int a);
    ~Player();
    void setName(string n);
    string getName();
};
#endif