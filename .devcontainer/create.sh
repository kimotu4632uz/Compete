#!/bin/sh

acc login
oj login https://atcoder.jp

cp -r .devcontainer/atcoder-cli-nodejs/cpptemp /home/vscode/.config/atcoder-cli-nodejs/
cp .devcontainer/atcoder-cli-nodejs/config.json /home/vscode/.config/atcoder-cli-nodejs/
