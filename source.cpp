#include <iostream>
#include <string>
#include <vector>
using namespace std;

void swap(int* a, int* b) 
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

void bubble_recursive(vector<int>* arr, int i) 
{
	if (i == 0)
		return;

	for (int j = 0; j < i - 1; j++)
	{
		if ((*arr)[j] < (*arr)[j + 1]) 
		{
			swap(&(*arr)[j], &(*arr)[j + 1]);
		}
	}
	bubble_recursive(arr, i - 1);
}

vector<int> input_num() 
{
	string strInput;
	vector<int> vec;
	string str = "";
	cout << "숫자를 입력하시오 : ";
	getline(cin, strInput);
	cout << endl;

	for (int i = 0; i < strInput.length(); i++) 
	{
		if (strInput.at(i) == ' ') 
		{
			vec.push_back(atof(str.c_str()));
			str = "";
		}
		else 
		{
			str += strInput.at(i);
			continue;
		}
	}
	vec.push_back(atoi(str.c_str()));

	return vec;
}


int GC_non_Recursive(vector<int> original_arr) 
{
	vector<int> arr(original_arr);
	int chk = 1;
	int GC = 1;
	if (arr.back() != 1) 
	{
		for (int i = 1; i <= arr.back(); i++) 
		{
			for (int j = 0; j < arr.size(); j++) 
			{
				if ((arr[j] % i) != 0) 
				{
					chk = 0;
					break;
				}
			} 
			if (chk == 1)
			{
				for (int j = 0; j < arr.size(); j++) 
				{
					arr[j] = arr[j] / i;
				}

				GC = GC * i;
				i = 1;
			}

			chk = 1;
		}
		return GC;
	}
	else 
	{
		return 1;
	}
}

int main() 
{
	vector<int> arr = input_num();
	int GC;

	for (int i : arr) 
	{
		cout << i << " ";
	}
	cout << endl;
	bubble_recursive(&arr, arr.size());
	GC = GC_non_Recursive(arr);
	cout << "최대 공약수 : " << GC << endl;
}