FROM node:26-slim

ENV SHELL=/bin/bash

RUN apt update && apt install -y \
    build-essential \
    git \
    python3 \
    python3-pip

RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH="/lib/ac-library"
# ENV CPLUS_INCLUDE_PATH="/lib/ac-library:/opt/boost/bin:/usr/include/eigen3"

RUN pip3 install online-judge-tools

RUN npm install -g atcoder-cli

WORKDIR /workspace
