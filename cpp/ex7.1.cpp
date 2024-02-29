#include <iostream>
#include <cstring>

class String
{
public:
    // 构造函数
    String(const char* str = nullptr)
    {
        if (str != nullptr)
        {
            len = strlen(str);
            p = new char[len + 1];
            strcpy(p, str);
        }
        else
        {
            len = 0;
            p = nullptr;
        }
    }

    // 拷贝构造函数
    String(const String& other)
    {
        len = other.len;
        if (other.p != nullptr)
        {
            p = new char[len + 1];
            strcpy(p, other.p);
        }
        else
        {
            p = nullptr;
        }
    }

    // 赋值运算符重载
    String& operator=(const String& other)
    {
        if (this == &other)
        {
            return *this;
        }

        if (p != nullptr)
        {
            delete[] p;
        }

        len = other.len;
        if (other.p != nullptr)
        {
            p = new char[len + 1];
            strcpy(p, other.p);
        }
        else
        {
            p = nullptr;
        }

        return *this;
    }

    // 加法运算符重载
    String operator+(const String& other) const
    {
        String result;
        result.len = len + other.len;
        result.p = new char[result.len + 1];
        if (p != nullptr)
        {
            strcpy(result.p, p);
        }
        if (other.p != nullptr)
        {
            strcat(result.p, other.p);
        }
        return result;
    }

    // 减法运算符重载
    String operator-(const String& other) const
    {
        String result;
        int i = len - 1;
        while (i >= 0 && p[i] == ' ')
        {
            i--;
        }
        result.len = i + 1 + other.len;
        result.p = new char[result.len + 1];
        if (p != nullptr)
        {
            strncpy(result.p, p, i + 1);
        }
        if (other.p != nullptr)
        {
            strcat(result.p, other.p);
        }
        return result;
    }

    // 友元函数，输出字符串
    friend std::ostream& operator<<(std::ostream& os, const String& str)
    {
        os << str.p;
        return os;
    }

    // 析构函数
    ~String()
    {
        if (p != nullptr)
        {
            delete[] p;
        }
    }

private:
    char* p; // 指向存储的字符串
    int len; // 记录字符串的长度
};

int main()
{
    String s1("hello");
    String s2(" world");
    String s3("   ");

    // 测试加法运算符重载
    String s4 = s1 + s2;
    std::cout << "s1 + s2 = " << s4 << std::endl;

    // 测试减法运算符重载
    String s5 = s1 - s3 + s2;
    std::cout << "s1 - s3 + s2 = " << s5 << std::endl;

    return 0;
}
