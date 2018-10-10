#pragma once
#include <iostream>
using namespace std;

const int SIZE = 100;

class Movie {
private:
    char* name;
    char* director;
    int minutes;

    void copy(const Movie& other);
    void destroy();
public:
    Movie();
    Movie(const char* name, const char* director, int minutes);
    Movie(const Movie& other);
    Movie& operator=(const Movie& other);
    ~Movie();

    const char* getName() const;
    const char* getDirector() const;
    int getMinutes() const;

    void setName(const char* name);
    void setDirector(const char* director);
    void setMinutes(int minutes);

    friend ostream& operator<<(ostream& os, const Movie& movie);
    friend istream& operator>>(istream& is, Movie& movie);
};