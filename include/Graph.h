#pragma once
#include "constValue.h"
#include "Vertex.h"
#include "Edge.h"


class Graph {
public:
	vector<Vertex> vertices; //Danh sach cac dinh cua do thi
	vector<Edge> Edges; // Danh sach cac canh cua do thi



	void HandleInputEvents();
	void Update();
	void connectSelectedVertices();

	void Draw();
private:
	int startNodeID; //Dinh bat dau thuat toan
	int nodeCount; //So luong dinh cua danh sach cac dinh

};