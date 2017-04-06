#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "book.h"
#include "bookpile.h"
#include "bookbot.h"
#include "bookdrop.h"
#include "storagepile.h"

bool BookPile::AddBook(Book b){
    //adds a book to the end of the vector
    books.push_back(b);
    return true;
}

//function to remove the last book from the list
void BookPile::RemoveBook(){
    //tries to remove a book only if a list exists
    if (books.size()!=0)
        //removes the last value from the vector
        books.pop_back();
    //if the list is empty, output an error
    else
        cout<<"BOOKPILE ERROR: The list is empty"<<endl;
}

//returns the last book from the list
Book BookPile::GetNextBook(){
    //returns a book only if the list is not empty
    if (books.size()!=0)
        return books[books.size()-1];
    //if the list is empty, error output and an empty Book value returned
    else{
        cout<<"BOOKPILE ERROR: The list is empty. Empty Book returned"<<endl;
        return Book();
    }
}

//prints out all books
void BookPile::ListAllBooks(){
    //if the list is empty, output an error
    if (books.size()==0)
        cout<<"ERROR: List is empty"<<endl;
    //loop to output every book in the list
    for (int i=0; i<static_cast<int>(books.size()); i++)
        cout<<"\""<<books[i].title<<"\" by "<<books[i].author<<", category: "<<books[i].category<<endl;
}

//returns the amount of books in the list
int BookPile::GetNumBooks(){
    return books.size();
}

//outputs one book, the one specified by the position provided
void BookPile::PrintBookAtPosition(int position){
    cout<<"\""<<books[position-1].title<<"\" by "<<books[position-1].author<<", category: "
    <<books[position-1].category<<"  | Book position: "<<position<<endl;
}
