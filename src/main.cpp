#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "graph.h"

using namespace std;

void createGraph(Graph<int>* &g) {
  ifstream file("graph.txt");
  int size;
  file >> size;
  file.ignore();
  g = new Graph<int>(size);

  string line;
  while(getline(file, line)){
    stringstream ss;
    ss << line;
    int v, adj;
    char colon;

    ss >> v >> colon;
    while( ss >> adj){
      g->getVertices()[v] = v;
      g->getAdjLists()[v].insertFirst(adj);
    }

  }
  file.close();
}

int main(){
  Graph<int>* g;
  createGraph(g);
  g->print();
  
  delete g;

  return 0;
}