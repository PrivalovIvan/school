FROM nginx

RUN apt-get update && apt-get upgrade && \
        apt-get install -y \
        libfcgi-dev gcc spawn-fcgi apt-utils net-tools nano;

WORKDIR ./server

COPY ./server /server/
COPY ./server/nginx/nginx.conf /etc/nginx/nginx.conf;

ENTRYPOINT ["sh", "start.sh"]