//Jacob Poteet
//2021
//Austin, TX
#include "LinkedList.h"


int main() {

    return 0;
}


LinkedList::~LinkedList()
{
    Node* currNode = head;
    Node* nextNode = NULL;

    while (currNode) {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }

}

Node* LinkedList::InsertNode(int index, int x) {
    
    //validate given index
    if (index < 0)
        return NULL;

    int currIndex = 1;
    Node* currNode = head;


    while (currNode and index > currIndex) {
        //If the given index is greater than list size, x will get added to the end of the list
        if (currNode->next != NULL) {
            currNode = currNode->next;
            currIndex++;
        }
        else {break;}
    }

    Node* newNode = new Node;
    newNode->data = x;

    if (index == 0) {
        //since index is 0, add to the beginning of the list
        newNode->next = head;
        head = newNode;
    }
    else {
        //insert node at correct index
        newNode->next = currNode->next;
        currNode->next = newNode;
    }

    return newNode;

}

int LinkedList::FindNode(int x){

    Node* currNode = head;
    int currIndex = 1;

    while (currNode and currNode->data != x) {
        currNode = currNode->next;
        currIndex++;
    }

    //if currNode was found this is valid, return position
    if (currNode != NULL)
        return currIndex;

    //currNode was invalid indicated the linked list has terminated, no match was found, returning 0
    return 0;
}

int LinkedList::DeleteNode(int x){

    Node* prevNode = NULL;
    Node* currNode = NULL;
    int currIndex = 1;

    while (currNode and currNode->data != x) {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }

    if (currNode != NULL) {
        //found correct node that is not the first element
        if (prevNode) {
            prevNode->next = currNode->next;
            delete currNode;
        }
        //deletes first element of list
        else {
            head = currNode->next;
            delete currNode;
        }
        return currIndex;
    }

    //no node was deleted because no node was found
    return 0;
}

void LinkedList::DisplayList()
{
    int num = 0;
    Node* currNode = head;

    while (currNode) {
        cout << currNode->data << endl;
        currNode = currNode->next;
        num++;
    }

    cout << "Number of nodes in list: " << num << endl;

}

int LinkedList::GetSize()
{
    int num = 0;
    Node* currNode = head;

    while (currNode) {
        currNode = currNode->next;
        num++;
    }

    return num;
}

void LinkedList::PushBack(int x) {

    Node* newNode = new Node;

    newNode->data = x;
    newNode->next = head;
    
    head = newNode;

    return;
}

void LinkedList::ConcatenateList(LinkedList* L2) {

    Node* currNode = head;
    Node* l2Node = L2->GetHeadNode();
    Node* newNode = new Node;

    if (currNode !=  NULL) {
        //iterate through self list until currNode is the last index. 
        while (currNode->next != NULL) {
            currNode = currNode->next;
        }
    }
    else if (l2Node == NULL) {
        return;
    }
    //self is an empty list so we must initialize the head to allow for concatenation
    else {
            newNode->data = l2Node->data;
            head = newNode;
            currNode = head;
            l2Node = l2Node->next;
    }

    //add elements from L2 into self
    while (l2Node != NULL) {

        newNode = new Node;

        newNode->data = l2Node->data;
        newNode->next = NULL;
    
        currNode->next = newNode;
        currNode = currNode->next;
        l2Node = l2Node->next;

    }
        return;
}

int LinkedList::GetMaxElem()
{
    Node* currNode = head;

    //if list is empty, return -1
    if (currNode == NULL)
        return -1;

    int currMax = -1;

    while (currNode) {
        //if a new max element is found, update the current max
        if (currNode->data > currMax)
            currMax = currNode->data;
        //iterate through the list and trach the current indect.
        currNode = currNode->next;

    }

    return currMax;


}

void LinkedList::RemoveDuplicateEntries() {
    unordered_set<int> tempSet;

    Node* currNode = head;
    Node* prevNode = NULL;

    while (currNode) {
        //if the current node data was found in the set declaring it a duplicate
        if (tempSet.count(currNode->data) and prevNode){
            //delete duplicate node
            prevNode->next = currNode->next;
            delete currNode;
        }
        //data was not found in the set
        else {
            tempSet.insert(currNode->data);
            prevNode = currNode;
        }
        currNode = prevNode->next;
    }


    return;

}


void PrintString(string message) {

    cout << message << endl;

    return;
}