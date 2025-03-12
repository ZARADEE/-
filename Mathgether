#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <numeric> // 包含accumulate函数的头文件
#include <tuple>   // 包含tuple的头文件

using namespace std;

// 辅助函数：确定运算符的优先级
int precedence(char op) {
    if (op == '~') return 3;
    if (op == '&' || op == '|') return 2;
    if (op == '>') return 1; // 蕴含
    return 0;
}

// 函数：应用运算符到两个操作数并返回结果
bool applyOp(bool a, bool b, char op) {
    switch (op) {
    case '&': return a && b;
    case '|': return a || b;
    case '>': return !a || b; // 蕴含
    }
    return false;
}

// 函数：将中缀表达式转换为后缀表达式
string infixToPostfix(const string& exp) {
    stack<char> ops;
    string postfix;
    for (char ch : exp) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            ops.push(ch);
        }
        else if (ch == ')') {
            while (!ops.empty() && ops.top() != '(') {
                postfix += ops.top();
                ops.pop();
            }
            ops.pop();
        }
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(ch)) {
                postfix += ops.top();
                ops.pop();
            }
            ops.push(ch);
        }
    }
    while (!ops.empty()) {
        postfix += ops.top();
        ops.pop();
    }
    return postfix;
}

// 函数：使用给定的变量值评估后缀表达式
bool evaluatePostfix(const string& postfix, const unordered_map<char, bool>& values) {
    stack<bool> st;
    for (char ch : postfix) {
        if (isalnum(ch)) {
            st.push(values.at(ch));
        }
        else {
            bool val2 = st.top(); st.pop();
            bool val1 = st.top(); st.pop();
            st.push(applyOp(val1, val2, ch));
        }
    }
    return st.top();
}

// 函数：生成所有可能的变量真值赋值
vector<unordered_map<char, bool>> generateTruthAssignments(const vector<char>& vars) {
    vector<unordered_map<char, bool>> assignments;
    int n = vars.size();
    int total = 1 << n; // 2^n
    for (int i = 0; i < total; ++i) {
        unordered_map<char, bool> assignment;
        for (int j = 0; j < n; ++j) {
            assignment[vars[j]] = (i & (1 << j)) != 0;
        }
        assignments.push_back(assignment);
    }
    return assignments;
}

// 函数：从表达式中提取变量
vector<char> extractVariables(const string& exp) {
    vector<char> vars;
    for (char ch : exp) {
        if (isalnum(ch) && find(vars.begin(), vars.end(), ch) == vars.end()) {
            vars.push_back(ch);
        }
    }
    return vars;
}

// 函数：从后缀表达式生成DNF和CNF
pair<string, string> generateDNF_CNF(const string& postfix, const vector<char>& vars) {
    vector<unordered_map<char, bool>> truthAssignments = generateTruthAssignments(vars);
    vector<string> dnfClauses, cnfClauses;

    for (const auto& assignment : truthAssignments) {
        if (evaluatePostfix(postfix, assignment)) {
            // DNF子句
            string clause;
            for (char var : vars) {
                clause += (assignment.at(var) ? "" : "~") + string(1, var) + "&";
            }
            clause.pop_back();
            dnfClauses.push_back("(" + clause + ")");
        }
        else {
            // CNF子句
            string clause;
            for (char var : vars) {
                clause += (assignment.at(var) ? "~" : "") + string(1, var) + "|";
            }
            clause.pop_back();
            cnfClauses.push_back("(" + clause + ")");
        }
    }

    string dnf = accumulate(dnfClauses.begin(), dnfClauses.end(), string(), [](const string& a, const string& b) { return a.empty() ? b : a + "|" + b; });
    string cnf = accumulate(cnfClauses.begin(), cnfClauses.end(), string(), [](const string& a, const string& b) { return a.empty() ? b : a + "&" + b; });

    return { dnf, cnf };
}

int Mathgether() {
    string exp; // 示例布尔表达式

    // 输出表达式以供测试
   // cout << "测试的布尔表达式: " << exp << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "|            zaradee的离散辅助编程代码              |" << endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "|       请输入需要进行相应求解的合式公式            |" << endl;
    cout << "|             字母为小写字母                        |" << endl;
    cout << "|      （析取:&，合取:|，条件:>，否定:~）      |：" << endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "|  当前程序等待响应。。。。。                       |" << endl;
    cout << "|  正在预测对应输入，以及构造相应的合式公式         |" << endl;
    cout << "|  正在分析，请稍作等待                             |" << endl;
    cout << "-----------------------------------------------------" << endl;

    cin >> exp;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空输入缓冲区,把输入的回车当作取字符取进去了
    string postfix = infixToPostfix(exp);
    vector<char> vars = extractVariables(exp);
    pair<string, string> dnf_cnf = generateDNF_CNF(postfix, vars);
    string dnf = dnf_cnf.first;
    string cnf = dnf_cnf.second;

    cout << "后缀表达式: " << postfix << endl;
    cout << "析取范式 (DNF): " << dnf << endl;
    cout << "合取范式 (CNF): " << cnf << endl;

    return 0;
}
