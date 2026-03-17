#include "Graph.h"

using namespace std; 

void Graph::handleEvents() {
	Vector2 mPos = GetMousePosition();
	// Xu ly Keo tha (MOUSE LEFT BUTTON)
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		for (int i = 0; i < vertices.size(); i++) {
			if (CheckCollisionPointCircle(mPos, vertices[i].getPosition(), (float)vertices[i].getRadious())) {
				draggingID = i;

				break; // Chi lay 1 dinh tron 
			}
		}
	}
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		draggingID = -1; // Toa do dinh se ko dc gan theo toa do chuot nua
	}
	// Xu ly chon dinh (MOUSE RIGHT BUTTON)
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
		for (int i = 0; i < vertices.size(); i++) {
			if (CheckCollisionPointCircle(mPos, vertices[i].getPosition(), (float)vertices[i].getRadious())) {
				vertices[i].toggleSelected(); //Bat tat mau khi nhan chuot phai
				break; // Chi lay 1 dinh tron 
			}
		}
	}

	if (IsKeyPressed(KEY_C)) {
		connectSelectedVertices();
	}

}

void Graph::Update() {

	if (draggingID != -1) {
		vertices[draggingID].setPosition(GetMousePosition());

	}

}

void Graph::connectSelectedVertices() {
	vector<int> selectedIndices;


	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].isSelected) {
			selectedIndices.push_back(i);
			//Gia su dinh thu i co chi so la i
		}
	}
	for (int i = 0; i < selectedIndices.size() - 1; i++) {
		for (int j = i + 1; j < selectedIndices.size(); j++) {
			int u = selectedIndices[i];
			int v = selectedIndices[j];

			bool existed = false;
			if (!Edges.empty()) {
				for (Edge e : Edges) {
					if ((e.u == u && e.v == v) || (e.v == u && e.u == v)) {
						existed = true;
						break;
					}
				}
			}

			if (!existed) {
				Edge e; e.u = u; e.v = v;
				Edges.push_back(e);
			}
		}
	}
	// Sau khi nối xong thì bỏ chọn tất cả
	for (auto& v : vertices) v.isSelected = false;

}

void Graph::Draw() {


	//Ve cac canh cua do thi
	for (auto& e : Edges) {
		DrawLineEx(vertices[e.u].getPosition(), vertices[e.v].getPosition(), 5.0f, GRAY);
	}

	//Ve cac dinh cua do thi
	for (auto& v : vertices) {
		v.Draw();
	}
}
