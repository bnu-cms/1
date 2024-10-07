#include <iostream>
#include <type_traits>
#include<vector>
#include "类函数.cpp"
void setcourse(){
    c[0] = {"犯罪心理学",2,"八点半到十点",0,"席勒"};
    c[1] = {"金融学",2,"四点到五点",1,"费渡"};
    c[2] = {"建筑学",2,"七点到八点半",2,"吴邪"};
}

int main() {
    setcourse();
    administrator ad0("1","1","1");
    la.push_back(ad0);
    administrator ad1("周明瑞","245674","yzlnd");
    la.push_back(ad1);
    teacher teacher0("1","1","1","1");
    lt.push_back(teacher0);
    teacher teacher1("吴邪","123456","wx123","建筑学");
    lt.push_back(teacher1);
    teacher teacher2("席勒","56789","xile567","犯罪心理学");
    lt.push_back(teacher2);
    student student0("1","1","1","1");
    ls.push_back(student0);
    student student1("金独子","79034","duzi790","天文");
    ls.push_back(student1);
    while(1){
    cout<<"登录 输入名字、ID、密码"<<endl;
    cout<<"1.学生2.老师3.管理员"<<endl;
    string iname;
    string iid;
    string ipassword;
    cin>>iname>>iid>>ipassword;
    int a;
    cin>>a;
    switch (a) {
    case 1:{
        sp=ls.begin();
        int as=sp->slogin( iname, iid, ipassword);
        if(as==1){
        cout<<"1.选课2.退课3.查看课表4.改密码5.退出"<<endl;
        int x;
        cin>>x;
        switch (x) {
    case 1:{
        cout<<"输入课名，编号，名字"<<endl;
        string coursename;
        int n;
        string iname;
        cin>>coursename>>n>>iname;
        sp->selectcourse( coursename, n, iname);
        break;
    }
    case 2:{
        cout<<"输入课名，编号，名字"<<endl;
        string coursename;
        int n;
        string iname;
        cin>>coursename>>n>>iname;
        sp->dropcourse( coursename, n, iname);
        break;
    }
    case 3:{
        sp->get();
        break;
    }
    case 4:{
        cout<<"输入密码"<<endl;
        string newp;
        sp->schangepassword(newp);
        break;
    }
    case 5:{
        sp->slogout();
        break;
    }
    }}
        break;
    }
    case 2:{
        tp=lt.begin();
        int at=tp ->tlogin(iname,iid, ipassword);
        if(at==1){
        cout<<"1.开课2.上传成绩3.查看学生名单4.改密码5.退出"<<endl;
        int b;
        cin>>b;
        teacher te("1","1","1","1");
    switch(b){
    case 1:{
        cout<<"输入课名，学分，时间，编号，老师名字"<<endl;
        string name;
        int cred;
        string t;
        int n;
        string teaname;
        cin>>name>>cred>>t>>n>>teaname;
        te.opencourse( name,cred, t, n,teaname);
        break;
     }
    case 2:{
        cout<<"输入课程编号，成绩，学生名"<<endl;
        int n;
        double grades;
        string stuname;
        cin>>n>>grades>>stuname;
        te.postgrades( n, grades,stuname);
        break;
    } 
    case 3:{
        cout<<"输入课程编号"<<endl;
        int n;
        cin>>n;
        te.getstulist(n);
        break;
    }
    case 4:{
        cout<<"输入密码"<<endl;
        string newp;
        tp->tchangepassword(newp);
        break;
    }
    case 5:{
        tp->tlogout();
        break;
    }
    }}
        break;
    }
    case 3:{
        ap=la.begin();
        int ay=ap->alogin(iname,  iid,  ipassword);
        if(ay==1){
        cout<<"1.改课2.改密码3.退出4.加学生"<<endl;
        int c;
        cin>>c;
        administrator abc("1","1","1");
    switch (c) {
    case 1:{
        cout<<"输入课名，学分，时间，编号，老师名字"<<endl;
        string name;
        int cred;
        string t;
        int n;
        string teaname;
        cin>>name>>cred>>t>>n>>teaname;
        abc.changecourse(name,  cred, t,n, teaname);
        break;
    }
    case 2:{
        cout<<"输入密码"<<endl;
        string newp;
        ap->achangepassword(newp);
        break;
    }
    case 3:{
        ap->alogout();
        break;
    }
    case 4:{
        cout<<"输入名字,ID,密码,专业"<<endl;
        string namenew;
        string idnew;
        string pwnew;
        string majornew;
        cin>>namenew>>idnew>>pwnew>>majornew;
        student st(namenew,idnew,pwnew,majornew);
        ls.push_back(st);
        cout<<"增加成功"<<endl;
        ap->alogout();
    }
    }}
        break;
    }
    }
}

}




	

