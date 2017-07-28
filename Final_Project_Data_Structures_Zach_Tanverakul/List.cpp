#include "List.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int length = 10;

List::List(){
    QB *head = nullptr;
    QB *tail = nullptr;
}

List::~List(){
    DeleteList();
}

void List::Print(string classtype){
     if( head == nullptr){

    }
    else {
    int i = 0;
    QB *x = head;

    while(i<length-1){
    cout<<x->name<<" <-> ";
    x = x->next;
    i++;
    }
    if (i = length){
        cout << x->name << " -> ";
        x = x->next;
    }
    cout << classtype << " Class!" << endl;
    x = head;
    }
}

void List::buildList(){
    string it = "Elite";
    head = new QB("Matt Ryan", 117, nullptr, nullptr, 38, 7);
    head->next = new QB("Tom Brady", 112, nullptr, head, 28, 2);
    head->next->next = new QB("Dak Prescott", 105, nullptr, head->next, 23, 4);
    head->next->next->next = new QB("Aaron Rodgers", 104, nullptr, head->next->next, 40, 7);
    head->next->next->next->next = new QB("Drew Brees", 102, nullptr, head->next->next->next, 37, 15);
    head->next->next->next->next->next = new QB("Kirk Cousins", 97, nullptr, head->next->next->next->next, 25, 12);
    head->next->next->next->next->next->next = new QB("Andrew Luck", 96, nullptr, head->next->next->next->next->next, 31, 13);
    head->next->next->next->next->next->next->next = new QB("Mathew Stafford", 93, nullptr, head->next->next->next->next->next->next, 24, 10);
    head->next->next->next->next->next->next->next->next = new QB("Tyrod Taylor", 90, nullptr, head->next->next->next->next->next->next, 17, 6);
    head->next->next->next->next->next->next->next->next->next = new QB ("Ben Roethlisberger", 95, nullptr, head->next->next->next->next->next->next, 29, 13);
    //Print(it);
}

void List::buildList2(){
    string it = "Mediocre";
    head = new QB("Alex Smith", 91, nullptr, nullptr, 15, 8);
    head->next = new QB("Marcus Mariota", 96, nullptr, head, 26, 9);
    head->next->next = new QB("Jameis Winston", 86, nullptr, head->next, 28, 18);
    head->next->next->next = new QB("Philip Rivers", 88, nullptr, head->next->next, 33, 21);
    head->next->next->next->next = new QB("Russel Wilson", 93, nullptr, head->next->next->next, 21, 11);
    head->next->next->next->next->next = new QB("Derek Carr", 97, nullptr, head->next->next->next->next, 28, 6);
    head->next->next->next->next->next->next = new QB("Sam Bradford", 99, nullptr, head->next->next->next->next->next, 20, 5);
    head->next->next->next->next->next->next->next = new QB("Carson Palmer", 87, nullptr, head->next->next->next->next->next->next, 26, 14);
    head->next->next->next->next->next->next->next->next = new QB("Joe Flacco", 84, nullptr, head->next->next->next->next->next->next->next, 20, 4);
    head->next->next->next->next->next->next->next->next->next = new QB("Andy Dalton", 92, nullptr, head->next->next->next->next->next->next->next->next, 18, 8);
    //Print(it);
}

void List::buildList3(){
    string it = "Dumpster-Fire";
    head = new QB("Trevor Siemian", 85, nullptr, nullptr, 18, 10);
    head->next = new QB("Brock Osweiler", 72, nullptr, head, 15, 16);
    head->next->next = new QB("Colin Kaepernick", 91, nullptr, head->next, 16, 4);
    head->next->next->next = new QB("Ryan Tannehill", 94, nullptr, head->next->next, 19, 12);
    head->next->next->next->next = new QB("Cam Newton", 76, nullptr, head->next->next->next, 19, 14);
    head->next->next->next->next->next = new QB("Carson Wentz", 79, nullptr, head->next->next->next->next, 16, 14);
    head->next->next->next->next->next->next = new QB("Eli Manning", 86, nullptr, head->next->next->next->next->next, 26, 16);
    head->next->next->next->next->next->next->next = new QB("Blake Bortles", 79, nullptr, head->next->next->next->next->next->next, 23, 16);
    head->next->next->next->next->next->next->next->next = new QB("Ryan Fitzpatrick", 70, nullptr, head->next->next->next->next->next->next->next, 12, 17);
    head->next->next->next->next->next->next->next->next->next = new QB("Case Keenum", 76, nullptr, head->next->next->next->next->next->next->next->next, 9, 11);
    //Print(it);
}

void List::Menu(){
    cout << "1. Build Graph" << endl;
    cout << "2. Print QB Class" << endl;
    cout << "3. Play Game" << endl;
    cout << "4. Shortest Path to victory" << endl;
    cout << "5. Exit" << endl;
}

void List::PlayGame(){
    string guess;
    QB *x = head;

    int v2 = rand() % 10;
    for (int i = 0; i < v2; i++)
    {
        x = x->next;
    }
    int v1 = rand() % 3;
    if (v1 = 0)
    {
        cout << x->rating << endl;
    }
    if (v1 = 1)
    {
        cout << x->td << endl;
    }
    if (v1 = 2)
    {
        cout << x->interceptions << endl;
    }
    cout << "Which Quarterback is this?" << endl;
    cin.ignore();
    getline(cin, guess);
    if (guess == x->name){
        cout << "You're Elite!"<< endl;
    }
    else
    {
        cout << "You're Garbage! It's " << x->name << endl;
    }
}

void List::DeleteList(){
    QB *temp;
    for (QB *i = head; i != nullptr; i = temp)
    {
        temp = i->next;
        //cout << "deleting " << i->name << endl;
        delete i;
    }
    cout << "Class Deleted!" << endl;
    head = nullptr;
    tail = nullptr;
}
