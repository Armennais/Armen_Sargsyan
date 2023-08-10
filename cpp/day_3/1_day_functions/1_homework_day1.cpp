#include <iostream>
using namespace std;


void num_guess(int s_num){
  int number;

  do {
    if (s_num < 0 || s_num > 100)
    {
      cout << "I said in[0:100] range!!! \n";
      cin >> s_num;
    }
    else
    {
      cout << "Try guess the number : \n";
      cin >> number;
      if (number < s_num)
      {
        cout << "Try a larger number \n";
      }
      else if (number > s_num)
      {
        cout << "Try a smaller number \n";
      }
      else
      {
        cout << "YESSS!!!  \n";
      }
    }
  } while (number != s_num);
}

int main()
{
        int s_num;  // secret number
        cout << "Input secret number for guessing in[0:100] range \n";
        cin >> s_num;  //Input secret number
       
	num_guess(s_num);
        
	return 0;
}


