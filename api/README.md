# Rest Api implemantation in C
## Requirements
sudo apt install libmicrohttpd-dev
sudo apt install libcjson-dev

## Compilation
(old)  gcc main.c -o rest_server -lmicrohttpd
(new)  make

# Testing
curl "http://localhost:8080/api/hello"
curl "http://localhost:8080/api/hello?name=Michael"
curl -X POST http://localhost:8080/api/data -H "Content-Type: application/json" -d '{"name":"Mario"}'


- 
