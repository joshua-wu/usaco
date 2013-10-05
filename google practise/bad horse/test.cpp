#include <iostream>
#include <map>
#include<math.h>
#include<string>
using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

int main()
{
    string sentence = "And I feel fine...";
    cout<<string("/home/home/tt").split<<endl;
    cin.get();
    return 0;
}
