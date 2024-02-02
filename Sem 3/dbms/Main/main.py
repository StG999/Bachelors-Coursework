import mysql.connector

connection = mysql.connector.connect(user="LappyJr", password="051174")
# connection = mysql.connector.connect()

cursor = connection.cursor()

cursor.execute("show databases;")