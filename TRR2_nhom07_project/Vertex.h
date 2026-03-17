#pragma once
#include "constValue.h"


class Vertex {
public:
	bool isDragging;
	bool isSelected;

	Vertex() {
		position = Vector2{ 100,100 };
		color = DARKBLUE;
		radius = nodeRadius;
		isDragging = false; isSelected = false;
	}
	Vertex(Vector2, Color, double);

	Vector2 getPosition();
	Color getColor();
	double getRadious();

	void setPosition(Vector2);
	void setColor(Color);
	void handleCircleDragged();
	void toggleSelected(); 


	void Draw();

private:
	Vector2 position;
	Color   color;
	float radius;

};