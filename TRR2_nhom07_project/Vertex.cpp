#include "Vertex.h"

using namespace std;


Vertex::Vertex() {
	position = Vector2{ 100,100 }; //Vi tri khoi tao
	color = DARKBLUE; 
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
	//Thay doi mau khi chon 


}

void Vertex::toggleSelected() {
	isSelected = !isSelected;
}

void Vertex::Draw() {
	if (isSelected) color = RED;
	else color = DARKBLUE;
	DrawCircleV(position, radius, color);
}
