#include <iostream>
using namespace std;

class Array {
    /*
    create = constructor
    bool isEmpty()
    bool isFull()
    void Fill()
    void Display()
    void InsertIndex(int index, int value)
    void InsertLast = Append(int value)
    void DeleteFirst()
    void DeleteLast()
    bool Search(int key)
    bool DeleteIndex(int item)
    bool DeleteItem(int item)
    int* Sort() // بترجع آراي
    int* BubbleSort() // بترجع آراي
    int BinarySearch(int value)

    */
private:
    int size;
    int length;
    int* items;

public:
    //Creation
    Array(int size) {
        this->size = size;
        length = 0;
        items = new int[size];
    }
    //is empty ? ---> Boolean //بسختدمها في ال validations
    bool isEmpty() {
        return (length == 0);
    }
    //is full ? ---> Boolean //بسختدمها في ال validations
    bool isFull() {
        return (length == size);
    }
    //Filling the array // لازم الاراي تكون فاضية
    void Fill() {
        if (isEmpty()) {
            cout << "Enter number of items: ";
            int number;
            cin >> number;
            if (number <= 0 || number > size) {
                cout << "Invalid number\n";
                return;
            }
            for (int i = 0; i < number; i++) {
                cout << "Enter item number " << (i + 1) << ": ";
                cin >> items[i];
                length++;
                cout << endl;
            }
        }
        else {
            cout << "Array shpuld be empty!\n";
        }
    }
    //Displaying elements
    void Display() {
        if (isEmpty()) {
            cout << "No items to display\n";
            return;
        }
        for (int i = 0; i < length; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
    //Inserting in specific index
    void InsertIndex(int index, int value) {
        if (isFull()) {
            cout << "Can not insert an element\n";
            return;
        }
        if (index < 0 || index > length) {
            cout << "Invalid position\n";
            return;
        }
        for (int i = length; i > index; i--) {
            items[i] = items[i - 1];
        }
        items[index] = value;
        length++;
    }
    void InsertFirst(int value) {
        //InsertIndex(0, value);
        if (isFull()) {
            cout << "Can not insert an element\n";
            return;
        }
        if (!isEmpty()) {
            for (int i = length; i > 0; i--) {
                items[i] = items[i - 1];
            }
            items[0] = value;
            length++;
        }
        else {
            items[0] = value;
            length++;
        }
    }
    void InsertLast(int value) {
        //  InsertIndex(0, value);
        if (isFull()) {
            cout << "Can not insert an element\n";
            return;
        }
        if (isEmpty()) {
            items[0] = value;
            length++;
        }
        else {
            items[length++] = value;
        }
    }
    //Deleting specific index
    void DeleteIndex(int index) {
        if (isEmpty()) {
            cout << "Array is Empty, no items to delete\n";
            return;
        }
        if (index >= 0 && index < length) {
            for (int i = index; i < length; i++) {
                items[i] = items[i + 1];
            }
            length--;
        }
        else {
            cout << "Index is not valid\n";
        }
    }
    //Delete specific item
    void DeleteItem(int item) {
        int index = -1;
        if (isEmpty()) {
            cout << "Array is Empty, no items to delete\n";
            return;
        }
        //int index = Search(item);
        for (int i = 0; i < length; i++) {
            if (items[i] == item)
                index = i;
        }
        if (index >= 0 && index < length) { // الكوندشن في الاو كان صح دايما 
            for (int i = index; i < length - 1; i++) { // -1 لان الاول كان هيخليني اطلع برا حدود الاراي
                items[i] = items[i + 1];
            }
            length--;
        }
        else
            cout << "Item is not found\n";
    }
    //Searching for a specific item
    int Search(int item) {
        if (isEmpty()) {
            cout << "Array is Empty\n";
            return -1;
        }
        int index = -1;
        for (int i = 0; i < length;i++) {
            if (items[i] == item) {
                index = i;
                break; // هيرجع اول ظهور للعنصر // لو عايزاه اخر عنصر احوش بريك
            }
        }
        return index;
    }
    //Bubble Sort
    /*int* BubbleSort() {                                      // Modifies the original array
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - i - 1;j++) {
                if (items[j] > items[j + 1]) {
                    int temp = items[j + 1];
                    items[j + 1] = items[j];
                    items[j] = temp;
                }
            }
        }
        return items;
    }*/
    int* BubbleSort() {                                       //Doesn't Modify the original array
        int* newarr = new int[length];
        for (int i = 0; i < length; i++) {
            newarr[i] = items[i]; // بخزن في اراي جديدة وصلتلها بالبوينتر
        }
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - i - 1;j++) {
                if (newarr[j] > newarr[j + 1]) {
                    int temp = newarr[j + 1];
                    newarr[j + 1] = newarr[j];
                    newarr[j] = temp;
                }
            }
        }
        return newarr;
    }
    int getLength() {
        return length;
    }
    int* Sort() {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - 1;j++) {
                if (items[j] > items[j + 1]) {
                    int temp = items[j + 1];
                    items[j + 1] = items[j];
                    items[j] = temp;
                }
            }
        }
        return items;
    }
    //Binary search
    int BinarySearch(int key) {

        Sort();// لازم اعمب سورت الاول // استخدم اي الجوريثم فيهمةىحكح

        if (isEmpty()) {
            cout << "Array is Empty\n";
            return -1;
        }
        int min = 0;
        int max = length - 1;
        int index = -1;
        while (min <= max) {
            int mid = (min + max) / 2;
            if (key > items[mid])
                min = mid + 1;
            else if (key < items[mid])
                max = mid - 1; // بعدل الكاكس مش المين
            else
            {
                index = mid;
                break;
            }
        }
        return index;
    }
};
class Node {
public:
    int Data;
    Node* Next;
    Node* Left;
    Node* Right;

