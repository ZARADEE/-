//下列代码是给出给定合式的真值表
//使用传统逻辑的进行栈和输入检测，满足条件则进行相应运算
//公式（析取:\\/，合取:/\\，条件:->，双条件:<->，否定:~）
//对于输入字母没有限制，怎么输入怎么输出
//关于处理在从主函数跳转至本函数后直接结束的问题，是通过新的cin.ignore取走缓冲区的回车


#include <iostream>
#include <cstring>
using namespace std;

#define N 150

int Get_Alpha_and_Sort(char a[], char b[]) {
    char tmp = ' ';
    int n = strlen(a);
    int i = 0, j = 0, k = 0;
    for (i = 0; i < n; i++) {
        if (((a[i] >= 'a') && (a[i] <= 'z')) || ((a[i] >= 'A') && (a[i] <= 'Z'))) {
            for (k = 0; k < j; k++) {
                if (b[k] == a[i])
                    break;
            }
            if (k >= j) {
                b[j] = a[i];
                j++;
            }
        }
    }
    for (i = 0; i < j - 1; i++) {
        for (k = 0; k < j - i - 1; k++) {
            if (b[k] > b[k + 1]) {
                tmp = b[k];
                b[k] = b[k + 1];
                b[k + 1] = tmp;
            }
        }
    }
    b[j] = '\0';
    return j;
}

void FillValue(char intial[], char alpha[], int var, char val[], char result[]) {
    int M = strlen(intial);
    int i = 0, j = 0, k = 0;
    for (i = 0; i < M; i++) {
        result[i] = intial[i];
    }
    result[i] = '\0';
    for (i = 0; i < M; i++) {
        for (j = 0; j < var; j++) {
            if (result[i] == alpha[j]) {
                result[i] = val[j];
                break;
            }
        }
    }
}

void NOT(char a[]) {
    int flag = 0;
    int i = 0, j = 0;
    while (i < strlen(a)) {
        j = i;
        flag = 0;
        if ((j + 1 < strlen(a)) && (a[j] == '~') && (a[j + 1] == '1')) {
            a[j] = '0';
            flag = 1;
        }
        else if ((j + 1 < strlen(a)) && (a[j] == '~') && (a[j + 1] == '0')) {
            a[j] = '1';
            flag = 1;
        }
        if (flag == 1) {
            j++;
            while (a[j + 1] != '\0') {
                a[j] = a[j + 1];
                j++;
            }
            a[j] = '\0';
        }
        else {
            i++;
        }
    }
}

void bracket(char a[]) {
    int flag = 0;
    int i = 0, j;
    while (i < strlen(a)) {
        j = i;
        flag = 0;
        if ((j + 2 < strlen(a)) && (a[j] == '(') && (a[j + 1] == '1') && (a[j + 2] == ')')) {
            a[j] = '1';
            flag = 1;
        }
        else if ((j + 2 < strlen(a)) && (a[j] == '(') && (a[j + 1] == '0') && (a[j + 2] == ')')) {
            a[j] = '0';
            flag = 1;
        }
        if (flag == 1) {
            j++;
            while (a[j + 2] != '\0') {
                a[j] = a[j + 2];
                j++;
            }
            a[j] = '\0';
        }
        else {
            i++;
        }
    }
}

void AND(char a[]) {
    int flag = 0;
    int i = 0, j = 0;
    while (i < strlen(a)) {
        j = i;
        flag = 0;
        if ((j + 3 < strlen(a)) && (a[j] == '0') && (a[j + 1] == '/') && (a[j + 2] == '\\') && (a[j + 3] == '0')) {
            a[j] = '0';
            flag = 1;
        }
        else if ((j + 3 < strlen(a)) && (a[j] == '0') && (a[j + 1] == '/') && (a[j + 2] == '\\') && (a[j + 3] == '1')) {
            a[j] = '0';
            flag = 1;
        }
        else if ((j + 3 < strlen(a)) && (a[j] == '1') && (a[j + 1] == '/') && (a[j + 2] == '\\') && (a[j + 3] == '0')) {
            a[j] = '0';
            flag = 1;
        }
        else if ((j + 3 < strlen(a)) && (a[j] == '1') && (a[j + 1] == '/') && (a[j + 2] == '\\') && (a[j + 3] == '1')) {
            a[j] = '1';
            flag = 1;
        }
        if (flag == 1) {
            j++;
            while (a[j + 3] != '\0') {
                a[j] = a[j + 3];
                j++;
            }
            a[j] = '\0';
        }
        else {
            i++;
        }
    }
}

void OR(char a[]) {
    int flag = 0;
    int i = 0, j = 0;
    while (i < strlen(a)) {
        j = i;
        flag = 0;
        if ((j + 3 < strlen(a)) && (a[j] == '0') && (a[j + 1] == '\\') && (a[j + 2] == '/') && (a[j + 3] == '0')) {
            a[j] = '0';
            flag = 1;
        }
        else if ((j + 3 < strlen(a)) && (a[j] == '0') && (a[j + 1] == '\\') && (a[j + 2] == '/') && (a[j + 3] == '1')) {
            a[j] = '1';
            flag = 1;
        }
        else if ((j + 3 < strlen(a)) && (a[j] == '1') && (a[j + 1] == '\\') && (a[j + 2] == '/') && (a[j + 3] == '0')) {
            a[j] = '1';
            flag = 1;
        }
        else if ((j + 3 < strlen(a)) && (a[j] == '1') && (a[j + 1] == '\\') && (a[j + 2] == '/') && (a[j + 3] == '1')) {
            a[j] = '1';
            flag = 1;
        }
        if (flag == 1) {
            j++;
            while (a[j + 3] != '\0') {
                a[j] = a[j + 3];
                j++;
            }
            a[j] = '\0';
        }
        else {
            i++;
        }
    }
}

