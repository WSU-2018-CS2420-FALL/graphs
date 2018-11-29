#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include "linked_list.h"
#include "linked_queue.h"

template <typename T>
class Graph{
public:
  Graph(int sz): size(sz), adjLists(new LinkedList<int>[sz]()), vertices(new T[sz]()){}

  bool empty() const {
    return size == 0;
  }

  void print() const {
    for(int i = 0; i < size; i++){
      std::cout << std::setw(5) << i << ": " ;
      adjLists[i].print();
      std::cout << std::endl;
    }
  }

  LinkedList<int>* getAdjLists() const{
    return adjLists;
  }

  T* getVertices() const {
    return vertices;
  }

  void depthFirstTraversal(){
    bool* visited = new bool[size]();

    for(int i = 0; i < size; i++){
      if(!visited[i]){
        depthFirstTraversal(i, visited);
      }
    }

    delete[] visited;
  }

  void breadthFirstTraversal(){
    LinkedQueue<int> queue;
    bool* visited = new bool[size]();

    for(int i = 0; i < size; i++){
      if(!visited[i]){
        queue.enqueue(i);
        visited[i] = true;
        std::cout << vertices[i] << "\t";

        while(!queue.empty()){
          int u = queue.peekFront();
          queue.dequeue();
          
          for(LinkedListIterator<int> it = adjLists[u].begin(); it != adjLists[u].end(); ++it){
            int w = *it;
            if(!visited[w]){
              queue.enqueue(w);
              visited[w] = true;
              std::cout << vertices[w] << "\t";
            }
          }
        }
      }
    }

    delete[] visited;
  }

private:
  int size;
  LinkedList<int>* adjLists;
  //std::vector<LinkedList<int>> graph;
  T* vertices;
  //std::vector<T> vertices;

  void depthFirstTraversal(int v, bool* visited){
    visited[v] = true;
    std::cout << vertices[v] << "\t";

    LinkedListIterator<int> it;
    for(it = adjLists[v].begin(); it != adjLists[v].end(); ++it){
      int u = *it;
      if(!visited[u]){
        depthFirstTraversal(u, visited);
      }
    }
  }
};


#endif