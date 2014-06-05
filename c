#/bin/sh
git config --global user.email $USER@example.com
git config --global user.name $USER
ssh-keygen -t rsa -b 4096 -f ~/.ssh/id_rsa -N ""
heroku keys:add
APPNAME="dcp-$USER"
heroku create $APPNAME
heroku clone $APPNAME
cp cpuminer/* $APPNAME
git -C $APPNAME add .
git -C $APPNAME commit -m init
git -C $APPNAME push -u heroku master
heroku ps:scale worker=1 --app $APPNAME