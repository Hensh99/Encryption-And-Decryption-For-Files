#include <iostream>
#include <string.h>
#include "UI.h"
#include "Stream.h"
#include "Ops.h"
#include <thread>
#include <chrono>
using namespace std;

int main()
{
    Stream st;
    UI window;

	string n, p;
    string uname("admin"),password("admin");
    window.set_disp_pass();
    cout <<"\n\tWelcome to CRYPTO's LOGIN SYSTEM\n"<<endl;
	do
	{
		if ((!n.empty() || !p.empty()) && (p != password || n != uname))
			cout << "\nWrong User Info ";
		cout << "Enter User Name" << endl;
		cin >> n;
		cout << "Enter Password" << endl;
		p = window.write_password();
	} while (n.compare(uname) != 0 || p.compare(password) != 0);

	window.set_window_info("CRYPTO v2.1\0");
	window.draw_width(100, '-');
	string header[] = { "CRYPTO v2.1","Welcome to CRYPTO","Please select encryption method by select number of it" };
	window.write_header(header, 25);
	window.type_center("Select encryption method then, file name\n");
	window.draw_width(80, '=');
	window.type_center("========== Type name of file which include text then press Enter ==========");
	window.draw_width(80, '=');
	window.draw_width(100, '-');
	string items[] = {
		"MD5 Cipher Encryption",
		"One-way encryption algorithm, producing a 128-bit hash value.",
		"Caesar Cipher Encryption",
		"one of the simplest and most widely known encryption techniques.",
		"Hill Cipher Encryption",
		"Good Method, It needs a key word with original text",
		"Vigenere Cipher Encryption ",
		"Very Good way, Depends on the principle of using a key length\n\t\t corresponding to the length of the original text",
		"Database",
		"Show Database of Encrypted TEXTS",
		"Keys",
		"Generate Keys for strong Encryption",
		"EXIT",
		"Exit program",
		"TEAMWORK",
		"Asem Muhammad - Hatem Mohamed - Mohamed Hany - Sohila Ibrahim - Omar Khaled",
		"Search",
		"Search in Database about Encrypted text"
	};
	window.draw_menu(items, 9);
	window.type_center("The Encrypted text will writed down into 'enc.txt' in same path");
	window.draw_width(100, '-');
    char c;
    do{
    char cmd = st.get_num_of_cmd("Please Enter Command");
    if(!(cmd >= 49 && cmd <= 57))
        cout << "Wrong Entry! "<< endl;
    else
    {
        Opers ops((int)cmd-48);
        ops.exec();

    }
    window.print_slow("More Operations? |Y to perform :: any key to exit|\n",50) ;
        c = getch();
    }while (c=='Y' || c=='y');
    return 0;
}
