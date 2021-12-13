#include<iostream>
#include<cstring>
#include<conio.h>
#include<windows.h>

using namespace std;
class list{
	private:
		struct node{
			string word;
			node *next;
		};
		node *listHeadPtr;
	public:
		list()
		{
				listHeadPtr = NULL;
		}
		void input(string);
		void display();
		string choice(string);
};




void list::display()
{
	node *temp=listHeadPtr;
	while(temp!=NULL)
	{
		if(temp->word == "\n")
		cout << temp->word;
		else
		cout<< temp->word << " "; 
		temp=temp->next;
	}
}

void list::input(string newWord)
{
	if(newWord == " ")
	return;
	node *ptrNew=new node();
	node *ptrTemp = listHeadPtr;
	ptrNew->word = newWord;
	ptrNew->next = NULL;
	if(listHeadPtr == NULL)
	{
		listHeadPtr = ptrNew;
		return;
	}
	while(ptrTemp->next != NULL)
	{
		ptrTemp = ptrTemp->next;
	}
	ptrTemp->next = ptrNew;
}

string list::choice(string val)
{
	string search[4] = {"\0", "\0", "\0", "\0"};
	bool diffWord = true;
	int top = 0;
	node *ptrTemp = listHeadPtr;
	while(ptrTemp != NULL)
	{
		if(ptrTemp->word == val)
		{
			diffWord = true;
		    ptrTemp  = ptrTemp->next;
		    if(ptrTemp == NULL)
		    break;
		    cout << "\n\n\n\n\n\n";
		    if(top < 4)
		    {	
		      for(int i=0;i<top;++i)
		      {
		      	if(search[i] == ptrTemp->word)
		      	diffWord = false;
			  }
		      if(ptrTemp->word != " " &&  diffWord)
		      search[top++] = ptrTemp->word;	
			}
		}
		ptrTemp = ptrTemp->next;
	}
	
	for(int i = 0;i<top;++i)
	{
		cout << i + 1 << ": "<< search[i] << "\t\t";
	}
	char choice = '5';
	if(top > 0)
	{
	  choice = getch();
	  system("cls");	
	}
	if(choice == '1' && search[0] != "\0")
    return search[0];
	else if(choice == '2'  && search[1] != "\0")
	return search[1];
	else if(choice == '3'  && search[2] != "\0")
	return search[2];
	else if(choice == '4'  && search[3] != "\0")
	return search[3];
	else
	return "\0";	
}

int startMenu();

int main()
{
	list usr;
	string val="", sentence="";
	for(;;)
	{
	   if(!startMenu())
	   {
	   	 usr.display();
	   	 return 0;
	   }
	  
	char cur_input;
	sentence = "";
	cout << "Enter a sentence: " << endl;
        while(1)
	    {
		  cur_input = getch();
		  cout << cur_input;
		  if(cur_input == ' ')
		    {
		      if(val == "\0")
		      continue;
		      string newWord = usr.choice(val);
		      usr.input(val);
		      if(newWord != "\0")
		      {
		         usr.input(newWord);
				 sentence += " " +  newWord;
			     cout << sentence << " ";	
			  }
			  else
			  {
			     system("cls");
			  	 cout << sentence << endl;
			  }
			  val = "\0";	
			}
		  else if(cur_input == '\r')
		    {
		    	usr.input(val);
		        usr.input("\n");
		        val = "";
		        cout << endl;
		        system("cls");
		        break;
			}
		 else
		  val += cur_input;
		  sentence += cur_input;
	    }	
	}
	 
	    usr.display();
	    
	return 0;
}

int startMenu()
{
	char choice;
	cout << "Press 1 to enter a sentence: " << endl;
	cout << "Press Q to quit: " << endl;
	cin >> choice;
	system("cls");
	if(choice == '1')
	{
	   return 1;	
	} 
	else
	{
	  return 0;	
	}
	  
}
