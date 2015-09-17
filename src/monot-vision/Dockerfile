FROM flaviostutz/opencv-x86

#Install MQTT Paho libraries
RUN cd /tmp
    && wget http://build.eclipse.org/technology/paho/C/1.0.3/201508131147/eclipse-paho-mqtt-c-unix-1.0.3.tar.gz
    && mkdir eclipse-paho-mqtt-c-unix-1.0.3
    && tar -xvf eclipse-paho-mqtt-c-unix-1.0.3.tar.gz -C eclipse-paho-mqtt-c-unix-1.0.3
    && cp eclipse-paho-mqtt-c-unix-1.0.3/lib/* /usr/local/lib
    && cp eclipse-paho-mqtt-c-unix-1.0.3/include/* /usr/local/include
    && ldconfig

#RUN apt-get update
#    && apt-get install libssl-dev
#    && cd /tmp
#    && git clone https://github.com/eclipse/paho.mqtt.c.git
#    && cd paho.mqtt.c
#    && git checkout v1.0.3
#    && make
#    && make install
#    && cd /tmp
#    && rm -R -f paho.mqtt.c
#    && git clone http://git.eclipse.org/gitroot/paho/org.eclipse.paho.mqtt.cpp.git
#    && cd org.eclipse.paho.mqtt.cpp
#    && make
#    && cd /tmp
#    && rm -R -f org.eclipse.paho.mqtt.cpp

#RUN apt-get update
#    && apt-get -y install libmosquittopp0-dev libmosquitto0-dev

ADD . /opt/monot-vision

RUN cd /opt/monot-vision/src && ../build/compile.sh

CMD [ "/opt/monot-vision/tmp/monot-vision" ]
