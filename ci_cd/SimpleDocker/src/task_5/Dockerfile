FROM nginx

RUN apt-get update && apt-get upgrade && \
        apt-get install -y \
        libfcgi-dev gcc spawn-fcgi apt-utils net-tools nano \
        && rm -rf /var/lib/apt/lists \
        && touch /var/run/nginx.pid;

WORKDIR ./server

COPY ./server /server/
COPY ./server/nginx/nginx.conf /etc/nginx/nginx.conf;


RUN chown -R nginx:nginx /usr; \
    chown -R nginx:nginx /etc/nginx/nginx.conf; \
    chown -R nginx:nginx /var/cache/nginx; \
    chown -R nginx:nginx /server; \
    chown -R nginx:nginx /var/run/nginx.pid;



USER nginx

ENTRYPOINT ["sh", "start.sh"]