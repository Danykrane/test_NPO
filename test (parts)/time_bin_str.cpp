#include <iostream>
#include <string>
#include <bitset>

using namespace std;
string changetoBinary(unsigned short int years)
{
    return bitset<16>(years).to_string();
}
int main()
{
 
    unsigned short int years = 65535;
    
    cout << changetoBinary(years);
}