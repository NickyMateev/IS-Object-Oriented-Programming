//
// Created by Mateev, Nikolay on 4/27/17.
//

#include "Team.h"


void Team::copy(const Team& other) {
    mystrcpy(this->name, other.name);
    this->numberOfTitles = other.numberOfTitles;

    this->players = new Player[other.playerCapacity];
    for (int i = 0; i < other.playerCount; ++i) {
        this->players[i] = other.players[i];
    }
    this->playerCount = other.playerCount;
    this->playerCapacity = other.playerCapacity;

    this->staffMembers = new StaffMember[other.staffMemberCapacity];
    for (int j = 0; j < other.staffMemberCount; ++j) {
       this->staffMembers[j] = other.staffMembers[j];
    }
    this->staffMemberCount = other.staffMemberCount;
    this->staffMemberCapacity = other.staffMemberCapacity;

    this->coach = other.coach;
}

void Team::destroy() {
    delete[] this->name;
    delete[] this->players;
    delete[] this->staffMembers;
}

void Team::resizeStaffMembers(int newCapacity) {
    StaffMember* temp = new StaffMember[newCapacity];
    for (int i = 0; i < this->staffMemberCount; ++i) {
        temp[i] = this->staffMembers[i];
    }

    delete[] this->staffMembers;
    this->staffMembers = temp;
    this->staffMemberCapacity = newCapacity;
}


void Team::removePlayerAt(int index) {
    for (int i = index; i < this->playerCount - 1; ++i) {
        this->players[i] = this->players[i + 1];
    }
    this->playerCount--;
}

void Team::removeStaffMemberAt(int index) {
    for (int i = index; i < this->staffMemberCount - 1; ++i) {
        this->staffMembers[i] = this->staffMembers[i + 1];
    }
    this->staffMemberCount--;
}

Team::Team() {
    mystrcpy(this->name, DEF_NAME);
    this->numberOfTitles = 0;

    this->players = new Player[MAX_TEAM_CAP];
    this->playerCount = 0;
    this->playerCapacity = MAX_TEAM_CAP;

    this->staffMembers = new StaffMember[DEFAULT_STAFF_CAP];
    this->staffMemberCount = 0;
    this->staffMemberCapacity = DEFAULT_STAFF_CAP;

    // this->coach = Coach();    <--- No need to write this, the class member 'coach' will automatically do this

}

Team::Team(const char* name, int numberOfTitles, const Player* players, int playerCount,
           const StaffMember* staffMembers, int staffMemberCount, const Coach& coach) {
    mystrcpy(this->name, name);
    this->numberOfTitles = (numberOfTitles >= 0) ? numberOfTitles : 0;

    this->players = new Player[MAX_TEAM_CAP];
    for (int i = 0; i < playerCount && i < MAX_TEAM_CAP; ++i) {
        this->players[i] = players[i];
    }
    this->playerCount = (playerCount >= 0) ? ((playerCount <= MAX_TEAM_CAP) ? playerCount : MAX_TEAM_CAP) : 0;
    this->playerCapacity = MAX_TEAM_CAP;

    int staffMembersCap = (staffMemberCount <= DEFAULT_STAFF_CAP) ? DEFAULT_STAFF_CAP : 2 * staffMemberCount;
    this->staffMembers = new StaffMember[staffMembersCap];
    for (int j = 0; j < staffMemberCount; ++j) {
        this->staffMembers[j] = staffMembers[j];
    }
    this->staffMemberCount = (staffMemberCount >= 0) ? staffMemberCount : 0;
    this->staffMemberCapacity = staffMembersCap;

    this->coach = coach;
}

Team::Team(const Team& other) {
    copy(other);
}

Team& Team::operator=(const Team& other) {
    if(this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

Team::~Team() {
    destroy();
}

const char* Team::getName() const {
    return this->name;
}

int Team::getNumberOfTitles() const {
    return this->numberOfTitles;
}

const Player* Team::getPlayers() const {
    return this->players;
}

int Team::getPlayerCount() const {
    return this->playerCount;
}

const StaffMember* Team::getStaffMembers() const {
    return this->staffMembers;
}

int Team::getStaffMemberCount() const {
    return this->staffMemberCount;
}

Coach Team::getCoach() const {
    return this->coach;
}

void Team::setName(const char* name) {
    delete[] this->name;
    mystrcpy(this->name, name);
}

void Team::setNumberOfTitles(int numberOfTitles) {
    if(numberOfTitles >= 0) {
        this->numberOfTitles = numberOfTitles;
    }
}

void Team::setPlayers(const Player* players, int playerCount) {
    if(playerCount > 0) {
        for (int i = 0; i < playerCount && i < MAX_TEAM_CAP; ++i) {
            this->players[i]  = players[i];
        }
        this->playerCount = (playerCount <= MAX_TEAM_CAP) ? playerCount : MAX_TEAM_CAP;
    }
}

void Team::setStaffMembers(const StaffMember* staffMembers, int staffMemberCount) {
    if(staffMemberCount > 0) {
        if(staffMemberCount > this->staffMemberCapacity) {
            delete[] this->staffMembers;
            this->staffMemberCapacity = 2 * staffMemberCount;
            this->staffMembers = new StaffMember[this->staffMemberCapacity];
        }

        for (int i = 0; i < staffMemberCount; ++i) {
            this->staffMembers[i] = staffMembers[i];
        }
        this->staffMemberCount = staffMemberCount;
    }
}

void Team::setCoach(const Coach& coach) {
    this->coach = coach;
}

void Team::add(const Player& player) {
    if(this->playerCount < MAX_TEAM_CAP) {
        this->players[this->playerCount] = player;
        this->playerCount++;
    }
}

void Team::add(const StaffMember& staffMember) {
    if(this->staffMemberCount == this->staffMemberCapacity) {
        resizeStaffMembers(2 * this->staffMemberCapacity);
    }

    this->staffMembers[this->staffMemberCount] = staffMember;
    this->staffMemberCount++;
}

void Team::remove(const Player& player) {
    for (int i = 0; i < this->playerCount; ++i) {
       if(this->players[i] == player) {
           removePlayerAt(i);
           break;
       }
    }
}

void Team::remove(const StaffMember& staffMember) {
    for (int i = 0; i < this->staffMemberCount; ++i) {
        if(this->staffMembers[i] == staffMember) {
            removeStaffMemberAt(i);
            break;
        }
    }
}

Team& Team::operator+=(const Player& obj) {
    add(obj);
    return *this;
}

Team& Team::operator+=(const StaffMember& obj) {
    add(obj);
    return *this;
}

Team& Team::operator-=(const Player& obj) {
    remove(obj);
    return *this;
}

Team& Team::operator-=(const StaffMember& obj) {
    remove(obj);
    return *this;
}

double Team::calculateTotalSalaries() {
    double total = 0;
    for (int i = 0; i < this->playerCount; ++i) {
        total += this->players[i].getSalary();
    }

    for (int i = 0; i < this->staffMemberCount; ++i) {
        total += this->staffMembers[i].getSalary();
    }

    total += this->coach.getSalary();

    return total;
}
