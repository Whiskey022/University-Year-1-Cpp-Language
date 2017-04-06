#ifndef STORAGEPILE_H_INCLUDED
#define STORAGEPILE_H_INCLUDED

class StoragePile : public BookPile{
public:
    StoragePile(string category);
    //adds a book only if the category is valid

    virtual bool AddBook(Book b);

protected:
    string storageCategory;
};

#endif // STORAGEPILE_H_INCLUDED
