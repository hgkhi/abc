#include <bits/stdc++.h>
using namespace std;

class StackQueue {
    private:
        stack<int> push_stack;
        stack<int> pop_stack;
        bool last_push;     // true if the last operation is push()

        /**
         * Runtime: O(n)
         */
        void stack_dump(stack<int>& dst, stack<int>& src)
        {
            while (!src.empty()) {
                dst.push(src.top());
                src.pop();
            }
        }
    public:
        StackQueue()
        {
            last_push = true;   // Just assume that
        }

        /**
         * Runtime: Worst: O(n)
         * Best + Avg: O(1)
         * Amotized: O(1)
         */
        void push(int value)
        {
            if (!last_push) {
                // All the data is in pop_stack now
                stack_dump(push_stack, pop_stack);
                last_push = true;
            }
            push_stack.push(value);
        }

        /**
         * Runtime: Worst: O(n)
         * Best + Avg: O(1)
         * Amotized: O(1)
         */
        int pop()
        {
            if (last_push) {
                stack_dump(pop_stack, push_stack);
                last_push = false;
            }

            if (!pop_stack.empty()) {
                int top = pop_stack.top();
                pop_stack.pop();
                return top;
            } else {
                throw underflow_error("Popping empty stack!");
            }
        }
        
        /**
         * Runtime: O(1)
         */
        size_t size()
        {
            // There must be an empty stack
            return push_stack.size() + pop_stack.size();
        }
};
