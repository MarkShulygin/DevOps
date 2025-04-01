FROM alpine
RUN apk add --no-cache build-base automake autoconf
WORKDIR /home/ubuntu/DevOps/DevOps
COPY . .
RUN ./configure
RUN make

FROM alpine
COPY --from=build /home/ubuntu/DevOps/DevOps /usr/local/bin/devops
ENTRYPOINT ["/usr/local/bin/devops"]

