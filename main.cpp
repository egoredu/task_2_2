#include <iostream>
#include <vector>
using namespace std;

int main() {
    // последовательно вводятся элементы массива, 0 – последний элементы
    // считается количество смен знака
    vector<int> array;
    int input;

    cin >> input;
    // stop when input equals zero
    while (input != 0){
        array.push_back(input);
        cin >> input;
    }

    int cur, maxlen, buf;
    vector<int>::iterator iter = array.begin();
    maxlen = 0;
    buf = 0;
    while (iter != array.end()) {
        // get the current element
        cur = *iter;
        if (cur % 2 != 0) buf++; // увеличиваем счетчик нечетных
        else{
            if (buf > maxlen) maxlen = buf; // если текущий счетчик больше максимума – обновляем максимум
            buf = 0;
        }
        ++iter;
    }
    if (buf > maxlen) maxlen = buf;
    cout << maxlen;
    return 0;
}