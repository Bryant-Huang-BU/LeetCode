class Solution {
public:
    string predictPartyVictory(string senate) {
        string decision = "", test = senate;
        int s = senate.size(), i = 0;
        map<int, bool> eligible;
        if (senate.find('D') == -1) {
            return "Radiant";
        }
        else if (senate.find('R') == -1) {
            return "Dire";
        }
        while (senate.find('D') != -1 && senate.find('R') != -1) {
            if (senate[i] == 'R') {
                int x = senate.find_first_of('D', i);
                if (x == -1) {
                    x = senate.find('D');
                }
                //cout << "found " << x << endl; 
                senate[x] = 'X';
                //cout << senate << endl;
            }       
            else if (senate[i] == 'D') {
                int x = senate.find_first_of('R', i);
                if (x == -1) {
                    x = senate.find('R');
                }
                //cout << "found " << x << endl;
                senate[x] = 'X';
                //cout << senate << " " << i << endl;

            }
            if (i >= s) {
                i = 0;
            }
            else {
                i++;
            }
        }
        if (senate.find('D') != -1) {
            //cout << senate << endl;
            //cout << senate.find('D') << endl;
            return "Dire";
        }
        else {
            cout << senate << endl;
            return "Radiant";
        }
        //cout << senate << endl;
        //return decision;
    }
};