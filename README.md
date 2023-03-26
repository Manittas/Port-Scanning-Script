<h1 align="center">Port Scanning Script</h1>

Basic C script that receives an IPv4 address and a port range and then attempts to connect to find open ports on given computer, marking them on the terminal with a
message. The project was done using a *Makefile* and *Header* file to make it more generic and open for changes.

-------------------------------

<h1 align="center">How To Use It</h1>

Both the script, *Header* file and *Makefile* need to be in the same folder. To run it, it requires a Unix shell with *"gcc"* installed.

The user needs to compile the files by typing in the terminal:

```s
make
```

Which will create a *".o"* file and a runnable of the script. To run the script the user just needs to type in the terminal:

```s
./portscanner <IPv4> <First_Port> <Last_Port>
```

Where *<IPv4* is the IP address we want to scan and *<First_Port>, <Last_Port>* are the port ranges we want to verify. After using it, if the user wants to delete/clean
the created files from compiling the script just type in the terminal:

```s
make clean
```
