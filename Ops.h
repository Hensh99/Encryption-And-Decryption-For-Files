#ifndef OPS_H_INCLUDED
#define OPS_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <cstring>
#include "md5.h"
#include "md5.cpp"
#include <thread>
#include <chrono>
using namespace std;
/*
* start Caesar class
*/
class Caesar
{
private:
    int key;
public:
    Caesar()
    {
            cout << "Enter Your Shifting Key : ";
            int temp;
            try{
            cin >>temp;
            }
            catch(int e)
            {
                exit(0);
            }
            this ->key = temp;


    }
     string encrypt(string mssg)
    {
            string e_message;
            int int_casting;
            string msg = mssg;

            for (int i = 0 ; i < msg.length() ; i++)
            {
                if (isupper(msg[i]))
                {
                    int_casting = ((int) (msg[i]+key-65)%26 +65);
                    e_message += ((char) int_casting);
                }

                else if(islower(msg[i]))
                {
                    int_casting = ((int)(msg[i]+key-97)%26 +97);
                    e_message +=((char)int_casting);
                }

                else if (isdigit(msg[i]))
                    e_message +=msg[i];

                else if ((int)msg[i] == 32)
      				e_message += (char)32;

    			else
					e_message+=msg[i];

            }
            return e_message;
    }

     string decrypt(string mssg)
    {
        string e_msg;
        for(int i=0;i<mssg.length();i++)
        {
            if(isupper(mssg[i]))
            {
                int temp = (int)((mssg[i]-key+65)%26 +65);
                e_msg += (char)temp;
            }

            else if(islower(mssg[i]))
            {
                int temp = (int)((mssg[i]-key-97)+26);
                e_msg += (char)(temp%26)+97;
            }

            else if(isdigit(mssg[i]))
                e_msg += (char)mssg[i];

            else if ((int)mssg[i] == 32)
      			e_msg += (char)32;

    		else
				e_msg+=mssg[i];
        }

    return e_msg;
    }
};
/*
* end Caesar class
*/






/*
* start Vigenere class
*/

class Vigenere
{
private:
    string key_string;
public:
    Vigenere(string temp)
    {
        for (int i=0;i<temp.length();i++)
        {
            if(isalpha(temp[i]))
                key_string+=temp[i];
        }

    }

