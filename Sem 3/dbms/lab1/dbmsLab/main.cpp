#include<iostream>
#include<conio.h>
#include<windows.h>
#include<mysql.h>
#include<sstream>
using namespace std;
main(){
    MYSQL* con;
    con = mysql_init(0);
    con = mysql_real_connect(con,"localhost","root","","mydb",0,NULL,0);
    if(con){
        cout<<"Connection Successful";
    }
    else{
        cout<<"Connection failed";
    }
    getch();
    return 0;
}
