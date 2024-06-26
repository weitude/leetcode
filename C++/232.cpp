class MyQueue {
	stack<int> stk1;
	stack<int> stk2;

	public:
	MyQueue() {}

	void push(int x) {
		stk1.push(x);
	}

	int pop() {
		if (stk2.empty()) {
			while(!stk1.empty()) {
				int temp = stk1.top();
				stk1.pop();
				stk2.push(temp);
			}
		}
		int temp = stk2.top();
		stk2.pop();
		return temp;
	}

	int peek() {
		if (stk2.empty()) {
			while(!stk1.empty()) {
				int temp = stk1.top();
				stk1.pop();
				stk2.push(temp);
			}
		}
		return stk2.top();
	}

	bool empty() {
		return stk1.empty() && stk2.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

