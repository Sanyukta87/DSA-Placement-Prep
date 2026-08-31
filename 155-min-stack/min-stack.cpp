class MinStack {
public:

    stack<int> st;       // Stores all values
    stack<int> minSt;    // Stores minimum values

    MinStack() {
        // Constructor  used
    }

    void push(int x) {

        st.push(x);      // Always push into normal stack

        // Push into min stack only if
        // x becomes a new minimum
        if(minSt.empty() || x <= minSt.top())
        {
            minSt.push(x);
        }
    }

    void pop() {

        // If removing current minimum,
        // remove it from min stack too
        if(st.top() == minSt.top())
        {
            minSt.pop();
        }

        st.pop();        // Remove from normal stack
    }

    int top() {

        // Return current top
        return st.top();
    }

    int getMin() {

        // Minimum is always at top of min stack
        return minSt.top();
    }
};