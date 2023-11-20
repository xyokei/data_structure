//
// Created by AutumnSigni on 2023/11/12.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    // 写文件操作
    ofstream outputFile("example.txt");

    if (outputFile.is_open()) {
        outputFile << "Hello, this is a line of text.\n";
        outputFile << "This is another line.\n";
        outputFile.close();
        cout << "File 'example.txt' has been written.\n";
    } else {
        cerr << "Unable to open the file for writing.\n";
        return 1; // 返回错误码
    }

    // 读文件操作
    ifstream inputFile("example.txt");

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << "Read line: " << line << endl;
        }
        inputFile.close();
    } else {
        cerr << "Unable to open the file for reading.\n";
        return 1; // 返回错误码
    }

    return 0;
}
