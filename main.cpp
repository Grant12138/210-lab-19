/***************************************************************************
* COMSC-210 | Lab 19 | Grant Luo
* Editor: CLion
* Compiler: Apple clang version 16.0.0
*/
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

struct Review
{
    double rating;
    string comments;
    Review* next;

    Review() : rating(-1.0), comments("No Review"), next(nullptr) {}
    ~Review() = default; // Memory management handled in the Movie class
};

class Movie
{
    private:
        string title;
        Review* head;
    public:
        // Constructor & Destructor
        Movie() : title("N/A"), head(nullptr) {}
        Movie(string theTitle, Review* hd = nullptr)
        {
            title = theTitle;
            head = hd;
        }
        ~Movie()
        {
            Review* current = head;
            while (current != nullptr)
            {
                head = current->next;
                delete current;
                current = head;
            }
        }

        // Setter
        void setTitle(string theTitle) { title = theTitle; }
        void setHead(Review* hd) { head = hd; }

        // Getter
        string getTitle() const { return title; }
        Review* getHead() const { return head; }
};

Review generateReview(ifstream&);
double randomRating();
void stackReview(Review*&, Review&);

int main()
{
    vector<Movie> movieList {};

    Review* movie1Head = nullptr;
    ifstream finMovie1("movieReviews1.txt");
    try
    {
        if (!finMovie1.good())
            throw "I/O error";
    }
    catch (const char* e)
    {
        cout << e << '\n';
        return 1;
    }
    generateReview(finMovie1);

    Movie movie1 {"Movie 1", movie1Head};


    return 0;
}

Review generateReview(ifstream& fin)
{
    Review* aReview = new Review {};

    aReview->rating = randomRating();
    getline(fin, aReview->comments);

    return *aReview;
}

double randomRating()
{
    srand(time(0));

    return (rand() % 41 + 10) / 10.0;
}

void stackReview(Review*& head, Review& aReview)
{
    if (head == nullptr)
        head = &aReview;
    else
    {
        aReview.next
    }
}