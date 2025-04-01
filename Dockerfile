FROM alpine
WORKDIR /home/ubuntu/DevOps/DevOps
COPY ./devops .
RUN apk add libstdc++
RUN apk add libc6-compat
ENTRYPOINT ["./devops"]
