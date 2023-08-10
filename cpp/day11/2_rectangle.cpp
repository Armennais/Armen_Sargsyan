#include <iostream>
#include <string>
using namespace std;
int main() {
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    cout << "Input:" << endl;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;
    
    int AB_x = (x1 - x2);
    int AB_y = (y1 - y2);
    int CD_x = (x3 - x4);
    int CD_y = (y3 - y4);
    
    int scalareProd = AB_x * CD_x + AB_y * CD_y; 
    
    string res = (scalareProd == 0)? "Yes .":"No";
    
    cout <<"Output : \n " << res << endl;
    
    return 0;
}
