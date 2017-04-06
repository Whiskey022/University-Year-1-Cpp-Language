#include <iostream>
#include <vector>
#include <string>

using namespace std;


#include "bookbot.h"



    //function to pick up a book from a BookPile
    bool BookBot::PickUpBook(BookPile& p){
        //if BookPile is empty, return false and print out an error
        if (p.GetNumBooks()==0){
            cout<<"BOOKBOT ERROR: BookPile given is empty"<<endl;
            return false;
        }
        //if BookBot already holds a book, return false and print out an error
        else if (book.title!="" || book.author!=""){
            cout<<"BOOKBOT ERROR: BookBot already holds a book"<<endl;
            return false;
        }
        //else, picks up a book
        else{
            //gets the top book from a BookPile
            book=p.GetNextBook();
            //removes the picked book from the BookPile
            p.RemoveBook();
            return true;
        }
    }

    //function to place down a book to a BookPile
    bool BookBot::PlaceDownBook(BookPile& p){
        //if BookBot doesnt hold a book, print out an error and return false
        if (book.title=="" && book.author==""){
            cout<<"BOOKBOT ERROR: BookBot doesn't hold a book"<<endl;
            return false;
        }
        //else, put down a book to a BookPile
        else {
            //ads the book to a BookPile
            p.AddBook(book);
            //BookBot's book assigned to an empty Book
            book = Book();
            return true;
        }
    }

    //prints out the BookBot's book
    void BookBot::ListContents(){
        //if there is a book, print it out
        if (book.title!="" || book.author!="")
            cout<<"\""<<book.title<<"\" by "<<book.author<<", category: "<<book.category<<endl;
        //else print out an error
        else
            cout<<"BOOKBOT ERROR: BookBot does not hold a book"<<endl;
    }

