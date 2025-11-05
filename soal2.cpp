#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<string> normalQueue;
    queue<string> emergencyQueue;

    for(int i = 0; i < N; i++) {
        string command;
        cin >> command;

        if(command == "DATANG") {
            string name;
            cin >> name;
            normalQueue.push(name);
        } 
        else if(command == "DARURAT") {
            string name;
            cin >> name;
            emergencyQueue.push(name);
        } 
        else if(command == "LAYANI") {
            if(!emergencyQueue.empty()) {
                cout << emergencyQueue.front() << endl;
                emergencyQueue.pop();
            } 
            else if(!normalQueue.empty()) {
                cout << normalQueue.front() << endl;
                normalQueue.pop();
            }
        }
    }
    return 0;
}//Masukkan jawaban disini
