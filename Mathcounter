//合式公式解释器前置代码，使用了一种比较取巧的办法进行合式公式的演算
//并不是传统的根据栈和输入检测进行求解，可以通过递归和替换来达到类似的效果？
//设想内容为编程得出给定的合式公式的不同阶段的化简公式
//在表达式中寻找括号对，即 ()，表示子表达式。
//使用 unordered_map<string, char> hs 来记录已处理的子表达式映射到一个大写字母。
//当找到完整的子表达式时，将其替换成一个新的大写字母
// 输入的字母需要是小写字母
//原子命题的符号改成大写字母，字母表顺序
//最多支持ABCDEFG七个元的替换
//~非，\/表示析取，/\表示合取，->表示蕴含，,<->表示等价,不是合式公式输出-1；
//(~((p/\q)->(p/\(p/\q))))

#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<char, char> hc;
unordered_map<string, char> hs;

string s, p = "ABCDEFGH";
int index;

void replace(int l, char c, int r) {
	s = s.substr(0, l) + c + s.substr(r + 1);
}

void end() {
	cout << s << endl;
	hc.clear();
	hs.clear();
	index = 0;
}

int Mathcounterm() {
	cout << "-----------------------------------------------------" << endl;
	cout << "|            zaradee的离散辅助编程代码              |" << endl;
	cout << "|---------------------------------------------------|" << endl;
	cout << "|       请输入需要进行相应化简操作的合式公式        |" << endl;
	cout << "|             字母为小写字母                        |" << endl;
	cout << "|（析取:\\/，合取:/\\，条件:->，双条件:<->，否定:~）|：" << endl;
	cout << "|---------------------------------------------------|" << endl;
	cout << "|  当前程序等待响应。。。。。                       |" << endl;
	cout << "|  正在预测对应输入，以及构造合式公式               |" << endl;
	cout << "|  正在分析，请稍作等待                             |" << endl;
	cout << "-----------------------------------------------------" << endl;

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		auto c = s[i];
		if (isalpha(c)) {
			if (!hc[c]) {
				hc[c] = p[index++];
			}
			replace(i, hc[c], i);
		}
	}
	end();
	while (s.size() > 1) {
		for (int i = 0; i < s.size(); i++) {
			auto c = s[i];
			if (c == '(') {
				bool flag = false;
				int j = i + 1, k;
				while (s[j] != ')') {
					if (isalpha(s[j])) {
						flag = true;
						k = j;
					}
					else if (s[j] == '(') {
						if (flag) {
							if (!hc[s[k]]) {
								hc[s[k]] = p[index++];
							}
							replace(k, hc[s[k]], k);
						}
						break;
					}
					j++;
				}
				if (s[j] == ')') {
					string r = s.substr(i, j - i + 1);
					if (!hs[r]) {
						hs[r] = p[index++];
					}
					replace(i, hs[r], j);

					j = i + 1;
					while (j < s.size() && s[j] != '(') {
						if (isalpha(s[j])) {
							if (!hc[s[j]]) {
								hc[s[j]] = p[index++];
							}
							replace(j, hc[s[j]], j);
						}
						j++;
					}
				}
			}
		}
		end();
	}
	return 0;
}
