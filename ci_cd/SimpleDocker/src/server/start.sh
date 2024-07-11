#!/bin/sh

gcc server.c -o mini_server -lfcgi
spawn-fcgi -a 127.0.0.1 -p 8080 mini_server
service nginx start
/bin/bash
tail -f /dev/null