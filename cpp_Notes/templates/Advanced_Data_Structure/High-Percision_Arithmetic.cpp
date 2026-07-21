#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdexcept>

using namespace std;

const int Base = 1000;
const int BaseDigits = 3;
const int Capacity = 100;

class BigInt {
private:
    int m_data[Capacity];
    int m_size;

public:
    BigInt();
    BigInt(const BigInt& bi) = default;
    BigInt(const char s[]);

    BigInt& operator=(const BigInt& bi) = default;

    void print(char end = '\n') const;
};

BigInt::BigInt() : m_data{}, m_size(0) {}

BigInt::BigInt(const char s[]) : m_data{}, m_size(0) {
    int length = static_cast<int>(strlen(s));

    for (int end = length; end > 0; end -= BaseDigits) {
        if (m_size >= Capacity) {
            throw overflow_error("BigInt capacity exceeded");
        }

        int start = max(0, end - BaseDigits);
        int block = 0;

        for (int i = start; i < end; ++i) {
            if (s[i] < '0' || s[i] > '9') {
                throw invalid_argument(
                    "BigInt requires decimal digits"
                );
            }

            block = block * 10 + (s[i] - '0');
        }

        m_data[m_size++] = block;
    }
    // delete the highest digit block's leading 0 
    while (m_size > 0 && m_data[m_size - 1] == 0) {
        --m_size;
    }
}

void BigInt::print(char end) const {
    if (m_size == 0) {
        cout << 0 << end;
        return;
    }

    cout << m_data[m_size - 1];

    for (int i = m_size - 2; i >= 0; --i) {
        for (int j = Base / 10; j > 0; j /= 10) {
            cout << (m_data[i] / j) % 10;
        }
    }

    cout << end;
}