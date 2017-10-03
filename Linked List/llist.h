//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P1 llist
// Your name: Sean Burk
// Compiler:  g++ 
// File type: headher file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // this is pointless

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 private:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  
 public:
  int  Count;        // counter for the number of nodes

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  //checks if it is empty
  bool isEmpty();    
  //displays all of the elements
  void displayAll();
  //adds an element to the front of the link list
  void addFront(el_t);
  //adds an element to the rear of the link list
  void addRear(el_t);
  //delets the front element
  void deleteFront(el_t&);
  //delets the rear element 
  void deleteRear(el_t&);
  //delets the element in the location of the intiger
  void deleteIth(int, el_t&);
  //adds an element before the location of the intiger
  void addbeforeIth(int, el_t);
};
