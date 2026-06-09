FROM node:26-slim

RUN apt update && apt install -y \
        build-essential \
        time \
        git \
        python3.13 \
        pipx \
    && apt autoremove -y \
    && apt autoclean -y \
    && pipx ensurepath

RUN pipx install git+https://github.com/online-judge-tools/oj.git && \
# RUN pipx install setuptools
# RUN pipx install git+https://github.com/online-judge-tools/oj.git && \
#     pipx inject online-judge-tools setuptools
# COPY atcoder.py /root/.local/share/pipx/venvs/online-judge-tools/lib/python3.13/site-packages/onlinejudge/service/atcoder.py

RUN npm install -g atcoder-cli
RUN echo 'if [ ! -f ~/.config/atcoder-cli-nodejs/config.json ]; then mkdir -p ~/.config/atcoder-cli-nodejs && cp -r /tmp/atcoder-cli-nodejs/* ~/.config/atcoder-cli-nodejs/; fi' >> /root/.bashrc
COPY atcoder-cli-nodejs/ /tmp/atcoder-cli-nodejs/

RUN pipx install aclogin

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
