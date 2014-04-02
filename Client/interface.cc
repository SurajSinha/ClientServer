#include <iostream>
#include <string>
#include "com.h"
#include "ans.h"
#include "newsGroup.h"
#include "article.h"
#include <vector>
#include "interface.h"
#include <algorithm>
using namespace std;

int validInput()
{
    int x;
    std::cin >> x;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Bad entry.  Enter a NUMBER: ";
        std::cin >> x;
    }
    return x;
}
int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr << "Usage: myclient host-name port-number" << endl;
    exit(1);
  }
  
  int port = -1;
  try {
    port = stoi(argv[2]);
  } catch (exception& e) {
    cerr << "Wrong port number. " << e.what() << endl;
    exit(1);
  }
  shared_ptr<Connection> conn = make_shared<Connection>(argv[1],port);
  if (!conn->isConnected()) {
    cerr << "Connection attempt failed" << endl;
    exit(1);
  }

  cout << "Connected to Server ";
  MessageHandler mh;
  mh.SetConnection(conn);	
  Com c(mh);
  Ans a(mh); 
  cout << "Welcome to our news system. Type the following in order to execute certain desired tasks:" << endl;

  while(true){

    cout << "1: List newsgroups'" <<endl;

    cout << "2: Create newsgroup" <<endl;

    cout << "3: Delete newsgroup" <<endl;

    cout << "4: List articles" <<endl;	

    cout << "5: Create article" <<endl;

    cout << "6: Delete article" <<endl;

    cout << "7: Get article" <<endl;

    string in;

    cin>>in;
    cin.ignore();
    if(in=="1"){

      cout<<"The newsgroups are the following:"<<endl;
      c.sendListNG();
      vector<NewsGroup> g = a.readAnsListNG();
      for(NewsGroup& n: g){
      	cout << n.id << " : "<< n.name<<endl;
      }
      //DONE

    }else if(in=="2"){

      cout<<"Type in the desired name for the newsgroup:"<<endl;

      string name;
      std::cin.ignore();
      getline(cin,name);
   // Man ska inte kunna skapa en newsgrop med whitespace som namn.
    // namn måste innehålla minst en char.
      
      c.sendCreateNG(name);
      bool done = a.readAnsCreateNG();
      if(done){
      	cout<<"Newsgroup "<< name <<" created"<<endl;;
      }else{
      	cout<<"NewsGroup with name "<<name<<" already exists in the current database."<<endl;
      }
      //DONE

    }else if(in=="3"){

      cout<<"Type in the number for the newsgroup that shall be deleted:"<<endl;

      size_t number=validInput();

      
      c.sendDeleteNG(number);
      bool done = a.readAnsDeleteNG();
      if(done){
      	cout<<"Newsgroup "<< number <<" deleted"<<endl;
      }else{
      	cout<<"Deletion failed"<<endl;
      }
      //DONE

    }else if(in=="4"){

      cout<<"Type in the number for the newsgroup:"<<endl;

      size_t number;
      cin>>number;
      c.sendListArt(number);
      vector<Article> g= a.readAnsListArt();
      for(Article& a: g){
      	cout<<a.title<<endl;
      }
      //DONE

    }else if(in=="5"){

      cout<<"Type in the desired name, author and text for the article:"<<endl;

      string name;

      string author;

      string text;

      cin>>name;

      cin>>author;

      string temp;

      while(cin>>temp){

	text+=temp;

	text+=" ";

      }

/*
		c.sendCreateArt(0,name,author,text)
		if(a.readCreateArt())	{
			cout<<"Article "<< name <<" created"<<endl;;
      	}else{
	      	cout<<"Creation failed"<<endl;
		}
*/

    }else if(in=="6"){

      cout<<"Type in the article number and the newsgroup number for the article that shall 			be deleted:"<<endl;

      size_t numberArticle;

      cin>>numberArticle;

      size_t numberNG;

      cin>>numberNG;

	/*  c.sendDeleteArt(numberNG,numberArticle);
	  auto res=a.readDeleteArt();
	  if(res==ASD)
	  {
	 	 cout<<"Error?"
	  }
	  else 
	  {
		cout<<"Article deleted"<<endl;
	  }*/
 

    }else if(in=="7"){

      cout<<"Type in the article number and the newsgroup number for the article that shall 			be retrieved:"<<endl;

      size_t numberArticle;

      cin>>numberArticle;

      size_t numberNG;

      cin>>numberNG;

/*
	 c.sendGetArt(numberNG, size_t numberArticle);   

		 try{
			Article art = a.readGetArt();
			cout<<"name:"<<art.title<<endl
 				<<"author:"<<art.writer<<endl
				<<contents<<endl;
	 	 }   
		 catch(WorldOnFireException eh)
		{
		}
*/

    }else{

      cout<<"invalid input"<<endl;

    }

  }
}
