#include "string.h"
#include <iostream>
#include <cstring>

using namespace std;

void String::freeMemory()
{
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
    }
    length = 0;
}

void String::copyFrom(const char *str, int len)
{
    data = new char[len + 1];
    strcpy(data, str);
    length = len;
}

String::String() : data(new char[1])
{
    data[0] = '\0';
}

String::String(const char *str) : data(nullptr)
{
    if (str != nullptr)
    {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }
    else
    {
        data = new char[1];
        data[0] = '\0';
    }
}

String::String(const String &other) : data(nullptr), length(other.length)
{
    if (other.data != nullptr)
    {
        data = new char[length + 1];
        strcpy(data, other.data);
    }
    else
    {
        data = new char[1];
        data[0] = '\0';
    }
}

String::~String()
{
    freeMemory();
}

String &String::operator=(const char *str)
{
    if (this->data != str)
    {
        freeMemory();
        if (str != nullptr)
        {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        }
        else
        {
            data = new char[1];
            data[0] = '\0';
            length = 0;
        }
    }
    return *this;
}

String &String::operator=(const String &other)
{
    if (this != &other)
    {
        freeMemory();
        length = other.length;
        if (other.data != nullptr)
        {
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        else
        {
            data = new char[1];
            data[0] = '\0';
        }
    }
    return *this;
}

String &String::operator+=(const char *str)
{
    if (str != nullptr && str[0] != '\0')
    {
        auto strLen = strlen(str);
        auto *newData = new char[length + strLen + 1];

        if (data != nullptr)
        {
            strcpy(newData, data);
        }
        else
        {
            newData[0] = '\0';
        }

        strcat(newData, str);
        freeMemory();
        data = newData;
        length += strLen;
    }
    return *this;
}

String &String::operator+=(const String &other)
{
    if (other.length > 0 && other.data != nullptr)
    {
        char *newData = new char[length + other.length + 1];

        if (data != nullptr)
        {
            strcpy(newData, data);
        }
        else
        {
            newData[0] = '\0';
        }

        strcat(newData, other.data);
        freeMemory();
        data = newData;
        length += other.length;
    }
    return *this;
}


String operator+(const String& lhs, const String& rhs) {
    String result = lhs;
    result += rhs;
    return result;
}

String operator+(const String& lhs, const char* rhs) {
    String result = lhs;
    result += rhs;
    return result;
}

String operator+(const char* lhs, const String& rhs) {
    String result = lhs;
    result += rhs;
    return result;
}


std::ostream &operator<<(std::ostream &os, const String &str) {
    return os << (str.data ? str.data : "");
}

std::istream &operator>>(std::istream &is, String &str) {
    const size_t MAX_BUFFER = 1024;
    char buffer[MAX_BUFFER];
    is.width(MAX_BUFFER);
    if (is >> buffer) {
        str = buffer;
    }
    return is;
}