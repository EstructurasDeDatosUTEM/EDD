
    #include <iostream>
    #include <queue>
    using namespace std;

    int main() {
        cout << "Queue Cola (Libreria C++)" << endl;
        queue<int> c;
        c.push(1);
        c.push(2);
        c.push(3);
        c.push(4);
        c.push(5);

        while(!c.empty()) {
            cout << c.front()<<endl;
            c.pop();
        }
        return 0;
    }

