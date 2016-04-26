#include <iostream>
#include"binaryTree.h"

using namespace std;

int main()
{

    BinaryTree<int> bt;

    bt.insertKey(1);
    bt.insertKey(2);
    bt.insertKey(3);
    bt.insertKey(4);
    bt.insertKey(5);
    bt.insertKey(6);
    bt.insertKey(7);
    bt.insertKey(8);
    bt.insertKey(9);
    bt.insertKey(10);

    bt.preorder();
    bt.inorder();
    bt.postorder();

    if(bt.searchKey(6))
    {
        cout<<"Found key."<<' ';
    }
    else
    {
        cout<<"Key was not found."<<endl;
    }



    if(bt.searchKey(15))
    {
        cout<<"Found key."<<' ';
    }
    else
    {
        cout<<"Key was not found."<<endl;
    }

    return 0;
}

