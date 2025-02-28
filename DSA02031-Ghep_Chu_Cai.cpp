//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 18/09/2024

#include <iostream>
#include <vector>

using namespace std;

bool isVowel(char c) {
    return c == 'A' || c == 'E';
}

bool isValid(const vector<char>& characters) {
    for (size_t i = 0; i < characters.size(); i++) {
        if (isVowel(characters[i])) {
            if (i > 0 && i < characters.size() - 1 && !isVowel(characters[i - 1]) && !isVowel(characters[i + 1])) {
                return false;
            }
        }
    }
    return true;
}

void generatePermutation(int index, vector<bool> usedCharacters, vector<char> currentPermutation, vector<char> characters) {
    for (size_t i = 0; i < characters.size(); i++) {
        if (!usedCharacters[i]) {
            currentPermutation[index] = characters[i];
            usedCharacters[i] = true;
            if (index == currentPermutation.size() - 1) {
                if (isValid(currentPermutation)) {
                    for (char c : currentPermutation) {
                    cout << c;
                    }
                    cout << endl;
                }
                
            } else {
                generatePermutation(index + 1, usedCharacters, currentPermutation, characters);
            }
            usedCharacters[i] = false;
        }
    }
}

void solve() {
    char c; cin >> c;
    vector<char> characters;
    for (char x = 'A'; x <= c; x++) {
        characters.push_back(x);
    }
    vector<bool> usedCharacters(characters.size(), false);
    vector<char> currentPermutation(characters.size());
    generatePermutation(0, usedCharacters, currentPermutation, characters);
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//GHÉP CHỮ CÁI