#ifndef BOOKBOT_H_INCLUDED
#define BOOKBOT_H_INCLUDED

class BookBot{
public:
    //function to pick up a book from a BookPile
    bool PickUpBook(BookPile& p);

    //function to place down a book to a BookPile
    bool PlaceDownBook(BookPile& p);

    //prints out the BookBot's book
    void ListContents();
protected:
    Book book;
};

#endif // BOOKBOT_H_INCLUDED
