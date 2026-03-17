#pragma once
#include "constValue.h"
#include "Vertex.h"
#include "Edge.h"

class Graph {
public:
	vector<Vertex> vertices; //Danh sach cac dinh cua do thi
	vector<Edge> Edges; // Danh sach cac canh cua do thi
	int draggingID = -1; //Xet dinh dang duoc keo

	void handleEvents();
	void Update();
	void connectSelectedVertices();

	void Draw();
private:


};