#!/bin/sh

#task_5
#docker rmi -f dockers:4.4
#docker build ../ -t dockers:4.4 -f /home/ivan/task_5/Dockerfile
#docker run --name docker_test -dti --rm -p 80:81 \ 
#-v /home/ivan/server/nginx/nginx.conf:/etc/nginx/nginx.conf dockers:4.4

#task_6
docker rmi -f dockers:4.4
docker build /home/ivan/ -t dockers:4.4 -f /home/ivan/task_5/Dockerfile
docker run --name docker_test \
         -dti --rm \
         -v /home/ivan/server/nginx/nginx.conf:/etc/nginx/nginx.conf \
         dockers:4.4 \
         nginx -g 'daemon off';