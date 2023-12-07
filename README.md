**Host Information Lookup**

This C program demonstrates host information lookup using the gethostbyname function. It takes a hostname as a command-line argument and retrieves details such as the official name, aliases, address type (IPv4 or IPv6), and associated IP addresses.
Usage

bash

./host_info_lookup <hostname>

Features

    Retrieves host information using the gethostbyname function.
    Displays the official name and aliases of the provided hostname.
    Determines the address type (IPv4 or IPv6) and lists associated IP addresses.

Dependencies

    Standard C libraries: stdio.h, stdlib.h, string.h.
    Socket programming libraries: sys/socket.h, netinet/in.h, arpa/inet.h, netdb.h.
