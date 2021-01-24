#ifndef STREAM_H_INCLUDED
#define STREAM_H_INCLUDED

#include <iostream>
#include <cstring>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "UI.h"
#include <thread>
#include <chrono>
using namespace std;
class Stream:public UI{


protected:

        string get_file_name(){
        printS("Please Enter File name with path without '.txt'", '|');
        string s;
        cin >> s;
        string temp = s+".txt";
        return temp;
    }
    string read_OriginalMsg()
    {
        string name = get_file_name();
        fstream file(name.c_str());
        if(file.is_open()){
        string txt;
        getline(file,txt);
        string T(txt);
        file.close();
        return T;
    }
    else
    {
    	throw "File cannot opened";
	}
    }

    void clear_file(string name)
    {
        string temp = name+".txt";
        fstream file;
        file.open(temp.c_str());
        file.clear();
        file.close();
    }
    void save_to_file(string enc,string msg)
    {
        ofstream file;
        file.open("enc.txt");
        file <<enc <<endl;
        file.close();
        printS("Saved", '|');
        ofstream db;
        db.open("database.txt",fstream::app);
        db << enc << endl << msg << endl;
        db.close();
    }

    void save_to_file(string enc)
    {
        ofstream file;
        file.open("enc.txt");
        file <<enc <<endl;
        file.close();
        printS("Saved", '|');
        ofstream db;
        db.open("database.txt",fstream::app);
        db << enc << endl;
        db.close();
    }


    void open_db()
    {
        string line;
        fstream file("database.txt");
        while(getline(file,line))
        {
            cout << line << endl;
        }
        cout << "End of Database" <<  endl;
    }

    string read_OriginalMsg(string name_file)
    {
        fstream file(name_file.c_str());
        if(file.is_open()){
        file.seekg (0, file.end);
        int chars = file.tellg();
        file.seekg (0, file.beg);
        char* words = new char[chars];
        file.read(words,chars);
        string temp(words);
        file.close();
        delete[] words;
        return temp;
    }
    else
    {
    	throw "Cannot Open file "+name_file;
	}

    }
    string search_in_db(string name_file,string search_txt)
    {
        fstream file (name_file.c_str());
        string temp;
        while(getline(file,temp))
        {
            if(temp.compare(search_txt) == 0){
                getline(file,temp);
               return temp;
            }
        }
        file.close();

    }
public:
    char get_num_of_cmd(string print)
    {
        print_slow(print,50);
        cout <<":";
        char cmd;
        cin >> cmd;
        return cmd;
    }

};

#endif // STREAM_H_INCLUDED
