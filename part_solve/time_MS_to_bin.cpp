#include <iostream>
#include <string>
#include <bitset>

using namespace std;
string changetoBinary(unsigned int &time)
{
    return bitset<32>(time).to_string();
}
int main()
{

    unsigned int time = 1125000;

    cout << changetoBinary(time);
}