#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Player {
    int id;
    string name;
    int score;
};

class Leaderboard {
    Player arr[MAX];
    int top;

public:
    Leaderboard() {
        top = -1;
    }

    void addPlayer() {
        if (top == MAX - 1) {
            cout << "Leaderboard Full!\n";
            return;
        }

        top++;
        cout << "Enter ID: ";
        cin >> arr[top].id;
    
        cout << "Enter Name: ";
        cin>> arr[top].name;

        cout << "Enter Score: ";
        cin >> arr[top].score;

        cout << "Player Added!\n";
    }

    void deletePlayer() {
        if (top == -1) {
            cout << "Leaderboard Empty!\n";
            return;
        }

        int id;
        cout << "Enter ID to Delete: ";
        cin >> id;

        int index = -1;
        for (int i = 0; i <= top; i++) {
            if (arr[i].id == id) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Player Not Found!\n";
            return;
        }

        cout << "Deleted: " << arr[index].name << endl;

        for (int i = index; i < top; i++) {
            arr[i] = arr[i + 1];
        }

        top--;
    }

    void display() {
        if (top == -1) {
            cout << "Leaderboard Empty!\n";
            return;
        }

        cout << "\nID\tName\tScore\n";
        cout << "---------------------\n";
        for (int i = 0; i <= top; i++) {
            cout << arr[i].id << "\t"
                 << arr[i].name << "\t"
                 << arr[i].score << endl;
        }
    }

    void sortLeaderboard() {
        for (int i = 0; i <= top; i++) {
            for (int j = 0; j < top; j++) {
                if (arr[j].score < arr[j + 1].score) {
                    Player temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        cout << "Sorted by Score!\n";
    }

    void searchPlayer() {
        int id;
        cout << "Enter ID to Search: ";
        cin >> id;

        for (int i = 0; i <= top; i++) {
            if (arr[i].id == id) {
                cout << "Found: "
                     << arr[i].name
                     << " Score: "
                     << arr[i].score << endl;
                return;
            }
        }
        cout << "Player Not Found!\n";
    }
};

int main() {
    Leaderboard lb;
    int ch;

    do {
        cout << "\n1 Add Player";
        cout << "\n2 Delete Player by ID";
        cout << "\n3 Display Leaderboard";
        cout << "\n4 Sort by Score";
        cout << "\n5 Search Player";
        cout << "\n6 Exit";
        cout << "\nEnter Choice: ";
        cin >> ch;

        switch (ch) {
        case 1: lb.addPlayer(); break;
        case 2: lb.deletePlayer(); break;
        case 3: lb.display(); break;
        case 4: lb.sortLeaderboard(); break;
        case 5: lb.searchPlayer(); break;
        case 6: cout << "Exit\n"; break;
        default: cout << "Wrong Choice!\n";
        }
    } while (ch != 6);

    return 0;
}

