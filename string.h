#include <iostream>
using namespace std;
class String
{

private:
	void SSize(int n);
public:
	int size;
	char* data;
	String();
	String(const char* s);
	String(const char c);
	String(const String& s);
	String(const String &s, int start, int end);
	~String();
	int length() const;
	char& operator[] (int number)const;
	String operator+(const String& s)const;
	String operator+(const char c)const;
	bool operator==(const String& s) const;
	String& operator=(const String& s);
	String& operator=(const char c);
	bool operator<(const String& s)const;
	bool operator>(const String& s)const;
	friend ostream& operator<< (ostream& out, const String& s);
	friend istream& operator>> (istream& in, String& s);
	void copy(const String& s, int start, int end);
	int p(const char c);
	int pclass(const char c);
	int pos(const char* s);
	int pcount(const char c);
	String* part(char c);
	String repeater(String &s, int n);
};