    //Encryption Function
    string encrypt(string mssg)
    {
string temp;
  string message = mssg;
  int casting ;
  string en_message;
  string messaget;
  int j =0;

  while (message.length() > key_string.length())
  	  {
        if (isalpha(key_string[j]))
        key_string += key_string[j];
        j++;
  	  }

  	  for (int w = 0 ; w < message.length();w++)
	  {
  		if (message[w] == (char)32)
  	    key_string.insert(w," ");
      }

  	  if (message.length() != key_string.length())
  	   key_string.erase(message.length(),key_string.length());

      cout<<"your New Key Is : "<<key_string<<endl;


  	for (int i = 0 ; i < message.length();i++)
  	{

    if  ( islower(message[i]) && islower(key_string[i]))
    {
    casting = ((((int)key_string[i]-97) +((int)message[i]-97))%26)+97;
    en_message += (char) casting;
    }

    else if (islower(message[i]) && isupper(key_string[i]))
    {
      casting = ((((int)key_string[i]-97) +((int)message[i]-65))%26)+97;
      en_message += (char) casting;
    }

     else if (isupper(message[i]) && islower(key_string[i]))
    {
      casting = ((((int)key_string[i]-65) +((int)message[i]-97))%26)+65;
      en_message += (char) casting;
    }

     else if (isupper(message[i]) && isupper(key_string[i]))
    {
      casting = ((((int)key_string[i]-65) +((int)message[i]-65))%26)+65;
      en_message += (char) casting;
    }
}


  	for (int t = 0 ; t < en_message.length(); t++)
  	{
      if (message[t] == (char) 32 )
  	  en_message.insert(t," ");
  	}
        temp = en_message;
      return temp;
    }
    //Decryption Function
     string decrypt(string mssg)
    {
        string message = mssg,temp;
  int casting ;
  string en_message;
  string messaget;
  int j =0;

  while (message.length() > key_string.length())
  	  {
        if (isalpha(key_string[j]))
        key_string += key_string[j];
        j++;
  	  }

  	  for (int w = 0 ; w < message.length();w++)
	  {
  		if (message[w] == (char)32)
  	    key_string.insert(w," ");
      }

  	  if (message.length() != key_string.length())
  	   key_string.erase(message.length(),key_string.length());

      cout<<"your New Key Is : "<<key_string<<endl;


  	for (int i = 0 ; i < message.length();i++)
  	{

    if  ( islower(message[i]) && islower(key_string[i]))
    {
    casting = (((message[i]-97) - (key_string[i]-97)+26)%26)+97;
    en_message += (char) casting;
    }

    else if (islower(message[i]) && isupper(key_string[i]))
    {
      casting = (((message[i]-97) - (key_string[i]-65)+26)%26)+97;
      en_message += (char) casting;
    }
     else if (isupper(message[i]) && islower(key_string[i]))
    {
      casting = (((message[i]-65) - (key_string[i]-97)+26)%26)+97;
      en_message += (char) casting;
    }
    else if (isupper(message[i]) && isupper(key_string[i]))
    {
      casting = (((message[i]-65) - (key_string[i]-65)+26)%26)+97;
      en_message += (char) casting;
    }
}

  	for (int t = 0 ; t < en_message.length(); t++)
  	{
      if (message[t] == (char) 32 )
  	  en_message.insert(t," ");
  	}

  	for (int r =0  ; r < message.length() ; r ++)
	  {
	  	if (ispunct(message[r] || isdigit(message[r])))
		  {
		  	en_message = "Erorr";
		  }
	  }
	  temp = en_message;
        return temp;
    }
};
/*
* end Vigenere class
*/





/*
* start Hill class
*/
class Hill
{
	private:
		string key;
		

