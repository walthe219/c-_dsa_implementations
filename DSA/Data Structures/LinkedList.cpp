// A doubly linked list

#include <string>
#include <iostream>
#include <stdexcept>

template <typename T>
struct Node{
    T value;
    Node<T>* next;
    Node<T>* prev;

    Node(T val) : value{val}, next{nullptr}, prev{nullptr} {};
};

template <typename T> 
class LinkedList{
    public:
        LinkedList() : head{nullptr}, tail{nullptr}, length{0} {};

        ~LinkedList(){
            Node<T>* current = head;
            Node<T>* next;

            while(current!=nullptr){
                next = (*current).next;
                delete current;
                current = next;
            }
        }

        void prepend(T val){
            Node<T>* node = new Node<T>(val);
            node->next = head;
            if(head!=nullptr){
                head->prev = node;
            }
            else{
                tail = node;
            }
            head = node;
            length++;
        }

        void append(T val){
            Node<T>* node = new Node<T>(val);
            node->prev = tail;
            if(tail!=nullptr){
                tail->next = node;
            }
            else{
                head = node;
            }
            tail = node;
            length++;
        }

        bool hasValue(int val){
            return getNodeWithVal(val) != nullptr;

        }

        T getValue(int pos){
            Node<T>* node = getNodeAtPos(pos);

            if(node==nullptr){
                return
            }

            return node->value;
        }

        int getPos(T val){
            
            return n
        }

        void insert(t val, int pos){
            length++;
        }

        void deleteVal(T val){
            Node<T>* node = getNodeWithVal(val);
            deleteNode(node);
        }

        void deleteAt(int pos){
            Node<T>* node = getNodeAtPos(pos);
            deleteNode(node);
        }

        std::string toString(){
            std::string  str = "";
            
            if(head==nullptr){
                str += "Null";
                return str;
            }
            
            Node<T>* current = head;
            str += std::to_string(head->value);
            current = current->next;
            while(current!=nullptr){
                str+= " -> ";
                str += std::to_string(current->value);
                current = current->next;
            }

            return str;
        }

        void print(){
            std::cout<<toString();
        }

    private: 
        Node<T>* head;
        Node<T>* tail;
        int length;

        Node<T>* getNodeWithVal(T val){
            Node<T>* current = head;

            while(current!=nullptr){
                if(current->value == val){
                    return current;
                }
                else{
                    current = current->next;
                }
            }

            return nullptr;
        }

        Node<T>* getNodeAtPos(int pos){
            
            if(pos >= length){
                return nullptr;
            }

            Node<T>* current = head;
            for(int i = 0; i<pos;i++){
                current = current->next;
            }

            return current;            
        }

        void deleteNode(Node<T>* node){
            
            if(node==nullptr){
                throw std::runtime_error("This item does not exist or the list is empty")
            }

            else if(node==head){
                head = node->next;
                if(head!=nullptr){
                    head->prev = nullptr;
                }
                delete node;
                length--;
            }

            else if(node==tail){
                tail = node->prev;
                tail->next = nullptr;
                delete node;
                length--;
            }

            else{
                Node<T>* pre = node->prev;
                Node<T>* nxt = node->next;
                pre->next = nxt;
                nxt->prev = pre;

                delete node;
                length--;
            }
        }
};
