// Design a stack class that supports the push, pop, top, and getMin operations.

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.

// Each function should run in O(1) time.
// pop, top and getMin will always be called on non-empty stacks.
#include <iostream>
#include <vector>

class MinStack
{
public:
    MinStack() // no need to initialize min due to the given assumptions of helper functions
    {
        topNode = nullptr;
        height = 0;
    }

    void push(int val)
    {
        // create first node
        if (topNode == nullptr)
        {
            topNode = new node(val);
            min.push_back(val);
            ++height;
        }
        // create the rest
        else
        {
            node *temp = new node(val);
            temp->next = topNode;
            topNode = temp;

            min.push_back(std::min(min[height - 1], val));
            ++height;
        }
    }

    void pop()
    {
        node *temp = topNode;
        topNode = topNode->next;
        delete temp;
        min.pop_back();

        if (--height == 0) // reset topNode if stack is emptied
            topNode = nullptr;
    }

    int top()
    {
        return topNode->data;
    }

    int getMin()
    {
        return min[height - 1];
    }

private:
    struct node
    {
        int data;
        node *next;
        node() : data(0), next(nullptr) {}
        node(int val) : data(val), next(nullptr) {}
    };

    node *topNode;
    int height;
    std::vector<int> min; // implement a currMin inside each node instead?
};

/***********************************************************************************************************************
 ***********************************************************************************************************************
 ***********************************************************************************************************************
 ***********************************************************************************************************************
 **********************************************************************************************************************/

int main()
{
    MinStack stack;
    stack.push(1);
    std::cout << stack.getMin() << std::endl;
    stack.push(2);
    std::cout << stack.getMin() << std::endl;
    stack.push(0);
    std::cout << stack.getMin() << std::endl;

    stack.pop();
    std::cout << stack.getMin() << std::endl;

    stack.push(4);
    std::cout << stack.getMin() << std::endl;
    stack.push(-4);
    std::cout << stack.getMin() << std::endl;
    stack.push(2);
    std::cout << stack.getMin() << std::endl;

    stack.pop();
    std::cout << stack.getMin() << std::endl;
    stack.pop();
    std::cout << stack.getMin() << std::endl;

    return 0;
}
