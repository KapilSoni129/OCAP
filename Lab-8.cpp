#include <iostream>
#include <string>

using namespace std;

string removeKdigits(string num, int k)
{
    int n = num.size();
    string res = "";

    if (n == k)
        return "0";

    for (char c : num)
    {
        while (res.size() > 0 && k > 0 && res.back() > c)
        {
            res.pop_back();
            k--;
        }
        res.push_back(c);
    }

    while (res.size() > 1 && res.back() == '0')
    {
        res.pop_back();
    }

    return res.empty() ? "0" : res;
}

int main()
{
    string num;
    int k;

    cout << "Enter the number: ";
    cin >> num;

    cout << "Enter the number of digits to remove: ";
    cin >> k;

    string result = removeKdigits(num, k);
    cout << "Smallest number after removing " << k << " digits: " << result << endl;

    return 0;
}
