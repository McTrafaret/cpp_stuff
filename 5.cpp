#include <iostream>
#include <string>

struct stack
{
	stack(int value);
	stack * next = NULL;
	int data;
};

stack::stack(int value)
{
	data = value;
}

bool is_empty(stack * node)
{
	return node == NULL;
}

void push(stack *& node, int value)
{
	stack * top = new stack(value);
	top -> next = node;
	node = top;
}

int pop(stack *& node)
{
	int value = node -> data;
	stack * temp = node;
	node = node -> next;
	delete temp;
	return value;
}

int peek(stack * node)
{
	return node -> data;
}

void stack_list(stack * node)
{
	while(!(is_empty(node)))
	{
		std::cout << node -> data << ' ';
		node = node -> next;
	}
	std::cout << std::endl;
}

bool is_in_array(char * array, int size, char symbol)
{
	for(int i = 0;i < size;i++)
	{
		if (symbol == array[i]) return true;
	}
	return false;
}

int get_index(char * array, int size, char symbol)
{
	for(int i = 0;i < size;i++)
	{
		if (symbol == array[i]) return i;
	}
	return 1232;
}

bool task_2(std::string expression)
{
	char open_brackets[3] {'(', '[', '{'};
	char close_brackets[3] {')', ']', '}'};
	stack * node = NULL;
	for(int i = 0;i < expression.length();i++)
	{
		if(is_in_array(open_brackets, 3, expression[i]))
		{
			push(node, expression[i]);
		}
		else if(is_in_array(close_brackets, 3, expression[i]))
		{
			int index = get_index(close_brackets, 3, expression[i]);
			if(peek(node) == open_brackets[index]) pop(node);
		}
	}
	return is_empty(node);
}

int task_3(std::string expression)
{
	stack * node = NULL;
	int divider;
	int subtrahend;
	for(int i = 0;i < expression.length();i++)
	{
		if(expression[i] > 47 && expression[i] < 58)
		{
			push(node, expression[i]-48);
		}
		else switch(expression[i])
		{
			case '+' :
				push(node, pop(node) + pop(node));
				break;
			case '-' :
				subtrahend = pop(node);
				push(node, pop(node) - subtrahend);
				break;
			case '*' :
				push(node, pop(node) * (pop(node)));
				break;
			case '/' :
				divider = pop(node);
				push(node, pop(node) / divider);
				break;
			default : std::cout << "Wrong input" << std::endl;
		}
	}
	return pop(node);
}

int main()
{
	std::string expression;
	std::cin >> expression;
	std::cout << task_3(expression) << std::endl;
	/*
	if (task_2(expression)) std::cout << "hype" << std::endl;
	else std::cout << "not hype" << std::endl;
	*/
	return 0;
}
