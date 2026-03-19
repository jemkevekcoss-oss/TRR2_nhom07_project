#include "Graph.h"

using namespace std; 


Graph::Graph() {
	startNodeID = 0;
	nodeCount = 0;
	draggingID = NOT_DRAGGING;

	addVertex(); //Try
}


int Graph::findIndexByID(const int& id) {
	for (int i = 0; i < (int)vertices.size(); i++) {
		if (vertices[i].getID() == id) return i;
	}
	return NONE_KEY; // Không thấy
}

void Graph::HandleDraggingVertex() {
	Vector2 mPos = GetMousePosition();
	// Xu ly Keo tha (MOUSE LEFT BUTTON)
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		for (int i = 0; i < vertices.size(); i++) {
			if (CheckCollisionPointCircle(mPos, vertices[i].getPosition(), vertices[i].getRadious())) {
				//draggingID = i;
				draggingID = vertices[i].getID();

				break; // Chi lay 1 dinh 
			}
		}
	}
	// Kết thúc kéo (Chuyển từ Update sang đây cho đồng bộ)
	if (draggingID != NOT_DRAGGING) {
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
			draggingID = NOT_DRAGGING;
		}
	}
	
}
void Graph::HandleSelectingVertex() {
	Vector2 mPos = GetMousePosition();
	// Xu ly chon dinh (MOUSE RIGHT BUTTON)
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
		for (int i = 0; i < vertices.size(); i++) {
			if (CheckCollisionPointCircle(mPos, vertices[i].getPosition(), (float)vertices[i].getRadious())) {
				vertices[i].toggleSelected(); //Bat tat mau khi nhan chuot phai
				
				break; // Chi lay 1 dinh tron 
			}
		}
	}
}
void Graph::HandleConnectSelectedVertices() {
	if (IsKeyPressed(KEY_C)) {
		vector<int> selectedIndices; //Temporary contaner
		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i].isSelected) {
				selectedIndices.push_back(vertices[i].getID());
				//Gia su dinh thu i co chi so la i
			}
		}
		for (int i = 0; i < selectedIndices.size() - 1; i++) {
			for (int j = i + 1; j < selectedIndices.size(); j++) {
				int u = selectedIndices[i];
				int v = selectedIndices[j];

				//Chi them nhung canh chua ton tai
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
}
void Graph::HandleDeleteSelectedVertices() {
	if (IsKeyPressed(KEY_X)) {
		vector<int> selectedIndices; //Temporary contaner
		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i].isSelected) {
				selectedIndices.push_back(vertices[i].getID());
				//Gia su dinh thu i co chi so la i
			}
		}
		for (int i = 0; i < selectedIndices.size() - 1; i++) {
			for (int j = i + 1; j < selectedIndices.size(); j++) {
				int u = selectedIndices[i];
				int v = selectedIndices[j];


				// Tìm và xóa cạnh nối giữa u và v (nếu có)
				for (auto it = Edges.begin(); it != Edges.end(); ) {
					if ((it->u == u && it->v == v) || (it->v == u && it->u == v)) {
						it = Edges.erase(it); // Xóa và lấy iterator kế tiếp
						// Nếu đồ thị đơn (chỉ có 1 cạnh giữa u,v) thì có thể break ở đây
						break;
					}
					else {
						++it;
					}
				}

			}
		}
		// Sau khi xóa xong thì bỏ chọn tất cả
		for (auto& v : vertices) v.isSelected = false;
	}
}

void Graph::HandleInputEvents() {
	HandleDraggingVertex();
	HandleSelectingVertex();
	HandleConnectSelectedVertices();
	HandleDeleteSelectedVertices();


}

void Graph::Update() {
	//Cap nhat toa do khi keo dinh
	Vector2 mPos = GetMousePosition();
	if (draggingID != NOT_DRAGGING) {
		int idx = findIndexByID(draggingID);
		if (idx != NONE_KEY) {
			vertices[idx].setPosition(mPos);
		}
	}
}


void Graph::addVertex() { //Try
	int verCount = 100;
	for (int i = 1; i <= verCount; i++) {
		Vertex ver;
		ver.setID(i);
		vertices.push_back(ver);
	}
}
void Graph::removeVertex() {


}

void Graph::Draw() {
	//Ve cac canh cua do thi
	// 1. Vẽ các cạnh của đồ thị
	
		for (Edge& e : Edges) {
			int idxU = findIndexByID(e.u); // Tìm vị trí đỉnh đầu
			int idxV = findIndexByID(e.v); // Tìm vị trí đỉnh cuối

			// Chỉ vẽ nếu cả 2 đỉnh đều tồn tại trong mảng
			if (idxU != NONE_KEY && idxV != NONE_KEY) {
				Vector2 startPos = vertices[idxU].getPosition();
				Vector2 endPos = vertices[idxV].getPosition();

				DrawLineEx(startPos, endPos, 5.0f, BLACK);

				// (Tùy chọn) Nếu có trọng số, bạn có thể vẽ thêm text ở trung điểm cạnh ở đây
			}
		}
	
	

	//Ve cac dinh cua do thi
	
		for (Vertex& v : vertices) {
			v.Draw();
		}
	
	
}


