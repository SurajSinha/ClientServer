#include <iostream>
#include <string>
using namespace std;

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

      //TODO

    }else if(in=="2"){

      cout<<"Type in the desired name for the newsgroup:"<<endl;

      string name;

      cin>>name;

      //TODO

    }else if(in=="3"){

      cout<<"Type in the number for the newsgroup that shall be deleted:"<<endl;

      string number;

      cin>>number;

      //TODO

    }else if(in=="4"){

      cout<<"Type in the number for the newsgroup:"<<endl;

      string number;

      cin>>number;

      //TODO

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
