FROM node:26-slim

RUN apt update && apt install -y \
        build-essential \
        time \
        git \
        python3.13 \
        python3-pip \
    && apt autoremove -y \
    && apt autoclean -y

RUN pip3 install --break-system-packages setuptools
RUN pip3 install --break-system-packages online-judge-tools
COPY atcoder.py /usr/local/lib/python3.13/dist-packages/onlinejudge/service/atcoder.py

RUN npm install -g atcoder-cli
RUN echo 'if [ ! -f ~/.config/atcoder-cli-nodejs/config.json ]; then mkdir -p ~/.config/atcoder-cli-nodejs && cp -r /tmp/atcoder-cli-nodejs/* ~/.config/atcoder-cli-nodejs/; fi' >> /root/.bashrc
COPY atcoder-cli-nodejs/ /tmp/atcoder-cli-nodejs/

RUN pip3 install --break-system-packages aclogin

RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH="/lib/ac-library"
# ENV CPLUS_INCLUDE_PATH="/lib/ac-library:/opt/boost/bin:/usr/include/eigen3"

RUN echo "if [ -f ~/.bash_aliases ]; then . ~/.bash_aliases; fi" >> /root/.bashrc
COPY .bash_aliases /root/.bash_aliases

ENV SHELL=/bin/bash
RUN ( \
    echo ""; \
    echo "# --- Terminal Color & Clean Hostname ---"; \
    echo "export TERM=xterm-256color"; \
    echo "export PS1='\[\e[31m\]\u\[\e[m\]:\[\e[34m\]\w\[\e[m\]$ '"; \
    echo "alias ls='ls --color=auto'"; \
    echo "alias ll='ls -l --color=auto'"; \
) >> /root/.bashrc

WORKDIR /workspace
