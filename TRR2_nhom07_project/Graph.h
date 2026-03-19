#pragma once
#include "constValue.h"
#include "Vertex.h"
#include "Edge.h"

using namespace std;

class Graph {
public:
	vector<Vertex> vertices; //Danh sach cac dinh cua do thi
	vector<Edge> Edges; // Danh sach cac canh cua do thi

	int draggingID;
	
	Graph();

	int findIndexByID(const int&);


	void HandleDraggingVertex();
	void HandleSelectingVertex();
	void HandleConnectSelectedVertices();
	void HandleDeleteSelectedVertices();

	void HandleInputEvents();
	void Update();
	

	void addVertex();
	void removeVertex();
	
	
	void Draw();
private:
	int startNodeID; //Dinh bat dau thuat toan
	int nodeCount; //So luong dinh cua danh sach cac dinh

};