#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList() : headPtr(nullptr), listLength(0)
{
  headPtr = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  listLength = x.getLength();
  Node<T>* origChainPtr = x.headPtr;
  if(origChainPtr == nullptr)
  {
    headPtr = nullptr;
  }
  else
  {
    headPtr = new Node<T>();
    headPtr -> setItem(origChainPtr -> getItem());
    Node<T>* newChainPtr = headPtr;
   for(int i = 1; i<listLength; i++)
    {
    origChainPtr = origChainPtr -> getNext();
    Node<T>* newNodePtr = new Node<T>();
    newNodePtr -> setItem(origChainPtr ->getItem());
    newChainPtr -> setNext(newNodePtr);
    newChainPtr = newChainPtr->getNext();
    }
    newChainPtr->setNext(nullptr);
  } 
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  LinkedList<int>temp;
  temp = x;
  x = y;
  y = temp;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  clear();
  listLength = x.getLength();
  Node<T>* origChainPtr = x.headPtr;
  if(origChainPtr == nullptr)
  {
    headPtr = nullptr;
  }
  else
  {
    headPtr = new Node<T>();
    headPtr -> setItem(origChainPtr -> getItem());
    Node<T>* newChainPtr = headPtr;
   for(int i = 1; i<listLength; i++)
    {
    origChainPtr = origChainPtr -> getNext();
    Node<T>* newNodePtr = new Node<T>();
    newNodePtr -> setItem(origChainPtr ->getItem());
    newChainPtr -> setNext(newNodePtr);
    newChainPtr = newChainPtr->getNext();
    }
    newChainPtr->setNext(nullptr);
  } 
  return *this; 
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  if(listLength == 0)
  {
    return true;
  }
  return false;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  return listLength;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  if(position > listLength+1 || position < 1)
  {
    return false;
  }
  if(position == 1)
  {
    Node<T>* newNodePtr = new Node<T>();
    newNodePtr -> setItem(item);
    newNodePtr -> setNext(headPtr);
    headPtr = newNodePtr;
    newNodePtr = nullptr;
    listLength++;
    return true;
  }
  if(position == listLength+1)
  {
    Node<T>* newNodePtr = new Node<T>();
    Node<T>* curPtr = new Node<T>();
    newNodePtr->setItem(item);
    curPtr = headPtr;

    while(curPtr->getNext() != nullptr)
    {
      curPtr = curPtr -> getNext();
    }
    curPtr->setNext(newNodePtr);
    newNodePtr->setNext(nullptr);
    newNodePtr = nullptr;
    curPtr = nullptr;
    listLength++;
    return true;
  }
  else
  { 
    Node<T>* curPtr = new Node<T>();
    Node<T>* newNodePtr = new Node<T>();
    newNodePtr -> setItem(item);
    curPtr = headPtr;
    for(int i = 1; i < position-1; i++)
    {
      curPtr = curPtr->getNext();
    }
    newNodePtr->setNext(curPtr->getNext());
    curPtr->setNext(newNodePtr);
    curPtr = nullptr;
    listLength++;
    return true;
  }
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  if(position > listLength+1 || position < 1)
  {
    return false;
  }
  Node<T>* nodetoRemovePtr = headPtr;
  Node<T>* curPtr = headPtr;
  if(position == 1)
  {
    Node<T>* nodetoDeletePtr = headPtr;
    nodetoDeletePtr = headPtr;
    headPtr = headPtr->getNext();
    nodetoDeletePtr->setNext(nullptr);
    delete nodetoDeletePtr;
    listLength--;
    return true;
  }
  if(position == listLength)
  {
    Node<T>* nodeToRemovePtr = new Node<T>();
    Node<T>* curPtr = new Node<T>();
    curPtr = headPtr;

    for(int i = 1; i < listLength-1; i++)
    {
      curPtr = curPtr -> getNext();
    }
    nodeToRemovePtr = curPtr->getNext();
    curPtr -> setNext(nullptr);
    delete nodeToRemovePtr;
    nodeToRemovePtr = nullptr;
    curPtr = nullptr;
    listLength--;
    return true;
  }
  else
  {
  for(int i = 1; i<position-1; i++)
  {
    curPtr = curPtr-> getNext();
  }
  nodetoRemovePtr = curPtr -> getNext();
  curPtr -> setNext(nodetoRemovePtr -> getNext());
  nodetoRemovePtr -> setNext(nullptr);
  delete nodetoRemovePtr;
  nodetoRemovePtr = nullptr;
  curPtr = nullptr;
  listLength--;
  return true;
  }
}

template <typename T>
void LinkedList<T>::clear()
{
  Node<T>* nodetoDeletePtr = headPtr;
  while(headPtr != nullptr)
  {
    nodetoDeletePtr = headPtr;
    headPtr = headPtr->getNext();
    nodetoDeletePtr->setNext(nullptr);
    delete nodetoDeletePtr;
  }
  
  nodetoDeletePtr = nullptr;
  listLength = 0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  if(position > listLength || position < 1)
  {
  }
  else
  {
    Node<T>* nodePtr = headPtr;
    for(int i = 1; i <position; i++)
    {
      nodePtr = nodePtr -> getNext();
    }
    return nodePtr -> getItem();
  }
  
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  if(position > listLength || position < 1)
  {
  }
  else
  {
    Node<T>* nodePtr = headPtr;
    for(int i = 1; i <position; i++)
    {
      nodePtr = nodePtr->getNext();
    }
    nodePtr->setItem(newValue);
  }
}
