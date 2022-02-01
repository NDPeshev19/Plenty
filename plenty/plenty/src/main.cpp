#include "include\backend\LinkedList.h"

#include <iostream>

class Demo
{
public:
	int first;
	int second;
	
	// mandatory
	Demo()
	{
		first = 0;
		second = 0;
	}

	// mandatory
	Demo(int f, int s)
	{
		first = f;
		second = s;
	}

	// mandatory
	Demo(const Demo& t)
	{
		first = t.first;
		second = t.second;
	}
	
	// mandatory if you want to use ll.printList or cout << ll;
	// alternative: print manually
	friend std::ostream& operator<<(std::ostream& out, Demo obj)
	{
		out << "F: " << obj.first << ' ' << "S: " << obj.second;
		return out;
	}

	// mandatory if you want to use any node specific functions like removeNode or addAfterNode
	// alternative: please don't
	friend bool operator==(const Demo& lhs, const Demo& rhs)
	{
		return lhs.first == rhs.first && lhs.second == lhs.second;
	}
};

int main()
{
	std::cout << "Hello World!" << std::endl;

	LinkedList<Demo> ll;

	ll.addAtBack(Demo(1, 2));
	ll.addAtBack(Demo(3, 4));
	ll.addAtBack(Demo(5, 6));

	std::cout << ll << std::endl;

	ll.removeNode({ 3, 4 });

	ll.printList();
}