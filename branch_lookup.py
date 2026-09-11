import sys 
import mysql.connector as ms 
db=ms.connect(host="localhost",user="root",password="12345",database="AXB_bank")
cur=db.cursor()
name=str(sys.argv[1])
name=name.upper()
cur.execute("select * from branches where branch_name=%s",(name,))
data=cur.fetchone()
if data==None:
    print("0\n")
else:
    print(data[2])


