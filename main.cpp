/***************************************************************************
* COMSC-210 | Lab 21 | Grant Luo
* Editor: CLion
* Compiler: Apple clang version 16.0.0
*/
#include <iostream>
using namespace std;

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

void print_id(string const& lab_desc);

// Driver program
int main()
{
    print_id("Goat Herd Manager 3000");

    srand(time(0));

    DoublyLinkedList list;
    int size = rand() % 16 + 5; // A random size between 5 and 20

    for (int i = 0; i < size; ++i)
    {
        Goat randomGoat;
        list.push_back(randomGoat);
    }
    cout << "List forward:\n";
    list.print();

    cout << "List backward:\n";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward:\n";
    list.print();

    return 0;
}

void print_id(string const& lab_desc)
{
    cout << "\nCOMSC210 | Grant Luo | " << lab_desc << "\n";
    cout << "Editor: CLion\n";
    cout << "Compiler: Apple clang version 16.0.0\n";
    cout << "File: " << __FILE__ << "\n";
    cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
}