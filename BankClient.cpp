#include <iostream>
#include <string>
#include <exception>

using namespace std;

class BankClient{
public:
    BankClient(){
        clientName = "";
	clientLastname = "";
	clientLogin = "";
	clientPassword = "";
	clientNumber = -1;
	clientMooney = 0;
    }
    void setClientName(string inName){
        clientName = inName;
    }
    string getClientName(){
        return clientName;
    }
    void setClientLastname(string inLastname){
        clientLastname = inLastname;
    }
    string getClientLastname(){
        return clientLastname;
    }
    void setClientLogin(string inLogin){
        clientLogin = inLogin;
    }
    string getClientLogin()
    {
        return clientLogin;
    }
    void setClientPassword(string inPassword){
        clientPassword = inPassword;
    }
    string getClientPassword()
    {
        return clientPassword;
    }
    void setClientNumber(int inNumber){
        clientNumber = inNumber;
    }
    int getClientNumber(){
        return clientNumber;
    }
    void setClientMooney(double inMooney){
        clientMooney = inMooney;

    }
    double getClientMooney(){
        return clientMooney;
    }
    void ClientCashout(int inout)
    {
        clientMooney -= inout;
    }

private:
    string clientName;
    string clientLastname;
    string clientLogin;
    string clientPassword;
    int clientNumber;
    double clientMooney;


};

class Database{
public:
    Database(){
    nextSlot = 0;
    }
    void addClient(BankClient& inClient){
        clients[nextSlot ++] = inClient;
    }
    void getUser(string inName, string inLastname){
	bool flag = false;
	for(int i = 0; i < nextSlot; i++)
	{
            if(inName == clients[i].getClientName() && inLastname == clients[i].getClientLastname())
	    {
                cout << "[-]Name: " << clients[i].getClientName() << endl;
	        cout << "[-]Lastname: " << clients[i].getClientLastname() << endl;
	        cout << "[-]Number: " << clients[i].getClientNumber() << endl;
	        cout << "[-]Current invoice: " << clients[i].getClientMooney() << endl;
		flag = true;
	    }
	}
	if(!flag)
	{
	    cerr <<"[-] Client with name " << inName << " and lastname " << inLastname << " Non found!" << endl;
	    throw exception();
	}
    }
    void getUser(int inNumber){
        bool flag = false;
	for(int i = 0; i < nextSlot; i ++)
	{
	    if(inNumber == clients[i].getClientNumber())
	    {
	        cout << "[-]Name: " << clients[i].getClientName() << endl;
		cout << "[-]Lastname: " << clients[i].getClientLastname() << endl;
		cout << "[-]Number: " << clients[i].getClientNumber() << endl;
		cout << "[-]Current invoice: " << clients[i].getClientMooney() << endl;
		flag = true;
	    }
	}
	if(flag == false)
	{
	    cerr << "[-] Client with number " << inNumber << " Non found! " << endl;
	    throw exception();
	}
    }
    void cashOut(string inName,string inLogin,string inPassword,int inout){
        bool flag = false;
	for(int i = 0; i < nextSlot; i ++)
	{
	    if(inName == clients[i].getClientName())
	    {
	        if(inLogin == clients[i].getClientLogin() && inPassword == clients[i].getClientPassword())
		{
		    clients[i].ClientCashout(inout);
		    cout << "[-] Your current invoice: " << clients[i].getClientMooney() << endl;
		    flag = true;
		}
	    }
	}
	if(!flag)
	{
	    cerr << "[-] You writing invalid datas! Please try again: " << endl;
	    throw exception();
	}
    }
private:
    BankClient clients[10];
    int nextSlot;


};

int main(){
    BankClient bankClient1;
    bankClient1.setClientName("Mike");
    bankClient1.setClientLastname("Mikel");
    bankClient1.setClientNumber(98202020);
    bankClient1.setClientLogin("mikel18");
    bankClient1.setClientPassword("mikel181920");
    bankClient1.setClientMooney(101000);
    Database clients;
    clients.addClient(bankClient1);
    clients.getUser("Mike","Mikel");
    clients.cashOut("Mike","mikel18","mikel181920",10000);
    clients.getUser(98202020);
    return 0;
}
