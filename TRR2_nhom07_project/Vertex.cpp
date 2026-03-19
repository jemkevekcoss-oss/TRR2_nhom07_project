#include "Vertex.h"

using namespace std;


Vertex::Vertex() {
	position = Vector2{ 100,100 }; //Vi tri khoi tao
	color = GRAY; 
	radius = 30;
	
	ID = 0;
	isDragging = false; isSelected = false;
}
int Vertex::autoID = 0;

Vertex::Vertex(Vector2& initPos, Color& initColor, float& R) {
	position = initPos;
	color = initColor;
	radius = R;
	isDragging = false; isSelected = false;
}


Vector2 Vertex::getPosition() { return position; }
Color Vertex::getColor() { return color; }
float Vertex::getRadious() { return radius; }
int Vertex::getID() { return ID; }

void Vertex::setPosition(Vector2& newPos) {
	position = newPos;
}
void Vertex::setColor(Color& newColor) {
	color = newColor;
}
void Vertex::setRadious(float& R) { radius = R; }
void Vertex::setID(int& id) { ID = id; }


void Vertex::HandleNodeDragged() {
	


}

void Vertex::toggleSelected() {
	isSelected = !isSelected;
}

void Vertex::Draw() {
	if (isSelected) color = RED;
	else color = GRAY;
	DrawCircleV(position, radius, color);

	const char* idText = TextFormat("%d", ID);

	int fontSize = 20;
	int textWidth = MeasureText(idText, fontSize);

	DrawText(idText,(int)position.x-textWidth/2,(int)position.y-fontSize/2,fontSize,WHITE);


}
