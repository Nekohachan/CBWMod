#pragma once
#include <functional>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

// ExpressionParser::evaluateCondition("表达式")


// 表达式解析器类
class ExpressionParser {
public:
    // 解析并计算表达式
    static double evaluate(const std::string& expression, const std::map<std::string, double>& variables = {}) {
        std::string expr = removeSpaces(expression);
        return parseExpression(expr, variables);
    }

    // 检查条件表达式是否成立
    static bool evaluateCondition(const std::string& condition, const std::map<std::string, double>& variables = {}) {
        std::string cond = removeSpaces(condition);

        // 查找比较运算符
        std::vector<std::string> operators = {"==", "!=", ">=", "<=", ">", "<"};
        for (const auto& op : operators) {
            size_t pos = cond.find(op);
            if (pos != std::string::npos) {
                std::string leftExpr  = cond.substr(0, pos);
                std::string rightExpr = cond.substr(pos + op.length());

                double leftVal  = parseExpression(leftExpr, variables);
                double rightVal = parseExpression(rightExpr, variables);

                if (op == "==") return leftVal == rightVal;
                if (op == "!=") return leftVal != rightVal;
                if (op == ">=") return leftVal >= rightVal;
                if (op == "<=") return leftVal <= rightVal;
                if (op == ">") return leftVal > rightVal;
                if (op == "<") return leftVal < rightVal;
            }
        }

        // 如果没有比较运算符，则计算表达式并检查是否为真（非零）
        return parseExpression(cond, variables) != 0.0;
    }

private:
    // 移除字符串中的所有空格
    static std::string removeSpaces(const std::string& s) {
        std::string result;
        for (char c : s) {
            if (!std::isspace(c)) {
                result += c;
            }
        }
        return result;
    }

    // 解析表达式
    static double parseExpression(const std::string& expr, const std::map<std::string, double>& variables) {
        // 处理括号
        size_t openParen = expr.find('(');
        if (openParen != std::string::npos) {
            int    parenCount = 1;
            size_t closeParen = openParen + 1;

            while (closeParen < expr.length() && parenCount > 0) {
                if (expr[closeParen] == '(') parenCount++;
                if (expr[closeParen] == ')') parenCount--;
                closeParen++;
            }

            if (parenCount == 0) {
                closeParen--;
                std::string inside      = expr.substr(openParen + 1, closeParen - openParen - 1);
                double      insideValue = parseExpression(inside, variables);

                std::string newExpr =
                    expr.substr(0, openParen) + std::to_string(insideValue) + expr.substr(closeParen + 1);
                return parseExpression(newExpr, variables);
            }
        }

        // 处理运算符优先级（乘除优先于加减）
        std::vector<std::pair<std::string, std::function<double(double, double)>>> operations = {
            {"*", [](double a, double b) { return a * b; }},
            {"/", [](double a, double b) { return a / b; }},
            {"+", [](double a, double b) { return a + b; }},
            {"-", [](double a, double b) { return a - b; }}
        };

        for (const auto& op : operations) {
            size_t pos = expr.find(op.first);
            if (pos != std::string::npos && pos > 0 && pos < expr.length() - 1) {
                std::string left  = expr.substr(0, pos);
                std::string right = expr.substr(pos + op.first.length());

                double leftVal  = parseExpression(left, variables);
                double rightVal = parseExpression(right, variables);

                return op.second(leftVal, rightVal);
            }
        }

        // 处理变量和数字
        if (variables.find(expr) != variables.end()) {
            return variables.at(expr);
        }

        // 尝试转换为数字
        try {
            return std::stod(expr);
        } catch (...) {
            throw std::runtime_error("无法解析表达式: " + expr);
        }
    }
};