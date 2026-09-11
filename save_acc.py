import sys
import mysql.connector as ms
db=ms.connect(host="localhost",user="root",password="12345",database="AXB_bank")
cur=db.cursor()
acc_no=str(sys.argv[1])
name=str(sys.argv[2])
branch_code=int(sys.argv[3])
acc_type=str(sys.argv[4])
bal=float(sys.argv[5])
cur.execute("insert into accounts(account_number,name,branch_code,account_type,balance) values(%s,%s,%s,%s,%s)",(acc_no,name,branch_code,acc_type,bal))
db.commit()
print(1)