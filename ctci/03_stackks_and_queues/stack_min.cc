#include <bits/stdc++.h>
using namespace std;

class MinStack {
	private:
		stack<int> data;
		stack<int> min_stack;
	public:
		void push(int value)
		{
			data.push(value);
			if (min_stack.empty()) {
				min_stack.push(value);
			} else {
				min_stack.push(::min(value, min_stack.top()));
			}
		}

		int pop()
		{
			int top = data.top();
			data.pop();
			min_stack.pop();

			return top;
		}

		int min()
		{
			return min_stack.top();
		}
};
