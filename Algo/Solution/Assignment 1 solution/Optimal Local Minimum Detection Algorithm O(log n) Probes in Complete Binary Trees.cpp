/*Consider an n − node complete binary tree T , where n = 2

d − 1 for some d. Each node v of T is labeled with
a real number xv. You may assume that the real numbers labeling the nodes are all distinct. A node v of T
is a local minimum if the label xv is less than the label xw for all nodes w that are joined to v by an edge.
You are given such a complete binary tree T, but the labeling is only specified in the following implicit way:
for each node v, you can determine the value xv by probing the node v. Show how to find a local minimum
of T using only O(log n) probes to the nodes of T.*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BT {
public:
    Node* ptr;
    BT() : ptr(nullptr) {}
    Node* insert(Node* ptr, int data) {
        if (ptr == nullptr) {
            return new Node(data);
        }

        if (data < ptr->data) {
            ptr->left = insert(ptr->left, data);
        }
        else {
            ptr->right = insert(ptr->right, data);
        }

        return ptr;
    }
    int foo(Node* ptr) {
        Node* current = ptr;
        while (current) {
            int data = current->data;
            Node* lc = current->left;
            Node* rc = current->right;

            if (lc == nullptr)
            {
                if (rc == nullptr)
                {
                    return data;
                }
            }

            if (lc == nullptr || data < lc->data)
            {
                if (rc == nullptr) 
                {
                    return data;
                }
                else if (data < rc->data)
                {
                    return data;
                }
            }

            if (lc != nullptr)
            {
                if (rc == nullptr)
                {
                    current = lc;
                }
                else if (lc->data < rc->data)
                {
                    current = lc;
                }
            }
            else 
            {
                current = rc;
            }
        }
        return -1;
    }

};

int main() {
    BT obj;
    obj.ptr = obj.insert(obj.ptr, 10);
    obj.ptr = obj.insert(obj.ptr, 4);
    obj.ptr = obj.insert(obj.ptr, 12);
    obj.ptr = obj.insert(obj.ptr, 65);
    obj.ptr = obj.insert(obj.ptr, 25);
    obj.ptr = obj.insert(obj.ptr,46);

    cout << " minimum is  : " << obj.foo(obj.ptr) << endl;

    return 0;
}
