#pragma once
#include <iostream>
using namespace std;

const int SIZE = 100;

class Song {
private:
    char* artist;
    char* name;
    int duration;
    char* genre; // enum would be probably better here

    void copy(const Song& other);
    void destroy();
public:
    Song();
    Song(const char* artist, const char* name, int duration, const char* genre);
    Song(const Song& other);
    Song& operator=(const Song& other);
    ~Song();

    const char* getName() const;
    const char* getArtist() const;
    int getDuration() const;
    const char* getGenre() const;

    void setName(const char* name);
    void setArtist(const char* artist);
    void setDuration(int duration);
    void setGenre(const char* genre);

    friend ostream& operator<<(ostream& os, const Song& song);
    friend istream& operator>>(istream& is, Song& song);
};