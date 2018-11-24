import urllib.request
import time

a = 3
b = 7

send = ("http://10.10.5.183/web/socket.php?data=" + str(a) + "&data2=" + str(b))
print(send)

while True:
    send = ("http://10.10.5.183/web/socket.php?data=" + str(a) + "&data2=" + str(b))
    print(send)
    contents = urllib.request.urlopen(send).read()
    print(contents)
    a = a + 1
    b = b + 2
    time.sleep(5)