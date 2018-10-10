#include <iostream>
using namespace std;

const int SIZE = 100;

class Movie {
private:
    char* name;
    char* director;
    int minutes;

    void copy(const Movie& other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->director = new char[strlen(other.director) + 1];
        strcpy(this->director, other.director);
        this->minutes = other.minutes;
    }

    void destroy() {
        delete[] this->name;
        delete[] this->director;
    }
public:
    Movie() {
        this->name = NULL;
        this->director = NULL;
        this->minutes = 0;
    }

    Movie(const char* name, const char* director, int minutes) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->director = new char[strlen(director) + 1];
        strcpy(this->director, director);
        this->minutes = minutes;
    }

    Movie(const Movie& other) {
        copy(other);
    }

    Movie& operator=(const Movie& other) {
        if (this != &other) {
            destroy();
            copy(other);
        }
        return *this;
    }

    ~Movie() {
        destroy();
    }

    const char* getName() const {
        return this->name;
    }

    const char* getDirector() const {
        return this->director;
    }

    int getMinutes() const {
        return this->minutes;
    }

    void setName(const char* name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void setDirector(const char* director) {
        delete[] this->director;
        this->director = new char[strlen(director) + 1];
        strcpy(this->director, director);
    }


    void setMinutes(int minutes) {
        this->minutes = minutes;
    }

    friend ostream& operator<<(ostream& os, const Movie& movie) {
        os << "Name: " << movie.name 
           << "\nDirector: " << movie.director
           << "\nLength: " << movie.minutes << " minutes";
        return os;
    }

    friend istream& operator>>(istream& is, Movie& movie) {
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
};

int main() {
    Movie movie1("Movie 1", "Director 1", 124);
    Movie movie2("Movie 2", "Director 2", 93);

    cout << movie1 << endl << endl;
    cout << movie2 << endl << endl;

    Movie movie3;
    cout << "Enter info for Movie 3:" << endl;
    cin >> movie3;

    cout << "\n*** Movie created ***\n" << movie3 << endl;
    return 0;
}