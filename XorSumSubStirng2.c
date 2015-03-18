
/*
    *  Given an array A of unsigned 32-bit ints, choose two in-bounds indices i, j so as to  maximize the value of A[i] ^ A[j], where ^ is the bitwise XOR (exclusive OR) operator.
    *  If  there are multiple possible answers, print any one.
    *  Example Input:
    *  4 2 0 13 49
    *  Output:
    *  3 4
    *  Explanation: 13 ^ 49 is 60, 13 and 49 are positioned at indexes 3 and 4. Printing "4 3" would have been equally valid.
    *  Solution Guidance:
    *  Let k be the bit width (maximum number of bits) of the primitive.
    *  Easy: O(arr.length^2) time, O(1) space.
    *  Hard: Sub-quadratic complexity. An O(k*arr.length) time algorithm is possible. It is OK to use some extra space.
*/

#include <iostream>
using namespace std;

class node
{
    int val;
    bool isLeaf;
    node *left;
    node *right;

    public:

    node()
    {
        val = 0;
        isLeaf = false;
        left = NULL;
        right = NULL;
    }

    void setVal(int n)
    {
        val = n;
    }

    int getVal()
    {
        return val;
    }

    void setLeftChild(node *ptr)
    {
        left = ptr;
    }

    void setRightChild(node *ptr)
    {
        right = ptr;
    }

    node* getLeftChild()
    {
        return left;
    }

    node* getRightChild()
    {
        return right;
    }

    void setIsLeaf(bool b)
    {
        isLeaf = b;
    }

    bool getIsLeaf()
    {
        return isLeaf;
    }
};


class Tree
{
    node *root;
    int heightOfTree ;
    public:

    Tree()
    {
        root = new node();
        root->setVal(99);
        heightOfTree = 31;
    }

    int getMSBPosition()
    {
        return 0;
    }

    void insertNode(node* ptr, int n, int pos)
    {
        if(pos>=0)
        {
            int getBit = (1<<pos) & n;
            node* newNode;
            if(getBit)
            {
                if(ptr->getRightChild() == NULL)
                {
                    newNode = new node();
                    newNode->setVal(1);
                    ptr->setRightChild(newNode);
                }
                if(pos == 0)
                {
                    node* leafNode = new node();
                    newNode->setIsLeaf(true);
                    leafNode->setVal(n);
                    newNode->setLeftChild(leafNode);
                }
                else
                    insertNode(ptr->getRightChild(),n,pos-1);
            }
            else
            {
                if(ptr->getLeftChild() == NULL)
                {
                    newNode = new node();
                    newNode->setVal(0);
                    ptr->setLeftChild(newNode);
                }
                if(pos == 0)
                {
                    node* leafNode = new node();
                    leafNode->setVal(n);
                    newNode->setIsLeaf(true);
                    newNode->setLeftChild(leafNode);
                }
                else
                    insertNode(ptr->getLeftChild(),n,pos-1);
            }
        }
    }

    void insert(int n)
    {
        insertNode(root,n,heightOfTree);
    }

    int findMax(node* ptr1, node* ptr2)
    {
        if(ptr1->getIsLeaf() == false)
        {
            int n01 = 0;
            int n10 = 0;
            bool pathTaken = false;
            if(ptr1->getLeftChild() != NULL && ptr2->getRightChild() != NULL)
            {
                n01 = findMax(ptr1->getLeftChild(),ptr2->getRightChild());
                pathTaken = true;
            }
            if(ptr1->getRightChild() != NULL && ptr2->getLeftChild() != NULL)
            {
                n10 = findMax(ptr1->getRightChild(),ptr2->getLeftChild());
                pathTaken = true;
            }
            if(!pathTaken)
            {
                if(ptr1->getLeftChild() && ptr2->getLeftChild())
                    n01 = findMax(ptr1->getLeftChild(),ptr2->getLeftChild());
                else
                    n10 = findMax(ptr1->getRightChild(),ptr2->getRightChild());
            }
            return n01>n10?n01 : n10;
        }
        else
        {
            return ptr1->getLeftChild()->getVal() ^ ptr2->getLeftChild()->getVal();
        }
    }
    int findMaxValue()
    {
        return findMax(root,root);
    }

};

int maxValue(int *arr,int n)
{
    int max = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(max < (arr[i]^arr[j]))
                max = (arr[i]^arr[j]);
        }
    }
    return max;
}

int main()
{
    int numberOfElements;
    cout<<"\nNUMBER OF ELEMENTS : ";
    cin>>numberOfElements;
    Tree t ;
    int *arr = new int[numberOfElements];
    for(int i=0; i<numberOfElements;i++)
    {
        cin>>arr[i];
        t.insert(arr[i]);
    }
    cout<<"\nEASY = "<<maxValue(arr,numberOfElements);
    cout<<"\nHARD = "<<t.findMaxValue();
}

