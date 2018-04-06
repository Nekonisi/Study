#!/bin/sh

cwd=`dirname "${0}"`
echo ${cwd}

read -p "Hit enter: "

for file in `ls`

do temp=`echo ${file}|sed 's/\.[^\.]*$//'`
pandoc_html ${file} -o ../html/${temp}.html
done