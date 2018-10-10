#include "Song.h"

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