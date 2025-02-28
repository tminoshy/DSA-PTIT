//https://github.com/tminoshy
//created by Đỗ Thiện Minh in 19/09/2024

#include <iostream>
#include <string>

using namespace std;

bool isValid(const string& dateString) {
    int date = stoi(dateString.substr(0, 2));
    int month = stoi(dateString.substr(2, 2));
    int year = stoi(dateString.substr(4));
    if (date <= 0 || date > 31 || month <= 0 || month > 12 || year < 2000) {
        return false;
    }
    return true;
}

void generateDates(string currentDate) {
    if (currentDate.size() == 8) {
        if (isValid(currentDate)) {
            currentDate.insert(2, 1, '/');
            currentDate.insert(5, 1, '/');
            cout << currentDate << endl;
        }
        return;
    }
    generateDates(currentDate + "0");
    generateDates(currentDate + "2");
}

void solve() {
    string currentDate = "";
    generateDates(currentDate);
}

int main() {
    solve();
    return 0;
}

//B23DCCE064
//NGÀY ĐẶC BIỆT