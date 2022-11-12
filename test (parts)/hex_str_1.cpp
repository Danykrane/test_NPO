#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    // char word[] = {48, 65, 6c, 6c, 6f, 21};
    long int val = 3254329049236;
    char str = 'A';
    string value = "Hello";
    ostringstream ss;
    ss << hex << val;
    string result = ss.str();
    cout << result << endl; // 3e8

    for (auto &it : value)
    {
        cout << hex << (int)it << ' ';
    }
    cout << endl;
    cout << hex << val << endl;
    cout << hex << static_cast<int>(str) << endl;

}