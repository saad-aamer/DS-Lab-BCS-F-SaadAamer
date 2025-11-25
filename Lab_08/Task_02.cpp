#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Combatant {
public:
    string name;
    int hp;
    int atk;

    Combatant() {
        name = "";
        hp = 0;
        atk = 0;
    }
    Combatant(string n, int h, int a) {
        name = n;
        hp = h;
        atk = a;
    }
};

class node {
public:
    Combatant data;
    node *left, *right;
    node(Combatant v) : data(v), left(nullptr), right(nullptr) {}
};

class BST {
    node* root;

    node* insertNode(node* t, Combatant x) {
        if (t == nullptr)
            return new node(x);
        if (x.name < t->data.name)
            t->left = insertNode(t->left, x);
        else if (x.name > t->data.name)
            t->right = insertNode(t->right, x);
        return t;
    }

    node* findMin(node* t) {
        while (t && t->left)
            t = t->left;
        return t;
    }

    node* deleteNode(node* t, string nm) {
        if (!t) return nullptr;

        if (nm < t->data.name)
            t->left = deleteNode(t->left, nm);
        else if (nm > t->data.name)
            t->right = deleteNode(t->right, nm);
        else {
            if (!t->left && !t->right) {
                delete t;
                return nullptr;
            }
            else if (!t->left) {
                node* r = t->right;
                delete t;
                return r;
            }
            else if (!t->right) {
                node* l = t->left;
                delete t;
                return l;
            }
            else {
                node* m = findMin(t->right);
                t->data = m->data;
                t->right = deleteNode(t->right, m->data.name);
            }
        }
        return t;
    }

    void inorder(node* t) {
        if (!t) return;
        inorder(t->left);
        cout << t->data.name << "(" << t->data.hp << ") ";
        inorder(t->right);
    }

public:
    BST() : root(nullptr) {}

    void insert(Combatant v) { root = insertNode(root, v); }

    void removeByName(string s) { root = deleteNode(root, s); }

    void display() {
        inorder(root);
        cout << endl;
    }

    node* getFrontline() {
        return findMin(root);
    }

    bool empty() {
        return root == nullptr;
    }
};

int dmgBonus() {
    return rand() % 5;
}

void attack(Combatant &a, Combatant &b) {
    int dmg = a.atk + dmgBonus();
    b.hp -= dmg;
    if (b.hp < 0) b.hp = 0;
    cout << a.name << " hits " << b.name << " for " << dmg << endl;
    cout << b.name << " HP: " << b.hp << endl;
}

int main() {
    srand(time(0));

    BST heroes, foes;

    heroes.insert(Combatant("Auron", 32, 6));
    heroes.insert(Combatant("Bren", 27, 5));
    heroes.insert(Combatant("Ciri", 25, 7));
    heroes.insert(Combatant("Daren", 23, 6));
    heroes.insert(Combatant("Elin", 28, 5));

    foes.insert(Combatant("Ghoul", 20, 4));
    foes.insert(Combatant("Ogre", 26, 6));
    foes.insert(Combatant("Serpent", 19, 5));
    foes.insert(Combatant("Wasp", 18, 3));
    foes.insert(Combatant("Shade", 25, 7));

    int round = 1;

    while (!heroes.empty() && !foes.empty()) {
        cout << "---------------\nRound " << round << "\n---------------\n";
        cout << "Heroes: "; heroes.display();
        cout << "Enemies: "; foes.display();

        node* h = heroes.getFrontline();
        node* e = foes.getFrontline();

        cout << "\nArena: " << h->data.name << " vs " << e->data.name << endl;

        attack(h->data, e->data);

        if (e->data.hp <= 0) {
            cout << e->data.name << " defeated\n\n";
            foes.removeByName(e->data.name);
            round++;
            continue;
        }

        attack(e->data, h->data);

        if (h->data.hp <= 0) {
            cout << h->data.name << " defeated\n\n";
            heroes.removeByName(h->data.name);
        }

        round++;
        cout << endl;
    }

    cout << "----------------------\n";

    if (heroes.empty() && foes.empty())
        cout << "Draw\n";
    else if (heroes.empty())
        cout << "Enemies Win\n";
    else
        cout << "Heroes Win\n";

    cout << "----------------------\n";

    return 0;
}
