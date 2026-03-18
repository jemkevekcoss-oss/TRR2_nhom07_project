#pragma once
#include "constValue.h"


class Vertex {
public:
	bool isDragging; //Dinh dang duoc keo 
	bool isSelected; //Dinh dang duoc chon 

	Vertex();
	Vertex(Vector2&, Color&, float&);

	Vector2 getPosition();
	Color getColor();
	float getRadious();

	void setPosition(Vector2&);
	void setColor(Color&);
	void setRadious(float&);

	void handleNodeDragged();

	void Draw();
private:
	Vector2 position;
	Color   color;
	float  radius; 

};