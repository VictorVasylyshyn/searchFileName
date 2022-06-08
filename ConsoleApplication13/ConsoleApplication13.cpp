#include <string>
#include <iostream>
#include <filesystem>
#include <Windows.h>
namespace fs = std::filesystem;
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Choose disk(C, D, E..): ";
    string disk;
    cin >> disk;
    int count = 0;
    fs::path p(disk + ":\\");

    if (exists(p))
    {
        if (is_directory(p))
        {
            cout << p << " is a directory containing:\n";
            typedef vector<fs::path> vec;
            vec v;
            copy(fs::directory_iterator(p), fs::directory_iterator(), back_inserter(v));
            sort(v.begin(), v.end());
            for (vec::const_iterator it(v.begin()); it != v.end(); ++it)
            {
                cout << "   " << *it << '\n';
            }
            cout << "Search file by name(with extension): ";
            string str;
            cin >> str;
            for (vec::const_iterator it(v.begin()); it != v.end(); ++it)
            {
                if (("E:\\" + str) == *it)
                {
                    cout << "   " << *it << '\n';
                    count++;
                }

            }
            if (count == 0) {
                cout << "This file doesn't exist!" << endl;
            }
        }
        else {
            cout << p << " exists, but is neither a regular file nor a directory\n";
        }
    }
    else {
        cout << p << " does not exist\n";
    }
    return 0;
}