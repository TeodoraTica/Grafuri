#ifndef BINARYTREE_H
#define BINARYTREE_H

using namespace std;

template <typename T>
struct Node{

    T info;
    Node<T> *left, *right;

    Node()
    {
        left = NULL;
        right = NULL;
    }

    Node(const T& info)
    {
        this->info = info;
        this->left = NULL;
        this->right = NULL;
    }

};

template <class T>
class BinaryTree {
private:

    Node<T> *root;

    void deleteTree(Node<T>* leaf)
    {
        if(leaf != NULL)
        {
            deleteTree(leaf->left);
            deleteTree(leaf->right);

            delete leaf;
        }
    }

    void insertKey(Node<T>* &leaf, const T& info)
    {
        if(leaf == NULL)
        {
            leaf = new Node<T>(info);
        }
        else
        {
            if(leaf->info > info)
            {
                insertKey(leaf->left, info);
            }

            if(leaf->info < info)
            {
                insertKey(leaf->right, info);
            }

            if(leaf->info == info)
            {
                cout<<"Node already exists."<<endl;
            }
        }
    }

    Node<T>* searchKey(Node<T>* leaf, const T& info)
    {
        if(leaf == NULL)
        {
            return NULL;
        }

        if(leaf->info == info)
        {
            return leaf;
        }

        if(leaf->info > info)
        {
            return searchKey(leaf->left, info);
        }

        if(leaf->info < info)
        {
            return searchKey(leaf->right, info);
        }
    }

    void preorder(Node<T>* node)
    {
        if(node)
        {
            cout<<node->info<<' ';
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(Node<T>* node)
    {
        if(node != NULL)
        {
            inorder(node->left);
            cout<<node->info<<' ';
            inorder(node->right);
        }
    }

    void postorder(Node<T>* node)
    {
        if(node != NULL)
        {
            postorder(node->left);
            postorder(node->right);
            cout<<node->info<<' ';
        }
    }

public:

    BinaryTree()
    {
        root = NULL;
    }

    ~BinaryTree()
    {
        deleteTree(root);
    }

    void insertKey(const T& info)
    {
        insertKey(root, info);
    }

    Node<T>* searchKey(const T& info)
    {
        return searchKey(root, info);
    }

    void preorder()
    {
        preorder(root);

        cout<<endl;
    }

    void inorder()
    {
        inorder(root);

        cout<<endl;
    }

    void postorder()
    {
        postorder(root);

        cout<<endl;
    }

    Node<T>* getRoot()
    {
        return root;
    }
};

#endif // BINARYTREE_H

