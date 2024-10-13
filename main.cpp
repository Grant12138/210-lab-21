#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class Goat
{
    private:
        int age;
        string name;
        string color;
        const string NAMES[15] = {"Billy", "Nanny", "Buttercup", "Daisy", "Clover", "Jasper",
                                  "Ivy", "Willow", "Maple", "Fern", "Sage", "Olive", "Hazel",
                                  "Aspen", "Birch"};
        const string COLORS[15] = {"White", "Black", "Brown", "Grey", "Spotted", "Piebald",
                                   "Golden", "Pinto", "Roan", "Red", "Cream", "Silver", "Blue",
                                   "Orange", "Green"};

    public:
        // Default constructor
        Goat()
        {
            age = rand() % 20  + 1;
            name = NAMES[rand() % 15];
            color = COLORS[rand() % 15];
        }

        // Parametrized constructor
        Goat(int a, string n, string c) : age(a), name(n), color(c) {}

        // getters
        string getName() const { return name; }
        string getColor() const { return color; }
        int getAge() const { return age; }
};

class DoublyLinkedList
{
    private:
        struct Node
        {
            Goat data;
            Node* prev;
            Node* next;
            Node(Goat val, Node* p = nullptr, Node* n = nullptr) : data(val), prev(p), next(n) {}
        };

        Node* head;
        Node* tail;
    public:
        // constructor
        DoublyLinkedList() { head = nullptr; tail = nullptr; }

        void push_back(Goat value)
        {
            Node* newNode = new Node(value);
            if (!tail) // if there is no tail, the list is empty
                head = tail = newNode;
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void push_front(Goat value)
        {
            Node* newNode = new Node(value);
            if (!head) // if there's no head, the list is empty
                head = tail = newNode;
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        void insert_after(Goat value, int position)
        {
            if (position < 0)
            {
                cout << "Position must be >= 0." << endl;
                return;
            }

            Node* newNode = new Node(value);
            if (!head)
            {
                head = tail = newNode;
                return;
            }

            Node* temp = head;
            for (int i = 0; i < position && temp; ++i)
                temp = temp->next;

            if (!temp)
            {
                cout << "Position exceeds list size. Node not inserted.\n";
                delete newNode;
                return;
            }

            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next)
                temp->next->prev = newNode;
            else
                tail = newNode; // Inserting at the end
            temp->next = newNode;
        }

        void delete_node(int value)
        {
            if (!head) return; // Empty list

            Node* temp = head;
            while (temp && temp->data != value)
                temp = temp->next;

            if (!temp) return; // Value not found

            if (temp->prev)
                temp->prev->next = temp->next;
            else
                head = temp->next; // Deleting the head

            if (temp->next)
                temp->next->prev = temp->prev;
            else
                tail = temp->prev; // Deleting the tail

            delete temp;
        }

        void print()
        {
            Node* current = head;
            if (!current) return;
            while (current)
            {
                cout << current->data.getName() << " (" << current->data.getColor() << ", " << current->data.getAge() << ")\n";
                current = current->next;
            }
            cout << endl;
        }

        void print_reverse()
        {
            Node* current = tail;
            if (!current) return;
            while (current)
            {
                cout << current->data.getName() << " (" << current->data.getColor() << ", " << current->data.getAge() << ")\n";
                current = current->prev;
            }
            cout << endl;
        }

        ~DoublyLinkedList()
        {
            while(head)
            {
                Node* temp = head;
                head = temp->next;
                delete temp;
            }
        }
};

// Driver program
int main()
{
    srand(time(0));

    DoublyLinkedList list;
    int size = rand() % 16 + 5;

    for (int i = 0; i < size; ++i)
    {
        Goat randomGoat
    }
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}