#include "Vertex.h"

using namespace std;


Vertex::Vertex() {
	position = Vector2{ 100,100 }; //Vi tri khoi tao
	color = DARKBLUE; 
	radius = 30;
	isDragging = false; isSelected = false;
}
Vertex::Vertex(Vector2& initPos, Color& initColor, float& R) {
	position = initPos;
	color = initColor;
	radius = R;
	isDragging = false; isSelected = false;
}


Vector2 Vertex::getPosition() { return position; }
Color Vertex::getColor() { return color; }
float Vertex::getRadious() { return radius; }

void Vertex::setPosition(Vector2& newPos) {
	position = newPos;
}
void Vertex::setColor(Color& newColor) {
	color = newColor;
}
void Vertex::setRadious(float& R) { radius = R; }

void Vertex::handleNodeDragged() {
	//Thay doi mau khi chon 


}


void Vertex::Draw() {

	DrawCircleV(position, radius, color);
}
