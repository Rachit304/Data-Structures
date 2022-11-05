#include <iostream>
using namespace std;
int Stairs(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    return Stairs(n -1) + Stairs (n-2) + Stairs(n-3);
    
}
int main() {
    int n;
    cin >> n;
    cout<< Stairs(n) << endl;

}
