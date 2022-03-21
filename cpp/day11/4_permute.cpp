#include <iostream>
#include <string>
using namespace std;

void permute(string a, int l, int r);
void my_swap(char& a, char& b);
int main()
{
	string str ;
     	cout << "Input: ";
	cin >> str;
	int n = str.size() - 1;
	permute(str, 0, n);
	return 0;
}

void my_swap(char& a, char& b) {
    int t = a;
    a = b;
    b = t;
}

void permute(string a, int l, int r)
{
	if (l == r)
		cout<<a<<endl;
	else
	{
		for (int i = l; i <= r; i++)
		{
			my_swap(a[l], a[i]);
			permute(a, l+1, r);
			my_swap(a[l], a[i]);
		}
	}
}
