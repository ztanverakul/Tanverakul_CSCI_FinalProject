#include <iostream>
#include <string>
#ifndef List_H
#define List_H

using namespace std;

struct QB {
    string name;
    int rating;
    int td;
    int interceptions;
    QB *next;
    QB *previous;

    QB(std::string nam, int rat, QB *n =nullptr, QB * p = nullptr, int t = 0, int inter = 0):
        name(nam), rating(rat), td(t), interceptions(inter), next(n), previous(p){}
};

class List{
    public:
        List();
        ~List();

        void Print(string);
        void buildList();
        void buildList2();
        void buildList3();
        void Menu();
        void PlayGame();
        void DeleteList();

        QB *head;
        QB *tail;

    protected:
    private:

};

#endif // List_H
