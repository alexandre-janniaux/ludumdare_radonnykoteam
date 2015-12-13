#pragma once
#include <set>
#include "graph/node.hpp"
#include "graph/branch.hpp"

class Graph;

class Path
{
public:
  Path();
  void insertBranch(Node::ID, Branch::ID);
  void addBranch(Node::ID, Branch::ID);
  float length(Graph&);
  Branch::ID getBranchID(int n);
  std::pair<Node::ID, Branch::ID>& operator[](int n) { return mPath[n]; }
  int getSize() const { return mPath.size(); }
  Node::ID getLastNodeID(Graph &g);
  Node::ID getNodeID(int n);
  int size();
  std::set<Node::ID> getNodes(Graph &g);
  bool isCyclic(Graph &g);
  void makeCyclic(Graph &g);
private:
  std::vector<std::pair<Node::ID, Branch::ID> > mPath;
  float m_length;
};
