import urllib.request
contents = urllib.request.urlopen("http://10.10.5.183/web/socket.php?name=5").read()
print(contents)