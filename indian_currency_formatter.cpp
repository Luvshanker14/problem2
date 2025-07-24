#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
string formatIndianCurrency(double num) {
    ostringstream oss;
    oss<<fixed<<setprecision(2)<<num;
    string s=oss.str();
    size_t dot=s.find('.');
    string intPart=s.substr(0,dot);
    string decPart=s.substr(dot);
    string res;
    int n=intPart.length();
    if (n > 3) 
    {
        res=intPart.substr(n-3);
        int i=n-4;
        while(i>=0) 
        {
            if (i==0)
            {
                res=intPart.substr(0, 1)+","+res;
                i--;
            } 
            else 
            {
                res=intPart.substr(i-1,2)+","+res;
                i-=2;
            }
        }
    } 
    else 
    {
        res=intPart;
    }
    return res+decPart;
}
// int main() 
// {
//     double num;
//     cin>>num;
//     cout <<formatIndianCurrency(num)<<endl;
//     return 0;
// }
