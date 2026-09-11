import sys
import mysql.connector as ms 
db=ms.connect(host="localhost",user="root",password="12345",database="AXB_bank")
cur=db.cursor()
cur.execute("select next_sequence from branches where branch_code=%s",(sys.argv[1],))
d=cur.fetchone()
print(d[0])
cur.execute("update branches set next_sequence=next_sequence+ 1 where branch_code=%s",(sys.argv[1],))
db.commit()
