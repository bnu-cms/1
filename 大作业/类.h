#include<iostream>
#include<list>
#include<string.h>
using namespace std;

class User{
	private:
	   string name;
	   string id;
	   string password;
	public:  
	   User(string sname,string sid,string spassword){
		   name=sname;
		   id=sid;
		   password=spassword;
	   }
	   string getname(){
		   return name;
	   }
	   string getid(){
		   return id;
	   }
	   string getpassword(){
		   return password;
	   }
};
class student : public User{
	private:
	    string classes[10];
		int classnum[10]={11,11,11,11,11,11,11,11,11,11};
		string major;
	public:
        student(string sname,string sid,string spassword,string smajor ):User(sname,sid,spassword),major(smajor){}
		bool selectcourse(string coursename,int n,string iname);
		bool dropcourse(string coursename,int n,string iname);
		bool get();
		int slogin(const string iname,const string iid,const string ipassword);
        bool slogout();
		bool schangepassword(string newpw);
};

class teacher : public User{
	private:
		string college;
	public:
	    teacher (string sname,string sid,string spassword,string scollege ):User(sname,sid,spassword),college(scollege){}
		bool opencourse(string name,int cred,string t,int n, string teaname );//开课
		void getstulist(int n);//学生名单
		bool postgrades(int n,double grades,string stuname);//打成绩
		int tlogin(const string iname,const string iid,const string ipassword);
		bool tlogout();
		bool tchangepassword(string newpw);
};

class administrator : public User{
	public:
	   administrator(string sname,string sid,string spassword):User(sname,sid,spassword){}
	   int alogin(const string iname,const string iid,const string ipassword);
	   bool changecourse(string name,int cred,string t,int n, string teaname );//改课
	   bool alogout();
	   bool achangepassword(string newpw);
};
struct Grade{
        string stuid;
		double grade;
		
};
struct course{
		string cname;
	    int credit;
     	string time;
		int num;
		string teachername;
		list<string>stulist;
		list<Grade>gradelist;
		
};

