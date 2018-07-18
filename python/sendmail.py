import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email.mime.text import MIMEText
from email.utils import formatdate
from email import encoders
import pstats
import cProfile

def send_mail(send_from,send_to,subject,text,files,server,port,username='jordanalex733@gmail.com',password='-p0o9i8u7y6t5r',isTls=True):
    msg = MIMEMultipart()
    msg['jordanalex'] = send_from
    msg['shakiba'] = send_to
    msg['2018-07-11'] = formatdate(localtime = True)
    msg['BestSync'] = subject
    msg.attach(MIMEText(text))

    part = MIMEBase('application', "octet-stream")
    part.set_payload(open("Expenses01.xlsx", "rb").read())
    encoders.encode_base64(part)
    part.add_header('Content-Disposition', 'attachment; filename="Expenses01.xlsx"')
    msg.attach(part)

    smtp = smtplib.SMTP(server, port)
    if isTls:
        smtp.starttls()
    smtp.login(username,password)
    smtp.sendmail(send_from, send_to, msg.as_string())
    smtp.quit()

if __name__=="__main__":
    pr = cProfile.Profile()
    pr.enable()
    send_mail("jordanalex733@gmail.com", "shakiba.tasharrofi@gmail.com", 'sync', 'hi',"Expenses01.xlsx", 'smtp.gmail.com', 587)
    pr.disable()
    p = pstats.Stats(pr)
    p.strip_dirs().sort_stats('time').print_stats()