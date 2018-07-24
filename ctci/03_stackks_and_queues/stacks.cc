#include <iostream>
#include <stdexcept>

using namespace std;

class MultiStack {
	private:
		size_t stack_num;
		size_t stack_size;
		int* data;
		size_t* sizes;
		size_t* tops;

		void stack_index_check(size_t stack_index)
		{
			if (stack_index >= stack_num) {
				throw out_of_range("Stack index out of range!");
			}
		}
	public:
		MultiStack(size_t stack_num, size_t stack_size)
		{
			this->stack_num = stack_num;
			this->stack_size = stack_size;

			size_t data_size = stack_num * stack_size;
			data = new int[data_size];

			sizes = new size_t[stack_num]();	// Set 0

			tops = new size_t[stack_num]();		// Set 0 too
			for (size_t i = 0; i < stack_num; ++i) {
				tops[i] = i * stack_size;
			}
		}

		~MultiStack()
		{
			delete[] data;
			data = nullptr;

			delete[] sizes;
			sizes = nullptr;

			delete[] tops;
			tops = nullptr;
		}

		void push(size_t stack_index, int value)
		{
			// Check for out-of-bound stack_index
			stack_index_check(stack_index);

			// Check for overflow
			if (sizes[stack_index] >= stack_size) {
				throw overflow_error("Stack is full!");
			}
			data[tops[stack_index]++] = value;
			++sizes[stack_index];
		}

		int pop(size_t stack_index)
		{
			// Check for out-of-bound stack_index
			stack_index_check(stack_index);

			// Check for underflow
			if (sizes[stack_index] == 0) {
				throw underflow_error("Stack is empty!");
			}
			--sizes[stack_index];
			return data[--tops[stack_index]];
		}

		size_t size(size_t stack_index)
		{
			return sizes[stack_index];
		}

		void dump()
		{
			cout << "sizes:" << endl;
			for (size_t i = 0; i < stack_num; ++i) {
				cout << sizes[i] << " ";
			}
			cout << endl;
			cout << "tops:" << endl;
			for (size_t i = 0; i < stack_num; ++i) {
				cout << tops[i] << " ";
			}
			cout << endl;
			cout << "data:" << endl;
			for (size_t i = 0; i < stack_num * stack_size; ++i) {
				cout << data[i] << " ";
			}
			cout << endl;
		}
};

int main()
{
	size_t stack_num = 3;
	size_t stack_size = 5;

	MultiStack mstack(stack_num, stack_size);
	try {
		for (size_t i = 0; i < stack_num; ++i) {
			for (size_t j = 0; j < stack_size; ++j) {
				mstack.push(i, j);
			}
		}
		mstack.dump();
		for (size_t i = 0; i < stack_num; ++i) {
			cout << "Stack " << i << endl;
			for (size_t j = 0; j < stack_size; ++j) {
				cout << mstack.pop(i) << endl;
			}
		}
	} catch (out_of_range ex) {
		cout << "OOR" << endl;
	} catch (underflow_error ex) {
		cout << "Underflow" << endl;
	} catch (overflow_error) {
		cout << "Overflow" << endl;
	}
}
