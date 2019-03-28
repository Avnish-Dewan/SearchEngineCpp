#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include<fstream>
#include<vector>
//#include "crawler.cpp"
using namespace std;
//int file_no=1;
char *words[1000];
int findFileSize(char *str)
{
	struct stat st; //variable which will count length of file.
	stat(str,&st); // temp.txt is the file where wget fetch the html

	return st.st_size;
}

//return the last position of title tag
int findWord(char *html,int pos,int id)
{
	int i;
	vector<char> v;
	for(i=pos;html[i]!='\0';i++)
	{
		if(html[i] =='<' && html[i+1] == 't' && html[i+2]=='i' && html[i+3] =='t' && html[i+4]=='l' && html[i+5]=='e')
		{
			i=i+5;
			while(html[i]!='>')
			{
				i++;
			}
			i++;
			//int j=0;
			while(html[i] != '<')
			{
				v.push_back(html[i]);
				i++;
				//j++;
			}
			/*for(int j=0;j<v.size();j++)
			{
				cout<<v[j];
			}*/
			words[id]=new char[v.size()+1];
			for(int j=0;j<v.size();j++)
			{
				words[id][j]=v[j];
			}
			words[id][v.size()]='\0';
			v.clear();
			//cout<<result<<endl;
			return i;
			//break;
		}
	}
	return -1;
}

//returns the
void getFileName(char *str,int fileNo)
{
	sprintf(str,"/home/avnish/Desktop/sefiles/temp%d.txt",fileNo);
	//file_no++;
}
char* getFile(int fileNo,char *htmlBuffer)
{
	char str[100];
	getFileName(str,fileNo);
	int fsize=findFileSize(str);
	htmlBuffer=new char[fsize+1];
	ifstream fin(str);
	char x;
	int i=0;
	while(!fin.eof())
	{
		x=fin.get();
		htmlBuffer[i]=x;
		i++;
	}
	//htmlBuffer[i]='\0';
	return htmlBuffer;
	//cout<<str<<" "<<fsize<<endl;

}
int main()
{
	int i=1;
	while(i<=10)
	{
		cout<<"HELLO";
		int pos=0;
		char *htmlBuffer;
		htmlBuffer=getFile(i,htmlBuffer);
		int id=0;
		while(pos!=-1)
		{
			pos=findWord(htmlBuffer,pos,id);
			cout<<words[id++]<<endl<<pos<<endl;
		}
		i++;
		delete htmlBuffer;
	}
}
