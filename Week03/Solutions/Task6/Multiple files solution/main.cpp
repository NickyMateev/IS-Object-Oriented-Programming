#include "Movie.h"

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