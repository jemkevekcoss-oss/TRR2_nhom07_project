#include "Vertex.h"

using namespace std;



Vertex::Vertex(Vector2 initPos, Color initColor, double R) {
	position = initPos;
	color = initColor;
	radius = R;
	isDragging = false; isSelected = false;
}

Vector2 Vertex::getPosition() { return position; }
Color Vertex::getColor() { return color; }
double Vertex::getRadious() { return radius; }


void Vertex::setPosition(Vector2 newPos) {
	position = newPos;
}
void Vertex::setColor(Color newColor) {
	color = newColor;
}


void Vertex::handleCircleDragged() {
	Vector2 mousePos = GetMousePosition();
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		if (CheckCollisionPointCircle(mousePos, position, 40)) {
			isDragging = true;

		}
	}
	if (isDragging) {
		position = mousePos;
		color = RED; // Đổi màu cho sinh động khi kéo

		// 3. Nếu thả chuột ra thì ngừng kéo
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
			isDragging = false;
			color = DARKBLUE;
		}
	}

}
void Vertex::toggleSelected() { isSelected = !isSelected; } // :))(


void Vertex::Draw() {

	if (isSelected) color = RED;
	else color = DARKBLUE;
	DrawCircleV(position, (float)radius, color);

}

