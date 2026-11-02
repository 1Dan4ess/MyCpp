#pragma once
#include "String.h"

class BitString : public String
{
public:
    BitString() : String() {}
    BitString(const char* str) : String(str)
    {
        for (size_t i = 0; i < getLength(); i++)
        {
            if (getStr()[i] != '0' and getStr()[i] != '1')
            {
                clear();
                break;
            }
        }
    }

    BitString(const BitString& str) : String(str) {}

    BitString operator+(const BitString& str) const
    {
        BitString result(*this);
        result += str;
        return result;
    }

    BitString& operator+=(const BitString& str)
    {
        int len1 = getLength();
        int len2 = str.getLength();
        int maxLen;
        if (len1 > len2)
        {
            maxLen = len1;
        }
        else
        {
            maxLen = len2;
        }
        char* buff = new char[maxLen + 2];
        buff[maxLen + 1] = '\0';
        int i = len1 - 1;
        int j = len2 - 1;
        int k = maxLen;
        int carry = 0;
        while (k >= 0)
        {
            int bit1 = 0;
            int bit2 = 0;
            if (i >= 0)
            {
                bit1 = getStr()[i] - '0';
                i--;
            }
            if (j >= 0)
            {
                bit2 = str.getStr()[j] - '0';
                j--;
            }
            int sum = bit1 + bit2 + carry;
            buff[k] = sum % 2 + '0';
            carry = sum / 2;
            k--;
        }
        int start = 0;
        while (buff[start] == '0' and buff[start + 1] != '\0')
        {
            start++;
        }
        *this = BitString(buff + start);
        delete[] buff;
        return *this;
    }

    bool operator==(const BitString& str) const
    {
        int i = 0;
        int j = 0;
        while (getStr()[i] == '0')
        {
            i++;
        }
        while (str.getStr()[j] == '0')
        {
            j++;
        }
        return strcmp(getStr() + i, str.getStr() + j) == 0;
    }

    bool operator!=(const BitString& str) const
    {
        return !(*this == str);
    }
};