#ifndef BOOKPILE_H_INCLUDED
#define BOOKPILE_H_INCLUDED

#include "book.h"

class BookPile
{
public:
    //function to add a book to the list
    void AddBook(Book b);

    //function to remove the last book from the list
    void RemoveBook();

    //returns the last book from the list
    Book GetNextBook();

    //prints out all books
    void ListAllBooks();

    //returns the amount of books in the list
    int GetNumBooks();

    //outputs one book, the one specified by the position provided
    void PrintBookAtPosition(int position);
protected:
    //protected vector of books (book titles and authors)
    vector<Book> books;
};

#endif // BOOKPILE_H_INCLUDED
