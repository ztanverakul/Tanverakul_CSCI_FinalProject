#include "Quarterback.hpp"
#include "List.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

Quarterback::Quarterback(){
}

Quarterback::~Quarterback(){
    vertices.clear();
    cout << "Graph Deleted!" << endl;
}

void Quarterback::addEdge(string v1, string v2, int weight){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    //adjVertex av2;
                    //av2.v = &vertices[i];
                    //av2.weight = weight;
                    //vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

void Quarterback::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        v.distance = 0;
        v.visited = false;
        v.previous = nullptr;
        vertices.push_back(v);

    }
}

void Quarterback::displayEdges(){
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->"<<endl;
    }
}

void Quarterback::ShortestPath(string starting, string destination){

    vertex * start = nullptr;
    vertex * ending = nullptr;
    //search routine to find starting and destination
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].visited = false;
        vertices[i].distance = INT_MAX;
        vertices[i].previous = nullptr;
        if (vertices[i].name == starting) {
            start = &vertices[i];
        }
        if (vertices[i].name == destination) {
            ending = &vertices[i];
        }
    }
    if (start != nullptr && ending != nullptr)
    {
      start->visited = true;
      start->distance = 0;
      //cout<<"pushing "<<start->name<<" into solved"<<endl;
      vector<vertex *> solved;
      vector<vertex *> path;
      solved.push_back(start);
      path.push_back(start);
      adjVertex * v;
      vertex * u;
      vertex * minVertex;
      vertex * prev;
      while (ending->visited == false) {
        int minDistance = INT_MAX;
        for (int i = 0; i < solved.size(); i++) {
            u = solved[i];
            //cout<<endl;
            //cout<<"Inspecting route from "<<u->name<<endl;
            for (int j = 0; j < u->adj.size(); j++) {
                v = &solved[i]->adj[j];
                //cout<<"-> to "<<v->v->name;
                if (v->v->visited == false) {
                    //cout<<", not yet solved,";
                    int dist = u->distance + v->weight;
                    if (dist < minDistance) {
                        //cout<<" the minimum distance was "<<minDistance;
                        minDistance = dist;
                        minVertex = v->v;
                        prev = u;
                        //cout<<" but there is a new minimum distance of "<<dist<<" between "
                        //<<start->name <<" and "<<minVertex->name<<endl;
                    }//else{cout<<" the minimum distance is "<<minDistance
                        //<<" and there is not a new minimum distance "<<dist<<endl;}
                }//else{
                  //cout<<" already solved, moving on"<<endl;
                //}
            }

        }
        solved.push_back(minVertex);
        //cout<<endl;
        //cout<<"pushing "<<minVertex->name<<" into solved ";
        minVertex->distance = minDistance;
        minVertex->previous = prev;
        minVertex->visited = true;
        //cout<<minVertex->name;
        //cout<<"(distance: "<<minVertex->distance
        //<<", visited: "<<minVertex->visited
        //<<", parent: "<<minVertex->previous->name<<")"<<endl;
        //cout<<"destination "<<ending->name<<" solved? "<<ending->visited<<endl;
        //cout<<endl;
      }
      cout<<"Shortest Path"<<endl;
      vertex * vert = ending;
      while (vert != nullptr) {
          path.push_back(vert);
          vert = vert->previous;
      }
          for (int i = 0; i < path.size()-1; i++) {
            if (i == path.size() -2)
              cout<<path[path.size()-1-i]->name;
            else
              cout<<path[path.size()-1-i]->name<<" - ";

          }
      cout<<endl;
      cout<<"Minimum Distance: "<<solved[solved.size()-1]->distance<<endl;
      if (solved[solved.size()-1]->distance < 25){
           cout << "Sorry but " << starting << " lost to " << destination << endl;
      }
      else {
           cout << starting << " beat " << destination << endl;
      }
  }else if (ending!=nullptr){
    cout<<"start not found"<<endl;
    exit(1);
  }else {
    cout<<"ending not found"<<endl;
    exit(1);
  }
}
