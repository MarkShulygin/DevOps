FROM alpine AS build

RUN apk add --no-cache build-base git

WORKDIR /src
RUN git clone https://github.com/MarkShulygin/DevOps.git .
RUN make

FROM alpine
RUN apk add --no-cache libstdc++
COPY --from=build /src/funcA.elf /usr/local/bin/devops
ENTRYPOINT ["/usr/local/bin/devops"]
