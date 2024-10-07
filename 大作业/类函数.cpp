#include  "类.h" 
#include<vector>
list<teacher>lt;
list<teacher>::iterator tp;
list<student>ls;
list<student>::iterator sp;
list<administrator>la;
list<administrator>::iterator ap;
course lc[10];
struct course c[10];

int teacher :: tlogin(const string iname,const string iid,const string ipassword){//登录
	int f=1;
    tp=lt.begin();
    while(tp!=lt.end()){
        if( tp->getname() == iname && tp->getid()==iid && tp->getpassword()==ipassword){
            f=0;
            cout<<"登入成功"<<endl;
            return 1;
        }
        tp++;    
    }
    if(f==1){
        cout<<"登入失败"<<endl;
        tp->tlogout();
        return 0;
    }
    else {
        return 1;
    }
    
}

bool teacher :: tlogout(){//退出
	tp=lt.begin();
    cout<<"退出"<<endl;
    return true;
}

bool teacher :: tchangepassword(const string newpw){//改密码
	tp->getpassword()=newpw;
	if(tp->getpassword()==newpw){
          cout<<"改密码成功"<<endl;
          tp->tlogout();
          return true;
    }
	   
	else
	   {
           tp->tlogout();
           return false;
       }
}
int student :: slogin(const string iname,const string iid,const string ipassword){//登录
	int f=1;
    sp=ls.begin();
    while(sp!=ls.end()){
        if( sp->getname() == iname && sp->getid()==iid && sp->getpassword()==ipassword){
            f=0;
            cout<<"登入成功"<<endl;
        }
        sp++;    
    }
    if(f==1){
        cout<<"登入失败"<<endl;
        sp->slogout();
        return 0;
    }
    else {
         return 1;
    }
   
}
bool student :: slogout(){//退出
	sp=ls.begin();
    cout<<"退出"<<endl;
    return true;
}
bool student :: schangepassword(const string newpw){//改密码
	sp->getpassword()=newpw;
	if(sp->getpassword()==newpw){
        cout<<"改密码成功"<<endl;
        sp->slogout();
        return true;
    }
	 
	else{
        cout<<"改密码失败"<<endl;
        sp->slogout();
    }
	   return false;
}
int administrator :: alogin(const string iname,const string iid,const string ipassword){//登录
	int f=1;
    while(ap!=la.end()){
        if( ap->getname() == iname && ap->getid()==iid && ap->getpassword()==ipassword){
            f=0;
            cout<<"登入成功"<<endl;
            
        }
        ap++;    
    }
    if(f==1){
        cout<<"登入失败"<<endl;
        ap->alogout();
        return 0;
    }
    else{
        
        return 1;
    }
}
bool administrator :: alogout(){//退出
	ap=la.begin();
    cout<<"退出"<<endl;
    return true;
}
bool administrator :: achangepassword(const string newpw){//改密码
	ap->getpassword()=newpw;
	if(ap->getpassword()==newpw){
        cout<<"改密码成功"<<endl;
        ap->alogout();
        return true;
    }
	else{
        cout<<"改密码失败"<<endl;
        ap->alogout();
        return false;
    }
	   
}

bool student ::selectcourse(string coursename,int n,string iname){//选课
      classes[n] = coursename;
      classnum[n]= n;
      lc[n].stulist.push_back(iname);
      if(classes[n] == coursename && classnum[n] == n){
           cout<<"选课成功"<<endl;
           sp->slogout();
           return true;
      }
      else {
           cout<<"选课失败"<<endl;
           sp->slogout();
           return false;     
      }
    ;
}
bool student :: dropcourse (string coursename,int n,string iname){//退课
        int f=0;
        classes[n]="";
        classnum[n]=11;
        lc[n].stulist.remove(iname);  
        cout<<"退课成功"<<endl;
        sp->slogout();
        return true;
     
    }
    
bool student ::get(){//打印课表
    int f=0;
	for(int i=0;i<10;i++){
        int y=classnum[i];
        if(y<=10){
        cout<<c[y].cname<<" "<<c[y].credit<<" "<<c[y].num<<" "<<c[y].teachername<<" "<<c[y].time<<endl;
        f=1;}
    }
        if(f==1){
            sp->slogout();
            return true;
            
        }
        else{
           cout<<"打印失败"<<endl;
           sp->slogout();
           return false;
        }
}
bool teacher ::opencourse(string name, int cred, string t, int n, string teaname){
       c[n]={name,cred,t,n,teaname};
        if(c[n].cname == name){
             cout<<"开课成功"<<endl;
             tp->tlogout();
             return true;
        }
        else{
            cout<<"开课失败"<<endl;
            tp->tlogout();
            return false;
        }    
}

bool teacher:: postgrades(int n,double grades,string stuname){
      Grade g={stuname,grades};
      lc[n].gradelist.push_back (g);
      cout<<"登记成功"<<endl;
      tp->tlogout();
      return true;
}

void teacher :: getstulist(int n){
     list <string> :: iterator ps =lc[n].stulist.begin();
     for(; ps != lc[n].stulist.end();ps++){
        cout<<"学生名单:"<<endl;
        cout<<*ps<<endl;
     }
     tp->tlogout();
}
bool administrator :: changecourse(string name, int cred, string t, int n, string teaname){
    c[n]={name,cred,t,n,teaname};
        if(c[n].cname == name && c[n].time==t &&c[n].credit==cred && c[n].teachername==teaname){
             cout<<"改课成功"<<endl;
             ap->alogout();
             return true;
        }
        else{
            cout<<"改课失败"<<endl;
            ap->alogout();
            return false;
        }    
}




