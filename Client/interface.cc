#include <iostream>
#include <string>
#include "com.h"
#include "ans.h"
#include "newsGroup.h"
#include "article.h"
#include <vector>
using namespace std;
Com c;
Ans a;
interface(Com& c, Ans& a){
	this.c=c;
	this.a=a;
}

int main(){	
  
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

    if(in=="1"){

      cout<<"The newsgroups are the following:"<<endl;
      c.sendListNG();
      vector<newsGroup> g = a.readAnsListNG();
      for(newsGroup& n: g){
      	cout << n.name<<endl;
      }
      //DONE

    }else if(in=="2"){

      cout<<"Type in the desired name for the newsgroup:"<<endl;

      string name;

      cin>>name;
      c.sendCreateNG(name);
      bool done = readAnsCreateNG();
      if(done){
      	cout<<"Newsgroup "<< name <<" created"<<endl;;
      }else{
      	cout<<"Creation failed"<<endl;
      }
      //DONE

    }else if(in=="3"){

      cout<<"Type in the number for the newsgroup that shall be deleted:"<<endl;

      size_t number;

      cin>>number;
      c.sendDeleteNG(number);
      a.readAnsDeleteNG();
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
      	cout<<g.title<<endl;
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

      //TODO

    }else if(in=="6"){

      cout<<"Type in the article number and the newsgroup number for the article that shall 			be deleted:"<<endl;

      string numberArticle;

      cin>>numberArticle;

      string numberNG;

      cin>>numberNG;

      //TODO

    }else if(in=="7"){

      cout<<"Type in the article number and the newsgroup number for the article that shall 			be retrieved:"<<endl;

      string numberArticle;

      cin>>numberArticle;

      string numberNG;

      cin>>numberNG;

      //TODO

    }else{

      cout<<"invalid input"<<endl;

    }

  }

}
