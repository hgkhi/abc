#include <bits/stdc++.h>
using namespace std;

/**
 * Runtime: O(n)
 */
void dump_stack(stack<int>& dst, stack<int>& src)
{
    while (!src.empty()) {
        dst.push(src.top());
        src.pop();
    }
}

/**
 *  Runtime: O(n^2)
 *  Space: O(n)
 */
void sort_stack(stack<int>& data)
{
    int temp_var;
    stack<int> temp_stack;
    while (!data.empty()) {
        if (temp_stack.empty()) {
            temp_stack.push(data.top());
            data.pop();
        } else {
            if (data.top() < temp_stack.top()) {
                temp_var = data.top();
                data.pop();
                dump_stack(data, temp_stack);
                data.push(temp_var);
            } else {
                temp_stack.push(data.top());
                data.pop();
            }
        }
    }
    dump_stack(data, temp_stack);
}
