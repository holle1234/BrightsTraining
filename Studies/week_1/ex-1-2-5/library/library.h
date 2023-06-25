#if !defined(LIBRARY)
#define LIBRARY


#include <string>
#include <vector>
#include <algorithm>
#include <array>



struct Book
{
    std::string title;
    std::string author;
    std::string ISBN;
    std::string year;
    int quantity;
    int nLoanded {0};
};


struct Library{

    private:
        std::vector<Book> books;

    public:
        const std::vector<Book>& getBooks(){
            return books;
        }

        std::vector<Book>::iterator getBookwithISBN(std::string ISBN){
            auto it = std::find_if(books.begin(), books.end(),
                                   [&](const Book& b){return b.ISBN == ISBN;});
            return it;
        }

        bool bookExist(Book& book){
            return getBookwithISBN(book.ISBN) != books.end();
        }
        
        // add new book to library
        void add(Book book){
            books.push_back(book);
        }

        // remove if exists
        void remove(Book& book){
            books.erase(std::remove_if(books.begin(), books.end(),
                        [&](const Book& libBook){return libBook.ISBN == book.ISBN;}));
        }

        // add loaned count 
        // update via search to make sure the real instance updates
        void loanBook(Book& book){
            auto it = getBookwithISBN(book.ISBN);
            if(it != books.end()){
                it->nLoanded++;
            }
        }

        // decrease loaned count
        // update via search to make sure the real instance updates
        void returnBook(Book& book){
        auto it = getBookwithISBN(book.ISBN);
            if(it != books.end()){
                it->nLoanded--;
            }
        }
};

void printBookCreationErrorMsg();

bool createBookDialog(Book &book);

std::ostream &operator<<(std::ostream &os, const Book &book);


#endif // LIBRARY
