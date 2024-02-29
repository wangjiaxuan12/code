#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string str = "...|(600100) 上海银行|(600111) 中远海运|(613500) 北京城建|(100350) 泸州老窖|...";
    std::regex regex("\\|(\\(\\d+\\))\\s+([^|]+)");
    std::smatch match;
    std::string::const_iterator iter(str.cbegin());
    std::string::const_iterator end(str.cend());
    while (std::regex_search(iter, end, match, regex)) {
        if (match.size() == 3) {
            std::string num = match[1].str();
            std::string cn = match[2].str();

            num.erase(std::remove_if(num.begin(), num.end(), [](char c) {
                return c == '(' || c == ')' || c == ' ';
            }), num.end());
            cn.erase(std::remove_if(cn.begin(), cn.end(), [](char c) {
                return c == '(' || c == ')' || c == ' ';
            }), cn.end());

            std::cout << "代码: " << num << ", 名称: " << cn << std::endl;
        }
        iter = match.suffix().first;
    }

    return 0;
}

