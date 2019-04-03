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
int id=0;
//int file_no=1;

//structure for making make List
struct Node
{
	char word[25];
	struct Node* next;
};

struct Node *head=(Node*)malloc(sizeof(Node));

char *words[1000];
int findFileSize(char *str)
{
	struct stat st; //variable which will count length of file.
	stat(str,&st); // temp.txt is the file where wget fetch the html

	return st.st_size;
}

//Make Linked List
void makeList()
{

}

//Extract Words
int extractWords(vector<char> v,int x)
{
	int j;
	bool inWord=false;
	/*for(int i=0;i<v.size();i++)
	{
		cout<<v[i];
	}*/
	for(int i=x;i<v.size();i++)
	{
		if(v[i]==' '|| v[i] == '-')
		{
			if(inWord==true)
			{
				words[id][j]='\0';
				//cout<<v[i]<<" ";
				//cout<<words[id++]<<endl;
				return i;
			}
			inWord=false;
		}
		else
		{
			if(inWord==false)
			{
				j=0;
				words[id]=new char[20];
				words[id][j++]=v[i];
				inWord=true;
			}
			else
			{
				words[id][j++]=v[i];
			}
		}
	}
	if(inWord==true)
	{
		//cout<<words[id]<<endl;
		words[id][++j]='\0';
	}
	return -1;
}

//return the last position of title tag
int findWordsInTitle(char *html,int pos)
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
			int j=0;
			while(html[i] != '<')
			{
				v.push_back(html[i]);
				i++;
			}
			int x=0;
			while(x!=-1)
			{
				x=extractWords(v,x);
				//cout<<words[id];
			}
			v.clear();
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
void getFile(int fileNo)
{
	char str[100];
	getFileName(str,fileNo);
	int fsize=findFileSize(str);
	char *htmlBuffer=new char[fsize+1];
	ifstream in(str);
	int i=0;
	char x;
	while(in.get(x))
	{
		htmlBuffer[i++]=x;
	}
	int pos=0;
	while(pos!=-1)
	{
		pos=findWordsInTitle(htmlBuffer,pos);
	}
	//cout<<htmlBuffer;
	//cout<<str<<endl;
}
int main()
{
	int i=1;
	//getFile(i);
	while(i<=10)
	{
		//cout<<"HELLO";
		//cout<<endl<<endl<<endl<<endl<<endl;
		int pos=0;
		getFile(i);
		i++;
	}
}
