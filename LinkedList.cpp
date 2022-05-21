
#include <iostream>
using std::cout;
using std::endl;
template<class Key>
class Node{
public:
    Key key;
    //D data;
    Node<Key> *next;
    Node<Key> *prev;
    Node()= default;
    Node(const Key key) : key(key), next(nullptr), prev(nullptr) {};
    ~Node() = default;
};

template<class Key>
class LinkedList
{   Node<Key> *first;
    Node<Key> *last;
    int length;
public:

    LinkedList() : first(nullptr), last(nullptr), length(0) {};
    ~LinkedList()
    {
        Node<Key> *tmp;
        while (first != nullptr)
        {
            tmp = first;
            first = first->next;
            delete tmp->key;
            delete tmp;
        }
    }

    Node<Key> * getFirst() const {
        return first;
    }
    Node<Key>* getLast()const{
        return last;
    }

    Node<Key> *addFirst(const Key key)
    {
        Node<Key> *new_node = new Node<Key>(key);
        if(last== nullptr&& first==nullptr)
        {
            first=new_node;
            last=new_node;
        }
        else
        {
            new_node->next=first;
            first->prev=new_node;
            first=new_node;
        }
        length++;
        return new_node;
    }

    Node<Key> *addEnd(const Key key)
    {
        Node<Key> *new_node = new Node<Key>(key);
        if(last== nullptr&& first==nullptr)
        {
            first=new_node;
            last=new_node;
        }
        else
        {
            last->next=new_node;
            new_node->prev=last;
            last=new_node;
        }
        length++;
        return new_node;
    }

    Node<Key> *addNode(Node<Key>* oldnode,const Key key)
    {
        Node<Key> *new_node = new Node<Key>(key);
        new_node->next = oldnode->next;
        if(oldnode->next != nullptr)
        {
            oldnode->next->prev = new_node;
        }
        new_node->prev = oldnode;
        oldnode->next = new_node;
        length++;
        return new_node;
    }

    bool deletePointer(Node<Key> *ptr)
    {
        if(ptr==first)
        {
            this->first=first->next;

            if(first)
            {
                first->prev=nullptr;
            }
            else
            {
                last = nullptr;
            }
            delete ptr->key;
            delete ptr;
            //ptr=NULL;
            length--;
            return true;
        }
        if(ptr==last)
        {
            this->last=last->prev;
            if(last)
            {
                last->next = nullptr;
            } else
            {
                first= nullptr;
            }
            delete ptr->key;
            delete ptr;
            //ptr=NULL;
            length--;
            return true;
        }
        if (ptr->prev != nullptr)
        {
            ptr->prev->next = ptr->next;
        }

        if (ptr->next != nullptr)
        {
            ptr->next->prev = ptr->prev;
        }
        delete ptr->key;
        delete ptr;
        //ptr=NULL;
        length--;
        return true;
    }

    bool removeByKey(const Key &key) {
        Node<Key> *ptr = first;
        while (ptr != nullptr ) {
            if (*ptr->key == *key) {
                deletePointer(ptr);
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }

    bool contain(const Key& key) {
        Node<Key>* ptr =getFirst();
        while (ptr != nullptr){
            if(*ptr->key == *key){
                return true;
            }
            ptr =ptr->next;
        }
        return false;
    }

    int size() const {
        return this->length;
    }

    void insertBeforeMe(Node<Key> *me, const Key &key) {

        if(me == first ){
            this->addFirst(key);
            return;
        }
        auto *newNode = new Node<Key>(key);
        me->prev->next= newNode;
        newNode->next=me;
        newNode->prev=me->prev;
        me->prev=newNode;
        length++;

    }
};

