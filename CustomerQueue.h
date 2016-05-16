/*
Author : Team Nirvana - Pranav and Chirag
*/

#ifndef CUSTOMERQUEUE_H_INCLUDED
#define CUSTOMERQUEUE_H_INCLUDED
#include <assert.h>

template <class Elem>
class BankQueue
{
  public:
    BankQueue(int MaxSize=5000);
    BankQueue(const BankQueue<Elem> &OtherBankQueue);
    ~BankQueue(void);

    void       Enqueue(const Elem &Item);    // Adds Item to BankQueue end
    Elem       Dequeue(void);                // Returns Item from Queue
    inline int ElemNum(void);                // Returns Number of Elements

  protected:
    Elem     *Data;      // The actual Data array
    const int MAX_NUM;   // The actual spaces will be one more than this
    int       Beginning, // Numbered location of the start and end
              End;

    int       ElemCount;
};


template <class Elem>
BankQueue<Elem>::BankQueue(int MaxSize) :
    MAX_NUM( MaxSize )   // Initialize the constant
{

  Data      = new Elem[MAX_NUM + 1];
  Beginning = 0;
  End       = 0;
  ElemCount = 0;
}

// BankQueue Copy Constructor function
template <class Elem>
BankQueue<Elem>::BankQueue(const BankQueue &OtherBankQueue) :
                MAX_NUM( OtherBankQueue.MAX_NUM )  // Initialize the constant
{
  Beginning = OtherBankQueue.Beginning;
  End       = OtherBankQueue.End;
  ElemCount = OtherBankQueue.ElemCount;

  Data      = new Elem[MAX_NUM + 1];
  for (int i = 0; i < MAX_NUM; i++)
    Data[i] = OtherBankQueue.Data[i];
}

// BankQueue Destructor function
template <class Elem>
BankQueue<Elem>::~BankQueue(void)
{
  delete[] Data;
}

// EnBankQueue() function
template <class Elem>
void BankQueue<Elem>::Enqueue(const Elem &Item)
{
  assert( ElemCount < MAX_NUM );

  Data[ End++ ] = Item;
  ++ElemCount;

  if (End > MAX_NUM)
    End -= (MAX_NUM + 1);
}

// Dequeue() function
template <class Elem>
Elem BankQueue<Elem>::Dequeue(void)
{
  assert( ElemCount > 0 );

  Elem ReturnValue = Data[ Beginning++ ];
  --ElemCount;

  if (Beginning > MAX_NUM)
    Beginning -= (MAX_NUM + 1);

  return ReturnValue;
}

template <class Elem>
inline int BankQueue<Elem>::ElemNum(void)
{
  return ElemCount;
}


#endif
