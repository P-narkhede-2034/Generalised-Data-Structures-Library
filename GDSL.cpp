//////////////////////////////////////////////////////////////////////////////////////
//      Generalised Data Structure Library
/////////////////////////////////////////////////////////////////////////////////////

/*
---------------------------------------------------------------------------------------
Type                    Name of class for node      Name of class for Functionality
---------------------------------------------------------------------------------------
Singly Linear            SinglyLLLnode               SinglyLLL          Done
Singly Cirular           SinglyCLLnode               SinglyCLL          Done
Doubly Linear            DoublyLLLnode               DoublyLLL          Done
Doubly Circular          DoublyCLLnode               DoublyCLL          Done
Stack                    Stacknode                   Stack              Done
Queue                    Queuenode                   Queue              Done
---------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//          Singly Linear LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private:        
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
};

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     SinglyLLL (Constructor)
//  Input         :     None
//  Author        :     Pranav Manoj Narkhede
//  Date          :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             None
//  Output :            Nothing
//  Description :       Used to delete first node from linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             None
//  Output :            Nothing
//  Description :       Used to delete last node from linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)  
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             None
//  Output :            Displays linked list elements
//  Description :       Used to display all nodes of linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             None
//  Output :            Returns number of nodes
//  Description :       Used to count total nodes in linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> ::Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node, Position
//  Output :            Nothing
//  Description :       Used to insert node at given position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position
//  Output :            Nothing
//  Description :       Used to delete node from given position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//          Doubly Linear LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DoublyLLL (Constructor)
//  Input         :     None
//  Author        :     Pranav Manoj Narkhede
//  Date          :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertLast(T no) 
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node, Position
//  Output :            Nothing
//  Description :       Used to insert node at given position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }  

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             None
//  Output :            Nothing
//  Description :       Used to delete first node from linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteFirst()
{
    if(this->first == NULL)                 // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)      // LL contains 1 node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    // LL contains more than 1 node
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             None
//  Output :            Nothing
//  Description :       Used to delete last node from linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)                 // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)      // LL contains 1 node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    // LL contains more than 1 node
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position
//  Output :            Nothing
//  Description :       Used to delete node from given position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid position\n";
        return;
    }  

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }    
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             None
//  Output :            Displays linked list elements
//  Description :       Used to display all nodes of linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::Display()
{
    DoublyLLLnode<T> *temp = NULL;
    
    temp = this->first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             None
//  Output :            Returns number of nodes
//  Description :       Used to count total nodes in linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T> ::Count()
{
    return this->iCount;
}


///////////////////////////////////////////////////////////////////////
//          Singly Circular LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCLLnode 
{
    public:
         T data ;
        SinglyCLLnode<T> *next;

        SinglyCLLnode( T no)
        {
        this->data = no;
        this->next = NULL; 
        }
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> * first;
        SinglyCLLnode<T> * last;
        int icount;
    
    public:
        SinglyCLL();
       void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     SinglyCLL (Constructor)
//  Input         :     None
//  Author        :     Pranav Manoj Narkhede
//  Date          :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyCLL<T> :: SinglyCLL ()
{
    first = NULL;
    last = NULL;
    icount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: InsertFirst( T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }

    icount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: InsertLast(T no)
{
        SinglyCLLnode<T> *  newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }

    icount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node, Position
//  Output :            Nothing
//  Description :       Used to insert node at given position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: InsertAtPos(T no ,int pos)
{
        SinglyCLLnode<T> * newn = NULL;
        SinglyCLLnode<T> * temp = NULL;
    int i = 0;

    if(pos < 1 || pos > icount+1)
    {
        cout<<"Invalid positon\n";
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == icount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = first;

        newn = new SinglyCLLnode<T>(no);

        for(i = 1; i < pos-1 ; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        icount ++;

    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             None
//  Output :            Nothing
//  Description :       Used to delete first node from linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteFirst()
{
     SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        temp =first;

        first = first->next;
        delete temp;
        last->next = first;
    }

    icount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             None
//  Output :            Nothing
//  Description :       Used to delete last node from linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;
        while(temp->next != last)
        {
            temp = temp->next;
        }
        
        delete last;
        last = temp;

        last->next = first;
    }

    icount --;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node, Position
//  Output :            Nothing
//  Description :       Used to insert node at given position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
        SinglyCLLnode<T> * temp = NULL;
        SinglyCLLnode<T> * target = NULL;

    int i = 0;

    if(pos < 1 || pos > icount)
    {
        cout<<"Invalid positon\n";
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == icount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1 ; i++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;
        

        icount --;

    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             None
//  Output :            Displays linked list elements
//  Description :       Used to display all nodes of linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: Display()
{
    int i = 0;
        SinglyCLLnode<T> * temp = NULL;

    temp = first;

    for(i = 1 ; i <= icount ; i++)
    {
        cout<<"| "<< temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"\n";
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             None
//  Output :            Returns number of nodes
//  Description :       Used to count total nodes in linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T> :: Count()
{
    return icount;
}

///////////////////////////////////////////////////////////////////////
//          Doubly Circular LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyLCL
{
    private:
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int icount;

    public:
        DoublyLCL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DoublyLCL (Constructor)
//  Input         :     None
//  Author        :     Pranav Manoj Narkhede
//  Date          :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLCL<T> :: DoublyLCL()
{
    first = NULL;
    last = NULL;
    icount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLCL<T> :: InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

    if(first == NULL && last == NULL)
    {
        first = last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;
    icount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLCL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

    if(first == NULL && last == NULL)
    {
        first = last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }

    last->next = first;
    first->prev = last;
    icount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node, Position
//  Output :            Nothing
//  Description :       Used to insert node at given position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLCL<T> :: InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > icount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == icount + 1)
    {
        InsertLast(no);
    }
    else
    {
        DoublyCLLnode<T> *temp = first;
        DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        icount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             None
//  Output :            Nothing
//  Description :       Used to delete first node from linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLCL<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = last = NULL;
    }
    else
    {
        DoublyCLLnode<T> *temp = first;
        first = first->next;
        delete temp;

        first->prev = last;
        last->next = first;
    }
    icount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             None
//  Output :            Nothing
//  Description :       Used to delete last node from linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLCL<T> :: DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = last = NULL;
    }
    else
    {
        DoublyCLLnode<T> *temp = last;
        last = last->prev;
        delete temp;

        last->next = first;
        first->prev = last;
    }
    icount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position
//  Output :            Nothing
//  Description :       Used to delete node from given position
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLCL<T> :: DeleteAtPos(int pos)
{
    if(pos < 1 || pos > icount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == icount)
    {
        DeleteLast();
    }
    else
    {
        DoublyCLLnode<T> *temp = first;

        for(int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        icount--;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             None
//  Output :            Displays linked list elements
//  Description :       Used to display all nodes of linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLCL<T> :: Display()
{
    if(first == NULL)
    {
        cout<<"List is empty\n";
        return;
    }

    DoublyCLLnode<T> *temp = first;

    for(int i = 1; i <= icount; i++)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"\n";
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             None
//  Output :            Returns number of nodes
//  Description :       Used to count total nodes in linked list
//  Author :            Pranav Manoj Narkhede
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLCL<T> :: Count()
{
    return icount;
}

///////////////////////////////////////////////////////////////////////
//                  Stack using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>   
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;
    
    Stacknode( T no)
    {
        data = no;
        this->next = NULL;
    }
};

template<class T>   
class Stack
{
    private:
        Stacknode<T> *first;
        int icount;
    
    public:

        Stack();
        void push(T);        
        T pop();             
        T peep();
        void Display();
        int Count();
};

template<class T>   
Stack<T> :: Stack()
{
    cout<<"Stack Get Created Sucessfully .... \n";
    this->first = NULL;
    this->icount = 0;
}

template<class T>  
void Stack<T> :: push( T no)
{
    Stacknode<T> *newn = NULL;
    
    newn = new Stacknode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }

    this->icount ++;
} 

template<class T>   
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;

    delete temp;

    this->icount --;

    return Value;
}

template<class T>   
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;
    
    return Value;

}

template<class T>   
void Stack<T> :: Display()
{
    Stacknode<T> *temp = NULL;

    temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

template<class T>   
int Stack<T> :: Count()
{
    return this->icount;
}

///////////////////////////////////////////////////////////////////////
//          Queue using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;
    
    Queuenode(T no)
    {
        data = no;
        this->next = NULL;
    }
};

template <class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        int icount;
    
    public:

        Queue();
        void enqueue(T);        
        T dequeue();           
        void Display();
        int Count();
};

template <class T>
Queue<T> :: Queue()
{
    cout<<"Queue Get Created Sucessfully .... \n";
    this->first = NULL;
    this->last = NULL;
    this->icount = 0;
}

template <class T>
void Queue<T> :: enqueue( T no)
{
    Queuenode<T> *newn = NULL;
    
    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }

    this->icount ++;
}  

template <class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;

    delete temp;

    this->icount --;

    return Value;
}

template <class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = NULL;

    temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int Queue<T> :: Count()
{
    return this->icount;
}

//////////////////////////////// End of Library ////////////////////////////////////////

int main()
{
    int mainChoice = -1;

    SinglyLLL<int> sll;
    DoublyLLL<int> dll;
    SinglyCLL<int> scll;
    DoublyLCL<int> dcll;
    Stack<int> stk;
    Queue<int> que;

    int value, pos, subChoice;

    do
    {
        cout << "\n====================================\n";
        cout << " GENERAL DATA STRUCTURE LIBRARY\n";
        cout << "====================================\n";
        cout << "1. Singly Linear Linked List\n";
        cout << "2. Doubly Linear Linked List\n";
        cout << "3. Singly Circular Linked List\n";
        cout << "4. Doubly Circular Linked List\n";
        cout << "5. Stack\n";
        cout << "6. Queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch(mainChoice)
        {
            // ==========================
            // 1. Singly Linear
            // ==========================
            case 1:
                do
                {
                    cout << "\n--- Singly Linear Linked List ---\n";
                    cout << "1.Insert First\n2.Insert Last\n3.Insert At Position\n";
                    cout << "4.Delete First\n5.Delete Last\n6.Delete At Position\n";
                    cout << "7.Display\n8.Count\n0.Back\n";
                    cin >> subChoice;

                    switch(subChoice)
                    {
                        case 1: cin>>value; sll.InsertFirst(value); break;
                        case 2: cin>>value; sll.InsertLast(value); break;
                        case 3: cin>>value>>pos; sll.InsertAtPos(value,pos); break;
                        case 4: sll.DeleteFirst(); break;
                        case 5: sll.DeleteLast(); break;
                        case 6: cin>>pos; sll.DeleteAtPos(pos); break;
                        case 7: sll.Display(); break;
                        case 8: cout<<"Count: "<<sll.Count()<<endl; break;
                    }
                }while(subChoice != 0);
                break;

            // ==========================
            // 2. Doubly Linear
            // ==========================
            case 2:
                do
                {
                    cout << "\n--- Doubly Linear Linked List ---\n";
                    cout << "1.Insert First\n2.Insert Last\n3.Insert At Position\n";
                    cout << "4.Delete First\n5.Delete Last\n6.Delete At Position\n";
                    cout << "7.Display\n8.Count\n0.Back\n";
                    cin >> subChoice;

                    switch(subChoice)
                    {
                        case 1: cin>>value; dll.InsertFirst(value); break;
                        case 2: cin>>value; dll.InsertLast(value); break;
                        case 3: cin>>value>>pos; dll.InsertAtPos(value,pos); break;
                        case 4: dll.DeleteFirst(); break;
                        case 5: dll.DeleteLast(); break;
                        case 6: cin>>pos; dll.DeleteAtPos(pos); break;
                        case 7: dll.Display(); break;
                        case 8: cout<<"Count: "<<dll.Count()<<endl; break;
                    }
                }while(subChoice != 0);
                break;

            // ==========================
            // 3. Singly Circular
            // ==========================
            case 3:
                do
                {
                    cout << "\n--- Singly Circular Linked List ---\n";
                    cout << "1.Insert First\n2.Insert Last\n3.Insert At Position\n";
                    cout << "4.Delete First\n5.Delete Last\n6.Delete At Position\n";
                    cout << "7.Display\n8.Count\n0.Back\n";
                    cin >> subChoice;

                    switch(subChoice)
                    {
                        case 1: cin>>value; scll.InsertFirst(value); break;
                        case 2: cin>>value; scll.InsertLast(value); break;
                        case 3: cin>>value>>pos; scll.InsertAtPos(value,pos); break;
                        case 4: scll.DeleteFirst(); break;
                        case 5: scll.DeleteLast(); break;
                        case 6: cin>>pos; scll.DeleteAtPos(pos); break;
                        case 7: scll.Display(); break;
                        case 8: cout<<"Count: "<<scll.Count()<<endl; break;
                    }
                }while(subChoice != 0);
                break;

            // ==========================
            // 4. Doubly Circular
            // ==========================
            case 4:
                do
                {
                    cout << "\n--- Doubly Circular Linked List ---\n";
                    cout << "1.Insert First\n2.Insert Last\n3.Insert At Position\n";
                    cout << "4.Delete First\n5.Delete Last\n6.Delete At Position\n";
                    cout << "7.Display\n8.Count\n0.Back\n";
                    cin >> subChoice;

                    switch(subChoice)
                    {
                        case 1: cin>>value; dcll.InsertFirst(value); break;
                        case 2: cin>>value; dcll.InsertLast(value); break;
                        case 3: cin>>value>>pos; dcll.InsertAtPos(value,pos); break;
                        case 4: dcll.DeleteFirst(); break;
                        case 5: dcll.DeleteLast(); break;
                        case 6: cin>>pos; dcll.DeleteAtPos(pos); break;
                        case 7: dcll.Display(); break;
                        case 8: cout<<"Count: "<<dcll.Count()<<endl; break;
                    }
                }while(subChoice != 0);
                break;

            // ==========================
            // 5. Stack
            // ==========================
            case 5:
                do
                {
                    cout << "\n--- Stack ---\n";
                    cout << "1.Push\n2.Pop\n3.Peep\n4.Display\n5.Count\n0.Back\n";
                    cin >> subChoice;

                    switch(subChoice)
                    {
                        case 1: cin>>value; stk.push(value); break;
                        case 2: cout<<"Popped: "<<stk.pop()<<endl; break;
                        case 3: cout<<"Top: "<<stk.peep()<<endl; break;
                        case 4: stk.Display(); break;
                        case 5: cout<<"Count: "<<stk.Count()<<endl; break;
                    }
                }while(subChoice != 0);
                break;

            // ==========================
            // 6. Queue
            // ==========================
            case 6:
                do
                {
                    cout << "\n--- Queue ---\n";
                    cout << "1.Enqueue\n2.Dequeue\n3.Display\n4.Count\n0.Back\n";
                    cin >> subChoice;

                    switch(subChoice)
                    {
                        case 1: cin>>value; que.enqueue(value); break;
                        case 2: cout<<"Removed: "<<que.dequeue()<<endl; break;
                        case 3: que.Display(); break;
                        case 4: cout<<"Count: "<<que.Count()<<endl; break;
                    }
                }while(subChoice != 0);
                break;

            case 0:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    }while(mainChoice != 0);

    return 0;
}
