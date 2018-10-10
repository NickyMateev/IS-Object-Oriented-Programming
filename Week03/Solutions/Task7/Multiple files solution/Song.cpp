#include "Song.h"

void Song::copy(const Song& other) {
    this->artist = new char[strlen(other.artist) + 1];
    strcpy(this->artist, other.artist);
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->duration = other.duration;
    this->genre = new char[strlen(other.genre) + 1];
    strcpy(this->genre, other.genre);
}

void Song::destroy() {
    delete[] this->artist;
    delete[] this->name;
    delete[] this->genre;
}

Song::Song() {
    this->artist = NULL;
    this->name = NULL;
    this->duration = 0;
    this->genre = NULL;
}

Song::Song(const char* artist, const char* name, int duration, const char* genre) {
    this->artist = new char[strlen(artist) + 1];
    strcpy(this->artist, artist);
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->duration = duration;
    this->genre = new char[strlen(genre) + 1];
    strcpy(this->genre, genre);
}

Song::Song(const Song& other) {
    copy(other);
}

Song& Song::operator=(const Song& other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

Song::~Song() {
    destroy();
}

const char* Song::getName() const {
    return this->name;
}

const char* Song::getArtist() const {
    return this->artist;
}

int Song::getDuration() const {
    return this->duration;
}

const char* Song::getGenre() const {
    return this->genre;
}

void Song::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Song::setArtist(const char* artist) {
    delete[] this->artist;
    this->artist = new char[strlen(artist) + 1];
    strcpy(this->artist, artist);
}

void Song::setDuration(int duration) {
    this->duration = duration;
}

void Song::setGenre(const char* genre) {
    delete[] this->genre;
    this->genre = new char[strlen(genre) + 1];
    strcpy(this->genre, genre);
}

ostream& operator<<(ostream& os, const Song& song) {
    os << "Artist: " << song.artist
        << "\nSong name: " << song.name
        << "\nDuration: " << song.duration << " minutes"
        << "\nGenre: " << song.genre;
    return os;
}

istream& operator>>(istream& is, Song& song) {
    delete[] song.name;
    delete[] song.artist;

    char* buffer = new char[SIZE];

    is.getline(buffer, SIZE);
    song.artist = new char[strlen(buffer) + 1];
    strcpy(song.artist, buffer);

    is.getline(buffer, SIZE);
    song.name = new char[strlen(buffer) + 1];
    strcpy(song.name, buffer);

    is >> song.duration;
    is.ignore();

    is.getline(buffer, SIZE);
    song.genre = new char[strlen(buffer) + 1];
    strcpy(song.genre, buffer);

    delete[] buffer;
    return is;
}