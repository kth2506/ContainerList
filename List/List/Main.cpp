// ** List ver.03 06.14

#include <iostream>

using namespace std;

struct List
{
	List* Front;
	int Value;
	List* Back;

};

void push_back(List* _Current, const int& _value);
void pop_back(List* _Current);
void Insert(List* _Current,const int _where, const int& _value);
void Output(List* _Current);
void Erase(List* _Current, const int& _where);

List* End = nullptr;
int main(void)
{
	List* NumberList = new List;
	
	NumberList->Front = nullptr;
	NumberList->Value = 10;
	NumberList->Back = nullptr;
	for (int i = 0; i < 9; ++i)
	{
		push_back(NumberList, (i+1) * 10 + 10);
	}

	Erase(NumberList, 10);
	Output(NumberList);
	return 0;
}

void push_back(List* _Current, const int& _value)
{
	if (_Current->Back == nullptr)
	{
		List* Temp = new List;

		Temp->Front = _Current;
		Temp->Value = _value;
		Temp->Back = nullptr;

		_Current->Back = Temp;
	}
	else
		push_back(_Current->Back, _value);
}

void pop_back(List* _Current)
{
	if (_Current->Back == nullptr)
	{
		End = _Current->Front;

		_Current->Front->Back = nullptr;
		delete _Current;
		_Current = nullptr;
	}
	else
		pop_back(_Current->Back);

}
void Insert(List* _Current, const int _where, const int& _value)
{
	if (_where > 2)
		Insert(_Current->Back, _where - 1, _value);
	else
	{
		List* Temp = new List;

		Temp->Front = _Current;
		Temp->Value = _value;
		Temp->Back = _Current->Back;

		_Current->Back = Temp;
	}
}

void Output(List* _Current)
{
	cout << _Current->Value << endl;
	
	if (_Current->Back != nullptr)
		Output(_Current->Back);
}

void Erase(List* _Current, const int& _where)
{
	if (_where > 1)
	{
		Erase(_Current->Back, _where - 1);
	}
	else
	{
		if (_Current->Back == nullptr)
		{
			End = _Current->Front;
			_Current->Front->Back = nullptr;
		}
		else
		{
			_Current->Back->Front = _Current->Front;
			_Current->Front->Back = _Current->Back;
		}

		delete _Current;
		_Current = nullptr;
	}

}

