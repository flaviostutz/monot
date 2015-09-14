FROM flaviostutz/opencv-x86

RUN apt-get update
    && apt-get install libssl-dev
    && cd /opt
    && git clone https://github.com/eclipse/paho.mqtt.c.git
    && cd paho.mqtt.c
    && git checkout v1.0.3
    && make
    && make install
    && cd /opt
    && rm -R -f paho.mqtt.c

ADD . /opt/monot-vision

RUN cd /opt/monot-vision/src && ../build/compile.sh

CMD [ "/opt/monot-vision/tmp/monot-vision" ]
