#include <iostream>
#include <string>

using namespace std;
// string ���ڿ��� ������ ������ �����ִ� ���.
class ExtString : public std::string {
public:
    ExtString() {}

    ExtString(char* pstr)
        : std::string(pstr) {}

    ExtString(std::string str)
        : std::string(str) {}

    int GetLength() {
        const char* pstr = c_str();   // c_str() : ���ڿ��� ����� ���ι�° �޸��ּҰ��� �����ϴ� string Ŭ������ ����Լ�
                                      // const�� ���� ������ ���ι�° �ּҰ��� �ٲ�������, ������� ����� �ǹ̷� cosnt�� ������

        int count = 0;
        for (count = 0; pstr[count] != 0; count++);

        return count;
    }
};


int main() {
    using namespace std;

    ExtString str((char*)"monster");

    cout << "str ���ڿ� ����: " << str.GetLength() << endl;

    cout << "str = " << str << endl;


    string str2 = "I am a boy!!";
    ExtString extStr(str2);

    cout << "extStr ���ڿ� ����: " << extStr.GetLength() << endl;
    cout << extStr << endl;

    ExtString str3 = str + extStr;

    cout << "str3 ���ڿ� ����: " << str3.GetLength() << endl;
    cout << str3 << endl;


    return 0;
}