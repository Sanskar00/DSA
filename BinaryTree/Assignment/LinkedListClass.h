template <typename T>

class LinkedList
{
    
public:
    T data;
    LinkedList * next;
    LinkedList(T data){
        this->data=data;
        this->next=NULL;
    };
};


