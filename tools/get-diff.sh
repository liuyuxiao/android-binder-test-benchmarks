#!/bin/bash
set -o nounset          # Treat unset variables as an error

LINUX=$1
ANDROID=$2
OUTDIR=diff-out

SUBDIR=`ls $ANDROID`
#if ! [ -e $(pwd)/${OUTDIR} ];then
#  mkdir $(pwd)/${OUTDIR} 
#fi
  
rm -rf $(pwd)/${OUTDIR} 
mkdir $(pwd)/${OUTDIR} 

diff -Nur --exclude=.git ${LINUX} ${ANDROID}  >${OUTDIR}/a.diff 
diffstat ${OUTDIR}/a.diff >${OUTDIR}/a.stat 

for basename in $SUBDIR
do
  path1="${LINUX}/${basename}"
  path2="${ANDROID}/${basename}"
  if [ -d ${path1} -a -d ${path2} ];then
    diff -qr ${path1} ${path2} | sed '/^Common/d' >${OUTDIR}/${basename}.diff 
    diff -Nur ${path1} ${path2} >${OUTDIR}/${basename}"-detail".diff 
    diffstat ${OUTDIR}/${basename}"-detail".diff > ${OUTDIR}/${basename}"-detail.stat" 
  fi
done

