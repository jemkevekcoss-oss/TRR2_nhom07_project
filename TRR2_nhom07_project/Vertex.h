#pragma once
#include "constValue.h"

using namespace std;

class Vertex {
public:
	bool isDragging; //Dinh dang duoc keo 
	bool isSelected; //Dinh dang duoc chon 
	
	

	Vertex();
	Vertex(Vector2&, Color&, float&);
	

	Vector2 getPosition();
	Color getColor();
	float getRadious();
	int getID();

	void setPosition(Vector2&);
	void setColor(Color&);
	void setRadious(float&);
	void setID(int&);

	void HandleNodeDragged();
	void toggleSelected();

	void Draw();
private:
	Vector2 position;
	Color   color;
	float  radius; 

	static int autoID;
	int ID; // So thu tu duoc gan vao dinh
};