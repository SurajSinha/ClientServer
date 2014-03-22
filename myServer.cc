#include <memory>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>

#include "server.h"
#include "connection.h"
#include "connectionclosedexception.h"

 int main(int argc, char* argv[]){
	/*
	 Checks if number of arguments is 2. If not then program is closed.
	*/
	if(argc!=2){
		cerr<<"Usage: myserver port-number" <<endl;
		exit(1);
	}
	/*
	  Tries to convert port number in argv array to Integer.
	*/
	int port(-1);
	try{
		port=stoi(argv[1]);
	}catch(exception& e){
		cerr<<"Wrong port number."<< e.what()<<endl;
		exit(1);
	}
	/*
	  A Server Object is instantiated.
	*/
	Server server(port);
	if(!server.isReady(){
		cerr<<"Server initialization Error."<<endl;
		exit(1);
	}
	//Handles connections with the Client.
	while(true){
		// Nullptr is returned if new Client wishes to communicate.
		auto conn=server.waitForActivity();
		if(!conn){
			try{
			
			}catch(ConnectionClosedException& e){
				server.deregisterConnection(conn);
				cout<<"Client closed Connection"<<endl;
			}
		}else{
			conn=make_shared<Connection>();
			server.registerConnection(conn);
			cout<<"New client connects"<< endl;
		}
	}
 }
 
 
