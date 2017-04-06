#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

//strings for categories of books
const string biography = "Biography";
const string history = "History";
const string reference = "Reference";
const string fiction = "Fiction";


#include "book.h"
#include "bookpile.h"
#include "bookbot.h"
#include "bookdrop.h"
#include "storagepile.h"

void PrintBook ( Book b );
void PrintPileMenu();

int main()
{
 /*   //testing BookDrop
    cout<<"------------------------------"<<endl;
    cout<<"Testing BookDrop"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<endl;

    cout<<"1. Creating a BookDrop"<<endl;
    BookDrop bookDrop;
    cout<<endl;

    cout<<"2. Printing out empty BookDrop"<<endl;
    bookDrop.ListAllBooks();
    cout<<endl;

    cout<<"3. Using AddBook() for a BookDrop and listing books"<<endl;
    Book book;
    book.title = "The Fellowship of The Ring";
    book.author = "J.R.R Tolkien";
    book.category = fiction;
    bookDrop.AddBook(book);
    book.title = "The Two Towers";
    book.author = "J.R.R Tolkien";
    book.category = fiction;
    bookDrop.AddBook(book);
    bookDrop.ListAllBooks();
    cout<<endl;

    cout<<"4. Adding a book with user input and listing"<<endl;
    bookDrop.CheckIn();
    bookDrop.ListAllBooks();
    cout<<endl;

    cout<<"5. Printing out GetNextBook()"<<endl;
    PrintBook(bookDrop.GetNextBook());
    cout<<endl;

    cout<<"6. Removing a Book and printing all books"<<endl;
    bookDrop.RemoveBook();
    bookDrop.ListAllBooks();
    cout<<endl;

    cout<<"7. CheckOut() test and listing all books"<<endl;
    bookDrop.CheckOut();
    bookDrop.ListAllBooks();
    cout<<endl;

    */
    //Testing StoragePile



    /*

    // This snippet lives in your main testing function , and
    // checks that your StoragePile is using the virtual
    // keyword properly

    // Create a StoragePile
    StoragePile claire (" Fiction ") ;

    // Create some Books
    Book fictionBook ;
    fictionBook . title = " Barry Trotter and the Magic Rock ";
    fictionBook . author = "K. J. Lowring ";
    fictionBook . category = " Fiction ";

    Book nonfiction ;
    nonfiction . title = " The C++ Programming Language ";
    nonfiction . author = " Bjarne Stroustrup ";
    nonfiction . category = " Reference ";

    // Create a BookPile pointer to a StoragePile
    BookPile * claire_pointer = & claire ;

    // AddBook will fail
    claire_pointer->AddBook ( nonfiction ) ;
    claire . AddBook ( nonfiction ) ;
    claire . ListAllBooks () ; // empty

    // AddBook will succeed
    claire_pointer -> AddBook ( fictionBook ) ;
    claire . AddBook ( fictionBook ) ;
    claire . ListAllBooks () ; // 2 copies of Barry Trotter

    // StoragePiles don 't care
    StoragePile dave ;
    dave . AddBook ( fictionBook ) ;
    dave . AddBook ( nonfiction ) ;
    dave . ListAllBooks () ;

    */

    //Various book piles and book bots created
    StoragePile pileHistory(history), pileReference(reference), pileBiography(biography), pileFiction(fiction);
    BookPile firstBookPile, secondBookPile;
    BookDrop bookDrop;
    BookBot firstBookBot, secondBookBot;


    //various books created and added to specific piles
    Book historyBooks[5];
    historyBooks[0].title="1000 Years of Annoying the French";
    historyBooks[0].author="Stephen Clarke";
    historyBooks[1].title="An Utterly Impartial History of Britain or 2000 Years of Upper Class Idiots In Charge";
    historyBooks[1].author="John O'Farrell";
    historyBooks[2].title="Shit my History Teacher DID NOT tell me!";
    historyBooks[2].author="Karl Wiggins";
    historyBooks[3].title="English History Made Brief, Irreverent and Pleasurable";
    historyBooks[3].author="Lacey Baldwin Smith";
    historyBooks[4].title="It All Started with Nudes: An Artful History of Art";
    historyBooks[4].author="Richard Armour";
    for (int i=0; i<5; i++){
        historyBooks[i].category=history;
        pileHistory.AddBook(historyBooks[i]);
    }

    Book biographyBooks[2];
    biographyBooks[0].title="The Bedwetter: Stories of Courage, Redemption, and Pee";
    biographyBooks[0].author="Sarah Silverman";
    biographyBooks[1].title="God, If You’re Not Up There, I’m F*cked";
    biographyBooks[1].author="Darrel Hammond";
    for (int i=0; i<2; i++){
        biographyBooks[i].category=biography;
        pileBiography.AddBook(biographyBooks[i]);
    }

    Book fictionBooks[4];
    fictionBooks[0].title = "The Hobbit";
    fictionBooks[1].title = "The Fellowship of The Ring";
    fictionBooks[2].title = "The Two Towers";
    fictionBooks[3].title = "The Return of The King";
    for (int i=0; i<4; i++){
        fictionBooks[i].category=fiction;
        fictionBooks[i].author="J.R.R Tolkien";
        pileFiction.AddBook(fictionBooks[i]);
    }

    Book otherBooks[3];
    otherBooks[0].title="The Little Book of Kama Sutra";
    otherBooks[0].author="Sadie Cayman";
    otherBooks[1].title="The Missionary Position: Mother Teresa in Theory and Practise";
    otherBooks[1].author="Chritsopher Hitchen";
    otherBooks[2].title="Everyone Poops";
    otherBooks[2].author="Taro Gomi";
    for(int i=0; i<3; i++)
        firstBookPile.AddBook(otherBooks[i]);

    //menu repeated until user chooses to exit
    while(1){
        //screen cleared
        system("cls");
        //MENU
        cout<<"--------------------------"<<endl;
        cout<<"-----------Menu-----------"<<endl;
        cout<<"--------------------------"<<endl;

        cout<<"1. Book check in."<<endl;
        cout<<"2. BookDrop pile check out."<<endl;
        cout<<"3. Put a book to a book pile."<<endl;
        cout<<"4. List books."<<endl;
        cout<<"5. Exit."<<endl;

        //user input which menu
        char choice;
        cin>>choice;

        //all choices
        if(choice=='1'){
            system("cls");
            //book check in function called
            bookDrop.CheckIn();
        }
        else if(choice=='2'){
            //all books checked out from the bookDrop pile
            bookDrop.CheckOut();
        }
        else if(choice=='3'){
            system("cls");
            //menu for choosing a pile repeated until valid input is given
            while(1){
                cout<<"Choose a book pile from which to put a book."<<endl<<endl;
                //pile menu printed with this function
                PrintPileMenu();
                cin>>choice;
                //last book picked from the pile according to user choice
                if (choice=='1')
                    if(firstBookBot.PickUpBook(bookDrop))
                        break;
                else if (choice=='2')
                    if(firstBookBot.PickUpBook(firstBookPile))
                        break;
                else if (choice=='3')
                    if(firstBookBot.PickUpBook(secondBookPile))
                        break;
                else if (choice=='4')
                    if(firstBookBot.PickUpBook(pileHistory))
                        break;
                else if (choice=='5')
                    if(firstBookBot.PickUpBook(pileReference))
                        break;
                else if (choice=='6')
                    if(firstBookBot.PickUpBook(pileBiography))
                        break;
                else if (choice=='7')
                    if(firstBookBot.PickUpBook(pileFiction))
                        break;
                else if (choice=='8')
                    break;

                system("cls");
            }
            //if user didnt input exit choice (8) previously, menu for pile to put the book into repeated until valid choice
            while(choice!='8'){
                system("cls");
                //list the book user have taken
                cout<<"Book taken:"<<endl;
                firstBookBot.ListContents();
                cout<<endl;
                cout<<"Choose a book pile to which to put a book."<<endl<<endl;
                //pile menu printed
                PrintPileMenu();
                //choice variable for second pile input
                char choice2;
                cin>>choice2;
                //all valid choices
                if (choice2=='1')
                    if(firstBookBot.PlaceDownBook(bookDrop))
                        break;
                else if (choice2=='2')
                    if(firstBookBot.PlaceDownBook(firstBookPile))
                        break;
                else if (choice2=='3')
                    if(firstBookBot.PlaceDownBook(secondBookPile))
                        break;
                else if (choice2=='4')
                    if(firstBookBot.PlaceDownBook(pileHistory))
                        break;
                else if (choice2=='5')
                    if(firstBookBot.PlaceDownBook(pileReference))
                        break;
                else if (choice2=='6')
                    if(firstBookBot.PlaceDownBook(pileBiography))
                        break;
                else if (choice2=='7')
                    if(firstBookBot.PlaceDownBook(pileFiction))
                        break;
                //if user decides to exit, bookBot places down a book to the pile it belonged to
                else if (choice2=='8'){
                    switch(choice){
                        case '1': firstBookBot.PlaceDownBook(bookDrop);
                        case '2': firstBookBot.PlaceDownBook(firstBookPile);
                        case '3': firstBookBot.PlaceDownBook(secondBookPile);
                        case '4': firstBookBot.PlaceDownBook(pileHistory);
                        case '5': firstBookBot.PlaceDownBook(pileReference);
                        case '6': firstBookBot.PlaceDownBook(pileBiography);
                        case '7': firstBookBot.PlaceDownBook(pileFiction);
                    }
                    break;
                }
            }

        }
        else if(choice=='4'){
            while(1){
                system("cls");
                cout<<"Choose a book pile to list"<<endl<<endl;
                //pile menu listed
                PrintPileMenu();

                cin>>choice;
                system("cls");
                if (choice=='1'){
                    bookDrop.ListAllBooks();
                    cout<<"Press \"e\" to exit"<<endl;
                    //books list exited only when user inputs e
                    while(choice!='e')
                        cin>>choice;
                    break;
                }
                else if (choice=='2'){
                    firstBookPile.ListAllBooks();
                    cout<<"Press \"e\" to exit"<<endl;
                    while(choice!='e')
                        cin>>choice;
                    break;
                }
                else if (choice=='3'){
                    secondBookPile.ListAllBooks();
                    cout<<"Press \"e\" to exit"<<endl;
                    while(choice!='e')
                        cin>>choice;
                    break;
                }
                else if (choice=='4'){
                    pileHistory.ListAllBooks();
                    cout<<"Press \"e\" to exit"<<endl;
                    while(choice!='e')
                        cin>>choice;
                    break;
                }
                else if (choice=='5'){
                    pileReference.ListAllBooks();
                    cout<<"Press \"e\" to exit"<<endl;
                    while(choice!='e')
                        cin>>choice;
                    break;
                }
                else if (choice=='6'){
                    pileBiography.ListAllBooks();
                    cout<<"Press \"e\" to exit"<<endl;
                    while(choice!='e')
                        cin>>choice;
                    break;
                }
                else if (choice=='7'){
                    pileFiction.ListAllBooks();
                    cout<<"Press \"e\" to exit"<<endl;
                    while(choice!='e')
                        cin>>choice;
                    break;
                }
                else if (choice=='8')
                    break;

            }
        }
        //if choice is 5, exit the program
        else if(choice=='5')
            break;

    }


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

void PrintPileMenu()
{
    cout<<"1. BookDrop pile."<<endl;
    cout<<"2. Book pile 01"<<endl;
    cout<<"3. Book pile 02"<<endl;
    cout<<"4. History book pile"<<endl;
    cout<<"5. Reference book pile"<<endl;
    cout<<"6. Biography book pile"<<endl;
    cout<<"7. Fiction book pile"<<endl;
    cout<<"8. Cancel"<<endl;
}
