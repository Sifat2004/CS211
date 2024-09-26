#include <iostream>
using namespace std;
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int main()
{
    while (true)
    {
        string outcome;
        cout << "Enter the race outcome(uppercase letters or 'done' to stop): ";
        cin >> outcome;
        if (outcome == "done")
            break;
        int numTeams = 0;
        int maxTeamSize = 0;
        int scores['Z' + 1] = {};
        int counts['Z' + 1] = {};
        for (int i = 0; i < outcome.length(); ++i)
        {
            scores[outcome[i]] += i + 1;
            if (counts[outcome[i]] == 0)
                ++numTeams;
            ++counts[outcome[i]];
            maxTeamSize = max(maxTeamSize, counts[outcome[i]]);
        }
        if (maxTeamSize != outcome.length() / numTeams)
        {
            cout << "The teams don't have the same number of runners.\n";
            continue;
        }
        cout << "There are " << numTeams << " teams.\n";
        cout << "Each team has " << maxTeamSize << " runners.\n";
        string winningTeams = "";
        double winningScore = outcome.length() * outcome.length();
        for (char i = 'A'; i <= 'Z'; ++i)
        {
            if (scores[i] != 0)
            {
                cout << i << ": " << (double)scores[i] / maxTeamSize << endl;
                if (scores[i] < winningScore)
                {
                    winningTeams = i;
                    winningScore = scores[i];
                }
            }
        }
        cout << "The winning team is team " << winningTeams << " with score " << winningScore / maxTeamSize << endl;
    }
    return 0;
}