import socket
import time

target = input("Enter IP: ")
ports = [21, 22, 80, 443, 3306]

start = time.time()

file = open("scan_results.txt", "w")

for port in ports:
    s = socket.socket()
    s.settimeout(1)
    result = s.connect_ex((target, port))

    if result == 0:
        status = "OPEN"
    else:
        status = "CLOSED"

    print(f"Port {port}: {status}")
    file.write(f"Port {port}: {status}\n")
    s.close()

file.close()

end = time.time()
print("Scan Time:", end - start)
