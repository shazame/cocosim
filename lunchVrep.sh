#! /bin/sh

vrepRemoteApiPortNumber=`echo 1234`
vrepSceneAbsolutePath=`readlink -f virtual-game-2016.ttt`
vrepPath=""

if [[ -z $vrepPath ]]; then
  echo "***************************************************************************"
  echo "! Please modify this script to set your vrepPath (vrep.sh included) first !"
  echo "***************************************************************************"
else
  $vrepPath -gREMOTEAPISERVERSERVICE_1234_FALSE_FALSE $vrepSceneAbsolutePath &
fi
