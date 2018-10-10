#include <iostream>
using namespace std;

const int SIZE = 100;

class Song {
private:
    char* artist;
    char* name;
    int duration;
    char* genre; // enum would be probably better here

    void copy(const Song& other) {
        this->artist = new char[strlen(other.artist) + 1];
        strcpy(this->artist, other.artist);
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->duration = other.duration;
        this->genre = new char[strlen(other.genre) + 1];
        strcpy(this->genre, other.genre);
    }

    void destroy() {
        delete[] this->artist;
        delete[] this->name;
        delete[] this->genre;
    }
public:
    Song() {
        this->artist = NULL;
        this->name = NULL;
        this->duration = 0;
        this->genre = NULL;
    }

    Song(const char* artist, const char* name, int duration, const char* genre) {
        this->artist = new char[strlen(artist) + 1];
        strcpy(this->artist, artist);
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->duration = duration;
        this->genre = new char[strlen(genre) + 1];
        strcpy(this->genre, genre);
    }

    Song(const Song& other) {
        copy(other);
    }

    Song& operator=(const Song& other) {
        if (this != &other) {
            destroy();
            copy(other);
        }
        return *this;
    }

    ~Song() {
        destroy();
    }

    const char* getName() const {
        return this->name;
    }

    const char* getArtist() const {
        return this->artist;
    }

    int getDuration() const {
        return this->duration;
    }

    const char* getGenre() const {
        return this->genre;
    }

    void setName(const char* name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void setArtist(const char* artist) {
        delete[] this->artist;
        this->artist = new char[strlen(artist) + 1];
        strcpy(this->artist, artist);
    }


    void setDuration(int duration) {
        this->duration = duration;
    }

    void setGenre(const char* genre) {
        delete[] this->genre;
        this->genre = new char[strlen(genre) + 1];
        strcpy(this->genre, genre);
    }

    friend ostream& operator<<(ostream& os, const Song& song) {
        os << "Artist: " << song.artist
           << "\nSong name: " << song.name
           << "\nDuration: " << song.duration << " minutes"
           << "\nGenre: " << song.genre;
        return os;
    }

    friend istream& operator>>(istream& is, Song& song) {
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
};

int main() {
    Song song1("Stoyan Ivanov", "I am God", 3, "reality");
    Song song2("Nikolay Mateev", "Amusing isn't it?", 4, "acoustic");

    cout << song1 << endl << endl;
    cout << song2 << endl << endl;

    Song song3;
    cout << "Enter info for Song 3:" << endl;
    cin >> song3;

    cout << "\n*** Song created ***\n" << song3 << endl;
    return 0;
}