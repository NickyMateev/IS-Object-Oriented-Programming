#include "Movie.h"

void Movie::copy(const Movie& other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->director = new char[strlen(other.director) + 1];
    strcpy(this->director, other.director);
    this->minutes = other.minutes;
}

void Movie::destroy() {
    delete[] this->name;
    delete[] this->director;
}

Movie::Movie() {
    this->name = NULL;
    this->director = NULL;
    this->minutes = 0;
}

Movie::Movie(const char* name, const char* director, int minutes) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->director = new char[strlen(director) + 1];
    strcpy(this->director, director);
    this->minutes = minutes;
}

Movie::Movie(const Movie& other) {
    copy(other);
}

Movie& Movie::operator=(const Movie& other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

Movie::~Movie() {
    destroy();
}

const char* Movie::getName() const {
    return this->name;
}

const char* Movie::getDirector() const {
    return this->director;
}

int Movie::getMinutes() const {
    return this->minutes;
}

void Movie::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Movie::setDirector(const char* director) {
    delete[] this->director;
    this->director = new char[strlen(director) + 1];
    strcpy(this->director, director);
}


void Movie::setMinutes(int minutes) {
    this->minutes = minutes;
}

ostream& operator<<(ostream& os, const Movie& movie) {
    os << "Name: " << movie.name 
        << "\nDirector: " << movie.director
        << "\nLength: " << movie.minutes << " minutes";
    return os;
}

istream& operator>>(istream& is, Movie& movie) {
    delete[] movie.name;
    delete[] movie.director;

    char* buffer = new char[SIZE];

    is.getline(buffer, SIZE);
    movie.name = new char[strlen(buffer) + 1];
    strcpy(movie.name, buffer);

    is.getline(buffer, SIZE);
    movie.director = new char[strlen(buffer) + 1];
    strcpy(movie.director, buffer);

    is >> movie.minutes;
    is.ignore();

    delete[] buffer;
    return is;
}