#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <thread>
#include <chrono>
using namespace std;

class UI{
private:

	void write_spaces(int spaces)
	{
		for (int i = 1; i < spaces; i++)
			cout << " ";
	}
public:
    void print_slow(const string& text, unsigned int millis)
    {
        for(int i=0;i<text.length();i++)
        {
            cout << text[i] << flush;
            std::this_thread::sleep_for(chrono::milliseconds(millis));
        }
    }
	void set_window_info(char title[])
	{
		system("mode 100,70");
		system("color 4F");
		SetConsoleTitle(title);
	}
	void draw_width(int width, char sympol)
	{
		if (width < 100)
		{
			int temp = (100 - width) / 2;
			for (int k = 1; k < temp; k++)
				cout << " ";
			for (int i = 0; i < width; i++)
				cout << sympol;
			cout << endl;
		}
		else {
			for (int i = 0; i < width; i++)
				cout << sympol;
			cout << endl;
		}

	}

	void write_header(string text[], int spaces)
	{
		write_spaces(spaces*1.7);
		cout << text[0] << endl << endl;
		write_spaces(spaces*1.58);
		cout << text[1] << endl << endl;
		write_spaces(spaces - 3);
		cout << text[2] << endl << endl;
		draw_width(100, '-');
	}

	void type_center(string txt)
	{
		if (txt.length() < 100)
		{
			int temp = (100 - txt.length()) / 2;
			for (int k = 1; k < temp; k++)
				cout << " ";
			cout << txt;
			cout << endl;
		}
		else {

			cout << txt;
			cout << endl;
		}
	}

	void draw_menu(string body[], int items)
	{
		int num = 1;
		for (int i = 0; i < items * 2; i += 2)
		{
			cout << "\t" << num << ". " << body[i] << endl << endl;
			cout << "\t\t(" << body[i + 1] << ")" << endl << endl << endl;
			num++;
		}
	}

	 void printS(string text, char sympol)
	{
		int len = text.length();
		draw_width(len + 2, sympol);
		type_center(sympol + text + sympol);
		draw_width(len + 2, sympol);
	}

	string write_password()
	{

		char key;
		string password;

		key = getch();
		while (key != 13) {

			if ((key >= 65 && key <= 90) || (key >= 97 && key <= 122) || (key >= 48 && key <= 57))
			{
				cout << '*';
				password += key;

			}
			else if (key == 8 && password.length() > 0)
			{
				password.resize(password.size() - 1);
				cout << "\b \b";
			}

			key = getch();

		}
		return password;
	}

	void set_disp_pass()
	{
	    system("mode 50,10");
		system("color F0");
		SetConsoleTitle("LOGIN SYSTEM");
	}

};



#endif // UI_H_INCLUDED
