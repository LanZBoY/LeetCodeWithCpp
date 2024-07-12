#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

string predictPartyVictory(string senate)
{
    unordered_map<char, string> resultMapping;
    resultMapping['R'] = "Radiant";
    resultMapping['D'] = "Dire";
    unordered_map<char, int> charIntMapping;
    charIntMapping['R'] = 0;
    charIntMapping['D'] = 1;
    int remainSkipping[2] = {0, 0};

    unordered_map<char, int> charCount;

    queue<char> q;
    for (char c : senate)
    {
        q.push(c);
        charCount[c]++;
    }
    for (auto pair : charCount)
    {
        if (pair.second == q.size())
        {
            return resultMapping[pair.first];
        }
    }
    while (q.size() > 1)
    {
        char c = q.front();

        if (remainSkipping[charIntMapping[c]] > 0)
        {
            remainSkipping[charIntMapping[c]]--;
            q.pop();
            charCount[c]--;
            if (charCount[c] == 0)
                break;
            continue;
        }
        remainSkipping[1 - charIntMapping[c]]++;
        q.push(c);
        q.pop();
    }
    return resultMapping[q.front()];
}

int main()
{
    cout << predictPartyVictory("RRR") << endl;
    cout << predictPartyVictory("RDD") << endl;
    cout << predictPartyVictory("DDRRR") << endl;
    cout << predictPartyVictory("DRRDRDRDRDDRDRDR") << endl;

    return 0;
}