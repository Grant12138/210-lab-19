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

Review* generateReview(ifstream&, Review*);
double randomRating();
void stackReview(Review*&, Review&);
void populateReviews(Review*& movieHead);

const int NUM_OF_REVIEWS = 3;
const int NUM_OF_MOVIES = 4;
const string MOVIE_REVIEWS_LIST[] = {"movieReviews1.txt",
                                     "movieReviews2.txt",
                                     "movieReviews3.txt",
                                     "movieReviews4.txt"};

int main()
{
    vector<Movie> movieList {Movie("Movie 1"),
                             Movie("Movie 2"),
                             Movie("Movie 3"),
                             Movie("Movie 4")};

    for (auto& aMovie : movieList)
    {
        Review* aMovieHead = nullptr;
        populateReviews(aMovieHead);
        aMovie.setHead(aMovieHead);
    }

    return 0;
}

Review* generateReview(ifstream& fin, Review* aReview)
{
    aReview->rating = randomRating();
    getline(fin, aReview->comments);

    return aReview;
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
        aReview.next = head;
        head = &aReview;
    }
}

void populateReviews(Review*& movieHead)
{
    static int whichReview = 0;


    for (int i = 0; i < NUM_OF_REVIEWS; i++)
    {

    }
}