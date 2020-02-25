//
// Created by loohan on 2019/5/20.
//

#ifndef ALGORITHMMS_MYSTRING_H
#define ALGORITHMMS_MYSTRING_H

#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

class MyString
{
public:
    MyString(const char* str = NULL);
    MyString(const MyString& other);  // copy constructor
    MyString& operator=(const MyString& other);  // operator= constructor
    MyString& operator+(const MyString& other);  // concat string
    bool operator==(const MyString& other);  // string cmp
    int length(const MyString& other)  // length of string
    {
        return strlen(m_data_);
    }
    ~MyString();
    friend ostream& operator<<(ostream &out, MyString &other)
    {
        out << other.m_data_;
        return out;
    }
private:
    char* m_data_;
};

MyString::MyString(const char *str)
{
    if (str == NULL)
    {
        m_data_ = new char[1];
        *m_data_ = '\0';  // set eof to '\0'
    } else
    {
        m_data_ = new char[strlen(str + 1)];
        strcpy(m_data_, str);
    }
}

MyString::~MyString()
{
    if (m_data_) {
        delete[] m_data_;
        m_data_ = 0;
    }
}

MyString::MyString(const MyString &other)
{
    if (!other.m_data_)
        m_data_ = 0;

    m_data_ = new char[strlen(other.m_data_) + 1];
    strcpy(m_data_, other.m_data_);
}

MyString& MyString::operator=(const MyString &other)
{
    if (this != &other)  // is not equal to itself
    {
        delete[] m_data_;  // clear itself first
        if (!other.m_data_)  // have no data
        {
            m_data_ = 0;
        } else
        {
            m_data_ = new char[strlen(other.m_data_) + 1];
            strcpy(m_data_, other.m_data_);
        }
    }
    return *this;
}

bool MyString::operator==(const MyString &other)
{
    if (strlen(other.m_data_) != strlen(m_data_))
        return false;
    return other.m_data_ == m_data_ ? true : false;
}

//MyString newString;
//MyString& MyString::operator+(const MyString &other)
//{
//    // if defined here and return newString, it'll crash when involve it outside
//    // because it'll released out of this scope.
//    MyString newString;
//    if (!other.m_data_)
//    {
//        newString = *this;
//    } else if(!m_data_)
//    {
//        newString = other;
//    } else {
//        newString.m_data_ = new char[strlen(other.m_data_) + strlen(m_data_) + 1];
//        strcpy(newString.m_data_, m_data_);
//        strcat(newString.m_data_, other.m_data_);
//    }
//    return newString;
//}

MyString& MyString::operator+(const MyString &other)
{
    if (!other.m_data_)
    {
        return *this;
    } else if(!m_data_)
    {
        m_data_ = new char[strlen(other.m_data_) + 1];
        strcpy(m_data_, other.m_data_);
    } else {
        strcat(m_data_, other.m_data_);
    }
    return *this;
}

int main()
{
    MyString str_01 = "hello";
    MyString str_02 = " world";
    MyString str_03;
    str_03 = str_01 + str_02;

    bool isEaual = str_01 == str_02;

    cout << str_01 << endl;
    cout << str_02 << endl;
    cout << str_03 << endl;
    cout << isEaual << endl;
}

#endif //ALGORITHMMS_MYSTRING_H
