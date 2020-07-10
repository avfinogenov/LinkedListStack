#include "Stack.h"

Stack::Stack()
{
}

Stack::Stack(Stack& source)
{
	count = source.count;
	Linklist* tmp;
	tmp = source.plast;
	int* t = new int[count];
	for(int i=0;i<count;i++)
	{
		t[i] = tmp->val;
		tmp = tmp->pprev;
		//node = source.plast->pprev;
	}
	for (int i = count ; i >0 ; i--)
	{
		Push(t[i - 1]);
	}
	delete[] t;

}

Stack& Stack::operator=(Stack& source)
{
	
	for (int i = 0; i < source.count; i++)
	{
		Pop();
	}
	count = source.count;
	Linklist* tmp;
	tmp = source.plast;
	int* t = new int[count];
	for (int i = 0; i < count; i++)
	{
		t[i] = tmp->val;
		tmp = tmp->pprev;
		//node = source.plast->pprev;
	}
	for (int i = count; i > 0; i--)
	{
		this->Push(t[i - 1]);
	}
	delete[] t;

	return *this;


	// TODO: вставьте здесь оператор return
}

Stack::~Stack()
{
	while(plast!=nullptr)
		{
			Pop();
		}
	
}

void Stack::Push(int in_val)
{
	Linklist* node = new Linklist(in_val);
	if (plast == nullptr )
	{
		plast = node;
		
	}
	else
	{
		node->pprev = plast;
		plast = node;
		
	}
	count++;
}

int Stack::Pop()
{
	if (plast != nullptr)
	{
		Linklist* p = plast->pprev;
		int tmp = plast->val;
		delete plast;
		plast = p;
		count--;
		return tmp;
		
	}
	else
	{
		return -1;
	}
}

int Stack::Size() const
{

	return count;
}

bool Stack::Empty() const
{
	if (plast==nullptr)
	{
		return true;
	}
	return false;
}
