import mysql.connector as c
con=c.connect(host="localhost",user="root",password="",database="mydb")
if con.is_connected():
    print("Connected")