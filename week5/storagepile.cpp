#include <iostream>
#include <vector>

using namespace std;

#include "book.h"
#include "bookpile.h"
#include "bookbot.h"
#include "bookdrop.h"
#include "storagepile.h"

StoragePile::StoragePile(string category = ""){
    storageCategory = category;
}
//adds a book only if the category is valid
bool StoragePile::AddBook(Book b){
    // adds a book if category is the same or if there is no storage category set
    if (storageCategory == b.category || storageCategory == ""){
        books.push_back(b);
        return true;
    }
    else {
        cout<<"STORAGEPILE ERROR: Wrong category "<<endl;
        return false;
    }
}
