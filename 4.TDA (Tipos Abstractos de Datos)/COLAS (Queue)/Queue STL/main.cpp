#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct comparatorInt {
    bool operator()(int i, int j) {
        return i > j;
    }
};

int main() {

    cout << "Priority Queue (MAX)" << endl;
    priority_queue <int> h;
    h.push(2);
    h.push(20);
    h.push(50);
    h.push(3);
    h.push(6);
    h.push(100);
    h.push(15);
    while (!h.empty()) {
        cout << " "<<h.top();
        h.pop();
    }

    cout <<endl << "Priority Queue (MIN)" << endl;

    priority_queue<int, std::vector<int>, comparatorInt > hmim;
    hmim.push(2);
    hmim.push(20);
    hmim.push(50);
    hmim.push(3);
    hmim.push(6);
    hmim.push(100);
    hmim.push(15);
    while ( !hmim.empty() ) {
        cout << " " << hmim.top();
        hmim.pop();
    }
    return 0;
}
