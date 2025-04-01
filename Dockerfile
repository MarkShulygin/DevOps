FROM alpine AS build
RUN apk add --no-cache build-base automake autoconf perl git
RUN git clone https://github.com/MarkShulygin/DevOps.git /src
WORKDIR /src
COPY . .
RUN aclocal
RUN autoconf
RUN automake --add-missing
RUN ./configure
RUN make

FROM alpine
COPY --from=build /home/ubuntu/DevOps/DevOps /usr/local/bin/devops
ENTRYPOINT ["/usr/local/bin/devops"]

