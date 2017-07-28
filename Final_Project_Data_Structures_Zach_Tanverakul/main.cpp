#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <sstream>
#include <string>
#include "Quarterback.hpp"
#include "List.hpp"

using namespace std;

int main()
{
    string classy;
    int choice = 0;
    Quarterback *lit = new Quarterback;

    List *litty = new List;

    while (choice!= 5) {
        litty->Menu();
        cin >> choice;

        int weight = rand() % 10;
        int weight1 = rand() % 10;
        int weight2 = rand() % 10;
        int weight3 = rand() % 10;
        int weight4 = rand() % 10;
        int weight5 = rand() % 10;
        int weight6 = rand() % 10;

        if (choice == 1){
            string classy2;
            cout << "Which class of Quarterback do you choose? (Elite, Mediocre, or Dumpster-Fire)" << endl;
            cin >> classy2;

            if ((classy2 == "Elite") || (classy2 == "elite")){
                litty->buildList();
                classy = "Elite";
            }

            if ((classy2 == "Mediocre") || (classy2 == "mediocre")){
                litty->buildList2();
                classy = "Mediocre";
            }

            if ((classy2 == "Dumpster-Fire") || (classy2 == "dumpster-fire"))
            {
                litty->buildList3();
                classy = "Dumpster-Fire";
            }

            QB *x = litty->head;

            for (QB *i = litty->head; i != nullptr; i = i->next){
                lit->addVertex(i->name);
            }

            lit->addEdge(x->name, x->next->name, weight);
            lit->addEdge(x->next->name, x->name, weight);
            lit->addEdge(x->next->name, x->next->next->name, weight1);
            lit->addEdge(x->next->next->name, x->next->name, weight1);
            lit->addEdge(x->next->next->name, x->next->next->next->name, weight2);
            lit->addEdge(x->next->next->next->name, x->next->next->name, weight2);
            lit->addEdge(x->next->next->next->name, x->next->next->next->next->name, weight3);
            lit->addEdge(x->next->next->next->next->name, x->next->next->next->name, weight3);
            lit->addEdge(x->next->next->next->next->name, x->next->next->next->next->next->name, weight4);
            lit->addEdge(x->next->next->next->next->next->name, x->next->next->next->next->name, weight4);
            lit->addEdge(x->next->next->next->next->next->name, x->next->next->next->next->next->next->name, weight5);
            lit->addEdge(x->next->next->next->next->next->next->name, x->next->next->next->next->next->name, weight5);
            lit->addEdge(x->next->next->next->next->next->next->name, x->next->next->next->next->next->next->next->name, weight6);
            lit->addEdge(x->next->next->next->next->next->next->next->name, x->next->next->next->next->next->next->name, weight6);

            lit->displayEdges();
        }

        if (choice == 2){
            litty->Print(classy);
        }

        if (choice == 3){
            litty->PlayGame();
        }

        if (choice == 4){
            QB *t = litty->head;

            string ooo;
            cout << "Choose a quarterback that " << t->name << " can beat: " << endl;
            cin.ignore();
            getline(cin, ooo);

            lit->ShortestPath(t->name, ooo);
        }

        if (choice == 5){
            litty->~List();
            lit->~Quarterback();

            cout << "Thanks for playing! Go Niners!" << endl;
            exit(0);
        }

    }
    return 0;
}
