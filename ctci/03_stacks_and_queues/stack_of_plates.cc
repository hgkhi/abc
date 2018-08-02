#include <bits/stdc++.h>
using namespace std;

class PlateStacks {
	private:
		size_t stack_limit;
		vector<stack<int>> stacks;
		size_t stack_pointer;
	public:
		PlateStacks(size_t stack_limit)
		{
			if (stack_limit <= 0) {
				throw bad_alloc();
			}
			this->stack_limit = stack_limit;
		}

		void push(int value)
		{
			if (stack_pointer >= stacks.size()) {
				stacks.push_back(stack<int>());
			}

			stacks[stack_pointer].push(value);
			if (stacks[stack_pointer].size() >= stack_limit) {
				++stack_pointer;
			}
		}

		int pop()
		{
			if (stack_pointer >= stacks.size() ||
					stacks[stack_pointer].empty()) {
				if (stack_pointer <= 0) {
					throw underflow_error("Empty stack!");
				}

				--stack_pointer;
			}
			int top = stacks[stack_pointer].top();
			stacks[stack_pointer].pop();
			return top;
		}
};
