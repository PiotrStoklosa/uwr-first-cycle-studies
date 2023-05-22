// Piotr Stoklosa
#include <iostream>
#include <initializer_list>

using namespace std;

template <class T>
class List
{
private:
    class Node
    {
    public:
        T val;
        Node *next;
        Node(T);
        Node();
    };

    Node *head;

public:
    List ();
    ~List ();

    List (const List &);
    List (List &&);

    List<T>& operator = (const List<T> &&);
    List<T>& operator = (const List<T> &);


    void wstaw (T, int);
    void usun (T);
    int wyszukaj (T) const;
    int zlicz () const;

    List(initializer_list<T>);

    friend ostream &operator << (ostream &out, const List &lista)
    {
        Node *temp = lista.head;
        if(temp != NULL)
        {
            while(temp->next != nullptr)
            {
                out << temp->val << " ";
                temp = temp->next;
            }
            out << temp->val;
        }

        return out;
    }

};

template <class T>
List<T>::~List(){
        while(head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        delete head;
    }


template <class T>
List<T>::List() : head(nullptr) {}

template <class T>
List<T>::Node::Node(T x) : val(x), next(nullptr) {}

template <class T>
List<T>::Node::Node() :next(nullptr) {}


template <class T>
List<T>::List (const List &lista)
{
    Node *temp = lista.head;
    head = new Node(temp->val);
    temp = temp->next;
    Node *nowy = head;

    while(temp)
    {
        nowy->next = new Node(temp->val);
        temp = temp->next;
        nowy = nowy->next;
    }
}

template <class T>
List<T>::List(initializer_list<T> l)
    {
        Node *temp = new Node();
        head = temp;

        unsigned int licznik=0;

        for (auto i : l)
        {
            licznik++;

            if (licznik == l.size())
            {
                temp->val = i;
                temp->next = nullptr;
            }
            else
            {
                temp->val = i;
                temp->next = new Node();
                temp = temp->next;
            }
        }
    }

template <class T>
List<T>::List (List &&lista)
{
    head = lista->head;
    lista->head = nullptr;
}

template <class T>
void List<T>::wstaw (T x, int a)
{
    if (head==nullptr)
    {
        head = new Node(x);
    }

    Node *temp = head;

    for (int i=1; i<a; i++)
    {
        if (!temp->next)
            temp->next = new Node(x);

        temp = temp->next;
    }

    Node *wstawiony = new Node(x);
    wstawiony->next=temp->next;
    temp->next = wstawiony;


}

template <class T>
void List<T>::usun (T x)
{
    if(head!=nullptr)
    {
        Node *temp = head;
        if (head->val == x)
        {
            head= head->next;
            return;
        }
        while(temp->next!=nullptr)
        {
            if (temp->next->val==x)
            {
                temp->next=temp->next->next;
                return;
            }
            temp = temp->next;
        }
    }
    cout<<"Nie znaleziono podnaego elementu!\n";
}

template <class T>
int List<T>::wyszukaj (T x) const
{
    int pozycja = -1;
    Node *temp = head;
    while(temp!=nullptr)
    {
        pozycja++;
        if (temp->val==x)
            return pozycja;
        temp = temp->next;
    }
    return -1;
}

template <class T>
int List<T>::zlicz() const
{
    int l = 0;
    Node *temp = head;
    while(temp)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

template <class T>
List<T>& List<T>::operator = (const List<T> &lista){

    delete head;

    Node *temp = lista.head;
    head = new Node(temp->val);
    temp = temp->next;
    Node *nowy = head;

    while(temp)
    {
        nowy->next = new Node(temp->val);
        temp = temp->next;
        nowy = nowy->next;
    }
    return *this;
  }

template <class T>
List<T>& List<T>::operator = (const List<T> &&lista){

    delete head;
    head = lista->head;
    lista->head = nullptr;
    return *this;
  }

