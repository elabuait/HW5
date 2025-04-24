
#ifndef CLASSES_H
#define CLASSES_H


template<class T>
class MyList;
    template< class T >
    class Node {
        friend class MyList<T>;
    public:
        Node(const T& theData, Node<T>* theLink)
                    : data(theData), link(theLink){}
        Node<T>* getLink( ) const { return link; }
        const T& getData( ) const { return data; }
        void setData(const T& theData) { data = theData; }
        void setLink(Node<T>* pointer) { link = pointer; }
    private:
        T data;
        Node<T> *link;
    };
template< class T >
class MyList {
public:
    MyList(): head(0) {};
    void insertHead(const T& theData);
    T deleteHead();
    bool search(T& target);
    void display() const;
private:
    Node<T> *head;
};


#endif //CLASSES_H