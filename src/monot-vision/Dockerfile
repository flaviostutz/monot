FROM flaviostutz/opencv-x86

RUN apt-get update
    && apt-get -y install software-properties-common
    && add-apt-repository -y ppa:mosquitto-dev/mosquitto-ppa
    && apt-get update
    && apt-get -y install libmosquitto-dev libmosquittopp-dev libmosquitto1 libmosquittopp1

ADD . /opt/monot-vision

RUN cd /opt/monot-vision/build && compile.sh

CMD [ "/opt/monot-vision/src/monot-vision" ]
