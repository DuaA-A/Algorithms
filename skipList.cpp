#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

class Node {
public:
    int key;
    Node** forward;
    Node(int key, int level) {
        this->key = key;
        forward = new Node*[level + 1];
        for (int i = 0; i <= level; i++) {
            forward[i] = nullptr;
        }
    }
    ~Node() {
        delete[] forward;
    }
};

class SkipList {
    int maxLevel;
    float p;
    int level;
    Node* header;

    int randomLevel() {
        int lvl = 0;
        while (((float)rand() / RAND_MAX) < p && lvl < maxLevel) {
            lvl++;
        }
        return lvl;
    }

public:
    SkipList(int maxLevel, float p) : maxLevel(maxLevel), p(p), level(0) {
        header = new Node(-1, maxLevel);
    }

    ~SkipList() {
        delete header;
    }

    void insert(int key) {
    Node* current = header;
    Node** update = new Node*[maxLevel + 1];
    for (int i = 0; i <= maxLevel; i++) {
        update[i] = nullptr;
    }
    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];
    if (current == nullptr || current->key != key) {
        int newLevel = randomLevel();
        if (newLevel > level) {
            for (int i = level + 1; i <= newLevel; i++) {
                update[i] = header;
            }
            level = newLevel;
        }
        Node* newNode = new Node(key, newLevel);
        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
        cout << "Inserted key: " << key << endl;
    }
    delete[] update;
}
    void erase(int key) {
    Node* current = header;
    Node** update = new Node*[maxLevel + 1];
    for (int i = 0; i <= maxLevel; i++) {
        update[i] = nullptr;
    }
    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];
    if (current != nullptr && current->key == key) {
        for (int i = 0; i <= level; i++) {
            if (update[i]->forward[i] != current) break;
            update[i]->forward[i] = current->forward[i];
        }
        delete current;
        
        while (level > 0 && header->forward[level] == nullptr) {
            level--;
        }
        cout << "Deleted key: " << key << endl;
    }
    delete[] update;
}


    void display() {
        cout << "\nSkip List:" << endl;
        for (int i = level; i >= 0; i--) {
            Node* node = header->forward[i];
            cout << "Level " << i << ": ";
            while (node != nullptr) {
                cout << node->key << " ";
                node = node->forward[i];
            }
            cout << endl;
        }
    }
};

int main() {
    srand((unsigned)time(0));
    SkipList list(5, 0.5);

    list.insert(3);
    list.insert(6);
    list.insert(7);
    list.insert(9);
    list.insert(12);
    list.insert(19);
    list.insert(17);
    list.insert(26);
    list.insert(21);
    list.insert(25);
    list.display();
    list.erase(19);
    list.erase(17);
    list.erase(25);
    list.display();

    return 0;
}
