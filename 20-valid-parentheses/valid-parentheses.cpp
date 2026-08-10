class Solution {
public:
    bool isValid(string s) {
  stack<char> st;
  
       for(char c : s)
{
    // Opening → push
    if(c == '(' || c == '[' || c == '{')
    {
        st.push(c);
    }
    else
    {
        // Closing but nothing to match
        if(st.empty())
            return false;

        // Wrong matching bracket
        if((c == ')' && st.top() != '(') ||
           (c == ']' && st.top() != '[') ||
           (c == '}' && st.top() != '{'))
        {
            return false;
        }

        st.pop(); // Correct match → remove opening bracket
    }
}

// Everything matched only if stack is empty
return st.empty();
    }
};