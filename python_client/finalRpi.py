#!/usr/bin/python3

import urllib.request
import json
import socket
import serial

HOST = ''
PORT = 30025
ser = serial.Serial('/dev/ttyUSB0',9600)

def ardRead():
    read_serial = ser.readline()
    operace = read_serial[0]
    if operace == '1':
        data1 = int(read_serial) - 1000
    if operace == '2':
        data2 = int(read_serial) - 2000
    if operace == '3':
        data3 = int(read_serial) - 3000
    if operace == '4':
        data4 = int(read_serial) - 4000
        data4 = data4 / 10
    serWrite(data1, data2, data3, data4)


def serWrite(data1, data2, data3, data4):
    send = ("http://10.10.5.183/web/socket.php?data=" + str(data1) + "&data2=" + str(data2)
            + "&data3=" + str(data3) + "&data4=" + str(data4))
    urllib.request.urlopen(send).read()

def serRead():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()
        conn, addr = s.accept()
        data = conn.recv(1024)

    data = data.decode("utf-8")
    data = json.loads(data)
    data5 = (int(data['direction']) * 1000) + 2000
    data6 = int(data['speed'])
    data5 = data5 + data6
    data5 = str(data5)
    ardWrite(data5)

def ardWrite(data5):
    ser.write(bytes(data5, 'utf-8'))

ardRead()
serRead()