    Node(int data) {
        Data = data;
        Left = Right = NULL;
    }
    Node() {
        Data = 0;
        Next = NULL;
    }
    Node(int Data) {
        this->Data = Data;
        Next = NULL;
    }
};
class LinkedList {
    /*
    Create --> Constructor 
    bool isEmpty()
    void Traverse()
    int Count() --> هيعد النود
    int Search(int key)
    void InsertFirst(int value)
    void InsertLast(int value)
    void InsertBeforPosition(int item, int value)
    void InsertAfterPosition(int item, int value)
    void DeleteFirst()
    void DeleteLast()
    void DeleteItem()
    void Replace(int item, int newvalue)
    */
private:
    Node* Head;
public:
    LinkedList() {
        Head = NULL;
    }
    bool isEmpty() {
        return (Head == NULL);
    }
    void Traverse() {
        if (isEmpty()) {
            cout << "List is empty, no items to traverse!\n";
            return;
        }
        Node* temp = Head;
        cout << "List item: ";
        while (temp != NULL) {
            cout << temp->Data << " ";
            temp = temp->Next;
        }
        cout << endl;
    }
    
    int Count() {
        int counter = 0;
        if (isEmpty()) {
            cout << "List is empty, no items to count!\n";
        }
        else {
            Node* temp = Head;
            while (temp != NULL) {
                counter++;
                temp = temp->Next;
            }
        }
        return counter;
    }
    //int Search(int key) {
    //    int k = -1;
    //    if (isEmpty()) {
    //        cout << "List is empty, no items to search for!\n";
    //    }
    //    else {
    //        Node* temp = Head;
    //        while (temp->Data != key) {
    //            temp = temp->Next;

