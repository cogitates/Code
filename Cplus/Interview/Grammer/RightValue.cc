// Big Block
// https://www.nowcoder.com/discuss/418915


#include <string>
#include <iostream>
using namespace std;
 
int main() {
    {
        std::string s = "1234";
        cout << s << endl; // "1234"
    }
    {
        std::string s = "1234";
        std::move(s);
        cout << s << endl; // "1234"
    }
    {
        std::string s = "1234";
        const auto& s1 = std::move(s);
        cout << s << ' ' << s1 << endl; // "1234 1234"
    }
    {
        std::string s = "1234";
        auto&& s1 = std::move(s);
        cout << s << ' ' << s1 << endl; // "1234 1234"
    }
 
    {
        std::string s = "1234";
        auto s1 = std::move(s);
        cout << s << ' ' << s1 << endl;  // " 1234"
 
    }
 
    return 0;
}