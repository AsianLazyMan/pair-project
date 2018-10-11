#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include<map>
#include <fstream>
#include <algorithm>
#include<sstream>
using namespace std;
int w = 0;
int n = 0;
map<string, int> ma;
map<string, int>mas;
map<string, int>maa;
int min(int a, int b) {
	if (a >= b) return b;
	else return a;
}
void lower(string& str) {//大写转化成小写
	for (int j = 0; j < str.size(); j++)
	{
		if (str[j] <= 'Z'&&str[j] >= 'A') {
			str[j] = str[j] + 32;
		}
	}
}
int Judge(string Word) {//判断是不是四个英文字母开头 后面跟着字母数字符号

	if (Word.empty()) return 0;
	if (Word.size() < 4) return 0;
	if (Word[0] >= 'a'&&Word[0] < 'z'&&Word[1] >= 'a'&&Word[1] <= 'z'&&Word[2] >= 'a'&&Word[2] <= 'z'&&Word[3] >= 'a'&&Word[3] <= 'z')
		return 1;
	else
		return 0;
}
int getCharNum(string filename)
{
	ifstream file(filename);
	string temp;
	int charNumEachLine = 0;
	int charNum = 0;
	while (getline(file, temp)) {
		bool space = false;
		for (int i = 0; i < (int)temp.size(); i++) {
			if (temp[i] > 32)
			{
				space = true;
				break;
			}
		}
		int x = 0;
		if(temp.size()>6)
		if (temp[0] == 'T'&&temp[1] == 'i'&&temp[2] == 't'&&temp[3] == 'l'&&temp[4] == 'e'&&temp[5] == ':') { x = 7; }
		if(temp.size()>4)
		if (temp[0] == 'A'&&temp[1] == 'b'&&temp[2] == 's'&&temp[3] == 't') { x = 10; }
		if (temp.size() == 1) space = false;
		if (space == true) {
			if (x=10)
			{
				charNumEachLine = temp.size() - 10;
				charNum = charNum + charNumEachLine;
			}
			if (x==7)
			{
				charNumEachLine = temp.size() - 6;
				charNum = charNum + charNumEachLine;
			}
			if (x==0)
			{
				charNumEachLine = temp.size();
				charNum = charNum + charNumEachLine;
			}
		}
	}
	file.close();
	return charNum;
}
int getLineNum(string filename)
{
	ifstream file(filename);
	string temp;
	int lineNum = 0;
	while (getline(file, temp)) {
		bool space = false;
		for (int i = 0; i < (int)temp.size(); i++) {
			if (temp[i] > 32)
			{
				space = true;
				break;
			}
		}
		if (space == true && (('A'<=temp[0]&&temp[0]<='Z')|| ('a' <= temp[0] && temp[0] <= 'z'))) {
			lineNum++;
		}
	}
	file.close();
	return lineNum;
}
int mm = 0;
void countWord(string filename) {
	ifstream file(filename);
	string temp;
	string word;
	string words;
	char c;
	string f;
	//while ((c = file.get()) != EOF) {
	//	temp.append(1, c);
	//}
	while (getline(file, temp))
	{
		if (temp.size() == 0) continue;
		int x = 0;
		int m = 0;
		int pos = 0;
		if (temp.size() >6)
		if (temp[0] == 'T'&&temp[1] == 'i'&&temp[2] == 't'&&temp[3] == 'l'&&temp[4] == 'e'&&temp[5] == ':') { pos = 7; x = 7; }
		if (temp.size() > 9)
		if (temp[0] == 'A'&&temp[1] == 'b'&&temp[2] == 's'&&temp[3] == 't'&&temp[8] == ':') { pos = 10; x = 10; }
		lower(temp);
		for (int y = x; y < temp.size(); ) {
			if (temp[y] < 48 || ((57 < temp[y]) && (temp[y] < 97)) || temp[y]>122)
			{
				if (y > temp.size())break;
				y++;
				continue;
			}
			else {//发现一个单词
				int fir = y;
				while ((temp[y] >= 'a'&&temp[y] <= 'z') || (temp[y] >= '0'&&temp[y] <= '9')) {
					word.append(temp, y, 1);
					y++;
					if (y > temp.size())break;
				}
				if (Judge(word)) {
					pos = fir;
					string tempword;
					int flag = 0;
					int flag1 = 0;
					int flag2 = 0;
					int cc = 0;
					m = 1;
					maa[word]++;
					if (w == 0)	ma[word] ++;
					else if (w == 1)
					{
						if (x == 7) {
							for (int u = 0; u < 10; u++) {
								ma[word] ++;
							}
						}
						else if (x == 10||x==0)
						{
							ma[word] ++;
						}
					}
					while (m != mm)
					{
						if (m != mm && y >= temp.size()) break;
						for (int k = y; k < temp.size(); ) {
							if (temp[k] < 48 || ((57 < temp[k]) && (temp[k] < 97)) || temp[k]>122)
							{

								k++; if (k >= temp.size()) { flag1 = 1; break; }
								continue;
							}
							else {//发现一个单词
								while ((temp[k] >= 'a'&&temp[k] <= 'z') || (temp[k] >= '0'&&temp[k] <= '9')) {
									tempword.append(temp, k, 1);
									k++;
									if (k > temp.size())break;
								}
								if (Judge(tempword)) {
									m++;
									if (m != mm && k >= temp.size()) {
										flag = 1;
										break;
									}
									if (m == mm) {
										words.append(temp, pos, k - pos);
										//pos = y + 1;
										if (w == 0) mas[words]++;
										if (w == 1) {
											if (x == 7)
												for (int u = 0; u < 10; u++)
													mas[words]++;
											if (x == 10)
												mas[words]++;
										}
										break;
									}
								}
								else
								{
									pos = k + 1;
									tempword.clear();
									flag2 = 1;
									break;
								}
								tempword.clear();
							}
						}
						if (flag == 1) break;
						if (flag1 == 1) break;
						if (flag2 == 1) break;
					}
					words.clear();
				}
				word.clear();
				words.clear();
			}
		}
	}
	file.close();
}
typedef pair<string, int> PAIR;
bool cmp(PAIR a, PAIR b)
{
	if (a.second > b.second)             return true;
	if (a.second < b.second)             return false;
	if (a.first == b.first)    return true;
	return false;
}
int main(int argc,char **argv)
{
	//string xx[11];
	string res;
	//for (int y = 0; y < 10; y++) cin >> xx[y];
	//if (argc == 1)	printf("It is short of filename!\n");
	//else if (argc > 15)	printf("Too many parametes!\n");
	//else {
	//for (int y = 0; y < 10; y++) cout << y << xx[y] << endl;
	for (int x = 0; x <10; x++) {
		if (strcmp(argv[x], "-w")==0)  {
			string s = argv[x + 1];
			stringstream ss;
			ss << s;
			ss >> w;
			//cout << w;
		}
		if (strcmp(argv[x], "-n") == 0) {
			string s = argv[x + 1];
			stringstream ss;
			ss << s;
			ss >> n;
			//cout << n;
		}
		if (strcmp(argv[x], "-m") == 0) {
			string s = argv[x + 1];
			stringstream ss;
			ss << s;
			ss >> mm;
			//cout << mm;
		}
	}
	res = argv[argc - 1];
	countWord(argv[2]);
	int num1 = getCharNum(argv[2]);
	int num2 = 0;
	int num3 = getLineNum(argv[2]);
	vector<PAIR> name_times_vec(ma.begin(), ma.end());
	vector<PAIR> words_vec(mas.begin(), mas.end());
	vector<PAIR> words(maa.begin(), maa.end());
	for (int j = 0; j < words.size(); j++) {
		num2 = num2 + words[j].second;
	}
	sort(name_times_vec.begin(), name_times_vec.end(), cmp);
	sort(words_vec.begin(), words_vec.end(), cmp);
	if (mm != 0) {

	}
	ofstream ofile(res);
	ofile << "characters:" << num1 << endl;
	ofile << "words:" << num2 << endl;
	ofile << "lines:" << num3 << endl;
	//还改好输出词组
	if (mm == 0) {
		if (n == 0)
			for (int i = 0; i < min(10, name_times_vec.size()); i++)
			{
				ofile << "<" << name_times_vec[i].first << ">: " << name_times_vec[i].second << endl;
			}
		else
			for (int i = 0; i < min(n, name_times_vec.size()); i++)
			{
				ofile << "<" << name_times_vec[i].first << ">: " << name_times_vec[i].second << endl;
			}
	}
	else
	{
		if (n == 0)
			for (int i = 0; i < min(10, words_vec.size()); i++)
			{
				ofile << "<" << words_vec[i].first << ">: " << words_vec[i].second << endl;
			}
		else
			for (int i = 0; i < min(n, words_vec.size()); i++)
			{
				ofile << "<" << words_vec[i].first << ">: " << words_vec[i].second << endl;
			}
	}

	//}
}


