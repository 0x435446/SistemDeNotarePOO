#pragma once
#include <utility>

using namespace std;

struct special_position {
	int x1, x2, y1, y2;
};

bool check_pos(special_position k, pair<int, int> obj_pos) {
	return obj_pos.first > k.y1 && obj_pos.first < k.y2 && obj_pos.second > k.x1 && obj_pos.second < k.x2;
}

vector<vector<special_position>> matrix_special_position() {
	special_position aux_pos;
	vector<vector<special_position>> pos_matrix;
	aux_pos.x1 = 10;
	aux_pos.y1 = 5;
	aux_pos.x2 = 20;
	aux_pos.y2 = 10;
	for (int i = 0; i < 5; ++i) {
		aux_pos.x1 = 10;
		aux_pos.x2 = 20;
		vector<special_position> aux_vector;
		for (int j = 0; j < 9; ++j) {
			aux_vector.push_back(aux_pos);
			aux_pos.x1 += 15;
			aux_pos.x2 += 15;
		}
		pos_matrix.push_back(aux_vector);
		aux_pos.y1 += 5;
		aux_pos.y2 += 5;
	}

	return pos_matrix;
}