	public:
		Hill(string k)
		{
			this -> key = k;
		}
	/*
private:
    int key1[2][2];
    int key2[3][3];
public:
    Hill(int selector)
    {
        if(selector == 0){
        for(int g=0;g<2;g++){
                for(int h=0;h<2;h++){
                    cout<<"key matrix"<<"["<<g<<"]"<<"["<<h<<"]";
                    cin>>this->key1[g][h];

                    this->key1[g][h]+=97;
                }
            }
        }
        else if(selector == 1){
        for(int m=0;m<3;m++){
                for(int n=0;n<3;n++){
                    cout<<"key matrix"<<"["<<m<<"]"<<"["<<n<<"]";
                    cin>>this->key2[m][n];

                    this->key2[m][n]+=97;
                }
            }
        }
    }
     string encrypt(string mssg)
    {
    string message ;
    string result;

    int message1,message2,message3;
    int let1,let2,let3,let4,let5;
    int asci_1,asci_2,asci_3;

    message = mssg;

    key1[0][0]= ((int)(key1[0][0] -97)%26);
    key1[0][1]= ((int)(key1[0][1] -97)%26);
    key1[1][0] =((int)(key1[1][0] -97)%26);
    key1[1][1] =((int)(key1[1][1] -97)%26);

for (int i=0,j=1; i < message.length(),j<message.length(); i+=2,j+=2)
    {
        message1 = ((int)message[i] - 97)%26 ;
        message2 = ((int)message[j] - 97)%26 ;


        let1 = (key1[0][0]*message1)+(key1[0][1]*message2);
        let2 = (key1[1][0]*message1)+(key1[1][1]*message2);

        asci_1 = ((let1) %26)+97;
        asci_2 =((let2)%26)+97;

        result += (char)asci_1;
        result += (char)asci_2;
    }

    key2[0][0]= ((int)(key2[0][0] -97)%26);
    key2[0][1]= ((int)(key2[0][1] -97)%26);
    key2[0][2]= ((int)(key2[0][2] -97)%26);
    key2[1][0] =((int)(key2[1][0] -97)%26);
    key2[1][1]= ((int)(key2[1][1] -97)%26);
    key2[1][2]= ((int)(key2[1][2] -97)%26);
    key2[2][0] =((int)(key2[2][0] -97)%26);
    key2[2][1]= ((int)(key2[2][1] -97)%26);
    key2[2][2]= ((int)(key2[2][2] -97)%26);

for (int p=0,o=1,r=2; p < message.length(),o<message.length(),r<message.length(); p+=3,o+=3,r+=3)
    {
        message1 = ((int)message[p] - 97)%26 ;
        message2 = ((int)message[o] - 97)%26 ;
        message3 = ((int)message[r] - 97)%26 ;


        let3 = (key2[0][0]*message1)+(key2[0][1]*message2)+(key2[0][2]*message3);
        let4 = (key2[1][0]*message1)+(key2[1][1]*message2)+(key2[1][2]*message3);
        let5 = (key2[2][0]*message1)+(key2[2][1]*message2)+(key2[2][2]*message3);

        asci_1 = ((let3) %26)+97;
        asci_2 = ((let4) %26)+97;
        asci_3 = ((let5) %26)+97;


        result += (char)asci_1;
        result += (char)asci_2;
        result += (char)asci_3;
}

return result;

    }

*/

string encrypt(string mssg)
{
	string message = mssg,  en_message0,en_message ;
  int c1r1 ,c1r2;
  

for (int r = 0 ; r < key.length() ; r ++)
  {
  	key[r] = tolower(key[r]);
  }
  if(message.length() % 2 != 0)
    {
        message+='Z';
    }
  int n1 = (int) key[0] , n2 = (int) key[1] , n3 = (int) key[2] , n4 = (int) key[3];
  
  en_message0 = message;
  

  for (int t = 0 ; t < message.length(); t++)
  	{
  		message[t] =tolower(message[t]);
  	
  	}
  for(int i = 0 , j = 1 ; i < message.length() ,j < message.length() ; i+=2 ,j+=2){
      c1r1 = (((int) (n1-97) * (int) (message[i]-97)) + ((int) (n2-97)* (int) (message[j]-97)))%26;
      en_message += (char) c1r1+97;
      c1r2 = (((int) (n3-97) * (int) (message[i]-97)) + ((int) (n4-97)* (int) (message[j]-97)))%26;
      en_message += (char) c1r2+97;
  }

  for (int q = 0 ; q < message.length();q++)
  {
    if(isupper(en_message0[q]))
    {
      en_message[q] = ((char)((int)en_message[q]-32));
    }
  }
  int predet;
  predet = ((n1-97) * (n4-97)) - ((n2 - 97) * (n3-97));
  

  en_message.resize(en_message.size()-1);
  return en_message;
}

string decrypt(string mssg)
{
	
	string message = mssg;
int len =  message.length();
  string en_messaget = message;

	for (int r = 0 ; r < key.length() ; r ++)
  	{
  		key[r] = tolower(key[r]);
  	}
  	

    
  	for (int t = 0 ; t < message.length(); t++)
  	{
  		message[t] =tolower(message[t]);

  	}
  	int n1 = (int) key[0] , n2 = (int) key[1] , n3 = (int) key[2] , n4 = (int)key[3];

  	int predet = ((n1-97) * (n4-97)) - ((n2-97) *(n3-97));
  	int tmpt=-1;
    int letter_range=26, q;
    int det;
    int newdit;
    for (int n22 = 0 ; n22 < 20 ; n22++)
{
    if ( n22 > letter_range) {
        int temp = n22;
        n22 = letter_range;
        letter_range = temp;
    }

    for (int t = 1; t <=  n22; ++t) {
        if (letter_range % t == 0 && n22 % t ==0) {
            q = t;
        }
    }

    for (int toe = 0 ; toe <1000 ; toe++)
    {
      for (int v = 0 ; v < 1000; v ++)
      {
        if (n22*predet-1 == toe && 26 * v == toe&& n22 %2 != 0)
          tmpt = n22;
      }
    }
}
if (tmpt== -1)
{
  cout<<"your Matrix Key Cant Be Decoding ";
  return 0 ;
}
int a1 = n1-97   , a2 = n2-97   , a3 = n3-97   , a4 = n4-97;
int b1 = a4      , b2 = a2 *-1  , b3 = a3*-1   , b4 = a1;
int c1 = b1*tmpt , c2 = b2*tmpt , c3 = b3*tmpt , c4 = b4*tmpt;
int d1 = c1%26   , d2 = c2%26   , d3 = c3%26   , d4 = c4%26 ;

while (d1 < 0 )
  d1+=26;

while (d2<0)
  d2+=26;

while (d3<0)
  d3+=26;

while (d4<0)
  d4+=26;

  int c1r1,c1r2;
  string en_message;

	  for(int i = 0 , j = 1 ; i < message.length() ,j < message.length() ; i+=2 ,j+=2)
    {
      c1r1 = (( (d1) * (int) (message[i]-97)) + ((int) (d2)* (message[j]-97)))%26;
      en_message += (char) c1r1+97;
      c1r2 = (((d3) * (int) (message[i]-97)) + ((int) (d4)* (message[j]-97)))%26;
      en_message += (char) c1r2+97;
  }
  for (int t = 0 ; t < en_messaget.length() ; t++)
  {
    if (isupper(en_messaget[t]))
    {
      en_message[t] = (int)en_message[t]-32;
    }
  }
  	//en_message.resize(en_message.size()-1);
    return en_message;
}


};
/*
* end Hill class
*/



