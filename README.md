# TFTP Server

A simple Trivial File Transfer Protocol (TFTP) server.

## Dependencies

| Dependency name         | Minimum required version | Ubuntu 22.04                         |
|-------------------------|--------------------------|--------------------------------------|
| C++                     | C++17                    | sudo apt-get install build-essential |
| tftp_common             | 1.2.0                    | ---                                  |
| Boost.System, Boost.Program_Options | 1.74         | sudo apt install libboost-system-dev libboost-program-options-dev |

## Usage

```
tftp_server [directory]
```


## Implemented features ([RFC 1350](https://datatracker.ietf.org/doc/html/rfc1350))

| Feature | Implementation status |
| ----------- | ----------------- |
| READ requests | ${\color{red}\text{TODO}}$ |
| Write requests | ${\color{red}\text{TODO}}$ |

## Extensions support

| Extension | Implementation status |
| ----------- | ----------------- |
| [RFC 2347: TFTP Option Extension](https://datatracker.ietf.org/doc/html/rfc2347) | ${\color{red}\text{TODO}}$ |
| [RFC 2348: TFTP Blocksize Option](https://datatracker.ietf.org/doc/html/rfc2348) | ${\color{red}\text{TODO}}$ |
| [RFC 2349: TFTP Timeout Interval and Transfer Size Options](https://datatracker.ietf.org/doc/html/rfc2349) | ${\color{red}\text{TODO}}$ |
| [RFC 7440: TFTP Windowsize Option](https://datatracker.ietf.org/doc/html/rfc7440) | ${\color{red}\text{TODO}}$ |
