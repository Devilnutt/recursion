#include <iostream>
#include <cctype>
// �����
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}
// �����
bool isLetter(char c) {
    return (c >= 'a' && c <= 'e') || (c >= 'A' && c <= 'E');
}
// ����� ��� �����
bool isUnsignedInteger(const char*& str) {
    if (isDigit(*str)) {
        ++str;
        while (isDigit(*str)) {
            ++str;
        }
        return true;
    }
    return false;
}
// �������������
bool isIdentifier(const char*& str) {
    if (isLetter(*str)) {
        ++str;
        return true;
    }
    return false;
}
// ���������
bool isFactor(const char*& str) {
    return isUnsignedInteger(str) || isIdentifier(str);
}
// ����
bool isTerm(const char*& str) {
    if (isFactor(str)) {
        if (*str == '*' /*?? || *str == '/' ??*/) {
            ++str;
            return isTerm(str);
        }
        return true;
    }
    return false;
}
// ���������
bool isExpression(const char*& str) {
    if (isTerm(str)) {
        if (*str == '+' || *str == '-') {
            ++str;
            return isExpression(str);
        }
        return true;
    }
    return false;
}
bool isExpressionImpl(const char* str) {
    return isExpression(str) && *str == '\0';
}

int main() {
    setlocale(LC_ALL, "Russian");
    const char* expr1 = "1*4-b";             // ���������1
    const char* expr2 = "144+2+c";           // ���������2
    const char* expr3 = "19/4-c";            // ���������3
    const char* expr4 = "12+a+b";            // ���������4

    std::cout << expr1 << (isExpressionImpl(expr1) ? " - ������" : " - ����") << std::endl;
    std::cout << expr2 << (isExpressionImpl(expr2) ? " - ������" : " - ����") << std::endl;
    std::cout << expr3 << (isExpressionImpl(expr3) ? " - ������" : " - ����") << std::endl;
    std::cout << expr4 << (isExpressionImpl(expr4) ? " - ������" : " - ����") << std::endl;

    return 0;
}
