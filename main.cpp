/***************************************************************************
* COMSC-210 | Lab 19 | Grant Luo
* Editor: CLion
* Compiler: Apple clang version 16.0.0
*/
#include <iostream>
#include <random>
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

void generateReview(ifstream&, Review*);
double randomRating();
void stackReview(Review*&, Review*);
void populateReviews(Review*&);

const int NUM_OF_REVIEWS = 3;
const string MOVIE_REVIEWS_LIST[] = {"movieReviews1.txt",
                                     "movieReviews2.txt",
                                     "movieReviews3.txt",
                                     "movieReviews4.txt"};

int main()
{
    vector<Movie> movieList {Movie("Kingsman"),
                             Movie("Kingsman 2"),
                             Movie("Star Wars"),
                             Movie("The Avengers")};

    for (auto& aMovie : movieList)
    {
        int i = 1;

        Review* aMovieHead = nullptr;
        populateReviews(aMovieHead);
        aMovie.setHead(aMovieHead);

        cout << aMovie.getTitle() << '\n';
        Review* current = aMovieHead;
        while (current != nullptr)
        {
            cout << "    > Review #" << i++ << ": " << current->rating << ": " << current->comments << '\n';
            current = current->next;
        }
    }

    return 0;
}

void generateReview(ifstream& fin, Review* aReview)
{
    aReview->rating = randomRating();
    getline(fin, aReview->comments);
}

double randomRating()
{

}

void stackReview(Review*& head, Review* aReview)
{
    if (head == nullptr)
        head = aReview;
    else
    {
        aReview->next = head;
        head = aReview;
    }
}

void populateReviews(Review*& movieHead)
{
    static int whichReview = 0;

    ifstream fin(MOVIE_REVIEWS_LIST[whichReview]);
    try
    {
        if (!fin.good()) throw "I/O error";
    }
    catch (const char* e)
    {
        cout << e << '\n';
        exit(1);
    }

    for (int i = 0; i < NUM_OF_REVIEWS; i++)
    {
        Review* aReview = new Review {};
        generateReview(fin, aReview);
        stackReview(movieHead, aReview);
    }
    fin.close();

    whichReview++;
}