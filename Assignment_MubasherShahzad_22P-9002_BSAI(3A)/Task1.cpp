#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
    int day;
    int month;
    int year;

    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
};

class Book
{
public:
    int ISBN;
    string author;
    string title;
    string genre;
    Date date_of_publication;

    Book()
    {
        ISBN = 0;
        author = "";
        title = "";
        genre = "";
        date_of_publication = Date();
    }

    Book(int ISBN, string author, string title, string genre, Date date_of_publication)
    {
        this->ISBN = ISBN;
        this->author = author;
        this->title = title;
        this->genre = genre;
        this->date_of_publication = date_of_publication;
    }

    void display_books_descriptions()
    {
        cout << "ISBN: " << ISBN << endl;
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Publication Date: " << date_of_publication.day << "/" << date_of_publication.month << "/" << date_of_publication.year << endl;
    }
};

class Node
{
public:
    Book book;
    Node *next;
    Node *prev;

    Node()
    {
        book = Book();
        next = NULL;
        prev = NULL;
    }

    Node(Book book)
    {
        this->book = book;
        next = NULL;
        prev = NULL;
    }
};

class Library
{
public:
    Node *head;
    Node *tail;

    Library()
    {
        head = NULL;
        tail = NULL;
    }
    int compare_dates(const Date &date_1, const Date &date_2)
    {
        if (date_1.year != date_2.year)
        {
            return date_1.year - date_2.year;
        }
        if (date_1.month != date_2.month)
        {
            return date_1.month - date_2.month;
        }
        return date_1.day - date_2.day;
    }

    void add_books(Book book)
    {
        Node *newNode = new Node(book);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node *current = head;

            if (compare_dates(book.date_of_publication, current->book.date_of_publication) < 0)
            {
                newNode->next = current;
                current->prev = newNode;
                head = newNode;
            }
            else
            {
                while (current->next != NULL &&
                       compare_dates(book.date_of_publication, current->next->book.date_of_publication) >= 0)
                {
                    current = current->next;
                }

                if (current->next == NULL)
                {
                    newNode->prev = current;
                    current->next = newNode;
                    tail = newNode;
                }
                else
                {
                    newNode->prev = current;
                    newNode->next = current->next;
                    current->next->prev = newNode;
                    current->next = newNode;
                }
            }
        }
    }

    void get_book_by_ISBN(int ISBN)
    {
        Node *current = head;

        while (current != NULL && current->book.ISBN != ISBN)
        {
            current = current->next;
        }

        if (current != NULL)
        {
            cout << "Book Found:" << endl;
            current->book.display_books_descriptions();
        }
        else
        {
            cout << "Book with ISBN " << ISBN << " not found" << endl;
        }
    }

    void get_book_by_Title(string title)
    {
        Node *current = head;

        while (current != NULL && current->book.title != title)
        {
            current = current->next;
        }

        if (current != NULL)
        {
            cout << "Book Found:" << endl;
            current->book.display_books_descriptions();
        }
        else
        {
            cout << "Book with title \"" << title << "\" not found" << endl;
        }
    }

    void displayBooks()
    {
        Node *current = head;

        while (current != NULL)
        {
            current->book.display_books_descriptions();
            cout << endl;
            current = current->next;
        }
    }

    void filter_books_by_Author(string author)
    {
        Node *current = head;
        bool found = false;

        while (current != NULL)
        {
            if (current->book.author == author)
            {
                current->book.display_books_descriptions();
                cout << endl;
                found = true;
            }
            current = current->next;
        }

        if (!found)
        {
            cout << "No books found by author: " << author << endl;
        }
    }

    void recommend_related_books(string genre, int currentISBN)
    {
        Node *current = head;
        int count = 0;

        while (current != NULL && count < 3)
        {
            if (current->book.genre == genre && current->book.ISBN != currentISBN)
            {
                cout << "Recommended Related Book:" << endl;
                current->book.display_books_descriptions();
                cout << endl;
                count++;
            }
            current = current->next;
        }

        if (count == 0)
        {
            cout << "No related books found." << endl;
        }
    }

    void delete_book_by_ISBN(int ISBN)
    {
        Node *current = head;

        while (current != NULL && current->book.ISBN != ISBN)
        {
            current = current->next;
        }

        if (current != NULL)
        {
            if (current == head && current == tail)
            {
                head = tail = NULL;
            }
            else if (current == head)
            {
                head = current->next;
                head->prev = NULL;
            }
            else if (current == tail)
            {
                tail = current->prev;
                tail->next = NULL;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            delete current;
            cout << "Book with ISBN " << ISBN << " deleted successfully." << endl;
        }
        else
        {
            cout << "Book with ISBN " << ISBN << " not found. Deletion failed." << endl;
        }
    }
};

void displayMenu()
{
    cout << "Book Management System For a Digital Library" << endl;
    cout << "1. Add New Book To The Library" << endl;
    cout << "2. Search Book By ISBN No" << endl;
    cout << "3. Search Book By its Title" << endl;
    cout << "4. Display All Books" << endl;
    cout << "5. Filter Books by Author" << endl;
    cout << "6. Recommend Related Books" << endl;
    cout << "7. Delete Book by ISBN No" << endl;
    cout << "8. Exit" << endl;
}

int main()
{
    Library libraryBooks;

    int choice;
    do
    {
        displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int ISBN, year, month, day;
            string author, title, genre;

            cout << "Enter ISBN: ";
            cin >> ISBN;
            cout << "Enter Author: ";
            cin.ignore();
            getline(cin, author);
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Genre: ";
            getline(cin, genre);
            cout << "Enter Publication Date (DD MM YYYY): ";
            cin >> day >> month >> year;

            Date date_of_publication(day, month, year);
            Book newBook(ISBN, author, title, genre, date_of_publication);
            libraryBooks.add_books(newBook);

            cout << "Book added successfully." << endl;
            cout << endl;
            break;
        }
        case 2:
        {
            int searchISBN;
            cout << "Enter Book ISBN No to search: ";
            cin >> searchISBN;
            libraryBooks.get_book_by_ISBN(searchISBN);
            break;
        }
        case 3:
        {
            string searchTitle;
            cout << "Enter Book Title to search: ";
            cin.ignore();
            getline(cin, searchTitle);
            libraryBooks.get_book_by_Title(searchTitle);
            break;
        }
        case 4:
        {
            cout << "Displaying all books:" << endl;
            libraryBooks.displayBooks();
            break;
        }
        case 5:
        {
            string authorName;
            cout << "Enter Author's Name to filter books: ";
            cin.ignore();
            getline(cin, authorName);
            libraryBooks.filter_books_by_Author(authorName);
            break;
        }
        case 6:
        {
            string genre;
            int currentISBN;

            cout << "Enter the genre of the current book: ";
            cin.ignore();
            getline(cin, genre);

            cout << "Enter the ISBN of the current book: ";
            cin >> currentISBN;

            libraryBooks.recommend_related_books(genre, currentISBN);
            break;
        }
        case 7:
        {
            int deleteISBN;
            cout << "Enter Book ISBN No to delete: ";
            cin >> deleteISBN;
            libraryBooks.delete_book_by_ISBN(deleteISBN);
            break;
        }
        case 8:
            cout << "Exit." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
