#pragma once
#include <map>
#include <set>
#include "node.hpp"
#include "branch.hpp"
#include "../path.hpp"
#include "random"


float constexpr leafLimit = 0.3f;

class Graph
{
	struct NeighbourHood : public std::multimap<Node::ID, Branch::ID>
	{
		Branch::ID operator[](Node::ID n)
		{ return find(n)->second; }
		Branch::ID const& operator[](Node::ID n) const
		{ return find(n)->second; }
	};

	public:
	Graph(); // TODO: Pour l’instant, cette fonction est un peu bidon
	//float distance(Node::ID n1, Node::ID n2);
	Node::ID addNode(Node n);
	void addNode(Node::ID n);
	Branch::ID newEdge(Node::ID n1, Node::ID n2);
	// static bool isItLeaf(Node::ID n1, Node::ID n2);
	bool hasDownEdge(Node::ID n) const;
	bool isCulDeSac(Branch::ID b) const;

	Branch const* getBranch(Branch::ID id) const;
	Branch* getBranch(Branch::ID id);
	Branch& operator[](Branch::ID b)
	{ return m_branchs.find(b)->second; }
	Branch const& operator[](Branch::ID b) const
	{ return m_branchs.find(b)->second; }

	Node const* getNode(Node::ID id) const;
	Node* getNode(Node::ID id);
	Node& operator[](Node::ID n)
	{ return m_nodes.find(n)->second; }
	Node const& operator[](Node::ID n) const
	{ return m_nodes.find(n)->second; }

	NeighbourHood& getNeighbours(Node::ID node)
	{ return m_neighbours.find(node)->second; }
	NeighbourHood const& getNeighbours(Node::ID node) const
	{ return m_neighbours.find(node)->second; }

	// Pour itérer sur les std::pair<Node::ID, NeighbourHood>
	std::map<Node::ID, NeighbourHood>::iterator begin()
	{ return m_neighbours.begin(); }
	std::map<Node::ID, NeighbourHood>::iterator end()
	{ return m_neighbours.end(); }

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	Path getPath(Node::ID n1, Node::ID n2) const;
	float getDist(Node::ID n1, Node::ID n2);

	private:

	void makePath();

	Branch::ID forceNewEdge(Node::ID n1, Node::ID n2);
	std::map<Node::ID, NeighbourHood> m_neighbours;

	std::map<Node::ID, Node> m_nodes;

	Branch::ID m_branchId;
	std::map<Branch::ID, Branch> m_branchs;

	std::map<std::pair<Node::ID, Node::ID>, std::pair<float, Branch::ID> > m_paths;
};
