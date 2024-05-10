#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

template<typename T>

class LinkedList{
    struct Node {
        T data;
        Node* prev = nullptr;
        Node* next = nullptr;
    };

    Node* head, * tail, * mid;
    size_t count;

public:
    LinkedList() : head(nullptr), tail(nullptr), mid(nullptr), count(0) {}

    ~LinkedList() {
        if (count == 0)
            return;

        Node* temp;
        Node* current = head->next;
        while (current != nullptr) {
            temp = current->next;
            delete current;
            current = temp;
        }
    }

    void push_back(T data) {

        if (tail == nullptr) {
            tail = head = new Node{ data, tail };
        }
        else {
            tail->next = new Node{ data, tail };
            tail = tail->next;
        }

        if (++count == 2) {
            mid = head;
        }
        else if (count % 2 == 0) {
            mid = mid->next;
        }

    }


    void pop_back() {
        if (tail == head) {
            delete tail;
            tail = head = nullptr;
        }
        else {
            Node* secondLast = tail->prev;
            delete tail;
            tail = secondLast;
            tail->next = nullptr;
        }

        if (count % 2 == 0 && mid != nullptr) {
            mid = mid->prev;
        }

        count--;
    }



    const Node* getMid() const {
        return mid;
    }

    void milen() {
        if (mid == nullptr)
            return;

        (tail->next = head)->prev = tail;
        mid->next = (head = mid->next)->prev = nullptr;

        swap(mid, tail);
        if (count % 2 != 0)
            mid = mid->prev;
    }


    void print() const {

        cout << count << '\n';

        for (Node* node = head; node != nullptr; node = node->next) {
            cout << node->data << ' ';
        }

        cout << '\n';
    }
};

int main()
{
    LinkedList<size_t> CheatSheets;
    string command;
    size_t n, CheatSheet;
    cin >> n;

    for (size_t i = 0; i < n; i++) {
        cin >> command;
        if (command == "add")
        {
            cin >> CheatSheet;
            CheatSheets.push_back(CheatSheet);
        }
        else if (command == "gun") {
            CheatSheets.pop_back();
        }
        else if (command == "milen") {
            CheatSheets.milen();
        }
    }

    CheatSheets.print();
    return 0;


}