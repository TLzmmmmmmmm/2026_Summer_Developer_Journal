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
    int compare(const BigInt& bi) const;
    void removeLeadingZeros();
    BigInt operator+(const BigInt& bi) const;
    BigInt operator-(const BigInt& bi) const;
    BigInt operator*(const BigInt& bi) const;
    BigInt operator*(int value) const;
    BigInt operator/(const BigInt& bi) const;
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
    removeLeadingZeros();
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

int BigInt::compare(const BigInt& bi) const {
    if(m_size != bi.m_size) {
        return m_size > bi.m_size ? 1: -1;
    }
    for (int i = m_size - 1 ; i >= 0 ; i--) {
        if (m_data[i] != bi.m_data[i]) {
            return m_data[i] > bi.m_data[i] ? 1 : -1;
        }
    }
    return 0;
}

void BigInt::removeLeadingZeros() {
    while (m_size > 0 && m_data[m_size - 1] == 0) {
        --m_size;
    }
}

BigInt BigInt::operator+(const BigInt& bi) const {
    BigInt ret;
    int i, carry = 0;
    for (i = 0 ; i < m_size || i < bi.m_size || carry > 0 ; i++) {
        if (i >= Capacity) {
            throw overflow_error(
                "BigInt capacity exceeded"
            );
        }
        if(i < m_size) carry += m_data[i];
        if(i < bi.m_size) carry += bi.m_data[i];
        ret.m_data[i] = carry % Base;
        carry /= Base;
    }
    ret.m_size = i;
    return ret;
}

// does not support negative result
BigInt BigInt::operator-(const BigInt& bi) const {
    BigInt ret;
    int i, carry = 0;
    ret.m_size = m_size;
    for (i = 0 ; i < ret.m_size ; i++) {
        ret.m_data[i] = m_data[i] - carry;
        if (i < bi.m_size) {
            ret.m_data[i] -= bi.m_data[i];
        }
        if (ret.m_data[i] < 0) {
            carry = 1;
            ret.m_data[i] += Base;
        }
        else {
            carry = 0;
        }
    }
    ret.removeLeadingZeros();
    return ret;
}

BigInt BigInt::operator*(const BigInt& bi) const {
    BigInt ret;

    if (m_size == 0 || bi.m_size == 0) {
        return ret;
    }

    if (m_size + bi.m_size > Capacity) {
        throw overflow_error("BigInt capacity exceeded");
    }

    ret.m_size = m_size + bi.m_size;

    for (int i = 0 ; i < m_size ; i++) {
        long long carry = 0;
        for (int j = 0 ; j < bi.m_size ; j++) {
            long long current =
                ret.m_data[i + j]
                + 1LL * m_data[i] * bi.m_data[j]
                + carry;

            ret.m_data[i + j] = current % Base;
            carry = current / Base;
        }
        ret.m_data[i + bi.m_size] += carry;
    }
    ret.removeLeadingZeros();
    return ret;
}

BigInt BigInt::operator*(int value) const {
    if (value < 0) {
        throw invalid_argument(
            "Negative multiplier is not supported"
        );
    }
    
    BigInt ret;

    if (value == 0 || m_size == 0) {
        return ret;
    }

    long long carry = 0;
    int i = 0;

    while (i < m_size || carry > 0) {
        long long current = carry;
        if (i < m_size) {
            current += 1LL * m_data[i] * value;
        }
        ret.m_data[i] = current % Base;
        carry = current / Base;
        ++i;
    }
    ret.m_size = i;
    return ret;
}

// integer only && ignore sign && round down to nearest integer
BigInt BigInt::operator/(const BigInt& bi) const {
    if (bi.m_size == 0) {
        throw invalid_argument("Division by zero");
    }

    BigInt ret, remainder;
    ret.m_size = m_size;
    for (int i = m_size - 1 ; i >= 0 ; --i) {
        if (remainder.m_size > 0 || m_data[i] != 0) {
            if (remainder.m_size >= Capacity) {
                throw overflow_error("BigInt capacity exceeded");
            }

            for (int j = remainder.m_size; j > 0; --j) {
                remainder.m_data[j] = remainder.m_data[j - 1];
            }

            remainder.m_data[0] = m_data[i];
            ++remainder.m_size;
        }
        int left = -1;
        int right = Base;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if ((bi * mid).compare(remainder) <= 0) {
                left = mid;
            }
            else {
                right = mid;
            }
            
        }
        ret.m_data[i] = left;
        remainder = remainder - bi * left;
    }
    ret.removeLeadingZeros();
    return ret;
}