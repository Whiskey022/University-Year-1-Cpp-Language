#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "book.h"
#include "bookpile.h"
#include "bookbot.h"
#include "bookdrop.h"
#include "storagepile.h"

void BookDrop::CheckIn(){
    Book book;
    string title, author, category;
    cout<<"Adding a book."<<endl;
    cout<<"Provide a book title: ";
    getline(cin, title);
    book.title=title;
    cout<<"Provide a book author: ";
    getline(cin, author);
    book.author=author;
    cout<<"Provide a book category: ";
    getline(cin, category);
    book.category=category;
    AddBook(book);
}

void BookDrop::CheckOut(){
    books.clear();
}
