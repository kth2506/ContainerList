// ** List ver.02 06.13

#include <iostream>

using namespace std;

struct List
{
	List* Front;
	int Value;
	List* Back;

};

void push_back(List* _Next, const int& _value);

void Insert(List* _Next,const int _where, const int& _value);

void Output(List* _Next);

void Erase(List* _Next, const int& _where);

int main(void)
{
	List* NumberList = new List;
	NumberList->Value = 10;
	NumberList->Back = nullptr;
	for (int i = 0; i < 9; ++i)
	{
		push_back(NumberList, (i+1) * 10 + 10);
	}

	Insert(NumberList, 5, 2);
	Erase(NumberList, 5);
	Output(NumberList);
	return 0;
}

void push_back(List* _Next, const int& _value)
{
	if (_Next->Back == nullptr)
	{
		List* Temp = new List;

		Temp->Value = _value;
		Temp->Back = nullptr;

		_Next->Back = Temp;
	}
	else
		push_back(_Next->Back, _value);
}

void Insert(List* _Next, const int _where, const int& _value)
{
	if (_where > 2)
		Insert(_Next->Back, _where - 1, _value);
	else
	{
		List* Temp = new List;
		Temp->Value = _value;
		Temp->Back = _Next->Back;

		_Next->Back = Temp;
	}
}

void Output(List* _Next)
{
	cout << _Next->Value << endl;
	
	if (_Next->Back != nullptr)
		Output(_Next->Back);
}

List* front = nullptr;
void Erase(List* _Next, const int& _where)
{
	if (_where > 1)
	{
		front = _Next;
		Erase(_Next->Back, _where - 1);
	
	}
	else
	{
		//List* Temp = _Next->Back;
		//_Next->Back = _Next->Back->Back;
		front->Back = _Next->Back;

		cout << &front->Back->Back << endl;
		cout << &_Next->Back->Back << endl;
		delete _Next;
		_Next = nullptr;


	}

}