/*
*
*Start XOR Class
*/

class XOR
{
	private:
		string key;

	void decimalToHexaDecimal(int iInteger){
 			for(int m=1;m>=0;--m){
                int iHexDigit=((iInteger>>(4*m)))%16;
                if(iHexDigit<10){
                    cout<<iHexDigit;
                }
                else{
                    cout<<(char)('A'+(iHexDigit-10));
                }
            }

}
	public:

		XOR(string k)
	{

 		this -> key = k;


	}

	string encrypt(string mssg)
	{
		int let,lets,keys;
	    string hex,temp;
	    string message = mssg,encryption;
		for(int j=0,k=1;j<key.length(),k<key.length();j+=2,k+=2){
		    keys=(((int)key[j]-97)+((int)key[k]-97));
		    //cout<<keys<<endl;
		}
			cout<<"Your ENCRYPTION is:"<<endl;
		for(int i=0;i<message.length();i++){
		            let=((int)message[i]-97)+keys;
		            temp +=i;
		            decimalToHexaDecimal(let);
		}
		return temp;
	}
	string decrypt()
	{

	}
};



class Opers:Stream{
        public:
        int cmd;


        Opers(int i)
        {
            cmd = i;
        }

        void close()
        {
            cout << "Program Will Exit!"<<endl;
            exit(0);
        }

        string enc_md5(string& msg)
        {
            string m= md5(msg);
            return m;
        }

        string gen_keys(int key_len)
        {
            string key;
            key.resize(key_len);
            for(int i=0;i<key_len;i++)
            {
                srand(clock());
                int t = (rand()%25)+97;
                key += (char)(t);
                for(int k=0;k<6000;k++)
                    for(int j=0;j<1000;j++){}
            }
            return key;
        }

