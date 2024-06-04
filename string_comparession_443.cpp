#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int put_char_num(vector<char> &chars, int index, int count)
{
    stack<char> s;
    if (count == 1)
        return ++index;
    while (count > 0)
    {
        s.push((count % 10) + '0');
        count /= 10;
    }
    while (!s.empty())
    {
        chars[++index] = s.top();
        s.pop();
    }
    return ++index;
}

int compress(vector<char> &chars)
{
    int i = 0;
    int count = 0;
    char current_char = chars[0];
    for (char ele : chars)
    {
        if (current_char == ele)
        {
            count++;
        }
        else
        {
            chars[i] = current_char;
            i = put_char_num(chars, i, count);
            current_char = ele;
            count = 1;
        }
    }
    if (i + 1 == chars.size())
    {
        return chars.size();
    }
    chars[i] = current_char;
    return put_char_num(chars, i, count);
}

int main()
{
    vector<char> in_data({'a', 'a', 'b', 'b', 'c', 'c', 'c'});
    cout << compress(in_data) << endl;
    in_data = vector({'a'});
    cout << compress(in_data) << endl;
    in_data = vector({'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'});
    cout << compress(in_data) << endl;
    in_data = vector({'a', 'a', 'a', 'b', 'b', 'a', 'a'});
    cout << compress(in_data) << endl;
    return 0;
}