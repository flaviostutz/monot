#!/bin/bash

#start mqtt server container
docker run -p 1883:1883 -p 9001:9001 -d toke/mosquitto

#start monot raspberry containers
docker run flaviostutz/monot-brain
docker run flaviostutz/monot-vision
docker run flaviostutz/monot-hearing
