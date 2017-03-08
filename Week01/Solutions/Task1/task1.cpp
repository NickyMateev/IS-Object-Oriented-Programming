#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 100;

struct Book
{
    char title[SIZE];
    char author[SIZE];
    char genre[SIZE];
    long ISBN;
    int pages;
    double price;
};

void initBook(Book& book, char* title, char* author, char* genre, long ISBN, int pages, double price)
{
    strcpy(book.title, title);
    strcpy(book.author, author);
    strcpy(book.genre, genre);
    book.ISBN = ISBN;
    book.pages = pages;
    book.price = price;
}

void printBook(Book book)
{
    cout << "Book info:" << endl;
    cout << "\tTitle: " << book.title << endl;
    cout << "\tAuthor: " << book.author << endl;
    cout << "\tGenre: " << book.genre << endl;
    cout << "\tISBN: " << book.ISBN << endl;
    cout << "\tPages: " << book.pages << endl;
    cout << "\tPrice: " << book.price << endl;
}

bool isAuthorSame(Book book1, Book book2)
{
    return (strcmp(book1.author, book2.author) == 0);
}

double getTotalPrice(Book* books, int size)
{
    if(size <= 0) // just in case
    {
        return -1;
    }

    double total = 0;
    for (int i = 0; i < size; ++i) {
       total += books[i].price;
    }
    return total;
}

Book getCheapestBook(Book* books, int size)
{
    if(size <= 0) // just in case
    {
        return Book(); // returns a default generated book
    }

    int index = 0;
    for (int i = 1; i < size; ++i) {
        if(books[i].price < books[index].price)
        {
            index = i;
        }
    }

    return books[index];
}

int getBookCountByGenre(Book* books, int size, char* genre)
{
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if(strcmp(books[i].genre, genre) == 0)
        {
            count++;
        }
    }
    return count;
}

Book getLongestBook(Book* books, int size)
{
    if(size <= 0) // just in case
    {
        return Book();
    }

    int index = 0;
    for (int i = 0; i < size; ++i) {
        if(books[i].pages > books[index].pages)
        {
            index = i;
        }
    }

    return books[index];
}

int bookByISBN(Book* books, int size, long ISBN)
{
    for (int i = 0; i < size; ++i)
    {
        if(books[i].ISBN == ISBN)
        {
            return i;
        }
    }
    return -1;
}



int main() {
    // Simple example of creating two book objects:
    Book book1, book2;
    initBook(book1, "Book1", "Author1", "Genre1", 1234567890, 123, 123.456);
    initBook(book2, "Book2", "Author2", "Genre2", 1234567890, 123, 123.456);

    printBook(book1);
    printBook(book2);

    // Example of working with an array of Book variables:
    const int SIZE = 3;
    Book books[SIZE];
    // initializing/filling up our books with values:
    initBook(books[0], "b1", "a1", "g1", 1, 2, 3);
    initBook(books[1], "b2", "a2", "g2", 2, 4, 6);
    initBook(books[2], "b3", "a3", "g3", 4, 8, 12);


    cout << "\nPrinting a book from the array:" << endl;
    printBook(books[1]); // printing a book from the array

    bool sameAuthor = isAuthorSame(books[0], books[1]);
    cout << "\nIs the first and second book's author the same? -> " << sameAuthor << endl;

    double totalPrice = getTotalPrice(books, SIZE);
    cout << "\nTotal price of the books in the array: $" << totalPrice << endl;

    Book cheapestBook = getCheapestBook(books, SIZE);
    cout << "\nCheapest book:" << endl;
    printBook(cheapestBook);

    char* genre = "g2";
    int count = getBookCountByGenre(books, SIZE, genre);
    cout << "\nNumber of books that are genre '" << genre << "' in the array: " << count << endl;

    Book longestBook = getLongestBook(books, SIZE);
    cout << "\nLongest book:" << endl;
    printBook(longestBook);

    int ISBN = 4;
    int bookIndex = bookByISBN(books, SIZE, ISBN);
    cout << "\nBook index of the book with ISBN '" << ISBN << "' is: " << bookIndex << endl;

    return 0;
}