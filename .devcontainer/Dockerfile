FROM node:26-slim

ENV SHELL=/bin/bash

RUN apt update && apt install -y \
    build-essential \
    git \
    python3 \
    python3-pip
    
RUN pip3 install --break-system-packages setuptools
RUN pip3 install --break-system-packages online-judge-tools
COPY atcoder.py /usr/local/lib/python3.13/dist-packages/onlinejudge/service/atcoder.py

RUN npm install -g atcoder-cli
RUN mkdir -p /root/.config/atcoder-cli-nodejs
COPY config/ /root/.config/atcoder-cli-nodejs/

RUN pip3 install --break-system-packages aclogin

RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH="/lib/ac-library"
# ENV CPLUS_INCLUDE_PATH="/lib/ac-library:/opt/boost/bin:/usr/include/eigen3"

RUN echo "if [ -f ~/.bash_aliases ]; then . ~/.bash_aliases; fi" >> /root/.bashrc
COPY .bash_aliases /root/.bash_aliases

WORKDIR /workspace
