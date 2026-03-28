#include <iostream>
using namespace std;

// print next character
char printNextCharacter(char ch) {
    int n = int(ch);
    char next_ch;

    if (n < 65 || (n > 90 && n < 97) || n > 122) {
        cout << "Invalid Input ";
        return ch;  // return same char just to satisfy return type
    }
    else if (n == 122) {
        cout << "Character Next to " << ch << " is : " << char(97)<<"\n";
        return char(97);
    }
    else if (n == 90) {
        cout << "Character Next to " << ch << " is : " << char(65)<<"\n";
        return char(65);
    } else {
        next_ch = char(n + 1);
        cout << "Character Next to " << ch << " is : " << next_ch<<"\n";
        return next_ch;
    }
}

int main() {
    char ch;
    cout << "Enter the Chharacter : ";
    cin >> ch;

    printNextCharacter(ch);
}
