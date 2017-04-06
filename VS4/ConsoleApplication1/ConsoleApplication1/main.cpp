#include <iostream>
#include <vector>
#include <string>

using namespace std;

//strings for categories of books
const string biography = "Biography";
const string history = "History";
const string reference = "Reference";
const string fiction = "Fiction";


#include "book.h"
#include "bookpile.h"
#include "bookbot.h"

void PrintBook ( Book b );

int main()
{
    //creating a new BookPile with some books
    BookPile bookPile;
    Book book;
    book.title = "Aussie Grit: My Formula One Journey";
    book.author = "Mark Webber";
    bookPile.AddBook(book);
    book.title = "James Hunt: The Biography";
    book.author = "Gerald Donaldson";
    bookPile.AddBook(book);
    book.title = "The Fellowship of The Ring";
    book.author = "J.R.R. Tolkiens";
    bookPile.AddBook(book);
    book.title = "The Two Towers";
    book.author = "J.R.R. Tolkiens";
    bookPile.AddBook(book);

    cout<<"Current BookPile: "<<endl;
    bookPile.ListAllBooks();
    cout<<endl;


    //Testing BookBot
    cout<<"--------------------------------------"<<endl;
    cout<<"Testing BookBot"<<endl;
    cout<<"--------------------------------------"<<endl;

    cout << "1. Listing empty BookBot's contents" << endl;
    BookBot bookBot;
    bookBot.ListContents();
    cout<<endl;

    cout << "2. Listing picked up book" << endl;
    bookBot.PickUpBook(bookPile);
    bookBot.ListContents();
    cout<<endl;

    cout << "3. Listing BookPile after picking up a book" << endl;
    bookPile.ListAllBooks();
    cout<<endl;

    cout << "4. Listing BookPile after placing down a book" << endl;
    bookBot.PlaceDownBook(bookPile);
    bookBot.ListContents();
    cout<<endl;

    cout << "5. Listing BookPile after placing down a book" << endl;
    bookPile.ListAllBooks();
    cout<<endl;

    cout << "6. Trying to pick up several books" << endl;
    bookBot.PickUpBook(bookPile);
    bookBot.PickUpBook(bookPile);
    cout<<"Listing BookBot contents: "<<endl;
    bookBot.ListContents();
    cout<<"Listing BookPile contents: "<<endl;
    bookPile.ListAllBooks();
    cout<<endl;

    cout << "7. Picking a book from an empty BookPile" << endl;
    BookPile emptyBookPile;
    bookBot.PickUpBook(emptyBookPile);
    cout<<endl<<endl;

    //Testing the Book structure
    cout<<"-----------------------------"<<endl;
    cout<<"Book structure testing"<<endl;
    cout<<"-----------------------------"<<endl;

    //placing down a book from BookBot for testing purposes
    bookBot.PlaceDownBook(bookPile);

    cout<<"1. Creating a new Book variable"<<endl;
    Book bookTest;
    cout<<endl;

    cout<<"2. Listing an empty book"<<endl;
    PrintBook(bookTest);
    cout<<endl;

    cout<<"3. Printing a book without an assigned category"<<endl;
    bookTest.title = "SPQR: A History of Ancient Rome";
    bookTest.author = "M. Beard";
    PrintBook(bookTest);
    cout<<endl;

    cout<<"4. Assigning a category to a book and printing it"<<endl;
    bookTest.category = history;
    PrintBook(bookTest);
    cout<<endl;

    cout<<"5. Adding a book with an assigned category to a BookPile and listing the books"<<endl;
    bookPile.AddBook(bookTest);
    bookPile.ListAllBooks();
    cout<<endl;

    cout<<"6. Listing a book by its position in the BookPile"<<endl;
    bookPile.PrintBookAtPosition(5);
    cout<<endl;

    cout<<"7. Picking up a book with BookBot and listing it"<<endl;
    bookBot.PickUpBook(bookPile);
    bookBot.ListContents();
    cout<<endl;

    return 0;
}


void PrintBook ( Book b )
{
 // Prints a string like
 // " The Use of Lemons in Science " by Cave Johnson

 std :: cout << "\"" // literal quotemark
 << b . title << "\" by "
 << b . author<< ", category: "
 << b . category
 << std :: endl ;

}