    //            if (temp->Data == key) {
    //                k = temp->Data;
    //                break;
    //            }
    //        }
    //    }
    //    return k;
    //}
    bool Search(int key) {
        bool found = false;
        if (isEmpty()) {
            cout << "List is empty!";
            found = false;
        }
        else {
            Node* temp = Head;
            while (temp != NULL) {
                if (temp->Data == key) {
                    found = true;
                    break;
                }
                temp = temp->Next;
            }
        }
        return found;
    }
    void InsertFirst(int value) {
        Node* newnode = new Node; // من غير نيو مش هيرضي يعمل رن  // Creating new node
        newnode->Data = value;
        if (isEmpty()) {
            newnode->Next = NULL;
            Head = newnode;
        }
        else {
            newnode->Next = Head;
            Head = newnode;
        }
    }
    void InsertLast(int value) {
        Node* newnode = new Node;
        newnode->Data = value;
        if (isEmpty()) {
            newnode->Next = NULL;
            Head = newnode;
        }
        else {
            Node* temp = Head;
            while (temp->Next != NULL) {
                temp = temp->Next;
            }
            temp->Next = newnode;
            temp = newnode;
        }
    }
    void InserBeforeItem(int item, int value) {
        Node* newnode = new Node;
        newnode->Data = value;
        if (Search(item)) {
            Node* temp = Head;
            while (temp->Next->Data != item && temp != NULL) {
                temp = temp->Next;
            }
            newnode->Next = temp->Next; // كإني خزنت بوينتر التيمب قبل ما اخليه يشاور علي النيو نود
            temp->Next = newnode; // غيرت نيكست التيمب خليته يشاور علي النيو نود
            /*
            temp->Next = newnode;
            //غلط لان كدا النيونود بتشاور علي نفسها وبفقد باقي الليست
            newnode->Next = temp->Next;
            */
        }
        else {
            cout << "Item is not found\n";
        }
    }
    int Pop() { // Removes most recent element
        /*if (isEmpty()) {
            cout << "Stack UnderFlow\n";
            return -1;
        }
        else {*/
            Node* delptr = Head;
            int v = delptr->Data;
            Head = Head->Next;
            delete delptr;
            cout << 1;
            return v;
        //}

    }
    void InsertAfterItem(int item, int value) {
        Node* newnode = new Node;
        newnode->Data = value;
        if (Search(item)) {
            Node* temp = Head;
            while (temp != NULL &&temp->Data != item) { // كان في غلط
                temp = temp->Next;
            }
            newnode->Next = temp->Next;  
                                                        //كان في غلط 
            temp->Next = newnode;
        }
    }
    void DeleteFirst() {
        if (isEmpty()) {
            cout << "No items to delete!\n";
        }
        else {
            Node* delptr = Head;
            Head = Head->Next;
            delete delptr;
        }
    }
    void DeleteLast() {
        if (isEmpty()) {
            cout << "No items to delete!\n";
        }
        else {
            Node* temp = Head;
            
            while (temp->Next->Next != NULL) { // وصلت للعنصر قبل الاخير
                temp = temp->Next;
            }
            temp->Next = NULL; // خليت العنصر الي انا واقفه عنده(قبل الاخير) يشاور علي (NULL)
        }
    }
    void DeleteItem(int item) {
        if (Search(item)) { // 1 2 3 4 5      DeleteItem(3)
            Node* temp = Head; // الي همشي بيه // هيقف عند العنصر نفسه
            Node* Prev = NULL; // هساويه بالنود الي قبل نود العنصر 
            while (temp->Data != item) {
                Prev = temp;   // 2
                temp = temp->Next; // 3
            }
            Prev->Next = temp->Next; // Next of 2 points to Next of 3 ==> (4)  // 1 2 4 5
            delete temp;
        }
    }
    void Replace(int item, int value) {
        if (isEmpty()) {
            cout << "No items to replace\n";
        }
        else {
            if (Search(item)) {
                Node* temp = Head;
                while (temp->Data != item) {
                    temp = temp->Next;
                }
                temp->Data = value;
            }
            else {
                cout << "Item is not found\n";
            }
        }
    }
};
class StackList {
    /*
    bool isEmpty()
    bool isFull()
    int Count()
    int/bool Search(key)
    void Push()    Modifies
    int Pop()      Modifies
    int Peek()     Doesn't modify
    void Display()
    */
private:
    Node* Top;
    int count;
public:
    StackList() {
        
        Top = NULL;
        count = 0;
    }
    bool isEmpty() {
        return(Top == NULL);
    }
    int Count() {
        int count = 0;
        if (isEmpty()) {
            cout << "Stack is Empty";
            count = 0;
        }
        else {
            Node* temp = Top;
            while (temp != NULL) {
                count++;
                temp = temp->Next;
            }
        }
        return count;
    }
    void Push(int value) {
        Node* newnode = new Node();


        newnode->Data = value;
        if (isEmpty()) {
            Top = newnode;
        }
        else {
            newnode->Next = Top;
            Top = newnode;
        }
    }
    int Pop() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        else {
            int data = Top->Data;
            Top = Top->Next;
            return data;
        }
    }
    int Peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        else {
            return Top->Data;
        }
    }
    void Display() {
        if (isEmpty()) {
            cout << "Stack is empty, no elements to show\n";
            return;
        }
        Node* temp = Top;
        cout << "List items: ";
        while (temp != NULL) {
            cout<< temp->Data << " ";
            temp = temp->Next;
        }
        cout << endl;
    }
    bool Search(int key) {
        bool found = false;
        if (isEmpty()) {
            cout << "Stack is empty\n";
        }
        else {
            Node* temp = Top;
            while (temp->Data != key) {
                if (temp->Data == key) {
                    found = true;
                    break;
                }
                temp = temp->Next;
            }
        }
        return found;
    }
};
class QueueList {
    /*
    bool isEmpty()
    void Enqueue(int value)    Modifies
    void Dequeue()             Modifies
    void Clear()
    void Traverse()
    int count()
    bool Search(int key)
    int Peek()
    */
private:
    int length;
    Node* Rear;
    Node* Front;

public:
    QueueList() {
        length = 0;
        Front = Rear = NULL;
    }
    bool isEmpty() {
        return(Front == NULL && Rear == NULL);
    }
    void Enqueue(int value) {
        Node* newnode = new Node;
        newnode->Data = value;
        if (isEmpty()) {
            Front = Rear = newnode;
            length++;
        }
        else {
            Rear->Next = newnode;
            Rear = newnode; // قيمة النيو نود تتحط في ال رير
            length++;
        }
    }
    void Display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        }
        else {
            Node* temp = Front;
            cout << "Elements of Queue: ";
            while (temp != NULL) {
                cout << temp->Data << " ";
                temp = temp->Next;
            }
            cout << endl;
        }
    }
    int Dequeue() {
        int value = -1;
        /*if (isEmpty()) {
            cout << "No items to dequeu\n";
        }
        else {*/
            Node* del = Front;
            Front = Front->Next;
            delete del;
        //}
        return value;
    }
    void Clear() {
        while (Front != NULL) {
            Dequeue();
        }
    }
    int Peek() {
        return Front->Data; // مين عليه الدور يطلع
    }
    bool Search(int key) {
        bool found = false;
        if (isEmpty()) {
            cout << "No items to dequeu\n";
        }
        else {
            Node* temp = Front;
            while (temp->Data != key) {
                if (temp->Data == key)
                    found = true;
                temp = temp->Next;
            }
        }
        return found;
    }
};
class StackArray {
private:
    int top;
    const int max = INT32_MAX;
    int* items;

public:
    StackArray() {
        top = -1;
        items = new int[max];
    }
    bool isEmpty() {
        return(top == -1);
    }
    int Count() {
        return (top + 1); // لان ال توب ماشي مع الانديسيس
    }
    void Push(int item) { // = Append

        if (top < max) {
            //top++;
            items[++top] = item;
        }
        else {
            cout << "Stack Overflow\n";
        }
    } 
    int Pop() { // Removes most recent element
        if (isEmpty()) {
            cout << "Stack UnderFlow\n";
            return top;
        }
        else {
            int value = items[top];
            items[top] = 0;
            top--;
            return value;
        }
        
    } 
    int Peek() { // show mosr recent element
        return items[top];
    }
    void Display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Items of Stack: ";
        for (int i = top; i >= 0; i--) { // بمشي بالعكس لان التوب بيمثل اخر عنصر دخل وانا عايزة اول عنصر دخل
            cout << items[i] << " ";
        }
        cout << endl;
    }
    /*void Clear() {
        while (top != -1) {
            Pop();
        }
    }*/
    bool isFound(int key) {
        bool found = false;
        for (int i = 0; i <= top; i++) {
            if (items[i] == key)
            {
                found = true;
                break;
            }
        }
        return found;
    }
};
class QueueArray {  // First in First out
private:
    int length;
    int size;
    int* items;

public:
    QueueArray(int size) {
        this->size = size;
        length = 0;
        items = new int[size];
    }
    bool isEmpty() {
        return(length == 0);
    }
    int GetLength() {
        return length;
    }
    void Enqueue(int item) {
        items[length++] = item;
    }
    void Dequeue() {
        if (isEmpty()) {
            cout << "No items to dequeu\n";
            return;
        }
        for (int i = length; i > 0; i++) {
            items[i] = items[i + 1];
        }
        length--;
    }
    void Display() {
        if (isEmpty()) {
            cout << "No items to display\n";
            return;
        }
        cout << "Items of the Queue: ";
        for (int i = 0; i < length; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
    int Peek() {
        return items[0];
    }

};
class BST {
    /*
    Creation = Constructors
    Node* Insert(Node* pnode, int item)
    void PreOrder(Node* pnode)
    void InOrder(Node* pnode)
    void PostOrder(Node* pnode)
    */
private:
    Node* Root;

public:
    BST() {
        Root = NULL;
    }
    Node* Insert(Node* pnode, int item) {
        if (pnode == NULL) {
            Node* newnode = new Node(item);
            pnode = newnode;
        }
        else if (item < pnode->Data)
            pnode->Left = Insert(pnode->Left, item);
        else
            pnode->Right = Insert(pnode->Right, item);
    }
    void Insert(int item) {
        Root = Insert(Root, item);
    }
    void PreOrder(Node* pnode) {
        if (pnode == NULL) 
            return;
        
        cout << pnode->Data << " ";
        PreOrder(pnode->Left);
        PreOrder(pnode->Right);
    }
    void InOrder(Node* pnode) {
        if (pnode == NULL)
            return;

        InOrder(pnode->Left);
        cout << pnode->Data << " ";
        InOrder(pnode->Right);
    }
    void PostOrder(Node* pnode) {
        if (pnode == NULL)
            return;

        PostOrder(pnode->Left);
        PostOrder(pnode->Right);
        cout << pnode->Data << " ";
    }
};

int main()
{
    //QueueList q = QueueList();
    //q.Enqueue(5);
    //q.Enqueue(6);
    //q.Enqueue(7);
    //q.Enqueue(8);
    //q.Display();
    //q.Dequeue();


    /*StackList s = StackList();
    s.Push(5);
    s.Push(6);
    s.Push(7);
    s.Push(8);
    s.Display();
    s.Pop();
    s.Display();*/
    /*int x = NULL;
    cout << x;*/


    LinkedList l = LinkedList();
    //l.InsertFirst(5);
    //cout << l.Pop();
    cout << l.Pop();
    cout << 1;
    /*l.InsertFirst(5);
    l.InsertFirst(6);
    l.InsertFirst(7);
    l.Traverse();
    l.InsertLast(9);
    l.InsertLast(10);
    l.InsertLast(11);
    l.Traverse();
    l.InserBeforeItem(5, 80);
    l.Traverse();
    l.InsertAfterItem(9, 100);
    l.Traverse();
    l.DeleteLast();
    l.Traverse();
    l.DeleteItem(5);
    l.Traverse();
    l.Replace(9, 18);
    l.Traverse();*/


    /*Array a = Array(20);
    a.Fill();
    a.Display();
    a.DeleteIndex(2);
    a.Display();
    a.DeleteItem(5);
    a.Display();*/
    //a.InsertIndex(4, 1);
    //a.Display();
    //cout << "Index is: " << a.BinarySearch(4);
    /*
    Q: How to return an array?
    A: Using pointer.
    */
    //int* arr = a.BubbleSort(); // خزنت ادرس الاراي الي هترجع في بوينتر
    //for (int i = 0; i < a.getLength(); i++) {
    //    cout << arr[i] << " ";
    //}
    //cout << endl;
    //cout << "After sorting: \n";
    //a.InsertFirst(10);
    //a.Display();
    //cout << "Item is in: " << a.BinarySearch(5) << endl;
    //
    //int* arrs = a.Sort(); // خزنت ادرس الاراي الي هترجع في بوينتر
    //for (int i = 0; i < a.getLength(); i++) {
    //    cout << arrs[i] << " ";
    //}

}

