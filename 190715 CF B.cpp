#include <iostream>
#include <string>
#include <cstring>
//#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int Q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> Q;

	for (int X=0;X<Q;X++){
		int n, m;
		cin >> n >> m;
		int grid[n][m];
		memset(grid, 0, sizeof(grid));
		for (int i=0;i<n;i++){
			string row;
			cin >> row;
			for (int j=0;j<=m;j++){
				if (row[j] == '*') grid[i][j] = 1; // B : 1, W : 0
			}
		}

		int max_black_value_row = 0;
		//int max_black_index_row = 0;
		vector<int> max_black_index_list_row;
		for (int i=0;i<n;i++){
			int curr_black_cnt = 0;
			for (int j=0;j<m;j++){
				if (grid[i][j] == 1) curr_black_cnt += 1;
			}
			if (curr_black_cnt > max_black_value_row) {
				max_black_index_list_row.clear();
				max_black_value_row = curr_black_cnt;
				max_black_index_list_row.push_back(i);
			}
			else if (curr_black_cnt == max_black_value_row) {
				max_black_index_list_row.push_back(i);
			}
		}

		int max_black_value_col = 0;
		//int max_black_index_col = 0;
		vector<int> max_black_index_list_col;		
		for (int j=0;j<m;j++){
			int curr_black_cnt = 0;
			for (int i=0;i<n;i++){
				if (grid[i][j] == 1) curr_black_cnt += 1;
			}
			if (curr_black_cnt > max_black_value_col) {
				max_black_index_list_col.clear();
				max_black_value_col = curr_black_cnt;
				max_black_index_list_col.push_back(j);
			}
			else if (curr_black_cnt == max_black_value_col) {
				max_black_index_list_col.push_back(j);			
			}
		
		}
		// cout << X << "\n";
		// for (int i=0;i<n;++i){
		// 	for (int j=0;j<m;++j){
		// 		cout << grid[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }

		// cout << "max_black_value_row : " << max_black_value_row << "\n";
		// for (int i=0;i<max_black_index_list_row.size();i++){
		// 	cout << max_black_index_list_row[i] << " ";
		// }
		// cout << "\n";

		// cout << "max_black_value_col : " << max_black_value_col << "\n";
		// for (int i=0;i<max_black_index_list_col.size();i++){
		// 	cout << max_black_index_list_col[i] << " ";
		// }	
		// cout << "\n";			

		int answer = 0;

		bool is_crosses_white = false;
		for (int i=0;i<max_black_index_list_row.size();i++){
			for (int j=0;j<max_black_index_list_col.size();j++){
				if (grid[max_black_index_list_row[i]][max_black_index_list_col[j]] == 0) {
					is_crosses_white = true;
					//cout << "okay we got this" << "\n\n";
					break;
				}
			}
			if (is_crosses_white == true) {
				break;
			}
		}

		if (is_crosses_white == false) { // crosses : black
			answer = m + n - max_black_value_row - max_black_value_col;
		}
		else {
			answer = m + n - max_black_value_row - max_black_value_col -1;
		}
		
		cout << answer << "\n";
		
	}	
}
