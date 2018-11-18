#!/usr/bin/env bash
pip3 install -r requirements.txt
chmod +x darwin
mkdir $HOME/bin
mv darwin $HOME/bin
echo 'export PATH=$PATH":$HOME/bin"' >> $HOME/".bashrc"
source $HOME/.bashrc
