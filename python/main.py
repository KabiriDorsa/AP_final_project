import os
import mysql.connector
import time
import xlsxwriter
import pstats
import cProfile


#Create source table in datebase
def source(path):
    cnx = mysql.connector.connect(user = 'root', password = 'sha00187', host= '127.0.0.1', port = '3306', database = 'synchronize')
    cursor = cnx.cursor(buffered=True)
    if cnx.is_connected():
        print('Connected to MySQL database')

    cursor.execute("DROP TABLE IF EXISTS source")
    sql = "CREATE TABLE source (file_name TEXT , size LONG, date_modification TEXT)"
    cursor.execute(sql)
    try:
        for root, directories, filenames in os.walk(path):
            for filename in filenames:
                a = os.path.join(root,filename)
                i = a.replace(path + '\\','')
                cursor.execute("""INSERT INTO source VALUES (%s, %s, %s)""",(i, os.path.getsize(a), time.ctime(os.path.getctime(a))))

            cnx.commit()


    except:
        cnx.rollback()
    cursor.execute("SELECT * FROM source")
    l = cursor.fetchall()
    print(l)
    workbook = xlsxwriter.Workbook('Expenses01.xlsx')
    worksheet = workbook.add_worksheet()
    row = col = 0
    for i in l:
        worksheet.write(row, col, i[0])
        worksheet.write(row, col + 1, i[1])
        worksheet.write(row, col + 2, i[2])
        row += 1
    workbook.close()

    cursor.close()
    cnx.close()



#create target table in datebase
def target(path):
    cnx = mysql.connector.connect(user = 'root', password = 'sha00187', host= '127.0.0.1', port = '3306', database = 'synchronize')
    cursor = cnx.cursor(buffered=True)
    cursor.execute("DROP TABLE IF EXISTS target")
    sql = "CREATE TABLE target (file_name TEXT , size LONG, date_modification TEXT)"
    cursor.execute(sql)
    try:
        for root, directories, filenames in os.walk(path2):
            for filename in filenames:
                b = os.path.join(root,filename)
                j = b.replace(path + '\\','')
                cursor.execute("""INSERT INTO target VALUES (%s, %s, %s)""",(j, os.path.getsize(b), time.ctime(os.path.getctime(b))))
            cnx.commit()
    except:
        cnx.rollback()
    cursor.execute("SELECT * FROM target")
    s = cursor.fetchall()
    print(s)
    cnx.close()
    cursor.close()
    cnx.close()


if __name__ == "__main__":
    #profile the code
    pr = cProfile.Profile()
    pr.enable()
    path = 'C:\\Users\\ASUS\\Desktop\\1'
    path2 = 'C:\\Users\\ASUS\\Desktop\\2'
    source(path)
    target(path2)
    pr.disable()
    p = pstats.Stats(pr)
    p.strip_dirs().sort_stats('time').print_stats()

