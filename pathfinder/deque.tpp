#include "deque.hpp"

template <typename T>
Deque<T>::Deque()
{
    size = 0;
}
  
template <typename T>
Deque<T>::~Deque()
{

}
template <typename T>
bool Deque<T>::isEmpty() const noexcept
{
    if(size == 0)
    {
        return true;
    }
    return false;
}

template <typename T>
void Deque<T>::pushFront(const T & item)
{
  list.insert(1,item);
  size++;
}

  /** Remove the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
template <typename T>
void Deque<T>::popFront()
{
  if(isEmpty()) throw std::runtime_error("deque is empty");
  list.remove(1);
  size--;
}

  /** Returns the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
template <typename T>
T Deque<T>::front() const
{
  if(isEmpty()) throw std::runtime_error("deque is empty");
  return list.getEntry(1);
}

  /** Add item to the back of the deque
   * may throw std::bad_alloc
   */
template <typename T>
void Deque<T>::pushBack(const T & item)
{
  list.insert(size+1, item);
  size++;
}

  /** Remove the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
template <typename T>
void Deque<T>::popBack()
{
  if(isEmpty()) throw std::runtime_error("deque is empty");
  list.remove(size);
  size--;
}


  /** Returns the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
template <typename T>
T Deque<T>::back() const
{
  if(isEmpty()) throw std::runtime_error("deque is empty");
  return list.getEntry(size);
}