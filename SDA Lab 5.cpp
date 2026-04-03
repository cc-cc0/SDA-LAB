#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Структура узла бинарного дерева поиска
struct Node {
    int data;       // поле данных
    Node* left;     // указатель на левое поддерево
    Node* right;    // указатель на правое поддерево

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Вставка элемента в BST
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    else {
        cout << "Элемент " << value << " уже существует в дереве, повтор не добавлен." << endl;
    }

    return root;
}

// Прямой обход (preorder, NLR)
void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Центрированный обход (inorder, LNR)
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Обратный обход (postorder, LRN)
void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Обход в глубину (DFS)
// Реализован рекурсивно по схеме preorder
void dfs(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    dfs(root->left);
    dfs(root->right);
}

// Обход в ширину (BFS)
void bfs(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

// Поиск элемента с выводом дополнительной информации
bool searchWithInfo(Node* root, int key, int depth, string path) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == key) {
        cout << "Элемент найден." << endl;
        cout << "Значение узла: " << root->data << endl;
        cout << "Глубина узла: " << depth << endl;
        cout << "Путь от корня: " << (path.empty() ? "Корень" : path) << endl;
        return true;
    }

    if (key < root->data) {
        return searchWithInfo(root->left, key, depth + 1, path + "L ");
    }
    else {
        return searchWithInfo(root->right, key, depth + 1, path + "R ");
    }
}

// Освобождение памяти
void deleteTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    setlocale(LC_ALL, "RU");

    Node* root = nullptr;
    int n;

    cout << "Введите количество элементов дерева: ";
    cin >> n;

    if (cin.fail() || n < 0) {
        cout << "Ошибка ввода количества элементов." << endl;
        return 1;
    }

    cout << "Введите элементы дерева:" << endl;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Элемент " << i + 1 << ": ";
        cin >> value;

        if (cin.fail()) {
            cout << "Ошибка ввода элемента." << endl;
            deleteTree(root);
            return 1;
        }

        root = insertNode(root, value);
    }

    if (root == nullptr) {
        cout << "Дерево пустое." << endl;
        return 0;
    }

    int choice;

    do {
        cout << "\nМЕНЮ\n";
        cout << "1. Прямой обход (preorder)\n";
        cout << "2. Центрированный обход (inorder)\n";
        cout << "3. Обратный обход (postorder)\n";
        cout << "4. Обход в глубину (DFS)\n";
        cout << "5. Обход в ширину (BFS)\n";
        cout << "6. Поиск элемента\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Ошибка ввода." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Прямой обход: ";
            preorder(root);
            cout << endl;
            break;

        case 2:
            cout << "Центрированный обход: ";
            inorder(root);
            cout << endl;
            break;

        case 3:
            cout << "Обратный обход: ";
            postorder(root);
            cout << endl;
            break;

        case 4:
            cout << "DFS: ";
            dfs(root);
            cout << endl;
            break;

        case 5:
            cout << "BFS: ";
            bfs(root);
            cout << endl;
            break;

        case 6: {
            int key;
            cout << "Введите ключ для поиска: ";
            cin >> key;

            if (cin.fail()) {
                cout << "Ошибка ввода." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }

            if (!searchWithInfo(root, key, 0, "")) {
                cout << "Элемент " << key << " не найден в дереве." << endl;
            }
            break;
        }

        case 0:
            cout << "Выход из программы." << endl;
            break;

        default:
            cout << "Неверный выбор." << endl;
        }

    } while (choice != 0);

    deleteTree(root);
    return 0;
}