void YunHan(char a[]) {
    int flag = 0;
    int i = 0, j = 0;
    while (i < strlen(a)) {
        j = i;
        flag = 0;
        if ((j + 3 < strlen(a)) && (a[j] == '0') && (a[j + 1] == '-') && (a[j + 2] == '>') && (a[j + 3] == '0')) {
            a[j] = '1';
            flag = 1;
        }
        else if ((j + 3 < strlen(a)) && (a[j] == '0') && (a[j + 1] == '-') && (a[j + 2] == '>') && (a[j + 3] == '1')) {
            a[j] = '1';
            flag = 1;
        }
        else if ((j + 3 < strlen(a)) && (a[j] == '1') && (a[j + 1] == '-') && (a[j + 2] == '>') && (a[j + 3] == '0')) {
            a[j] = '0';
            flag = 1;
        }
        else if ((j + 3 < strlen(a)) && (a[j] == '1') && (a[j + 1] == '-') && (a[j + 2] == '>') && (a[j + 3] == '1')) {
            a[j] = '1';
            flag = 1;
        }
        if (flag == 1) {
            j++;
            while (a[j + 3] != '\0') {
                a[j] = a[j + 3];
                j++;
            }
            a[j] = '\0';
        }
        else {
            i++;
        }
    }
}

void DengJia(char a[]) {
    int flag = 0;
    int i = 0, j = 0;
    while (i < strlen(a)) {
        j = i;
        flag = 0;
        if ((j + 4 < strlen(a)) && (a[j] == '0') && (a[j + 1] == '<') && (a[j + 2] == '-') && (a[j + 3] == '>') && (a[j + 4] == '0')) {
            a[j] = '1';
            flag = 1;
        }
        else if ((j + 4 < strlen(a)) && (a[j] == '0') && (a[j + 1] == '<') && (a[j + 2] == '-') && (a[j + 3] == '>') && (a[j + 4] == '1')) {
            a[j] = '0';
            flag = 1;
        }
        else if ((j + 4 < strlen(a)) && (a[j] == '1') && (a[j + 1] == '<') && (a[j + 2] == '-') && (a[j + 3] == '>') && (a[j + 4] == '0')) {
            a[j] = '0';
            flag = 1;
        }
        else if ((j + 4 < strlen(a)) && (a[j] == '1') && (a[j + 1] == '<') && (a[j + 2] == '-') && (a[j + 3] == '>') && (a[j + 4] == '1')) {
            a[j] = '1';
            flag = 1;
        }
        if (flag == 1) {
            j++;
            while (a[j + 4] != '\0') {
                a[j] = a[j + 4];
                j++;
            }
            a[j] = '\0';
        }
        else {
            i++;
        }
    }
}

int Mathtablem() {

    char State0[N];
    char State[N] = { 0 };
    char AlphaList[N];
    char CharVal[N];


    cout << "-----------------------------------------------------" << endl;
    cout << "|            zaradee的离散辅助编程代码              |" << endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "|       请输入需要进行构造真值表的合式公式 ：       |" << endl;
    cout << "|             字母为小写字母                        |" << endl;
    cout << "|（析取:\\/，合取:/\\，条件:->，双条件:<->，否定:~）|：" << endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "|  当前程序等待响应。。。。。                       |" << endl;
    cout << "|  正在预测对应输入，以及构造真值表                 |" << endl;
    cout << "|  正在分析，请稍作等待                             |" << endl;
    cout << "-----------------------------------------------------" << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空输入缓冲区,把输入的回车当作取字符取进去了

    cin.getline(State0, N);

    //cout << "cout 0" << endl;//作为测试的输出标记
    //测试用标记
    int old = strlen(State0) + 1;
    int nnew = strlen(State0);

    for (int i = 0; i < nnew; i++) {
        State[i] = State0[i];
    }
    State[nnew] = '\0';
    //  cout << "cout1" << endl;   测试用标记点
    int var = Get_Alpha_and_Sort(State, AlphaList);

    int Row = 1;
    for (int i = 0; i < var; i++) {
        CharVal[i] = '0';
        Row = Row * 2;
    }
    CharVal[var] = '\0';
    cout << endl;

    for (int i = 0; i < var; i++) {
        cout << AlphaList[i] << "    ";
    }
    cout << " " << State << endl;
    // cout << "cout 2" << endl; 测试用标记点
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < var; j++) {
            cout << CharVal[j] << "    ";
        }
        State[0] = '\0';

        FillValue(State0, AlphaList, var, CharVal, State);

        old = strlen(State0) + 1;
        nnew = strlen(State);
        while (nnew < old) {
            old = strlen(State);

            NOT(State);
            bracket(State);
            AND(State);
            OR(State);
            YunHan(State);
            DengJia(State);

            nnew = strlen(State);
        }

        cout << " " << State << endl;
        int flag = 1;
        for (int j = var - 1; j >= 0; j--) {
            if (CharVal[j] == '1') {
                if (flag == 1) {
                    CharVal[j] = '0';
                    flag = 1;
                }
                else
                    break;
            }
            else if (CharVal[j] == '0') {
                if (flag == 1) {
                    CharVal[j] = '1';
                    flag = 0;
                }
                else
                    break;
            }
        }
    }

    return 0;
}
