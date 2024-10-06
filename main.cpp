/***************************************************************************
* COMSC-210 | Lab 19 | Grant Luo
* Editor: CLion
* Compiler: Apple clang version 16.0.0
*/
#include <iostream>
#include <random>
#include <vector>
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

int main()
{
    vector<Movie> movieList {};
    Movie movie1 {'Movie 1'};


    return 0;
}