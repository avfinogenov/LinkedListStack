#pragma once
class Linklist
{
	
	
public:
	int val;
	Linklist* pprev = nullptr;
	Linklist();
	Linklist(int in_val)
	{
		val = in_val;
	}
	Linklist& operator =(Linklist& source)
	{
		val = source.val;
	}
};
class Stack
{

	

public:
	Stack();
	Stack(Stack& source);
	Stack& operator= (Stack& source);
	~Stack();
	void Push( int in_val);
	int Pop();
	int Size() const;
	bool Empty() const;
	Linklist* plast = nullptr;
private:
	int count = 0;
	
	
};