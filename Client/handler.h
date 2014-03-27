#ifndef HANDLER_H
#define HANDLER_H

#include <memory>
#include "connection.h"
#include "protocol.h"

struct ProtocolViolationException{};

class MessageHandler
{
private:
	
	std::shared_ptr<Connection> conn;
public:
////// 
	MessageHandler() {}
	void SetConnection(std::shared_ptr<Connection> con){
		conn=con;
	}
	
//////	
	MessageHandler(std::shared_ptr<Connection> con) : conn(con)
	{	
	}

	
	void sendByte(unsigned char i) const
	{
		conn->write(i);
	}

	void sendInt(int value) const
	{
		sendByte((value >> 24) & 0xFF);		
		sendByte((value >> 16) & 0xFF);
		sendByte((value >> 8) & 0xFF);
		sendByte(value & 0xFF);
	}

	void sendCode(unsigned char i) const
	{
		sendByte(i);
	}
	void sendNumParameter(int i) const
	{
		sendCode(Protocol::PAR_NUM);
		sendInt(i);
	}
	void sendStringParameter(const std::string& str) const
	{
		sendCode(Protocol::PAR_STRING);
		sendInt(str.size());
		for(char c:str)
		{
			sendByte(c);
		}
	}


	unsigned char recieveByte() const
	{
		return conn->read();
	}
	int recieveInt() const
	{
		int b1 = recieveByte();		
		int b2 = recieveByte();
		int b3 = recieveByte();
		int b4 = recieveByte();
		return b1 << 24 | b2 << 16 | b3 << 8 | b4;
	}

	unsigned char recieveCode() const
	{	
		return recieveByte();
	}
	int recieveIntParameter() const
	{
		if(recieveCode()!=Protocol::PAR_NUM)
		{
			throw ProtocolViolationException();
		}
		return recieveInt();
	}
	std::string recieveStringParameter() const
	{
		if(recieveCode()!=Protocol::PAR_STRING)
		{
			throw ProtocolViolationException();
		}
		int c=recieveInt();
		if(c<0)
		{
			throw ProtocolViolationException();
		}
		std::string str;
		for(int i=0;i<c;i++)
		{
			str+=recieveByte();
		}
		return str;
	}


};


#endif
