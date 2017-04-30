//
// Created by Mateev, Nikolay on 4/27/17.
//

#ifndef EXAM1_TEAM_H
#define EXAM1_TEAM_H
#include <iostream>
#include "myFunctions.h"
#include "Player.h"
#include "StaffMember.h"
#include "Coach.h"

const char* DEF_NAME = "DEFAULT_NAME";
const int MAX_TEAM_CAP = 12;
const int DEFAULT_STAFF_CAP = 16;

class Team {
private:
    char* name;
    int numberOfTitles;

    Player* players;
    int playerCount;
    int playerCapacity;

    StaffMember* staffMembers;
    int staffMemberCount;
    int staffMemberCapacity;

    Coach coach;

    void copy(const Team& other);
    void destroy();

    void resizeStaffMembers(int newCapacity);
    void removePlayerAt(int index);
    void removeStaffMemberAt(int index);
public:
    Team();
    Team(const char* name, int numberOfTitles, const Player* players, int playerCount, const StaffMember* staffMembers, int staffMemberCount, const Coach& coach);
    Team(const Team& other);
    Team& operator=(const Team& other);
    ~Team();

    const char* getName() const;
    int getNumberOfTitles() const;
    const Player* getPlayers() const;
    int getPlayerCount() const;
    const StaffMember* getStaffMembers() const;
    int getStaffMemberCount() const;
    Coach getCoach() const;

    void setName(const char* name);
    void setNumberOfTitles(int numberOfTitles);
    void setPlayers(const Player* players, int playerCount);
    void setStaffMembers(const StaffMember* staffMembers, int staffMemberCount);
    void setCoach(const Coach& coach);

    // two add functions -> no problem having the same name as long as the function parameters are different(this is known as function overloading)
    void add(const Player& player);
    void add(const StaffMember& staffMember);

    void remove(const Player& player);
    void remove(const StaffMember& staffMember);

    Team& operator+=(const Player& obj);
    Team& operator+=(const StaffMember& obj);

    Team& operator-=(const Player& obj);
    Team& operator-=(const StaffMember& obj);

    double calculateTotalSalaries();
};


#endif //EXAM1_TEAM_H
