//============================================================================
// Name        : OsamaHayat.cpp
// Author      : Osama Hayat Khan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void SentenceCheck(ifstream& ifile,string phrase)
{

	string temp;
	char read;
	int count=0;
	int line=1;

	while(!ifile.eof())
	{
		ifile.get(read);
		if(read=='\n')
		{
			++line;
		}
		else if(read!='.')
		{
			temp=temp+read;
		}
		else
		{
			//cout<<temp<<endl;
			if(temp==phrase)
			{
				cout<<"Sentence Found in line "<<line<<endl;
				++count;
			}
			temp="";
		}
		cout<<"Total Occurrences: "<<count;

	}

}

void WordCheck(ifstream& ifile, string word)
{
	string temp;
	char read;
	int count=0;
	int line=1;
	while(!ifile.eof())
	{
		ifile.get(read);
		if(read=='\n')
		{
			++line;
		}
		else if(read!=' ' && read!='.')
		{
			temp=temp+read;

		}
		else
		{
			//cout<<temp<<endl;
			if(temp==word)
			{
				cout<<"Word Found in line "<<line<<endl;
				++count;
			}
			temp="";

		}
	}
	cout<<"Total Occurrences: "<<count;
}



int main() {


	cout<<"**********************************************"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*                 FILE SEARCH                *"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"**********************************************"<<endl<<endl;


	ifstream ifile;
	string name;
	char choice;
	string phrase;


	cout<<"Enter File Name:";
	cin>>name;

	ifile.open(name);
	if(!ifile)
	{
		cout<<"Error Opening File. Exiting..."<<endl;
	}
	else
	{
		cout<<"(S)entence Check"<<endl;
		cout<<"(W)ord Check"<<endl;
		cin>>choice;
		cin.clear();
		cin.ignore();

		if(choice=='S')
		{
			cout<<"Enter Phrase to search in file:";
			getline(cin,phrase);
			//cout<<phrase<<endl<<endl;
			SentenceCheck(ifile,phrase);
		}

		else if(choice=='W')
		{
			cout<<"Enter Word to search in file:";
			cin>>phrase;
			WordCheck(ifile,phrase);
		}
	}

}
