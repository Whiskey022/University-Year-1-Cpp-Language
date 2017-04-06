#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED


struct Book{
    //Simpler way of creating a constructor
    /*Book(string defaultCategory = "Default"){
        category = defaultCategory;
    }*/

    //constructor, assigning a default value for a category string
    Book(string defaultCategory = "Default"):category(defaultCategory){};
    string category;
    string title;
    string author;
};

#endif // BOOK_H_INCLUDED
