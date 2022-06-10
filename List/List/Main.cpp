// ** List ver.01 06.10

#include <iostream>

using namespace std;

struct List
{
	int Value;
	List* Back;

};

void AddObject(List* _Next, const int& _value);

void Output(List* _Next);

void Insert(List* _Next, const int& _where);

void Erase(List* _Next, const int& _where);

int main(void)
{
	List* NumberList = new List;
	NumberList->Value = 0;
	NumberList->Back = nullptr;
	for (int i = 0; i < 10; ++i)
	{
		AddObject(NumberList, i * 10 + 10);
	}

	Output(NumberList);
	return 0;
}

void AddObject(List* _Next, const int& _value)
{
	if (_Next->Back == nullptr)
	{
		List* Temp = new List;

		Temp->Value = _value;
		Temp->Back = nullptr;

		_Next->Back = Temp;
	}
	else
		AddObject(_Next->Back, _value);
}

void Output(List* _Next)
{
	cout << _Next->Value << endl;
	
	if (_Next->Back != nullptr)
		Output(_Next->Back);
}

void Insert(List* _Next, const int& _where, const int& _value)
{
	AddObject(_Next, _value);
}

void Erase(List* _Next, const int& _where)
{

}
