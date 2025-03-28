// 主函数主要是作为一个输出的窗口，更多的是互动性，真正的功能实现在于Mathcounterm和mathtablem的这两个函数
// 函数封装在Mathtable Mathcounter两个文件中，使用extern + 函数名的形式作为调用。
//原谅我主文件图省事直接叫filename吧
//选择进行输出的类型以及类别

#include <iostream>
#include <cstring>
extern int Mathcounterm();
extern int Mathtablem();
extern int Mathgether();

using namespace std;
//选择是否是已经标定的输入模式，并返回相应的触发数字
int choosefun(string c) {
    int flag = 0;
    if (c == "M") {
        flag = 1; // 调用Mathcounter，输出化简过程
    }
    else if (c == "T") {
        flag = 2; // 调用Mathtable输出真值表
    }
    else if (c == "F") {
        flag = 3;//调用Mathgether,求解主合取范式以及主析取范式
    }
    else {
        flag = -1;
    }
    return flag;
}

int main() {
    string c;
    int gex;

    cout << "------------------------------------------------------" << endl;
    cout << "|            zaradee的离散辅助编程代码                |" << endl;
    cout << "|-----------------------------------------------------|" << endl;
    cout << "|     请选择需要进行的操作模式（输入小写字母M,T,F）： |" << endl;
    cout << "|     本程序为内测版本                            ：  | " << endl;
    cout << "|-----------------------------------------------------|" << endl;
    cout << "|     M - 输出化简过程                                |" << endl;
    cout << "|     T - 输出真值表                                  |" << endl;
    cout << "|     F - 主合取范式以及主析取范式求解                |" << endl;
    cout << "|     其余功能暂未实装                                |" << endl;
    cout << "------------------------------------------------------" << endl;


    cin >> c;
    gex = choosefun(c);


    if (gex == 2) {
        Mathtablem();
    }
    else if (gex == 1) {
        Mathcounterm();
    }
    else if (gex == 3) {
        Mathgether();
    }
    else if (gex == -1) {
        cout << "-----------------------------------------------------" << endl;
        cout << "|            zaradee的离散辅助编程代码              |" << endl;
        cout << "|---------------------------------------------------|" << endl;
        cout << "|       请输入需要进行构造真值表的合式公式 ：       |" << endl;
        cout << "|             字母为小写字母                        |" << endl;
        cout << "|（析取:\\/，合取:/\\，条件:->，双条件:<->，否定:~）|：" << endl;
        cout << "|---------------------------------------------------|" << endl;
        cout << "|  当前程序等待响应。。。。。                       |" << endl;
        cout << "|  检测到输入模式错误                               |" << endl;
        cout << "|  停止响应，请用户检查所需模式是否实装             |" << endl;
        cout << "|  正在启动TT2协议。。。。。                        |" << endl;
        cout << "|  感谢您的使用,下次再会                            |" << endl;
        cout << "-----------------------------------------------------" << endl;

        return 0;
    }
}