        void exec()
        {
            string msg;
            string e_msg;
            switch(cmd)
            {
                case 1:
                {
                    string name = get_file_name();
                    clear_file(name);
                    try{
                    msg =  read_OriginalMsg(name);
                }
                catch(string e)
                {
                	cout << e << endl;
                	break;
				}
                    e_msg = enc_md5(msg);
                    save_to_file(e_msg,msg);
                    break;
                }//end case 1


                case 2:
                {

                    int c;
                    cout << "1-Encrypt or 2-Decrypt?"<<endl;
                    cin >> c;
                    if(c == 1){
                        string name = get_file_name();
                        try{
                        msg =  read_OriginalMsg(name);
                        }catch(string e)
                        {
                            cout << e << endl;
                            break;
                        }
                        Caesar* csar = new Caesar();
                        e_msg = csar->encrypt(msg);
                        save_to_file(e_msg,msg);
                    }
                    else if(c == 2){
                        string name = get_file_name();
                        try{
                        msg =  read_OriginalMsg(name);
                        }catch(string e)
                        {
                            cout << e << endl;
                            break;
                        }
                        Caesar* csar = new Caesar();
                        e_msg = csar->decrypt(msg);
                        save_to_file(e_msg,msg);
                    }
                    else
                        exec();
                    break;
                }//end case 2

                case 3:
                {
                        int c;
                        cout << "1-Encrypt or 2-Decrypt?"<<endl;
                        cin >> c;
                        if(c == 1){
                            string name = get_file_name();
                            try{
                            msg =  read_OriginalMsg(name);
                            }catch(string e)
                            {
                                cout << e << endl;
                                break;
                            }
                            string key;
                            cout<<"Enter Encryption Key: ";
  							cin>>key;
                            Hill h(key);
                            e_msg = h.encrypt(msg);
                            save_to_file(e_msg,msg);
                        }
                        else if(c == 2)
                        {
                        	string name = get_file_name();
                            try{
                            msg =  read_OriginalMsg(name);
                            }catch(string e)
                            {
                                cout << e << endl;
                                break;
                            }
                            string key;
                            cout<<"Enter Encryption Key: ";
  							cin>>key;
                            Hill h(key);
                            e_msg = h.decrypt(msg);
                            save_to_file(e_msg,msg);
						}
                        else
                            exec();
                        break;
                }//end case 3



                case 4:
                    {
                        int c;
                        cout << "1-Encrypt or 2-Decrypt?"<<endl;
                        cin >> c;
                        if(c == 1){

                            try{
                            msg =  read_OriginalMsg();
                            }catch(string e)
                            {
                                cout << e << endl;
                                break;
                            }
                            cout<< "Enter Key: ";
                            string temp;
                            cin >> temp;
                            Vigenere* v = new Vigenere(temp);
                            e_msg = v -> encrypt(msg);
                            save_to_file(e_msg,msg);
                        }
                        else if(c==2)
                        {

                            try{
                            msg =  read_OriginalMsg();
                            }catch(string e)
                            {
                                cout << e << endl;
                                break;
                            }
                            cout<< "Enter Key: ";
                            string temp;
                            cin >> temp;
                            Vigenere v(temp);
                            e_msg = v.decrypt(msg);
                            save_to_file(e_msg,msg);
                        }
                        else
                            exec();
                        break;
                    }//end case 4


                case 5:
                {
                        open_db();
                        break;
                }//end case 5



                case 6:
                    {
                        int len;
                        cout << "Enter length of key: ";
                        cin >> len;
                        string key = gen_keys(len);
                        printS("Key: " + key,'#');
                        save_to_file(key);
                        break;
                    }//end case 6


            case 7:
                {
                close();
                break;
                }//end case 7



            case 8:
                {

                    type_center("Asem Muhammad - Hatem Mohamed - Mohamed Hani - Sohila Ibrahim - Omar Khaled");
                    break;
                }//end case 8

                case 9:
                {
                try{
                msg =  read_OriginalMsg();
                }catch(string e)
                {
                    cout << e << endl;
                    break;
                }
                string temp = search_in_db("database.txt",msg);
                cout << temp << endl;

                }//end case 9
            }

        }



    };

#endif // OPS_H_INCLUDED
