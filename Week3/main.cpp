#include <iostream>
#include <vector>

using namespace std;

//Book structure included
#include "book.h"
//BookPile class included
#include "bookpile.h"

void PrintBook ( Book b );

int main()
{

    //provided first testing
    cout<<"First provided testing example"<<endl<<endl;
    cout << " Test 1: Create pile " << endl ;
    BookPile p;

    cout << " Test 2: Empty listing " << endl ;
    p . ListAllBooks () ;

    cout << " Test 3: Adding book " << endl ;
    Book b;
    b . title = " The C++ Standard Library ";
    b . author = " Alice Bobson ";
    p.AddBook(b);

    cout << " Test 4: List books " << endl ;
    p . ListAllBooks () ;

    cout<<endl<<endl;



    //implementing second testing
    cout<<"Second testing guided by the table checklist"<<endl<<endl;

    cout<<"1. Creating a BookPile "<<endl;
    BookPile test;

    cout<<"2-3. Empty listing"<<endl;
    test.ListAllBooks();

    cout<<"4. Adding a book"<<endl;
    b.title = "Filth";
    b.author = "Irvine Welsh";
    test.AddBook(b);
    test.ListAllBooks();

    cout<<"5. Adding 2 extra books"<<endl;
    b.title = "Trainspotting";
    b.author = "Irvine Welsh";
    test.AddBook(b);
    b.title = "The Stranger";
    b.author = "A. Camus";
    test.AddBook(b);
    test.ListAllBooks();

    cout<<"6. Removing a book"<<endl;
    test.RemoveBook();
    test.ListAllBooks();

    cout<<"7. Creating a second BookPile"<<endl;
    BookPile test2;
    test.ListAllBooks();

    cout<<"8/10. Testing GetNextBook() and listing all books"<<endl;
    b=test.GetNextBook();
    cout<<b.author<<": "<<b.title<<"   ||A book from the top"<<endl;
    test.ListAllBooks();

    cout<<"9. Listing contents twice"<<endl;
    test.ListAllBooks();
    test.ListAllBooks();

    cout<<endl<<endl;

    //Testing the questions from part a
    cout<<"Third testing guided by the questions of part a"<<endl<<endl;

    cout<<"1. What books are currently in the pile?"<<endl;
    test.ListAllBooks();
    cout<<endl;

    cout<<"2. Adding books easily"<<endl;
    b.title = "The Book Thief";
    b.author = "M. Zusak";
    test.AddBook(b);
    b.title = "Living in The End of Times";
    b.author = "S. Zizek";
    test.AddBook(b);
    test.ListAllBooks();
    cout<<endl;

    cout<<"3. Removing a book from the top"<<endl;
    test.RemoveBook();
    test.ListAllBooks();
    cout<<endl;

    cout<<"4. What item is at a particular position in the pile."<<endl;
    test.PrintBookAtPosition(2);
    cout<<endl;

    cout<<"5. Printing all contents and positions"<<endl;
    for (int i=0; i<test.GetNumBooks(); i++)
        test.PrintBookAtPosition(i+1);

    cout<<endl<<endl;

    //Testing from question e
    cout<<"Fourth testing guided by the task e"<<endl<<endl;

    cout<<"1. Removing a Book from an empty BookPile"<<endl;
    BookPile emptyBook;
    emptyBook.RemoveBook();
    cout<<endl;

    cout<<"2. GetNextBook() from an empty BookPile"<<endl;
    b=emptyBook.GetNextBook();
    cout<<endl;

    return 0;
}



void PrintBook ( Book b )
{
 // Prints a string like
 // " The Use of Lemons in Science " by Cave Johnson

 std :: cout << "\"" // literal quotemark
 << b . title << "\" by "
 << b . author
 << std :: endl ;

}
