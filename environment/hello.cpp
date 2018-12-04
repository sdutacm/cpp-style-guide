#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    auto return_code = []() { return 0; }();
    cout << "Hello World!" << endl;
    return return_code;
}