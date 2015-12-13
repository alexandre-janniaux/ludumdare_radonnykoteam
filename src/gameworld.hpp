#pragma once
#include "SFML/Graphics.hpp"
#include <graph/graph.hpp>
#include <splinerenderer.hpp>

class Insect {
public:
  
private:
  InsectType type;
  sf::CircleShape hitbox;
  bool busy;
  Path path; 
};

enum InsectType {LADYBUG, APHID};

enum NodeType{};

class GameWorld
{
    public:
	GameWorld();
	~GameWorld();
	
	void
	render (sf::RenderTarget& target);
	
	void
	update (sf::Time time);
	
	void
	spawnInsect (InsectType type, Node node);
	
	void
	spawnNode (NodeType type, sf::Vector2f position);
	
    private:
	Graph mGraph;
	SplineRenderer mSplineRenderer;
	std::vector<Insect>mLadyBugs;
	std::vector<Insect>mAphids;
	sf::Sprite mBackGround;
};
