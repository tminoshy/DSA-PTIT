//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 16/10/2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct dictionary {
    vector<pair<int, int>> direction{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    vector<string> words;
    vector<vector<char>> dic;
    vector<string> result;
    vector<vector<bool>> visited;

    dictionary(int K, int M, int N) : words(K), dic(M, vector<char>(N)), visited(M, vector<bool>(N)) {}
};

void findWord(int K, int M, int N, int row, int col, string s, dictionary &a) {
    for (int i = 0; i < K; i++) {
        if (a.words[i] == s) {
            a.result.push_back(s);
        }
    }

    for (int i = 0; i < 8; i++) {
        int newRow = row + a.direction[i].first;
        int newCol = col + a.direction[i].second;
        if (newRow >= 0 && newRow < M && newCol >= 0 && newCol < N && !a.visited[newRow][newCol]) {
            a.visited[newRow][newCol] = true;
            findWord(K, M, N, newRow, newCol, s + a.dic[newRow][newCol], a);
            a.visited[newRow][newCol] = false;
        }
    }
}

void testcase() {
    int K, M, N;
    cin >> K >> M >> N;
    dictionary a(K, M, N);
    for (string &word : a.words) {
        cin >> word;
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a.dic[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                fill(a.visited[k].begin(), a.visited[k].end(), false);
            }
            a.visited[i][j] = true;
            string s = "";
            findWord(K, M, N, i, j, s + a.dic[i][j], a);
        }
    }

    if (!a.result.size()) {
        cout << "-1" << '\n';
        return;
    }
    for (const string &s : a.result) {
        cout << s << " ";
    }
    cout << '\n';
}

int main() {
    int testCaseCount;
    cin >> testCaseCount;
    while (testCaseCount--) {
        testcase();
    }
    return 0;
}

//B23DCCE064
//TỪ ĐIỂN