#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("text.txt");
    string s;

    while (getline(fin, s)) {
        cout << s << endl;
    }
    fin.close();
    return 0;
}