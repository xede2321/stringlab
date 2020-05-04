#include "String.h"
#include <iostream>
using namespace std;
String::String(){
	data = new char[1];
	data[0] = 0;
	size = 1;
}
String::String(const char* s){
	data = NULL;
	size = strlen(s) + 1;
	data = new char[size + 1];	
	for (int i = 0; i < size; i++)	{
		data[i] = s[i];
	}
	data[size] = 0;
}
String::String(const char c){
	if (c != 0)	{
		size = 2;
		data = new char[2];
		data[0] = c;
		data[1] = 0;
	}
	else{
		size = 1;
		data = new char[2];
		data[0] = 0;
	}
}

String::String(const String& s){
	data = NULL;
	size = s.length();
	data = new char[size];
	for (int i = 0; i < size; i++){
		data[i] = s[i];
	}
}
String::String(const String& s, int start, int end){
	data = NULL;
	size = end - start + 2;
	data = new char[size];
	for (int i = 0; i < size; i++){
		data[i] = s[start + i];
	}
	data[size - 1] = 0;
}
String::~String(){
	delete[] data; 
}

int String::length() const{
	return size;
}
String String::operator+(const String& s) const{
	String res(*this);
	res.SSize(size + s.length() - 1);
	for (int i = size - 1; i < res.length(); i++){
		res[i] = s[i - size + 1];
	}
	return res;
}
String String::operator+(const char c)const{
	String res(*this);
	if (res.size != 1){
		res.SSize(size + 1);
	}
	else{
		res.SSize(size + 2);
	}
	int ressize = res.length();
	res[ressize - 2] = c;
	return res;
}
String& String::operator=(const String& s){
	if (*this == s){
		return *this;
	}
	if (data != NULL){
		delete[] data;
	}
	size = s.length();
	data = NULL;
	data = new char[size]; 
	for (int i = 0; i < size; i++){
		data[i] = s[i];
	}
	return *this;
}
bool String::operator==(const String& s) const{
	if (size == s.length()){
		int i = 0;
		while (data[i] == s[i]){	
			i++;
		}		
	}
	return 0;
}

String& String::operator=(const char c){
	String temp(c);
	*this = temp;
	return *this;
}

bool String::operator<(const String& s) const{
	for (int i = 0; i < (size < s.length() ? size : s.length()); i++){
		if (data[i] < s[i]) return true;
		else if (data[i] > s[i]) return false;
	}
	return false;
}

bool String::operator>(const String& s) const{
	for (int i = 0; i < (size < s.length() ? size : s.length()); i++){
		if (data[i] > s[i]) return true;
		else if (data[i] < s[i]) return false;
	}
	return false;
}
char& String::operator[](int number) const{
	return data[number];
}
void String::copy(const String& s, int start, int end){
	String copy(s, start, end);
	*this = copy;
}
int String::p(const char c) 
{
	for (int i = 0; i < size; i++)
		if (this->data[i] == c)
			return i;
	return 0;
}
int String::pclass(const char c)
{
	int last = 0;
	for (int i = 0; i < size; i++)
		if (data[i] == c)
			last = i;
	return last;
}
int String::pos(const char* s) 
{
	int sizechar = strlen(s);
	int count = 0;
	int i;
	for (i = sizechar; i < size; i++)
	{
		if (data[i] == s[i])
			count++;
		else
			count = 0;
		if (count == sizechar)
			break;
	}
	if (count == sizechar)
		return i - count;
	return 0;
}
int String::pcount(const char c)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (data[i] == c)
			count++;
	return count;
}
String* String::part(char c) 
{
	int count = this->pcount(c);
	String* res = NULL;
	int arraysize;
	if (size - 2 != this->pclass(c) || this->p(c) != 0)
	{
		arraysize = count + 1;
		res = new String[arraysize];
	}
	else
	{
		arraysize = count;
		res = new String[arraysize];
	}
	res[0] = *this;
	for (int i = 1; i < arraysize; i++)
	{
		int start = res[i - 1].p(c);
		int end = res[i - 1].length() - 1;
		String copy(res[i - 1], start + 1, end);
		res[i] = copy;
		res[i - 1].SSize(start + 1);
	}
	return res;
}
String String::repeater(String &s, int n)
{
	if (s.length() == 0)
		throw "Length = 0";
	String res(s);
	for (int i = 0; i < n - 1; i++)
	{
		res = res + s;
	}
	return res;
}
void String::SSize(int n){
	if (size != n){	
		int copysize = size;
		char* copy = data; 
		size = n;
		data = NULL;
		data = new char[size];		
		if (n >= copysize){ 	
			for (int i = 0; i < copysize; i++)
				data[i] = copy[i];
			data[n - 1] = 0;
		}
		else{	
			for (int i = 0; i < n; i++)
				data[i] = copy[i];
			data[n - 1] = 0;
		}
		delete[] copy;
	}
}
ostream& operator<<(ostream& out, const String& s){
	out << s.data << endl;
	return out;
}
istream& operator>>(istream& in, String& s){
	char get[256];
	in.getline(get, 256);
	String right(get);
	s = right;
	return in;
}
