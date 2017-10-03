// ====================================================
//HW#: HW3P1 llist
//Your name: Sean Burk
//Complier:  g++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

//Purpose- be a linked list
llist::llist()
{
  Front=Rear=NULL;
  Count=0;
}

llist::~llist()
{
  int trash;//to waist memory with
  while(Count!=0)
    {
      deleteFront(trash);
    }
  cout<<"calling the llist desctructor.\n";
}

bool llist::isEmpty()
{
  if(Count==0&&Front==NULL&&Rear==NULL)
    return true;
  return false;
}

void llist::displayAll()
{
  if(isEmpty())
    {
      cout<<"[ empty ]\n";
      return;
    }
  Node *temp=Front;//holds what is being printed out
  cout<<"[ ";
  for(int i=0;i<Count;i++)
    {
      cout<<temp->Elem<<" ";
      temp=temp->Next;
    }
  cout<<"]\n";
}

void llist::addRear(el_t NewNum)
{
  if(isEmpty())
    {
      addFront(NewNum);
      return;
    }
  Node *add=new Node;
  add->Next=NULL;
  add->Elem=NewNum;
  Rear->Next=add;
  Rear=add;
  Count++;
  return;
}

void llist::addFront(el_t NewNum)
{
  Node *add=new Node;
  add->Elem=NewNum;
  add->Next=NULL;
  if(isEmpty())
    {
      Front=Rear=add;
      Front->Next=Rear;
      Count++;
      return;
    }
  add->Next=Front;
  Front=add;
  Count++;
}

void llist::deleteFront(el_t& OldNum)
{
  if(isEmpty())
    throw Underflow();
  OldNum=Front->Elem;
  if(Count==1)
    {
      delete Front;
      Front=Rear=NULL;
      Count--;
      return;
    }
  Node *trash=Front;// the node thats being deleted
  Front=Front->Next;
  delete trash;
  Count--;
  return;
}

void llist::deleteRear(el_t& OldNum)
{
  if(isEmpty())
    throw Underflow();
  OldNum=Rear->Elem;
  if(Count==1)
    {
      delete Rear;
      Rear=Front=NULL;
      Count--;
      return;
    }
  Node *trash=Front;//the node before the one being deleted 
  while(trash->Next!=Rear)
    trash=trash->Next;
  delete Rear;
  Rear=trash;
  Rear->Next=NULL;
  Count--;
  return;
}

void llist::deleteIth(int I, el_t& OldNum)
{
  if(I<1||I>Count)
    {
      throw OutOfRange();
    }
  if(I==Count)
    {
      deleteRear(OldNum);
      return;
    }
  if(I==1)
    {
      deleteFront(OldNum);
      return;
    }
  Node *trash=NULL,*before=Front;//the one being deleted and the one before the one being deleted
  for(int i=2;i<I;i++)
    {
      before=before->Next;
    }
  trash=before->Next;
  before->Next=trash->Next;
  OldNum=trash->Elem;
  delete trash;
  Count--;
  return;
}

void llist::addbeforeIth(int I, el_t NewNum)
{
  if(I<1||I>Count+1)
    throw OutOfRange();
  if(I==Count+1)
    {
      addRear(NewNum);
      return;
    }
  if(I==1)
    {
      addFront(NewNum);
      return;
    }
  Node *after=NULL,*before=Front;//the one before and after the added element
  for(int i=2;i<I;i++)
    {
      before=before->Next;
    }
  after=before->Next;
  Node *add=new Node;
  add->Elem=NewNum;
  add->Next=after;
  before->Next=add;
  Count++;
  return;
}

