#include <iostream>
#include <vector>
#include <climits>
#ifndef Quarterback_H
#define Quarterback_H

using namespace std;

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
  std::string name;
	bool visited;
	int distance;
	vertex *previous;
  std::vector<adjVertex> adj;
};

class Quarterback{
    public:
        Quarterback();
        ~Quarterback();

        void addEdge(std::string, std::string, int);
        void addVertex(std::string);
        void displayEdges();
		void ShortestPath(string, string);

		void deleteVertices(std::string);
    protected:
    private:
        std::vector<vertex> vertices;

};

#endif // Quarterback_H
